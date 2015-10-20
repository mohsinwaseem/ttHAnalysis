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

  Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry=0; jentry<nentries;jentry++)
  {
    if(jentry%1000 == 0)
      std::cout << "Loop over entry " << jentry << "/" << nentries << ".\n";
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);   nbytes += nb;
    // if (Cut(ientry) < 0) continue;
    
    //**************************************************************************************************************************************************
    //**************************************************************************************************************************************************
    //--------------------------------------------------------------------Kinematics--------------------------------------------------------------------
    //**************************************************************************************************************************************************
    //**************************************************************************************************************************************************

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
	
      }//end loop on Electons
    //*************************************************************************


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

      }//end loop on Muons
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
	  
	  }

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
	
      }//end loop on Jets
    //*************************************************************************


    // Update the progress bar
    //    tools.ProgressBar(jentry, nentries, 100, 150);
  
  }//end loop on entries


  // Keep this line here!
  outFile->cd();

  // Create and write canvases here
  

  // Uncomment this line to write also the histograms to the file
  outFile->Write();
}

//#################################################
void Validation::MakeHisto(void)
//#################################################
{

  //Electron***************************************************************************
  hElec_Pt                      = new TH1D ("hElec_Pt","hElec_Pt",200,0,200);
  hElec_Eta                     = new TH1D ("hElec_Eta","hElec_Eta",100,-4,4);
  hElec_Phi                     = new TH1D ("hElec_Phi","hElec_Phi",100,-4,4);
  hElec_E                       = new TH1D ("hElec_E","hElec_E",200,0,200);
  hElec_Charge                  = new TH1D ("hElec_Charge","hElec_Charge",5,-2,2);
  
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
 

  //Muon***************************************************************************
  hMuon_Pt                         = new TH1D ("hMuon_Pt","hMuon_Pt",200,0,200);
  hMuon_Eta                        = new TH1D ("hMuon_Eta","hMuon_Eta",100,-4,4);
  hMuon_Phi                        = new TH1D ("hMuon_Phi","hMuon_Phi",100,-4,4);
  hMuon_E                          = new TH1D ("hMuon_E","hMuon_E",200,0,200);
  hMuon_Charge                     = new TH1D ("hMuon_Charge","hMuon_Charge",5,-2,2);
  
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

  
  //Tau***************************************************************************
  hTau_Pt                   = new TH1D ("hTau_Pt","hTau_Pt",200,0,200);
  hTau_Eta                  = new TH1D ("hTau_Eta","hTau_Eta",100,-4,4);
  hTau_Phi                  = new TH1D ("hTau_Phi","hTau_Phi",100,-4,4);
  hTau_E                    = new TH1D ("hTau_E","hTau_E",200,0,200);
  hTau_Charge               = new TH1D ("hTau_Charge","hTau_Charge",5,-2,2);
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
  
  hJet_ChMulti     = new TH1D("hJet_ChMulti"     ,"hJet_ChMulti"     ,50,0,50);
  hJet_ChHadMulti  = new TH1D("hJet_ChHadMulti"  ,"hJet_ChHadMulti"  ,50,0,50);
  hJet_NMulti      = new TH1D("hJet_NMulti"      ,"hJet_NMulti"      ,50,0,50);
  hJet_NHadMulti   = new TH1D("hJet_NHadMulti"   ,"hJet_NHadMulti"   ,50,0,50);
  hJet_ElecMulti   = new TH1D("hJet_ElecMulti"   ,"hJet_ElecMulti"   ,50,0,50);
  hJet_MuonMulti   = new TH1D("hJet_MuonMulti"   ,"hJet_MuonMulti"   ,50,0,50);
  hJet_PhotonMulti = new TH1D("hJet_PhotonMulti" ,"hJet_PhotonMulti" ,50,0,50);
  
  hJet_ParFl_bDisJP = new TProfile ("hJet_ParFl_bDisJP","hJet_ParFl_bDisJP",11,-5.5,5.5,-100,100);
  hJet_HadFl_bDisJP = new TProfile ("hJet_HadFl_bDisJP","hJet_HadFl_bDisJP",6,-0.5,5.5,-100,100);
    
  hJet_ParFl_bDisCMVA = new TProfile ("hJet_ParFl_bDisCMVA","hJet_ParFl_bDisCMVA",11,-5.5,5.5,-100,100);
  hJet_HadFl_bDisCMVA = new TProfile ("hJet_HadFl_bDisCMVA","hJet_HadFl_bDisCMVA",6,-0.5,5.5,-100,100);
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
