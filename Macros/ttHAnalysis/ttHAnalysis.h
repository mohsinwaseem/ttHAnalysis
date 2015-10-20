#ifndef ttHAnalysis_h
#define ttHAnalysis_h

#include <iostream>

#include "../utilities/TreeAnalyserMC.C"
#include "../utilities/AuxTools.C"
#include "../utilities/Table.C"
#include "../utilities/Datasets.C"

class ttHAnalysis : public TreeAnalyserMC
{
  public:
    ttHAnalysis(const std::string SamplePath,
	const std::string SampleName,
	const std::string text_, 
	const int maxEvents_ = -1, 
	TTree* tree=0) : 
    TreeAnalyserMC("ttHAnalysis", SamplePath, SampleName, text_, maxEvents_, tree) {
      auxTools_.StopwatchStart();
      mcSample = SampleName;
    };

    ~ttHAnalysis() {};

    virtual void Loop();

  private:
    //    C11Func c11;
    std::string mcSample;
    AuxTools auxTools_;
    Datasets datasets_;

    // Add your private variables/methods here
};

#endif // ttHAnalysis_h
