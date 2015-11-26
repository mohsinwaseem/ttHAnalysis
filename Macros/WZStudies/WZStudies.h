#ifndef WZStudies_h
#define WZStudies_h

#include <iostream>

#include "../utilities/TreeAnalyserMC.C"
#include "../utilities/AuxTools.C"
#include "../utilities/Table.C"
#include "../utilities/Datasets.C"

class WZStudies : public TreeAnalyserMC
{
  public:
    WZStudies(const std::string SamplePath,
	const std::string SampleName,
	const std::string text_, 
	const int maxEvents_ = -1, 
	TTree* tree=0) : 
    TreeAnalyserMC("WZStudies", SamplePath, SampleName, text_, maxEvents_, tree) {
      auxTools_.StopwatchStart();
      mcSample = SampleName;
    };

    ~WZStudies() {};

    virtual void Loop();

  private:
    std::string mcSample;
    AuxTools auxTools_;
    Datasets datasets_;

    // Add your private variables/methods here
    void MakeHisto(void);
    void myPrintGenp(Size_t Indx, bool bPrintHeaders);
    
};

#endif // WZStudies_h
