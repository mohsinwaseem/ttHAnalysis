#ifndef HistoTools_cxx
#define HistoTools_cxx

#include "HistoTools.h"

//#define DEBUG

//****************************************************************************
void HistoTools::BookHisto_1D(TH1D *&histo, 
			      const char *hName, 
			      const Int_t nBins, 
			      const Double_t xMin,  
			      const Double_t xMax)
//****************************************************************************
{

  histo = new TH1D(hName, hName, nBins, xMin, xMax);
  histo->Sumw2();
  return;
}


//****************************************************************************
void HistoTools::BookHisto_2D(TH2D *&histo, 
			      const char *hName, 
			      const Int_t nBinsX, 
			      const Double_t xMin,  
			      const Double_t xMax,
			      const Int_t nBinsY, 
			      const Double_t yMin,  
			      const Double_t yMax)
//****************************************************************************
{

  histo = new TH2D(hName, hName, nBinsX, xMin, xMax, nBinsY, yMin, yMax);
  histo->Sumw2();
  return;
}


//****************************************************************************
void HistoTools::DivideHistos_1D(TH1D *hNumerator,
				 TH1D *hDenominator)
//****************************************************************************
{

  // Sanity Check
  for (int i = 0; i <= hNumerator->GetNbinsX()+1; i++){
    int N    = hNumerator  ->GetBinContent(i);
    int D    = hDenominator->GetBinContent(i);
    double r = double(N)/double(D);
    if ( r > 1.0) std::cout << "W A R N I N G ! HistoTools::DivideHistos_1D(...)  - bin " << i 
			    << " (eT = " << i*hNumerator->GetBinWidth(i) << " GeV): Numerator/Denominator = " 
			    << N << "/" << D << " = " << r << std::endl;
  }
  
  hNumerator->Divide(hNumerator, hDenominator, 1.0, 1.0, "binomial");
  return;
}


//****************************************************************************
void HistoTools::ConvertToOneMinusCumulativeHisto_1D(TH1D *histo)
//****************************************************************************
{
  
  // For-loop over all histogram bins
  const int nBins = histo->GetNbinsX()+1;
  for (int b=0; b <= nBins+1; b++){
    
    const double value = histo->Integral(b, nBins);
    const double error = TMath::Sqrt(value);
    histo->SetBinContent( b, value );
    histo->SetBinError  ( b, error );
  }
  return;
}


//****************************************************************************
void HistoTools::ConvertToOneMinusCumulativeHisto_2D(TH2D *histo)
//****************************************************************************
{
  // Leadng jet on x-axis

  // For-loop over all histogram bins
  const int nBinsX = histo->GetNbinsX()+1;
  const int nBinsY = histo->GetNbinsY()+1;
  
  // For-loop: x-axis bins
  for (int bx=0; bx <= nBinsX; bx++){

    // For-loop: y-axis bins
    for (int by=0; by <= nBinsY; by++){

      if (by > bx) break;
      const double value = histo->Integral(bx, nBinsX, by, nBinsY);
      const double error = TMath::Sqrt(value);
      histo->SetBinContent( bx, by, value );
      histo->SetBinError( bx, by, error );

    } // For-loop: y-axis bins
    
  } // For-loop: x-axis bins

  return;
}


//****************************************************************************
void HistoTools::ConvertToRateHisto_1D(TH1D *histo,
				       const Double_t nEvents, 
				       const Double_t crossingRate)
//****************************************************************************
{

  // Variable declarations
  const Double_t convertTokHz  = ( 1.0E-03);  // 1Hz -> 1kHz
  const Double_t normFactor    = (crossingRate * convertTokHz) / (nEvents);

  // Convert histogram to 1-cumulative
  ConvertToOneMinusCumulativeHisto_1D(histo);

  // Scale to desired crossing-rate
  histo->Scale( normFactor );


#ifdef DEBUG
  std::cout << "normFactor = Crossing_Rate x ConvertToKHz = " << crossingRate << " x " << convertTokHz << " = " << normFactor << std::endl;
#endif
  return;

}


//****************************************************************************
void HistoTools::ConvertToRateHisto_2D(TH2D *histo, 
				       const Double_t nEvents,
				       const Double_t crossingRate)
//****************************************************************************
{

  // Variable declarations
  const Double_t convertTokHz = ( 1.0E-03);  // 1Hz -> 1kHz
  const Double_t normFactor   = (crossingRate * convertTokHz) / (nEvents);

  // Convert histogram to 1-cumulative
  ConvertToOneMinusCumulativeHisto_2D(histo);

  // Scale to desired crossing-rate
  histo->Scale( normFactor );

  return;
}

#endif  // HistoTools_cxx

//****************************************************************************
void HistoTools::FillAllBinsUpToValue_1D(TH1D *histo, 
					 const Double_t fillValue)
//****************************************************************************
{

  // Variable declarations
  const int stepValue = int ( double(histo->GetXaxis()->GetXmax())/double(histo->GetNbinsX()) ); 
  const int maxValue  = histo->GetXaxis()->GetXmax();

  // For-loop: All bins
  for (int value = 0; value <= maxValue; value += stepValue){ 
    if ( fillValue >= value) histo->Fill(value);
  }
  
  return;
}


//****************************************************************************
void HistoTools::FillAllBinsUpToValue_2D(TH2D *histo, 
					 const Double_t xFillValue, 
					 const Double_t yFillValue)
//****************************************************************************
{

  // Variable declarations
  const int stepValue = int ( double(histo->GetXaxis()->GetXmax())/double(histo->GetNbinsX()) ); 
  const int yMaxValue = histo->GetYaxis()->GetXmax();
  const int xMaxValue = histo->GetXaxis()->GetXmax();

  if (yMaxValue != xMaxValue)
    {
      std::cout << "W A R N I N G ! HistoTools::FillAllBinsUpToCaloEtHisto_2D(...) - X-axis max is different than Y-axis max.\nExiting \n";
      exit(1);    
    }
  
  // For-loop: x-axis 
  for (int xVal = 0; xVal <= xMaxValue; xVal+=stepValue)
    {
      
      // Only x-axis values up to xFillValue
      if (xVal > xFillValue) break;
      
      // For-loop: y-axis
      for (int yVal = 0; yVal <= yMaxValue; yVal+=stepValue)
	{
	  
	  // Only y-axis values up to yFillValue
	  if (yVal > yFillValue) break;
	  
	  // Sanity check: xEt is leading value => xVal > yVal
	  if (yVal > xVal) break;
      
	  // Fill histogram with the values
	  histo->Fill(xVal, yVal);

	}// For-loop: y-axis 
      
    }// For-loop: x-axis
  
  return;
}


//****************************************************************************
void HistoTools::ConvertNumeratorHistoToEfficiency_1D(TH1D *histo, 
						      const int nEvtsTotal, 
						      const std::string errType)
//****************************************************************************
{
  
  // Variable declarations
  const int nBins = histo->GetNbinsX()+1;
  double eff, err;

  // For-loop: all bins
  for (int bx = 0; bx <= nBins; bx++){
    
    // Calculate efficiency value and error
    const int nPass = histo->GetBinContent(bx);
    tools.Efficiency(nPass, nEvtsTotal, errType, eff, err );
  
    // Replace histogram's bin contect with efficiency and its error
    histo->SetBinContent(bx, eff);
    histo->SetBinError  (bx, err);
  }

  return;
}


//****************************************************************************
void HistoTools::ConvertNumeratorHistoToEfficiency_2D(TH2D *histo, 
						      const int nEvtsTotal,
						      const std::string errType)
//****************************************************************************
{

  // Variable declarations
  const int nBinsX  = histo->GetNbinsX()+1;
  const int nBinsY  = histo->GetNbinsY()+1;
  double eff, err;
  
  // For-loop: x-axis bins
  for (int bx=0; bx <= nBinsX; bx++){

    // For-loop: y-axis bins
    for (int by=0; by <= nBinsY; by++){

      const int nPass = histo->GetBinContent(bx, by);
      tools.Efficiency(nPass, nEvtsTotal, errType, eff, err );

      // Update current histo bin to true eff value and error
      histo->SetBinContent(bx, by, eff);
      histo->SetBinError  (bx, by, err);

    } // For-loop: y-axis bins

  }// For-loop: x-axis bins

  return;
}

//#endif // HistoTools_cxx


