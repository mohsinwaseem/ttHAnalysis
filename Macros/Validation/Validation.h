#ifndef Validation_h
#define Validation_h

#include <iostream>

#include <TProfile.h>

#include "../utilities/TreeAnalyserMC.C"
#include "../utilities/AuxTools.C"
#include "../utilities/Table.C"
#include "../utilities/Datasets.C"

class Validation : public TreeAnalyserMC
{
  public:
    Validation(const std::string SamplePath,
	const std::string SampleName,
	const std::string text_, 
	const int maxEvents_ = -1, 
	TTree* tree=0) : 
    TreeAnalyserMC("Validation", SamplePath, SampleName, text_, maxEvents_, tree) {
      auxTools_.StopwatchStart();
      mcSample = SampleName;
    };

    ~Validation() {};

    virtual void Loop();

  private:
    std::string mcSample;
    AuxTools auxTools_;
    Datasets datasets_;

    // Add your private variables/methods here
    void MakeHisto(void);

    Bool_t IsFinalGenp (Size_t MotIndx, vector<unsigned short>& Daug);
    
    //Histograms
    //Electron
    TH1D *hElec_Pt;
    TH1D *hElec_Eta;
    TH1D *hElec_Phi;
    TH1D *hElec_E;
    TH1D *hElec_Charge;
    
    TH1D *hElec_SCl_Eta;
    TH1D *hElec_SCl_EtaWidth;
    TH1D *hElec_SCl_Phi;
    TH1D *hElec_SCl_PhiWidth;
    TH1D *hElec_SCl_E;
    TH1D *hElec_SCl_RawE;
    
    TH1D *hElec_GsfTrack_D0;
    TH1D *hElec_GsfTrack_Z0;
    TH1D *hElec_GsfTrack_D0Error;
    TH1D *hElec_GsfTrack_Z0Error;
    TH1D *hElec_GsfTrack_NormalizedChi2;
    
    TH1D *hElec_IP3d;
    TH1D *hElec_IP3dError;
    TH1D *hElec_IP2d;
    TH1D *hElec_IP2dError;

    //Muon
    TH1D *hMuon_Pt;
    TH1D *hMuon_Eta;
    TH1D *hMuon_Phi;
    TH1D *hMuon_E;
    TH1D *hMuon_Charge;
    
    TH1D *hMuon_InnerTrack_D0;
    TH1D *hMuon_InnerTrack_Z0;
    TH1D *hMuon_InnerTrack_D0Error;
    TH1D *hMuon_InnerTrack_Z0Error;
    TH1D *hMuon_InnerTrack_NormalizedChi2;
    
    TH1D *hMuon_GlobalTrack_D0;
    TH1D *hMuon_GlobalTrack_Z0;
    TH1D *hMuon_GlobalTrack_D0Error;
    TH1D *hMuon_GlobalTrack_Z0Error;
    TH1D *hMuon_GlobalTrack_NormalizedChi2;
    
    TH1D *hMuon_IP3d;
    TH1D *hMuon_IP3dError;
    TH1D *hMuon_IP2d;
    TH1D *hMuon_IP2dError;

    //Tau
    TH1D *hTau_Pt;
    TH1D *hTau_Eta;
    TH1D *hTau_Phi;
    TH1D *hTau_E;
    TH1D *hTau_Charge;
    TH1D *hTau_DecayMode;
    
    TH1D *hTau_LeadChHadCand_Pt;
    TH1D *hTau_LeadChHadCand_Eta;
    TH1D *hTau_LeadChHadCand_Phi;
    TH1D *hTau_LeadChHadCand_E;
    TH1D *hTau_LeadChHadCand_Et;
    TH1D *hTau_LeadChHadCand_Id;
    TH1D *hTau_LeadChHadCand_Charge;
    TH1D *hTau_LeadChHadCand_Vx;
    TH1D *hTau_LeadChHadCand_Vy;
    TH1D *hTau_LeadChHadCand_Vz;
  
  
    //MET
    TH1D *hMET_Pt;
    TH1D *hMET_Phi;
    TH1D *hMET_SumEt;

    //Jet
    TH1D *hJet_Pt;
    TH1D *hJet_Eta;
    TH1D *hJet_Phi;
    TH1D *hJet_E;
    TH1D *hJet_JetArea;
    
    TH1D *hJet_ChMulti;
    TH1D *hJet_ChHadMulti;
    TH1D *hJet_NMulti;
    TH1D *hJet_NHadMulti;
    
    TH1D *hJet_ElecMulti;
    TH1D *hJet_MuonMulti;
    TH1D *hJet_PhotonMulti;
    
    TH1D *hJet_ParFl_bDisJP;
    TH1D *hJet_HadFl_bDisJP;
    
    TProfile *hJet_ParFl_bDisCMVA;
    TProfile *hJet_HadFl_bDisCMVA;
  
};

#endif // Validation_h
