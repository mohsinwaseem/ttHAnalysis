#ifndef EventYield_h
#define EventYield_h

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
  ParticleInfo()
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

struct ttHParIndx{
  
  Int_t t;
  Int_t tbar;
  Int_t H;


  Int_t Wpfromt;
  Int_t TpfromWpt;

  Int_t Wmfromtbar;
  Int_t TmfromWmtbar;


  Int_t WpfromH;
  Int_t TpfromWpH;
  
  Int_t WmfromH;
  Int_t TmfromWmH;


  Int_t Z1fromH;
  Int_t TpfromZ1H;
  Int_t TmfromZ1H;

  Int_t Z2fromH;
  Int_t TpfromZ2H;
  Int_t TmfromZ2H;


  Int_t TpfromH;
  Int_t TmfromH;



  ttHParIndx()
  {
    t = -1;
    tbar = -1;
    H = -1;
    
    
    Wpfromt = -1;
    TpfromWpt = -1;
    
    Wmfromtbar = -1;
    TmfromWmtbar = -1;
    
    
    WpfromH = -1;
    TpfromWpH = -1;
  
    WmfromH = -1;
    TmfromWmH = -1;
    
    
    Z1fromH = -1;
    TpfromZ1H = -1;
    TmfromZ1H = -1;

    Z2fromH = -1;
    TpfromZ2H = -1;
    TmfromZ2H = -1;
    
    
    TpfromH = -1;
    TmfromH = -1;
  }

};


class EventYield : public TreeAnalyserMC
{
  public:
    EventYield(const std::string SamplePath,
	const std::string SampleName,
	const std::string text_, 
	const int maxEvents_ = -1, 
	TTree* tree=0) : 
    TreeAnalyserMC("EventYield", SamplePath, SampleName, text_, maxEvents_, tree) {
      auxTools_.StopwatchStart();
      mcSample = SampleName;
    };

    ~EventYield() {};

    virtual void Loop();

  private:
    std::string mcSample;
    AuxTools auxTools_;
    Datasets datasets_;

    // Add your private variables/methods here
    Bool_t IsFinalGenp (Size_t MotIndx, vector<unsigned short>& Daug);
    
    Bool_t IsFinalGenpPy6 (Size_t MotIndx, vector<unsigned short>& Daug);
    
    Bool_t IsFinalBHadron(Int_t Index);

    void GetLeptonEntries(Int_t Indx, vector<ParticleInfo> &vGenLep);

    ParticleInfo SetParticleInfo (Int_t Indx, Double_t Pt, Double_t Eta, Double_t Phi, Double_t E, Int_t Id, Int_t Charge);
    
    void SortLepPt (vector<ParticleInfo> &vSort);
    
    void myPrintGenp(Size_t Indx, bool bPrintHeaders);

    Int_t GetFinalGenpIndx (Size_t MotIndx, vector<unsigned short>& Daug);
    
    ttHParIndx GetttHParIndices();

    void CalculateEventExpectation(void);

    Double_t CheckLeptonBranching(Size_t Indx);

};

#endif // EventYield_h
