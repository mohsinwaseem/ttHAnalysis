#ifndef HistoTools_h
#define HistoTools_h

#include <cmath>
#include <iomanip>
#include <TLorentzVector.h>

#include "TreeDefinitionGenP.h"
#include "AuxTools.h"

class HistoTools{

 public:
  virtual ~HistoTools() { };
  void BookHisto_1D(TH1D *&histo, 
		    const char* hName, 
		    const Int_t nBins, 
		    const Double_t xMin,  
		    const Double_t xMax);

  void BookHisto_2D(TH2D *&histo, 
		    const char* hName, 
		    const Int_t nBinsX, 
		    const Double_t xMin,  
		    const Double_t xMax, 
		    const Int_t nBinsY, 
		    const Double_t yMin,  
		    const Double_t yMax);

  void DivideHistos_1D(TH1D *hNumerator,
		       TH1D *hDenominator);
  
  void ConvertToRateHisto_1D(TH1D *histo, 
			     const Double_t nEvents,
			     const Double_t crossingRate=30.0E+06);
  
  void ConvertToRateHisto_2D(TH2D *histo, 
			     const Double_t nEvents, 
			     const Double_t crossingRate=30.0E+06);
  
  void ConvertToOneMinusCumulativeHisto_1D(TH1D *histo);
  
  void ConvertToOneMinusCumulativeHisto_2D(TH2D *histo);

  void FillAllBinsUpToValue_1D(TH1D *histo, 
			       const Double_t fillValue);

  void FillAllBinsUpToValue_2D(TH2D *histo, 
			       const Double_t xFillValue, 
			       const Double_t yFillValue);
  
  void ConvertNumeratorHistoToEfficiency_1D(TH1D *histo, 
					    const int nEvtsTotal, 
					    const std::string errType = "binomial");
  
  void ConvertNumeratorHistoToEfficiency_2D(TH2D *histo, 
					    const int nEvtsTotal,
					    const std::string errType = "binomial");

 private:
  AuxTools tools;

};

#endif // HistoTools_h
