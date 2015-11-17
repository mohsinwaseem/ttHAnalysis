#ifndef RePro_h
#define RePro_h

#include <iostream>

#include "../utilities/TreeAnalyserMC.C"
#include "../utilities/AuxTools.C"
#include "../utilities/Table.C"
#include "../utilities/Datasets.C"

class RePro : public TreeAnalyserMC
{
  public:
    RePro(const std::string SamplePath,
	const std::string SampleName,
	const std::string text_, 
	const int maxEvents_ = -1, 
	TTree* tree=0) : 
    TreeAnalyserMC("RePro", SamplePath, SampleName, text_, maxEvents_, tree) {
      auxTools_.StopwatchStart();
      mcSample = SampleName;
    };

    ~RePro() {};

    virtual void Loop();

    void MakeHisto (void);

  private:
    std::string mcSample;
    AuxTools auxTools_;
    Datasets datasets_;

    // Add your private variables/methods here

    TH1D* hGenPar_PdgId;
    TH1D* hGenJet_N;
    TH1D* hGenJet_Pt;
    

};

#endif // RePro_h
