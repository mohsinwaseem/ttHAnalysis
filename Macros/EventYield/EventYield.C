#ifndef EventYield_cxx
#define EventYield_cxx

#include "EventYield.h"
#include "../utilities/constants.h"

#include <TRandom3.h>

void EventYield::Loop()
{
  if (fChain == 0) return;

  Long64_t nentries = (MaxEvents == -1) ? fChain->GetEntries() : std::min((int)fChain->GetEntries(), MaxEvents);

  std::cout << "Analyzing " << nentries << " events.\n";

  
  //  CalculateEventExpectation();

  // Book histograms here





  Double_t nHtoTT=0.0;
  Double_t nHtoZZ=0.0;
  Double_t nHtoWW=0.0;
  Double_t nHtoBB=0.0;

  Double_t n2lssHTT=0.0;
  Double_t n2lssHZZ=0.0;
  Double_t n2lssHWW=0.0;
  Double_t n2lssbbHTT=0.0;
  Double_t n2lssbbHZZ=0.0;
  Double_t n2lssbbHWW=0.0;

  Double_t n3lHTT=0.0;
  Double_t n3lHZZ=0.0;
  Double_t n3lHWW=0.0;
  Double_t n3lbbHTT=0.0;
  Double_t n3lbbHZZ=0.0;
  Double_t n3lbbHWW=0.0;

  Double_t n4lHTT=0.0;
  Double_t n4lHZZ=0.0;
  Double_t n4lHWW=0.0;
  Double_t n4lbbHTT=0.0;
  Double_t n4lbbHZZ=0.0;
  Double_t n4lbbHWW=0.0;

  Double_t totalfucking2lss=0.0;

  Double_t Lumi = 19.6;//fb-1
  Double_t Sigma = 130.2; //fb  508.5;//
  Double_t nEvtLumi = Sigma*Lumi;
  Double_t Weight =  nEvtLumi/nentries;

  Int_t nHiggs=0;
  Int_t nWplus=0;
  Int_t nWMinus=0;
  Int_t nTest=0;

  
  Double_t nW = 0.0;
  Double_t nWL = 0.0;
  
  Double_t nZ = 0.0;
  Double_t nZL = 0.0;

  Double_t nT = 0.0;
  Double_t nTL = 0.0;

  // TH1D* test;
  // test = new TH1D("test","test",10000,0,1);
  
  Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry=0; jentry<nentries;jentry++)
  {

    //    TRandom3 r;
    //    cout<< r.Rndm(5)<<endl;
    //  cout<< r.Uniform(rand()%100/100.0)<<endl;
    //    test->Fill(r.Uniform(rand()%100/100.0));


    // float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX); 
    // cout<<r <<endl;

    if(jentry%1000 == 0)
      std::cout << "Loop over entry " << jentry << "/" << nentries << ".\n";
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);   nbytes += nb;
    // if (Cut(ientry) < 0) continue;
    //    cout<<"\tThis is Genp\t"<<GenP_PdgId->size()<<endl;
    Size_t nGenp = GenP_Pt->size();
    // cout<< nGenp<<endl;

    // for(Size_t i=0; i<nGenp; i++)
    //   {
    // 	if(EvtNumber == 881422 || EvtNumber == 924723 || EvtNumber == 435239)
    // 	  myPrintGenp(i,true);
    //   }

    ttHParIndx lIndex;
    //   lIndex.init();
    lIndex = GetttHParIndices();

    if(lIndex.H != -1) nHiggs++;
    if(lIndex.Wpfromt != -1) nWplus++;
    if(lIndex.Wmfromtbar != -1) nWMinus++;

    // cout<< EvtNumber<<endl;

    // cout<< lIndex.t<<"\t\t"<< lIndex.tbar<<"\t\t"<< lIndex.H<<endl
    //  	<<"\t\t"<<lIndex.Wpfromt<<"\t\t"<<lIndex.Wmfromtbar<<endl
    //  	<<"\t\t"<<lIndex.WpfromH<<"\t\t"<<lIndex.WmfromH<<"\t\t"<<lIndex.TpfromH<<"\t\t"<<lIndex.TmfromH<<"\t\t"<<lIndex.Z1fromH<<"\t\t"<<lIndex.Z2fromH<<endl;
    // cout<<EvtNumber<<"\n\n___________________________________________________________________________________________________________________\n"<<endl;


    //Step1: Basic Acceptance of e, mu, and bhad.
    vector<ParticleInfo> vGenLep;
    vector<ParticleInfo> vGenBHad;
   
    // Get Leptons from indices found above....
    
    if(lIndex.Wpfromt != -1)      GetLeptonEntries(lIndex.Wpfromt    ,vGenLep);
    if(lIndex.TpfromWpt != -1)    GetLeptonEntries(lIndex.TpfromWpt  ,vGenLep);
   
    if(lIndex.Wmfromtbar != -1)   GetLeptonEntries(lIndex.Wmfromtbar  ,vGenLep);
    if(lIndex.TmfromWmtbar != -1) GetLeptonEntries(lIndex.TmfromWmtbar,vGenLep);

    if(lIndex.WpfromH != -1)      GetLeptonEntries(lIndex.WpfromH   ,vGenLep);
    if(lIndex.TpfromWpH != -1)    GetLeptonEntries(lIndex.TpfromWpH   ,vGenLep);
    
    if(lIndex.WmfromH != -1)      GetLeptonEntries(lIndex.WmfromH   ,vGenLep);
    if(lIndex.TmfromWmH != -1)    GetLeptonEntries(lIndex.TmfromWmH   ,vGenLep);

    if(lIndex.TpfromH != -1)      GetLeptonEntries(lIndex.TpfromH   ,vGenLep);
    if(lIndex.TmfromH != -1)      GetLeptonEntries(lIndex.TmfromH   ,vGenLep);
    
    if(lIndex.Z1fromH != -1)      GetLeptonEntries(lIndex.Z1fromH   ,vGenLep);
    if(lIndex.TpfromZ1H != -1)    GetLeptonEntries(lIndex.TpfromZ1H   ,vGenLep);
    if(lIndex.TmfromZ1H != -1)    GetLeptonEntries(lIndex.TmfromZ1H   ,vGenLep);

    if(lIndex.Z2fromH != -1)      GetLeptonEntries(lIndex.Z2fromH   ,vGenLep);
    if(lIndex.TpfromZ2H != -1)    GetLeptonEntries(lIndex.TpfromZ2H   ,vGenLep);
    if(lIndex.TmfromZ2H != -1)    GetLeptonEntries(lIndex.TmfromZ2H   ,vGenLep);


    //*********************************************************************************
    //Checking Leptong Branching....W
    if(lIndex.Wpfromt != -1)    {nW++;	nWL+=CheckLeptonBranching(lIndex.Wpfromt);}
    if(lIndex.Wmfromtbar != -1) {nW++;	nWL+=CheckLeptonBranching(lIndex.Wmfromtbar);}
    if(lIndex.WmfromH != -1)    {nW++;	nWL+=CheckLeptonBranching(lIndex.WmfromH);}
    if(lIndex.WpfromH != -1)    {nW++;	nWL+=CheckLeptonBranching(lIndex.WpfromH);}


    //Checking Leptong Branching....T
    if(lIndex.TpfromWpt != -1)    {nT++; nTL+=CheckLeptonBranching(lIndex.TpfromWpt);}
    if(lIndex.TmfromWmtbar != -1) {nT++; nTL+=CheckLeptonBranching(lIndex.TmfromWmtbar);}
    if(lIndex.TpfromWpH != -1)    {nT++; nTL+=CheckLeptonBranching(lIndex.TpfromWpH);}
    if(lIndex.TmfromWmH != -1)    {nT++; nTL+=CheckLeptonBranching(lIndex.TmfromWmH);}
    if(lIndex.TpfromH != -1)      {nT++; nTL+=CheckLeptonBranching(lIndex.TpfromH);}
    if(lIndex.TmfromH != -1)      {nT++; nTL+=CheckLeptonBranching(lIndex.TmfromH);}
    if(lIndex.TpfromZ1H != -1)    {nT++; nTL+=CheckLeptonBranching(lIndex.TpfromZ1H);}
    if(lIndex.TmfromZ1H != -1)    {nT++; nTL+=CheckLeptonBranching(lIndex.TmfromZ1H);}
    if(lIndex.TpfromZ2H != -1)    {nT++; nTL+=CheckLeptonBranching(lIndex.TpfromZ2H);}
    if(lIndex.TmfromZ2H != -1)    {nT++; nTL+=CheckLeptonBranching(lIndex.TmfromZ2H);}


    //Checking Leptong Branching....Z
    if(lIndex.Z1fromH != -1)      {nZ++; nZL+=CheckLeptonBranching(lIndex.Z1fromH);}
    if(lIndex.Z2fromH != -1)      {nZ++; nZL+=CheckLeptonBranching(lIndex.Z2fromH);}
    //*********************************************************************************




    // if(vGenLep.size()>1)cout<<"\n\n___________________________________________________________________________________________________________________\n"<<EvtNumber<<endl;
    // if(vGenLep.size()>1) cout<< vGenLep.size()<<"\t\t"<<vGenLep.at(0).Pt<<"\t"<<vGenLep.at(0).PdgId<<"\t\t"<<vGenLep.at(0).Indx<<endl;
    // if(vGenLep.size()>1) cout<< vGenLep.size()<<"\t\t"<<vGenLep.at(1).Pt<<"\t"<<vGenLep.at(1).PdgId<<"\t\t"<<vGenLep.at(1).Indx<<endl;
    // if(vGenLep.size()>2) cout<< vGenLep.size()<<"\t\t"<<vGenLep.at(2).Pt<<"\t"<<vGenLep.at(2).PdgId<<"\t\t"<<vGenLep.at(2).Indx<<endl;
    // if(vGenLep.size()>3) cout<< vGenLep.size()<<"\t\t"<<vGenLep.at(3).Pt<<"\t"<<vGenLep.at(3).PdgId<<"\t\t"<<vGenLep.at(3).Indx<<endl;
    
    for(Size_t iGenp = 0; iGenp<nGenp; iGenp++)
      {

    	if(IsFinalBHadron(iGenp))
    	  {
	    //	    cout<< iGenp<<"\t"<<GenP_PdgId->at(iGenp)<<endl;
    	    if(GenP_Pt->at(iGenp)>25 && abs(GenP_Eta->at(iGenp))<2.5)
    	      {
    		ParticleInfo BHad;
    		BHad =  SetParticleInfo (iGenp,
    					 GenP_Pt->at(iGenp),
    					 GenP_Eta->at(iGenp),
    					 GenP_Phi->at(iGenp),
    					 GenP_E->at(iGenp),
    					 GenP_PdgId->at(iGenp),
    					 GenP_Charge->at(iGenp));
    		vGenBHad.push_back(BHad);
    	      }//if within acceptance
    	  }// if final BHadron
      }// end loop on Genp

    //Step2: Simulate Trigger Lep Pt (20,10)
    Bool_t bPassTrg=false;

    SortLepPt(vGenLep);

    if(vGenLep.size()>1)// atleast 2 leptons
      {
	// cout<<vGenLep.at(0).PdgId<<"\t\t"<<vGenLep.at(1).PdgId<<endl;
	// cout<<vGenLep.at(0).Pt<<"\t\t"<<vGenLep.at(1).Pt<<endl;
	if(vGenLep.at(0).Pt>20 && vGenLep.at(1).Pt>10)
	  bPassTrg = true;
      }// atleast 2 leptons
    

    //Step3: Identify Higgs decay process, TT,ZZ,WW
    Bool_t bHtoTT=false;
    Bool_t bHtoZZ=false;
    Bool_t bHtoWW=false;
    
    for(Size_t iGenp=0; iGenp<nGenp; iGenp++)
      {
    	if(GenP_PdgId->at(iGenp) == 25 )//&& GenP_Daughters->at(iGenp).size()!=0 
    	  {
	    
	    //if(IsFinalGenp(iGenp, GenP_Daughters->at(iGenp)))// For sample made with pythia 8, this check do not work because of the way information is stored.
	    
	    
	    if(GenP_Daughters->at(iGenp).size() == 3)         //For sample made with pythia 6,.
	                                                      //Just ask if this selected higgs have three daughters, (which is always the case)
	                                                      // and pick first two daughters as already being done.
    	      {
		Size_t Dau1 = GenP_Daughters->at(iGenp).at(0);
    		Size_t Dau2 = GenP_Daughters->at(iGenp).at(1);
    		if(abs(GenP_PdgId->at(Dau1)) == 15 || abs(GenP_PdgId->at(Dau2)) == 15 )
    		  {
    		    bHtoTT=true;
    		    nHtoTT++;
    		  }
    		if(abs(GenP_PdgId->at(Dau1)) == 23 || abs(GenP_PdgId->at(Dau2)) == 23 )
    		  {
    		    bHtoZZ=true;
    		    nHtoZZ++;
    		  }
    		if(abs(GenP_PdgId->at(Dau1)) == 24 || abs(GenP_PdgId->at(Dau2)) == 24 )
    		  {
    		    bHtoWW=true;
    		    nHtoWW++;
    		  }
		if(abs(GenP_PdgId->at(Dau1)) == 5 || abs(GenP_PdgId->at(Dau2)) == 5 )
    		  {
		    nHtoBB++;
    		  }
    	      }// is final Higgs
    	  }// if higgs
      }// loop on particles
    
    
    //Step4: Select Events
    if(bPassTrg)
      {
    	if(vGenLep.size()==2)
    	  {
	    //totalfucking2lss+=Weight;
	    if(vGenLep.at(0).Charge == vGenLep.at(1).Charge)
    	      {
		//		cout<< GenP_PdgId->at(vGenLep.at(0).Indx)<<"\t"<< GenP_PdgId->at(vGenLep.at(0).Indx)<<endl;
    		if(bHtoTT)
    		  {
		    n2lssHTT+= Weight;//n2lssHTT++;
    		    if(vGenBHad.size()==2)
    		      {
    			n2lssbbHTT+= Weight;
    		      }//if 2 Bhad in acceptance
    		  }// if event is H to TT
    		if(bHtoZZ)
    		  {
    		    n2lssHZZ+= Weight;
    		    if(vGenBHad.size()==2)
    		      {
    			n2lssbbHZZ+= Weight;
    		      }//if 2 Bhad in acceptance
    		  }// if event is H to ZZ
    		if(bHtoWW)
    		  {
    		    n2lssHWW+= Weight;
    		    if(vGenBHad.size()==2)
    		      {
    			n2lssbbHWW+= Weight;
    		      }//if 2 Bhad in acceptance
    		  }// if event is H to ZZ
    	      }// same sign
    	  }//if 2lep



    	if(vGenLep.size()==3)
    	  {
    	    if(bHtoTT)
    	      {
    		n3lHTT+= Weight;
    		if(vGenBHad.size()==2)
    		  {
    		    n3lbbHTT+= Weight;
    		  }//if 2 Bhad in acceptance
    	      }// if event is H to TT
    	    if(bHtoZZ)
    	      {
    		n3lHZZ+= Weight;
    		if(vGenBHad.size()==2)
    		  {
    		    n3lbbHZZ+= Weight;
    		  }//if 2 Bhad in acceptance
    	      }// if event is H to ZZ
    	    if(bHtoWW)
    	      {
    		n3lHWW+= Weight;
    		if(vGenBHad.size()==2)
    		  {
    		    n3lbbHWW+= Weight;
    		  }//if 2 Bhad in acceptance
    	      }// if event is H to ZZ
    	  }//if 3lep



    	if(vGenLep.size()==4)
    	  {
    	    if(bHtoTT)
    	      {
    		n4lHTT+= Weight;
    		if(vGenBHad.size()==2)
    		  {
    		    n4lbbHTT+= Weight;
    		  }//if 2 Bhad in acceptance
    	      }// if event is H to TT
    	    if(bHtoZZ)
    	      {
    		n4lHZZ+= Weight;
    		if(vGenBHad.size()==2)
    		  {
    		    n4lbbHZZ+= Weight;
    		  }//if 2 Bhad in acceptance
    	      }// if event is H to ZZ
    	    if(bHtoWW)
    	      {
    		n4lHWW+= Weight;
    		if(vGenBHad.size()==2)
    		  {
    		    n4lbbHWW+= Weight;
    		  }//if 2 Bhad in acceptance
    	      }// if event is H to ZZ
    	  }//if 4lep
	



      }// if pass trg


    //    for(Size_t it=0;it<nGenp; it++)
    //{
    // if(EvtNumber == 10061073)
    //   for(Size_t il=0; il<vGenLep.size(); il++)
    // 	{
    // 	  cout<< "\t"<<vGenLep.at(il).Indx<<"\t"<<vGenLep.at(il).PdgId<<"\t"<<vGenLep.at(il).Pt<<endl;
    // 	}
    // 	  myPrintGenp(it, true);
    //  }
  
    // for(Size_t iLep=0; iLep<vGenLep.size(); iLep++)
    //   {
    //  	cout<< vGenLep.at(iLep).Pt<<"\t"<<vGenLep.at(iLep).Eta<<"\t"<<vGenLep.at(iLep).PdgId<<endl;
    //   }
    // cout<<"\t\t"<< EvtNumber<<endl<<endl;

    // Update the progress bar
    //    tools.ProgressBar(jentry, nentries, 100, 150);
    
  }// end loop on events


  cout<< "TotalEvents \t "<< nentries<<endl;
  cout<< "H to TT events \t "<<nHtoTT<<"\tPercentage\t"<<nHtoTT/nentries<<endl;
  cout<< "H to ZZ events \t "<<nHtoZZ<<"\tPercentage\t"<<nHtoZZ/nentries<<endl;
  cout<< "H to WW events \t "<<nHtoWW<<"\tPercentage\t"<<nHtoWW/nentries<<endl;
  cout<< "H to BB events \t "<<nHtoBB<<"\tPercentage\t"<<nHtoBB/nentries<<endl;
  cout<<endl<<endl<<"________________________________________________________"<<endl;
  
  cout<< "\tFinalState\t    HtoWW \t    HtoTT \t    HtoZZ \t   Total"<<endl;
  cout<< "\t2lss\t\t  "<<n2lssHWW<<"\t  "<<n2lssHTT<<"\t  "<<n2lssHZZ<<"\t  "<<n2lssHWW+n2lssHTT+n2lssHZZ<<endl;
  cout<< "\t3l\t\t  "<<n3lHWW<<"\t  "<<n3lHTT<<"\t  "<<n3lHZZ<<"\t  "<<n3lHWW+n3lHTT+n3lHZZ<<endl;
  cout<< "\t4l\t\t  "<<n4lHWW<<"\t  "<<n4lHTT<<"\t  "<<n4lHZZ<<"\t  "<<n4lHWW+n4lHTT+n4lHZZ<<endl;
  cout<< "__________________________________________________________\n\n"; 
  cout<< "\t2lss+bb\t\t  "<<n2lssbbHWW<<"\t  "<<n2lssbbHTT<<"\t  "<<n2lssbbHZZ<<"\t  "<<n2lssbbHWW+n2lssbbHTT+n2lssbbHZZ<<endl;
  cout<< "\t3l+bb\t\t  "<<n3lbbHWW<<"\t  "<<n3lbbHTT<<"\t  "<<n3lbbHZZ<<"\t  "<<n3lbbHWW+n3lbbHTT+n3lbbHZZ<<endl;
  cout<< "\t4l+bb\t\t  "<<n4lbbHWW<<"\t  "<<n4lbbHTT<<"\t  "<<n4lbbHZZ<<"\t  "<<n4lbbHWW+n4lbbHTT+n4lbbHZZ<<endl;




  cout<<"________________________________________________________________________________________________\n";
  cout<<"\tN Higgs\t"<<  nHiggs<<"\tN W+\t"<< nWplus<<"\t N W-\t"<< nWMinus<<"\tnTest \t"<<nTest++<<endl;


  cout<<"\n\n\nW\t"<<nW<<"\t\t"<<nWL<<"\t\t"<<nWL/nW<<endl;
  cout<<"\n\n\nT\t"<<nT<<"\t\t"<<nTL<<"\t\t"<<nTL/nT<<endl;
  cout<<"\n\n\nZ\t"<<nZ<<"\t\t"<<nZL<<"\t\t"<<nZL/nZ<<endl;


  cout<<"\t\t"<<totalfucking2lss<<endl;

  // Keep this line here!
  outFile->cd();

  // Create and write canvases here

  // Uncomment this line to write also the histograms to the file
  outFile->Write();
}

//****************************************************************************
void EventYield::GetLeptonEntries(Int_t Indx, vector<ParticleInfo> &lepVec)
//****************************************************************************
{
  for(Size_t iDau=0; iDau<GenP_Daughters->at(Indx).size(); iDau++)
    {
      Int_t DauIndx=GenP_Daughters->at(Indx).at(iDau);
      if(abs(GenP_PdgId->at(DauIndx)) == 11)
	{
	  if(GenP_Pt->at(DauIndx)>7 && abs(GenP_Eta->at(DauIndx))<2.5)
	    {
	      ParticleInfo Lep;
	      Lep = SetParticleInfo (DauIndx,
				     GenP_Pt->at(DauIndx),
				     GenP_Eta->at(DauIndx),
				     GenP_Phi->at(DauIndx),
				     GenP_E->at(DauIndx),
				     GenP_PdgId->at(DauIndx),
				     GenP_Charge->at(DauIndx));
	      lepVec.push_back(Lep);
	    }// if within detector acceptance
	}// if electron
      if(abs(GenP_PdgId->at(DauIndx)) == 13)
	{
	  if(GenP_Pt->at(DauIndx)>5 && abs(GenP_Eta->at(DauIndx))<2.4)
	    {
	      ParticleInfo Lep;
	      Lep = SetParticleInfo (DauIndx,
				     GenP_Pt->at(DauIndx),
				     GenP_Eta->at(DauIndx),
				     GenP_Phi->at(DauIndx),
				     GenP_E->at(DauIndx),
				     GenP_PdgId->at(DauIndx),
				     GenP_Charge->at(DauIndx));
	      lepVec.push_back(Lep);
	    }// if within detector acceptance
	}//if muon
    }
  
}

//****************************************************************************
Bool_t EventYield::IsFinalGenp (Size_t MotIndx, vector<unsigned short>& Daug)
//****************************************************************************
{
  Int_t MotId = GenP_PdgId->at(MotIndx);
  
  if(Daug.size()==0) return true;
  
  for(Size_t iDau=0; iDau<Daug.size(); iDau++)
    {
      Int_t DauIndx = Daug.at(iDau);
      Int_t DauId   = GenP_PdgId->at(DauIndx);
      //if(MotId != DauId)
      //{
	  //return true;
      //  break;
      //}
      if(MotId == DauId  )
	return false;
    }// end loop on daughters
  return true;
}


//****************************************************************************
Bool_t EventYield::IsFinalGenpPy6 (Size_t MotIndx, vector<unsigned short>& Daug)
//****************************************************************************
{
  Int_t MotId = GenP_PdgId->at(MotIndx);
  
  if(Daug.size()==0) return true;
  
  for(Size_t iDau=0; iDau<Daug.size(); iDau++)
    {
      Int_t DauIndx = Daug.at(iDau);
      Int_t DauId   = GenP_PdgId->at(DauIndx);
      //if(MotId != DauId)
      //{
	  //return true;
      //  break;
      //}
      if(MotId == DauId  )
	return false;
    }// end loop on daughters
  return true;
}

//****************************************************************************
Bool_t EventYield::IsFinalBHadron(Int_t Index)
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

//****************************************************************************
ParticleInfo EventYield::SetParticleInfo (Int_t Indx, Double_t Pt, Double_t Eta, Double_t Phi, Double_t E, Int_t Id, Int_t Charge)
//****************************************************************************
{
  ParticleInfo temp;
  temp.Pt     = Pt;
  temp.Eta    = Eta;
  temp.Phi    = Phi;
  temp.E      = E;
  temp.PdgId  = Id;
  temp.Charge = Charge;
  temp.Indx   = Indx;
  return temp;
}


//****************************************************************************
void EventYield::SortLepPt(vector<ParticleInfo> &vSort)
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


//**************************************************
ttHParIndx EventYield::GetttHParIndices()
//**************************************************
{

  ttHParIndx list;
  
  for (Size_t iGenp=0; iGenp<GenP_Pt->size(); iGenp++)
    {
      //*********************************************
      // TOP QUARK
      //*********************************************
      if (GenP_PdgId->at(iGenp) == 6)
	{
//	  cout<<"\t\t"<< iGenp<<"\t"<<GenP_Pt->at(iGenp)<< endl;
	  vector<unsigned short> tDau = GenP_Daughters->at(iGenp);
	  if(IsFinalGenp(iGenp, tDau ))
	    {
//	      cout<<"\t"<< iGenp<<"\t"<<GenP_Pt->at(iGenp)<< endl;
	      list.t = iGenp;
	      for(Size_t iDau=0; iDau<tDau.size(); iDau++)
		{
		  Size_t DauIndx = tDau.at(iDau);
		  if(GenP_PdgId->at(DauIndx) == 24)
		    {
		      //cout<<DauIndx<< "\t"<<GenP_Pt->at(DauIndx)<<endl;
		      //cout<<GenP_Daughters->at(DauIndx).size()<<endl;
		      list.Wpfromt = GetFinalGenpIndx(DauIndx, GenP_Daughters->at(DauIndx));
		      for(Size_t iWpDau=0; iWpDau<GenP_Daughters->at(list.Wpfromt).size(); iWpDau++ )//cout<<list.Wpfromt<<endl;
			{
			  Size_t WpDauIndx = GenP_Daughters->at(list.Wpfromt).at(iWpDau);
			  if(abs(GenP_PdgId->at(WpDauIndx)) == 15)
			    {
			      //cout<< EvtNumber<<"\t"<<list.Wpfromt<<"\t"<<WpDauIndx<<"\t"<<GenP_PdgId->at(WpDauIndx)<<endl;
			      list.TpfromWpt = GetFinalGenpIndx(WpDauIndx, GenP_Daughters->at(WpDauIndx));
			      //cout<<"\tThe final Tau iss \t"<< test<<endl;
			    }
			}//end loop on daughters of Wp


		      //cout<<list.Wpfromt<<endl;
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
	      list.tbar = iGenp;
	      for(Size_t iDau=0; iDau<tbarDau.size(); iDau++)
		{
		  Size_t DauIndx = tbarDau.at(iDau);
		  if(GenP_PdgId->at(DauIndx) == -24)
		    {
		      list.Wmfromtbar = GetFinalGenpIndx(DauIndx, GenP_Daughters->at(DauIndx));
		      for(Size_t iWmDau=0; iWmDau<GenP_Daughters->at(list.Wmfromtbar).size(); iWmDau++ )//cout<<list.Wpfromt<<endl;
			{
			  Size_t WmDauIndx = GenP_Daughters->at(list.Wmfromtbar).at(iWmDau);
			  if(abs(GenP_PdgId->at(WmDauIndx)) == 15)
			    {
			      //  cout<< EvtNumber<<"\t"<<list.Wmfromtbar<<"\t"<<WmDauIndx<<"\t"<<GenP_PdgId->at(WmDauIndx)<<endl;
			      list.TmfromWmtbar = GetFinalGenpIndx(WmDauIndx, GenP_Daughters->at(WmDauIndx));
			      //  cout<<"\tThe final Tau iss \t"<< list.TmfromWmtbar<<endl;
			    }
			}//end loop on daughters of Wm
		      
		      
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
	  //	  cout<<"\tThe higgssss   \t"<<iGenp<<endl;
	  vector<unsigned short> HDau = GenP_Daughters->at(iGenp);
	  Bool_t bhasZ1 = false;
	  //if(IsFinalGenp(iGenp, HDau )) // Py8
	  if(HDau.size() != 0)// Py6
	    {
	      // cout<<"\t\t\t\tThe higgssss   \t"<<iGenp<<endl;
	      list.H = iGenp;
	      for(Size_t iDau=0; iDau<HDau.size(); iDau++)
		{
		  Size_t DauIndx = HDau.at(iDau);
		  if(GenP_PdgId->at(DauIndx) == -24)
		    {
		      //cout<<"This do not occur\n";
		      list.WmfromH = GetFinalGenpIndx(DauIndx, GenP_Daughters->at(DauIndx));

		      for(Size_t iWmDau=0; iWmDau<GenP_Daughters->at(list.WmfromH).size(); iWmDau++ )//cout<<list.Wpfromt<<endl;
			{
			  Size_t WmDauIndx = GenP_Daughters->at(list.WmfromH).at(iWmDau);
			  if(abs(GenP_PdgId->at(WmDauIndx)) == 15)
			    {
			      //cout<< EvtNumber<<"\t"<<list.WmfromH<<"\t"<<WmDauIndx<<"\t"<<GenP_PdgId->at(WmDauIndx)<<endl;
			      list.TmfromWmH = GetFinalGenpIndx(WmDauIndx, GenP_Daughters->at(WmDauIndx));
			      //cout<<"\tThe final Tau iss \t"<< list.TmfromWmH<<endl;
			    }
			}//end loop on daughters of Wm

		    }// if W
		  if(GenP_PdgId->at(DauIndx) == +24)
		    {
		      //cout<<"This do not occur either\n";
		      list.WpfromH = GetFinalGenpIndx(DauIndx, GenP_Daughters->at(DauIndx));
		      
		      for(Size_t iWpDau=0; iWpDau<GenP_Daughters->at(list.WpfromH).size(); iWpDau++ )//cout<<list.Wpfromt<<endl;
			{
			  Size_t WpDauIndx = GenP_Daughters->at(list.WpfromH).at(iWpDau);
			  if(abs(GenP_PdgId->at(WpDauIndx)) == 15)
			    {
			      //cout<< EvtNumber<<"\t"<<list.WpfromH<<"\t"<<WpDauIndx<<"\t"<<GenP_PdgId->at(WpDauIndx)<<endl;
			      list.TpfromWpH = GetFinalGenpIndx(WpDauIndx, GenP_Daughters->at(WpDauIndx));
			      //cout<<"\tThe final Tau iss \t"<< list.TpfromWpH<<endl;
			    }
			}//end loop on daughters of Wm


		    }// if W
		  if(GenP_PdgId->at(DauIndx) == -15)
		    {
		      list.TmfromH = GetFinalGenpIndx(DauIndx, GenP_Daughters->at(DauIndx));
		    }// if T
		  if(GenP_PdgId->at(DauIndx) == 15)
		    {
		      list.TpfromH = GetFinalGenpIndx(DauIndx, GenP_Daughters->at(DauIndx));
		    }// if T
		  if(GenP_PdgId->at(DauIndx) == 23)
		    {
		      Bool_t bhasZ1 = false; 
		      if(!bhasZ1)
			{
			  list.Z1fromH = GetFinalGenpIndx(DauIndx, GenP_Daughters->at(DauIndx));
			  //list.Z1fromH = GetFinalGenpIndx(DauIndx, GenP_Daughters->at(HDau.at(0)));
			  bhasZ1 = true;
			  //Bool_t bhasT1=false;
			  for(Size_t iZ1Dau=0; iZ1Dau<GenP_Daughters->at(list.Z1fromH).size(); iZ1Dau++ )//cout<<list.Wpfromt<<endl;
			    {
			      Size_t Z1DauIndx = GenP_Daughters->at(list.Z1fromH).at(iZ1Dau);
			      if(GenP_PdgId->at(Z1DauIndx) == 15)
				{
				  list.TmfromZ1H = GetFinalGenpIndx(Z1DauIndx, GenP_Daughters->at(Z1DauIndx));
				}
			      if(GenP_PdgId->at(Z1DauIndx) == -15)
				{
				  list.TpfromZ1H = GetFinalGenpIndx(Z1DauIndx, GenP_Daughters->at(Z1DauIndx));
				}
				  //Int_t test  = GetFinalGenpIndx(Z1DauIndx, GenP_Daughters->at(Z1DauIndx));
				  // cout<<"\tThe final Tau iss \t"<< test<<endl;
				  //cout<<"\tThe final Tau 1  iss \t"<< list.TpfromZ1H<<endl;
				  //cout<<"\t and The final Tau 2  iss \t"<< list.TmfromZ1H<<endl;
			    			      
			    }//end loop on daughters of Z1
			  

			}
			
		      if(bhasZ1) 
			{
			  //list.Z2fromH = GetFinalGenpIndx(DauIndx, GenP_Daughters->at(HDau.at(1)));
			  list.Z2fromH = GetFinalGenpIndx(DauIndx, GenP_Daughters->at(DauIndx));
			
			  //			  Bool_t bhasT1=false;
			  for(Size_t iZ2Dau=0; iZ2Dau<GenP_Daughters->at(list.Z2fromH).size(); iZ2Dau++ )//cout<<list.Wpfromt<<endl;
			    {
			      Size_t Z2DauIndx = GenP_Daughters->at(list.Z2fromH).at(iZ2Dau);
			      if(GenP_PdgId->at(Z2DauIndx) == 15)
				{
				  list.TmfromZ2H = GetFinalGenpIndx(Z2DauIndx, GenP_Daughters->at(Z2DauIndx));
				}
			      if(GenP_PdgId->at(Z2DauIndx) == -15)
				{
				  list.TpfromZ2H = GetFinalGenpIndx(Z2DauIndx, GenP_Daughters->at(Z2DauIndx));
				}

			      
			    }//end loop on daughters of Wm
			}
		    }// if Z
		}// loop on t dau
	    }//final Higgs
	}//end if Higgs
      //*********************************************
    }//end loop on Genp

  return list;
}

//****************************************************************************
Int_t EventYield::GetFinalGenpIndx (Size_t MotIndx, vector<unsigned short>& Daug)
//****************************************************************************
{
  Int_t MotId = GenP_PdgId->at(MotIndx);
  
  Int_t FinalGenpIndx = MotIndx;

//  cout<<MotIndx<<"\t\t"<<MotId<<"\t\t"<< Daug.size()<<"\t\t"<<FinalGenpIndx <<endl;

  if(Daug.size()==0) return FinalGenpIndx;
  
  for(Size_t iDau=0; iDau<Daug.size(); iDau++)
    {
      Int_t DauIndx = Daug.at(iDau);
      Int_t DauId   = GenP_PdgId->at(DauIndx);
      if(MotId != DauId)
	break;
      if(MotId == DauId)
	FinalGenpIndx = GetFinalGenpIndx(DauIndx,GenP_Daughters->at(DauIndx));
    }// end loop on daughters
  return FinalGenpIndx;
}

//**************************************************
void EventYield::myPrintGenp(Size_t Indx, bool bPrintHeaders)
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
	       // << std::setw(10)  << "px"
	       // << std::setw(10) << "py"
	       << std::setw(10) << "pT"
	  //       << std::setw(10) << "pz"
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
	 // << std::setw(10) << std::setprecision(3) << px
	 // << std::setw(10) << std::setprecision(3) << py
	 // << std::setw(10) << std::setprecision(3) << pz
	 << std::setw(10) << std::setprecision(3) << pt
	 << std::setw(10) << std::setprecision(3) << ene
	 << std::setw(10) << std::setprecision(3) << eta
	 << std::setw(10) << std::setprecision(3) << phi
	 << std::setw(10) << std::setprecision(3) << mass
	 << std::setw(10) << std::setprecision(3) << GenP_VertexZ->at(Indx)
	 << std::endl;
}

//**************************************************
void EventYield::CalculateEventExpectation(void)
//**************************************************
{

  vector<Double_t > BRH;
  BRH.push_back(0.063);    // H to TT
  BRH.push_back(0.0266);   // H to ZZ
  BRH.push_back(0.216);    // H to WW
  // Double_t BRHtoW = 0.216;
  // Double_t BRHtoT = 0.063;
  // Double_t BRHtoZ = 0.0266;
  
  vector<Double_t > BRW;
  BRW.push_back(0.1125);  //W to TNu
  BRW.push_back(0.6760);  //W to QQ
  BRW.push_back(0.2132);  //W to LNu

  
  // Double_t BRWtoL = 0.2132;
  // Double_t BRWtoT = 0.1125;
  // Double_t BRWtoQ = 0.6760;
  

  vector<Double_t > BRZ;
  BRZ.push_back(0.6991);  //Z to QQ
  BRZ.push_back(0.0672);  //Z to LL
  BRZ.push_back(0.0365);  //Z to TT
  
  // Double_t BRZtoL = 0.0672;
  // Double_t BRZtoT = 0.0365;
  // Double_t BRZtoQ = 0.6991;


  vector<Double_t > BRT;
  BRT.push_back(0.6479);  //T to Had
  BRT.push_back(0.3521);  //T to LNu


  vector<Double_t > BRNone;
  BRNone.push_back(1.000);
  // Double_t BRTtoL = 0.3521;
  // Double_t BRTtoQ = 0.6479;
  
  Double_t TotalBR=0;

  // for(Size_t iHDecay=0; iHDecay<1; iHDecay++) //iHDecay 0 = HtoTT, iHDecay 1 = HtoZZ, iHDecay 2 = HtoWW
  //   {
  //     if(iHDecay == 0)
  // 	{
  // 	  for(Size_t iT1H=0; iT1H<2; iT1H++) // Daughters of Tau1 decay of higgs
  // 	    {
  // 	      for(Size_t iT2H=0; iT2H<2; iT2H++) // Daughters of Tau2 decay of higgs
  // 		{
  // 		  for(Size_t iW1t=0; iW1t< 3; iW1t++)
  // 		    {
  // 		      if(iW1t == 0)
  // 			{
  // 			  for(Size_t iT1Wt=0; iT1Wt<2; iT1Wt++)
  // 			    {
  // 			      for(Size_t iW1t=0; iW1t< 3; iW1t++)
  // 				{
  // 				  if(iW1t == 0)
  // 				    {
  // 				      for(Size_t iT1Wt=0; iT1Wt<2; iT1Wt++)
  // 					{
  // 					  TotalBR = BRH.at(iHDecay) * BRT(iT1H) * BRT(iT2H) * BRW(iW1t) * BRW(iW2T) *  ;
  // 					}// loop on Tau from W2t
  // 				    }// if W2 Decay to Tau
  // 				}// loop on W2 from top
  // 			    }// loop on Tau from W1t
  // 			}//if W1 Decay to Tau
  // 		    }//loop on W1 from top 
  // 		}//loop on Tau 2 from H
  // 	    }//loop on Tau 1 from H
  // 	}// if H decay to Tau
  //   }// loop on H decay



  // for(Size_t iHDecay=0; iHDecay<1; iHDecay++)
  //   {
  //     //iHDecay 0 = HtoTT, iHDecay 1 = HtoZZ, iHDecay 2 = HtoWW*BRW.at(iWpDecay)*BRW.at(iWmDecay)
  //     for(Size_t iTmDecay=0; iTmDecay<1; iTmDecay++)
  // 	{
  // 	  //iTmDecay 0 = TmtoHad, iTmDecay 1 = TmtoLNu
  // 	  for(Size_t iTpDecay=0; iTpDecay<1; iTpDecay++)
  // 	    {
  // 	      //iTpDecay 0 = TptoHad, iTpDecay 1 = TmtoLNu
	      
  // 	      for(Size_t iWpDecay=0; iWpDecay<3; iWpDecay++)
  // 		{
  // 		  //iWpDecay 0 = WptoQQ, iWpDecay 1 = WptoLNu
  // 		  for(Size_t iWmDecay=0; iWmDecay<3; iWmDecay++)
  // 		    {
  // 		      //iWmDecay 0 = WmtoQQ, iWmDecay 1 = WmtoLNu
  // 		      //for(Size_t iTmWmDecay=0; iTmWmDecay<2; iTmWmDecay++)
  // 			{
  // 			  //iTmWmDecay 0 = TmtoHad, iTmWmDecay 1 = TmtoLNu
  // 			  //  for(Size_t iTpWpDecay=0; iTpWpDecay<2; iTpWpDecay++)
  // 			    {
  // 			      //iTpWpDecay 0 = TptoHad, iTpWpDecay 1 = TptoLNu
  // 			      TotalBR = BRW.at(iWpDecay)*BRW.at(iWmDecay)*BRH.at(iHDecay)*BRT.at(iTpDecay)*BRT.at(iTmDecay);//*BRT.at(iTmWmDecay)*BRT.at(iTpWpDecay);
  // 			      cout<<
  // 			    }
  // 			}
  // 		    }
  // 		}
  // 	    }

  // 	}
  //   }

}

//**************************************************
Double_t EventYield::CheckLeptonBranching(Size_t Indx)
//**************************************************
{
  Double_t nL=0.0;
  for(Size_t iD=0; iD<GenP_Daughters->at(Indx).size() ; iD++)
    {
      Int_t DIndx = GenP_Daughters->at(Indx).at(iD);
      if(abs(GenP_PdgId->at(DIndx)) == 11 || abs(GenP_PdgId->at(DIndx)) == 13 )
	{
	  nL++;
	  break;
	}
    }
  return nL;
  
}

#endif // EventYield_cxx
