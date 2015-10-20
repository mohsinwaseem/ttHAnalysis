#ifndef ttHAnalysis_h
#define ttHAnalysis_h

#include <iostream>

#include "../utilities/TreeAnalyserMC.C"
#include "../utilities/AuxTools.C"
#include "../utilities/Table.C"
#include "../utilities/Datasets.C"

#include <TProfile.h>

struct Particle
{
  Int_t    Id;
  Int_t    Charge;
  Double_t Pt;
  Double_t Eta;
  Double_t Phi;
  Double_t M;
  Double_t E;
  
  void init()
  {
    Id     = -100;
    Charge = 0;
    Pt     = 0;
    Eta    = -100;
    Phi    = -100;
    M      = 0;
    E      = 0;
  }
  

};//End Struct.


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
    
    void myPrintGenp(Size_t Indx, bool bPrintHeaders);
    void MakeHistos(void);
    
    Particle SetParticleIdChargePtEtaPhiME(Int_t    Id,
					   Int_t    Charge,
					   Double_t Pt,
					   Double_t Eta,
					   Double_t Phi,
					   Double_t M,
					   Double_t E
					   );
    void SortParticleVectorPt(vector<Particle> &Vsort);
    
    Bool_t IsFinalGenp (Size_t MotIndx, vector<unsigned short>& Daug);
    
    Bool_t IsLeptonicDecay (Size_t Indx);
    
    Bool_t IsDecayToTau (Size_t Indx);
       
    Size_t IndexOfParticleDecaying (Size_t Indx);

    Int_t TTHDecayMode(void);

    //Histos
    TH1D* httHDecayMode;

    //PrimaryVertex
    TH1D* hPV_X;
    TH1D* hPV_Y;
    TH1D* hPV_Z;

    //Electrons
    TH1D* hElec_Pt;
    TH1D* hElec_Eta;
    TH1D* hElec_Phi;
    TH1D* hElec_M;  
    TH1D* hElec_E;  
    TH1D* hElec_SCl_Eta;     
    TH1D* hElec_SCl_EtaWidth;
    TH1D* hElec_SCl_Phi;     
    TH1D* hElec_SCl_PhiWidth;
    TH1D* hElec_SCl_PositionR;
    TH1D* hElec_SCl_E;        
    TH1D* hElec_GsfTrack_D0;
    TH1D* hElec_GsfTrack_Z0;


    //Muon
    TH1D* hMuon_Pt;
    TH1D* hMuon_Eta;
    TH1D* hMuon_Phi;
    TH1D* hMuon_M;  
    TH1D* hMuon_E;  
 
    TH1D* hMuon_GlobalTrack_D0;
    TH1D* hMuon_GlobalTrack_Z0;

    TH1D* hMuon_InnerTrack_D0;
    TH1D* hMuon_InnerTrack_Z0;
    
    TH1D* hMuon_BestTrack_D0;
    TH1D* hMuon_BestTrack_Z0;

    //Jet
    TH1D* hJet_Pt;
    TH1D* hJet_Eta;
    TH1D* hJet_Phi;
    TH1D* hJet_M;  
    TH1D* hJet_E;  
    TH1D* hJet_JetArea;  

    TH2D* hPartonFlavorVSJet_bDis_JBP;
    TH2D* hPartonFlavorVSJet_bDis_JP;
    TH2D* hPartonFlavorVSJet_bDis_TCHP;
    TH2D* hPartonFlavorVSJet_bDis_TCHE;
    TH2D* hPartonFlavorVSJet_bDis_SVHP;
    TH2D* hPartonFlavorVSJet_bDis_SVHE;
    TH2D* hPartonFlavorVSJet_bDis_CMVA;
    
    
    TH2D* hHadronFlavorVSJet_bDis_JBP;
    TH2D* hHadronFlavorVSJet_bDis_JP;
    TH2D* hHadronFlavorVSJet_bDis_TCHP;
    TH2D* hHadronFlavorVSJet_bDis_TCHE;
    TH2D* hHadronFlavorVSJet_bDis_SVHP;
    TH2D* hHadronFlavorVSJet_bDis_SVHE;
    TH2D* hHadronFlavorVSJet_bDis_CMVA;

    TProfile* hPPartonFlavorVSJet_bDis_JBP;
    TProfile* hPPartonFlavorVSJet_bDis_JP;
    TProfile* hPPartonFlavorVSJet_bDis_TCHP;
    TProfile* hPPartonFlavorVSJet_bDis_TCHE;
    TProfile* hPPartonFlavorVSJet_bDis_SVHP;
    TProfile* hPPartonFlavorVSJet_bDis_SVHE;
    TProfile* hPPartonFlavorVSJet_bDis_CMVA;
    
    
    TProfile* hPHadronFlavorVSJet_bDis_JBP;
    TProfile* hPHadronFlavorVSJet_bDis_JP;
    TProfile* hPHadronFlavorVSJet_bDis_TCHP;
    TProfile* hPHadronFlavorVSJet_bDis_TCHE;
    TProfile* hPHadronFlavorVSJet_bDis_SVHP;
    TProfile* hPHadronFlavorVSJet_bDis_SVHE;
    TProfile* hPHadronFlavorVSJet_bDis_CMVA;
    
    //Leptons
    TH1D* hLeadingLepPt;
    TH1D* hSubLeadingLepPt;
    TH1D* hSubSubLeadingLepPt;
    TH1D* hSubSubSubLeadingLepPt;
    
    
    //BJets
    TH1D* hLBJetPt;
    TH1D* hLBJetEta;
    TH1D* hLBJetM;
    TH1D* hLBJetE;
    TH1D* hLBJetCMulti;
    TH1D* hLBJetCHMulti;
    TH1D* hLBJetNMulti;
    TH1D* hLBJetNHMulti;

    TH1D* hMBJetPt;
    TH1D* hMBJetEta;
    TH1D* hMBJetM;
    TH1D* hMBJetE;
    TH1D* hMBJetCMulti;
    TH1D* hMBJetCHMulti;
    TH1D* hMBJetNMulti;
    TH1D* hMBJetNHMulti;

    TH1D* hTBJetPt;
    TH1D* hTBJetEta;
    TH1D* hTBJetM;
    TH1D* hTBJetE;
    TH1D* hTBJetCMulti;
    TH1D* hTBJetCHMulti;
    TH1D* hTBJetNMulti;
    TH1D* hTBJetNHMulti;

    TH1D* hJetMulti; 
    TH1D* hLBJetMulti;
    TH1D* hMBJetMulti;
    TH1D* hTBJetMulti;


    //MET
    TH1D* hMETPt;   
    TH1D* hMETPhi;  
    TH1D* hMETSumEt;


};

#endif // ttHAnalysis_h
