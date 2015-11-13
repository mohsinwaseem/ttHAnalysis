void MCToy()
{
  Double_t pass =0.0;
  Double_t TotalExp = 10000000.0;
  
  Double_t nMu0   = 0.0;

  Double_t nMu1   = 0.0;

  Double_t nMu2   = 0.0;

  Double_t nMu3   = 0.0;

  Double_t nMu4   = 0.0;

  Double_t nMu5   = 0.0;

  Double_t nMu6   = 0.0;

  Double_t nMu7   = 0.0;

  Double_t nMu8   = 0.0;

  Double_t nMuG4  = 0.0;

  // TH1D *test;
  // test = new TH1D ("test","test",1000,-2,2);

  for (Size_t i=0; i<TotalExp; i++)
    {
      TRandom3 r1;
      Double_t ran1 = r1.Uniform(rand()%100 / 100.);
      TRandom3 r2;
      Double_t ran2 = r2.Uniform(rand()%100 / 100.);
      TRandom3 r3;
      Double_t ran3 = r3.Uniform(rand()%100 / 100.);
      TRandom3 r4;
      Double_t ran4 = r4.Uniform(rand()%100 / 100.);
      TRandom3 r5;
      Double_t ran5 = r5.Uniform(rand()%100 / 100.);
      TRandom3 r6;
      Double_t ran6 = r6.Uniform(rand()%100 / 100.);
      TRandom3 r7;
      Double_t ran7 = r7.Uniform(rand()%100 / 100.);
      TRandom3 r8;
      Double_t ran8 = r8.Uniform(rand()%100 / 100.);



      //      cout<<r.Uniform(rand()%100 / 100.)<<endl;

      //      cout<<NoofMu (ran1)<<endl;

      Double_t TotalMuons =   NoofMu (ran1) + NoofMu (ran2)
	                    + NoofMu (ran3) + NoofMu (ran4)
	                    + NoofMu (ran5) + NoofMu (ran6)
	                    + NoofMu (ran7) + NoofMu (ran8);


      if(TotalMuons >=4)
	nMuG4++;
      if(TotalMuons ==8)
	nMu8++;
      if(TotalMuons ==7)
	nMu7++;
      if(TotalMuons ==6)
	nMu6++;
      if(TotalMuons ==5)
	nMu5++;
      if(TotalMuons ==4)
	nMu4++;
      if(TotalMuons ==3)
	nMu3++;
      if(TotalMuons ==2)
	nMu2++;
      if(TotalMuons ==1)
	nMu1++;
      if(TotalMuons ==0)
	nMu0++;
      

    }
  cout<<"\n\n\n";
  cout<<"8  Muon events from 8 tau in   "<<TotalExp<<"\tExp are\t"<<nMu8<<" probability  is     "<< nMu8/TotalExp<<endl;
  cout<<"7  Muon events from 8 tau in   "<<TotalExp<<"\tExp are\t"<<nMu7<<" probability  is     "<< nMu7/TotalExp<<endl;
  cout<<"6  Muon events from 8 tau in   "<<TotalExp<<"\tExp are\t"<<nMu6<<" probability  is     "<< nMu6/TotalExp<<endl;
  cout<<"5  Muon events from 8 tau in   "<<TotalExp<<"\tExp are\t"<<nMu5<<" probability  is     "<< nMu5/TotalExp<<endl;
  cout<<"4  Muon events from 8 tau in   "<<TotalExp<<"\tExp are\t"<<nMu4<<" probability  is     "<< nMu4/TotalExp<<endl;
  cout<<"3  Muon events from 8 tau in   "<<TotalExp<<"\tExp are\t"<<nMu3<<" probability  is     "<< nMu3/TotalExp<<endl;
  cout<<"2  Muon events from 8 tau in   "<<TotalExp<<"\tExp are\t"<<nMu2<<" probability  is     "<< nMu2/TotalExp<<endl;
  cout<<"1  Muon events from 8 tau in   "<<TotalExp<<"\tExp are\t"<<nMu1<<" probability  is     "<< nMu1/TotalExp<<endl;
  cout<<"0  Muon events from 8 tau in   "<<TotalExp<<"\tExp are\t"<<nMu0<<" probability  is     "<< nMu0/TotalExp<<endl;

  cout<<"4+  Muon events from 8 tau in   "<<TotalExp<<"\tExp are\t"<<nMuG4<<" probability  is     "<< nMuG4/TotalExp<<endl;

 cout<<"\n\n\n";


} 

Double_t NoofMu (Double_t ran)
{
  Double_t Mu1 =0;
  
  if(ran <= 0.1736)
    Mu1++;
  // else if (ran > 0.1736 && ran <= 0.3521)
  //   E1++;
  // else if(ran > 0.3521)
  //   THad1++;

  return Mu1;
}
