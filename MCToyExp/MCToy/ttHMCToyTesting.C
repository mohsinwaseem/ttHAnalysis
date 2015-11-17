void ttHMCToyTesting()
{
  Double_t pass =0.0;
  Double_t TotalExp = 5000000.0;
  
  Double_t nWW = 0.0;
  Double_t nZZ = 0.0;
  Double_t nTT = 0.0;
  
  //***********************************************************
  //Counters for HWW Cases 
  Double_t HWWn0l0Th  = 0.0;
  Double_t HWWn0l1Th  = 0.0;
  Double_t HWWn0l2Th  = 0.0;
  Double_t HWWn0l3Th  = 0.0;
  Double_t HWWn0l4Th  = 0.0;
  
  Double_t HWWn1l0Th  = 0.0;
  Double_t HWWn1l1Th  = 0.0;
  Double_t HWWn1l2Th  = 0.0;
  Double_t HWWn1l3Th  = 0.0;
  Double_t HWWn1l4Th  = 0.0;

  Double_t HWWn2l0Th  = 0.0;
  Double_t HWWn2l1Th  = 0.0;
  Double_t HWWn2l2Th  = 0.0;
  Double_t HWWn2l3Th  = 0.0;
  Double_t HWWn2l4Th  = 0.0;

  Double_t HWWn3l0Th  = 0.0;
  Double_t HWWn3l1Th  = 0.0;
  Double_t HWWn3l2Th  = 0.0;
  Double_t HWWn3l3Th  = 0.0;
  Double_t HWWn3l4Th  = 0.0;

  Double_t HWWn4l0Th  = 0.0;
  Double_t HWWn4l1Th  = 0.0;
  Double_t HWWn4l2Th  = 0.0;
  Double_t HWWn4l3Th  = 0.0;
  Double_t HWWn4l4Th  = 0.0;
  
  Double_t HWWn2lss0Th  = 0.0;
  Double_t HWWn2lss1Th  = 0.0;
  Double_t HWWn2lss2Th  = 0.0;
  Double_t HWWn2lss3Th  = 0.0;
  Double_t HWWn2lss4Th  = 0.0;

  Double_t HWWn2los0Th  = 0.0;
  Double_t HWWn2los1Th  = 0.0;
  Double_t HWWn2los2Th  = 0.0;
  Double_t HWWn2los3Th  = 0.0;
  Double_t HWWn2los4Th  = 0.0;
  //***********************************************************  

  //***********************************************************
  // Counters for HZZ cases 
  Double_t HZZn0l0Th  = 0.0;
  Double_t HZZn0l1Th  = 0.0;
  Double_t HZZn0l2Th  = 0.0;
  Double_t HZZn0l3Th  = 0.0;
  Double_t HZZn0l4Th  = 0.0;
  Double_t HZZn0l5Th  = 0.0;
  Double_t HZZn0l6Th  = 0.0;

  Double_t HZZn1l0Th  = 0.0;
  Double_t HZZn1l1Th  = 0.0;
  Double_t HZZn1l2Th  = 0.0;
  Double_t HZZn1l3Th  = 0.0;
  Double_t HZZn1l4Th  = 0.0;
  Double_t HZZn1l5Th  = 0.0;
  Double_t HZZn1l6Th  = 0.0;

  Double_t HZZn2l0Th  = 0.0;
  Double_t HZZn2l1Th  = 0.0;
  Double_t HZZn2l2Th  = 0.0;
  Double_t HZZn2l3Th  = 0.0;
  Double_t HZZn2l4Th  = 0.0;
  Double_t HZZn2l5Th  = 0.0;
  Double_t HZZn2l6Th  = 0.0;

  Double_t HZZn3l0Th  = 0.0;
  Double_t HZZn3l1Th  = 0.0;
  Double_t HZZn3l2Th  = 0.0;
  Double_t HZZn3l3Th  = 0.0;
  Double_t HZZn3l4Th  = 0.0;
  Double_t HZZn3l5Th  = 0.0;
  Double_t HZZn3l6Th  = 0.0;

  Double_t HZZn4l0Th  = 0.0;
  Double_t HZZn4l1Th  = 0.0;
  Double_t HZZn4l2Th  = 0.0;
  Double_t HZZn4l3Th  = 0.0;
  Double_t HZZn4l4Th  = 0.0;
  Double_t HZZn4l5Th  = 0.0;
  Double_t HZZn4l6Th  = 0.0;

  Double_t HZZn5l0Th  = 0.0;
  Double_t HZZn5l1Th  = 0.0;
  Double_t HZZn5l2Th  = 0.0;
  Double_t HZZn5l3Th  = 0.0;
  Double_t HZZn5l4Th  = 0.0;
  Double_t HZZn5l5Th  = 0.0;
  Double_t HZZn5l6Th  = 0.0;

  Double_t HZZn6l0Th  = 0.0;
  Double_t HZZn6l1Th  = 0.0;
  Double_t HZZn6l2Th  = 0.0;
  Double_t HZZn6l3Th  = 0.0;
  Double_t HZZn6l4Th  = 0.0;
  Double_t HZZn6l5Th  = 0.0;
  Double_t HZZn6l6Th  = 0.0;

  Double_t HZZn2lss0Th  = 0.0;
  Double_t HZZn2lss1Th  = 0.0;
  Double_t HZZn2lss2Th  = 0.0;
  Double_t HZZn2lss3Th  = 0.0;
  Double_t HZZn2lss4Th  = 0.0;
  Double_t HZZn2lss5Th  = 0.0;
  Double_t HZZn2lss6Th  = 0.0;

  Double_t HZZn2los0Th  = 0.0;
  Double_t HZZn2los1Th  = 0.0;
  Double_t HZZn2los2Th  = 0.0;
  Double_t HZZn2los3Th  = 0.0;
  Double_t HZZn2los4Th  = 0.0;
  Double_t HZZn2los5Th  = 0.0;
  Double_t HZZn2los6Th  = 0.0;
  //***********************************************************


  //***********************************************************
  //Counter for HTT cases
  Double_t HTTn0l0Th  = 0.0;
  Double_t HTTn0l1Th  = 0.0;
  Double_t HTTn0l2Th  = 0.0;
  Double_t HTTn0l3Th  = 0.0;
  Double_t HTTn0l4Th  = 0.0;

  Double_t HTTn1l0Th  = 0.0;
  Double_t HTTn1l1Th  = 0.0;
  Double_t HTTn1l2Th  = 0.0;
  Double_t HTTn1l3Th  = 0.0;
  Double_t HTTn1l4Th  = 0.0;

  Double_t HTTn2l0Th  = 0.0;
  Double_t HTTn2l1Th  = 0.0;
  Double_t HTTn2l2Th  = 0.0;
  Double_t HTTn2l3Th  = 0.0;
  Double_t HTTn2l4Th  = 0.0;

  Double_t HTTn3l0Th  = 0.0;
  Double_t HTTn3l1Th  = 0.0;
  Double_t HTTn3l2Th  = 0.0;
  Double_t HTTn3l3Th  = 0.0;
  Double_t HTTn3l4Th  = 0.0;

  Double_t HTTn4l0Th  = 0.0;
  Double_t HTTn4l1Th  = 0.0;
  Double_t HTTn4l2Th  = 0.0;
  Double_t HTTn4l3Th  = 0.0;
  Double_t HTTn4l4Th  = 0.0;

  Double_t HTTn2lss0Th  = 0.0;
  Double_t HTTn2lss1Th  = 0.0;
  Double_t HTTn2lss2Th  = 0.0;
  Double_t HTTn2lss3Th  = 0.0;
  Double_t HTTn2lss4Th  = 0.0;

  Double_t HTTn2los0Th  = 0.0;
  Double_t HTTn2los1Th  = 0.0;
  Double_t HTTn2los2Th  = 0.0;
  Double_t HTTn2los3Th  = 0.0;
  Double_t HTTn2los4Th  = 0.0;
  //***********************************************************
  
  Double_t Lumi = 100.0;//19.6;//fb-1
  Double_t Sigma = 508.5;//130.2; //fb  508.5;//
  Double_t nEvtLumi = Sigma*Lumi;
  Double_t Weight =  nEvtLumi/TotalExp;

 
  // TH1D *test;
  // test = new TH1D ("test","test",1000,-2,2);

  Double_t totalLepTau=0;
  Double_t totalHadTau=0;

  for (Long64_t i=0; i<TotalExp; i++)
    {
      if(i%1000 == 0) 	cout<<i<<endl;

      TRandom3 tempr;
      Double_t tempranTDecay = tempr.Uniform(rand()%100 / 100.);
      Double_t TaugoLep=IsLfromT(tempranTDecay);
      Double_t TaugoHad=IsQfromT(tempranTDecay);
      
      if(TaugoLep)totalLepTau++;
      if(TaugoHad)totalHadTau++;
      

      TRandom3 r1;
      Double_t ranHDecay = r1.Uniform(rand()%100 / 100.);
 
      
      if(IsWWfromH(ranHDecay))
	{
	  TRandom3 r2;
	  Double_t ranWptDecay = r2.Uniform(rand()%100 / 100.);
	  TRandom3 r3;
	  Double_t ranWmtDecay = r3.Uniform(rand()%100 / 100.);

	  TRandom3 r4;
	  Double_t ranTpWptDecay = r4.Uniform(rand()%100 / 100.);
	  TRandom3 r5;
	  Double_t ranTmWmtDecay = r5.Uniform(rand()%100 / 100.);


	  TRandom3 r6;
	  Double_t ranWpHDecay = r6.Uniform(rand()%100 / 100.);
	  TRandom3 r7;
	  Double_t ranWmHDecay = r7.Uniform(rand()%100 / 100.);

	  TRandom3 r8;
	  Double_t ranTpWpHDecay = r8.Uniform(rand()%100 / 100.);
	  TRandom3 r9;
	  Double_t ranTmWmHDecay = r9.Uniform(rand()%100 / 100.);

	  nWW++;
	  //Top Quark
 	  Double_t LpWpt    = IsLfromW(ranWptDecay); // first lepton from WT
	  //Double_t QqWpt    = IsQfromW(ranWptDecay); // W goes hadronically 
	  Double_t TpWpt    = IsTfromW(ranWptDecay); // random number for same W will be same as for one before
	  Double_t LpTpWpt  = 0;
	  Double_t ThTpWpt  = 0;
	  if(TpWpt) 
	    {
	      LpTpWpt = IsLfromT(ranTpWptDecay); // second lepton from TWpt
	      ThTpWpt = IsQfromT(ranTpWptDecay); // Tau gets hadronic
	    }

	  //Anti Top Quark
	  Double_t LmWmt    = IsLfromW(ranWmtDecay); // third lepton from WTbar
	  //Double_t QqWmt    = IsQfromW(ranWmtDecay); // W goes hadronically 
	  Double_t TmWmt    = IsTfromW(ranWmtDecay); // random number for same W will be same as for one before
	  Double_t LmTmWmt  = 0;
	  Double_t ThTmWmt  = 0;
	  if(TmWmt)
	    {
	      LmTmWmt = IsLfromT(ranTmWmtDecay); //  fourth lepton from TWptbar
	      ThTmWmt = IsQfromT(ranTmWmtDecay); // Tau gets hadronic
	    }

	  //Higgs Wp
	  Double_t LpWpH    = IsLfromW(ranWpHDecay); // fifth lepton from WpH
	  //Double_t QqWpH    = IsQfromW(ranWpHDecay); // hadronic  WpH
	  Double_t TpWpH    = IsTfromW(ranWpHDecay); // random number for same W will be same as for one before
	  Double_t LpTpWpH  = 0;
	  Double_t ThTpWpH  = 0;
	  if(TpWpH)
	    {
	      LpTpWpH = IsLfromT(ranTpWpHDecay); // Sixth lepton from TpWpH
	      ThTpWpH = IsQfromT(ranTpWpHDecay); // Tau gets hadronic
	    }

	  //Higgs Wm
	  Double_t LmWmH    = IsLfromW(ranWmHDecay); // Seventh lepton from WpH
	  //Double_t QqWmH    = IsQfromW(ranWmHDecay); // hadronic  WpH
	  Double_t TmWmH    = IsTfromW(ranWmHDecay); // random number for same W will be same as for one before
	  Double_t LmTmWmH  = 0;
	  Double_t ThTmWmH  = 0;
	  if(TmWmH) 
	    {
	      LmTmWmH = IsLfromT(ranTmWmHDecay); // Eighth lepton from TpWpH
	      ThTmWmH = IsQfromT(ranTmWmHDecay); // Tau gets hadronic
	    }

	  vector <Double_t> vLp;
	  vector <Double_t> vLm;
	  //vector <Double_t> vQq;
	  vector <Double_t> vTh;

	  if(ThTmWmH) vTh.push_back(ThTmWmH);
	  if(ThTpWpH) vTh.push_back(ThTpWpH);
	  if(ThTmWmt) vTh.push_back(ThTmWmt);
	  if(ThTpWpt) vTh.push_back(ThTpWpt);
	  
	  if(LpWpt)   vLp.push_back(LpWpt);
	  if(LpTpWpt) vLp.push_back(LpTpWpt);
	  if(LpWpH)   vLp.push_back(LpWpH);
	  if(LpTpWpH) vLp.push_back(LpTpWpH);


	  if(LmWmt)   vLm.push_back(LmWmt);
	  if(LmTmWmt) vLm.push_back(LmTmWmt);
	  if(LmWmH)   vLm.push_back(LmWmH);
	  if(LmTmWmH) vLm.push_back(LmTmWmH);

	  Double_t nL  = vLp.size()+vLm.size();
	  Double_t nTh = vTh.size();
	  //	  cout<< nL<<endl;
	  if(nL == 0)
	    {
	      if(nTh == 0) HWWn0l0Th++;
	      if(nTh == 1) HWWn0l1Th++;
	      if(nTh == 2) HWWn0l2Th++;
	      if(nTh == 3) HWWn0l3Th++;
	      if(nTh == 4) HWWn0l4Th++;
	    }
	  if(nL == 1)
	    {
	      if(nTh == 0) HWWn1l0Th++;
	      if(nTh == 1) HWWn1l1Th++;
	      if(nTh == 2) HWWn1l2Th++;
	      if(nTh == 3) HWWn1l3Th++;
	      if(nTh == 4) HWWn1l4Th++;
		
	    }
	  if(nL == 2)
	    {
	      if(nTh == 0) HWWn2l0Th++;
	      if(nTh == 1) HWWn2l1Th++;
	      if(nTh == 2) HWWn2l2Th++;
	      if(nTh == 3) HWWn2l3Th++;
	      if(nTh == 4) HWWn2l4Th++;
	      if(vLp.size() == 2 || vLm.size() == 2 )
		{
		  if(nTh == 0) HWWn2lss0Th++;
		  if(nTh == 1) HWWn2lss1Th++;
		  if(nTh == 2) HWWn2lss2Th++;
		  if(nTh == 3) HWWn2lss3Th++;
		  if(nTh == 4) HWWn2lss4Th++;
		}
		//cout<< "got two same sign candidate"<<endl;
	      if(vLp.size() == 1 && vLm.size() == 1 )
		{
		  if(nTh == 0) HWWn2los0Th++;
		  if(nTh == 1) HWWn2los1Th++;
		  if(nTh == 2) HWWn2los2Th++;
		  if(nTh == 3) HWWn2los3Th++;
		  if(nTh == 4) HWWn2los4Th++;
		}
	    }

	  if(nL == 3)
	    {
	      if(nTh == 0) HWWn3l0Th++;
	      if(nTh == 1) HWWn3l1Th++;
	      if(nTh == 2) HWWn3l2Th++;
	      if(nTh == 3) HWWn3l3Th++;
	      if(nTh == 4) HWWn3l4Th++;
	      //cout<< "got three same sign candidate"<<endl;
	    }
	  if(nL == 4)
	    {
	      if(nTh == 0) HWWn4l0Th++;
	      if(nTh == 1) HWWn4l1Th++;
	      if(nTh == 2) HWWn4l2Th++;
	      if(nTh == 3) HWWn4l3Th++;
	      if(nTh == 4) HWWn4lTh++;
	    }
 
	}// Higgs to WW 


      if(IsZZfromH(ranHDecay))
	{


	  TRandom3 r2;
	  Double_t ranWptDecay = r2.Uniform(rand()%100 / 100.);
	  TRandom3 r3;
	  Double_t ranWmtDecay = r3.Uniform(rand()%100 / 100.);

	  TRandom3 r4;
	  Double_t ranTpWptDecay = r4.Uniform(rand()%100 / 100.);
	  TRandom3 r5;
	  Double_t ranTmWmtDecay = r5.Uniform(rand()%100 / 100.);

	  TRandom3 r6;
	  Double_t ranZ1HDecay = r6.Uniform(rand()%100 / 100.);
	  TRandom3 r7;
	  Double_t ranZ2HDecay = r7.Uniform(rand()%100 / 100.);


	  TRandom3 r8;
	  Double_t ranTpZ1HDecay = r8.Uniform(rand()%100 / 100.);
	  TRandom3 r9;
	  Double_t ranTmZ1HDecay = r9.Uniform(rand()%100 / 100.);

	  TRandom3 r10;
	  Double_t ranTpZ2HDecay = r10.Uniform(rand()%100 / 100.);
	  TRandom3 r11;
	  Double_t ranTmZ2HDecay = r11.Uniform(rand()%100 / 100.);

	  nZZ++;
	  //Top Quark
	  Double_t LpWpt    = IsLfromW(ranWptDecay); // first lepton from WT
	  Double_t QqWpt    = IsQfromW(ranWptDecay); // W goes hadronically 
	  Double_t TpWpt    = IsTfromW(ranWptDecay); // random number for same W will be same as for one before
	  Double_t LpTpWpt  = 0;
	  Double_t ThTpWpt  = 0;
	  if(TpWpt) 
	    {
	      LpTpWpt = IsLfromT(ranTpWptDecay); // second lepton from TWpt
	      ThTpWpt = IsQfromT(ranTpWptDecay); // Tau gets hadronic
	    }

	  //Anti Top Quark
	  Double_t LmWmt    = IsLfromW(ranWmtDecay); // third lepton from WTbar
	  Double_t QqWmt    = IsQfromW(ranWmtDecay); // W goes hadronically 
	  Double_t TmWmt    = IsTfromW(ranWmtDecay); // random number for same W will be same as for one before
	  Double_t LmTmWmt  = 0;
	  Double_t ThTmWmt  = 0;
	  if(TmWmt)
	    {
	      LmTmWmt = IsLfromT(ranTmWmtDecay); //  fourth lepton from TWptbar
	      ThTmWmt = IsQfromT(ranTmWmtDecay); // Tau gets hadronic
	    }
	  
	  //Higgs Z1
	  Double_t LpZ1H    = IsLfromZ(ranZ1HDecay); // 5 lepton from WpH
	  Double_t LmZ1H    = IsLfromZ(ranZ1HDecay); // 6 

	  Double_t TpZ1H    = IsTfromZ(ranZ1HDecay); // random number for same W will be same as for one before
	  Double_t LpTpZ1H  = 0;
	  Double_t ThTpZ1H  = 0;
	  if(TpZ1H) 
	    {
	      LpTpZ1H = IsLfromT(ranTpZ1HDecay); // 7 lepton from TpZ1H
	      ThTpZ1H = IsQfromT(ranTpZ1HDecay);  // tau goes hadronic
	    }

	  Double_t TmZ1H    = IsTfromZ(ranZ1HDecay); // random number for same W will be same as for one before
	  Double_t LmTmZ1H  = 0;
	  Double_t ThTmZ1H  = 0;
	  if(TmZ1H)
	    {
	      LmTmZ1H = IsLfromT(ranTmZ1HDecay); // 8 lepton from TpWpH
	      ThTmZ1H = IsQfromT(ranTmZ1HDecay);  // tau goes hadronic
	    }

	  //Higgs Z2
	  Double_t LpZ2H    = IsLfromZ(ranZ2HDecay); // 9 lepton from WpH
	  Double_t LmZ2H    = IsLfromZ(ranZ2HDecay); // 10 lepton from WpH 

	  Double_t TpZ2H    = IsTfromZ(ranZ2HDecay); // random number for same W will be same as for one before
	  Double_t LpTpZ2H  = 0;
	  Double_t ThTpZ2H  = 0;
	  if(TpZ2H) 
	    {
	      LpTpZ2H = IsLfromT(ranTpZ2HDecay); // 11 lepton from TpWpH
	      ThTpZ2H = IsQfromT(ranTpZ2HDecay); // Tau goes hadronic
	    }


	  Double_t TmZ2H    = IsTfromZ(ranZ2HDecay); // random number for same W will be same as for one before
	  Double_t LmTmZ2H  = 0;
	  Double_t ThTmZ2H  = 0;
	  if(TmZ2H) 
	    {
	      LmTmZ2H = IsLfromT(ranTmZ2HDecay); // 12 lepton from TpWpH	  
	      ThTmZ2H = IsQfromT(ranTmZ2HDecay); // tau goes hadronic
	    }

	  vector <Double_t> vLp;
	  vector <Double_t> vLm;
	  vector <Double_t> vTh;

	  if(ThTmWmt) vTh.push_back(ThTmWmt);
	  if(ThTpWpt) vTh.push_back(ThTpWpt);
	  if(ThTmZ1H) vTh.push_back(ThTmZ1H);
	  if(ThTpZ1H) vTh.push_back(ThTpZ1H);
	  if(ThTmZ2H) vTh.push_back(ThTmZ2H);
	  if(ThTpZ2H) vTh.push_back(ThTpZ2H);


	  if(LpWpt)   vLp.push_back(LpWpt);
	  if(LpTpWpt) vLp.push_back(LpTpWpt);
	  if(LpZ1H)   vLp.push_back(LpZ1H);
	  if(LpTpZ1H) vLp.push_back(LpTpZ1H);
	  if(LpZ2H)   vLp.push_back(LpZ2H);
	  if(LpTpZ2H) vLp.push_back(LpTpZ2H);


	  if(LmWmt)   vLm.push_back(LmWmt);
	  if(LmTmWmt) vLm.push_back(LmTmWmt);
	  if(LmZ1H)   vLm.push_back(LmZ1H);
	  if(LmTmZ1H) vLm.push_back(LmTmZ1H);
	  if(LmZ2H)   vLm.push_back(LmZ2H);
	  if(LmTmZ2H) vLm.push_back(LmTmZ2H);


	  Double_t nL  = vLp.size()+vLm.size();
	  Double_t nTh = vTh.size();

	  //	  cout<< nL<<endl;

	  if(nL == 0)
	    {
	      if(nTh == 0) HZZn0l0Th++;
	      if(nTh == 1) HZZn0l1Th++;
	      if(nTh == 2) HZZn0l2Th++;
	      if(nTh == 3) HZZn0l3Th++;
	      if(nTh == 4) HZZn0l4Th++;
	      if(nTh == 5) HZZn0l5Th++;
	      if(nTh == 6) HZZn0l6Th++;
	    }

	  if(nL == 1)
	    {
	      if(nTh == 0) HZZn1l0Th++;
	      if(nTh == 1) HZZn1l1Th++;
	      if(nTh == 2) HZZn1l2Th++;
	      if(nTh == 3) HZZn1l3Th++;
	      if(nTh == 4) HZZn1l4Th++;
	      if(nTh == 5) HZZn1l5Th++;
	      if(nTh == 6) HZZn1l6Th++;
	    }

	  if(nL == 2)
	    {
	      if(nTh == 0) HZZn2l0Th++;
	      if(nTh == 1) HZZn2l1Th++;
	      if(nTh == 2) HZZn2l2Th++;
	      if(nTh == 3) HZZn2l3Th++;
	      if(nTh == 4) HZZn2l4Th++;
	      if(nTh == 5) HZZn2l5Th++;
	      if(nTh == 6) HZZn2l6Th++;
	      if(vLp.size() == 2 || vLm.size() == 2 )
		{
		  if(nTh == 0) HZZn2lss0Th++;
		  if(nTh == 1) HZZn2lss1Th++;
		  if(nTh == 2) HZZn2lss2Th++;
		  if(nTh == 3) HZZn2lss3Th++;
		  if(nTh == 4) HZZn2lss4Th++;
		  if(nTh == 5) HZZn2lss5Th++;
		  if(nTh == 6) HZZn2lss6Th++;
		  
		}
	      if(vLp.size() == 1 && vLm.size() == 1 )
		{
		  if(nTh == 0) HZZn2los0Th++;
		  if(nTh == 1) HZZn2los1Th++;
		  if(nTh == 2) HZZn2los2Th++;
		  if(nTh == 3) HZZn2los3Th++;
		  if(nTh == 4) HZZn2los4Th++;
		  if(nTh == 5) HZZn2los5Th++;
		  if(nTh == 6) HZZn2los6Th++;
		}
		//cout<< "got two same sign candidate"<<endl;
	    }

	  if(nL == 3)
	    {
	      if(nTh == 0) HZZn3l0Th++;
	      if(nTh == 1) HZZn3l1Th++;
	      if(nTh == 2) HZZn3l2Th++;
	      if(nTh == 3) HZZn3l3Th++;
	      if(nTh == 4) HZZn3l4Th++;
	      if(nTh == 5) HZZn3l5Th++;
	      if(nTh == 6) HZZn3l6Th++;
		//cout<< "got two same sign candidate"<<endl;
	    }
	  if(nL == 4)
	    {
	      if(nTh == 0) HZZn4l0Th++;
	      if(nTh == 1) HZZn4l1Th++;
	      if(nTh == 2) HZZn4l2Th++;
	      if(nTh == 3) HZZn4l3Th++;
	      if(nTh == 4) HZZn4l4Th++;
	      if(nTh == 5) HZZn4l5Th++;
	      if(nTh == 6) HZZn4l6Th++;
	    }

	  if(nL == 5)
	    {
	      if(nTh == 0) HZZn5l0Th++;
	      if(nTh == 1) HZZn5l1Th++;
	      if(nTh == 2) HZZn5l2Th++;
	      if(nTh == 3) HZZn5l3Th++;
	      if(nTh == 4) HZZn5l4Th++;
	      if(nTh == 5) HZZn5l5Th++;
	      if(nTh == 6) HZZn5l6Th++;
	    }
	  
	  if(nL == 6)
	    {
	      if(nTh == 0) HZZn6l0Th++;
	      if(nTh == 1) HZZn6l1Th++;
	      if(nTh == 2) HZZn6l2Th++;
	      if(nTh == 3) HZZn6l3Th++;
	      if(nTh == 4) HZZn6l4Th++;
	      if(nTh == 5) HZZn6l5Th++;
	      if(nTh == 6) HZZn6l6Th++;
	    }

	}
      
      if(IsTTfromH(ranHDecay))
	{

	  TRandom3 r2;
	  Double_t ranWptDecay = r2.Uniform(rand()%100 / 100.);
	  TRandom3 r3;
	  Double_t ranWmtDecay = r3.Uniform(rand()%100 / 100.);

	  TRandom3 r4;
	  Double_t ranTpWptDecay = r4.Uniform(rand()%100 / 100.);
	  TRandom3 r5;
	  Double_t ranTmWmtDecay = r5.Uniform(rand()%100 / 100.);

	  TRandom3 r6;
	  Double_t ranTpHDecay = r6.Uniform(rand()%100 / 100.);
	  TRandom3 r7;
	  Double_t ranTmHDecay = r7.Uniform(rand()%100 / 100.);



	  nTT++;
	  //Top Quark
	  Double_t LpWpt    = IsLfromW(ranWptDecay); // first lepton from WT
	  Double_t QqWpt    = IsQfromW(ranWptDecay); // W goes hadronically 
	  Double_t TpWpt    = IsTfromW(ranWptDecay); // random number for same W will be same as for one before
	  Double_t LpTpWpt  = 0;
	  Double_t ThTpWpt  = 0;
	  if(TpWpt) 
	    {
	      LpTpWpt = IsLfromT(ranTpWptDecay); // second lepton from TWpt
	      ThTpWpt = IsQfromT(ranTpWptDecay); // Tau gets hadronic
	    }

	  //Anti Top Quark
	  Double_t LmWmt    = IsLfromW(ranWmtDecay); // third lepton from WTbar
	  Double_t QqWmt    = IsQfromW(ranWmtDecay); // W goes hadronically 
	  Double_t TmWmt    = IsTfromW(ranWmtDecay); // random number for same W will be same as for one before
	  Double_t LmTmWmt  = 0;
	  Double_t ThTmWmt  = 0;
	  if(TmWmt)
	    {
	      LmTmWmt = IsLfromT(ranTmWmtDecay); //  fourth lepton from TWptbar
	      ThTmWmt = IsQfromT(ranTmWmtDecay); // Tau gets hadronic
	    }

	  
	  //Higgs Tp
	  Double_t LpTpH    = IsLfromT(ranTpHDecay); // 5 lepton from TpH
	  Double_t ThTpH    = IsQfromT(ranTpHDecay); // Tau goes hadronic
 	 
	  //Higgs Tm
	  Double_t LmTmH    = IsLfromT(ranTmHDecay); // 6 lepton from TmH
	  Double_t ThTmH    = IsQfromT(ranTmHDecay); // 6 lepton from TmH


	  vector <Double_t> vLp;
	  vector <Double_t> vTh;
	  vector <Double_t> vLm;
	  
	  if(ThTmWmt) vTh.push_back(ThTmWmt);
	  if(ThTpWpt) vTh.push_back(ThTpWpt);
	  if(ThTmH)   vTh.push_back(ThTmH);
	  if(ThTpH)   vTh.push_back(ThTpH);

	  if(LpWpt)   vLp.push_back(LpWpt);
	  if(LpTpWpt) vLp.push_back(LpTpWpt);
	  if(LpTpH)   vLp.push_back(LpTpH);

	  if(LmWmt)   vLm.push_back(LmWmt);
	  if(LmTmWmt) vLm.push_back(LmTmWmt);	  
	  if(LmTmH)   vLm.push_back(LmTmH);


	  Double_t nL  = vLp.size()+vLm.size();
	  Double_t nTh = vTh.size(); 

	  //cout<<nL<<"\t\t"<< nTh<<endl;
	  
	  if(nL == 0)
	    {
	      if(nTh == 0) HTTn0l0Th++;
	      if(nTh == 1) HTTn0l1Th++;
	      if(nTh == 2) HTTn0l2Th++;
	      if(nTh == 3) HTTn0l3Th++;
	      if(nTh == 4) HTTn0l4Th++;
	    }
	  if(nL == 1)
	    {
	      if(nTh == 0) HTTn1l0Th++;
	      if(nTh == 1) HTTn1l1Th++;
	      if(nTh == 2) HTTn1l2Th++;
	      if(nTh == 3) HTTn1l3Th++;
	      if(nTh == 4) HTTn1l4Th++;		
	    }


	  if(nL == 2)
	    {
	      if(nTh == 0) HTTn2l0Th++;
	      if(nTh == 1) HTTn2l1Th++;
	      if(nTh == 2) HTTn2l2Th++;
	      if(nTh == 3) HTTn2l3Th++;
	      if(nTh == 4) HTTn2l4Th++;		
	      if(vLp.size() == 2 || vLm.size() == 2 )
		{
		  if(nTh == 0) HTTn2lss0Th++;
		  if(nTh == 1) HTTn2lss1Th++;
		  if(nTh == 2) HTTn2lss2Th++;
		  if(nTh == 3) HTTn2lss3Th++;
		  if(nTh == 4) HTTn2lss4Th++;		

		}
	      if(vLp.size() == 1 && vLm.size() == 1 )
		{
		  if(nTh == 0) HTTn2los0Th++;
		  if(nTh == 1) HTTn2los1Th++;
		  if(nTh == 2) HTTn2los2Th++;
		  if(nTh == 3) HTTn2los3Th++;
		  if(nTh == 4) HTTn2los4Th++;		
		}
		//cout<< "got two same sign candidate"<<endl;
	    }

	  if(nL == 3)
	    {
	      if(nTh == 0) HTTn3l0Th++;
	      if(nTh == 1) HTTn3l1Th++;
	      if(nTh == 2) HTTn3l2Th++;
	      if(nTh == 3) HTTn3l3Th++;
	      if(nTh == 4) HTTn3l4Th++;		
		//cout<< "got two same sign candidate"<<endl;
	    }
	  if(nL == 4)
	    {
	      if(nTh == 0) HTTn4l0Th++;
	      if(nTh == 1) HTTn4l1Th++;
	      if(nTh == 2) HTTn4l2Th++;
	      if(nTh == 3) HTTn4l3Th++;
	      if(nTh == 4) HTTn4l4Th++;		
	    }

	}


      //      cout<<r.Uniform(rand()%100 / 100.)<<endl;

      //      cout<<NoofMu (ran1)<<endl;

      // Double_t TotalMuons =   NoofMu (ran1) + NoofMu (ran2)
      // 	                    + NoofMu (ran3) + NoofMu (ran4)
      // 	                    + NoofMu (ran5) + NoofMu (ran6)
      // 	                    + NoofMu (ran7) + NoofMu (ran8);


      


    }// end loop on events

  ofstream myfile;
  myfile.open ("MCToyEvtExp.txt", ios::app);
  myfile<<"\n\n\n";

  myfile<<"Total Lep Tau    "<<totalLepTau/TotalExp<<endl;
  myfile<<"Total Had Tau    "<<totalHadTau/TotalExp<<endl;

  myfile<<"\n\n\n";

  myfile<< "\tTotal Events\t"<< TotalExp<<"\tWW percentage\t"<<nWW/TotalExp<<endl;
  myfile<< "\tTotal Events\t"<< TotalExp<<"\tZZ percentage\t"<<nZZ/TotalExp<<endl;
  myfile<< "\tTotal Events\t"<< TotalExp<<"\tTT percentage\t"<<nTT/TotalExp<<endl;

  



  myfile<<"\n\n\n ________________________HWW______________________\n\n";

  myfile<< "\t0l 0Th  \t"<< HWWn0l0Th<<"\t percentage\t"<<HWWn0l0Th/TotalExp<<endl;
  myfile<< "\t0l 1Th  \t"<< HWWn0l1Th<<"\t percentage\t"<<HWWn0l1Th/TotalExp<<endl;
  myfile<< "\t0l 2Th  \t"<< HWWn0l2Th<<"\t percentage\t"<<HWWn0l2Th/TotalExp<<endl;
  myfile<< "\t0l 3Th  \t"<< HWWn0l3Th<<"\t percentage\t"<<HWWn0l3Th/TotalExp<<endl;
  myfile<< "\t0l 4Th  \t"<< HWWn0l4Th<<"\t percentage\t"<<HWWn0l4Th/TotalExp<<endl;


  myfile<< "\t1l 0Th  \t"<< HWWn1l0Th<<"\t percentage\t"<<HWWn1l0Th/TotalExp<<endl;
  myfile<< "\t1l 1Th  \t"<< HWWn1l1Th<<"\t percentage\t"<<HWWn1l1Th/TotalExp<<endl;
  myfile<< "\t1l 2Th  \t"<< HWWn1l2Th<<"\t percentage\t"<<HWWn1l2Th/TotalExp<<endl;
  myfile<< "\t1l 3Th  \t"<< HWWn1l3Th<<"\t percentage\t"<<HWWn1l3Th/TotalExp<<endl;
  myfile<< "\t1l 4Th  \t"<< HWWn1l4Th<<"\t percentage\t"<<HWWn1l4Th/TotalExp<<endl;

  myfile<< "\t2l 0Th  \t"<< HWWn2l0Th<<"\t percentage\t"<<HWWn2l0Th/TotalExp<<endl;
  myfile<< "\t2l 1Th  \t"<< HWWn2l1Th<<"\t percentage\t"<<HWWn2l1Th/TotalExp<<endl;
  myfile<< "\t2l 2Th  \t"<< HWWn2l2Th<<"\t percentage\t"<<HWWn2l2Th/TotalExp<<endl;
  myfile<< "\t2l 3Th  \t"<< HWWn2l3Th<<"\t percentage\t"<<HWWn2l3Th/TotalExp<<endl;
  myfile<< "\t2l 4Th  \t"<< HWWn2l4Th<<"\t percentage\t"<<HWWn2l4Th/TotalExp<<endl;

  myfile<< "\t2lss 0Th  \t"<< HWWn2lss0Th<<"\t percentage\t"<<HWWn2lss0Th/TotalExp<<endl;
  myfile<< "\t2lss 1Th  \t"<< HWWn2lss1Th<<"\t percentage\t"<<HWWn2lss1Th/TotalExp<<endl;
  myfile<< "\t2lss 2Th  \t"<< HWWn2lss2Th<<"\t percentage\t"<<HWWn2lss2Th/TotalExp<<endl;
  myfile<< "\t2lss 3Th  \t"<< HWWn2lss3Th<<"\t percentage\t"<<HWWn2lss3Th/TotalExp<<endl;
  myfile<< "\t2lss 4Th  \t"<< HWWn2lss4Th<<"\t percentage\t"<<HWWn2lss4Th/TotalExp<<endl;

  myfile<< "\t2los 0Th  \t"<< HWWn2los0Th<<"\t percentage\t"<<HWWn2los0Th/TotalExp<<endl;
  myfile<< "\t2los 1Th  \t"<< HWWn2los1Th<<"\t percentage\t"<<HWWn2los1Th/TotalExp<<endl;
  myfile<< "\t2los 2Th  \t"<< HWWn2los2Th<<"\t percentage\t"<<HWWn2los2Th/TotalExp<<endl;
  myfile<< "\t2los 3Th  \t"<< HWWn2los3Th<<"\t percentage\t"<<HWWn2los3Th/TotalExp<<endl;
  myfile<< "\t2los 4Th  \t"<< HWWn2los4Th<<"\t percentage\t"<<HWWn2los4Th/TotalExp<<endl;

  myfile<< "\t3l 0Th  \t"<< HWWn3l0Th<<"\t percentage\t"<<HWWn3l0Th/TotalExp<<endl;
  myfile<< "\t3l 1Th  \t"<< HWWn3l1Th<<"\t percentage\t"<<HWWn3l1Th/TotalExp<<endl;
  myfile<< "\t3l 2Th  \t"<< HWWn3l2Th<<"\t percentage\t"<<HWWn3l2Th/TotalExp<<endl;
  myfile<< "\t3l 3Th  \t"<< HWWn3l3Th<<"\t percentage\t"<<HWWn3l3Th/TotalExp<<endl;
  myfile<< "\t3l 4Th  \t"<< HWWn3l4Th<<"\t percentage\t"<<HWWn3l4Th/TotalExp<<endl;

  myfile<< "\t4l 0Th  \t"<< HWWn4l0Th<<"\t percentage\t"<<HWWn4l0Th/TotalExp<<endl;
  myfile<< "\t4l 1Th  \t"<< HWWn4l1Th<<"\t percentage\t"<<HWWn4l1Th/TotalExp<<endl;
  myfile<< "\t4l 2Th  \t"<< HWWn4l2Th<<"\t percentage\t"<<HWWn4l2Th/TotalExp<<endl;
  myfile<< "\t4l 3Th  \t"<< HWWn4l3Th<<"\t percentage\t"<<HWWn4l3Th/TotalExp<<endl;
  myfile<< "\t4l 4Th  \t"<< HWWn4l4Th<<"\t percentage\t"<<HWWn4l4Th/TotalExp<<endl;

  myfile<<"\n\n\n ________________________HTT______________________\n\n";

  myfile<< "\t0l 0Th  \t"<< HTTn0l0Th<<"\t percentage\t"<<HTTn0l0Th/TotalExp<<endl;
  myfile<< "\t0l 1Th  \t"<< HTTn0l1Th<<"\t percentage\t"<<HTTn0l1Th/TotalExp<<endl;
  myfile<< "\t0l 2Th  \t"<< HTTn0l2Th<<"\t percentage\t"<<HTTn0l2Th/TotalExp<<endl;
  myfile<< "\t0l 3Th  \t"<< HTTn0l3Th<<"\t percentage\t"<<HTTn0l3Th/TotalExp<<endl;
  myfile<< "\t0l 4Th  \t"<< HTTn0l4Th<<"\t percentage\t"<<HTTn0l4Th/TotalExp<<endl;

  myfile<< "\t1l 0Th  \t"<< HTTn1l0Th<<"\t percentage\t"<<HTTn1l0Th/TotalExp<<endl;
  myfile<< "\t1l 1Th  \t"<< HTTn1l1Th<<"\t percentage\t"<<HTTn1l1Th/TotalExp<<endl;
  myfile<< "\t1l 2Th  \t"<< HTTn1l2Th<<"\t percentage\t"<<HTTn1l2Th/TotalExp<<endl;
  myfile<< "\t1l 3Th  \t"<< HTTn1l3Th<<"\t percentage\t"<<HTTn1l3Th/TotalExp<<endl;
  myfile<< "\t1l 4Th  \t"<< HTTn1l4Th<<"\t percentage\t"<<HTTn1l4Th/TotalExp<<endl;

  myfile<< "\t2l 0Th  \t"<< HTTn2l0Th<<"\t percentage\t"<<HTTn2l0Th/TotalExp<<endl;
  myfile<< "\t2l 1Th  \t"<< HTTn2l1Th<<"\t percentage\t"<<HTTn2l1Th/TotalExp<<endl;
  myfile<< "\t2l 2Th  \t"<< HTTn2l2Th<<"\t percentage\t"<<HTTn2l2Th/TotalExp<<endl;
  myfile<< "\t2l 3Th  \t"<< HTTn2l3Th<<"\t percentage\t"<<HTTn2l3Th/TotalExp<<endl;
  myfile<< "\t2l 4Th  \t"<< HTTn2l4Th<<"\t percentage\t"<<HTTn2l4Th/TotalExp<<endl;

  myfile<< "\t2lss 0Th  \t"<< HTTn2lss0Th<<"\t percentage\t"<<HTTn2lss0Th/TotalExp<<endl;  
  myfile<< "\t2lss 1Th  \t"<< HTTn2lss1Th<<"\t percentage\t"<<HTTn2lss1Th/TotalExp<<endl;
  myfile<< "\t2lss 2Th  \t"<< HTTn2lss2Th<<"\t percentage\t"<<HTTn2lss2Th/TotalExp<<endl;
  myfile<< "\t2lss 3Th  \t"<< HTTn2lss3Th<<"\t percentage\t"<<HTTn2lss3Th/TotalExp<<endl;
  myfile<< "\t2lss 4Th  \t"<< HTTn2lss4Th<<"\t percentage\t"<<HTTn2lss4Th/TotalExp<<endl;

  myfile<< "\t2los 0Th  \t"<< HTTn2los0Th<<"\t percentage\t"<<HTTn2los0Th/TotalExp<<endl;  
  myfile<< "\t2los 1Th  \t"<< HTTn2los1Th<<"\t percentage\t"<<HTTn2los1Th/TotalExp<<endl;
  myfile<< "\t2los 2Th  \t"<< HTTn2los2Th<<"\t percentage\t"<<HTTn2los2Th/TotalExp<<endl;
  myfile<< "\t2los 3Th  \t"<< HTTn2los3Th<<"\t percentage\t"<<HTTn2los3Th/TotalExp<<endl;
  myfile<< "\t2los 4Th  \t"<< HTTn2los4Th<<"\t percentage\t"<<HTTn2los4Th/TotalExp<<endl;

  myfile<< "\t3l 0Th  \t"<< HTTn3l0Th<<"\t percentage\t"<<HTTn3l0Th/TotalExp<<endl;
  myfile<< "\t3l 1Th  \t"<< HTTn3l1Th<<"\t percentage\t"<<HTTn3l1Th/TotalExp<<endl;
  myfile<< "\t3l 2Th  \t"<< HTTn3l2Th<<"\t percentage\t"<<HTTn3l2Th/TotalExp<<endl;
  myfile<< "\t3l 3Th  \t"<< HTTn3l3Th<<"\t percentage\t"<<HTTn3l3Th/TotalExp<<endl;
  myfile<< "\t3l 4Th  \t"<< HTTn3l4Th<<"\t percentage\t"<<HTTn3l4Th/TotalExp<<endl;

  myfile<< "\t4l 0Th  \t"<< HTTn4l0Th<<"\t percentage\t"<<HTTn4l0Th/TotalExp<<endl;
  myfile<< "\t4l 1Th  \t"<< HTTn4l1Th<<"\t percentage\t"<<HTTn4l1Th/TotalExp<<endl;
  myfile<< "\t4l 2Th  \t"<< HTTn4l2Th<<"\t percentage\t"<<HTTn4l2Th/TotalExp<<endl;
  myfile<< "\t4l 3Th  \t"<< HTTn4l3Th<<"\t percentage\t"<<HTTn4l3Th/TotalExp<<endl;
  myfile<< "\t4l 4Th  \t"<< HTTn4l4Th<<"\t percentage\t"<<HTTn4l4Th/TotalExp<<endl;

  myfile<<"\n\n\n ________________________HZZ______________________\n\n";

  myfile<< "\t0l 0Th  \t"<< HZZn0l0Th<<"\t percentage\t"<<HZZn0l0Th/TotalExp<<endl;
  myfile<< "\t0l 1Th  \t"<< HZZn0l1Th<<"\t percentage\t"<<HZZn0l1Th/TotalExp<<endl;
  myfile<< "\t0l 2Th  \t"<< HZZn0l2Th<<"\t percentage\t"<<HZZn0l2Th/TotalExp<<endl;
  myfile<< "\t0l 3Th  \t"<< HZZn0l3Th<<"\t percentage\t"<<HZZn0l3Th/TotalExp<<endl;
  myfile<< "\t0l 4Th  \t"<< HZZn0l4Th<<"\t percentage\t"<<HZZn0l4Th/TotalExp<<endl;
  myfile<< "\t0l 5Th  \t"<< HZZn0l5Th<<"\t percentage\t"<<HZZn0l5Th/TotalExp<<endl;
  myfile<< "\t0l 6Th  \t"<< HZZn0l6Th<<"\t percentage\t"<<HZZn0l6Th/TotalExp<<endl;

  myfile<< "\t1l 0Th  \t"<< HZZn1l0Th<<"\t percentage\t"<<HZZn1l0Th/TotalExp<<endl;
  myfile<< "\t1l 1Th  \t"<< HZZn1l1Th<<"\t percentage\t"<<HZZn1l1Th/TotalExp<<endl;
  myfile<< "\t1l 2Th  \t"<< HZZn1l2Th<<"\t percentage\t"<<HZZn1l2Th/TotalExp<<endl;
  myfile<< "\t1l 3Th  \t"<< HZZn1l3Th<<"\t percentage\t"<<HZZn1l3Th/TotalExp<<endl;
  myfile<< "\t1l 4Th  \t"<< HZZn1l4Th<<"\t percentage\t"<<HZZn1l4Th/TotalExp<<endl;
  myfile<< "\t1l 5Th  \t"<< HZZn1l5Th<<"\t percentage\t"<<HZZn1l5Th/TotalExp<<endl;
  myfile<< "\t1l 6Th  \t"<< HZZn1l6Th<<"\t percentage\t"<<HZZn1l6Th/TotalExp<<endl;

  myfile<< "\t2l 0Th  \t"<< HZZn2l0Th<<"\t percentage\t"<<HZZn2l0Th/TotalExp<<endl;
  myfile<< "\t2l 1Th  \t"<< HZZn2l1Th<<"\t percentage\t"<<HZZn2l1Th/TotalExp<<endl;
  myfile<< "\t2l 2Th  \t"<< HZZn2l2Th<<"\t percentage\t"<<HZZn2l2Th/TotalExp<<endl;
  myfile<< "\t2l 3Th  \t"<< HZZn2l3Th<<"\t percentage\t"<<HZZn2l3Th/TotalExp<<endl;
  myfile<< "\t2l 4Th  \t"<< HZZn2l4Th<<"\t percentage\t"<<HZZn2l4Th/TotalExp<<endl;
  myfile<< "\t2l 5Th  \t"<< HZZn2l5Th<<"\t percentage\t"<<HZZn2l5Th/TotalExp<<endl;
  myfile<< "\t2l 6Th  \t"<< HZZn2l6Th<<"\t percentage\t"<<HZZn2l6Th/TotalExp<<endl;


  myfile<< "\t2lss 0Th  \t"<< HZZn2lss0Th<<"\t percentage\t"<<HZZn2lss0Th/TotalExp<<endl;
  myfile<< "\t2lss 1Th  \t"<< HZZn2lss1Th<<"\t percentage\t"<<HZZn2lss1Th/TotalExp<<endl;
  myfile<< "\t2lss 2Th  \t"<< HZZn2lss2Th<<"\t percentage\t"<<HZZn2lss2Th/TotalExp<<endl;
  myfile<< "\t2lss 3Th  \t"<< HZZn2lss3Th<<"\t percentage\t"<<HZZn2lss3Th/TotalExp<<endl;
  myfile<< "\t2lss 4Th  \t"<< HZZn2lss4Th<<"\t percentage\t"<<HZZn2lss4Th/TotalExp<<endl;
  myfile<< "\t2lss 5Th  \t"<< HZZn2lss5Th<<"\t percentage\t"<<HZZn2lss5Th/TotalExp<<endl;
  myfile<< "\t2lss 6Th  \t"<< HZZn2lss6Th<<"\t percentage\t"<<HZZn2lss6Th/TotalExp<<endl;

  myfile<< "\t2los 0Th  \t"<< HZZn2los0Th<<"\t percentage\t"<<HZZn2los0Th/TotalExp<<endl;
  myfile<< "\t2los 1Th  \t"<< HZZn2los1Th<<"\t percentage\t"<<HZZn2los1Th/TotalExp<<endl;
  myfile<< "\t2los 2Th  \t"<< HZZn2los2Th<<"\t percentage\t"<<HZZn2los2Th/TotalExp<<endl;
  myfile<< "\t2los 3Th  \t"<< HZZn2los3Th<<"\t percentage\t"<<HZZn2los3Th/TotalExp<<endl;
  myfile<< "\t2los 4Th  \t"<< HZZn2los4Th<<"\t percentage\t"<<HZZn2los4Th/TotalExp<<endl;
  myfile<< "\t2los 5Th  \t"<< HZZn2los5Th<<"\t percentage\t"<<HZZn2los5Th/TotalExp<<endl;
  myfile<< "\t2los 6Th  \t"<< HZZn2los6Th<<"\t percentage\t"<<HZZn2los6Th/TotalExp<<endl;

  myfile<< "\t3l 0Th  \t"<< HZZn3l0Th<<"\t percentage\t"<<HZZn3l0Th/TotalExp<<endl;
  myfile<< "\t3l 1Th  \t"<< HZZn3l1Th<<"\t percentage\t"<<HZZn3l1Th/TotalExp<<endl;
  myfile<< "\t3l 2Th  \t"<< HZZn3l2Th<<"\t percentage\t"<<HZZn3l2Th/TotalExp<<endl;
  myfile<< "\t3l 3Th  \t"<< HZZn3l3Th<<"\t percentage\t"<<HZZn3l3Th/TotalExp<<endl;
  myfile<< "\t3l 4Th  \t"<< HZZn3l4Th<<"\t percentage\t"<<HZZn3l4Th/TotalExp<<endl;
  myfile<< "\t3l 5Th  \t"<< HZZn3l5Th<<"\t percentage\t"<<HZZn3l5Th/TotalExp<<endl;
  myfile<< "\t3l 6Th  \t"<< HZZn3l6Th<<"\t percentage\t"<<HZZn3l6Th/TotalExp<<endl;

  myfile<< "\t4l 0Th  \t"<< HZZn4l0Th<<"\t percentage\t"<<HZZn4l0Th/TotalExp<<endl;
  myfile<< "\t4l 1Th  \t"<< HZZn4l1Th<<"\t percentage\t"<<HZZn4l1Th/TotalExp<<endl;
  myfile<< "\t4l 2Th  \t"<< HZZn4l2Th<<"\t percentage\t"<<HZZn4l2Th/TotalExp<<endl;
  myfile<< "\t4l 3Th  \t"<< HZZn4l3Th<<"\t percentage\t"<<HZZn4l3Th/TotalExp<<endl;
  myfile<< "\t4l 4Th  \t"<< HZZn4l4Th<<"\t percentage\t"<<HZZn4l4Th/TotalExp<<endl;
  myfile<< "\t4l 5Th  \t"<< HZZn4l5Th<<"\t percentage\t"<<HZZn4l5Th/TotalExp<<endl;
  myfile<< "\t4l 6Th  \t"<< HZZn4l6Th<<"\t percentage\t"<<HZZn4l6Th/TotalExp<<endl;

  myfile<< "\t5l 0Th  \t"<< HZZn5l0Th<<"\t percentage\t"<<HZZn5l0Th/TotalExp<<endl;
  myfile<< "\t5l 1Th  \t"<< HZZn5l1Th<<"\t percentage\t"<<HZZn5l1Th/TotalExp<<endl;
  myfile<< "\t5l 2Th  \t"<< HZZn5l2Th<<"\t percentage\t"<<HZZn5l2Th/TotalExp<<endl;
  myfile<< "\t5l 3Th  \t"<< HZZn5l3Th<<"\t percentage\t"<<HZZn5l3Th/TotalExp<<endl;
  myfile<< "\t5l 4Th  \t"<< HZZn5l4Th<<"\t percentage\t"<<HZZn5l4Th/TotalExp<<endl;
  myfile<< "\t5l 5Th  \t"<< HZZn5l5Th<<"\t percentage\t"<<HZZn5l5Th/TotalExp<<endl;
  myfile<< "\t5l 6Th  \t"<< HZZn5l6Th<<"\t percentage\t"<<HZZn5l6Th/TotalExp<<endl;

  myfile<< "\t6l 0Th  \t"<< HZZn6l0Th<<"\t percentage\t"<<HZZn6l0Th/TotalExp<<endl;
  myfile<< "\t6l 1Th  \t"<< HZZn6l1Th<<"\t percentage\t"<<HZZn6l1Th/TotalExp<<endl;
  myfile<< "\t6l 2Th  \t"<< HZZn6l2Th<<"\t percentage\t"<<HZZn6l2Th/TotalExp<<endl;
  myfile<< "\t6l 3Th  \t"<< HZZn6l3Th<<"\t percentage\t"<<HZZn6l3Th/TotalExp<<endl;
  myfile<< "\t6l 4Th  \t"<< HZZn6l4Th<<"\t percentage\t"<<HZZn6l4Th/TotalExp<<endl;
  myfile<< "\t6l 5Th  \t"<< HZZn6l5Th<<"\t percentage\t"<<HZZn6l5Th/TotalExp<<endl;
  myfile<< "\t6l 6Th  \t"<< HZZn6l6Th<<"\t percentage\t"<<HZZn6l6Th/TotalExp<<endl;


  myfile<<endl<<endl<<"________________________________________________________\n\n\n\n"<<endl;
  
  // cout<< "\tFinalState\t    HtoWW \t    HtoTT \t    HtoZZ \t   Total"<<endl;
  // cout<< "\t2lss\t\t  "<<HWWn2lss<<"\t  "<<HTTn2lss<<"\t  "<<HZZn2lss<<"\t  "<<HWWn2lss+HTTn2lss+HZZn2lss<<endl;
  // cout<< "\t3l\t\t  "<<HWWn3l<<"\t  "<<HTTn3l<<"\t  "<<HZZn3l<<"\t  "<<HWWn3l+HTTn3l+HZZn3l<<endl;
  // cout<< "\t4l\t\t  "<<HWWn4l<<"\t  "<<HTTn4l<<"\t  "<<HZZn4l<<"\t  "<<HWWn4l+HTTn4l+HZZn4l<<endl;
  // cout<< "__________________________________________________________\n\n"; 



  // cout<<endl<<endl<<"________________________________________________________\n\n\n\n"<<endl;
  
  // cout<< "\tFinalState\t    HtoWW \t    HtoTT \t    HtoZZ \t   Total"<<endl;
  // cout<< "\t2lss\t\t  "<<HWWn2lss*Weight<<"\t  "<<HTTn2lss*Weight<<"\t  "<<HZZn2lss*Weight<<"\t  "<<(HWWn2lss+HTTn2lss+HZZn2lss)*Weight<<endl;
  // cout<< "\t3l\t\t  "<<HWWn3l*Weight<<"\t  "<<HTTn3l*Weight<<"\t  "<<HZZn3l*Weight<<"\t  "<<(HWWn3l+HTTn3l+HZZn3l)*Weight<<endl;
  // cout<< "\t4l\t\t  "<<HWWn4l*Weight<<"\t  "<<HTTn4l*Weight<<"\t  "<<HZZn4l*Weight<<"\t  "<<(HWWn4l+HTTn4l+HZZn4l)*Weight<<endl;
  // cout<< "__________________________________________________________\n\n"; 

} 

Double_t IsWWfromH (Double_t ran)
{
  Double_t WW =0;
  
  if(ran <= 0.216)
    WW++;

  return WW;
}

Double_t IsZZfromH (Double_t ran)
{
  Double_t ZZ =0;
  
  if(ran > 0.216 && ran<=0.2426)
    ZZ++;

  return ZZ;
}


Double_t IsTTfromH (Double_t ran)
{
  Double_t TT =0;
  
  if(ran > 0.2426 && ran<=0.3063)
    TT++;

  return TT;
}

Double_t IsLfromW (Double_t ran)
{
  Double_t L =0;
  
  if(ran <= 0.2132)
    L++;

  return L;
}

Double_t IsTfromW (Double_t ran)
{
  Double_t T =0;
  
  if(ran > 0.2132 && ran<= 0.3257)
    T++;

  return T;
}

Double_t IsQfromW (Double_t ran)
{
  Double_t Q =0;
  
  if(ran > 0.3257 && ran<= 1.0)
    Q++;

  return Q;
}


Double_t IsLfromZ (Double_t ran)
{
  Double_t L =0;
  
  if(ran <= 0.0672)
    L++;

  return L;
}

Double_t IsTfromZ (Double_t ran)
{
  Double_t T =0;
  
  if(ran > 0.0672 && ran<= 0.1009)
    T++;

  return T;
}

Double_t IsNufromZ (Double_t ran)
{
  Double_t Nu =0;
  
  if(ran > 0.1009 && ran<= 0.3009)
    Nu++;

  return Nu;
}


Double_t IsQfromZ (Double_t ran)
{
  Double_t Q =0;
  
  if(ran > 0.3009 && ran<= 1.0)
    Q++;

  return Q;
}


Double_t IsLfromT (Double_t ran)
{
  Double_t L =0;
  
  if(ran <= 0.3521)
    L++;

  return L;
}


Double_t IsQfromT (Double_t ran)
{
  Double_t Q =0;
  
  if(ran > 0.3521 && ran<= 1.0)
    Q++;

  return Q;
}
