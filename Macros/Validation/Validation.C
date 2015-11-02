#ifndef Validation_cxx
#define Validation_cxx

#include "Validation.h"
#include "../utilities/constants.h"

void Validation::Loop()
{
  if (fChain == 0) return;

  Long64_t nentries = (MaxEvents == -1) ? fChain->GetEntries() : std::min((int)fChain->GetEntries(), MaxEvents);

  std::cout << "Analyzing " << nentries << " events.\n";

  // Book histograms here
  MakeHisto();

  Int_t l2ss = 0;
  Int_t l3   = 0;
  Int_t l4   = 0;
  
  Int_t l2ssbb = 0;
  Int_t l3bb   = 0;
  Int_t l4bb   = 0;

  Int_t HtoTl2ss = 0;
  Int_t HtoTl3   = 0;
  Int_t HtoTl4   = 0;
  
  Int_t HtoTl2ssbb = 0;
  Int_t HtoTl3bb   = 0;
  Int_t HtoTl4bb   = 0;


  Int_t HtoZl2ss = 0;
  Int_t HtoZl3   = 0;
  Int_t HtoZl4   = 0;
  
  Int_t HtoZl2ssbb = 0;
  Int_t HtoZl3bb   = 0;
  Int_t HtoZl4bb   = 0;


  Int_t HtoWl2ss = 0;
  Int_t HtoWl3   = 0;
  Int_t HtoWl4   = 0;
  
  Int_t HtoWl2ssbb = 0;
  Int_t HtoWl3bb   = 0;
  Int_t HtoWl4bb   = 0;

  Int_t nHtoTT=0;
  Int_t nHtoZZ=0;
  Int_t nHtoWW=0;

  Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry=0; jentry<nentries;jentry++)
  {
    if(jentry%1000 == 0)
      std::cout << "Loop over entry " << jentry << "/" << nentries << ".\n";
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);   nbytes += nb;
    // if (Cut(ientry) < 0) continue;

    //    cout<<"\n\n\t\tEvtSeparator\n\n";

    //    cout<< PV_Z->at(0);
    // Int_t tempIndx = -1;
    // for(Size_t iGenp=0; iGenp<GenP_Pt->size(); iGenp++)
    //   {
    // 	if (GenP_PdgId->at(iGenp) == 25)
    // 	  if(IsFinalGenp(iGenp, GenP_Daughters->at(iGenp)))
    // 	    tempIndx = iGenp;
    //   }
    // //cout<<"\t\t\t\t"<< GenP_VertexZ->at(tempIndx)<<endl;
    // hTestPV ->Fill(GenP_VertexZ->at(tempIndx) - PV_Z->at(0));

    vector<ParticleInfo> Lep;
    Int_t DM = DecayMode();
    
    hDecayMode -> Fill (DM);
    
    //**************************************************************************************************************************************************
    //**************************************************************************************************************************************************
    //--------------------------------------------------------------------Kinematics--------------------------------------------------------------------
    //**************************************************************************************************************************************************
    //**************************************************************************************************************************************************
    

    //*************************************************************************
    // ---------------------Gen Study---------------------------------
    //*************************************************************************
    Size_t nGenp = GenP_Pt->size();
    
    //**********************
    // Taking GenP Vertex
    //**********************
    Double_t GenPV_X=-100;
    Double_t GenPV_Y=-100;
    Double_t GenPV_Z=-100;
    
    for(Size_t iPV=0; iPV<nGenp; iPV++)
      {
	if(GenP_Status->at(iPV) == 21)
	  {
	    GenPV_X = GenP_VertexX->at(iPV);
	    GenPV_Y = GenP_VertexY->at(iPV);
	    GenPV_Z = GenP_VertexZ->at(iPV);
	    break;
	  }
      }// end loop for obtaining PV

    hGenPV_X->Fill(GenPV_X);
    hGenPV_Y->Fill(GenPV_Y);
    hGenPV_Z->Fill(GenPV_Z);
    //    cout<< GenPV_Z<< endl;
    //**********************

    //**********************
    // Taking MET four vector
    //**********************
    Double_t GenMet_Pt  = -100;
    Double_t GenMet_Eta = -100;
    Double_t GenMet_Phi = -100;
    Double_t GenMet_E = -100;
    Int_t nNu = 0 ;
    TLorentzVector MET;
  
    for(Size_t iMet=0; iMet<nGenp; iMet++)
      {
	if(abs(GenP_PdgId->at(iMet)) == 12 || abs(GenP_PdgId->at(iMet)) == 14 || abs(GenP_PdgId->at(iMet)) == 16 )
	  {
	    if(GenP_Status->at(iMet) == 1)
	      {
		TLorentzVector Nu;
		Nu.SetPtEtaPhiE(GenP_Pt->at(iMet),
				GenP_Eta->at(iMet),
				GenP_Phi->at(iMet),
				GenP_E->at(iMet));
		MET += Nu;
		
		nNu++;
	      }
	  }
      }//end loop for calc of MET
    //  cout<< MET.Et()<<"\t\t"<<MET.E()<<endl;
  
    hGenNuMultiplicity->Fill(nNu);
    hGenMET_Et->Fill(MET.Et());
    hGenMET_Pt->Fill(MET.Pt());
    //**********************

    //**********************
    // Gen Particles
    //**********************
    Double_t nBJets      =0;
    
    for(Size_t iGenp=0; iGenp<nGenp; iGenp++)
      {
	//Electrons
	if(abs(GenP_PdgId->at(iGenp)) == 11)
	  {
	    if(GenP_Status->at(iGenp) == 1)//if(IsFinalGenp(iGenp, GenP_Daughters->at(iGenp)))
	      {
		hGenElec_Pt->Fill(GenP_Pt->at(iGenp));
		
		Double_t tempEta=GenP_Eta->at(iGenp);
		if(tempEta < -2.4) tempEta = -2.5;
		if(tempEta > 2.4)  tempEta =  2.5;

		hGenElec_Eta->Fill(tempEta);
		hGenElec_E->Fill(GenP_E->at(iGenp));
		
		Double_t RIso = RIsoLepton(GenP_Pt->at(iGenp),GenP_Eta->at(iGenp),GenP_Phi->at(iGenp)); 
		hGenElec_RIso->Fill(RIso);
		
		hGenElec_Lxy->Fill(GetLxy(iGenp, GenPV_X, GenPV_Y));
		hGenElec_Lxyz->Fill(GetLxyz(iGenp, GenPV_X, GenPV_Y,  GenPV_Z));
		Double_t dPhi = auxTools_.DeltaPhi(GenP_Phi->at(iGenp), MET.Phi());
		hdPhi_GenElec_MET ->Fill(dPhi);
	      }// if status 1
	  }//end if Electrons


	//Muons
	if(abs(GenP_PdgId->at(iGenp)) == 13)
	  {
	    if(GenP_Status->at(iGenp) == 1)//if(IsFinalGenp(iGenp, GenP_Daughters->at(iGenp)))
	      {
		hGenMuon_Pt->Fill(GenP_Pt->at(iGenp));
		
		Double_t tempEta=GenP_Eta->at(iGenp);
		if(tempEta < -2.5) tempEta = -2.6;
		if(tempEta > 2.5)  tempEta =  2.6;
		
		hGenMuon_Eta->Fill(tempEta);
		hGenMuon_E->Fill(GenP_E->at(iGenp));
		
		Double_t RIso = RIsoLepton(GenP_Pt->at(iGenp),GenP_Eta->at(iGenp),GenP_Phi->at(iGenp)); 
		hGenMuon_RIso->Fill(RIso);
		
		hGenMuon_Lxy->Fill(GetLxy(iGenp, GenPV_X, GenPV_Y));
		hGenMuon_Lxyz->Fill(GetLxyz(iGenp, GenPV_X, GenPV_Y,  GenPV_Z));
		Double_t dPhi = auxTools_.DeltaPhi(GenP_Phi->at(iGenp), MET.Phi());
		hdPhi_GenMuon_MET ->Fill(dPhi);
	      }// if status 1
	  }//end if Muons

	
	//Taus
	if(abs(GenP_PdgId->at(iGenp)) == 15)
	  {
	    if(IsFinalGenp(iGenp, GenP_Daughters->at(iGenp)))//if(GenP_Status->at(iGenp) == 1)
	      {
		hGenTau_Pt->Fill(GenP_Pt->at(iGenp));

		Double_t tempEta=GenP_Eta->at(iGenp);
		if(tempEta < -2.5) tempEta = -2.6;
		if(tempEta > 2.5)  tempEta =  2.6;

		hGenTau_Eta->Fill(tempEta);
		hGenTau_E->Fill(GenP_E->at(iGenp));
		
		Double_t RIso = RIsoLepton(GenP_Pt->at(iGenp),GenP_Eta->at(iGenp),GenP_Phi->at(iGenp)); 
		hGenTau_RIso->Fill(RIso);
		
		Double_t dPhi = auxTools_.DeltaPhi(GenP_Phi->at(iGenp), MET.Phi());
		hdPhi_GenTau_MET ->Fill(dPhi);
	      }// if status 1
	  }//end if Taus

	//Bjet
	if(IsFinalBHadron(iGenp))
	  {
	    Double_t bEta = GenP_Eta->at(iGenp);
	    Double_t bPhi = GenP_Phi->at(iGenp);
	    
	    for(Size_t itgJ=0; itgJ<GenJet_Pt->size(); itgJ++)
	      {
		Double_t jEta = GenJet_Eta->at(itgJ);
		Double_t jPhi = GenJet_Phi->at(itgJ);
		
		Double_t drBJ = auxTools_.DeltaR(bEta,bPhi,
						 jEta,jPhi);
		hDRBJ -> Fill (drBJ);

	      }// loop on jets

	    nBJets++;
	    hbGenHad_Pt->Fill(GenP_Pt->at(iGenp));
	    hbGenHad_Eta->Fill(GenP_Eta->at(iGenp));
	    hbGenHad_E->Fill(GenP_E->at(iGenp));
	    
	    Double_t dPhi = auxTools_.DeltaPhi(GenP_Phi->at(iGenp), MET.Phi());
	    hdPhi_bGenHad_MET ->Fill(dPhi);

	    Double_t nNeutralInB =0;
	    Double_t nChargedInB =0;
	    
	    for(Size_t iMulti=0; iMulti< nGenp; iMulti++)
	      {
		if(GenP_Status->at(iMulti) == 1)
		  {
		    Double_t dR = auxTools_.DeltaR(GenP_Eta->at(iGenp),GenP_Phi->at(iGenp),
						   GenP_Eta->at(iMulti),GenP_Phi->at(iMulti));
		    if(dR<0.4)
		      {
			if(GenP_Charge->at(iMulti) == 0)
			  {
			    nNeutralInB++;
			  }
			if(GenP_Charge->at(iMulti) == 1)
			  {
			    nChargedInB++;
			  }
		      }
		  }
	      }// loop on Genp for finding multiplicities
	    hbGenHad_ChMulti->Fill(nChargedInB);
	    hbGenHad_NMulti ->Fill(nNeutralInB);

	  }// if B Hadron

      }// end loop on Genp
    hbGenHad_Multiplicity->Fill(nBJets);
    //**********************
    
    
    //**********************
    // Gen Jets
    //**********************
    Size_t nGenJ = GenJet_Pt->size();
    
    Double_t HT  = 0 ;//Scalar sum of all jets
    TLorentzVector vGenJet;
    Double_t MHT = 0 ;//Vector sum of all jets
    
    for(Size_t iGenJ=0; iGenJ<nGenJ; iGenJ++)
      {
	hGenJet_Pt->Fill(GenJet_Pt->at(iGenJ));
	hGenJet_Eta->Fill(GenJet_Eta->at(iGenJ));
	hGenJet_E->Fill(GenJet_E->at(iGenJ));
	
	Double_t dPhi = auxTools_.DeltaPhi(GenJet_Phi->at(iGenJ), MET.Phi());
	hdPhi_GenJet_MET ->Fill(dPhi);

	Double_t nNeutralInJet =0;
	Double_t nChargedInJet =0;
	
	for(Size_t iMulti=0; iMulti< nGenp; iMulti++)
	  {
	    if(GenP_Status->at(iMulti) == 1)
	      {
		Double_t dR = auxTools_.DeltaR(GenJet_Eta->at(iGenJ),GenJet_Phi->at(iGenJ),
					       GenP_Eta->at(iMulti),GenP_Phi->at(iMulti));
		if(dR<0.4)
		  {
		    if(GenP_Charge->at(iMulti) == 0)
		      {
			nNeutralInJet++;
		      }
		    if(GenP_Charge->at(iMulti) == 1)
		      {
			nChargedInJet++;
		      }
		  }
	      }
	  }// loop on Genp for finding multiplicities

	hGenJet_ChMulti->Fill(nChargedInJet);
	hGenJet_NMulti ->Fill(nNeutralInJet);

	TLorentzVector tempgenJet;
	tempgenJet.SetPtEtaPhiE(GenJet_Pt->at(iGenJ),GenJet_Eta->at(iGenJ),GenJet_Phi->at(iGenJ),GenJet_E->at(iGenJ));

	HT += tempgenJet.Et();

	vGenJet+=tempgenJet;
	
      }//loop on gen jets
    MHT = vGenJet.Et();

    hHT  -> Fill(HT);
    hMHT -> Fill(MHT);

    hGenJet_Multiplicity->Fill(nGenJ);


    //*********************************
    // Event Expectation .... Table 1 AN 2013 159
    //*********************************
    Size_t TotalGenp = GenP_Pt->size(); 
    vector<ParticleInfo> GenLep;
    Int_t nbHad = 0;
    
    Bool_t bHtoW = false;
    Bool_t bHtoZ = false;
    Bool_t bHtoT = false;
    
    for(Size_t iH = 0; iH<TotalGenp; iH++)
      {
	if(GenP_PdgId->at(iH) == 25)
	  {
	    if(IsFinalGenp(iH, GenP_Daughters->at(iH)))
	      {
		if(GenP_Daughters->at(iH).size() > 0)
		  {
		    //	    cout<< "\t\t"<<GenP_PdgId->at(GenP_Daughters->at(iH).at(0))<<endl;
		    if(abs(GenP_PdgId->at(GenP_Daughters->at(iH).at(0))) == 15 )
		      bHtoT = true;
		    if(abs(GenP_PdgId->at(GenP_Daughters->at(iH).at(0))) == 23 )
		      bHtoZ = true;
		    if(abs(GenP_PdgId->at(GenP_Daughters->at(iH).at(0))) == 24 )
		      bHtoW = true;
		  }
	      }// if final Higgs
	  }// if higgs
      }// loop for chekcing decay of Higgs

    if(bHtoT) nHtoTT++;
    if(bHtoZ) nHtoZZ++;
    if(bHtoW) nHtoWW++;

    for(Size_t iGenp = 0; iGenp<TotalGenp; iGenp++)
      {
	// Step 1... collect status 1 electrons and muons within acceptance.
	if(GenP_Status->at(iGenp) == 1)
	  {
	    if(abs(GenP_PdgId->at(iGenp)) == 11)
	      {
		if(GenP_Pt->at(iGenp) > 7 && abs(GenP_Eta->at(iGenp)) < 2.5)
		  {
		    //		    cout<<GenP_Eta->at(iGenp)<<"\t"<<GenP_Pt->at(iGenp)<<"\t"<<EvtNumber<<"\t"<< iGenp<<endl;
		    ParticleInfo tempGen;
		    tempGen = SetParticleInfo(GenP_Pt->at(iGenp), GenP_Eta->at(iGenp), GenP_Phi->at(iGenp), GenP_E->at(iGenp), GenP_PdgId->at(iGenp), GenP_Charge->at(iGenp));
		    GenLep.push_back(tempGen);
		  }
		
	      }// if electron

	    if(abs(GenP_PdgId->at(iGenp)) == 13)
	      {
		if(GenP_Pt->at(iGenp) > 5 && abs(GenP_Eta->at(iGenp)) < 2.4)
		  {
		    ParticleInfo tempGen;
		    tempGen = SetParticleInfo(GenP_Pt->at(iGenp), GenP_Eta->at(iGenp), GenP_Phi->at(iGenp), GenP_E->at(iGenp), GenP_PdgId->at(iGenp), GenP_Charge->at(iGenp));
		    GenLep.push_back(tempGen);
		    //cout<<GenP_Eta->at(iGenp)<<"\t"<<GenP_Pt->at(iGenp)<<"\t"<<EvtNumber<<"\t"<< iGenp<<endl;
		  }
		
	      }// if muon


	  }// if status one genp
	if(IsFinalBHadron(iGenp))
	  {
	    if(GenP_Pt->at(iGenp) > 25 && abs(GenP_Eta->at(iGenp)) < 2.5)
	    {
	      nbHad ++;
	      //	      cout<<GenP_Eta->at(iGenp)<<"\t"<<GenP_Pt->at(iGenp)<<"\t"<<EvtNumber<<"\t"<< iGenp<<endl;
	    }
	    
	  }// if muon


      }// end loop on Genp

    //Di Lepton trigger pass (20,10) GeV...
    Bool_t bPassTrg2010 = false;
    if(GenLep.size()>=2)
      {
	SortLepPt(GenLep);
	if(GenLep.at(0).Pt > 20 && GenLep.at(1).Pt > 10)
	  {
	    // cout<< GenLep.at(0).Pt<<"\t\t" << GenLep.at(1).Pt<<endl;
	    bPassTrg2010 = true;
	  }
      }
    if(bPassTrg2010)
      {
	if(GenLep.size()==2)
	  {
	    if(GenLep.at(0).Charge ==  GenLep.at(1).Charge)
	      {
		//cout<<EvtNumber<<"\t\t"<< GenLep.at(0).Pt<<"\t\t" << GenLep.at(1).Pt<<"     and the charge      "<<GenLep.at(0).Charge<<"\t\t" << GenLep.at(1).Charge<<endl; 
	      	if(bHtoT)
		  {
		    HtoTl2ss++;
		    if(nbHad == 2)
		      HtoTl2ssbb++;
		  }
		if(bHtoZ)
		  {
		    HtoZl2ss++;
		    if(nbHad == 2)
		      HtoZl2ssbb++;
		  }
		if(bHtoW)
		  {
		    HtoWl2ss++;
		    if(nbHad == 2)
		      HtoWl2ssbb++;
		  }

		l2ss++;
		if(nbHad == 2)
		  l2ssbb++;
	      }
	  }
	if(GenLep.size()==3)
	  {
	    //	    cout<<EvtNumber<<"\t\t"<< GenLep.at(0).Pt<<"\t\t" << GenLep.at(1).Pt<<"     and the charge      "<<GenLep.at(0).Charge<<"\t\t" << GenLep.at(1).Charge<<endl;
	    if(bHtoT)
	      {
		HtoTl3++;
		if(nbHad == 2)
		  HtoTl3bb++;
	      }
	    if(bHtoZ)
	      {
		HtoZl3++;
		if(nbHad == 2)
		  HtoZl3bb++;
	      }
	    if(bHtoW)
	      {
		HtoWl3++;
		if(nbHad == 2)
		  HtoWl3bb++;
	      }
	    
	    l3++;
	    if(nbHad == 2)
	      l3bb++;
	  }
	if(GenLep.size()==4)
	  {
	    if(bHtoT)
	      {
		HtoTl4++;
		if(nbHad == 2)
		  HtoTl4bb++;
	      }
	    if(bHtoZ)
	      {
		HtoZl4++;
		if(nbHad == 2)
		  HtoZl4bb++;
	      }
	    if(bHtoW)
	      {
		HtoWl4++;
		if(nbHad == 2)
		  HtoWl4bb++;
	      }

	    l4++;
	    if(nbHad == 2)
	      l4bb++;
	  }
      }

    //*********************************

    
    //*************************************************************************

    

    
    //*************************************************************************
    // ---------------------Electrons-----------------------------------------
    //*************************************************************************
    Size_t nElec = Elec_Pt->size();
    for(Size_t iElec=0; iElec<nElec; iElec++)
      {
	hElec_Pt->Fill(Elec_Pt->at(iElec));
	hElec_Eta   -> Fill(Elec_Eta   ->at(iElec));
	hElec_Phi   -> Fill(Elec_Phi   ->at(iElec));
	hElec_E     -> Fill(Elec_E     ->at(iElec));
	hElec_Charge-> Fill(Elec_Charge->at(iElec));

	hElec_SCl_Eta      -> Fill(Elec_SCl_Eta      -> at(iElec));
	hElec_SCl_EtaWidth -> Fill(Elec_SCl_EtaWidth -> at(iElec));
	hElec_SCl_Phi      -> Fill(Elec_SCl_Phi      -> at(iElec));
	hElec_SCl_PhiWidth -> Fill(Elec_SCl_PhiWidth -> at(iElec));
	hElec_SCl_E        -> Fill(Elec_SCl_E        -> at(iElec));
	hElec_SCl_RawE     -> Fill(Elec_SCl_RawE     -> at(iElec));

	Bool_t bHasGsfTk = Elec_HasGsfTrack->at(iElec);
	if(bHasGsfTk)
	  {
	    hElec_GsfTrack_D0             -> Fill(Elec_GsfTrack_D0             -> at(iElec));
	    hElec_GsfTrack_Z0             -> Fill(Elec_GsfTrack_Z0             -> at(iElec));
	    hElec_GsfTrack_D0Error        -> Fill(Elec_GsfTrack_D0Error        -> at(iElec));
	    hElec_GsfTrack_Z0Error        -> Fill(Elec_GsfTrack_Z0Error        -> at(iElec));
	    hElec_GsfTrack_NormalizedChi2 -> Fill(Elec_GsfTrack_NormalizedChi2 -> at(iElec));
	  }
	
	hElec_IP3d      -> Fill(Elec_IP3d      ->at(iElec));
	hElec_IP3dError -> Fill(Elec_IP3dError ->at(iElec));
	hElec_IP2d      -> Fill(Elec_IP2d      ->at(iElec));
	hElec_IP2dError -> Fill(Elec_IP2dError ->at(iElec));

	Double_t dPhi = auxTools_.DeltaPhi(Elec_Phi   ->at(iElec), MET_Phi);
	hdPhi_Elec_MET ->Fill(dPhi);

	Double_t RIso = RIsoLepton(Elec_Pt->at(iElec),Elec_Eta->at(iElec),Elec_Phi->at(iElec)); 
	hElec_RIso->Fill(RIso);
	//	cout<< Elec_Id->at(iElec)<<endl;
	//	cout<< sumPtC<<"\t\t"<<sumPtN<<endl;

	ParticleInfo temp;
	temp = SetParticleInfo(Elec_Pt->at(iElec), Elec_Eta->at(iElec), Elec_Phi->at(iElec), Elec_E->at(iElec), Elec_Id->at(iElec), Elec_Charge->at(iElec));
	Lep.push_back(temp);

	//	cout<< Elec_Pt->at(iElec)<<endl;
      }//end loop on Electons
    //*************************************************************************
    
    // cout<<"\t"<< Lep.size()<<endl;
    // if(Lep.size()>0)cout<<"\t\t"<<Lep.at(0).Pt<<endl;


    //*************************************************************************
    // ---------------------Muon-----------------------------------------
    //*************************************************************************
    Size_t nMuon = Muon_Pt->size();
    for(Size_t iMuon=0; iMuon<nMuon; iMuon++)
      {
	hMuon_Pt->Fill(Muon_Pt->at(iMuon));
	hMuon_Eta   -> Fill(Muon_Eta   ->at(iMuon));
	hMuon_Phi   -> Fill(Muon_Phi   ->at(iMuon));
	hMuon_E     -> Fill(Muon_E     ->at(iMuon));
	hMuon_Charge-> Fill(Muon_Charge->at(iMuon));

	Bool_t bHasInnerTk = Muon_HasInnerTrack->at(iMuon);
	if(bHasInnerTk)
	  {
	    hMuon_InnerTrack_D0             -> Fill(Muon_InnerTrack_D0             -> at(iMuon));
	    hMuon_InnerTrack_Z0             -> Fill(Muon_InnerTrack_Z0             -> at(iMuon));
	    hMuon_InnerTrack_D0Error        -> Fill(Muon_InnerTrack_D0Error        -> at(iMuon));
	    hMuon_InnerTrack_Z0Error        -> Fill(Muon_InnerTrack_Z0Error        -> at(iMuon));
	    hMuon_InnerTrack_NormalizedChi2 -> Fill(Muon_InnerTrack_NormalizedChi2 -> at(iMuon));
	  }
	
	Bool_t bHasGlobalTk = Muon_HasGlobalTrack->at(iMuon);
	if(bHasGlobalTk)
	  {
	    hMuon_GlobalTrack_D0             -> Fill(Muon_GlobalTrack_D0             -> at(iMuon));
	    hMuon_GlobalTrack_Z0             -> Fill(Muon_GlobalTrack_Z0             -> at(iMuon));
	    hMuon_GlobalTrack_D0Error        -> Fill(Muon_GlobalTrack_D0Error        -> at(iMuon));
	    hMuon_GlobalTrack_Z0Error        -> Fill(Muon_GlobalTrack_Z0Error        -> at(iMuon));
	    hMuon_GlobalTrack_NormalizedChi2 -> Fill(Muon_GlobalTrack_NormalizedChi2 -> at(iMuon));
	  }
	
	hMuon_IP3d      -> Fill(Muon_IP3d      ->at(iMuon));
	hMuon_IP3dError -> Fill(Muon_IP3dError ->at(iMuon));
	hMuon_IP2d      -> Fill(Muon_IP2d      ->at(iMuon));
	hMuon_IP2dError -> Fill(Muon_IP2dError ->at(iMuon));

	Double_t dPhi = auxTools_.DeltaPhi(Muon_Phi   ->at(iMuon), MET_Phi);
	hdPhi_Muon_MET ->Fill(dPhi);
	
	Double_t RIso = RIsoLepton(Muon_Pt->at(iMuon),Muon_Eta->at(iMuon),Muon_Phi->at(iMuon)); 
	hMuon_RIso->Fill(RIso);

	ParticleInfo temp;
	temp = SetParticleInfo(Muon_Pt->at(iMuon), Muon_Eta->at(iMuon), Muon_Phi->at(iMuon), Muon_E->at(iMuon), Muon_Id->at(iMuon), Muon_Charge->at(iMuon));
	Lep.push_back(temp);

      }//end loop on Muons
    //*************************************************************************
    

    //*************************************************************************
    // Lep Combined
    //*************************************************************************
    SortLepPt(Lep);
    if (Lep.size()>0)
      hLeadingLep -> Fill(Lep.at(0).Pt);
    if (Lep.size()>1)
      hSubLeadingLep -> Fill(Lep.at(1).Pt);
    if (Lep.size()>2)
      hSubSubLeadingLep -> Fill(Lep.at(2).Pt);



    //*************************************************************************


    //*************************************************************************
    // ---------------------Tau-----------------------------------------
    //*************************************************************************
    Size_t nTau = Tau_Pt->size();
    for(Size_t iTau=0; iTau<nTau; iTau++)
      {
	hTau_Pt->Fill(Tau_Pt->at(iTau));
	hTau_Eta   -> Fill(Tau_Eta   ->at(iTau));
	hTau_Phi   -> Fill(Tau_Phi   ->at(iTau));
	hTau_E     -> Fill(Tau_E     ->at(iTau));
	hTau_Charge-> Fill(Tau_Charge->at(iTau));
	hTau_DecayMode-> Fill(Tau_DecayMode->at(iTau));

	Bool_t bHasLeadCHCTk = Tau_hasLeadChargedHadrCand->at(iTau);
	if(bHasLeadCHCTk)
	  {
	    hTau_LeadChHadCand_Pt             -> Fill(Tau_LeadingCHCPt             -> at(iTau));
	    hTau_LeadChHadCand_Eta            -> Fill(Tau_LeadingCHCEta            -> at(iTau));
	    hTau_LeadChHadCand_Phi            -> Fill(Tau_LeadingCHCPhi            -> at(iTau));
	    hTau_LeadChHadCand_E              -> Fill(Tau_LeadingCHCE              -> at(iTau));
	    hTau_LeadChHadCand_Et             -> Fill(Tau_LeadingCHCEt             -> at(iTau));
	    hTau_LeadChHadCand_Id             -> Fill(Tau_LeadingCHCId             -> at(iTau));
	    hTau_LeadChHadCand_Charge         -> Fill(Tau_LeadingCHCCharge         -> at(iTau));
	    hTau_LeadChHadCand_Vx             -> Fill(Tau_LeadingCHCVx             -> at(iTau));
	    hTau_LeadChHadCand_Vy             -> Fill(Tau_LeadingCHCVy             -> at(iTau));
	    hTau_LeadChHadCand_Vz             -> Fill(Tau_LeadingCHCVz             -> at(iTau));
	 
	    // if(abs(Tau_LeadingCHCId -> at(iTau)) == 11 || abs(Tau_LeadingCHCId -> at(iTau)) == 13 )
	    //   {
	    // 	cout<< "Leptonic Tau Leading Dau\t"<<Tau_LeadingCHCId-> at(iTau)<<endl; 
	    //   }
	    // if(Tau_LeadingCHCCharge -> at(iTau) == 0)
	    //   {
	    // 	cout<<"Neutral Leading Dau ID \t"<<Tau_LeadingCHCId-> at(iTau)<<endl;
	    //   }
 
	  }
	float dPhi = auxTools_.DeltaPhi(Tau_Phi   ->at(iTau), MET_Phi);
	hdPhi_Tau_MET ->Fill(dPhi);

      }//end loop on Taus
    //*************************************************************************


    //*************************************************************************
    //-----------------------------MET---------------------------------------
    //*************************************************************************
    hMET_Pt->Fill(MET_Pt);
    hMET_Phi->Fill(MET_Phi);
    hMET_SumEt->Fill(MET_SumEt);
    
    //    cout<<"\tMET ENERGY\t"<<MET_SumEt<<endl;
    //*************************************************************************



    //*************************************************************************
    //-----------------------------Jets---------------------------------------
    //*************************************************************************
    Size_t nJet = Jet_Pt->size();
    hJet_Multiplicity->Fill(nJet);
    Size_t nbJPLwp=0;
    Size_t nbJPMwp=0;
    Size_t nbJPTwp=0;
    Size_t nbJParFl=0;
    for(Size_t iJet=0; iJet<nJet; iJet++)
      {
	hJet_Pt     ->Fill(Jet_Pt      ->at(iJet));
	hJet_Eta    -> Fill(Jet_Eta    ->at(iJet));
	hJet_Phi    -> Fill(Jet_Phi    ->at(iJet));
	hJet_E      -> Fill(Jet_E      ->at(iJet));
	hJet_JetArea-> Fill(Jet_JetArea->at(iJet));

	hJet_ChMulti    -> Fill(Jet_ChargedMultiplicity->at(iJet));
	hJet_ChHadMulti -> Fill(Jet_ChargedHadronMultiplicity->at(iJet));
	hJet_NMulti     -> Fill(Jet_NeutralMultiplicity->at(iJet));
	hJet_NHadMulti  -> Fill(Jet_NeutralHadronMultiplicity->at(iJet));

	hJet_ElecMulti   -> Fill(Jet_ElectronMultiplicity->at(iJet));
	hJet_MuonMulti   -> Fill(Jet_MuonMultiplicity->at(iJet));
	hJet_PhotonMulti -> Fill(Jet_PhotonMultiplicity->at(iJet));
	
	hJet_ParFl_bDisJP->Fill(Jet_GenPartonFlavour->at(iJet),Jet_bDis_JP->at(iJet));
	hJet_HadFl_bDisJP->Fill(Jet_GenHadronFlavour->at(iJet),Jet_bDis_JP->at(iJet));

	hJet_ParFl_bDisCMVA->Fill(Jet_GenPartonFlavour->at(iJet),Jet_bDis_CMVA->at(iJet));
	hJet_HadFl_bDisCMVA->Fill(Jet_GenHadronFlavour->at(iJet),Jet_bDis_CMVA->at(iJet));
	
	if(abs(Jet_GenPartonFlavour->at(iJet)) == 5)
	  {
	    hbJet_Pt->Fill(Jet_Pt->at(iJet));
	    hbJet_Eta->Fill(Jet_Eta->at(iJet));
	    hbJet_Phi->Fill(Jet_Phi->at(iJet));
	    hbJet_E->Fill(Jet_E->at(iJet));
	    hbJet_JetArea-> Fill(Jet_JetArea->at(iJet));

	    hbJet_ChMulti    -> Fill(Jet_ChargedMultiplicity->at(iJet));
	    hbJet_ChHadMulti -> Fill(Jet_ChargedHadronMultiplicity->at(iJet));
	    hbJet_NMulti     -> Fill(Jet_NeutralMultiplicity->at(iJet));
	    hbJet_NHadMulti  -> Fill(Jet_NeutralHadronMultiplicity->at(iJet));
	    
	    hbJet_ElecMulti   -> Fill(Jet_ElectronMultiplicity->at(iJet));
	    hbJet_MuonMulti   -> Fill(Jet_MuonMultiplicity->at(iJet));
	    hbJet_PhotonMulti -> Fill(Jet_PhotonMultiplicity->at(iJet));

	    float dPhib = auxTools_.DeltaPhi(Jet_Phi   ->at(iJet), MET_Phi);
	    hdPhi_bJet_MET ->Fill(dPhib);

	    nbJParFl++;
	  }
	if(Jet_bDis_JP->at(iJet)> 0.275)
	  nbJPLwp++;
	if(Jet_bDis_JP->at(iJet)> 0.545)
	  nbJPMwp++;
	if(Jet_bDis_JP->at(iJet)> 0.790)
	  nbJPTwp++;

	float dPhi = auxTools_.DeltaPhi(Jet_Phi   ->at(iJet), MET_Phi);
	hdPhi_Jet_MET ->Fill(dPhi);

      }//end loop on Jets
    hbJetParFl_Multiplicity->Fill(nbJParFl);
    hbJetL_Multiplicity->Fill(nbJPLwp);
    hbJetM_Multiplicity->Fill(nbJPMwp);
    hbJetT_Multiplicity->Fill(nbJPTwp);


    //*************************************************************************
    




    
    // Update the progress bar
    //    tools.ProgressBar(jentry, nentries, 100, 150);
  
  }//end loop on entries

  
  cout<< "\tTotal Events\t"<<nentries<<endl;
  cout<< "\tEvents with 2 LepSS\t"<< l2ss<<endl;
  cout<< "\tEvents with 3 Lep\t"<< l3<<endl;
  cout<< "\tEvents with 4 Lep\t"<< l4<<endl;
  
  cout<< "\tEvents with 2 LepSS + 2b\t"<< l2ssbb<<endl;
  cout<< "\tEvents with 3 Lep + 2b\t"<< l3bb<<endl;
  cout<< "\tEvents with 4 Lep + 2b\t"<< l4bb<<endl<<endl<<endl;


  cout<< "\tEvents with 2 LepSS HtoT\t"<< HtoTl2ss/22.81<<endl;
  cout<< "\tEvents with 3 Lep  HtoT\t"<< HtoTl3/22.81<<endl;
  cout<< "\tEvents with 4 Lep   HtoT\t"<< HtoTl4/22.81<<endl;
  
  cout<< "\tEvents with 2 LepSS + 2b  HtoT\t"<< HtoTl2ssbb/22.81<<endl;
  cout<< "\tEvents with 3 Lep + 2b   HtoT\t"<< HtoTl3bb/22.81<<endl;
  cout<< "\tEvents with 4 Lep + 2b   HtoT\t"<< HtoTl4bb/22.81<<endl<<endl<<endl;


  cout<< "\tEvents with 2 LepSS HtoZ\t"<< HtoZl2ss/22.81<<endl;
  cout<< "\tEvents with 3 Lep  HtoZ\t"<< HtoZl3/22.81<<endl;
  cout<< "\tEvents with 4 Lep   HtoZ\t"<< HtoZl4/22.81<<endl;
  
  cout<< "\tEvents with 2 LepSS + 2b  HtoZ\t"<< HtoZl2ssbb/22.81<<endl;
  cout<< "\tEvents with 3 Lep + 2b   HtoZ\t"<< HtoZl3bb/22.81<<endl;
  cout<< "\tEvents with 4 Lep + 2b   HtoZ\t"<< HtoZl4bb/22.81<<endl<<endl<<endl;


  cout<< "\tEvents with 2 LepSS HtoW\t"<< HtoWl2ss/22.81<<endl;
  cout<< "\tEvents with 3 Lep  HtoW\t"<< HtoWl3/22.81<<endl;
  cout<< "\tEvents with 4 Lep   HtoW\t"<< HtoWl4/22.81<<endl;
  
  cout<< "\tEvents with 2 LepSS + 2b  HtoW\t"<< HtoWl2ssbb/22.81<<endl;
  cout<< "\tEvents with 3 Lep + 2b   HtoW\t"<< HtoWl3bb/22.81<<endl;
  cout<< "\tEvents with 4 Lep + 2b   HtoW\t"<< HtoWl4bb/22.81<<endl<<endl<<endl;



  cout<< "\tActual Events with 2 LepSS\t"<< (HtoTl2ss +HtoZl2ss  +HtoWl2ss)/22.81<<endl;
  cout<< "\tActual Events with 3 Lep\t"<<   (HtoTl3   +HtoZl3    +HtoWl3  )/22.81<<endl;
  cout<< "\tActual Events with 4 Lep\t"<<   (HtoTl4   +HtoZl4    +HtoWl4  )/22.81<<endl;
  
  cout<< "\tActual Events with 2 LepSS + 2b\t"<< (HtoTl2ssbb+HtoZl2ssbb+HtoWl2ssbb)/22.81<<endl;
  cout<< "\tActual Events with 3 Lep + 2b\t"<<   (HtoTl3bb  +HtoZl3bb  +HtoWl3bb  )/22.81<<endl;
  cout<< "\tActual Events with 4 Lep + 2b\t"<<   (HtoTl4bb  +HtoZl4bb  +HtoWl4bb  )/22.81<<endl<<endl<<endl;


  
  cout<< "\tH to WW\t"<<nHtoWW<<"\t\t"<<nHtoWW/nentries<<endl;
  cout<< "\tH to ZZ\t"<<nHtoZZ<<"\t\t"<<nHtoZZ/nentries<<endl;
  cout<< "\tH to TT\t"<<nHtoTT<<"\t\t"<<nHtoTT/nentries<<endl;


  // Keep this line here!
  outFile->cd();

  // Create and write canvases here
  //  hJet_ParFl_bDisJP_ProjX = hJet_ParFl_bDisJP->ProjectionX(); 
  //hJet_HadFl_bDisJP_ProjX = hJet_HadFl_bDisJP->ProjectionX();
  
  TH1D *hTest1  = hJet_ParFl_bDisJP ->ProjectionX();
  TH1D *hTest2  = hJet_HadFl_bDisJP ->ProjectionX();

  hTestPV->Scale(1/hTestPV->Integral());

  // Uncomment this line to write also the histograms to the file
  outFile->Write();
}

//#################################################
void Validation::MakeHisto(void)
//#################################################
{

  hDecayMode  = new TH1D ("hDecayMode","hDecayMode",49,0,49);

  hTestPV = new TH1D ("hTestPV","hTestPV",100, -0.2,0.2);

  //Electron***************************************************************************
  hElec_Pt                      = new TH1D ("hElec_Pt","hElec_Pt",200,0,200);
  hElec_Eta                     = new TH1D ("hElec_Eta","hElec_Eta",100,-4,4);
  hElec_Phi                     = new TH1D ("hElec_Phi","hElec_Phi",100,-4,4);
  hElec_E                       = new TH1D ("hElec_E","hElec_E",200,0,200);
  hElec_Charge                  = new TH1D ("hElec_Charge","hElec_Charge",3,-1.5,1.5);
  
  hElec_SCl_Eta                 = new TH1D ("hElec_SCl_Eta","hElec_SCl_Eta",100,-4,4);
  hElec_SCl_EtaWidth            = new TH1D ("hElec_SCl_EtaWidth","hElec_SCl_EtaWidth",100,0,1);
  hElec_SCl_Phi                 = new TH1D ("hElec_SCl_Phi","hElec_SCl_Phi",100,-4,4);
  hElec_SCl_PhiWidth            = new TH1D ("hElec_SCl_PhiWidth","hElec_SCl_PhiWidth",100,0,1);
  hElec_SCl_E                   = new TH1D ("hElec_SCl_E","hElec_SCl_E",200,0,200);
  hElec_SCl_RawE                = new TH1D ("hElec_SCl_RawE","hElec_SCl_RawE",200,0,200);
  
  hElec_GsfTrack_D0             = new TH1D ("hElec_GsfTrack_D0","hElec_GsfTrack_D0",100,-5,5);
  hElec_GsfTrack_Z0             = new TH1D ("hElec_GsfTrack_Z0","hElec_GsfTrack_Z0",100,-25,25);
  hElec_GsfTrack_D0Error        = new TH1D ("hElec_GsfTrack_D0Error","hElec_GsfTrack_D0Error",100,0,1);
  hElec_GsfTrack_Z0Error        = new TH1D ("hElec_GsfTrack_Z0Error","hElec_GsfTrack_Z0Error",100,0,1);
  hElec_GsfTrack_NormalizedChi2 = new TH1D ("hElec_GsfTrack_NormalizedChi2","hElec_GsfTrack_NormalizedChi2",100,1,100);
  
  hElec_IP3d                    = new TH1D ("hElec_IP3d","hElec_IP3d",100,-5,5);
  hElec_IP3dError               = new TH1D ("hElec_IP3dError","hElec_IP3dError",100,0,1);
  hElec_IP2d                    = new TH1D ("hElec_IP2d","hElec_IP2d",100,-5,5);
  hElec_IP2dError               = new TH1D ("hElec_IP2dError","hElec_IP2dError",100,0,1);

  hdPhi_Elec_MET                = new TH1D ("hdPhi_Elec_MET","hdPhi_Elec_MET", 100,-4,4);

  hElec_RIso                    = new TH1D ("hElec_RIso","hElec_RIso", 100,0,5);

  //Muon***************************************************************************
  hMuon_Pt                         = new TH1D ("hMuon_Pt","hMuon_Pt",200,0,200);
  hMuon_Eta                        = new TH1D ("hMuon_Eta","hMuon_Eta",100,-4,4);
  hMuon_Phi                        = new TH1D ("hMuon_Phi","hMuon_Phi",100,-4,4);
  hMuon_E                          = new TH1D ("hMuon_E","hMuon_E",200,0,200);
  hMuon_Charge                     = new TH1D ("hMuon_Charge","hMuon_Charge",4,-2,2);
  
  hMuon_InnerTrack_D0              = new TH1D ("hMuon_InnerTrack_D0","hMuon_InnerTrack_D0",100,-5,5);
  hMuon_InnerTrack_Z0              = new TH1D ("hMuon_InnerTrack_Z0","hMuon_InnerTrack_Z0",100,-25,25);
  hMuon_InnerTrack_D0Error         = new TH1D ("hMuon_InnerTrack_D0Error","hMuon_InnerTrack_D0Error",100,0,1);
  hMuon_InnerTrack_Z0Error         = new TH1D ("hMuon_InnerTrack_Z0Error","hMuon_InnerTrack_Z0Error",100,0,1);
  hMuon_InnerTrack_NormalizedChi2  = new TH1D ("hMuon_InnerTrack_NormalizedChi2","hMuon_InnerTrack_NormalizedChi2",100,1,100);

  hMuon_GlobalTrack_D0             = new TH1D ("hMuon_GlobalTrack_D0","hMuon_GlobalTrack_D0",100,-5,5);
  hMuon_GlobalTrack_Z0             = new TH1D ("hMuon_GlobalTrack_Z0","hMuon_GlobalTrack_Z0",100,-25,25);
  hMuon_GlobalTrack_D0Error        = new TH1D ("hMuon_GlobalTrack_D0Error","hMuon_GlobalTrack_D0Error",100,0,1);
  hMuon_GlobalTrack_Z0Error        = new TH1D ("hMuon_GlobalTrack_Z0Error","hMuon_GlobalTrack_Z0Error",100,0,1);
  hMuon_GlobalTrack_NormalizedChi2 = new TH1D ("hMuon_GlobalTrack_NormalizedChi2","hMuon_GlobalTrack_NormalizedChi2",100,1,100);
  
  hMuon_IP3d                       = new TH1D ("hMuon_IP3d","hMuon_IP3d",100,-5,5);
  hMuon_IP3dError                  = new TH1D ("hMuon_IP3dError","hMuon_IP3dError",100,0,1);
  hMuon_IP2d                       = new TH1D ("hMuon_IP2d","hMuon_IP2d",100,-5,5);
  hMuon_IP2dError                  = new TH1D ("hMuon_IP2dError","hMuon_IP2dError",100,0,1);

  hdPhi_Muon_MET                = new TH1D ("hdPhi_Muon_MET","hdPhi_Muon_MET", 100,-4,4);

  hMuon_RIso                    = new TH1D ("hMuon_RIso","hMuon_RIso", 100,0,5);

  //Lep combined ****************************************************************
  hLeadingLep       = new TH1D ("hLeadingLep"      ,"hLeadingLep"      ,100,0,100);
  hSubLeadingLep    = new TH1D ("hSubLeadingLep"   ,"hSubLeadingLep"   ,100,0,100);
  hSubSubLeadingLep = new TH1D ("hSubSubLeadingLep","hSubSubLeadingLep",100,0,100);


  //Tau***************************************************************************
  hTau_Pt                   = new TH1D ("hTau_Pt","hTau_Pt",200,0,200);
  hTau_Eta                  = new TH1D ("hTau_Eta","hTau_Eta",100,-4,4);
  hTau_Phi                  = new TH1D ("hTau_Phi","hTau_Phi",100,-4,4);
  hTau_E                    = new TH1D ("hTau_E","hTau_E",200,0,200);
  hTau_Charge               = new TH1D ("hTau_Charge","hTau_Charge",4,-2,2);
  hTau_DecayMode            = new TH1D ("hTau_DecayMode","hTau_DecayMode",100,0,20);
  
  hTau_LeadChHadCand_Pt     = new TH1D ("hTau_LeadChHadCand_Pt","hTau_LeadChHadCand_Pt",200,0,200);
  hTau_LeadChHadCand_Eta    = new TH1D ("hTau_LeadChHadCand_Eta","hTau_LeadChHadCand_Eta",100,-4,4);
  hTau_LeadChHadCand_Phi    = new TH1D ("hTau_LeadChHadCand_Phi","hTau_LeadChHadCand_Phi",100,-4,4);
  hTau_LeadChHadCand_E      = new TH1D ("hTau_LeadChHadCand_E","hTau_LeadChHadCand_E",200,0,200);
  hTau_LeadChHadCand_Et     = new TH1D ("hTau_LeadChHadCand_Et","hTau_LeadChHadCand_Et",200,0,200);
  hTau_LeadChHadCand_Id     = new TH1D ("hTau_LeadChHadCand_Id","hTau_LeadChHadCand_Id",800,-400,400);
  hTau_LeadChHadCand_Charge = new TH1D ("hTau_LeadChHadCand_Charge","hTau_LeadChHadCand_Charge",5,-2,2);
  hTau_LeadChHadCand_Vx     = new TH1D ("hTau_LeadChHadCand_Vx","hTau_LeadChHadCand_Vx",100,-1,1);
  hTau_LeadChHadCand_Vy     = new TH1D ("hTau_LeadChHadCand_Vy","hTau_LeadChHadCand_Vy",100,-1,1);
  hTau_LeadChHadCand_Vz     = new TH1D ("hTau_LeadChHadCand_Vz","hTau_LeadChHadCand_Vz",100,-25,25);

  hdPhi_Tau_MET                = new TH1D ("hdPhi_Tau_MET","hdPhi_Tau_MET", 100,-4,4);

  //MET***************************************************************************
  hMET_Pt    = new TH1D ("hMET_Pt","hMET_Pt",200,0,200);
  hMET_Phi   = new TH1D ("hMET_Phi","hMET_Phi",100,-4,4);
  hMET_SumEt = new TH1D ("hMET_SumEt","hMET_SumEt",200,0,5000);
  
  //Jet***************************************************************************
  hJet_Pt          = new TH1D("hJet_Pt"     ,"hJet_Pt"     ,200,0,200);
  hJet_Eta         = new TH1D("hJet_Eta"    ,"hJet_Eta"    ,100,-4,4);
  hJet_Phi         = new TH1D("hJet_Phi"    ,"hJet_Phi"    ,200,-4,4);
  hJet_E           = new TH1D("hJet_E"      ,"hJet_E"      ,200,0,200);
  hJet_JetArea     = new TH1D("hJet_JetArea","hJet_JetArea",100,-4,4);
  
  hJet_ChMulti     = new TH1D("hJet_ChMulti"     ,"hJet_ChMulti"     ,50,-0.5,49.5);
  hJet_ChHadMulti  = new TH1D("hJet_ChHadMulti"  ,"hJet_ChHadMulti"  ,50,-0.5,49.5);
  hJet_NMulti      = new TH1D("hJet_NMulti"      ,"hJet_NMulti"      ,50,-0.5,49.5);
  hJet_NHadMulti   = new TH1D("hJet_NHadMulti"   ,"hJet_NHadMulti"   ,50,-0.5,49.5);
  hJet_ElecMulti   = new TH1D("hJet_ElecMulti"   ,"hJet_ElecMulti"   ,50,-0.5,49.5);
  hJet_MuonMulti   = new TH1D("hJet_MuonMulti"   ,"hJet_MuonMulti"   ,50,-0.5,49.5);
  hJet_PhotonMulti = new TH1D("hJet_PhotonMulti" ,"hJet_PhotonMulti" ,50,-0.5,49.5);

  hdPhi_Jet_MET    = new TH1D ("hdPhi_Jet_MET","hdPhi_Jet_MET", 100,-4,4);

  hJet_ParFl_bDisJP = new TProfile ("hJet_ParFl_bDisJP","hJet_ParFl_bDisJP",11,-5.5,5.5,-100,100);
  hJet_HadFl_bDisJP = new TProfile ("hJet_HadFl_bDisJP","hJet_HadFl_bDisJP",6,-0.5,5.5,-100,100);

  // hJet_ParFl_bDisJP_ProjX = new TH1D("hJet_ParFl_bDisJP_ProjX","hJet_ParFl_bDisJP_ProjX",11,-5.5,5.5);
  // hJet_HadFl_bDisJP_ProjX = new TH1D("hJet_HadFl_bDisJP_ProjX","hJet_HadFl_bDisJP_ProjX",6,-0.5,5.5);
 
  hJet_ParFl_bDisCMVA = new TProfile ("hJet_ParFl_bDisCMVA","hJet_ParFl_bDisCMVA",11,-5.5,5.5,-100,100);
  hJet_HadFl_bDisCMVA = new TProfile ("hJet_HadFl_bDisCMVA","hJet_HadFl_bDisCMVA",6,-0.5,5.5,-100,100);

  hJet_Multiplicity       = new TH1D ("hJet_Multiplicity"      ,"hJet_Multiplicity"      ,40,-0.5,39.5);
  hbJetParFl_Multiplicity = new TH1D ("hbJetParFl_Multiplicity","hbJetParFl_Multiplicity",10,-0.5,9.5);
  hbJetL_Multiplicity     = new TH1D ("hbJetL_Multiplicity"    ,"hbJetL_Multiplicity"    ,10,-0.5,9.5);
  hbJetM_Multiplicity     = new TH1D ("hbJetM_Multiplicity"    ,"hbJetM_Multiplicity"    ,10,-0.5,9.5);
  hbJetT_Multiplicity     = new TH1D ("hbJetT_Multiplicity"    ,"hbJetT_Multiplicity"    ,10,-0.5,9.5);


  hbJet_Pt          = new TH1D("hbJet_Pt"     ,"hbJet_Pt"     ,200,0,200);
  hbJet_Eta         = new TH1D("hbJet_Eta"    ,"hbJet_Eta"    ,100,-4,4);
  hbJet_Phi         = new TH1D("hbJet_Phi"    ,"hbJet_Phi"    ,200,-4,4);
  hbJet_E           = new TH1D("hbJet_E"      ,"hbJet_E"      ,200,0,200);
  hbJet_JetArea     = new TH1D("hbJet_JetArea","hbJet_JetArea",100,-4,4);
  
  hbJet_ChMulti     = new TH1D("hbJet_ChMulti"     ,"hbJet_ChMulti"     ,50,-0.5,49.5);
  hbJet_ChHadMulti  = new TH1D("hbJet_ChHadMulti"  ,"hbJet_ChHadMulti"  ,50,-0.5,49.5);
  hbJet_NMulti      = new TH1D("hbJet_NMulti"      ,"hbJet_NMulti"      ,50,-0.5,49.5);
  hbJet_NHadMulti   = new TH1D("hbJet_NHadMulti"   ,"hbJet_NHadMulti"   ,50,-0.5,49.5);
  hbJet_ElecMulti   = new TH1D("hbJet_ElecMulti"   ,"hbJet_ElecMulti"   ,50,-0.5,49.5);
  hbJet_MuonMulti   = new TH1D("hbJet_MuonMulti"   ,"hbJet_MuonMulti"   ,50,-0.5,49.5);
  hbJet_PhotonMulti = new TH1D("hbJet_PhotonMulti" ,"hbJet_PhotonMulti" ,50,-0.5,49.5);
  
  hdPhi_bJet_MET    = new TH1D ("hdPhi_bJet_MET","hdPhi_bJet_MET", 100,-4,4);


  // Gen Level Study
  hGenPV_X   = new TH1D("hGenPV_X","hGenPV_X", 100,-0.2,0.2);
  hGenPV_Y   = new TH1D("hGenPV_Y","hGenPV_Y", 100,-0.2,0.2);
  hGenPV_Z   = new TH1D("hGenPV_Z","hGenPV_Z", 100,-25,25);

  hGenMET_Et   = new TH1D("hGenMET_Et","hGenMET_Et",200,0,2000);
  hGenMET_Pt   = new TH1D("hGenMET_Pt","hGenMET_Pt",200,0,200);
  hGenNuMultiplicity = new TH1D("hGenNuMultiplicity","hGenNuMultiplicity", 15, -0.5 , 14.5);
  hMHT = new TH1D ("hMHT","hMHT", 200, 0, 2000);
  hHT  = new TH1D ("hHT" ,"hHT" , 200, 0, 2000);

  
  hGenElec_Pt       = new TH1D("hGenElec_Pt"      ,"hGenElec_Pt"      ,200,0,200);
  hGenElec_Eta      = new TH1D("hGenElec_Eta"     ,"hGenElec_Eta"     , 100,-5,5);
  hGenElec_E        = new TH1D("hGenElec_E"       ,"hGenElec_E"       ,200,0,200);
  hGenElec_RIso     = new TH1D("hGenElec_RIso"    ,"hGenElec_RIso"    , 100,0,5);
  hGenElec_Lxy      = new TH1D("hGenElec_Lxy"     ,"hGenElec_Lxy"     ,100,-5,5);
  hGenElec_Lxyz     = new TH1D("hGenElec_Lxyz"    ,"hGenElec_Lxyz"    ,100,-5,5);
  hdPhi_GenElec_MET = new TH1D("hdPhi_GenElec_MET","hdPhi_GenElec_MET", 100,-4,4);
 

  hGenMuon_Pt       = new TH1D("hGenMuon_Pt"      ,"hGenMuon_Pt"      ,200,0,200);
  hGenMuon_Eta      = new TH1D("hGenMuon_Eta"     ,"hGenMuon_Eta"     , 100,-5,5);
  hGenMuon_E        = new TH1D("hGenMuon_E"       ,"hGenMuon_E"       ,200,0,200);
  hGenMuon_RIso     = new TH1D("hGenMuon_RIso"    ,"hGenMuon_RIso"    , 100,0,5);
  hGenMuon_Lxy      = new TH1D("hGenMuon_Lxy"     ,"hGenMuon_Lxy"     ,100,-5,5);
  hGenMuon_Lxyz     = new TH1D("hGenMuon_Lxyz"    ,"hGenMuon_Lxyz"    ,100,-5,5);
  hdPhi_GenMuon_MET = new TH1D("hdPhi_GenMuon_MET","hdPhi_GenMuon_MET", 100,-4,4);
 
    
  hGenTau_Pt       = new TH1D("hGenTau_Pt"      ,"hGenTau_Pt"      ,200,0,200);
  hGenTau_Eta      = new TH1D("hGenTau_Eta"     ,"hGenTau_Eta"     , 100,-5,5);
  hGenTau_E        = new TH1D("hGenTau_E"       ,"hGenTau_E"       ,200,0,200);
  hGenTau_RIso     = new TH1D("hGenTau_RIso"    ,"hGenTau_RIso"    , 100,0,5);
  hdPhi_GenTau_MET = new TH1D("hdPhi_GenTau_MET","hdPhi_GenTau_MET", 100,-4,4);
  
  
  hbGenHad_Pt           = new TH1D("hbGenHad_Pt"          ,"hbGenHad_Pt",200,0,200);
  hbGenHad_Eta          = new TH1D("hbGenHad_Eta"         ,"hbGenHad_Eta", 100,-5,5);
  hbGenHad_E            = new TH1D("hbGenHad_E"           ,"hbGenHad_E",200,0,200);
  hdPhi_bGenHad_MET     = new TH1D("hdPhi_bGenHad_MET"    ,"hdPhi_bGenHad_MET",100,-4,4);
  hbGenHad_ChMulti      = new TH1D("hbGenHad_ChMulti"     ,"hbGenHad_ChMulti",10,-0.5,9.5);
  hbGenHad_NMulti       = new TH1D("hbGenHad_NMulti"      ,"hbGenHad_NMulti",10,-0.5,9.5);
  hbGenHad_Multiplicity = new TH1D("hbGenHad_Multiplicity","hbGenHad_Multiplicity",5,-0.5,4.5);

  hDRBJ = new TH1D ("hDRBJ","hDRBJ",100,0,2);
  
  hGenJet_Pt           = new TH1D("hGenJet_Pt"          ,"hGenJet_Pt",200,0,200);
  hGenJet_Eta          = new TH1D("hGenJet_Eta"         ,"hGenJet_Eta", 100,-5,5);
  hGenJet_E            = new TH1D("hGenJet_E"           ,"hGenJet_E",200,0,200);
  hdPhi_GenJet_MET     = new TH1D("hdPhi_GenJet_MET"    ,"hdPhi_GenJet_MET",100,-4,4);
  hGenJet_ChMulti      = new TH1D("hGenJet_ChMulti"     ,"hGenJet_ChMulti",10,-0.5,9.5);
  hGenJet_NMulti       = new TH1D("hGenJet_NMulti"      ,"hGenJet_NMulti",10,-0.5,9.5);
  hGenJet_Multiplicity = new TH1D("hGenJet_Multiplicity","hGenJet_Multiplicity",20,4.5,24.5);


}

//****************************************************************************
ParticleInfo Validation::SetParticleInfo (Double_t Pt, Double_t Eta, Double_t Phi, Double_t E, Int_t Id, Int_t Charge)
//****************************************************************************
{
  ParticleInfo temp;
  temp.Pt     = Pt;
  temp.Eta    = Eta;
  temp.Phi    = Phi;
  temp.E      = E;
  temp.PdgId  = Id;
  temp.Charge = Charge;

  return temp;
}


//****************************************************************************
void Validation::SortLepPt(vector<ParticleInfo> &vSort)
//****************************************************************************
{

  ParticleInfo temp;
  for (Size_t i = 0; i < vSort.size(); i++)
    {
        for (Size_t j = 0; j < vSort.size()-1; j++)
	  {
	    if(vSort.at(j).Pt < vSort.at(j+1).Pt)
	      {
		temp          = vSort.at(j);
		vSort.at(j)   = vSort.at(j+1);
		vSort.at(j+1) = temp;
	      }
	  }// end inner loop
    }// end outer loop
  
}

//****************************************************************************
Bool_t Validation::IsFinalGenp (Size_t MotIndx, vector<unsigned short>& Daug)
//****************************************************************************
{
  Int_t MotId = GenP_PdgId->at(MotIndx);
  
  if(Daug.size()==0) return true;
  
  for(Size_t iDau=0; iDau<Daug.size(); iDau++)
    {
      Int_t DauIndx = Daug.at(iDau);
      Int_t DauId   = GenP_PdgId->at(DauIndx);
      
      if(MotId == DauId)
	return false;
    }// end loop on daughters
  return true;
}

//****************************************************************************
Int_t Validation::GetFinalGenpIndx (Size_t MotIndx, vector<unsigned short>& Daug)
//****************************************************************************
{
  Int_t MotId = GenP_PdgId->at(MotIndx);
  
  Int_t FinalGenpIndx = MotIndx;

  if(Daug.size()==0) return FinalGenpIndx;
  
  for(Size_t iDau=0; iDau<Daug.size(); iDau++)
    {
      Int_t DauIndx = Daug.at(iDau);
      Int_t DauId   = GenP_PdgId->at(DauIndx);
      
      if(MotId == DauId)
	FinalGenpIndx = GetFinalGenpIndx(DauIndx,GenP_Daughters->at(DauIndx));
    }// end loop on daughters
  return FinalGenpIndx;
}

//****************************************************************************
Double_t Validation::RIsoLepton (Double_t Lep_Pt, Double_t Lep_Eta, Double_t Lep_Phi)
//****************************************************************************
{
  Double_t sumPtC = 0;
  Double_t sumPtN = 0;

  for(Size_t iGenp=0; iGenp<GenP_Pt->size(); iGenp++)
    {
      if(abs(GenP_PdgId->at(iGenp)) != 11 && abs(GenP_PdgId->at(iGenp)) != 13 && 
	 abs(GenP_PdgId->at(iGenp)) != 12 && abs(GenP_PdgId->at(iGenp)) != 14 && abs(GenP_PdgId->at(iGenp)) != 16)
	{
	  if(GenP_Status->at(iGenp) == 1 )
	    {
	      Double_t GenEta = GenP_Eta->at(iGenp);
	      Double_t GenPhi = GenP_Phi->at(iGenp);
	      
	      Double_t dR = auxTools_.DeltaR(GenEta,GenPhi,
					     Lep_Eta,Lep_Phi);
	      //	cout<<"\tDR\t"<<dR<<endl;
	      if(dR <0.4)
		{
		  if(GenP_Charge->at(iGenp) != 0) sumPtC += GenP_Pt->at(iGenp);
		  if(GenP_Charge->at(iGenp) == 0)sumPtN += GenP_Pt->at(iGenp);
		}//	  
	    }//status 1
	}//if not electron genp
    }// end loop on Genp
  Double_t RIso = (sumPtC+sumPtN)/Lep_Pt;
  return RIso;
}

//****************************************************************************
Int_t Validation::DecayMode ()
//****************************************************************************
{

  Int_t DecayMode=0;

  Int_t tIndx = -1;
  Int_t tbarIndx = -1;
  Int_t HIndx = -1;
  
  Int_t WptIndx=-1;
  Int_t WmtbarIndx=-1;
  Int_t WpHIndx=-1;
  Int_t WmHIndx=-1;
  Int_t TpHIndx=-1;
  Int_t TmHIndx=-1;
  Int_t Z1HIndx=-1;
  Int_t Z2HIndx=-1;

  //  cout<<"\tEvtNumber\t"<<EvtNumber<<endl;
  
  for (Size_t iGenp=0; iGenp<GenP_Pt->size(); iGenp++)
    {
      //*********************************************
      // TOP QUARK
      //*********************************************
      if (GenP_PdgId->at(iGenp) == 6)
	{
	  vector<unsigned short> tDau = GenP_Daughters->at(iGenp);
	  if(IsFinalGenp(iGenp, tDau ))
	    {
	      tIndx = iGenp;
	      for(Size_t iDau=0; iDau<tDau.size(); iDau++)
		{
		  Size_t DauIndx = tDau.at(iDau);
		  if(GenP_PdgId->at(DauIndx) == 24)
		    {
		      WptIndx = GetFinalGenpIndx(DauIndx, GenP_Daughters->at(DauIndx));
		    }// if W
		}// loop on t dau
	    }//final top
	}//end if Top
      //*********************************************

      //*********************************************
      // Anti TOP QUARK
      //*********************************************
      if (GenP_PdgId->at(iGenp) == -6)
	{
	  vector<unsigned short> tbarDau = GenP_Daughters->at(iGenp);
	  if(IsFinalGenp(iGenp, tbarDau ))
	    {
	      tbarIndx = iGenp;
	      for(Size_t iDau=0; iDau<tbarDau.size(); iDau++)
		{
		  Size_t DauIndx = tbarDau.at(iDau);
		  if(GenP_PdgId->at(DauIndx) == -24)
		    {
		      WmtbarIndx = GetFinalGenpIndx(DauIndx, GenP_Daughters->at(DauIndx));
		    }// if W
		}// loop on t dau
	    }//final Antitop
	}//end if AntiTop
      //*********************************************

      //*********************************************
      // Higgs
      //*********************************************
      if (GenP_PdgId->at(iGenp) == 25)
	{
	  vector<unsigned short> HDau = GenP_Daughters->at(iGenp);
	  Bool_t bhasZ1 = false;
	  if(IsFinalGenp(iGenp, HDau ))
	    {
	      HIndx = iGenp;
	      for(Size_t iDau=0; iDau<HDau.size(); iDau++)
		{
		  Size_t DauIndx = HDau.at(iDau);
		  if(GenP_PdgId->at(DauIndx) == -24)
		    {
		      WmHIndx = GetFinalGenpIndx(DauIndx, GenP_Daughters->at(DauIndx));
		    }// if W
		  if(GenP_PdgId->at(DauIndx) == +24)
		    {
		      WpHIndx = GetFinalGenpIndx(DauIndx, GenP_Daughters->at(DauIndx));
		    }// if W
		  if(GenP_PdgId->at(DauIndx) == -15)
		    {
		      TmHIndx = GetFinalGenpIndx(DauIndx, GenP_Daughters->at(DauIndx));
		    }// if T
		  if(GenP_PdgId->at(DauIndx) == 15)
		    {
		      TpHIndx = GetFinalGenpIndx(DauIndx, GenP_Daughters->at(DauIndx));
		    }// if T
		  if(GenP_PdgId->at(DauIndx) == 23)
		    {
		      if(!bhasZ1)
			{
			  Z1HIndx = GetFinalGenpIndx(DauIndx, GenP_Daughters->at(DauIndx));
			  bhasZ1 = true;
			}
		      else 
			Z2HIndx = GetFinalGenpIndx(DauIndx, GenP_Daughters->at(DauIndx));
		    }// if Z
		}// loop on t dau
	    }//final Higgs
	}//end if Higgs
      //*********************************************
    }//end loop on Genp
  if(TpHIndx != -1)
    {
      if(!IsLeptonic(WptIndx) && !IsLeptonic(WmtbarIndx) && !IsLeptonic(TpHIndx) && !IsLeptonic(TmHIndx)) DecayMode = 1;
      if(!IsLeptonic(WptIndx) &&  IsLeptonic(WmtbarIndx) && !IsLeptonic(TpHIndx) && !IsLeptonic(TmHIndx)) DecayMode = 2;
      if( IsLeptonic(WptIndx) && !IsLeptonic(WmtbarIndx) && !IsLeptonic(TpHIndx) && !IsLeptonic(TmHIndx)) DecayMode = 3;
      if( IsLeptonic(WptIndx) &&  IsLeptonic(WmtbarIndx) && !IsLeptonic(TpHIndx) && !IsLeptonic(TmHIndx)) DecayMode = 4;
      if(!IsLeptonic(WptIndx) && !IsLeptonic(WmtbarIndx) &&  IsLeptonic(TpHIndx) && !IsLeptonic(TmHIndx)) DecayMode = 5;
      if(!IsLeptonic(WptIndx) && !IsLeptonic(WmtbarIndx) && !IsLeptonic(TpHIndx) &&  IsLeptonic(TmHIndx)) DecayMode = 6;
     

      if(!IsLeptonic(WptIndx) &&  IsLeptonic(WmtbarIndx) &&  IsLeptonic(TpHIndx) && !IsLeptonic(TmHIndx)) DecayMode = 7;
      if(!IsLeptonic(WptIndx) &&  IsLeptonic(WmtbarIndx) && !IsLeptonic(TpHIndx) &&  IsLeptonic(TmHIndx)) DecayMode = 8;
      if( IsLeptonic(WptIndx) && !IsLeptonic(WmtbarIndx) &&  IsLeptonic(TpHIndx) && !IsLeptonic(TmHIndx)) DecayMode = 9;
      if( IsLeptonic(WptIndx) && !IsLeptonic(WmtbarIndx) && !IsLeptonic(TpHIndx) &&  IsLeptonic(TmHIndx)) DecayMode = 10;
      if( IsLeptonic(WptIndx) &&  IsLeptonic(WmtbarIndx) &&  IsLeptonic(TpHIndx) && !IsLeptonic(TmHIndx)) DecayMode = 11;
      if( IsLeptonic(WptIndx) &&  IsLeptonic(WmtbarIndx) && !IsLeptonic(TpHIndx) &&  IsLeptonic(TmHIndx)) DecayMode = 12;
      
      if(!IsLeptonic(WptIndx) && !IsLeptonic(WmtbarIndx) &&  IsLeptonic(TpHIndx) &&  IsLeptonic(TmHIndx)) DecayMode = 13;
      if(!IsLeptonic(WptIndx) &&  IsLeptonic(WmtbarIndx) &&  IsLeptonic(TpHIndx) &&  IsLeptonic(TmHIndx)) DecayMode = 14;
      if( IsLeptonic(WptIndx) && !IsLeptonic(WmtbarIndx) &&  IsLeptonic(TpHIndx) &&  IsLeptonic(TmHIndx)) DecayMode = 15;
      if( IsLeptonic(WptIndx) &&  IsLeptonic(WmtbarIndx) &&  IsLeptonic(TpHIndx) &&  IsLeptonic(TmHIndx)) DecayMode = 16;
    }
  
  if(Z2HIndx != -1)
    {
      if(!IsLeptonic(WptIndx) && !IsLeptonic(WmtbarIndx) && !IsLeptonic(Z1HIndx) && !IsLeptonic(Z2HIndx)) DecayMode = 17;
      if(!IsLeptonic(WptIndx) &&  IsLeptonic(WmtbarIndx) && !IsLeptonic(Z1HIndx) && !IsLeptonic(Z2HIndx)) DecayMode = 18;
      if( IsLeptonic(WptIndx) && !IsLeptonic(WmtbarIndx) && !IsLeptonic(Z1HIndx) && !IsLeptonic(Z2HIndx)) DecayMode = 19;
      if( IsLeptonic(WptIndx) &&  IsLeptonic(WmtbarIndx) && !IsLeptonic(Z1HIndx) && !IsLeptonic(Z2HIndx)) DecayMode = 20;
      if(!IsLeptonic(WptIndx) && !IsLeptonic(WmtbarIndx) &&  IsLeptonic(Z1HIndx) && !IsLeptonic(Z2HIndx)) DecayMode = 21;
      if(!IsLeptonic(WptIndx) && !IsLeptonic(WmtbarIndx) && !IsLeptonic(Z1HIndx) &&  IsLeptonic(Z2HIndx)) DecayMode = 22;
     

      if(!IsLeptonic(WptIndx) &&  IsLeptonic(WmtbarIndx) &&  IsLeptonic(Z1HIndx) && !IsLeptonic(Z2HIndx)) DecayMode = 23;
      if(!IsLeptonic(WptIndx) &&  IsLeptonic(WmtbarIndx) && !IsLeptonic(Z1HIndx) &&  IsLeptonic(Z2HIndx)) DecayMode = 24;
      if( IsLeptonic(WptIndx) && !IsLeptonic(WmtbarIndx) &&  IsLeptonic(Z1HIndx) && !IsLeptonic(Z2HIndx)) DecayMode = 25;
      if( IsLeptonic(WptIndx) && !IsLeptonic(WmtbarIndx) && !IsLeptonic(Z1HIndx) &&  IsLeptonic(Z2HIndx)) DecayMode = 26;
      if( IsLeptonic(WptIndx) &&  IsLeptonic(WmtbarIndx) &&  IsLeptonic(Z1HIndx) && !IsLeptonic(Z2HIndx)) DecayMode = 27;
      if( IsLeptonic(WptIndx) &&  IsLeptonic(WmtbarIndx) && !IsLeptonic(Z1HIndx) &&  IsLeptonic(Z2HIndx)) DecayMode = 28;
      
      if(!IsLeptonic(WptIndx) && !IsLeptonic(WmtbarIndx) &&  IsLeptonic(Z1HIndx) &&  IsLeptonic(Z2HIndx)) DecayMode = 29;
      if(!IsLeptonic(WptIndx) &&  IsLeptonic(WmtbarIndx) &&  IsLeptonic(Z1HIndx) &&  IsLeptonic(Z2HIndx)) DecayMode = 30;
      if( IsLeptonic(WptIndx) && !IsLeptonic(WmtbarIndx) &&  IsLeptonic(Z1HIndx) &&  IsLeptonic(Z2HIndx)) DecayMode = 31;
      if( IsLeptonic(WptIndx) &&  IsLeptonic(WmtbarIndx) &&  IsLeptonic(Z1HIndx) &&  IsLeptonic(Z2HIndx)) DecayMode = 32;
    }

  if(WpHIndx != -1)
    {
      if(!IsLeptonic(WptIndx) && !IsLeptonic(WmtbarIndx) && !IsLeptonic(WpHIndx) && !IsLeptonic(WmHIndx)) DecayMode = 33;
      if(!IsLeptonic(WptIndx) &&  IsLeptonic(WmtbarIndx) && !IsLeptonic(WpHIndx) && !IsLeptonic(WmHIndx)) DecayMode = 34;
      if( IsLeptonic(WptIndx) && !IsLeptonic(WmtbarIndx) && !IsLeptonic(WpHIndx) && !IsLeptonic(WmHIndx)) DecayMode = 35;
      if( IsLeptonic(WptIndx) &&  IsLeptonic(WmtbarIndx) && !IsLeptonic(WpHIndx) && !IsLeptonic(WmHIndx)) DecayMode = 36;
      if(!IsLeptonic(WptIndx) && !IsLeptonic(WmtbarIndx) &&  IsLeptonic(WpHIndx) && !IsLeptonic(WmHIndx)) DecayMode = 37;
      if(!IsLeptonic(WptIndx) && !IsLeptonic(WmtbarIndx) && !IsLeptonic(WpHIndx) &&  IsLeptonic(WmHIndx)) DecayMode = 38;
     

      if(!IsLeptonic(WptIndx) &&  IsLeptonic(WmtbarIndx) &&  IsLeptonic(WpHIndx) && !IsLeptonic(WmHIndx)) DecayMode = 39;
      if(!IsLeptonic(WptIndx) &&  IsLeptonic(WmtbarIndx) && !IsLeptonic(WpHIndx) &&  IsLeptonic(WmHIndx)) DecayMode = 40;
      if( IsLeptonic(WptIndx) && !IsLeptonic(WmtbarIndx) &&  IsLeptonic(WpHIndx) && !IsLeptonic(WmHIndx)) DecayMode = 41;
      if( IsLeptonic(WptIndx) && !IsLeptonic(WmtbarIndx) && !IsLeptonic(WpHIndx) &&  IsLeptonic(WmHIndx)) DecayMode = 42;
      if( IsLeptonic(WptIndx) &&  IsLeptonic(WmtbarIndx) &&  IsLeptonic(WpHIndx) && !IsLeptonic(WmHIndx)) DecayMode = 43;
      if( IsLeptonic(WptIndx) &&  IsLeptonic(WmtbarIndx) && !IsLeptonic(WpHIndx) &&  IsLeptonic(WmHIndx)) DecayMode = 44;
      
      if(!IsLeptonic(WptIndx) && !IsLeptonic(WmtbarIndx) &&  IsLeptonic(WpHIndx) &&  IsLeptonic(WmHIndx)) DecayMode = 45;
      if(!IsLeptonic(WptIndx) &&  IsLeptonic(WmtbarIndx) &&  IsLeptonic(WpHIndx) &&  IsLeptonic(WmHIndx)) DecayMode = 46;
      if( IsLeptonic(WptIndx) && !IsLeptonic(WmtbarIndx) &&  IsLeptonic(WpHIndx) &&  IsLeptonic(WmHIndx)) DecayMode = 47;
      if( IsLeptonic(WptIndx) &&  IsLeptonic(WmtbarIndx) &&  IsLeptonic(WpHIndx) &&  IsLeptonic(WmHIndx)) DecayMode = 48;
    }


  return DecayMode;
  // if(TpHIndx!=-1){
    
    // cout<< "W+ from Top\t"<<WptIndx<<"\tW- from AntiTop\t"<<WmtbarIndx<<endl;
    // cout<<"\tFrom Higgs\t"<<HIndx<<"\t\t"<<GenP_Pt->at(HIndx)<<endl;
    // cout<< "W+\t"<<WpHIndx<<"\tW-\t"<<WmHIndx<< "\tT+\t"<<TpHIndx<<"\tT-\t"<<TmHIndx<< "\tZ1\t"<<Z1HIndx<<"\tZ2\t"<<Z2HIndx<<endl;
  //  }
  //    cout<<"\n_________________________________________________________________________________________________________\n\n";
  
}


//****************************************************************************
Bool_t Validation::IsLeptonic (Size_t Index)
//****************************************************************************
{								
  Bool_t isLeptonic = false;
  vector<unsigned short> vDau = GenP_Daughters->at(Index);
  for(Size_t iDau=0; iDau<vDau.size(); iDau++)
    {
      Size_t DauIndx = vDau.at(iDau);
      if(abs(GenP_PdgId->at(DauIndx)) == 11 || abs(GenP_PdgId->at(DauIndx)) == 13)
	{
	  isLeptonic = true;
	  break;
	}
    }

  return isLeptonic;
}

//****************************************************************************
Bool_t Validation::IsFinalBHadron(Int_t Index)
//****************************************************************************
{
  Int_t Gen_ID = GenP_PdgId->at(Index);
  Int_t Mod = abs(Gen_ID)%10000;
  Int_t Had = 0;
  Bool_t isFinalBHad = true;
  if(Mod > 1000)
    Had=Mod/1000;
  else if(Mod < 1000)
    Had=Mod/100;
  
  if(Had != 5)
    isFinalBHad = false; // not BHad
  if(Had == 5)
    {
      vector <unsigned short> vBHadDau;
      vBHadDau = GenP_Daughters->at(Index);
      for(Size_t iDau=0; iDau<vBHadDau.size(); iDau++)
	{
	  Size_t DauIndx = vBHadDau.at(iDau);
	  Int_t  DauId   = GenP_PdgId->at(DauIndx);
	  Int_t  DauMod  = abs(DauId)%10000;
	  Int_t  DauHad  = 0;
	  if(DauMod > 1000)
	    DauHad=DauMod/1000;
	  else if(DauMod < 1000)
	    DauHad=DauMod/100;
	  if(DauHad == Had)
	    isFinalBHad = false; // not final BHAd
	}// loop on Dau
    }


  return isFinalBHad;
}

//**************************************************
void Validation::GetFinalDaughters(Size_t Indx, 
				   vector<Size_t> &vFinalDau)
//**************************************************
{
  vector<unsigned short> vDau = GenP_Daughters->at(Indx);
  for(Size_t iDau=0; iDau<vDau.size(); iDau++)
    {
      Int_t DauIndx = vDau.at(iDau);
      Int_t DauStat = GenP_Status->at(DauIndx);
      Bool_t usedDau = false;

      for(Size_t ifd=0; ifd<vFinalDau.size(); ifd++ )
	{
	  if(DauIndx == vFinalDau.at(ifd))
	    usedDau = true;
	}
      if(usedDau) continue;

      if(DauStat == 1)
	{
	  vFinalDau.push_back(DauIndx);
	}
      else if(DauStat > 1)
	{
	  GetFinalDaughters(DauIndx,vFinalDau);
	}
    }
}


//**************************************************
void Validation::myPrintGenp(Size_t Indx, bool bPrintHeaders)
//**************************************************
{
  unsigned int moth1 = 0;
  unsigned int moth2 = 0;
  unsigned int daug1 = 0;
  unsigned int daug2 = 0;
  unsigned int NDaug;
  static Int_t evOld = 0;

  ofstream myfile;
  myfile.open ("PrintGenp.txt", ios::app);

  if ( (evOld != EvtNumber) || (Indx == 0) ) {
    myfile << std::endl;
    evOld = EvtNumber;

    if (bPrintHeaders)
      {
	myfile //<< std::setw(10)  << ">>> Run"
	       << std::setw(10)  << "Event"
	       << std::setw(10)  << "Indx"  
	       << std::setw(10) << "Id" 
	       << std::setw(10)  << "Status"
	       << std::setw(10)  << "Mot1"
	       << std::setw(10)  << "Mot2"
	       << std::setw(10)  << "Dau1"
	       << std::setw(10)  << "Dau2"
	       << std::setw(10)  << "px"
	       << std::setw(10) << "py"
	       << std::setw(10) << "pz"
	       << std::setw(10) << "E"
	       << std::setw(10) << "Eta"
	       << std::setw(10) << "Phi"
	       << std::setw(10) << "M"
	       << std::setw(10) << "Vtx-Z"
	       << std::endl;
      }
  }
  if (GenP_Mothers->at(Indx).size() > 0) moth1 = GenP_Mothers->at(Indx).at(0);
  if (GenP_Mothers->at(Indx).size() > 1) moth2 = GenP_Mothers->at(Indx).at(1);
  NDaug = GenP_Daughters->at(Indx).size();
  if (NDaug > 0){
    daug1 = GenP_Daughters->at(Indx).at(0); // First Daughter index
    if (NDaug > 1) {
      daug2 = daug1 + NDaug -1;          // Last Daughter index 
      if (GenP_Daughters->at(Indx).at(NDaug-1) != daug2) daug2 -=1;
    }
  }
  double mass = GenP_M->at(Indx);
  double pt   = GenP_Pt->at(Indx);
  double phi  = GenP_Phi->at(Indx);
  double eta  = GenP_Eta->at(Indx);

  TLorentzVector pGen;
  pGen.SetPtEtaPhiM(pt,eta,phi,mass);
  double ene = pGen.E();
  double px  = pGen.Px();
  double py  = pGen.Py();
  double pz  = pGen.Pz();
  myfile << std::fixed;
  myfile //<< std::setw(10) << std::setprecision(0) << RunNumber
	 << std::setw(10) << std::setprecision(0) << EvtNumber
	 << std::setw(10) << std::setprecision(0) << Indx
	 << std::setw(10) << std::setprecision(0) << GenP_PdgId->at(Indx)
	 << std::setw(10) << std::setprecision(0) << GenP_Status->at(Indx)
	 << std::setw(10) << std::setprecision(0) << moth1
	 << std::setw(10) << std::setprecision(0) << moth2
	 << std::setw(10) << std::setprecision(0) << daug1
	 << std::setw(10) << std::setprecision(0) << daug2
	 << std::setw(10) << std::setprecision(3) << px
	 << std::setw(10) << std::setprecision(3) << py
	 << std::setw(10) << std::setprecision(3) << pz
	 << std::setw(10) << std::setprecision(3) << ene
	 << std::setw(10) << std::setprecision(3) << eta
	 << std::setw(10) << std::setprecision(3) << phi
	 << std::setw(10) << std::setprecision(3) << mass
	 << std::setw(10) << std::setprecision(3) << GenP_VertexZ->at(Indx)
	 << std::endl;
}

#endif // Validation_cxx
//Dump
	// //************************************************
	// //Genp Check for decay mode
	// //************************************************	
	// float tau_eta = Tau_Eta -> at(iTau);
	// float tau_phi = Tau_Phi -> at(iTau);
	// Size_t nGenp = GenP_Pt->size();
	// for(Size_t iGenp=0; iGenp<nGenp; iGenp++)
	//   {
	//     //if(GenP_PdgId->at(iGenp) == Tau_Id->at(iTau))
	//     if(abs(GenP_PdgId->at(iGenp)) == 15)
	//       {
	// 	if(IsFinalGenp(iGenp,GenP_Daughters->at(iGenp)))
	// 	  {
	// 	    float genTau_eta = GenP_Eta->at(iGenp);
	// 	    float genTau_phi = GenP_Phi->at(iGenp);
		    
	// 	    float dr = auxTools_.DeltaR(tau_eta, tau_phi,
	// 					genTau_eta, genTau_phi);
	// 	    cout<<"\tThis is tau \t"<<"\tNTaus\t"<<nTau<<"\t\t"<< dr<<endl;
		    
	// 	    tauinGen++;
		    
	// 	  }
	//       }
	//   }
