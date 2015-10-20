#ifndef TreeDefinitionReco_h
#define TreeDefinitionReco_h

#include "TreeDefinitionBase.h"

class TreeDefinitionReco : public virtual TreeDefinitionBase
{
  public:
    //Declaration of leaf types

  //Event tree
  //Event
  Int_t *RunNumber;
  Int_t *EvtNumber;

  //MET
  float *MET_Px;
  float *MET_Py;
  float *MET_Pt;
  float *MET_Phi;
  float *MET_SumEt;
  
  float *MET_UncorrectedPt;
  float *MET_UncorrectedPhi;
  float *MET_UncorrectedSumEt;
  
  float *MET_CaloMETPt;
  float *MET_CaloMETPhi;
  float *MET_CaloMETSumEt;

  //Electrons
  Int_t* Elec_N;
  std::vector<float> *Elec_Pt;
  std::vector<float> *Elec_Eta;
  std::vector<float> *Elec_Phi;
  std::vector<float> *Elec_M;
  std::vector<float> *Elec_E;
  std::vector<Int_t> *Elec_Id;
  std::vector<Int_t> *Elec_Charge;

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
  float *PV_X;
  float *PV_Y;
  float *PV_Z;
  std::vector<float> *Vertex_X;
  std::vector<float> *Vertex_ErrorX;
  std::vector<float> *Vertex_Y;
  std::vector<float> *Vertex_ErrorY;
  std::vector<float> *Vertex_Z;
  std::vector<float> *Vertex_ErrorZ;
  std::vector<float> *Vertex_Chi2;
  std::vector<float> *Vertex_DOF;
  std::vector<float> *Vertex_ReducedChi2;
   

   // List of branches
  //Event
  TBranch *b_RunNumber;
  TBranch *b_EvtNumber;

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
  //Event
  RunNumber = 0;
  EvtNumber = 0;

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




   std::cout << "I N F O ! TreeDefinitionReco::InitReco(...) - Setting branch addresses and branch pointers." << std::endl;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);




   //Event
  fChain->SetBranchAddress("RunNumber"               , &RunNumber               , &b_RunNumber);
  fChain->SetBranchAddress("EvtNumber"               , &EvtNumber               , &b_EvtNumber);

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

  //Electrons
  fChain->SetBranchAddress("Elec_N"               , &               , &b_);
  fChain->SetBranchAddress("Elec_Pt"               , &               , &b_);
  fChain->SetBranchAddress("Elec_Eta"               , &               , &b_);
  fChain->SetBranchAddress("Elec_Phi"               , &               , &b_);
  fChain->SetBranchAddress("Elec_M"               , &               , &b_);
  fChain->SetBranchAddress("Elec_E"               , &               , &b_);
  fChain->SetBranchAddress("Elec_Id"               , &               , &b_);
  fChain->SetBranchAddress("Elec_Charge"               , &               , &b_);
  
  fChain->SetBranchAddress("Elec_SCl_Eta"               , &               , &b_);
  fChain->SetBranchAddress("Elec_SCl_EtaWidth"               , &               , &b_);
  fChain->SetBranchAddress("Elec_SCl_Phi"               , &               , &b_);
  fChain->SetBranchAddress("Elec_SCl_PhiWidth"               , &               , &b_);
  fChain->SetBranchAddress("Elec_SCl_E"               , &               , &b_);
  fChain->SetBranchAddress("Elec_SCl_RawE"               , &               , &b_);
  fChain->SetBranchAddress("Elec_SCl_PreShowerE"               , &               , &b_);
  fChain->SetBranchAddress("Elec_SCl_PreShower1E"               , &               , &b_);
  fChain->SetBranchAddress("Elec_SCl_PreShower2E"               , &               , &b_);
  fChain->SetBranchAddress("Elec_SCl_PositionR"               , &               , &b_);
  
  fChain->SetBranchAddress("Elec_HasGsfTrack"               , &               , &b_);
  fChain->SetBranchAddress("Elec_GsfTrack_D0"               , &               , &b_);
  fChain->SetBranchAddress("Elec_GsfTrack_Z0"               , &               , &b_);
  fChain->SetBranchAddress("Elec_GsfTrack_D0Error"               , &               , &b_);
  fChain->SetBranchAddress("Elec_GsfTrack_Z0Error"               , &               , &b_);
  fChain->SetBranchAddress("Elec_GsfTrack_PV_Dxy"               , &               , &b_);
  fChain->SetBranchAddress("Elec_GsfTrack_PV_Z0"               , &               , &b_);
  fChain->SetBranchAddress("Elec_GsfTrack_RP_Dxy"               , &               , &b_);
  fChain->SetBranchAddress("Elec_GsfTrack_RP_Z0"               , &               , &b_);
  fChain->SetBranchAddress("Elec_GsfTrack_BS_Dxy"               , &               , &b_);
  fChain->SetBranchAddress("Elec_GsfTrack_BS_Z0"               , &               , &b_);
  fChain->SetBranchAddress("Elec_GsfTrack_DxyError"               , &               , &b_);
  //std::vector<Double_t> *Elec_GsfTrack_Z0Error;
  fChain->SetBranchAddress("Elec_GsfTrack_NormalizedChi2"               , &               , &b_);
  fChain->SetBranchAddress("Elec_IP3d"               , &               , &b_);
  fChain->SetBranchAddress("Elec_IP3dError"               , &               , &b_);
  fChain->SetBranchAddress("Elec_IP2d"               , &               , &b_);
  fChain->SetBranchAddress("Elec_IP2dError"               , &               , &b_);
  fChain->SetBranchAddress("Elec_IP3dBS"               , &               , &b_);
  fChain->SetBranchAddress("Elec_IP3dBSError"               , &               , &b_);
  fChain->SetBranchAddress("Elec_IP2dBS"               , &               , &b_);
  fChain->SetBranchAddress("Elec_IP2dBSError"               , &               , &b_);
  
  
  
  //Muons
  fChain->SetBranchAddress("Muon_Pt"               , &               , &b_);
  fChain->SetBranchAddress("Muon_Eta"               , &               , &b_);
  fChain->SetBranchAddress("Muon_Phi"               , &               , &b_);
  fChain->SetBranchAddress("Muon_M"               , &               , &b_);
  fChain->SetBranchAddress("Muon_E"               , &               , &b_);
  fChain->SetBranchAddress("Muon_Id"               , &               , &b_);
  fChain->SetBranchAddress("Muon_Charge"               , &               , &b_);
  
  fChain->SetBranchAddress("Muon_IP3d"               , &               , &b_);
  fChain->SetBranchAddress("Muon_IP3dError"               , &               , &b_);
  fChain->SetBranchAddress("Muon_IP2d"               , &               , &b_);
  fChain->SetBranchAddress("Muon_IP2dError"               , &               , &b_);
  fChain->SetBranchAddress("Muon_IP3dBS"               , &               , &b_);
  fChain->SetBranchAddress("Muon_IP3dBSError"               , &               , &b_);
  fChain->SetBranchAddress("Muon_IP2dBS"               , &               , &b_);
  fChain->SetBranchAddress("Muon_IP2dBSError"               , &               , &b_);
  
  fChain->SetBranchAddress("Muon_HasGlobalTrack"               , &               , &b_);
  fChain->SetBranchAddress("Muon_GlobalTrack_D0"               , &               , &b_);
  fChain->SetBranchAddress("Muon_GlobalTrack_Z0"               , &               , &b_);
  fChain->SetBranchAddress("Muon_GlobalTrack_D0Error"               , &               , &b_);
  fChain->SetBranchAddress("Muon_GlobalTrack_Z0Error"               , &               , &b_);
  fChain->SetBranchAddress("Muon_GlobalTrack_PV_Dxy"               , &               , &b_);
  fChain->SetBranchAddress("Muon_GlobalTrack_PV_Z0"               , &               , &b_);
  fChain->SetBranchAddress("Muon_GlobalTrack_RP_Dxy"               , &               , &b_);
  fChain->SetBranchAddress("Muon_GlobalTrack_RP_Z0"               , &               , &b_);
  fChain->SetBranchAddress("Muon_GlobalTrack_BS_Dxy"               , &               , &b_);
  fChain->SetBranchAddress("Muon_GlobalTrack_BS_Z0"               , &               , &b_);
  fChain->SetBranchAddress("Muon_GlobalTrack_DxyError"               , &               , &b_);
  //std::vector<Double_t> *Muon_GlobalTrack_Z0Error"               , &               , &b_);
  fChain->SetBranchAddress("Muon_GlobalTrack_NormalizedChi2"               , &               , &b_);
  fChain->SetBranchAddress("Muon_GlobalTrack_Pt"               , &               , &b_);
  fChain->SetBranchAddress("Muon_GlobalTrack_Eta"               , &               , &b_);
  fChain->SetBranchAddress("Muon_GlobalTrack_Phi"               , &               , &b_);
  fChain->SetBranchAddress("Muon_GlobalTrack_PtError"               , &               , &b_);
  fChain->SetBranchAddress("Muon_GlobalTrack_EtaError"               , &               , &b_);
  fChain->SetBranchAddress("Muon_GlobalTrack_PhiError"               , &               , &b_);
  fChain->SetBranchAddress("Muon_GlobalTrack_Charge"               , &               , &b_);
  
  fChain->SetBranchAddress("Muon_HasInnerTrack"               , &               , &b_);
  fChain->SetBranchAddress("Muon_InnerTrack_D0"               , &               , &b_);
  fChain->SetBranchAddress("Muon_InnerTrack_Z0"               , &               , &b_);
  fChain->SetBranchAddress("Muon_InnerTrack_D0Error"               , &               , &b_);
  fChain->SetBranchAddress("Muon_InnerTrack_Z0Error"               , &               , &b_);
  fChain->SetBranchAddress("Muon_InnerTrack_PV_Dxy"               , &               , &b_);
  fChain->SetBranchAddress("Muon_InnerTrack_PV_Z0"               , &               , &b_);
  fChain->SetBranchAddress("Muon_InnerTrack_RP_Dxy"               , &               , &b_);
  fChain->SetBranchAddress("Muon_InnerTrack_RP_Z0"               , &               , &b_);
  fChain->SetBranchAddress("Muon_InnerTrack_BS_Dxy"               , &               , &b_);
  fChain->SetBranchAddress("Muon_InnerTrack_BS_Z0"               , &               , &b_);
  fChain->SetBranchAddress("Muon_InnerTrack_DxyError"               , &               , &b_);
  //std::vector<Double_t> *Muon_InnerTrack_Z0Error;
  fChain->SetBranchAddress("Muon_InnerTrack_NormalizedChi2"               , &               , &b_);
  fChain->SetBranchAddress("Muon_InnerTrack_Pt"               , &               , &b_);
  fChain->SetBranchAddress("Muon_InnerTrack_Eta"               , &               , &b_);
  fChain->SetBranchAddress("Muon_InnerTrack_Phi"               , &               , &b_);
  fChain->SetBranchAddress("Muon_InnerTrack_PtError"               , &               , &b_);
  fChain->SetBranchAddress("Muon_InnerTrack_EtaError"               , &               , &b_);
  fChain->SetBranchAddress("Muon_InnerTrack_PhiError"               , &               , &b_);
  fChain->SetBranchAddress("Muon_InnerTrack_Charge"               , &               , &b_);

  fChain->SetBranchAddress("Muon_HasBestTrack"               , &               , &b_);
  fChain->SetBranchAddress("Muon_BestTrackType"               , &               , &b_);
  fChain->SetBranchAddress("Muon_BestTrack_D0"               , &               , &b_);
  fChain->SetBranchAddress("Muon_BestTrack_Z0"               , &               , &b_);
  fChain->SetBranchAddress("Muon_BestTrack_D0Error"               , &               , &b_);
  fChain->SetBranchAddress("Muon_BestTrack_Z0Error"               , &               , &b_);
  fChain->SetBranchAddress("Muon_BestTrack_PV_Dxy"               , &               , &b_);
  fChain->SetBranchAddress("Muon_BestTrack_PV_Z0"               , &               , &b_);
  fChain->SetBranchAddress("Muon_BestTrack_RP_Dxy"               , &               , &b_);
  fChain->SetBranchAddress("Muon_BestTrack_RP_Z0"               , &               , &b_);
  fChain->SetBranchAddress("Muon_BestTrack_BS_Dxy"               , &               , &b_);
  fChain->SetBranchAddress("Muon_BestTrack_BS_Z0"               , &               , &b_);
  fChain->SetBranchAddress("Muon_BestTrack_DxyError"               , &               , &b_);
  //std::vector<Double_t> *Muon_BestTrack_Z0Error;
  fChain->SetBranchAddress("Muon_BestTrack_NormalizedChi2"               , &               , &b_);
  fChain->SetBranchAddress("Muon_BestTrack_Pt"               , &               , &b_);
  fChain->SetBranchAddress("Muon_BestTrack_Eta"               , &               , &b_);
  fChain->SetBranchAddress("Muon_BestTrack_Phi"               , &               , &b_);
  fChain->SetBranchAddress("Muon_BestTrack_PtError"               , &               , &b_);
  fChain->SetBranchAddress("Muon_BestTrack_EtaError"               , &               , &b_);
  fChain->SetBranchAddress("Muon_BestTrack_PhiError"               , &               , &b_);
  fChain->SetBranchAddress("Muon_BestTrack_Charge"               , &               , &b_);

  
  //Taus
  fChain->SetBranchAddress("Tau_Pt"               , &               , &b_);
  fChain->SetBranchAddress("Tau_Eta"               , &               , &b_);
  fChain->SetBranchAddress("Tau_Phi"               , &               , &b_);
  fChain->SetBranchAddress("Tau_M"               , &               , &b_);
  fChain->SetBranchAddress("Tau_E"               , &               , &b_);
  fChain->SetBranchAddress("Tau_Id"               , &               , &b_);
  fChain->SetBranchAddress("Tau_Charge"               , &               , &b_);
  
  fChain->SetBranchAddress("Tau_DecayMode"               , &               , &b_);
  fChain->SetBranchAddress("Tau_IsCaloTau"               , &               , &b_);

  fChain->SetBranchAddress("Tau_hasLeadChargedHadrCand"               , &               , &b_);
  fChain->SetBranchAddress("Tau_LeadingCHCPt"               , &               , &b_);
  fChain->SetBranchAddress("Tau_LeadingCHCEta"               , &               , &b_);
  fChain->SetBranchAddress("Tau_LeadingCHCPhi"               , &               , &b_);
  fChain->SetBranchAddress("Tau_LeadingCHCM"               , &               , &b_);
  fChain->SetBranchAddress("Tau_LeadingCHCE"               , &               , &b_);
  fChain->SetBranchAddress("Tau_LeadingCHCEt"               , &               , &b_);
  fChain->SetBranchAddress("Tau_LeadingCHCId"               , &               , &b_);
  fChain->SetBranchAddress("Tau_LeadingCHCCharge"               , &               , &b_);
  
  fChain->SetBranchAddress("Tau_LeadingCHCVx"               , &               , &b_);
  fChain->SetBranchAddress("Tau_LeadingCHCVy"               , &               , &b_);
  fChain->SetBranchAddress("Tau_LeadingCHCVz"               , &               , &b_);
  
  //Jets
  fChain->SetBranchAddress("Jet_Pt"               , &               , &b_);
  fChain->SetBranchAddress("Jet_Eta"               , &               , &b_);
  fChain->SetBranchAddress("Jet_Phi"               , &               , &b_);
  fChain->SetBranchAddress("Jet_M"               , &               , &b_);
  fChain->SetBranchAddress("Jet_E"               , &               , &b_);
  fChain->SetBranchAddress("Jet_JetArea"               , &               , &b_);
  
  fChain->SetBranchAddress("Jet_ChargedMultiplicity"               , &               , &b_);
  fChain->SetBranchAddress("Jet_ChargedHadronMultiplicity"               , &               , &b_);
  fChain->SetBranchAddress("Jet_NeutralMultiplicity"               , &               , &b_);
  fChain->SetBranchAddress("Jet_NeutralHadronMultiplicity"               , &               , &b_);
  fChain->SetBranchAddress("Jet_ElectronMultiplicity"               , &               , &b_);
  fChain->SetBranchAddress("Jet_MuonMultiplicity"               , &               , &b_);
  fChain->SetBranchAddress("Jet_PhotonMultiplicity"               , &               , &b_);
  
  fChain->SetBranchAddress("Jet_NeutralEmEnergy"               , &               , &b_);
  fChain->SetBranchAddress("Jet_NeutralEmEnergyFraction"               , &               , &b_);
  fChain->SetBranchAddress("Jet_NeutralHadEnergy"               , &               , &b_);
  fChain->SetBranchAddress("Jet_NeutralHadEnergyFraction"               , &               , &b_);
  
  fChain->SetBranchAddress("Jet_ChargedEmEnergy"               , &               , &b_);
  fChain->SetBranchAddress("Jet_ChargedEmEnergyFraction"               , &               , &b_);
  fChain->SetBranchAddress("Jet_ChargedHadEnergy"               , &               , &b_);
  fChain->SetBranchAddress("Jet_ChargedHadEnergyFraction"               , &               , &b_);
  fChain->SetBranchAddress("Jet_ChargedMuEnergy"               , &               , &b_);
  fChain->SetBranchAddress("Jet_ChargedMuEnergyFraction"               , &               , &b_);
  
  fChain->SetBranchAddress("Jet_ElectronEnergy"               , &               , &b_);
  fChain->SetBranchAddress("Jet_ElectronEnergyFraction"               , &               , &b_);
  fChain->SetBranchAddress("Jet_MuonEnergy"               , &               , &b_);
  fChain->SetBranchAddress("Jet_MuonEnergyFraction"               , &               , &b_);
  fChain->SetBranchAddress("Jet_PhotonEnergy"               , &               , &b_);
  fChain->SetBranchAddress("Jet_PhotonEnergyFraction"               , &               , &b_);
  
  fChain->SetBranchAddress("Jet_bDis_JBP"               , &               , &b_);
  fChain->SetBranchAddress("Jet_bDis_JP"               , &               , &b_);
  fChain->SetBranchAddress("Jet_bDis_TCHP"               , &               , &b_);
  fChain->SetBranchAddress("Jet_bDis_TCHE"               , &               , &b_);
  fChain->SetBranchAddress("Jet_bDis_SVHP"               , &               , &b_);
  fChain->SetBranchAddress("Jet_bDis_SVHE"               , &               , &b_);
  fChain->SetBranchAddress("Jet_bDis_CMVA"               , &               , &b_);
  
  fChain->SetBranchAddress("Jet_HasGenJet"               , &               , &b_);
  fChain->SetBranchAddress("Jet_GenJet_Pt"               , &               , &b_);
  fChain->SetBranchAddress("Jet_GenJet_Eta"               , &               , &b_);
  fChain->SetBranchAddress("Jet_GenJet_Phi"               , &               , &b_);
  fChain->SetBranchAddress("Jet_GenJet_M"               , &               , &b_);
  fChain->SetBranchAddress("Jet_GenJet_E"               , &               , &b_);
  fChain->SetBranchAddress("Jet_GenJet_emE"               , &               , &b_);
  fChain->SetBranchAddress("Jet_GenJet_hadE"               , &               , &b_);
  fChain->SetBranchAddress("Jet_GenJet_invisibleE"               , &               , &b_);
  fChain->SetBranchAddress("Jet_GenPartonFlavour"               , &               , &b_);
  fChain->SetBranchAddress("Jet_GenHadronFlavour"               , &               , &b_);
  
  //Vertex and Primary Vertex
  fChain->SetBranchAddress("PV_X"               , &               , &b_);
  fChain->SetBranchAddress("PV_Y"               , &               , &b_);
  fChain->SetBranchAddress("PV_Z"               , &               , &b_);
  fChain->SetBranchAddress("Vertex_X"               , &               , &b_);
  fChain->SetBranchAddress("Vertex_ErrorX"               , &               , &b_);
  fChain->SetBranchAddress("Vertex_Y"               , &               , &b_);
  fChain->SetBranchAddress("Vertex_ErrorY"               , &               , &b_);
  fChain->SetBranchAddress("Vertex_Z"               , &               , &b_);
  fChain->SetBranchAddress("Vertex_ErrorZ"               , &               , &b_);
  fChain->SetBranchAddress("Vertex_Chi2"               , &               , &b_);
  fChain->SetBranchAddress("Vertex_DOF"               , &               , &b_);
  fChain->SetBranchAddress("Vertex_ReducedChi2"               , &               , &b_);



   std::cout << "I N F O ! TreeDefinitionReco::InitReco(...) - Setting L1 Calo Tau addresses." << std::endl;


   std::cout << "I N F O ! TreeDefinitionReco::InitReco(...) - Setting L1 Jet addresses." << std::endl;


   Notify();
}

#endif // TreeDefinitionReco_h
