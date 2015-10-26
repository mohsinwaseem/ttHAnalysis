void histExtractor()
{
  
  gROOT->Reset();
  // gStyle->SetStripDecimals();
  //gStyle->SetLabelOffset(2);
  //gStyle->SetLabelFont(132);
  //gStyle->SetLabelSize(2);
  //gStyle->SetFrameBorderMode(0);
  //gStyle->SetTitleBorderSize(0);
  //gStyle->SetStatBorderSize(0);
  //gStyle->SetErrorX(0) ;
  //gStyle->SetOptFit(000000);
  //  TCanvas *c1 = new TCanvas("c1","Z1Mass",800,800);
  //create, fill and draw h1
  gStyle->SetOptStat(kFALSE);
  gPad->SetLeftMargin(.18);
  gPad->SetBottomMargin(.18);
  gPad->SetTicky();
  gPad->SetTickx();
  TFile f1("Validation_Histograms_ttH125.root");
  TH1F *h1 = (TH1F*)f1.Get("hJet_ParFl_bDisJP");
  //h1->SetFillColor(kGreen-9);
  //h1->SetLineColor(kBlack);
  // h1->Smooth();

  
  h1->Draw("P");

  //TFile test("Mass.root","RECREATE");
  TFile test("4mu.root","RECREATE");
  h1->Write();
  test.Close();


}
