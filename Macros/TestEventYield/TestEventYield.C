#ifndef TestEventYield_cxx
#define TestEventYield_cxx

#include "TestEventYield.h"
#include "../utilities/constants.h"

void TestEventYield::Loop()
{
  if (fChain == 0) return;

  Long64_t nentries = (MaxEvents == -1) ? fChain->GetEntries() : std::min((int)fChain->GetEntries(), MaxEvents);

  std::cout << "Analyzing " << nentries << " events.\n";

  // Book histograms here

  Double_t nHtoTT=0.0;
  Double_t nHtoZZ=0.0;
  Double_t nHtoWW=0.0;

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


  Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry=0; jentry<nentries;jentry++)
  {
    if(jentry%1000 == 0)
      std::cout << "Loop over entry " << jentry << "/" << nentries << ".\n";
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);   nbytes += nb;
    // if (Cut(ientry) < 0) continue;

    Size_t nGenp = GenP_Pt->size();
  
    //Step1: Basic Acceptance of e, mu, and bhad.
    vector<ParticleInfo> vGenLep;
    vector<ParticleInfo> vGenBHad;
    for(Size_t iGenp = 0; iGenp<nGenp; iGenp++)
      {
	//Take All status 1 leptons in an event in 
	if(GenP_Status->at(iGenp) == 1)
	  {
	    if(abs(GenP_PdgId->at(iGenp)) == 11)
	      {
		if(GenP_Pt->at(iGenp)>7 && abs(GenP_Eta->at(iGenp))<2.5)
		  {
		    ParticleInfo Lep;
		    Lep = SetParticleInfo (iGenp,
					   GenP_Pt->at(iGenp),
					   GenP_Eta->at(iGenp),
					   GenP_Phi->at(iGenp),
					   GenP_E->at(iGenp),
					   GenP_PdgId->at(iGenp),
					   GenP_Charge->at(iGenp));
		    vGenLep.push_back(Lep);
		  }// if within detector acceptance
	      }// if electron
	    if(abs(GenP_PdgId->at(iGenp)) == 13)
	      {
		if(GenP_Pt->at(iGenp)>5 && abs(GenP_Eta->at(iGenp))<2.4)
		  {
		    ParticleInfo Lep;
		    Lep = SetParticleInfo (iGenp,
					   GenP_Pt->at(iGenp),
					   GenP_Eta->at(iGenp),
					   GenP_Phi->at(iGenp),
					   GenP_E->at(iGenp),
					   GenP_PdgId->at(iGenp),
					   GenP_Charge->at(iGenp));
		    vGenLep.push_back(Lep);
		  }// if within detector acceptance
	      }//if muon
	  }// if status 1 particle

	if(IsFinalBHadron(iGenp))
	  {
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
	if(vGenLep.at(0).Pt>20 && vGenLep.at(1).Pt>10)
	  bPassTrg = true;
      }// atleast 2 leptons
    

    //Step3: Identify Higgs decay process, TT,ZZ,WW
    Bool_t bHtoTT=false;
    Bool_t bHtoZZ=false;
    Bool_t bHtoWW=false;
        
    for(Size_t iGenp=0; iGenp<nGenp; iGenp++)
      {
	if(GenP_PdgId->at(iGenp) == 25)
	  {
	    if(IsFinalGenp(iGenp, GenP_Daughters->at(iGenp)))
	      {
		Size_t Dau1 = GenP_Daughters->at(iGenp).at(0);
		Size_t Dau2 = GenP_Daughters->at(iGenp).at(1);
		if(abs(GenP_PdgId->at(Dau1)) == 15 && abs(GenP_PdgId->at(Dau2)) == 15 )
		  {
		    bHtoTT=true;
		    nHtoTT++;
		  }
		if(abs(GenP_PdgId->at(Dau1)) == 23 && abs(GenP_PdgId->at(Dau2)) == 23 )
		  {
		    bHtoZZ=true;
		    nHtoZZ++;
		  }
		if(abs(GenP_PdgId->at(Dau1)) == 24 && abs(GenP_PdgId->at(Dau2)) == 24 )
		  {
		    bHtoWW=true;
		    nHtoWW++;
		  }
	      }// is final Higgs
	  }// if higgs
      }// loop on particles


    //Step4: Select Events
    if(bPassTrg)
      {
	if(vGenLep.size()==2)
	  {
	    if(vGenLep.at(0).Charge == vGenLep.at(1).Charge)
	      {
		if(bHtoTT)
		  {
		    n2lssHTT++;
		    if(vGenBHad.size()==2)
		      {
			n2lssbbHTT++;
		      }//if 2 Bhad in acceptance
		  }// if event is H to TT
		if(bHtoZZ)
		  {
		    n2lssHZZ++;
		    if(vGenBHad.size()==2)
		      {
			n2lssbbHZZ++;
		      }//if 2 Bhad in acceptance
		  }// if event is H to ZZ
		if(bHtoWW)
		  {
		    n2lssHWW++;
		    if(vGenBHad.size()==2)
		      {
			n2lssbbHWW++;
		      }//if 2 Bhad in acceptance
		  }// if event is H to ZZ
	      }// same sign
	  }//if 2lep



	if(vGenLep.size()==3)
	  {
	    if(bHtoTT)
	      {
		n3lHTT++;
		if(vGenBHad.size()==2)
		  {
		    n3lbbHTT++;
		  }//if 2 Bhad in acceptance
	      }// if event is H to TT
	    if(bHtoZZ)
	      {
		n3lHZZ++;
		if(vGenBHad.size()==2)
		  {
		    n3lbbHZZ++;
		  }//if 2 Bhad in acceptance
	      }// if event is H to ZZ
	    if(bHtoWW)
	      {
		n3lHWW++;
		if(vGenBHad.size()==2)
		  {
		    n3lbbHWW++;
		  }//if 2 Bhad in acceptance
	      }// if event is H to ZZ
	  }//if 3lep



	if(vGenLep.size()==4)
	  {
	    if(bHtoTT)
	      {
		n4lHTT++;
		if(vGenBHad.size()==2)
		  {
		    n4lbbHTT++;
		  }//if 2 Bhad in acceptance
	      }// if event is H to TT
	    if(bHtoZZ)
	      {
		n4lHZZ++;
		if(vGenBHad.size()==2)
		  {
		    n4lbbHZZ++;
		  }//if 2 Bhad in acceptance
	      }// if event is H to ZZ
	    if(bHtoWW)
	      {
		n4lHWW++;
		if(vGenBHad.size()==2)
		  {
		    n4lbbHWW++;
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
  cout<<endl<<endl<<"________________________________________________________"<<endl;
  
  cout<< "\tFinalState\t HtoWW \t HtoTT \t HtoZZ \t Total"<<endl;
  cout<< "\t2lss\t\t  "<<n2lssHWW<<"\t  "<<n2lssHTT<<"\t  "<<n2lssHZZ<<"\t  "<<n2lssHWW+n2lssHTT+n2lssHZZ<<endl;
  cout<< "\t3l\t\t  "<<n3lHWW<<"\t  "<<n3lHTT<<"\t  "<<n3lHZZ<<"\t  "<<n3lHWW+n3lHTT+n3lHZZ<<endl;
  cout<< "\t4l\t\t  "<<n4lHWW<<"\t  "<<n4lHTT<<"\t  "<<n4lHZZ<<"\t  "<<n4lHWW+n4lHTT+n4lHZZ<<endl;
  cout<< "__________________________________________________________\n\n"; 
  cout<< "\t2lss+bb\t\t  "<<n2lssbbHWW<<"\t  "<<n2lssbbHTT<<"\t  "<<n2lssbbHZZ<<"\t  "<<n2lssbbHWW+n2lssbbHTT+n2lssbbHZZ<<endl;
  cout<< "\t3l+bb\t\t  "<<n3lbbHWW<<"\t  "<<n3lbbHTT<<"\t  "<<n3lbbHZZ<<"\t  "<<n3lbbHWW+n3lbbHTT+n3lbbHZZ<<endl;
  cout<< "\t4l+bb\t\t  "<<n4lbbHWW<<"\t  "<<n4lbbHTT<<"\t  "<<n4lbbHZZ<<"\t  "<<n4lbbHWW+n4lbbHTT+n4lbbHZZ<<endl;


  // Keep this line here!
  outFile->cd();

  // Create and write canvases here

  // Uncomment this line to write also the histograms to the file
  // outFile->Write();
}


//****************************************************************************
Bool_t TestEventYield::IsFinalGenp (Size_t MotIndx, vector<unsigned short>& Daug)
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
Bool_t TestEventYield::IsFinalBHadron(Int_t Index)
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
ParticleInfo TestEventYield::SetParticleInfo (Int_t Indx, Double_t Pt, Double_t Eta, Double_t Phi, Double_t E, Int_t Id, Int_t Charge)
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
void TestEventYield::SortLepPt(vector<ParticleInfo> &vSort)
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
void TestEventYield::myPrintGenp(Size_t Indx, bool bPrintHeaders)
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

#endif // TestEventYield_cxx
