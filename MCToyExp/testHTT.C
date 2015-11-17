void testHTT()
{
  Double_t pass =0.0;
  Double_t TotalExp = 5000.0;
  
  Double_t nWW = 0.0;
  Double_t nZZ = 0.0;
  Double_t nTT = 0.0;

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



  for (Long64_t i=0; i<TotalExp; i++)
    {
      if(i%1000 == 0) 	cout<<i<<endl;
    
      TRandom3 r1;
      Double_t ranHDecay = r1.Uniform(rand()%100 / 100.);

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
	      if(nTh == 0) {HTTn0l0Th++;cout<<"it occured"<<endl;}
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

    }

  cout<<"\n\n\n";

  cout<< "\tTotal Events\t"<< TotalExp<<"\tWW percentage\t"<<nWW/TotalExp<<endl;
  cout<< "\tTotal Events\t"<< TotalExp<<"\tZZ percentage\t"<<nZZ/TotalExp<<endl;
  cout<< "\tTotal Events\t"<< TotalExp<<"\tTT percentage\t"<<nTT/TotalExp<<endl;


    cout<<"\n\n\n ________________________HTT______________________\n\n";

  cout<< "\t0l 0Th  \t"<< HTTn0l0Th<<"\t percentage\t"<<HTTn0l0Th/TotalExp<<endl;
  cout<< "\t0l 1Th  \t"<< HTTn0l1Th<<"\t percentage\t"<<HTTn0l1Th/TotalExp<<endl;
  cout<< "\t0l 2Th  \t"<< HTTn0l2Th<<"\t percentage\t"<<HTTn0l2Th/TotalExp<<endl;
  cout<< "\t0l 3Th  \t"<< HTTn0l3Th<<"\t percentage\t"<<HTTn0l3Th/TotalExp<<endl;
  cout<< "\t0l 4Th  \t"<< HTTn0l4Th<<"\t percentage\t"<<HTTn0l4Th/TotalExp<<endl;

  cout<< "\t1l 0Th  \t"<< HTTn1l0Th<<"\t percentage\t"<<HTTn1l0Th/TotalExp<<endl;
  cout<< "\t1l 1Th  \t"<< HTTn1l1Th<<"\t percentage\t"<<HTTn1l1Th/TotalExp<<endl;
  cout<< "\t1l 2Th  \t"<< HTTn1l2Th<<"\t percentage\t"<<HTTn1l2Th/TotalExp<<endl;
  cout<< "\t1l 3Th  \t"<< HTTn1l3Th<<"\t percentage\t"<<HTTn1l3Th/TotalExp<<endl;
  cout<< "\t1l 4Th  \t"<< HTTn1l4Th<<"\t percentage\t"<<HTTn1l4Th/TotalExp<<endl;

  cout<< "\t2l 0Th  \t"<< HTTn2l0Th<<"\t percentage\t"<<HTTn2l0Th/TotalExp<<endl;
  cout<< "\t2l 1Th  \t"<< HTTn2l1Th<<"\t percentage\t"<<HTTn2l1Th/TotalExp<<endl;
  cout<< "\t2l 2Th  \t"<< HTTn2l2Th<<"\t percentage\t"<<HTTn2l2Th/TotalExp<<endl;
  cout<< "\t2l 3Th  \t"<< HTTn2l3Th<<"\t percentage\t"<<HTTn2l3Th/TotalExp<<endl;
  cout<< "\t2l 4Th  \t"<< HTTn2l4Th<<"\t percentage\t"<<HTTn2l4Th/TotalExp<<endl;

  cout<< "\t2lss 0Th  \t"<< HTTn2lss0Th<<"\t percentage\t"<<HTTn2lss0Th/TotalExp<<endl;  
  cout<< "\t2lss 1Th  \t"<< HTTn2lss1Th<<"\t percentage\t"<<HTTn2lss1Th/TotalExp<<endl;
  cout<< "\t2lss 2Th  \t"<< HTTn2lss2Th<<"\t percentage\t"<<HTTn2lss2Th/TotalExp<<endl;
  cout<< "\t2lss 3Th  \t"<< HTTn2lss3Th<<"\t percentage\t"<<HTTn2lss3Th/TotalExp<<endl;
  cout<< "\t2lss 4Th  \t"<< HTTn2lss4Th<<"\t percentage\t"<<HTTn2lss4Th/TotalExp<<endl;

  cout<< "\t3l 0Th  \t"<< HTTn3l0Th<<"\t percentage\t"<<HTTn3l0Th/TotalExp<<endl;
  cout<< "\t3l 1Th  \t"<< HTTn3l1Th<<"\t percentage\t"<<HTTn3l1Th/TotalExp<<endl;
  cout<< "\t3l 2Th  \t"<< HTTn3l2Th<<"\t percentage\t"<<HTTn3l2Th/TotalExp<<endl;
  cout<< "\t3l 3Th  \t"<< HTTn3l3Th<<"\t percentage\t"<<HTTn3l3Th/TotalExp<<endl;
  cout<< "\t3l 4Th  \t"<< HTTn3l4Th<<"\t percentage\t"<<HTTn3l4Th/TotalExp<<endl;

  cout<< "\t4l 0Th  \t"<< HTTn4l0Th<<"\t percentage\t"<<HTTn4l0Th/TotalExp<<endl;
  cout<< "\t4l 1Th  \t"<< HTTn4l1Th<<"\t percentage\t"<<HTTn4l1Th/TotalExp<<endl;
  cout<< "\t4l 2Th  \t"<< HTTn4l2Th<<"\t percentage\t"<<HTTn4l2Th/TotalExp<<endl;
  cout<< "\t4l 3Th  \t"<< HTTn4l3Th<<"\t percentage\t"<<HTTn4l3Th/TotalExp<<endl;
  cout<< "\t4l 4Th  \t"<< HTTn4l4Th<<"\t percentage\t"<<HTTn4l4Th/TotalExp<<endl;
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
