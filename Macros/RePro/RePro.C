#ifndef RePro_cxx
#define RePro_cxx

#include "RePro.h"
#include "../utilities/constants.h"

void RePro::Loop()
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

    Size_t nGenj = GenJet_Pt->size();
    Size_t nGenp = GenP_Pt->size();


    hGenJet_N -> Fill (nGenj);
    for(Size_t iGenj=0; iGenj<nGenj; iGenj++)
      {
	hGenJet_Pt->Fill(GenJet_Pt->at(iGenj));
      }

    for(Size_t iGenp=0; iGenp<nGenp; iGenp++)
      {
	if(GenP_Status->at(iGenp) == 21 || GenP_Status->at(iGenp) == 22 || GenP_Status->at(iGenp) == 23)
	  hGenPar_PdgId->Fill(GenP_PdgId->at(iGenp));
      }

    // Update the progress bar
    //    tools.ProgressBar(jentry, nentries, 100, 150);
    
  }

  cout<<endl;
  // Keep this line here!
  outFile->cd();

  // Create and write canvases here
  
  hGenJet_N      ->Scale(1/hGenJet_N->Integral());
  hGenJet_Pt     ->Scale(1/hGenJet_Pt->Integral());
  hGenPar_PdgId  ->Scale(1/hGenPar_PdgId->Integral());
  

  // Uncomment this line to write also the histograms to the file
  outFile->Write();
}

void RePro::MakeHisto (void)
{
  hGenPar_PdgId = new TH1D ("hGenPar_PdgId","hGenPar_PdgId",60,-30,30);
  

  hGenJet_N     = new TH1D ("hGenJet_N","hGenJet_N",40,-0.5,39.5);
  hGenJet_Pt    = new TH1D ("hGenJet_Pt","hGenJet_Pt",60,0,300);  
}

#endif // RePro_cxx
