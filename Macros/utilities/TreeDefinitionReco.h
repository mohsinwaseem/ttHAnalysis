//This is to check backup working.

#ifndef TreeDefinitionReco_h
#define TreeDefinitionReco_h

#include "TreeDefinitionBase.h"

class TreeDefinitionReco : public virtual TreeDefinitionBase
{
  public:
    //Declaration of leaf types

  //Event tree

  //MET
  float MET_Px;
  float MET_Py;
  float MET_Pt;
  float MET_Phi;
  float MET_SumEt;
  
  float MET_UncorrectedPt;
  float MET_UncorrectedPhi;
  float MET_UncorrectedSumEt;
  
  float MET_CaloMETPt;
  float MET_CaloMETPhi;
  float MET_CaloMETSumEt;

  //Electrons
  Int_t* Elec_N;
  std::vector<float> *Elec_Pt;
  std::vector<float> *Elec_Eta;
  std::vector<float> *Elec_Phi;
  std::vector<float> *Elec_M;
  std::vector<float> *Elec_E;
  std::vector<Int_t> *Elec_Id;
  std::vector<Int_t> *Elec_Charge;

  std::vector<bool>  *Elec_IsPF;
  std::vector<float> *Elec_EcalIso;
  std::vector<float> *Elec_HcalIso;
  std::vector<float> *Elec_CaloIso;
  std::vector<float> *Elec_HadOverEm;
  std::vector<float> *Elec_HadOverEm1;
  std::vector<float> *Elec_HadOverEm2;

  std::vector<float> *Elec_NeutralHadIso;
  std::vector<float> *Elec_ChargedHadIso;
  std::vector<float> *Elec_PUChargedHadIso;
  std::vector<float> *Elec_ParticleIso;
  std::vector<float> *Elec_PhotonIso;
  std::vector<float> *Elec_TrackIso;

  std::vector<float> *Elec_E1X5;
  std::vector<float> *Elec_E2X5max;
  std::vector<float> *Elec_E5X5;

  std::vector<float> *Elec_EcalEnergy;
  std::vector<float> *Elec_CorrectedEcalEnergy;
  std::vector<float> *Elec_CorrectedEcalEnergyError;
  std::vector<float> *Elec_TrackMomentumError;
  
  std::vector<float> *Elec_Vx;
  std::vector<float> *Elec_Vy;
  std::vector<float> *Elec_Vz;
  
  std::vector<float> *Elec_SigmaEtaEta;
  std::vector<float> *Elec_SigmaIetaIeta;
  std::vector<float> *Elec_SigmaIphiIphi;
  std::vector<float> *Elec_SigmaIetaIphi;
  std::vector<float> *Elec_Full5x5_SigmaIphiIphi;
  std::vector<float> *Elec_Full5x5_SigmaEtaEta;
  std::vector<float> *Elec_Full5x5_SigmaIetaIeta;
  std::vector<float> *Elec_Full5x5_SigmaIetaIphi;
  std::vector<float> *Elec_Full5x5_R9;
  std::vector<float> *Elec_Full5x5_E1x5;
  std::vector<float> *Elec_Full5x5_E5x5;
  std::vector<float> *Elec_Full5x5_E2x5Max;

  std::vector<float> *Elec_Dr03ECALSumEt;
  std::vector<float> *Elec_Dr03HCALSumEt;
  std::vector<float> *Elec_Dr03HCAL1SumEt;
  std::vector<float> *Elec_Dr03HCAL2SumEt;
  std::vector<float> *Elec_Dr03TkSumPt;


  std::vector<float> *Elec_Dr04ECALSumEt;
  std::vector<float> *Elec_Dr04HCALSumEt;
  std::vector<float> *Elec_Dr04HCAL1SumEt;
  std::vector<float> *Elec_Dr04HCAL2SumEt;
  std::vector<float> *Elec_Dr04TkSumPt;


  std::vector<float> *Elec_SCl_Eta;
  std::vector<float> *Elec_SCl_EtaWidth;
  std::vector<float> *Elec_SCl_Phi;
  std::vector<float> *Elec_SCl_PhiWidth;
  std::vector<float> *Elec_SCl_E;
  std::vector<float> *Elec_SCl_RawE;
  std::vector<float> *Elec_SCl_PreShowerE;
  std::vector<float> *Elec_SCl_PreShower1E;
  std::vector<float> *Elec_SCl_PreShower2E;
  std::vector<float> *Elec_SCl_PositionR;
  
  std::vector<Bool_t>*Elec_HasGsfTrack;
  std::vector<float> *Elec_GsfTrack_D0;
  std::vector<float> *Elec_GsfTrack_Z0;
  std::vector<float> *Elec_GsfTrack_D0Error;
  std::vector<float> *Elec_GsfTrack_Z0Error;
  std::vector<float> *Elec_GsfTrack_PV_Dxy;
  std::vector<float> *Elec_GsfTrack_PV_Z0;
  std::vector<float> *Elec_GsfTrack_RP_Dxy;
  std::vector<float> *Elec_GsfTrack_RP_Z0;
  std::vector<float> *Elec_GsfTrack_BS_Dxy;
  std::vector<float> *Elec_GsfTrack_BS_Z0;
  std::vector<float> *Elec_GsfTrack_DxyError;
  //std::vector<Double_t> *Elec_GsfTrack_Z0Error;
  std::vector<float> *Elec_GsfTrack_NormalizedChi2;
  std::vector<float> *Elec_IP3d;
  std::vector<float> *Elec_IP3dError;
  std::vector<float> *Elec_IP2d;
  std::vector<float> *Elec_IP2dError;
  std::vector<float> *Elec_IP3dBS;
  std::vector<float> *Elec_IP3dBSError;
  std::vector<float> *Elec_IP2dBS;
  std::vector<float> *Elec_IP2dBSError;



  //Muons
  std::vector<float> *Muon_Pt;
  std::vector<float> *Muon_Eta;
  std::vector<float> *Muon_Phi;
  std::vector<float> *Muon_M;
  std::vector<float> *Muon_E;
  std::vector<Int_t> *Muon_Id;
  std::vector<Int_t> *Muon_Charge;

  std::vector<bool> *Muon_IsPF;
  std::vector<bool> *Muon_IsGlobalMuon;
  std::vector<bool> *Muon_IsTrackerMuon;
  std::vector<bool> *Muon_IsStandAloneMuon;
  std::vector<bool> *Muon_IsCaloMuon;
  std::vector<bool> *Muon_IsRPCMuon;

  std::vector<float> *Muon_EcalIso;
  std::vector<float> *Muon_HcalIso;
  std::vector<float> *Muon_CaloIso;

  std::vector<float> *Muon_Vx;
  std::vector<float> *Muon_Vy;
  std::vector<float> *Muon_Vz;
  
  std::vector<float> *Muon_NeutralHadronIso;
  std::vector<float> *Muon_ChargedHadronIso;
  std::vector<float> *Muon_PUChargedHadronIso;
  std::vector<float> *Muon_PhotonIso;
  std::vector<float> *Muon_TrackIso;
  
  std::vector<float> *Muon_PFIso03_SumChargedHadronPt;
  std::vector<float> *Muon_PFIso03_SumChargedParticlePt;
  std::vector<float> *Muon_PFIso03_SumNeutralHadronEt;
  std::vector<float> *Muon_PFIso03_SumNeutralHadronEtHighThreshold;
  std::vector<float> *Muon_PFIso03_SumPhotonEt;
  std::vector<float> *Muon_PFIso03_SumPhotonEtHighThreshold;
  std::vector<float> *Muon_PFIso03_SumPUPt;
  
  std::vector<float> *Muon_PFIso04_SumChargedHadronPt;
  std::vector<float> *Muon_PFIso04_SumChargedParticlePt;
  std::vector<float> *Muon_PFIso04_SumNeutralHadronEt;
  std::vector<float> *Muon_PFIso04_SumNeutralHadronEtHighThreshold;
  std::vector<float> *Muon_PFIso04_SumPhotonEt;
  std::vector<float> *Muon_PFIso04_SumPhotonEtHighThreshold;
  std::vector<float> *Muon_PFIso04_SumPUPt;


  std::vector<float> *Muon_IP3d;
  std::vector<float> *Muon_IP3dError;
  std::vector<float> *Muon_IP2d;
  std::vector<float> *Muon_IP2dError;
  std::vector<float> *Muon_IP3dBS;
  std::vector<float> *Muon_IP3dBSError;
  std::vector<float> *Muon_IP2dBS;
  std::vector<float> *Muon_IP2dBSError;

  std::vector<Bool_t> *Muon_HasGlobalTrack;
  std::vector<float> *Muon_GlobalTrack_D0;
  std::vector<float> *Muon_GlobalTrack_Z0;
  std::vector<float> *Muon_GlobalTrack_D0Error;
  std::vector<float> *Muon_GlobalTrack_Z0Error;
  std::vector<float> *Muon_GlobalTrack_PV_Dxy;
  std::vector<float> *Muon_GlobalTrack_PV_Z0;
  std::vector<float> *Muon_GlobalTrack_RP_Dxy;
  std::vector<float> *Muon_GlobalTrack_RP_Z0;
  std::vector<float> *Muon_GlobalTrack_BS_Dxy;
  std::vector<float> *Muon_GlobalTrack_BS_Z0;
  std::vector<float> *Muon_GlobalTrack_DxyError;
  //std::vector<Double_t> *Muon_GlobalTrack_Z0Error;
  std::vector<float> *Muon_GlobalTrack_NormalizedChi2;
  std::vector<float> *Muon_GlobalTrack_Pt;
  std::vector<float> *Muon_GlobalTrack_Eta;
  std::vector<float> *Muon_GlobalTrack_Phi;
  std::vector<float> *Muon_GlobalTrack_PtError;
  std::vector<float> *Muon_GlobalTrack_EtaError;
  std::vector<float> *Muon_GlobalTrack_PhiError;
  std::vector<float> *Muon_GlobalTrack_Charge;

  std::vector<Bool_t> *Muon_HasInnerTrack;
  std::vector<float> *Muon_InnerTrack_D0;
  std::vector<float> *Muon_InnerTrack_Z0;
  std::vector<float> *Muon_InnerTrack_D0Error;
  std::vector<float> *Muon_InnerTrack_Z0Error;
  std::vector<float> *Muon_InnerTrack_PV_Dxy;
  std::vector<float> *Muon_InnerTrack_PV_Z0;
  std::vector<float> *Muon_InnerTrack_RP_Dxy;
  std::vector<float> *Muon_InnerTrack_RP_Z0;
  std::vector<float> *Muon_InnerTrack_BS_Dxy;
  std::vector<float> *Muon_InnerTrack_BS_Z0;
  std::vector<float> *Muon_InnerTrack_DxyError;
  //std::vector<Double_t> *Muon_InnerTrack_Z0Error;
  std::vector<float> *Muon_InnerTrack_NormalizedChi2;
  std::vector<float> *Muon_InnerTrack_Pt;
  std::vector<float> *Muon_InnerTrack_Eta;
  std::vector<float> *Muon_InnerTrack_Phi;
  std::vector<float> *Muon_InnerTrack_PtError;
  std::vector<float> *Muon_InnerTrack_EtaError;
  std::vector<float> *Muon_InnerTrack_PhiError;
  std::vector<float> *Muon_InnerTrack_Charge;

  std::vector<Bool_t> *  Muon_HasBestTrack;
  std::vector<float> *Muon_BestTrackType;
  std::vector<float> *Muon_BestTrack_D0;
  std::vector<float> *Muon_BestTrack_Z0;
  std::vector<float> *Muon_BestTrack_D0Error;
  std::vector<float> *Muon_BestTrack_Z0Error;
  std::vector<float> *Muon_BestTrack_PV_Dxy;
  std::vector<float> *Muon_BestTrack_PV_Z0;
  std::vector<float> *Muon_BestTrack_RP_Dxy;
  std::vector<float> *Muon_BestTrack_RP_Z0;
  std::vector<float> *Muon_BestTrack_BS_Dxy;
  std::vector<float> *Muon_BestTrack_BS_Z0;
  std::vector<float> *Muon_BestTrack_DxyError;
  //std::vector<Double_t> *Muon_BestTrack_Z0Error;
  std::vector<float> *Muon_BestTrack_NormalizedChi2;
  std::vector<float> *Muon_BestTrack_Pt;
  std::vector<float> *Muon_BestTrack_Eta;
  std::vector<float> *Muon_BestTrack_Phi;
  std::vector<float> *Muon_BestTrack_PtError;
  std::vector<float> *Muon_BestTrack_EtaError;
  std::vector<float> *Muon_BestTrack_PhiError;
  std::vector<float> *Muon_BestTrack_Charge;

  
  //Taus
  std::vector<float> *Tau_Pt;
  std::vector<float> *Tau_Eta;
  std::vector<float> *Tau_Phi;
  std::vector<float> *Tau_M;
  std::vector<float> *Tau_E;
  std::vector<Int_t> *Tau_Id;
  std::vector<Int_t> *Tau_Charge;

  std::vector<Int_t> *Tau_DecayMode;
  std::vector<bool>  *Tau_IsCaloTau;

  std::vector<bool>  *Tau_hasLeadChargedHadrCand;
  std::vector<float> *Tau_LeadingCHCPt;
  std::vector<float> *Tau_LeadingCHCEta;
  std::vector<float> *Tau_LeadingCHCPhi;
  std::vector<float> *Tau_LeadingCHCM;
  std::vector<float> *Tau_LeadingCHCE;
  std::vector<float> *Tau_LeadingCHCEt;
  std::vector<Int_t> *Tau_LeadingCHCId;
  std::vector<Int_t> *Tau_LeadingCHCCharge;

  std::vector<float> *Tau_LeadingCHCVx;
  std::vector<float> *Tau_LeadingCHCVy;
  std::vector<float> *Tau_LeadingCHCVz;

  //Jets
  std::vector<float> *Jet_Pt;
  std::vector<float> *Jet_Eta;
  std::vector<float> *Jet_Phi;
  std::vector<float> *Jet_M;
  std::vector<float> *Jet_E;
  std::vector<float> *Jet_JetArea;

  std::vector<Int_t> *Jet_ChargedMultiplicity;
  std::vector<Int_t> *Jet_ChargedHadronMultiplicity;
  std::vector<Int_t> *Jet_NeutralMultiplicity;
  std::vector<Int_t> *Jet_NeutralHadronMultiplicity;
  std::vector<Int_t> *Jet_ElectronMultiplicity;
  std::vector<Int_t> *Jet_MuonMultiplicity;
  std::vector<Int_t> *Jet_PhotonMultiplicity;

  std::vector<float> *Jet_NeutralEmEnergy;
  std::vector<float> *Jet_NeutralEmEnergyFraction;
  std::vector<float> *Jet_NeutralHadEnergy;
  std::vector<float> *Jet_NeutralHadEnergyFraction;
  
  std::vector<float> *Jet_ChargedEmEnergy;
  std::vector<float> *Jet_ChargedEmEnergyFraction;
  std::vector<float> *Jet_ChargedHadEnergy;
  std::vector<float> *Jet_ChargedHadEnergyFraction;
  std::vector<float> *Jet_ChargedMuEnergy;
  std::vector<float> *Jet_ChargedMuEnergyFraction;
  
  std::vector<float> *Jet_ElectronEnergy;
  std::vector<float> *Jet_ElectronEnergyFraction;
  std::vector<float> *Jet_MuonEnergy;
  std::vector<float> *Jet_MuonEnergyFraction;
  std::vector<float> *Jet_PhotonEnergy;
  std::vector<float> *Jet_PhotonEnergyFraction;
  
  std::vector<float> *Jet_bDis_JBP;
  std::vector<float> *Jet_bDis_JP;
  std::vector<float> *Jet_bDis_TCHP;
  std::vector<float> *Jet_bDis_TCHE;
  std::vector<float> *Jet_bDis_SVHP;
  std::vector<float> *Jet_bDis_SVHE;
  std::vector<float> *Jet_bDis_CMVA;

  std::vector<float> *Jet_bDis_CSV;
  std::vector<float> *Jet_bDis_CSV2;
  std::vector<float> *Jet_bDis_CISV2;
  std::vector<float> *Jet_bDis_CSVSL;


  std::vector<Bool_t> *Jet_HasGenJet;
  std::vector<float> *Jet_GenJet_Pt;
  std::vector<float> *Jet_GenJet_Eta;
  std::vector<float> *Jet_GenJet_Phi;
  std::vector<float> *Jet_GenJet_M;
  std::vector<float> *Jet_GenJet_E;
  std::vector<float> *Jet_GenJet_emE;
  std::vector<float> *Jet_GenJet_hadE;
  std::vector<float> *Jet_GenJet_invisibleE;

  std::vector<Int_t> *Jet_GenPartonFlavour;
  std::vector<Int_t> *Jet_GenHadronFlavour;

  //Vertex and Primary Vertex
  /* float PV_X; */
  /* float PV_Y; */
  /* float PV_Z; */
  std::vector<float> *PV_X;
  std::vector<float> *PV_Y;
  std::vector<float> *PV_Z;
  std::vector<float> *Vertex_X;
  std::vector<float> *Vertex_ErrorX;
  std::vector<float> *Vertex_Y;
  std::vector<float> *Vertex_ErrorY;
  std::vector<float> *Vertex_Z;
  std::vector<float> *Vertex_ErrorZ;
  std::vector<float> *Vertex_Chi2;
  std::vector<float> *Vertex_DOF;
  std::vector<float> *Vertex_ReducedChi2;


  //PileUp
  std::vector<int>                  *PU_Bx;
  std::vector<float>                *PU_EventPU;
  std::vector<int>                  *PU_BxPU;
  std::vector< std::vector<float> > *PU_ZPositions;
   

   // List of branches

  //MET
  TBranch *b_MET_Px;
  TBranch *b_MET_Py;
  TBranch *b_MET_Pt;
  TBranch *b_MET_Phi;
  TBranch *b_MET_SumEt;
  
  TBranch *b_MET_UncorrectedPt;
  TBranch *b_MET_UncorrectedPhi;
  TBranch *b_MET_UncorrectedSumEt;
  
  TBranch *b_MET_CaloMETPt;
  TBranch *b_MET_CaloMETPhi;
  TBranch *b_MET_CaloMETSumEt;

  //Electrons
  TBranch *b_Elec_N;
  TBranch  *b_Elec_Pt;
  TBranch  *b_Elec_Eta;
  TBranch  *b_Elec_Phi;
  TBranch  *b_Elec_M;
  TBranch  *b_Elec_E;
  TBranch  *b_Elec_Id;
  TBranch  *b_Elec_Charge;

  TBranch  *b_Elec_IsPF;
  TBranch  *b_Elec_EcalIso;
  TBranch  *b_Elec_HcalIso;
  TBranch  *b_Elec_CaloIso;
  TBranch  *b_Elec_HadOverEm;
  TBranch  *b_Elec_HadOverEm1;
  TBranch  *b_Elec_HadOverEm2;

  TBranch  *b_Elec_NeutralHadIso;
  TBranch  *b_Elec_ChargedHadIso;
  TBranch  *b_Elec_PUChargedHadIso;
  TBranch  *b_Elec_ParticleIso;
  TBranch  *b_Elec_PhotonIso;
  TBranch  *b_Elec_TrackIso;

  TBranch  *b_Elec_E1X5;
  TBranch  *b_Elec_E2X5max;
  TBranch  *b_Elec_E5X5;

  TBranch  *b_Elec_EcalEnergy;
  TBranch  *b_Elec_CorrectedEcalEnergy;
  TBranch  *b_Elec_CorrectedEcalEnergyError;
  TBranch  *b_Elec_TrackMomentumError;
  
  TBranch  *b_Elec_Vx;
  TBranch  *b_Elec_Vy;
  TBranch  *b_Elec_Vz;
  
  TBranch  *b_Elec_SigmaEtaEta;
  TBranch  *b_Elec_SigmaIetaIeta;
  TBranch  *b_Elec_SigmaIphiIphi;
  TBranch  *b_Elec_SigmaIetaIphi;
  TBranch  *b_Elec_Full5x5_SigmaIphiIphi;
  TBranch  *b_Elec_Full5x5_SigmaEtaEta;
  TBranch  *b_Elec_Full5x5_SigmaIetaIeta;
  TBranch  *b_Elec_Full5x5_SigmaIetaIphi;
  TBranch  *b_Elec_Full5x5_R9;
  TBranch  *b_Elec_Full5x5_E1x5;
  TBranch  *b_Elec_Full5x5_E5x5;
  TBranch  *b_Elec_Full5x5_E2x5Max;

  TBranch  *b_Elec_Dr03ECALSumEt;
  TBranch  *b_Elec_Dr03HCALSumEt;
  TBranch  *b_Elec_Dr03HCAL1SumEt;
  TBranch  *b_Elec_Dr03HCAL2SumEt;
  TBranch  *b_Elec_Dr03TkSumPt;

  TBranch  *b_Elec_Dr04ECALSumEt;
  TBranch  *b_Elec_Dr04HCALSumEt;
  TBranch  *b_Elec_Dr04HCAL1SumEt;
  TBranch  *b_Elec_Dr04HCAL2SumEt;
  TBranch  *b_Elec_Dr04TkSumPt;

  TBranch  *b_Elec_SCl_Eta;
  TBranch  *b_Elec_SCl_EtaWidth;
  TBranch  *b_Elec_SCl_Phi;
  TBranch  *b_Elec_SCl_PhiWidth;
  TBranch  *b_Elec_SCl_E;
  TBranch  *b_Elec_SCl_RawE;
  TBranch  *b_Elec_SCl_PreShowerE;
  TBranch  *b_Elec_SCl_PreShower1E;
  TBranch  *b_Elec_SCl_PreShower2E;
  TBranch  *b_Elec_SCl_PositionR;
  
  TBranch  *b_Elec_HasGsfTrack;
  TBranch  *b_Elec_GsfTrack_D0;
  TBranch  *b_Elec_GsfTrack_Z0;
  TBranch  *b_Elec_GsfTrack_D0Error;
  TBranch  *b_Elec_GsfTrack_Z0Error;
  TBranch  *b_Elec_GsfTrack_PV_Dxy;
  TBranch  *b_Elec_GsfTrack_PV_Z0;
  TBranch  *b_Elec_GsfTrack_RP_Dxy;
  TBranch  *b_Elec_GsfTrack_RP_Z0;
  TBranch  *b_Elec_GsfTrack_BS_Dxy;
  TBranch  *b_Elec_GsfTrack_BS_Z0;
  TBranch  *b_Elec_GsfTrack_DxyError;
  //std::vector<Double_t> *Elec_GsfTrack_Z0Error;
  TBranch  *b_Elec_GsfTrack_NormalizedChi2;
  TBranch  *b_Elec_IP3d;
  TBranch  *b_Elec_IP3dError;
  TBranch  *b_Elec_IP2d;
  TBranch  *b_Elec_IP2dError;
  TBranch  *b_Elec_IP3dBS;
  TBranch  *b_Elec_IP3dBSError;
  TBranch  *b_Elec_IP2dBS;
  TBranch  *b_Elec_IP2dBSError;



  //Muons
  TBranch  *b_Muon_Pt;
  TBranch  *b_Muon_Eta;
  TBranch  *b_Muon_Phi;
  TBranch  *b_Muon_M;
  TBranch  *b_Muon_E;
  TBranch  *b_Muon_Id;
  TBranch  *b_Muon_Charge;


  TBranch  *b_Muon_IsPF;
  TBranch  *b_Muon_IsGlobalMuon;
  TBranch  *b_Muon_IsTrackerMuon;
  TBranch  *b_Muon_IsStandAloneMuon;
  TBranch  *b_Muon_IsCaloMuon;
  TBranch  *b_Muon_IsRPCMuon;

  TBranch  *b_Muon_EcalIso;
  TBranch  *b_Muon_HcalIso;
  TBranch  *b_Muon_CaloIso;

  TBranch  *b_Muon_Vx;
  TBranch  *b_Muon_Vy;
  TBranch  *b_Muon_Vz;
  
  TBranch  *b_Muon_NeutralHadronIso;
  TBranch  *b_Muon_ChargedHadronIso;
  TBranch  *b_Muon_PUChargedHadronIso;
  TBranch  *b_Muon_PhotonIso;
  TBranch  *b_Muon_TrackIso;
  
  TBranch  *b_Muon_PFIso03_SumChargedHadronPt;
  TBranch  *b_Muon_PFIso03_SumChargedParticlePt;
  TBranch  *b_Muon_PFIso03_SumNeutralHadronEt;
  TBranch  *b_Muon_PFIso03_SumNeutralHadronEtHighThreshold;
  TBranch  *b_Muon_PFIso03_SumPhotonEt;
  TBranch  *b_Muon_PFIso03_SumPhotonEtHighThreshold;
  TBranch  *b_Muon_PFIso03_SumPUPt;
  
  TBranch  *b_Muon_PFIso04_SumChargedHadronPt;
  TBranch  *b_Muon_PFIso04_SumChargedParticlePt;
  TBranch  *b_Muon_PFIso04_SumNeutralHadronEt;
  TBranch  *b_Muon_PFIso04_SumNeutralHadronEtHighThreshold;
  TBranch  *b_Muon_PFIso04_SumPhotonEt;
  TBranch  *b_Muon_PFIso04_SumPhotonEtHighThreshold;
  TBranch  *b_Muon_PFIso04_SumPUPt;


  TBranch  *b_Muon_IP3d;
  TBranch  *b_Muon_IP3dError;
  TBranch  *b_Muon_IP2d;
  TBranch  *b_Muon_IP2dError;
  TBranch  *b_Muon_IP3dBS;
  TBranch  *b_Muon_IP3dBSError;
  TBranch  *b_Muon_IP2dBS;
  TBranch  *b_Muon_IP2dBSError;

  TBranch  *b_Muon_HasGlobalTrack;
  TBranch  *b_Muon_GlobalTrack_D0;
  TBranch  *b_Muon_GlobalTrack_Z0;
  TBranch  *b_Muon_GlobalTrack_D0Error;
  TBranch  *b_Muon_GlobalTrack_Z0Error;
  TBranch  *b_Muon_GlobalTrack_PV_Dxy;
  TBranch  *b_Muon_GlobalTrack_PV_Z0;
  TBranch  *b_Muon_GlobalTrack_RP_Dxy;
  TBranch  *b_Muon_GlobalTrack_RP_Z0;
  TBranch  *b_Muon_GlobalTrack_BS_Dxy;
  TBranch  *b_Muon_GlobalTrack_BS_Z0;
  TBranch  *b_Muon_GlobalTrack_DxyError;
  //std::vector<Double_t> *Muon_GlobalTrack_Z0Error;
  TBranch  *b_Muon_GlobalTrack_NormalizedChi2;
  TBranch  *b_Muon_GlobalTrack_Pt;
  TBranch  *b_Muon_GlobalTrack_Eta;
  TBranch  *b_Muon_GlobalTrack_Phi;
  TBranch  *b_Muon_GlobalTrack_PtError;
  TBranch  *b_Muon_GlobalTrack_EtaError;
  TBranch  *b_Muon_GlobalTrack_PhiError;
  TBranch  *b_Muon_GlobalTrack_Charge;

  TBranch  *b_Muon_HasInnerTrack;
  TBranch  *b_Muon_InnerTrack_D0;
  TBranch  *b_Muon_InnerTrack_Z0;
  TBranch  *b_Muon_InnerTrack_D0Error;
  TBranch  *b_Muon_InnerTrack_Z0Error;
  TBranch  *b_Muon_InnerTrack_PV_Dxy;
  TBranch  *b_Muon_InnerTrack_PV_Z0;
  TBranch  *b_Muon_InnerTrack_RP_Dxy;
  TBranch  *b_Muon_InnerTrack_RP_Z0;
  TBranch  *b_Muon_InnerTrack_BS_Dxy;
  TBranch  *b_Muon_InnerTrack_BS_Z0;
  TBranch  *b_Muon_InnerTrack_DxyError;
  //std::vector<Double_t> *Muon_InnerTrack_Z0Error;
  TBranch  *b_Muon_InnerTrack_NormalizedChi2;
  TBranch  *b_Muon_InnerTrack_Pt;
  TBranch  *b_Muon_InnerTrack_Eta;
  TBranch  *b_Muon_InnerTrack_Phi;
  TBranch  *b_Muon_InnerTrack_PtError;
  TBranch  *b_Muon_InnerTrack_EtaError;
  TBranch  *b_Muon_InnerTrack_PhiError;
  TBranch  *b_Muon_InnerTrack_Charge;

  TBranch  *b_Muon_HasBestTrack;
  TBranch  *b_Muon_BestTrackType;
  TBranch  *b_Muon_BestTrack_D0;
  TBranch  *b_Muon_BestTrack_Z0;
  TBranch  *b_Muon_BestTrack_D0Error;
  TBranch  *b_Muon_BestTrack_Z0Error;
  TBranch  *b_Muon_BestTrack_PV_Dxy;
  TBranch  *b_Muon_BestTrack_PV_Z0;
  TBranch  *b_Muon_BestTrack_RP_Dxy;
  TBranch  *b_Muon_BestTrack_RP_Z0;
  TBranch  *b_Muon_BestTrack_BS_Dxy;
  TBranch  *b_Muon_BestTrack_BS_Z0;
  TBranch  *b_Muon_BestTrack_DxyError;
  //std::vector<Double_t> *Muon_BestTrack_Z0Error;
  TBranch  *b_Muon_BestTrack_NormalizedChi2;
  TBranch  *b_Muon_BestTrack_Pt;
  TBranch  *b_Muon_BestTrack_Eta;
  TBranch  *b_Muon_BestTrack_Phi;
  TBranch  *b_Muon_BestTrack_PtError;
  TBranch  *b_Muon_BestTrack_EtaError;
  TBranch  *b_Muon_BestTrack_PhiError;
  TBranch  *b_Muon_BestTrack_Charge;

  
  //Taus
  TBranch  *b_Tau_Pt;
  TBranch  *b_Tau_Eta;
  TBranch  *b_Tau_Phi;
  TBranch  *b_Tau_M;
  TBranch  *b_Tau_E;
  TBranch  *b_Tau_Id;
  TBranch  *b_Tau_Charge;

  TBranch  *b_Tau_DecayMode;
  TBranch  *b_Tau_IsCaloTau;

  TBranch  *b_Tau_hasLeadChargedHadrCand;
  TBranch  *b_Tau_LeadingCHCPt;
  TBranch  *b_Tau_LeadingCHCEta;
  TBranch  *b_Tau_LeadingCHCPhi;
  TBranch  *b_Tau_LeadingCHCM;
  TBranch  *b_Tau_LeadingCHCE;
  TBranch  *b_Tau_LeadingCHCEt;
  TBranch  *b_Tau_LeadingCHCId;
  TBranch  *b_Tau_LeadingCHCCharge;

  TBranch  *b_Tau_LeadingCHCVx;
  TBranch  *b_Tau_LeadingCHCVy;
  TBranch  *b_Tau_LeadingCHCVz;

  //Jets
  TBranch  *b_Jet_Pt;
  TBranch  *b_Jet_Eta;
  TBranch  *b_Jet_Phi;
  TBranch  *b_Jet_M;
  TBranch  *b_Jet_E;
  TBranch  *b_Jet_JetArea;

  TBranch  *b_Jet_ChargedMultiplicity;
  TBranch  *b_Jet_ChargedHadronMultiplicity;
  TBranch  *b_Jet_NeutralMultiplicity;
  TBranch  *b_Jet_NeutralHadronMultiplicity;
  TBranch  *b_Jet_ElectronMultiplicity;
  TBranch  *b_Jet_MuonMultiplicity;
  TBranch  *b_Jet_PhotonMultiplicity;

  TBranch  *b_Jet_NeutralEmEnergy;
  TBranch  *b_Jet_NeutralEmEnergyFraction;
  TBranch  *b_Jet_NeutralHadEnergy;
  TBranch  *b_Jet_NeutralHadEnergyFraction;
  
  TBranch  *b_Jet_ChargedEmEnergy;
  TBranch  *b_Jet_ChargedEmEnergyFraction;
  TBranch  *b_Jet_ChargedHadEnergy;
  TBranch  *b_Jet_ChargedHadEnergyFraction;
  TBranch  *b_Jet_ChargedMuEnergy;
  TBranch  *b_Jet_ChargedMuEnergyFraction;
  
  TBranch  *b_Jet_ElectronEnergy;
  TBranch  *b_Jet_ElectronEnergyFraction;
  TBranch  *b_Jet_MuonEnergy;
  TBranch  *b_Jet_MuonEnergyFraction;
  TBranch  *b_Jet_PhotonEnergy;
  TBranch  *b_Jet_PhotonEnergyFraction;
  
  TBranch  *b_Jet_bDis_JBP;
  TBranch  *b_Jet_bDis_JP;
  TBranch  *b_Jet_bDis_TCHP;
  TBranch  *b_Jet_bDis_TCHE;
  TBranch  *b_Jet_bDis_SVHP;
  TBranch  *b_Jet_bDis_SVHE;
  TBranch  *b_Jet_bDis_CMVA;
  
  TBranch  *b_Jet_bDis_CSV;
  TBranch  *b_Jet_bDis_CSV2;
  TBranch  *b_Jet_bDis_CISV2;
  TBranch  *b_Jet_bDis_CSVSL;


  TBranch  *b_Jet_HasGenJet;
  TBranch  *b_Jet_GenJet_Pt;
  TBranch  *b_Jet_GenJet_Eta;
  TBranch  *b_Jet_GenJet_Phi;
  TBranch  *b_Jet_GenJet_M;
  TBranch  *b_Jet_GenJet_E;
  TBranch  *b_Jet_GenJet_emE;
  TBranch  *b_Jet_GenJet_hadE;
  TBranch  *b_Jet_GenJet_invisibleE;
  TBranch  *b_Jet_GenPartonFlavour;
  TBranch  *b_Jet_GenHadronFlavour;

  //Vertex and Primary Vertex
  TBranch  *b_PV_X;
  TBranch  *b_PV_Y;
  TBranch  *b_PV_Z;
  TBranch  *b_Vertex_X;
  TBranch  *b_Vertex_ErrorX;
  TBranch  *b_Vertex_Y;
  TBranch  *b_Vertex_ErrorY;
  TBranch  *b_Vertex_Z;
  TBranch  *b_Vertex_ErrorZ;
  TBranch  *b_Vertex_Chi2;
  TBranch  *b_Vertex_DOF;
  TBranch  *b_Vertex_ReducedChi2;


  //PileUp
  TBranch  *b_PU_Bx;
  TBranch  *b_PU_EventPU;
  TBranch  *b_PU_BxPU;
  TBranch  *b_PU_ZPositions;


   virtual void InitReco(TTree *tree);
};

void TreeDefinitionReco::InitReco(TTree *tree)
{
  // The Init() function is called when the selector needs to initialize
  // a new tree or chain. Typically here the branch addresses and branch
  // pointers of the tree will be set.
  // It is normally not necessary to make changes to the generated
  // code, but the routine can be extended by the user if needed.
  // Init() will be called many times when running on PROOF
  // (once per file to be processed).
  
  
  // Set object pointer
  //MET
  MET_Px = 0;
  MET_Py = 0;
  MET_Pt = 0;
  MET_Phi = 0;
  MET_SumEt = 0;
  
  MET_UncorrectedPt = 0;
  MET_UncorrectedPhi = 0;
  MET_UncorrectedSumEt = 0;
  
  MET_CaloMETPt = 0;
  MET_CaloMETPhi = 0;
  MET_CaloMETSumEt = 0;

  //Electrons
  Elec_N = 0;
  Elec_Pt = 0;
  Elec_Eta = 0;
  Elec_Phi = 0;
  Elec_M = 0;
  Elec_E = 0;
  Elec_Id = 0;
  Elec_Charge = 0;
  

  Elec_IsPF = 0;
  Elec_EcalIso = 0;
  Elec_HcalIso = 0;
  Elec_CaloIso = 0;
  Elec_HadOverEm = 0;
  Elec_HadOverEm1 = 0;
  Elec_HadOverEm2 = 0;

  Elec_NeutralHadIso = 0;
  Elec_ChargedHadIso = 0;
  Elec_PUChargedHadIso = 0;
  Elec_ParticleIso = 0;
  Elec_PhotonIso = 0;
  Elec_TrackIso = 0;

  Elec_E1X5 = 0;
  Elec_E2X5max = 0;
  Elec_E5X5 = 0;

  Elec_EcalEnergy = 0;
  Elec_CorrectedEcalEnergy = 0;
  Elec_CorrectedEcalEnergyError = 0;
  Elec_TrackMomentumError = 0;
  
  Elec_Vx = 0;
  Elec_Vy = 0;
  Elec_Vz = 0;
  
  Elec_SigmaEtaEta = 0;
  Elec_SigmaIetaIeta = 0;
  Elec_SigmaIphiIphi = 0;
  Elec_SigmaIetaIphi = 0;
  Elec_Full5x5_SigmaIphiIphi = 0;
  Elec_Full5x5_SigmaEtaEta = 0;
  Elec_Full5x5_SigmaIetaIeta = 0;
  Elec_Full5x5_SigmaIetaIphi = 0;
  Elec_Full5x5_R9 = 0;
  Elec_Full5x5_E1x5 = 0;
  Elec_Full5x5_E5x5 = 0;
  Elec_Full5x5_E2x5Max = 0;

  Elec_Dr03ECALSumEt = 0;
  Elec_Dr03HCALSumEt = 0;
  Elec_Dr03HCAL1SumEt = 0;
  Elec_Dr03HCAL2SumEt = 0;
  Elec_Dr03TkSumPt = 0;


  Elec_Dr04ECALSumEt = 0;
  Elec_Dr04HCALSumEt = 0;
  Elec_Dr04HCAL1SumEt = 0;
  Elec_Dr04HCAL2SumEt = 0;
  Elec_Dr04TkSumPt = 0;

  
  Elec_SCl_Eta = 0;
  Elec_SCl_EtaWidth = 0;
  Elec_SCl_Phi = 0;
  Elec_SCl_PhiWidth = 0;
  Elec_SCl_E = 0;
  Elec_SCl_RawE = 0;
  Elec_SCl_PreShowerE = 0;
  Elec_SCl_PreShower1E = 0;
  Elec_SCl_PreShower2E = 0;
  Elec_SCl_PositionR = 0;
  
  Elec_HasGsfTrack = 0;
  Elec_GsfTrack_D0 = 0;
  Elec_GsfTrack_Z0 = 0;
  Elec_GsfTrack_D0Error = 0;
  Elec_GsfTrack_Z0Error = 0;
  Elec_GsfTrack_PV_Dxy = 0;
  Elec_GsfTrack_PV_Z0 = 0;
  Elec_GsfTrack_RP_Dxy = 0;
  Elec_GsfTrack_RP_Z0 = 0;
  Elec_GsfTrack_BS_Dxy = 0;
  Elec_GsfTrack_BS_Z0 = 0;
  Elec_GsfTrack_DxyError = 0;
  //std::vector<Double_t> *Elec_GsfTrack_Z0Error = 0;
  Elec_GsfTrack_NormalizedChi2 = 0;
  Elec_IP3d = 0;
  Elec_IP3dError = 0;
  Elec_IP2d = 0;
  Elec_IP2dError = 0;
  Elec_IP3dBS = 0;
  Elec_IP3dBSError = 0;
  Elec_IP2dBS = 0;
  Elec_IP2dBSError = 0;
  
  
  
  //Muons
  Muon_Pt = 0;
  Muon_Eta = 0;
  Muon_Phi = 0;
  Muon_M = 0;
  Muon_E = 0;
  Muon_Id = 0;
  Muon_Charge = 0;

  Muon_IsPF = 0;
  Muon_IsGlobalMuon = 0;
  Muon_IsTrackerMuon = 0;
  Muon_IsStandAloneMuon = 0;
  Muon_IsCaloMuon = 0;
  Muon_IsRPCMuon = 0;

  Muon_EcalIso = 0;
  Muon_HcalIso = 0;
  Muon_CaloIso = 0;

  Muon_Vx = 0;
  Muon_Vy = 0;
  Muon_Vz = 0;
  
  Muon_NeutralHadronIso = 0;
  Muon_ChargedHadronIso = 0;
  Muon_PUChargedHadronIso = 0;
  Muon_PhotonIso = 0;
  Muon_TrackIso = 0;
  
  Muon_PFIso03_SumChargedHadronPt = 0;
  Muon_PFIso03_SumChargedParticlePt = 0;
  Muon_PFIso03_SumNeutralHadronEt = 0;
  Muon_PFIso03_SumNeutralHadronEtHighThreshold = 0;
  Muon_PFIso03_SumPhotonEt = 0;
  Muon_PFIso03_SumPhotonEtHighThreshold = 0;
  Muon_PFIso03_SumPUPt = 0;
  
  Muon_PFIso04_SumChargedHadronPt = 0;
  Muon_PFIso04_SumChargedParticlePt = 0;
  Muon_PFIso04_SumNeutralHadronEt = 0;
  Muon_PFIso04_SumNeutralHadronEtHighThreshold = 0;
  Muon_PFIso04_SumPhotonEt = 0;
  Muon_PFIso04_SumPhotonEtHighThreshold = 0;
  Muon_PFIso04_SumPUPt = 0;



  
  Muon_IP3d = 0;
  Muon_IP3dError = 0;
  Muon_IP2d = 0;
  Muon_IP2dError = 0;
  Muon_IP3dBS = 0;
  Muon_IP3dBSError = 0;
  Muon_IP2dBS = 0;
  Muon_IP2dBSError = 0;
  
  Muon_HasGlobalTrack = 0;
  Muon_GlobalTrack_D0 = 0;
  Muon_GlobalTrack_Z0 = 0;
  Muon_GlobalTrack_D0Error = 0;
  Muon_GlobalTrack_Z0Error = 0;
  Muon_GlobalTrack_PV_Dxy = 0;
  Muon_GlobalTrack_PV_Z0 = 0;
  Muon_GlobalTrack_RP_Dxy = 0;
  Muon_GlobalTrack_RP_Z0 = 0;
  Muon_GlobalTrack_BS_Dxy = 0;
  Muon_GlobalTrack_BS_Z0 = 0;
  Muon_GlobalTrack_DxyError = 0;
  //std::vector<Double_t> *Muon_GlobalTrack_Z0Error = 0;
  Muon_GlobalTrack_NormalizedChi2 = 0;
  Muon_GlobalTrack_Pt = 0;
  Muon_GlobalTrack_Eta = 0;
  Muon_GlobalTrack_Phi = 0;
  Muon_GlobalTrack_PtError = 0;
  Muon_GlobalTrack_EtaError = 0;
  Muon_GlobalTrack_PhiError = 0;
  Muon_GlobalTrack_Charge = 0;
  
  Muon_HasInnerTrack = 0;
  Muon_InnerTrack_D0 = 0;
  Muon_InnerTrack_Z0 = 0;
  Muon_InnerTrack_D0Error = 0;
  Muon_InnerTrack_Z0Error = 0;
  Muon_InnerTrack_PV_Dxy = 0;
  Muon_InnerTrack_PV_Z0 = 0;
  Muon_InnerTrack_RP_Dxy = 0;
  Muon_InnerTrack_RP_Z0 = 0;
  Muon_InnerTrack_BS_Dxy = 0;
  Muon_InnerTrack_BS_Z0 = 0;
  Muon_InnerTrack_DxyError = 0;
  //std::vector<Double_t> *Muon_InnerTrack_Z0Error = 0;
  Muon_InnerTrack_NormalizedChi2 = 0;
  Muon_InnerTrack_Pt = 0;
  Muon_InnerTrack_Eta = 0;
  Muon_InnerTrack_Phi = 0;
  Muon_InnerTrack_PtError = 0;
  Muon_InnerTrack_EtaError = 0;
  Muon_InnerTrack_PhiError = 0;
  Muon_InnerTrack_Charge = 0;

  Muon_HasBestTrack = 0;
  Muon_BestTrackType = 0;
  Muon_BestTrack_D0 = 0;
  Muon_BestTrack_Z0 = 0;
  Muon_BestTrack_D0Error = 0;
  Muon_BestTrack_Z0Error = 0;
  Muon_BestTrack_PV_Dxy = 0;
  Muon_BestTrack_PV_Z0 = 0;
  Muon_BestTrack_RP_Dxy = 0;
  Muon_BestTrack_RP_Z0 = 0;
  Muon_BestTrack_BS_Dxy = 0;
  Muon_BestTrack_BS_Z0 = 0;
  Muon_BestTrack_DxyError = 0;
  //std::vector<Double_t> *Muon_BestTrack_Z0Error = 0;
  Muon_BestTrack_NormalizedChi2 = 0;
  Muon_BestTrack_Pt = 0;
  Muon_BestTrack_Eta = 0;
  Muon_BestTrack_Phi = 0;
  Muon_BestTrack_PtError = 0;
  Muon_BestTrack_EtaError = 0;
  Muon_BestTrack_PhiError = 0;
  Muon_BestTrack_Charge = 0;

  
  //Taus
  Tau_Pt = 0;
  Tau_Eta = 0;
  Tau_Phi = 0;
  Tau_M = 0;
  Tau_E = 0;
  Tau_Id = 0;
  Tau_Charge = 0;
  
  Tau_DecayMode = 0;
  Tau_IsCaloTau = 0;

  Tau_hasLeadChargedHadrCand = 0;
  Tau_LeadingCHCPt = 0;
  Tau_LeadingCHCEta = 0;
  Tau_LeadingCHCPhi = 0;
  Tau_LeadingCHCM = 0;
  Tau_LeadingCHCE = 0;
  Tau_LeadingCHCEt = 0;
  Tau_LeadingCHCId = 0;
  Tau_LeadingCHCCharge = 0;
  
  Tau_LeadingCHCVx = 0;
  Tau_LeadingCHCVy = 0;
  Tau_LeadingCHCVz = 0;
  
  //Jets
  Jet_Pt = 0;
  Jet_Eta = 0;
  Jet_Phi = 0;
  Jet_M = 0;
  Jet_E = 0;
  Jet_JetArea = 0;
  
  Jet_ChargedMultiplicity = 0;
  Jet_ChargedHadronMultiplicity = 0;
  Jet_NeutralMultiplicity = 0;
  Jet_NeutralHadronMultiplicity = 0;
  Jet_ElectronMultiplicity = 0;
  Jet_MuonMultiplicity = 0;
  Jet_PhotonMultiplicity = 0;
  
  Jet_NeutralEmEnergy = 0;
  Jet_NeutralEmEnergyFraction = 0;
  Jet_NeutralHadEnergy = 0;
  Jet_NeutralHadEnergyFraction = 0;
  
  Jet_ChargedEmEnergy = 0;
  Jet_ChargedEmEnergyFraction = 0;
  Jet_ChargedHadEnergy = 0;
  Jet_ChargedHadEnergyFraction = 0;
  Jet_ChargedMuEnergy = 0;
  Jet_ChargedMuEnergyFraction = 0;
  
  Jet_ElectronEnergy = 0;
  Jet_ElectronEnergyFraction = 0;
  Jet_MuonEnergy = 0;
  Jet_MuonEnergyFraction = 0;
  Jet_PhotonEnergy = 0;
  Jet_PhotonEnergyFraction = 0;
  
  Jet_bDis_JBP = 0;
  Jet_bDis_JP = 0;
  Jet_bDis_TCHP = 0;
  Jet_bDis_TCHE = 0;
  Jet_bDis_SVHP = 0;
  Jet_bDis_SVHE = 0;
  Jet_bDis_CMVA = 0;
  Jet_bDis_CSV = 0;
  Jet_bDis_CSV2 = 0;
  Jet_bDis_CISV2 = 0;
  Jet_bDis_CSVSL = 0;
  
  Jet_HasGenJet = 0;
  Jet_GenJet_Pt = 0;
  Jet_GenJet_Eta = 0;
  Jet_GenJet_Phi = 0;
  Jet_GenJet_M = 0;
  Jet_GenJet_E = 0;
  Jet_GenJet_emE = 0;
  Jet_GenJet_hadE = 0;
  Jet_GenJet_invisibleE = 0;
  Jet_GenPartonFlavour = 0;
  Jet_GenHadronFlavour = 0;
  
  //Vertex and Primary Vertex
  PV_X = 0;
  PV_Y = 0;
  PV_Z = 0;
  Vertex_X = 0;
  Vertex_ErrorX = 0;
  Vertex_Y = 0;
  Vertex_ErrorY = 0;
  Vertex_Z = 0;
  Vertex_ErrorZ = 0;
  Vertex_Chi2 = 0;
  Vertex_DOF = 0;
  Vertex_ReducedChi2 = 0;

  //PileUp
  PU_Bx = 0;
  PU_EventPU = 0;
  PU_BxPU = 0;
  PU_ZPositions = 0;

   std::cout << "I N F O ! TreeDefinitionReco::InitReco(...) - Setting branch addresses and branch pointers." << std::endl;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

  std::cout << "I N F O ! TreeDefinitionReco::InitReco(...) - Setting MET addresses." << std::endl;
  //MET
  fChain->SetBranchAddress("MET_Px"               , &MET_Px               , &b_MET_Px);
  fChain->SetBranchAddress("MET_Py"               , &MET_Py               , &b_MET_Py);
  fChain->SetBranchAddress("MET_Pt"               , &MET_Pt               , &b_MET_Pt);
  fChain->SetBranchAddress("MET_Phi"              , &MET_Phi              , &b_MET_Phi);
  fChain->SetBranchAddress("MET_SumEt"            , &MET_SumEt            , &b_MET_SumEt);
  
  fChain->SetBranchAddress("MET_UncorrectedPt"    , &MET_UncorrectedPt    , &b_MET_UncorrectedPt);
  fChain->SetBranchAddress("MET_UncorrectedPhi"   , &MET_UncorrectedPhi   , &b_MET_UncorrectedPhi);
  fChain->SetBranchAddress("MET_UncorrectedSumEt" , &MET_UncorrectedSumEt , &b_MET_UncorrectedSumEt);
  
  fChain->SetBranchAddress("MET_CaloMETPt"        , &MET_CaloMETPt        , &b_MET_CaloMETPt);
  fChain->SetBranchAddress("MET_CaloMETPhi"       , &MET_CaloMETPhi       , &b_MET_CaloMETPhi);
  fChain->SetBranchAddress("MET_CaloMETSumEt"     , &MET_CaloMETSumEt     , &b_MET_CaloMETSumEt);

  std::cout << "I N F O ! TreeDefinitionReco::InitReco(...) - Setting Electron addresses." << std::endl;
  //Electrons
  fChain->SetBranchAddress("Elec_N"                      , &Elec_N                      , &b_Elec_N);
  fChain->SetBranchAddress("Elec_Pt"                     , &Elec_Pt                     , &b_Elec_Pt);
  fChain->SetBranchAddress("Elec_Eta"                    , &Elec_Eta                    , &b_Elec_Eta);
  fChain->SetBranchAddress("Elec_Phi"                    , &Elec_Phi                    , &b_Elec_Phi);
  fChain->SetBranchAddress("Elec_M"                      , &Elec_M                      , &b_Elec_M);
  fChain->SetBranchAddress("Elec_E"                      , &Elec_E                      , &b_Elec_E);
  fChain->SetBranchAddress("Elec_Id"                     , &Elec_Id                     , &b_Elec_Id);
  fChain->SetBranchAddress("Elec_Charge"                 , &Elec_Charge                 , &b_Elec_Charge);
  
  fChain->SetBranchAddress("Elec_IsPF"                  , &Elec_IsPF                    , &b_Elec_IsPF);
  fChain->SetBranchAddress("Elec_EcalIso"               , &Elec_EcalIso                 , &b_Elec_EcalIso);
  fChain->SetBranchAddress("Elec_HcalIso"               , &Elec_HcalIso                 , &b_Elec_HcalIso);
  fChain->SetBranchAddress("Elec_CaloIso"               , &Elec_CaloIso                 , &b_Elec_CaloIso);
  fChain->SetBranchAddress("Elec_HadOverEm"             , &Elec_HadOverEm               , &b_Elec_HadOverEm);
  fChain->SetBranchAddress("Elec_HadOverEm1"            , &Elec_HadOverEm1              , &b_Elec_HadOverEm1);
  fChain->SetBranchAddress("Elec_HadOverEm2"            , &Elec_HadOverEm2              , &b_Elec_HadOverEm2);

  fChain->SetBranchAddress("Elec_NeutralHadIso"         , &Elec_NeutralHadIso           , &b_Elec_NeutralHadIso);
  fChain->SetBranchAddress("Elec_ChargedHadIso"         , &Elec_ChargedHadIso           , &b_Elec_ChargedHadIso);
  fChain->SetBranchAddress("Elec_PUChargedHadIso"       , &Elec_PUChargedHadIso         , &b_Elec_PUChargedHadIso);
  fChain->SetBranchAddress("Elec_ParticleIso"           , &Elec_ParticleIso             , &b_Elec_ParticleIso);
  fChain->SetBranchAddress("Elec_PhotonIso"             , &Elec_PhotonIso               , &b_Elec_PhotonIso);
  fChain->SetBranchAddress("Elec_TrackIso"              , &Elec_TrackIso                , &b_Elec_TrackIso);

  fChain->SetBranchAddress("Elec_E1X5"                  , &Elec_E1X5                    , &b_Elec_E1X5);
  fChain->SetBranchAddress("Elec_E2X5max"               , &Elec_E2X5max                 , &b_Elec_E2X5max);
  fChain->SetBranchAddress("Elec_E5X5"                  , &Elec_E5X5                    , &b_Elec_E5X5);

  fChain->SetBranchAddress("Elec_EcalEnergy"               , &Elec_EcalEnergy               , &b_Elec_EcalEnergy);
  fChain->SetBranchAddress("Elec_CorrectedEcalEnergy"      , &Elec_CorrectedEcalEnergy      , &b_Elec_CorrectedEcalEnergy);
  fChain->SetBranchAddress("Elec_CorrectedEcalEnergyError" , &Elec_CorrectedEcalEnergyError , &b_Elec_CorrectedEcalEnergyError);
  fChain->SetBranchAddress("Elec_TrackMomentumError"       , &Elec_TrackMomentumError       , &b_Elec_TrackMomentumError);
  
  fChain->SetBranchAddress("Elec_Vx"               , &Elec_Vx                 , &b_Elec_Vx);
  fChain->SetBranchAddress("Elec_Vy"               , &Elec_Vy                 , &b_Elec_Vy);
  fChain->SetBranchAddress("Elec_Vz"               , &Elec_Vz                 , &b_Elec_Vz);
  
  fChain->SetBranchAddress("Elec_SigmaEtaEta"                 , &Elec_SigmaEtaEta             , &b_Elec_SigmaEtaEta);
  fChain->SetBranchAddress("Elec_SigmaIetaIeta"               , &Elec_SigmaIetaIeta           , &b_Elec_SigmaIetaIeta);
  fChain->SetBranchAddress("Elec_SigmaIphiIphi"               , &Elec_SigmaIphiIphi           , &b_Elec_SigmaIphiIphi);
  fChain->SetBranchAddress("Elec_SigmaIetaIphi"               , &Elec_SigmaIetaIphi           , &b_Elec_SigmaIetaIphi);
  fChain->SetBranchAddress("Elec_Full5x5_SigmaIphiIphi"       , &Elec_Full5x5_SigmaIphiIphi   , &b_Elec_Full5x5_SigmaIphiIphi);
  fChain->SetBranchAddress("Elec_Full5x5_SigmaEtaEta"         , &Elec_Full5x5_SigmaEtaEta     , &b_Elec_Full5x5_SigmaEtaEta);
  fChain->SetBranchAddress("Elec_Full5x5_SigmaIetaIeta"       , &Elec_Full5x5_SigmaIetaIeta   , &b_Elec_Full5x5_SigmaIetaIeta);
  fChain->SetBranchAddress("Elec_Full5x5_SigmaIetaIphi"       , &Elec_Full5x5_SigmaIetaIphi   , &b_Elec_Full5x5_SigmaIetaIphi);
  fChain->SetBranchAddress("Elec_Full5x5_R9"                  , &Elec_Full5x5_R9              , &b_Elec_Full5x5_R9);
  fChain->SetBranchAddress("Elec_Full5x5_E1x5"                , &Elec_Full5x5_E1x5            , &b_Elec_Full5x5_E1x5);
  fChain->SetBranchAddress("Elec_Full5x5_E5x5"                , &Elec_Full5x5_E5x5            , &b_Elec_Full5x5_E5x5);
  fChain->SetBranchAddress("Elec_Full5x5_E2x5Max"             , &Elec_Full5x5_E2x5Max         , &b_Elec_Full5x5_E2x5Max);

  fChain->SetBranchAddress("Elec_Dr03ECALSumEt"               , &Elec_Dr03ECALSumEt                , &b_Elec_Dr03ECALSumEt);
  fChain->SetBranchAddress("Elec_Dr03HCALSumEt"               , &Elec_Dr03HCALSumEt                , &b_Elec_Dr03HCALSumEt);
  fChain->SetBranchAddress("Elec_Dr03HCAL1SumEt"              , &Elec_Dr03HCAL1SumEt               , &b_Elec_Dr03HCAL1SumEt);
  fChain->SetBranchAddress("Elec_Dr03HCAL2SumEt"              , &Elec_Dr03HCAL2SumEt               , &b_Elec_Dr03HCAL2SumEt);
  fChain->SetBranchAddress("Elec_Dr03TkSumPt"                 , &Elec_Dr03TkSumPt                  , &b_Elec_Dr03TkSumPt);

  fChain->SetBranchAddress("Elec_Dr04ECALSumEt"               , &Elec_Dr04ECALSumEt                , &b_Elec_Dr04ECALSumEt);
  fChain->SetBranchAddress("Elec_Dr04HCALSumEt"               , &Elec_Dr04HCALSumEt                , &b_Elec_Dr04HCALSumEt);
  fChain->SetBranchAddress("Elec_Dr04HCAL1SumEt"              , &Elec_Dr04HCAL1SumEt               , &b_Elec_Dr04HCAL1SumEt);
  fChain->SetBranchAddress("Elec_Dr04HCAL2SumEt"              , &Elec_Dr04HCAL2SumEt               , &b_Elec_Dr04HCAL2SumEt);
  fChain->SetBranchAddress("Elec_Dr04TkSumPt"                 , &Elec_Dr04TkSumPt                  , &b_Elec_Dr04TkSumPt);


  fChain->SetBranchAddress("Elec_SCl_Eta"                , &Elec_SCl_Eta                , &b_Elec_SCl_Eta);
  fChain->SetBranchAddress("Elec_SCl_EtaWidth"           , &Elec_SCl_EtaWidth           , &b_Elec_SCl_EtaWidth);
  fChain->SetBranchAddress("Elec_SCl_Phi"                , &Elec_SCl_Phi                , &b_Elec_SCl_Phi);
  fChain->SetBranchAddress("Elec_SCl_PhiWidth"           , &Elec_SCl_PhiWidth           , &b_Elec_SCl_PhiWidth);
  fChain->SetBranchAddress("Elec_SCl_E"                  , &Elec_SCl_E                  , &b_Elec_SCl_E);
  fChain->SetBranchAddress("Elec_SCl_RawE"               , &Elec_SCl_RawE               , &b_Elec_SCl_RawE);
  fChain->SetBranchAddress("Elec_SCl_PreShowerE"         , &Elec_SCl_PreShowerE         , &b_Elec_SCl_PreShowerE);
  fChain->SetBranchAddress("Elec_SCl_PreShower1E"        , &Elec_SCl_PreShower1E        , &b_Elec_SCl_PreShower1E);
  fChain->SetBranchAddress("Elec_SCl_PreShower2E"        , &Elec_SCl_PreShower2E        , &b_Elec_SCl_PreShower2E);
  fChain->SetBranchAddress("Elec_SCl_PositionR"          , &Elec_SCl_PositionR          , &b_Elec_SCl_PositionR);
  
  fChain->SetBranchAddress("Elec_HasGsfTrack"            , &Elec_HasGsfTrack            , &b_Elec_HasGsfTrack);
  fChain->SetBranchAddress("Elec_GsfTrack_D0"            , &Elec_GsfTrack_D0            , &b_Elec_GsfTrack_D0);
  fChain->SetBranchAddress("Elec_GsfTrack_Z0"            , &Elec_GsfTrack_Z0            , &b_Elec_GsfTrack_Z0);
  fChain->SetBranchAddress("Elec_GsfTrack_D0Error"       , &Elec_GsfTrack_D0Error       , &b_Elec_GsfTrack_D0Error);
  fChain->SetBranchAddress("Elec_GsfTrack_Z0Error"       , &Elec_GsfTrack_Z0Error       , &b_Elec_GsfTrack_Z0Error);
  fChain->SetBranchAddress("Elec_GsfTrack_PV_Dxy"        , &Elec_GsfTrack_PV_Dxy        , &b_Elec_GsfTrack_PV_Dxy);
  fChain->SetBranchAddress("Elec_GsfTrack_PV_Z0"         , &Elec_GsfTrack_PV_Z0         , &b_Elec_GsfTrack_PV_Z0);
  fChain->SetBranchAddress("Elec_GsfTrack_RP_Dxy"        , &Elec_GsfTrack_RP_Dxy        , &b_Elec_GsfTrack_RP_Dxy);
  fChain->SetBranchAddress("Elec_GsfTrack_RP_Z0"         , &Elec_GsfTrack_RP_Z0         , &b_Elec_GsfTrack_RP_Z0);
  fChain->SetBranchAddress("Elec_GsfTrack_BS_Dxy"        , &Elec_GsfTrack_BS_Dxy        , &b_Elec_GsfTrack_BS_Dxy);
  fChain->SetBranchAddress("Elec_GsfTrack_BS_Z0"         , &Elec_GsfTrack_BS_Z0         , &b_Elec_GsfTrack_BS_Z0);
  fChain->SetBranchAddress("Elec_GsfTrack_DxyError"      , &Elec_GsfTrack_DxyError      , &b_Elec_GsfTrack_DxyError);
  //std::vector<Double_t> *Elec_GsfTrack_Z0Error;
  fChain->SetBranchAddress("Elec_GsfTrack_NormalizedChi2", &Elec_GsfTrack_NormalizedChi2, &b_Elec_GsfTrack_NormalizedChi2);
  fChain->SetBranchAddress("Elec_IP3d"                   , &Elec_IP3d                   , &b_Elec_IP3d);
  fChain->SetBranchAddress("Elec_IP3dError"              , &Elec_IP3dError              , &b_Elec_IP3dError);
  fChain->SetBranchAddress("Elec_IP2d"                   , &Elec_IP2d                   , &b_Elec_IP2d);
  fChain->SetBranchAddress("Elec_IP2dError"              , &Elec_IP2dError              , &b_Elec_IP2dError);
  fChain->SetBranchAddress("Elec_IP3dBS"                 , &Elec_IP3dBS                 , &b_Elec_IP3dBS);
  fChain->SetBranchAddress("Elec_IP3dBSError"            , &Elec_IP3dBSError            , &b_Elec_IP3dBSError);
  fChain->SetBranchAddress("Elec_IP2dBS"                 , &Elec_IP2dBS                 , &b_Elec_IP2dBS);
  fChain->SetBranchAddress("Elec_IP2dBSError"            , &Elec_IP2dBSError            , &b_Elec_IP2dBSError);
  
  
  std::cout << "I N F O ! TreeDefinitionReco::InitReco(...) - Setting Muon addresses." << std::endl;
  //Muons
  fChain->SetBranchAddress("Muon_Pt"                        , &Muon_Pt                        , &b_Muon_Pt);
  fChain->SetBranchAddress("Muon_Eta"                       , &Muon_Eta                       , &b_Muon_Eta);
  fChain->SetBranchAddress("Muon_Phi"                       , &Muon_Phi                       , &b_Muon_Phi);
  fChain->SetBranchAddress("Muon_M"                         , &Muon_M                         , &b_Muon_M);
  fChain->SetBranchAddress("Muon_E"                         , &Muon_E                         , &b_Muon_E);
  fChain->SetBranchAddress("Muon_Id"                        , &Muon_Id                        , &b_Muon_Id);
  fChain->SetBranchAddress("Muon_Charge"                    , &Muon_Charge                    , &b_Muon_Charge);
  
  fChain->SetBranchAddress("Muon_IsPF"                   , &Muon_IsPF	                   , &b_Muon_IsPF	);
  fChain->SetBranchAddress("Muon_IsGlobalMuon"           , &Muon_IsGlobalMuon	           , &b_Muon_IsGlobalMuon	);
  fChain->SetBranchAddress("Muon_IsTrackerMuon"          , &Muon_IsTrackerMuon	           , &b_Muon_IsTrackerMuon	);
  fChain->SetBranchAddress("Muon_IsStandAloneMuon"       , &Muon_IsStandAloneMuon	   , &b_Muon_IsStandAloneMuon	);
  fChain->SetBranchAddress("Muon_IsCaloMuon"             , &Muon_IsCaloMuon	           , &b_Muon_IsCaloMuon	);
  fChain->SetBranchAddress("Muon_IsRPCMuon"              , &Muon_IsRPCMuon	           , &b_Muon_IsRPCMuon	);
  fChain->SetBranchAddress("Muon_EcalIso"                , &Muon_EcalIso	           , &b_Muon_EcalIso	);
  fChain->SetBranchAddress("Muon_HcalIso"                , &Muon_HcalIso	           , &b_Muon_HcalIso	);
  fChain->SetBranchAddress("Muon_CaloIso"                , &Muon_CaloIso	           , &b_Muon_CaloIso	);
  
  fChain->SetBranchAddress("Muon_Vx"           , &Muon_Vx	           , &b_Muon_Vx	);
  fChain->SetBranchAddress("Muon_Vy"           , &Muon_Vy	           , &b_Muon_Vy	);
  fChain->SetBranchAddress("Muon_Vz"           , &Muon_Vz	           , &b_Muon_Vz	);
  
  fChain->SetBranchAddress("Muon_NeutralHadronIso"    , &Muon_NeutralHadronIso	           , &b_Muon_NeutralHadronIso	);
  fChain->SetBranchAddress("Muon_ChargedHadronIso"    , &Muon_ChargedHadronIso	           , &b_Muon_ChargedHadronIso	);
  fChain->SetBranchAddress("Muon_PUChargedHadronIso"  , &Muon_PUChargedHadronIso	   , &b_Muon_PUChargedHadronIso	);
  fChain->SetBranchAddress("Muon_PhotonIso"           , &Muon_PhotonIso	                   , &b_Muon_PhotonIso	);
  fChain->SetBranchAddress("Muon_TrackIso"            , &Muon_TrackIso	                   , &b_Muon_TrackIso	);

  fChain->SetBranchAddress("Muon_PFIso03_SumChargedHadronPt"              , &Muon_PFIso03_SumChargedHadronPt	           , &b_Muon_PFIso03_SumChargedHadronPt	);
  fChain->SetBranchAddress("Muon_PFIso03_SumChargedParticlePt"            , &Muon_PFIso03_SumChargedParticlePt	           , &b_Muon_PFIso03_SumChargedParticlePt	);
  fChain->SetBranchAddress("Muon_PFIso03_SumNeutralHadronEt"              , &Muon_PFIso03_SumNeutralHadronEt	           , &b_Muon_PFIso03_SumNeutralHadronEt	);
  fChain->SetBranchAddress("Muon_PFIso03_SumNeutralHadronEtHighThreshold" , &Muon_PFIso03_SumNeutralHadronEtHighThreshold  , &b_Muon_PFIso03_SumNeutralHadronEtHighThreshold	);
  fChain->SetBranchAddress("Muon_PFIso03_SumPhotonEt"                     , &Muon_PFIso03_SumPhotonEt	                   , &b_Muon_PFIso03_SumPhotonEt	);
  fChain->SetBranchAddress("Muon_PFIso03_SumPhotonEtHighThreshold"        , &Muon_PFIso03_SumPhotonEtHighThreshold	   , &b_Muon_PFIso03_SumPhotonEtHighThreshold	);
  fChain->SetBranchAddress("Muon_PFIso03_SumPUPt"                         , &Muon_PFIso03_SumPUPt	                   , &b_Muon_PFIso03_SumPUPt	);


  fChain->SetBranchAddress("Muon_PFIso04_SumChargedHadronPt"              , &Muon_PFIso04_SumChargedHadronPt	           , &b_Muon_PFIso04_SumChargedHadronPt	);
  fChain->SetBranchAddress("Muon_PFIso04_SumChargedParticlePt"            , &Muon_PFIso04_SumChargedParticlePt	           , &b_Muon_PFIso04_SumChargedParticlePt	);
  fChain->SetBranchAddress("Muon_PFIso04_SumNeutralHadronEt"              , &Muon_PFIso04_SumNeutralHadronEt	           , &b_Muon_PFIso04_SumNeutralHadronEt	);
  fChain->SetBranchAddress("Muon_PFIso04_SumNeutralHadronEtHighThreshold" , &Muon_PFIso04_SumNeutralHadronEtHighThreshold  , &b_Muon_PFIso04_SumNeutralHadronEtHighThreshold	);
  fChain->SetBranchAddress("Muon_PFIso04_SumPhotonEt"                     , &Muon_PFIso04_SumPhotonEt	                   , &b_Muon_PFIso04_SumPhotonEt	);
  fChain->SetBranchAddress("Muon_PFIso04_SumPhotonEtHighThreshold"        , &Muon_PFIso04_SumPhotonEtHighThreshold	   , &b_Muon_PFIso04_SumPhotonEtHighThreshold	);
  fChain->SetBranchAddress("Muon_PFIso04_SumPUPt"                         , &Muon_PFIso04_SumPUPt	                   , &b_Muon_PFIso04_SumPUPt	);
  


  fChain->SetBranchAddress("Muon_IP3d"                      , &Muon_IP3d                      , &b_Muon_IP3d);
  fChain->SetBranchAddress("Muon_IP3dError"                 , &Muon_IP3dError                 , &b_Muon_IP3dError);
  fChain->SetBranchAddress("Muon_IP2d"                      , &Muon_IP2d                      , &b_Muon_IP2d);
  fChain->SetBranchAddress("Muon_IP2dError"                 , &Muon_IP2dError                 , &b_Muon_IP2dError);
  fChain->SetBranchAddress("Muon_IP3dBS"                    , &Muon_IP3dBS                    , &b_Muon_IP3dBS);
  fChain->SetBranchAddress("Muon_IP3dBSError"               , &Muon_IP3dBSError               , &b_Muon_IP3dBSError);
  fChain->SetBranchAddress("Muon_IP2dBS"                    , &Muon_IP2dBS                    , &b_Muon_IP2dBS);
  fChain->SetBranchAddress("Muon_IP2dBSError"               , &Muon_IP2dBSError               , &b_Muon_IP2dBSError);
  
  fChain->SetBranchAddress("Muon_HasGlobalTrack"            , &Muon_HasGlobalTrack            , &b_Muon_HasGlobalTrack);
  fChain->SetBranchAddress("Muon_GlobalTrack_D0"            , &Muon_GlobalTrack_D0            , &b_Muon_GlobalTrack_D0);
  fChain->SetBranchAddress("Muon_GlobalTrack_Z0"            , &Muon_GlobalTrack_Z0            , &b_Muon_GlobalTrack_Z0);
  fChain->SetBranchAddress("Muon_GlobalTrack_D0Error"       , &Muon_GlobalTrack_D0Error       , &b_Muon_GlobalTrack_D0Error);
  fChain->SetBranchAddress("Muon_GlobalTrack_Z0Error"       , &Muon_GlobalTrack_Z0Error       , &b_Muon_GlobalTrack_Z0Error);
  fChain->SetBranchAddress("Muon_GlobalTrack_PV_Dxy"        , &Muon_GlobalTrack_PV_Dxy        , &b_Muon_GlobalTrack_PV_Dxy);
  fChain->SetBranchAddress("Muon_GlobalTrack_PV_Z0"         , &Muon_GlobalTrack_PV_Z0         , &b_Muon_GlobalTrack_PV_Z0);
  fChain->SetBranchAddress("Muon_GlobalTrack_RP_Dxy"        , &Muon_GlobalTrack_RP_Dxy        , &b_Muon_GlobalTrack_RP_Dxy);
  fChain->SetBranchAddress("Muon_GlobalTrack_RP_Z0"         , &Muon_GlobalTrack_RP_Z0         , &b_Muon_GlobalTrack_RP_Z0);
  fChain->SetBranchAddress("Muon_GlobalTrack_BS_Dxy"        , &Muon_GlobalTrack_BS_Dxy        , &b_Muon_GlobalTrack_BS_Dxy);
  fChain->SetBranchAddress("Muon_GlobalTrack_BS_Z0"         , &Muon_GlobalTrack_BS_Z0         , &b_Muon_GlobalTrack_BS_Z0);
  fChain->SetBranchAddress("Muon_GlobalTrack_DxyError"      , &Muon_GlobalTrack_DxyError      , &b_Muon_GlobalTrack_DxyError);
  //std::vector<Double_t> *Muon_GlobalTrack_Z0Error"               , &               , &b_);
  fChain->SetBranchAddress("Muon_GlobalTrack_NormalizedChi2", &Muon_GlobalTrack_NormalizedChi2, &b_Muon_GlobalTrack_NormalizedChi2);
  fChain->SetBranchAddress("Muon_GlobalTrack_Pt"            , &Muon_GlobalTrack_Pt            , &b_Muon_GlobalTrack_Pt);
  fChain->SetBranchAddress("Muon_GlobalTrack_Eta"           , &Muon_GlobalTrack_Eta           , &b_Muon_GlobalTrack_Eta);
  fChain->SetBranchAddress("Muon_GlobalTrack_Phi"           , &Muon_GlobalTrack_Phi           , &b_Muon_GlobalTrack_Phi);
  fChain->SetBranchAddress("Muon_GlobalTrack_PtError"       , &Muon_GlobalTrack_PtError       , &b_Muon_GlobalTrack_PtError);
  fChain->SetBranchAddress("Muon_GlobalTrack_EtaError"      , &Muon_GlobalTrack_EtaError      , &b_Muon_GlobalTrack_EtaError);
  fChain->SetBranchAddress("Muon_GlobalTrack_PhiError"      , &Muon_GlobalTrack_PhiError      , &b_Muon_GlobalTrack_PhiError);
  fChain->SetBranchAddress("Muon_GlobalTrack_Charge"        , &Muon_GlobalTrack_Charge        , &b_Muon_GlobalTrack_Charge);

  fChain->SetBranchAddress("Muon_HasInnerTrack"            , &Muon_HasInnerTrack            , &b_Muon_HasInnerTrack);
  fChain->SetBranchAddress("Muon_InnerTrack_D0"            , &Muon_InnerTrack_D0            , &b_Muon_InnerTrack_D0);
  fChain->SetBranchAddress("Muon_InnerTrack_Z0"            , &Muon_InnerTrack_Z0            , &b_Muon_InnerTrack_Z0);
  fChain->SetBranchAddress("Muon_InnerTrack_D0Error"       , &Muon_InnerTrack_D0Error       , &b_Muon_InnerTrack_D0Error);
  fChain->SetBranchAddress("Muon_InnerTrack_Z0Error"       , &Muon_InnerTrack_Z0Error       , &b_Muon_InnerTrack_Z0Error);
  fChain->SetBranchAddress("Muon_InnerTrack_PV_Dxy"        , &Muon_InnerTrack_PV_Dxy        , &b_Muon_InnerTrack_PV_Dxy);
  fChain->SetBranchAddress("Muon_InnerTrack_PV_Z0"         , &Muon_InnerTrack_PV_Z0         , &b_Muon_InnerTrack_PV_Z0);
  fChain->SetBranchAddress("Muon_InnerTrack_RP_Dxy"        , &Muon_InnerTrack_RP_Dxy        , &b_Muon_InnerTrack_RP_Dxy);
  fChain->SetBranchAddress("Muon_InnerTrack_RP_Z0"         , &Muon_InnerTrack_RP_Z0         , &b_Muon_InnerTrack_RP_Z0);
  fChain->SetBranchAddress("Muon_InnerTrack_BS_Dxy"        , &Muon_InnerTrack_BS_Dxy        , &b_Muon_InnerTrack_BS_Dxy);
  fChain->SetBranchAddress("Muon_InnerTrack_BS_Z0"         , &Muon_InnerTrack_BS_Z0         , &b_Muon_InnerTrack_BS_Z0);
  fChain->SetBranchAddress("Muon_InnerTrack_DxyError"      , &Muon_InnerTrack_DxyError      , &b_Muon_InnerTrack_DxyError);
  //std::vector<Double_t> *Muon_InnerTrack_Z0Error"               , &               , &b_);
  fChain->SetBranchAddress("Muon_InnerTrack_NormalizedChi2", &Muon_InnerTrack_NormalizedChi2, &b_Muon_InnerTrack_NormalizedChi2);
  fChain->SetBranchAddress("Muon_InnerTrack_Pt"            , &Muon_InnerTrack_Pt            , &b_Muon_InnerTrack_Pt);
  fChain->SetBranchAddress("Muon_InnerTrack_Eta"           , &Muon_InnerTrack_Eta           , &b_Muon_InnerTrack_Eta);
  fChain->SetBranchAddress("Muon_InnerTrack_Phi"           , &Muon_InnerTrack_Phi           , &b_Muon_InnerTrack_Phi);
  fChain->SetBranchAddress("Muon_InnerTrack_PtError"       , &Muon_InnerTrack_PtError       , &b_Muon_InnerTrack_PtError);
  fChain->SetBranchAddress("Muon_InnerTrack_EtaError"      , &Muon_InnerTrack_EtaError      , &b_Muon_InnerTrack_EtaError);
  fChain->SetBranchAddress("Muon_InnerTrack_PhiError"      , &Muon_InnerTrack_PhiError      , &b_Muon_InnerTrack_PhiError);
  fChain->SetBranchAddress("Muon_InnerTrack_Charge"        , &Muon_InnerTrack_Charge        , &b_Muon_InnerTrack_Charge);

  fChain->SetBranchAddress("Muon_HasBestTrack"            , &Muon_HasBestTrack            , &b_Muon_HasBestTrack);
  fChain->SetBranchAddress("Muon_BestTrackType"           , &Muon_BestTrackType           , &b_Muon_BestTrackType);
  fChain->SetBranchAddress("Muon_BestTrack_D0"            , &Muon_BestTrack_D0            , &b_Muon_BestTrack_D0);
  fChain->SetBranchAddress("Muon_BestTrack_Z0"            , &Muon_BestTrack_Z0            , &b_Muon_BestTrack_Z0);
  fChain->SetBranchAddress("Muon_BestTrack_D0Error"       , &Muon_BestTrack_D0Error       , &b_Muon_BestTrack_D0Error);
  fChain->SetBranchAddress("Muon_BestTrack_Z0Error"       , &Muon_BestTrack_Z0Error       , &b_Muon_BestTrack_Z0Error);
  fChain->SetBranchAddress("Muon_BestTrack_PV_Dxy"        , &Muon_BestTrack_PV_Dxy        , &b_Muon_BestTrack_PV_Dxy);
  fChain->SetBranchAddress("Muon_BestTrack_PV_Z0"         , &Muon_BestTrack_PV_Z0         , &b_Muon_BestTrack_PV_Z0);
  fChain->SetBranchAddress("Muon_BestTrack_RP_Dxy"        , &Muon_BestTrack_RP_Dxy        , &b_Muon_BestTrack_RP_Dxy);
  fChain->SetBranchAddress("Muon_BestTrack_RP_Z0"         , &Muon_BestTrack_RP_Z0         , &b_Muon_BestTrack_RP_Z0);
  fChain->SetBranchAddress("Muon_BestTrack_BS_Dxy"        , &Muon_BestTrack_BS_Dxy        , &b_Muon_BestTrack_BS_Dxy);
  fChain->SetBranchAddress("Muon_BestTrack_BS_Z0"         , &Muon_BestTrack_BS_Z0         , &b_Muon_BestTrack_BS_Z0);
  fChain->SetBranchAddress("Muon_BestTrack_DxyError"      , &Muon_BestTrack_DxyError      , &b_Muon_BestTrack_DxyError);
  //std::vector<Double_t> *Muon_BestTrack_Z0Error"               , &               , &b_);
  fChain->SetBranchAddress("Muon_BestTrack_NormalizedChi2", &Muon_BestTrack_NormalizedChi2, &b_Muon_BestTrack_NormalizedChi2);
  fChain->SetBranchAddress("Muon_BestTrack_Pt"            , &Muon_BestTrack_Pt            , &b_Muon_BestTrack_Pt);
  fChain->SetBranchAddress("Muon_BestTrack_Eta"           , &Muon_BestTrack_Eta           , &b_Muon_BestTrack_Eta);
  fChain->SetBranchAddress("Muon_BestTrack_Phi"           , &Muon_BestTrack_Phi           , &b_Muon_BestTrack_Phi);
  fChain->SetBranchAddress("Muon_BestTrack_PtError"       , &Muon_BestTrack_PtError       , &b_Muon_BestTrack_PtError);
  fChain->SetBranchAddress("Muon_BestTrack_EtaError"      , &Muon_BestTrack_EtaError      , &b_Muon_BestTrack_EtaError);
  fChain->SetBranchAddress("Muon_BestTrack_PhiError"      , &Muon_BestTrack_PhiError      , &b_Muon_BestTrack_PhiError);
  fChain->SetBranchAddress("Muon_BestTrack_Charge"        , &Muon_BestTrack_Charge        , &b_Muon_BestTrack_Charge);


  std::cout << "I N F O ! TreeDefinitionReco::InitReco(...) - Setting Tau addresses." << std::endl;
  //Taus
  fChain->SetBranchAddress("Tau_Pt"                      , &Tau_Pt                     , &b_Tau_Pt);
  fChain->SetBranchAddress("Tau_Eta"                     , &Tau_Eta                    , &b_Tau_Eta);
  fChain->SetBranchAddress("Tau_Phi"                     , &Tau_Phi                    , &b_Tau_Phi);
  fChain->SetBranchAddress("Tau_M"                       , &Tau_M                      , &b_Tau_M);
  fChain->SetBranchAddress("Tau_E"                       , &Tau_E                      , &b_Tau_E);
  fChain->SetBranchAddress("Tau_Id"                      , &Tau_Id                     , &b_Tau_Id);
  fChain->SetBranchAddress("Tau_Charge"                  , &Tau_Charge                 , &b_Tau_Charge);
  
  fChain->SetBranchAddress("Tau_DecayMode"               , &Tau_DecayMode              , &b_Tau_DecayMode);
  fChain->SetBranchAddress("Tau_IsCaloTau"               , &Tau_IsCaloTau              , &b_Tau_IsCaloTau);

  fChain->SetBranchAddress("Tau_hasLeadChargedHadrCand"  , &Tau_hasLeadChargedHadrCand , &b_Tau_hasLeadChargedHadrCand);
  fChain->SetBranchAddress("Tau_LeadingCHCPt"            , &Tau_LeadingCHCPt           , &b_Tau_LeadingCHCPt);
  fChain->SetBranchAddress("Tau_LeadingCHCEta"           , &Tau_LeadingCHCEta          , &b_Tau_LeadingCHCEta);
  fChain->SetBranchAddress("Tau_LeadingCHCPhi"           , &Tau_LeadingCHCPhi          , &b_Tau_LeadingCHCPhi);
  fChain->SetBranchAddress("Tau_LeadingCHCM"             , &Tau_LeadingCHCM            , &b_Tau_LeadingCHCM);
  fChain->SetBranchAddress("Tau_LeadingCHCE"             , &Tau_LeadingCHCE            , &b_Tau_LeadingCHCE);
  fChain->SetBranchAddress("Tau_LeadingCHCEt"            , &Tau_LeadingCHCEt           , &b_Tau_LeadingCHCEt);
  fChain->SetBranchAddress("Tau_LeadingCHCId"            , &Tau_LeadingCHCId           , &b_Tau_LeadingCHCId);
  fChain->SetBranchAddress("Tau_LeadingCHCCharge"        , &Tau_LeadingCHCCharge       , &b_Tau_LeadingCHCCharge);
  
  fChain->SetBranchAddress("Tau_LeadingCHCVx"            , &Tau_LeadingCHCVx           , &b_Tau_LeadingCHCVx);
  fChain->SetBranchAddress("Tau_LeadingCHCVy"            , &Tau_LeadingCHCVy           , &b_Tau_LeadingCHCVy);
  fChain->SetBranchAddress("Tau_LeadingCHCVz"            , &Tau_LeadingCHCVz           , &b_Tau_LeadingCHCVz);
  

  std::cout << "I N F O ! TreeDefinitionReco::InitReco(...) - Setting Jet addresses." << std::endl;
  //Jets
  fChain->SetBranchAddress("Jet_Pt"                        , &Jet_Pt                        , &b_Jet_Pt);
  fChain->SetBranchAddress("Jet_Eta"                       , &Jet_Eta                       , &b_Jet_Eta);
  fChain->SetBranchAddress("Jet_Phi"                       , &Jet_Phi                       , &b_Jet_Phi);
  fChain->SetBranchAddress("Jet_M"                         , &Jet_M                         , &b_Jet_M);
  fChain->SetBranchAddress("Jet_E"                         , &Jet_E                         , &b_Jet_E);
  fChain->SetBranchAddress("Jet_JetArea"                   , &Jet_JetArea                   , &b_Jet_JetArea);
  
  fChain->SetBranchAddress("Jet_ChargedMultiplicity"       , &Jet_ChargedMultiplicity       , &b_Jet_ChargedMultiplicity);
  fChain->SetBranchAddress("Jet_ChargedHadronMultiplicity" , &Jet_ChargedHadronMultiplicity , &b_Jet_ChargedHadronMultiplicity);
  fChain->SetBranchAddress("Jet_NeutralMultiplicity"       , &Jet_NeutralMultiplicity       , &b_Jet_NeutralMultiplicity);
  fChain->SetBranchAddress("Jet_NeutralHadronMultiplicity" , &Jet_NeutralHadronMultiplicity , &b_Jet_NeutralHadronMultiplicity);
  fChain->SetBranchAddress("Jet_ElectronMultiplicity"      , &Jet_ElectronMultiplicity      , &b_Jet_ElectronMultiplicity);
  fChain->SetBranchAddress("Jet_MuonMultiplicity"          , &Jet_MuonMultiplicity          , &b_Jet_MuonMultiplicity);
  fChain->SetBranchAddress("Jet_PhotonMultiplicity"        , &Jet_PhotonMultiplicity        , &b_Jet_PhotonMultiplicity);
  
  fChain->SetBranchAddress("Jet_NeutralEmEnergy"           , &Jet_NeutralEmEnergy           , &b_Jet_NeutralEmEnergy);
  fChain->SetBranchAddress("Jet_NeutralEmEnergyFraction"   , &Jet_NeutralEmEnergyFraction   , &b_Jet_NeutralEmEnergyFraction);
  fChain->SetBranchAddress("Jet_NeutralHadEnergy"          , &Jet_NeutralHadEnergy          , &b_Jet_NeutralHadEnergy);
  fChain->SetBranchAddress("Jet_NeutralHadEnergyFraction"  , &Jet_NeutralHadEnergyFraction  , &b_Jet_NeutralHadEnergyFraction);
  
  fChain->SetBranchAddress("Jet_ChargedEmEnergy"           , &Jet_ChargedEmEnergy           , &b_Jet_ChargedEmEnergy);
  fChain->SetBranchAddress("Jet_ChargedEmEnergyFraction"   , &Jet_ChargedEmEnergyFraction   , &b_Jet_ChargedEmEnergyFraction);
  fChain->SetBranchAddress("Jet_ChargedHadEnergy"          , &Jet_ChargedHadEnergy          , &b_Jet_ChargedHadEnergy);
  fChain->SetBranchAddress("Jet_ChargedHadEnergyFraction"  , &Jet_ChargedHadEnergyFraction  , &b_Jet_ChargedHadEnergyFraction);
  fChain->SetBranchAddress("Jet_ChargedMuEnergy"           , &Jet_ChargedMuEnergy           , &b_Jet_ChargedMuEnergy);
  fChain->SetBranchAddress("Jet_ChargedMuEnergyFraction"   , &Jet_ChargedMuEnergyFraction   , &b_Jet_ChargedMuEnergyFraction);
  
  fChain->SetBranchAddress("Jet_ElectronEnergy"            , &Jet_ElectronEnergy            , &b_Jet_ElectronEnergy);
  fChain->SetBranchAddress("Jet_ElectronEnergyFraction"    , &Jet_ElectronEnergyFraction    , &b_Jet_ElectronEnergyFraction);
  fChain->SetBranchAddress("Jet_MuonEnergy"                , &Jet_MuonEnergy                , &b_Jet_MuonEnergy);
  fChain->SetBranchAddress("Jet_MuonEnergyFraction"        , &Jet_MuonEnergyFraction        , &b_Jet_MuonEnergyFraction);
  fChain->SetBranchAddress("Jet_PhotonEnergy"              , &Jet_PhotonEnergy              , &b_Jet_PhotonEnergy);
  fChain->SetBranchAddress("Jet_PhotonEnergyFraction"      , &Jet_PhotonEnergyFraction      , &b_Jet_PhotonEnergyFraction);
  
  fChain->SetBranchAddress("Jet_bDis_JBP"                  , &Jet_bDis_JBP                  , &b_Jet_bDis_JBP);
  fChain->SetBranchAddress("Jet_bDis_JP"                   , &Jet_bDis_JP                   , &b_Jet_bDis_JP);
  fChain->SetBranchAddress("Jet_bDis_TCHP"                 , &Jet_bDis_TCHP                 , &b_Jet_bDis_TCHP);
  fChain->SetBranchAddress("Jet_bDis_TCHE"                 , &Jet_bDis_TCHE                 , &b_Jet_bDis_TCHE);
  fChain->SetBranchAddress("Jet_bDis_SVHP"                 , &Jet_bDis_SVHP                 , &b_Jet_bDis_SVHP);
  fChain->SetBranchAddress("Jet_bDis_SVHE"                 , &Jet_bDis_SVHE                 , &b_Jet_bDis_SVHE);
  fChain->SetBranchAddress("Jet_bDis_CMVA"                 , &Jet_bDis_CMVA                 , &b_Jet_bDis_CMVA);

  fChain->SetBranchAddress("Jet_bDis_CSV"                  , &Jet_bDis_CSV                  , &b_Jet_bDis_CSV);
  fChain->SetBranchAddress("Jet_bDis_CSV2"                 , &Jet_bDis_CSV2                 , &b_Jet_bDis_CSV2);
  fChain->SetBranchAddress("Jet_bDis_CISV2"                , &Jet_bDis_CISV2                , &b_Jet_bDis_CISV2);
  fChain->SetBranchAddress("Jet_bDis_CSVSL"                , &Jet_bDis_CSVSL                , &b_Jet_bDis_CSVSL);
   
  fChain->SetBranchAddress("Jet_HasGenJet"                 , &Jet_HasGenJet                 , &b_Jet_HasGenJet);
  fChain->SetBranchAddress("Jet_GenJet_Pt"                 , &Jet_GenJet_Pt                 , &b_Jet_GenJet_Pt);
  fChain->SetBranchAddress("Jet_GenJet_Eta"                , &Jet_GenJet_Eta                , &b_Jet_GenJet_Eta);
  fChain->SetBranchAddress("Jet_GenJet_Phi"                , &Jet_GenJet_Phi                , &b_Jet_GenJet_Phi);
  fChain->SetBranchAddress("Jet_GenJet_M"                  , &Jet_GenJet_M                  , &b_Jet_GenJet_M);
  fChain->SetBranchAddress("Jet_GenJet_E"                  , &Jet_GenJet_E                  , &b_Jet_GenJet_E);
  fChain->SetBranchAddress("Jet_GenJet_emE"                , &Jet_GenJet_emE                , &b_Jet_GenJet_emE);
  fChain->SetBranchAddress("Jet_GenJet_hadE"               , &Jet_GenJet_hadE               , &b_Jet_GenJet_hadE);
  fChain->SetBranchAddress("Jet_GenJet_invisibleE"         , &Jet_GenJet_invisibleE         , &b_Jet_GenJet_invisibleE);
  fChain->SetBranchAddress("Jet_GenPartonFlavour"          , &Jet_GenPartonFlavour          , &b_Jet_GenPartonFlavour);
  fChain->SetBranchAddress("Jet_GenHadronFlavour"          , &Jet_GenHadronFlavour          , &b_Jet_GenHadronFlavour);
  

  std::cout << "I N F O ! TreeDefinitionReco::InitReco(...) - Setting Vertex addresses." << std::endl;
  //Vertex and Primary Vertex
  fChain->SetBranchAddress("PV_X"               , &PV_X               , &b_PV_X);
  fChain->SetBranchAddress("PV_Y"               , &PV_Y               , &b_PV_Y);
  fChain->SetBranchAddress("PV_Z"               , &PV_Z               , &b_PV_Z);
  fChain->SetBranchAddress("Vertex_X"           , &Vertex_X           , &b_Vertex_X);
  fChain->SetBranchAddress("Vertex_ErrorX"      , &Vertex_ErrorX      , &b_Vertex_ErrorX);
  fChain->SetBranchAddress("Vertex_Y"           , &Vertex_Y           , &b_Vertex_Y);
  fChain->SetBranchAddress("Vertex_ErrorY"      , &Vertex_ErrorY      , &b_Vertex_ErrorY);
  fChain->SetBranchAddress("Vertex_Z"           , &Vertex_Z           , &b_Vertex_Z);
  fChain->SetBranchAddress("Vertex_ErrorZ"      , &Vertex_ErrorZ      , &b_Vertex_ErrorZ);
  fChain->SetBranchAddress("Vertex_Chi2"        , &Vertex_Chi2        , &b_Vertex_Chi2);
  fChain->SetBranchAddress("Vertex_DOF"         , &Vertex_DOF         , &b_Vertex_DOF);
  fChain->SetBranchAddress("Vertex_ReducedChi2" , &Vertex_ReducedChi2 , &b_Vertex_ReducedChi2);

  std::cout << "I N F O ! TreeDefinitionReco::InitReco(...) - Setting Pileup addresses." << std::endl;
  //PileUp
  fChain->SetBranchAddress("PU_Bx"         , &PU_Bx         , &b_PU_Bx);
  fChain->SetBranchAddress("PU_EventPU"    , &PU_EventPU    , &b_PU_EventPU);
  fChain->SetBranchAddress("PU_BxPU"       , &PU_BxPU       , &b_PU_BxPU);
  fChain->SetBranchAddress("PU_ZPositions" , &PU_ZPositions , &b_PU_ZPositions);


   Notify();
}

#endif // TreeDefinitionReco_h
