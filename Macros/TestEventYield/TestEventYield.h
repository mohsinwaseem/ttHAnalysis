#ifndef TestEventYield_h
#define TestEventYield_h

#include <iostream>

#include "../utilities/TreeAnalyserMC.C"
#include "../utilities/AuxTools.C"
#include "../utilities/Table.C"
#include "../utilities/Datasets.C"

struct ParticleInfo{
  Double_t Pt;
  Double_t Eta;
  Double_t Phi;
  Double_t E;
  Int_t    PdgId;
  Int_t    Charge;
  Int_t    Indx;
  void init()
  {
    Pt     = -100;
    Eta    = -100;
    Phi    = -100;
    E      = -100;
    PdgId  = 0;
    Charge =-100;
    Indx   = -1;
  }

};

class TestEventYield : public TreeAnalyserMC
{
  public:
    TestEventYield(const std::string SamplePath,
	const std::string SampleName,
	const std::string text_, 
	const int maxEvents_ = -1, 
	TTree* tree=0) : 
    TreeAnalyserMC("TestEventYield", SamplePath, SampleName, text_, maxEvents_, tree) {
      auxTools_.StopwatchStart();
      mcSample = SampleName;
    };

    ~TestEventYield() {};

    virtual void Loop();

  private:
    std::string mcSample;
    AuxTools auxTools_;
    Datasets datasets_;

    // Add your private variables/methods here
    Bool_t IsFinalGenp (Size_t MotIndx, vector<unsigned short>& Daug);
    
    Bool_t IsFinalBHadron(Int_t Index);

    ParticleInfo SetParticleInfo (Int_t Indx, Double_t Pt, Double_t Eta, Double_t Phi, Double_t E, Int_t Id, Int_t Charge);
    
    void SortLepPt (vector<ParticleInfo> &vSort);
    
    void myPrintGenp(Size_t Indx, bool bPrintHeaders);
};

#endif // TestEventYield_h
