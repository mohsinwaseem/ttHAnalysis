#ifndef Validation_h
#define Validation_h

#include <iostream>

#include <TProfile.h>

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

  void init()
  {
    Pt     = -100;
    Eta    = -100;
    Phi    = -100;
    E      = -100;
    PdgId  = 0;
    Charge =-100;
  }

};

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
    
    Bool_t IsFinalBHadron(Int_t Index);
    
    void GetFinalDaughters(Size_t Indx, 
			   vector<Size_t> &vFinalDau);
    

    Int_t GetFinalGenpIndx (Size_t MotIndx, vector<unsigned short>& Daug);
    
    Bool_t IsLeptonic (Size_t Index);
    
    Double_t RIsoLepton (Double_t Lep_Pt, Double_t Lep_Eta, Double_t Lep_Phi);

    void myPrintGenp(Size_t Indx, bool bPrintHeaders);
    
    ParticleInfo SetParticleInfo (Double_t Pt, Double_t Eta, Double_t Phi, Double_t E, Int_t Id, Int_t Charge);

    void SortLepPt (vector<ParticleInfo> &vSort);

    Int_t DecayMode();

    //Histograms
    TH1D *hDecayMode;

    TH1D* hTestPV;

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

    TH1D *hdPhi_Elec_MET;
    TH1D *hElec_RIso;

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

    TH1D *hdPhi_Muon_MET;

    TH1D *hMuon_RIso;

    //Lep Combined
    TH1D *hLeadingLep;
    TH1D *hSubLeadingLep;
    TH1D *hSubSubLeadingLep;



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
  
    TH1D *hdPhi_Tau_MET;
  
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
    
    TProfile *hJet_ParFl_bDisJP;
    TProfile *hJet_HadFl_bDisJP;

    /* TH1D* hJet_ParFl_bDisJP_ProjX; */
    /* TH1D* hJet_HadFl_bDisJP_ProjX; */

    TH1D *hdPhi_Jet_MET;

    TProfile *hJet_ParFl_bDisCMVA;
    TProfile *hJet_HadFl_bDisCMVA;
  
    TH1D *hJet_Multiplicity;
    TH1D *hbJetParFl_Multiplicity;
    TH1D *hbJetL_Multiplicity;
    TH1D *hbJetM_Multiplicity;
    TH1D *hbJetT_Multiplicity;

    TH1D *hbJet_Pt;
    TH1D *hbJet_Eta;
    TH1D *hbJet_Phi;
    TH1D *hbJet_E;
    TH1D *hbJet_JetArea;
    
    TH1D *hbJet_ChMulti;
    TH1D *hbJet_ChHadMulti;
    TH1D *hbJet_NMulti;
    TH1D *hbJet_NHadMulti;

    TH1D *hbJet_ElecMulti;
    TH1D *hbJet_MuonMulti;
    TH1D *hbJet_PhotonMulti;

    TH1D *hdPhi_bJet_MET;

    //*****************************
    // Gen Level Histos
    
    TH1D* hGenPV_X;
    TH1D* hGenPV_Y;
    TH1D* hGenPV_Z;

    TH1D* hGenMET_Et;
    TH1D* hGenMET_Pt;
    TH1D* hGenNuMultiplicity;
    TH1D* hHT;
    TH1D* hMHT;



    TH1D* hGenElec_Pt;
    TH1D* hGenElec_Eta;
    TH1D* hGenElec_E;
    
    TH1D* hGenElec_RIso;
    
    TH1D* hGenElec_Lxy;
    TH1D* hGenElec_Lxyz;
    TH1D* hdPhi_GenElec_MET;

    
    TH1D* hGenMuon_Pt;
    TH1D* hGenMuon_Eta;
    TH1D* hGenMuon_E;
    
    TH1D* hGenMuon_RIso;
    
    TH1D* hGenMuon_Lxy;
    TH1D* hGenMuon_Lxyz;
    TH1D* hdPhi_GenMuon_MET;

    
    TH1D* hGenTau_Pt;
    TH1D* hGenTau_Eta;
    TH1D* hGenTau_E;
    TH1D* hGenTau_RIso;
    TH1D* hdPhi_GenTau_MET;

    
    TH1D* hbGenHad_Pt;
    TH1D* hbGenHad_Eta;
    TH1D* hbGenHad_E;
    TH1D* hdPhi_bGenHad_MET;
    TH1D* hbGenHad_ChMulti;
    TH1D* hbGenHad_NMulti;
    TH1D* hbGenHad_Multiplicity;

    TH1D* hDRBJ;
    
    TH1D* hGenJet_Pt;
    TH1D* hGenJet_Eta;
    TH1D* hGenJet_E;
    TH1D* hdPhi_GenJet_MET;
    TH1D* hGenJet_ChMulti;
    TH1D* hGenJet_NMulti;
    TH1D* hGenJet_Multiplicity;


};

#endif // Validation_h
