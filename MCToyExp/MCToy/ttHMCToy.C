void ttHMCToy()
{
  Double_t pass =0.0;
  Double_t TotalExp = 5000000.0;
  
  Double_t nWW = 0.0;
  Double_t nZZ = 0.0;
  Double_t nTT = 0.0;
  
  Double_t nL  = 0.0;


  Double_t HWWn2l  = 0.0;
  Double_t HWWn3l  = 0.0;
  Double_t HWWn4l  = 0.0;
  Double_t HWWn5l  = 0.0;
  Double_t HWWn2lss  = 0.0;
  Double_t HWWn3lss  = 0.0;

  Double_t HZZn2l  = 0.0;
  Double_t HZZn3l  = 0.0;
  Double_t HZZn4l  = 0.0;
  Double_t HZZn5l  = 0.0;
  Double_t HZZn2lss  = 0.0;
  Double_t HZZn3lss  = 0.0;


  Double_t HTTn2l  = 0.0;
  Double_t HTTn3l  = 0.0;
  Double_t HTTn4l  = 0.0;
  Double_t HTTn5l  = 0.0;
  Double_t HTTn2lss  = 0.0;
  Double_t HTTn3lss  = 0.0;

  
  Double_t Lumi = 19.6;//fb-1
  Double_t Sigma = 130.2; //fb  508.5;//
  Double_t nEvtLumi = Sigma*Lumi;
  Double_t Weight =  nEvtLumi/TotalExp;

 
  // TH1D *test;
  // test = new TH1D ("test","test",1000,-2,2);

  for (Long64_t i=0; i<TotalExp; i++)
    {
      if(i%1000 == 0) 	cout<<i<<endl;
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
	  Double_t TpWpt    = IsTfromW(ranWptDecay); // random number for same W will be same as for one before
	  Double_t LpTpWpt  = 0;
	  if(TpWpt) LpTpWpt = IsLfromT(ranTpWptDecay); // second lepton from TWpt

	  //Anti Top Quark
	  Double_t LmWmt    = IsLfromW(ranWmtDecay); // third lepton from WTbar
	  Double_t TmWmt    = IsTfromW(ranWmtDecay); // random number for same W will be same as for one before
	  Double_t LmTmWmt  = 0;
	  if(TmWmt) LmTmWmt = IsLfromT(ranTmWmtDecay); //  fourth lepton from TWptbar
	  
	  //Higgs Wp
	  Double_t LpWpH    = IsLfromW(ranWpHDecay); // fifth lepton from WpH
	  Double_t TpWpH    = IsTfromW(ranWpHDecay); // random number for same W will be same as for one before
	  Double_t LpTpWpH  = 0;
	  if(TpWpH) LpTpWpH = IsLfromT(ranTpWpHDecay); // Sixth lepton from TpWpH

	  //Higgs Wm
	  Double_t LmWmH    = IsLfromW(ranWmHDecay); // Seventh lepton from WpH
	  Double_t TmWmH    = IsTfromW(ranWmHDecay); // random number for same W will be same as for one before
	  Double_t LmTmWmH  = 0;
	  if(TmWmH) LmTmWmH = IsLfromT(ranTmWmHDecay); // Eighth lepton from TpWpH
	  

	  vector <Double_t> vLp;
	  vector <Double_t> vLm;
	

	  if(LpWpt)   vLp.push_back(LpWpt);
	  if(LpTpWpt) vLp.push_back(LpTpWpt);
	  if(LpWpH)   vLp.push_back(LpWpH);
	  if(LpTpWpH) vLp.push_back(LpTpWpH);


	  if(LmWmt)   vLm.push_back(LmWmt);
	  if(LmTmWmt) vLm.push_back(LmTmWmt);
	  if(LmWmH)   vLm.push_back(LmWmH);
	  if(LmTmWmH) vLm.push_back(LmTmWmH);

	  Double_t nL = vLp.size()+vLm.size();
	  
	  //	  cout<< nL<<endl;
	  if(nL == 2)
	    {
	      HWWn2l++;
	      if(vLp.size() == 2 || vLm.size() == 2 )
		{
		  HWWn2lss++;
		}
		//cout<< "got two same sign candidate"<<endl;
	    }

	  if(nL == 3)
	    {
	      HWWn3l++;
	      if(vLp.size() == 3 || vLm.size() == 3 )
		{
		  HWWn3lss++;
		}
	      //cout<< "got three same sign candidate"<<endl;
	    }
	  if(nL == 4)
	    {
	      HWWn4l++;
	    }
	  if(nL == 5)
	    {
	      HWWn5l++;
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
 	  Double_t LpWpt    = IsLfromW(ranWptDecay); // 1 lepton from WT
	  Double_t TpWpt    = IsTfromW(ranWptDecay); // random number for same W will be same as for one before
	  Double_t LpTpWpt  = 0;
	  if(TpWpt) LpTpWpt = IsLfromT(ranTpWptDecay); // 2 lepton from TWpt

	  //Anti Top Quark
	  Double_t LmWmt    = IsLfromW(ranWmtDecay); // 3 lepton from WTbar
	  Double_t TmWmt    = IsTfromW(ranWmtDecay); // random number for same W will be same as for one before
	  Double_t LmTmWmt  = 0;
	  if(TmWmt) LmTmWmt = IsLfromT(ranTmWmtDecay); // 4 lepton from TWptbar
	  
	  //Higgs Z1
	  Double_t LpZ1H    = IsLfromZ(ranZ1HDecay); // 5 lepton from WpH
	  Double_t LmZ1H    = IsLfromZ(ranZ1HDecay); // 6 

	  Double_t TpZ1H    = IsTfromZ(ranZ1HDecay); // random number for same W will be same as for one before
	  Double_t LpTpZ1H  = 0;
	  if(TpZ1H) LpTpZ1H = IsLfromT(ranTpZ1HDecay); // 7 lepton from TpZ1H


	  Double_t TmZ1H    = IsTfromZ(ranZ1HDecay); // random number for same W will be same as for one before
	  Double_t LmTmZ1H  = 0;
	  if(TmZ1H) LmTmZ1H = IsLfromT(ranTmZ1HDecay); // 8 lepton from TpWpH

	  //Higgs Z2
	  Double_t LpZ2H    = IsLfromZ(ranZ2HDecay); // 9 lepton from WpH
	  Double_t LmZ2H    = IsLfromZ(ranZ2HDecay); // 10 lepton from WpH 

	  Double_t TpZ2H    = IsTfromZ(ranZ2HDecay); // random number for same W will be same as for one before
	  Double_t LpTpZ2H  = 0;
	  if(TpZ2H) LpTpZ2H = IsLfromT(ranTpZ2HDecay); // 11 lepton from TpWpH

	  Double_t TmZ2H    = IsTfromZ(ranZ2HDecay); // random number for same W will be same as for one before
	  Double_t LmTmZ2H  = 0;
	  if(TmZ2H) LmTmZ2H = IsLfromT(ranTmZ2HDecay); // 12 lepton from TpWpH	  


	  vector <Double_t> vLp;
	  vector <Double_t> vLm;
	

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


	  Double_t nL = vLp.size()+vLm.size();
	  
	  //	  cout<< nL<<endl;
	  if(nL == 2)
	    {
	      HZZn2l++;
	      if(vLp.size() == 2 || vLm.size() == 2 )
		{
		  HZZn2lss++;
		}
		//cout<< "got two same sign candidate"<<endl;
	    }

	  if(nL == 3)
	    {
	      HZZn3l++;
	      if(vLp.size() == 3 || vLm.size() == 3 )
		{
		  HZZn3lss++;
		}
		//cout<< "got two same sign candidate"<<endl;
	    }
	  if(nL == 4)
	    {
	      HZZn4l++;
	    }
	  if(nL == 5)
	    {
	      HZZn5l++;
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
	  Double_t ranTpWpHDecay = r6.Uniform(rand()%100 / 100.);
	  TRandom3 r7;
	  Double_t ranTmWmHDecay = r7.Uniform(rand()%100 / 100.);



	  nTT++;
	  //Top Quark
 	  Double_t LpWpt    = IsLfromW(ranWptDecay); // 1 lepton from WT
	  Double_t TpWpt    = IsTfromW(ranWptDecay); // random number for same W will be same as for one before
	  Double_t LpTpWpt  = 0;
	  if(TpWpt) LpTpWpt = IsLfromT(ranTpWptDecay); // 2 lepton from TWpt

	  //Anti Top Quark
	  Double_t LmWmt    = IsLfromW(ranWmtDecay); // 3 lepton from WTbar
	  Double_t TmWmt    = IsTfromW(ranWmtDecay); // random number for same W will be same as for one before
	  Double_t LmTmWmt  = 0;
	  if(TmWmt) LmTmWmt = IsLfromT(ranTmWmtDecay); // 4 lepton from TWptbar

	  
	  //Higgs Tp
	  Double_t LpTpH    = IsLfromT(ranTpWpHDecay); // 5 lepton from TpH

	  //Higgs Tm
	  Double_t LmTmH    = IsLfromT(ranTmWmHDecay); // 6 lepton from TmH


	  vector <Double_t> vLp;
	  vector <Double_t> vLm;

	  if(LpWpt)   vLp.push_back(LpWpt);
	  if(LpTpWpt) vLp.push_back(LpTpWpt);
	  if(LpTpH)   vLp.push_back(LpTpH);

	  if(LmWmt)   vLm.push_back(LmWmt);
	  if(LmTmWmt) vLm.push_back(LmTmWmt);	  
	  if(LmTmH)   vLm.push_back(LmTmH);


	  Double_t nL = vLp.size()+vLm.size();
	  
	  //	  cout<< nL<<endl;
	  if(nL == 2)
	    {
	      HTTn2l++;
	      if(vLp.size() == 2 || vLm.size() == 2 )
		{
		  HTTn2lss++;
		}
		//cout<< "got two same sign candidate"<<endl;
	    }

	  if(nL == 3)
	    {
	      HTTn3l++;
	      if(vLp.size() == 3 || vLm.size() == 3 )
		{
		  HTTn3lss++;
		}
		//cout<< "got two same sign candidate"<<endl;
	    }
	  if(nL == 4)
	    {
	      HTTn4l++;
	    }
	  if(nL == 5)
	    {
	      HTTn5l++;
	    }

	}


      //      cout<<r.Uniform(rand()%100 / 100.)<<endl;

      //      cout<<NoofMu (ran1)<<endl;

      // Double_t TotalMuons =   NoofMu (ran1) + NoofMu (ran2)
      // 	                    + NoofMu (ran3) + NoofMu (ran4)
      // 	                    + NoofMu (ran5) + NoofMu (ran6)
      // 	                    + NoofMu (ran7) + NoofMu (ran8);


      

    }
  cout<<"\n\n\n";

  cout<< "\tTotal Events\t"<< TotalExp<<"\tWW percentage\t"<<nWW/TotalExp<<endl;
  cout<< "\tTotal Events\t"<< TotalExp<<"\tZZ percentage\t"<<nZZ/TotalExp<<endl;
  cout<< "\tTotal Events\t"<< TotalExp<<"\tTT percentage\t"<<nTT/TotalExp<<endl;

  

  cout<<"\n\n\n ________________________HWW______________________\n\n";

  cout<< "\tTotal Events with 2l  \t"<< HWWn2l<<"\t percentage\t"<<HWWn2l/TotalExp<<endl;
  cout<< "\tTotal Events with 2lss\t"<< HWWn2lss<<"\t percentage\t"<<HWWn2lss/TotalExp<<endl;

  cout<< "\tTotal Events with 3l  \t"<< HWWn3l<<"\t percentage\t"<<HWWn3l/TotalExp<<endl;
  cout<< "\tTotal Events with 3lss\t"<< HWWn3lss<<"\t percentage\t"<<HWWn3lss/TotalExp<<endl;

  cout<< "\tTotal Events with 4l  \t"<< HWWn4l<<"\t percentage\t"<<HWWn4l/TotalExp<<endl;
  cout<< "\tTotal Events with 5l  \t"<< HWWn5l<<"\t percentage\t"<<HWWn5l/TotalExp<<endl;

  cout<<"\n\n\n ________________________HTT______________________\n\n";

  cout<< "\tTotal Events with 2l  \t"<< HTTn2l<<"\tL percentage\t"<<HTTn2l/TotalExp<<endl;
  cout<< "\tTotal Events with 2lss\t"<< HTTn2lss<<"\tL percentage\t"<<HTTn2lss/TotalExp<<endl;

  cout<< "\tTotal Events with 3l  \t"<< HTTn3l<<"\tL percentage\t"<<HTTn3l/TotalExp<<endl;
  cout<< "\tTotal Events with 3lss\t"<< HTTn3lss<<"\tL percentage\t"<<HTTn3lss/TotalExp<<endl;

  cout<< "\tTotal Events with 4l  \t"<< HTTn4l<<"\tL percentage\t"<<HTTn4l/TotalExp<<endl;
  cout<< "\tTotal Events with 5l  \t"<< HTTn5l<<"\tL percentage\t"<<HTTn5l/TotalExp<<endl;

  cout<<"\n\n\n ________________________HZZ______________________\n\n";

  cout<< "\tTotal Events with 2l  \t"<< HZZn2l<<"\tL percentage\t"<<HZZn2l/TotalExp<<endl;
  cout<< "\tTotal Events with 2lss\t"<< HZZn2lss<<"\tL percentage\t"<<HZZn2lss/TotalExp<<endl;

  cout<< "\tTotal Events with 3l  \t"<< HZZn3l<<"\tL percentage\t"<<HZZn3l/TotalExp<<endl;
  cout<< "\tTotal Events with 3lss\t"<< HZZn3lss<<"\tL percentage\t"<<HZZn3lss/TotalExp<<endl;

  cout<< "\tTotal Events with 4l  \t"<< HZZn4l<<"\tL percentage\t"<<HZZn4l/TotalExp<<endl;
  cout<< "\tTotal Events with 5l  \t"<< HZZn5l<<"\tL percentage\t"<<HZZn5l/TotalExp<<endl;


  cout<<endl<<endl<<"________________________________________________________\n\n\n\n"<<endl;
  
  cout<< "\tFinalState\t    HtoWW \t    HtoTT \t    HtoZZ \t   Total"<<endl;
  cout<< "\t2lss\t\t  "<<HWWn2lss<<"\t  "<<HTTn2lss<<"\t  "<<HZZn2lss<<"\t  "<<HWWn2lss+HTTn2lss+HZZn2lss<<endl;
  cout<< "\t3l\t\t  "<<HWWn3l<<"\t  "<<HTTn3l<<"\t  "<<HZZn3l<<"\t  "<<HWWn3l+HTTn3l+HZZn3l<<endl;
  cout<< "\t4l\t\t  "<<HWWn4l<<"\t  "<<HTTn4l<<"\t  "<<HZZn4l<<"\t  "<<HWWn4l+HTTn4l+HZZn4l<<endl;
  cout<< "__________________________________________________________\n\n"; 



  cout<<endl<<endl<<"________________________________________________________\n\n\n\n"<<endl;
  
  cout<< "\tFinalState\t    HtoWW \t    HtoTT \t    HtoZZ \t   Total"<<endl;
  cout<< "\t2lss\t\t  "<<HWWn2lss*Weight<<"\t  "<<HTTn2lss*Weight<<"\t  "<<HZZn2lss*Weight<<"\t  "<<(HWWn2lss+HTTn2lss+HZZn2lss)*Weight<<endl;
  cout<< "\t3l\t\t  "<<HWWn3l*Weight<<"\t  "<<HTTn3l*Weight<<"\t  "<<HZZn3l*Weight<<"\t  "<<(HWWn3l+HTTn3l+HZZn3l)*Weight<<endl;
  cout<< "\t4l\t\t  "<<HWWn4l*Weight<<"\t  "<<HTTn4l*Weight<<"\t  "<<HZZn4l*Weight<<"\t  "<<(HWWn4l+HTTn4l+HZZn4l)*Weight<<endl;
  cout<< "__________________________________________________________\n\n"; 

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
  
  if(ran > 0.0672 && ran<= 0.10085)
    T++;

  return T;
}


Double_t IsLfromT (Double_t ran)
{
  Double_t L =0;
  
  if(ran <= 0.3521)
    L++;

  return L;
}
