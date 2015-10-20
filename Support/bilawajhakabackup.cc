// -*- C++ -*-
// ttH Leptonic
// Author: Ather Mohsan Waseem (mather@cern.ch)
// University of Cyprus
// Package:    IPHCFlatTree/MyNtupleMaker
// Class:      MyNtupleMaker
// 
/**\class MyNtupleMaker MyNtupleMaker.cc IPHCFlatTree/MyNtupleMaker/plugins/MyNtupleMaker.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Mohsan Waseem Ather
//         Created:  Tue, 16 Jun 2015 13:59:29 GMT
//
//

#include <memory>
#include <iostream>
#include <sstream>

#include <vector>


#include "FWCore/Common/interface/TriggerNames.h"
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
#include "SimDataFormats/GeneratorProducts/interface/GenEventInfoProduct.h"
#include "SimDataFormats/PileupSummaryInfo/interface/PileupSummaryInfo.h"
#include "SimDataFormats/GeneratorProducts/interface/LHEEventProduct.h"
#include "SimDataFormats/GeneratorProducts/interface/HepMCProduct.h"
#include "SimDataFormats/JetMatching/interface/JetFlavourMatching.h"

#include "DataFormats/Common/interface/TriggerResults.h"
#include "DataFormats/PatCandidates/interface/PackedTriggerPrescales.h"

#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/PatCandidates/interface/Electron.h"
#include "DataFormats/PatCandidates/interface/Muon.h"
#include "DataFormats/PatCandidates/interface/Tau.h"
#include "DataFormats/PatCandidates/interface/Jet.h"
#include "DataFormats/PatCandidates/interface/MET.h"
#include "DataFormats/PatCandidates/interface/TriggerObjectStandAlone.h"

#include "DataFormats/METReco/interface/SpecificGenMETData.h"
#include "DataFormats/METReco/interface/MET.h"

#include "DataFormats/Math/interface/deltaR.h"

#include "IPHCFlatTree/FlatTreeProducer/interface/tinyxml2.h"

#include "IPHCFlatTree/FlatTreeProducer/interface/FlatTree.hh"
#include "IPHCFlatTree/FlatTreeProducer/interface/MCTruth.hh"

//#include "EgammaAnalysis/ElectronTools/interface/EGammaMvaEleEstimatorCSA14.h"

#include "RecoEgamma/EgammaTools/interface/ConversionTools.h"

#include "TMVA/Tools.h"
#include "TMVA/Reader.h"
#include "TMVA/MethodCuts.h"
#include "TFile.h"
#include "TThreadSlots.h"
#include "TROOT.h"
#include "Compression.h"

using namespace std;
#include <vector>


//
// class declaration
//

class MyNtupleMaker : public edm::EDAnalyzer {
   public:
      explicit MyNtupleMaker(const edm::ParameterSet&);
      ~MyNtupleMaker();

      static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);


   private:
      virtual void beginJob() override;
      virtual void analyze(const edm::Event&, const edm::EventSetup&) override;
      virtual void endJob() override;

  void InitializeContainers(void);

      //virtual void beginRun(edm::Run const&, edm::EventSetup const&) override;
      //virtual void endRun(edm::Run const&, edm::EventSetup const&) override;
      //virtual void beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&) override;
      //virtual void endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&) override;

      // ----------member data ---------------------------

  //Tree
  TTree* EvtTree;
  const edm::Service<TFileService> fs;


  //Event
  Int_t RunNumber;
  Int_t EvtNumber;

  //MET
  // Double_t MET_Px;
  // Double_t MET_Py;
  // Double_t MET_Pt;
  // Double_t MET_Phi;
  // Double_t MET_SumEt;
  
  // Double_t MET_UncorrectedPt;
  // Double_t MET_UncorrectedPhi;
  // Double_t MET_UncorrectedSumEt;
  
  // Double_t MET_CaloMETPt;
  // Double_t MET_CaloMETPhi;
  // Double_t MET_CaloMETSumEt;

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

  //GenJets
  // Int_t                                      GenJet_N;
  // std::vector<Double_t>                      GenJet_Pt;
  // std::vector<Double_t>                      GenJet_Eta;
  // std::vector<Double_t>                      GenJet_Phi;
  // std::vector<Double_t>                      GenJet_M;
  // std::vector<Double_t>                      GenJet_E;
  // std::vector<Double_t>                      GenJet_emE;
  // std::vector<Double_t>                      GenJet_hadE;
  // std::vector<Double_t>                      GenJet_invE;
  // std::vector<Double_t>                      GenJet_auxE;
  // std::vector<Double_t>                      GenJet_VertexX;
  // std::vector<Double_t>                      GenJet_VertexY;
  // std::vector<Double_t>                      GenJet_VertexZ;
  // std::vector<vector<Int_t > >               GenJet_GenpPdgId;
  // std::vector<vector<Double_t > >            GenJet_GenpPt;
  // std::vector<vector<Double_t > >            GenJet_GenpEta;
  // std::vector<vector<Double_t > >            GenJet_GenpPhi;
  // std::vector<vector<Double_t > >            GenJet_GenpE;

  Int_t                                   GenJet_N;
  std::vector<float>                      GenJet_Pt;
  std::vector<float>                      GenJet_Eta;
  std::vector<float>                      GenJet_Phi;
  std::vector<float>                      GenJet_M;
  std::vector<float>                      GenJet_E;
  std::vector<float>                      GenJet_emE;
  std::vector<float>                      GenJet_hadE;
  std::vector<float>                      GenJet_invE;
  std::vector<float>                      GenJet_auxE;
  std::vector<float>                      GenJet_VertexX;
  std::vector<float>                      GenJet_VertexY;
  std::vector<float>                      GenJet_VertexZ;
  std::vector<vector<Int_t > >            GenJet_GenpPdgId;
  std::vector<vector<float > >            GenJet_GenpPt;
  std::vector<vector<float > >            GenJet_GenpEta;
  std::vector<vector<float > >            GenJet_GenpPhi;
  std::vector<vector<float > >            GenJet_GenpE;
  

  //Genp
  // Int_t                                      GenP_N;
  // std::vector<Double_t>                      GenP_Pt;
  // std::vector<Double_t>                      GenP_Eta;
  // std::vector<Double_t>                      GenP_Phi;
  // std::vector<Double_t>                      GenP_M;
  // std::vector<Double_t>                      GenP_E;
  // std::vector<Int_t>                         GenP_PdgId;
  // std::vector<Int_t>                         GenP_Charge;
  // std::vector<Int_t>                         GenP_Status;
  // std::vector<Double_t>                      GenP_VertexX;
  // std::vector<Double_t>                      GenP_VertexY;
  // std::vector<Double_t>                      GenP_VertexZ;
  // std::vector< std::vector<unsigned short> > GenP_Mothers;
  // std::vector< std::vector<unsigned short> > GenP_Daughters;
  
  Int_t                                      GenP_N;
  std::vector<float>                      GenP_Pt;
  std::vector<float>                      GenP_Eta;
  std::vector<float>                      GenP_Phi;
  std::vector<float>                      GenP_M;
  std::vector<float>                      GenP_E;
  std::vector<Int_t>                         GenP_PdgId;
  std::vector<Int_t>                         GenP_Charge;
  std::vector<Int_t>                         GenP_Status;
  std::vector<float>                      GenP_VertexX;
  std::vector<float>                      GenP_VertexY;
  std::vector<float>                      GenP_VertexZ;
  std::vector< std::vector<unsigned short> > GenP_Mothers;
  std::vector< std::vector<unsigned short> > GenP_Daughters;


  //Electrons
  // Int_t Elec_N;
  // std::vector<Double_t> Elec_Pt;
  // std::vector<Double_t> Elec_Eta;
  // std::vector<Double_t> Elec_Phi;
  // std::vector<Double_t> Elec_M;
  // std::vector<Double_t> Elec_E;
  // std::vector<Int_t>    Elec_Id;
  // std::vector<Int_t>    Elec_Charge;

  // std::vector<Double_t> Elec_SCl_Eta;
  // std::vector<Double_t> Elec_SCl_EtaWidth;
  // std::vector<Double_t> Elec_SCl_Phi;
  // std::vector<Double_t> Elec_SCl_PhiWidth;
  // std::vector<Double_t> Elec_SCl_E;
  // std::vector<Double_t> Elec_SCl_RawE;
  // std::vector<Double_t> Elec_SCl_PreShowerE;
  // std::vector<Double_t> Elec_SCl_PreShower1E;
  // std::vector<Double_t> Elec_SCl_PreShower2E;
  // std::vector<Double_t> Elec_SCl_PositionR;
  
  // std::vector<Bool_t>   Elec_HasGsfTrack;
  // std::vector<Double_t> Elec_GsfTrack_D0;
  // std::vector<Double_t> Elec_GsfTrack_Z0;
  // std::vector<Double_t> Elec_GsfTrack_D0Error;
  // std::vector<Double_t> Elec_GsfTrack_Z0Error;
  // std::vector<Double_t> Elec_GsfTrack_PV_Dxy;
  // std::vector<Double_t> Elec_GsfTrack_PV_Z0;
  // std::vector<Double_t> Elec_GsfTrack_RP_Dxy;
  // std::vector<Double_t> Elec_GsfTrack_RP_Z0;
  // std::vector<Double_t> Elec_GsfTrack_BS_Dxy;
  // std::vector<Double_t> Elec_GsfTrack_BS_Z0;
  // std::vector<Double_t> Elec_GsfTrack_DxyError;
  // //std::vector<Double_t> Elec_GsfTrack_Z0Error;
  // std::vector<Double_t> Elec_GsfTrack_NormalizedChi2;
  // std::vector<Double_t> Elec_IP3d;
  // std::vector<Double_t> Elec_IP3dError;
  // std::vector<Double_t> Elec_IP2d;
  // std::vector<Double_t> Elec_IP2dError;
  // std::vector<Double_t> Elec_IP3dBS;
  // std::vector<Double_t> Elec_IP3dBSError;
  // std::vector<Double_t> Elec_IP2dBS;
  // std::vector<Double_t> Elec_IP2dBSError;

  Int_t Elec_N;
  std::vector<float> Elec_Pt;
  std::vector<float> Elec_Eta;
  std::vector<float> Elec_Phi;
  std::vector<float> Elec_M;
  std::vector<float> Elec_E;
  std::vector<Int_t>    Elec_Id;
  std::vector<Int_t>    Elec_Charge;

  std::vector<float> Elec_SCl_Eta;
  std::vector<float> Elec_SCl_EtaWidth;
  std::vector<float> Elec_SCl_Phi;
  std::vector<float> Elec_SCl_PhiWidth;
  std::vector<float> Elec_SCl_E;
  std::vector<float> Elec_SCl_RawE;
  std::vector<float> Elec_SCl_PreShowerE;
  std::vector<float> Elec_SCl_PreShower1E;
  std::vector<float> Elec_SCl_PreShower2E;
  std::vector<float> Elec_SCl_PositionR;
  
  std::vector<Bool_t>   Elec_HasGsfTrack;
  std::vector<float> Elec_GsfTrack_D0;
  std::vector<float> Elec_GsfTrack_Z0;
  std::vector<float> Elec_GsfTrack_D0Error;
  std::vector<float> Elec_GsfTrack_Z0Error;
  std::vector<float> Elec_GsfTrack_PV_Dxy;
  std::vector<float> Elec_GsfTrack_PV_Z0;
  std::vector<float> Elec_GsfTrack_RP_Dxy;
  std::vector<float> Elec_GsfTrack_RP_Z0;
  std::vector<float> Elec_GsfTrack_BS_Dxy;
  std::vector<float> Elec_GsfTrack_BS_Z0;
  std::vector<float> Elec_GsfTrack_DxyError;
  //std::vector<Double_t> Elec_GsfTrack_Z0Error;
  std::vector<float> Elec_GsfTrack_NormalizedChi2;
  std::vector<float> Elec_IP3d;
  std::vector<float> Elec_IP3dError;
  std::vector<float> Elec_IP2d;
  std::vector<float> Elec_IP2dError;
  std::vector<float> Elec_IP3dBS;
  std::vector<float> Elec_IP3dBSError;
  std::vector<float> Elec_IP2dBS;
  std::vector<float> Elec_IP2dBSError;



  //Muons
  // std::vector<Double_t> Muon_Pt;
  // std::vector<Double_t> Muon_Eta;
  // std::vector<Double_t> Muon_Phi;
  // std::vector<Double_t> Muon_M;
  // std::vector<Double_t> Muon_E;
  // std::vector<Int_t>    Muon_Id;
  // std::vector<Int_t>    Muon_Charge;

  // std::vector<Double_t> Muon_IP3d;
  // std::vector<Double_t> Muon_IP3dError;
  // std::vector<Double_t> Muon_IP2d;
  // std::vector<Double_t> Muon_IP2dError;
  // std::vector<Double_t> Muon_IP3dBS;
  // std::vector<Double_t> Muon_IP3dBSError;
  // std::vector<Double_t> Muon_IP2dBS;
  // std::vector<Double_t> Muon_IP2dBSError;

  // std::vector<Bool_t> Muon_HasGlobalTrack;
  // std::vector<Double_t> Muon_GlobalTrack_D0;
  // std::vector<Double_t> Muon_GlobalTrack_Z0;
  // std::vector<Double_t> Muon_GlobalTrack_D0Error;
  // std::vector<Double_t> Muon_GlobalTrack_Z0Error;
  // std::vector<Double_t> Muon_GlobalTrack_PV_Dxy;
  // std::vector<Double_t> Muon_GlobalTrack_PV_Z0;
  // std::vector<Double_t> Muon_GlobalTrack_RP_Dxy;
  // std::vector<Double_t> Muon_GlobalTrack_RP_Z0;
  // std::vector<Double_t> Muon_GlobalTrack_BS_Dxy;
  // std::vector<Double_t> Muon_GlobalTrack_BS_Z0;
  // std::vector<Double_t> Muon_GlobalTrack_DxyError;
  // //std::vector<Double_t> Muon_GlobalTrack_Z0Error;
  // std::vector<Double_t> Muon_GlobalTrack_NormalizedChi2;
  // std::vector<Double_t> Muon_GlobalTrack_Pt;
  // std::vector<Double_t> Muon_GlobalTrack_Eta;
  // std::vector<Double_t> Muon_GlobalTrack_Phi;
  // std::vector<Double_t> Muon_GlobalTrack_PtError;
  // std::vector<Double_t> Muon_GlobalTrack_EtaError;
  // std::vector<Double_t> Muon_GlobalTrack_PhiError;
  // std::vector<Double_t> Muon_GlobalTrack_Charge;

  // std::vector<Bool_t>   Muon_HasInnerTrack;
  // std::vector<Double_t> Muon_InnerTrack_D0;
  // std::vector<Double_t> Muon_InnerTrack_Z0;
  // std::vector<Double_t> Muon_InnerTrack_D0Error;
  // std::vector<Double_t> Muon_InnerTrack_Z0Error;
  // std::vector<Double_t> Muon_InnerTrack_PV_Dxy;
  // std::vector<Double_t> Muon_InnerTrack_PV_Z0;
  // std::vector<Double_t> Muon_InnerTrack_RP_Dxy;
  // std::vector<Double_t> Muon_InnerTrack_RP_Z0;
  // std::vector<Double_t> Muon_InnerTrack_BS_Dxy;
  // std::vector<Double_t> Muon_InnerTrack_BS_Z0;
  // std::vector<Double_t> Muon_InnerTrack_DxyError;
  // //std::vector<Double_t> Muon_InnerTrack_Z0Error;
  // std::vector<Double_t> Muon_InnerTrack_NormalizedChi2;
  // std::vector<Double_t> Muon_InnerTrack_Pt;
  // std::vector<Double_t> Muon_InnerTrack_Eta;
  // std::vector<Double_t> Muon_InnerTrack_Phi;
  // std::vector<Double_t> Muon_InnerTrack_PtError;
  // std::vector<Double_t> Muon_InnerTrack_EtaError;
  // std::vector<Double_t> Muon_InnerTrack_PhiError;
  // std::vector<Double_t> Muon_InnerTrack_Charge;

  // std::vector<Bool_t>   Muon_HasBestTrack;
  // std::vector<Double_t> Muon_BestTrackType;
  // std::vector<Double_t> Muon_BestTrack_D0;
  // std::vector<Double_t> Muon_BestTrack_Z0;
  // std::vector<Double_t> Muon_BestTrack_D0Error;
  // std::vector<Double_t> Muon_BestTrack_Z0Error;
  // std::vector<Double_t> Muon_BestTrack_PV_Dxy;
  // std::vector<Double_t> Muon_BestTrack_PV_Z0;
  // std::vector<Double_t> Muon_BestTrack_RP_Dxy;
  // std::vector<Double_t> Muon_BestTrack_RP_Z0;
  // std::vector<Double_t> Muon_BestTrack_BS_Dxy;
  // std::vector<Double_t> Muon_BestTrack_BS_Z0;
  // std::vector<Double_t> Muon_BestTrack_DxyError;
  // //std::vector<Double_t> Muon_BestTrack_Z0Error;
  // std::vector<Double_t> Muon_BestTrack_NormalizedChi2;
  // std::vector<Double_t> Muon_BestTrack_Pt;
  // std::vector<Double_t> Muon_BestTrack_Eta;
  // std::vector<Double_t> Muon_BestTrack_Phi;
  // std::vector<Double_t> Muon_BestTrack_PtError;
  // std::vector<Double_t> Muon_BestTrack_EtaError;
  // std::vector<Double_t> Muon_BestTrack_PhiError;
  // std::vector<Double_t> Muon_BestTrack_Charge;


  std::vector<float> Muon_Pt;
  std::vector<float> Muon_Eta;
  std::vector<float> Muon_Phi;
  std::vector<float> Muon_M;
  std::vector<float> Muon_E;
  std::vector<Int_t>    Muon_Id;
  std::vector<Int_t>    Muon_Charge;

  std::vector<float> Muon_IP3d;
  std::vector<float> Muon_IP3dError;
  std::vector<float> Muon_IP2d;
  std::vector<float> Muon_IP2dError;
  std::vector<float> Muon_IP3dBS;
  std::vector<float> Muon_IP3dBSError;
  std::vector<float> Muon_IP2dBS;
  std::vector<float> Muon_IP2dBSError;

  std::vector<Bool_t> Muon_HasGlobalTrack;
  std::vector<float> Muon_GlobalTrack_D0;
  std::vector<float> Muon_GlobalTrack_Z0;
  std::vector<float> Muon_GlobalTrack_D0Error;
  std::vector<float> Muon_GlobalTrack_Z0Error;
  std::vector<float> Muon_GlobalTrack_PV_Dxy;
  std::vector<float> Muon_GlobalTrack_PV_Z0;
  std::vector<float> Muon_GlobalTrack_RP_Dxy;
  std::vector<float> Muon_GlobalTrack_RP_Z0;
  std::vector<float> Muon_GlobalTrack_BS_Dxy;
  std::vector<float> Muon_GlobalTrack_BS_Z0;
  std::vector<float> Muon_GlobalTrack_DxyError;
  //std::vector<Double_t> Muon_GlobalTrack_Z0Error;
  std::vector<float> Muon_GlobalTrack_NormalizedChi2;
  std::vector<float> Muon_GlobalTrack_Pt;
  std::vector<float> Muon_GlobalTrack_Eta;
  std::vector<float> Muon_GlobalTrack_Phi;
  std::vector<float> Muon_GlobalTrack_PtError;
  std::vector<float> Muon_GlobalTrack_EtaError;
  std::vector<float> Muon_GlobalTrack_PhiError;
  std::vector<float> Muon_GlobalTrack_Charge;

  std::vector<Bool_t>   Muon_HasInnerTrack;
  std::vector<float> Muon_InnerTrack_D0;
  std::vector<float> Muon_InnerTrack_Z0;
  std::vector<float> Muon_InnerTrack_D0Error;
  std::vector<float> Muon_InnerTrack_Z0Error;
  std::vector<float> Muon_InnerTrack_PV_Dxy;
  std::vector<float> Muon_InnerTrack_PV_Z0;
  std::vector<float> Muon_InnerTrack_RP_Dxy;
  std::vector<float> Muon_InnerTrack_RP_Z0;
  std::vector<float> Muon_InnerTrack_BS_Dxy;
  std::vector<float> Muon_InnerTrack_BS_Z0;
  std::vector<float> Muon_InnerTrack_DxyError;
  //std::vector<Double_t> Muon_InnerTrack_Z0Error;
  std::vector<float> Muon_InnerTrack_NormalizedChi2;
  std::vector<float> Muon_InnerTrack_Pt;
  std::vector<float> Muon_InnerTrack_Eta;
  std::vector<float> Muon_InnerTrack_Phi;
  std::vector<float> Muon_InnerTrack_PtError;
  std::vector<float> Muon_InnerTrack_EtaError;
  std::vector<float> Muon_InnerTrack_PhiError;
  std::vector<float> Muon_InnerTrack_Charge;

  std::vector<Bool_t>   Muon_HasBestTrack;
  std::vector<float> Muon_BestTrackType;
  std::vector<float> Muon_BestTrack_D0;
  std::vector<float> Muon_BestTrack_Z0;
  std::vector<float> Muon_BestTrack_D0Error;
  std::vector<float> Muon_BestTrack_Z0Error;
  std::vector<float> Muon_BestTrack_PV_Dxy;
  std::vector<float> Muon_BestTrack_PV_Z0;
  std::vector<float> Muon_BestTrack_RP_Dxy;
  std::vector<float> Muon_BestTrack_RP_Z0;
  std::vector<float> Muon_BestTrack_BS_Dxy;
  std::vector<float> Muon_BestTrack_BS_Z0;
  std::vector<float> Muon_BestTrack_DxyError;
  //std::vector<Double_t> Muon_BestTrack_Z0Error;
  std::vector<float> Muon_BestTrack_NormalizedChi2;
  std::vector<float> Muon_BestTrack_Pt;
  std::vector<float> Muon_BestTrack_Eta;
  std::vector<float> Muon_BestTrack_Phi;
  std::vector<float> Muon_BestTrack_PtError;
  std::vector<float> Muon_BestTrack_EtaError;
  std::vector<float> Muon_BestTrack_PhiError;
  std::vector<float> Muon_BestTrack_Charge;

  
  //Taus
  // std::vector<Double_t> Tau_Pt;
  // std::vector<Double_t> Tau_Eta;
  // std::vector<Double_t> Tau_Phi;
  // std::vector<Double_t> Tau_M;
  // std::vector<Double_t> Tau_E;
  // std::vector<Int_t>    Tau_Id;
  // std::vector<Int_t>    Tau_Charge;

  std::vector<float> Tau_Pt;
  std::vector<float> Tau_Eta;
  std::vector<float> Tau_Phi;
  std::vector<float> Tau_M;
  std::vector<float> Tau_E;
  std::vector<Int_t> Tau_Id;
  std::vector<Int_t> Tau_Charge;

  std::vector<Int_t> Tau_DecayMode;
  std::vector<bool>  Tau_IsCaloTau;

  std::vector<bool> Tau_hasLeadChargedHadrCand;
  std::vector<float> Tau_LeadingTrackPt;
  std::vector<float> Tau_LeadingTrackEta;
  std::vector<float> Tau_LeadingTrackPhi;
  std::vector<float> Tau_LeadingTrackM;
  std::vector<float> Tau_LeadingTrackE;
  std::vector<float> Tau_LeadingTrackEt;
  std::vector<Int_t> Tau_LeadingTrackId;
  std::vector<Int_t> Tau_LeadingTrackCharge;




  //Jets
  // std::vector<Double_t> Jet_Pt;
  // std::vector<Double_t> Jet_Eta;
  // std::vector<Double_t> Jet_Phi;
  // std::vector<Double_t> Jet_M;
  // std::vector<Double_t> Jet_E;
  // std::vector<Double_t> Jet_JetArea;
  // std::vector<Int_t>    Jet_nTks;
  // std::vector<Int_t>    Jet_ChargedMultiplicity;
  // std::vector<Int_t>    Jet_NeutralMultiplicity;
  // std::vector<Double_t> Jet_NeutralHadronEnergyFraction;
  // std::vector<Double_t> Jet_NeutralEmEnergyFraction;
  // std::vector<Double_t> Jet_ChargedHadronEnergyFraction;
  // std::vector<Double_t> Jet_MuonEnergyFraction;
  // std::vector<Double_t> Jet_ChargedEmEnergyFraction;

  // std::vector<Double_t> Jet_bDis_JBP;
  // std::vector<Double_t> Jet_bDis_JP;
  // std::vector<Double_t> Jet_bDis_TCHP;
  // std::vector<Double_t> Jet_bDis_TCHE;
  // std::vector<Double_t> Jet_bDis_SVHP;
  // std::vector<Double_t> Jet_bDis_SVHE;
  // std::vector<Double_t> Jet_bDis_CMVA;

  // std::vector<Bool_t>   Jet_HasGenJet;
  // std::vector<Double_t> Jet_GenJet_Pt;
  // std::vector<Double_t> Jet_GenJet_Eta;
  // std::vector<Double_t> Jet_GenJet_Phi;
  // std::vector<Double_t> Jet_GenJet_M;
  // std::vector<Double_t> Jet_GenJet_E;
  // std::vector<Int_t>    Jet_GenJet_Status;
  // std::vector<Int_t>    Jet_GenJet_PdgId;

  std::vector<float> Jet_Pt;
  std::vector<float> Jet_Eta;
  std::vector<float> Jet_Phi;
  std::vector<float> Jet_M;
  std::vector<float> Jet_E;
  std::vector<float> Jet_JetArea;
  std::vector<Int_t>    Jet_nTks;
  std::vector<Int_t>    Jet_ChargedMultiplicity;
  std::vector<Int_t>    Jet_NeutralMultiplicity;
  std::vector<float> Jet_NeutralHadronEnergyFraction;
  std::vector<float> Jet_NeutralEmEnergyFraction;
  std::vector<float> Jet_ChargedHadronEnergyFraction;
  std::vector<float> Jet_MuonEnergyFraction;
  std::vector<float> Jet_ChargedEmEnergyFraction;

  std::vector<float> Jet_bDis_JBP;
  std::vector<float> Jet_bDis_JP;
  std::vector<float> Jet_bDis_TCHP;
  std::vector<float> Jet_bDis_TCHE;
  std::vector<float> Jet_bDis_SVHP;
  std::vector<float> Jet_bDis_SVHE;
  std::vector<float> Jet_bDis_CMVA;

  std::vector<Bool_t>   Jet_HasGenJet;
  std::vector<float> Jet_GenJet_Pt;
  std::vector<float> Jet_GenJet_Eta;
  std::vector<float> Jet_GenJet_Phi;
  std::vector<float> Jet_GenJet_M;
  std::vector<float> Jet_GenJet_E;
  std::vector<Int_t>    Jet_GenJet_Status;
  std::vector<Int_t>    Jet_GenJet_PdgId;


  //PU-Jets
  std::vector<float> PUJet_Pt;
  std::vector<float> PUJet_Eta;
  std::vector<float> PUJet_Phi;
  std::vector<float> PUJet_M;
  std::vector<float> PUJet_E;
  std::vector<float> PUJet_JetArea;
  std::vector<Int_t> PUJet_nTks;
  std::vector<Int_t> PUJet_ChargedMultiplicity;
  std::vector<Int_t> PUJet_NeutralMultiplicity;
  std::vector<float> PUJet_NeutralHadronEnergyFraction;
  std::vector<float> PUJet_NeutralEmEnergyFraction;
  std::vector<float> PUJet_ChargedHadronEnergyFraction;
  std::vector<float> PUJet_MuonEnergyFraction;
  std::vector<float> PUJet_ChargedEmEnergyFraction;

  std::vector<float> PUJet_bDis_JBP;
  std::vector<float> PUJet_bDis_JP;
  std::vector<float> PUJet_bDis_TCHP;
  std::vector<float> PUJet_bDis_TCHE;
  std::vector<float> PUJet_bDis_SVHP;
  std::vector<float> PUJet_bDis_SVHE;
  std::vector<float> PUJet_bDis_CMVA;

  std::vector<Bool_t>PUJet_HasGenJet;
  std::vector<float> PUJet_GenJet_Pt;
  std::vector<float> PUJet_GenJet_Eta;
  std::vector<float> PUJet_GenJet_Phi;
  std::vector<float> PUJet_GenJet_M;
  std::vector<float> PUJet_GenJet_E;
  std::vector<Int_t> PUJet_GenJet_Status;
  std::vector<Int_t> PUJet_GenJet_PdgId;
  



  
};

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//
MyNtupleMaker::MyNtupleMaker(const edm::ParameterSet& iConfig)

{
  TFile& f = fs->file();
  f.SetCompressionAlgorithm(ROOT::kZLIB);
  f.SetCompressionLevel(9);
  // EvtTree = fs->make<TTree>("EvtTree", "EvtTree");
  //  ftree = new FlatTree(fs->make<TTree>("tree","tree"));
  
   //now do what ever initialization is needed
  //edm::Service<TFileService> fs;
}


MyNtupleMaker::~MyNtupleMaker()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void
MyNtupleMaker::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   using namespace edm;
   RunNumber   = iEvent.id().run();
   EvtNumber   = iEvent.id().event();

   //****************************************************************************
   // BeamSpot
   //****************************************************************************
   edm::Handle<reco::BeamSpot> bsHandle;
   iEvent.getByLabel("offlineBeamSpot", bsHandle);
   const reco::BeamSpot &beamspot = *bsHandle.product();


   //****************************************************************************
   // MET
   //****************************************************************************
   edm::Handle<pat::METCollection> met;
   iEvent.getByLabel("slimmedMETs",met);

   const pat::MET &tempmet = met->front();
   MET_Px    = tempmet.px();
   MET_Py    = tempmet.py();
   MET_Pt    = tempmet.pt();
   MET_Phi   = tempmet.phi();
   MET_SumEt = tempmet.sumEt();

   //   std::cout<<tempmet.eta()<<endl;
   
   MET_UncorrectedPt = tempmet.uncorrectedPt();
   MET_UncorrectedPhi = tempmet.uncorrectedPhi();
   MET_UncorrectedSumEt = tempmet.uncorrectedSumEt();
   
   MET_CaloMETPt = tempmet.caloMETPt();
   MET_CaloMETPhi = tempmet.caloMETPhi();
   MET_CaloMETSumEt = tempmet.caloMETSumEt();

   //****************************************************************************
   // GenJets
   //****************************************************************************
   edm::Handle<reco::GenJetCollection> genJetHandle;                            
   // //iEvent.getByLabel("ak4GenJets",genJetHandle);
   iEvent.getByLabel("slimmedGenJets", genJetHandle);



   Int_t nGenJet = genJetHandle->size();
   for(Int_t iGenJet=0; iGenJet<nGenJet; iGenJet++)
     {
       const reco::GenJet& tempgenJ = genJetHandle->at(iGenJet);
             
       GenJet_Pt.push_back           (tempgenJ.pt());
       GenJet_Eta.push_back          (tempgenJ.eta());
       GenJet_Phi.push_back          (tempgenJ.phi());
       GenJet_M.push_back            (tempgenJ.mass());
       GenJet_E.push_back            (tempgenJ.energy());
       GenJet_emE.push_back          (tempgenJ.emEnergy());
       GenJet_hadE.push_back         (tempgenJ.hadEnergy());
       GenJet_invE.push_back         (tempgenJ.invisibleEnergy());
       GenJet_auxE.push_back         (tempgenJ.auxiliaryEnergy());
       GenJet_VertexX.push_back      (tempgenJ.vx());
       GenJet_VertexY.push_back      (tempgenJ.vy());
       GenJet_VertexZ.push_back      (tempgenJ.vz());
       
       // vector<const reco::GenParticle*> mcparts = tempgenJ.getGenConstituents();
       // vector<Int_t> jetgenId;
       // vector<float> jetgenPt;
       // vector<float> jetgenEta;
       // vector<float> jetgenPhi;
       // vector<float> jetgenE;
       
       // for(Size_t ipar=0; ipar<mcparts.size();ipar++)
       // 	 {
       // 	   const reco::GenParticle* mcpart = mcparts[ipar];
       // 	   if (mcpart) 
       // 	     {
       // 	       jetgenId.push_back (mcpart->pdgId());
       // 	       jetgenPt.push_back (mcpart->pt());
       // 	       jetgenEta.push_back(mcpart->eta());
       // 	       jetgenPhi.push_back(mcpart->phi());
       // 	       jetgenE.push_back  (mcpart->energy());
       // 	     }
       // 	 }
       // GenJet_GenpPdgId.push_back    (jetgenId);
       // GenJet_GenpPt.push_back       (jetgenPt);
       // GenJet_GenpEta.push_back      (jetgenEta);
       // GenJet_GenpPhi.push_back      (jetgenPhi);
       // GenJet_GenpE.push_back        (jetgenE);
       
    }


   //****************************************************************************
   // GenParticles
   //****************************************************************************
   edm::Handle<reco::GenParticleCollection> genParticlesHandle;                            
   iEvent.getByLabel("prunedGenParticles",genParticlesHandle);
   //iEvent.getByLabel("genParticles",genParticlesHandle); 
   

   unsigned int genPIndex = 0;

   //int testIndx=0;

   //Int_t nGenp = genParticlesHandle->size();
   //for(Int_t iGenp=0; iGenp<nGenp; iGenp++)
   for ( reco::GenParticleCollection::const_iterator tempgenp = genParticlesHandle->begin(); tempgenp != genParticlesHandle->end(); tempgenp++, genPIndex++ )
     {
       //       std::cout<< tempgenp.pt()<<std::endl;
       // const reco::GenParticle& tempgenp = genParticlesHandle->at(iGenp);

       std::vector<unsigned short> vMothers;
       
       /// For-loop (nested): mothers
       for(unsigned int iMom = 0; iMom < tempgenp->numberOfMothers(); iMom++)
	 {
	 
	   /// Dynamic cast of reco::Candidate to reco::GenParticle
	   const reco::GenParticle* mom = dynamic_cast<const reco::GenParticle*>( tempgenp->mother(iMom) );
	   //	   std::cout<<&mom<<std::endl;
	   int diffMom   = &(*tempgenp) - mom;
	   int genp_IMom = mom!=0 ? genPIndex-diffMom : 65535; // condition ? result1 : result2 (treat 65535 as NULL)
	   vMothers.push_back(genp_IMom);
	 
       	 /// Sanity check
       	 // if(mom!=0){
       	 //   const reco::GenParticle* momFromDiff = &( truth.at(genp_IMom) );
       	 //   if( mom->pt() != momFromDiff->pt() ) { edm::LogError("TkTauFromCaloNTupleMaker") << "\nERROR! GenParticle mom pT = " << mom->pt() << ", genp_IMom pT = " << momFromDiff->pt() << std::endl; }
       	 // }
	 } /// For-loop (nested): mothers
       

       std::vector<unsigned short> vDaughters;
       /// For-loop (nested): daughters
       for(unsigned int iDau = 0; iDau < tempgenp->numberOfDaughters(); iDau++)
	 {
	   
	   /// Dynamic cast of reco::Candidate to reco::GenParticle
	   const reco::GenParticle* dau = dynamic_cast<const reco::GenParticle*>( tempgenp->daughter(iDau) );
	   int diffDau   = dau - &( *tempgenp );
	   int genp_IDau = dau!=0 ? genPIndex+diffDau : 0; // condition ? result1 : result2 
	   vDaughters.push_back( genp_IDau );
	   
	   // /// Sanity check
	   // if(dau!=0){
	   //   const reco::GenParticle* dauFromDiff = &(truth.at( genp_IDau) );
	   //   if(dau->pt() != dauFromDiff->pt()) { edm::LogError("TkTauFromCaloNTupleMaker") << "\nERROR! GenParticle daughter pT = " << dau->pt() << ", genp_IDau pT = " << dauFromDiff->pt() << std::endl; }
	   // }
	 }/// For-loop (nested): daughters
       
       //std::cout<<testIndx++<<endl;
       
       GenP_Pt.push_back        (tempgenp->pt());
       GenP_Eta.push_back       (tempgenp->eta());
       GenP_Phi.push_back       (tempgenp->phi());
       GenP_M.push_back         (tempgenp->mass());
       GenP_E.push_back         (tempgenp->energy());
       GenP_PdgId.push_back     (tempgenp->pdgId());
       GenP_Charge.push_back    (tempgenp->charge());
       GenP_Status.push_back    (tempgenp->status());
       GenP_VertexX.push_back   (tempgenp->vx());
       GenP_VertexY.push_back   (tempgenp->vy());
       GenP_VertexZ.push_back   (tempgenp->vz());
       GenP_Mothers.push_back   (vMothers);
       GenP_Daughters.push_back (vDaughters);

       //       std::vector< std::vector<unsigned short> > GenP_Mothers;
       //std::vector< std::vector<unsigned short> > GenP_Daughters;

     }//For-loop GenP
   

   //****************************************************************************
   // Primary vertex
   //****************************************************************************
   edm::Handle<reco::VertexCollection> vertices;
   iEvent.getByLabel("offlineSlimmedPrimaryVertices",vertices);

   reco::Vertex *primVtx = NULL;   
   
   if( ! vertices->empty() )
     {
       const reco::Vertex &PV = vertices->front();
       primVtx = (reco::Vertex*)&PV;
     }
   
   //****************************************************************************
   // Electrons
   //****************************************************************************
   edm::Handle<pat::ElectronCollection> electrons;
   iEvent.getByLabel("slimmedElectrons",electrons);
   
   Int_t nElec = electrons->size();
   
   for(Int_t iElec = 0; iElec<nElec; iElec++)
     {
       const pat::Electron& tempelec = electrons->at(iElec);
       
       
       Elec_Pt.push_back     (tempelec.pt());
       Elec_Eta.push_back    (tempelec.eta());
       Elec_Phi.push_back    (tempelec.phi());
       Elec_M.push_back      (tempelec.mass());
       Elec_E.push_back      (tempelec.energy());
       Elec_Id.push_back     (tempelec.pdgId());
       Elec_Charge.push_back (tempelec.charge());
       
       Elec_SCl_Eta.push_back (tempelec.superCluster()->eta());
       Elec_SCl_EtaWidth.push_back (tempelec.superCluster()->etaWidth());
       Elec_SCl_Phi.push_back (tempelec.superCluster()->phi());
       Elec_SCl_PhiWidth.push_back (tempelec.superCluster()->phiWidth());
       Elec_SCl_E.push_back (tempelec.superCluster()->energy());
       Elec_SCl_RawE.push_back (tempelec.superCluster()->rawEnergy());
       Elec_SCl_PreShowerE.push_back (tempelec.superCluster()->preshowerEnergy());
       Elec_SCl_PreShower1E.push_back (tempelec.superCluster()->preshowerEnergyPlane1());
       Elec_SCl_PreShower2E.push_back (tempelec.superCluster()->preshowerEnergyPlane2());
       Elec_SCl_PositionR.push_back (tempelec.superCluster()->position().R());

       Elec_IP3d.push_back(tempelec.dB(pat::Electron::PV3D));
       Elec_IP3dError.push_back(tempelec.edB(pat::Electron::PV3D));
       Elec_IP2d.push_back(tempelec.dB(pat::Electron::PV2D));
       Elec_IP2dError.push_back(tempelec.edB(pat::Electron::PV2D));
       Elec_IP3dBS.push_back(tempelec.dB(pat::Electron::BS3D));
       Elec_IP3dBSError.push_back(tempelec.edB(pat::Electron::BS3D));
       Elec_IP2dBS.push_back(tempelec.dB(pat::Electron::BS2D));
       Elec_IP2dBSError.push_back(tempelec.edB(pat::Electron::BS2D));

       //GSF Track
       const reco::GsfTrackRef gsfTrack = tempelec.gsfTrack();
       Bool_t hasGsfTrack = ( gsfTrack.isNonnull() );
       Elec_HasGsfTrack.push_back(hasGsfTrack);
       
       Elec_GsfTrack_D0.push_back((hasGsfTrack) ? gsfTrack->d0() : -666);
       Elec_GsfTrack_Z0.push_back((hasGsfTrack) ? gsfTrack->dz() : -666);
       
       Elec_GsfTrack_D0Error.push_back((hasGsfTrack) ? gsfTrack->d0Error() : -666);
       Elec_GsfTrack_Z0Error.push_back((hasGsfTrack) ? gsfTrack->dzError() : -666);
       
       Elec_GsfTrack_PV_Dxy.push_back((hasGsfTrack) ? gsfTrack->dxy(primVtx->position()) : -666);
       Elec_GsfTrack_PV_Z0.push_back((hasGsfTrack) ? gsfTrack->dz(primVtx->position()) : -666);	
       
       Elec_GsfTrack_RP_Dxy.push_back((hasGsfTrack) ? gsfTrack->dxy(gsfTrack->referencePoint()) : -666);
       Elec_GsfTrack_RP_Z0.push_back((hasGsfTrack) ? gsfTrack->dz(gsfTrack->referencePoint()) : -666);
       
       Elec_GsfTrack_BS_Dxy.push_back((hasGsfTrack) ? gsfTrack->dxy(beamspot.position()) : -666);
       Elec_GsfTrack_BS_Z0.push_back((hasGsfTrack) ? gsfTrack->dz(beamspot.position()) : -666);	
       
       Elec_GsfTrack_DxyError.push_back((hasGsfTrack) ? gsfTrack->dxyError() : -666);
       //Elec_GsfTrack_Z0Error.push_back((hasGsfTrack) ? gsfTrack->dzError() : -666);	
       
       Elec_GsfTrack_NormalizedChi2.push_back((hasGsfTrack) ? gsfTrack->normalizedChi2() : -666);	
       
  	
       
      }// end loop on electrons
   
   //****************************************************************************
   //Muons
   //****************************************************************************

    edm::Handle<pat::MuonCollection> muons;
    iEvent.getByLabel("slimmedMuons",muons);

    Int_t nMuon = muons->size();
   
    for(Int_t iMuon = 0; iMuon<nMuon; iMuon++)
      {
        const pat::Muon& tempmuon = muons->at(iMuon);
       
        Muon_Pt.push_back     (tempmuon.pt());
        Muon_Eta.push_back    (tempmuon.eta());
        Muon_Phi.push_back    (tempmuon.phi());
        Muon_M.push_back      (tempmuon.mass());
        Muon_E.push_back      (tempmuon.energy());
        Muon_Id.push_back     (tempmuon.pdgId());
        Muon_Charge.push_back (tempmuon.charge());


	Muon_IP3d.push_back(tempmuon.dB(pat::Muon::PV3D));
        Muon_IP3dError.push_back(tempmuon.edB(pat::Muon::PV3D));
        Muon_IP2d.push_back(tempmuon.dB(pat::Muon::PV2D));
        Muon_IP2dError.push_back(tempmuon.edB(pat::Muon::PV2D));
        Muon_IP3dBS.push_back(tempmuon.dB(pat::Muon::BS3D));
        Muon_IP3dBSError.push_back(tempmuon.edB(pat::Muon::BS3D));
        Muon_IP2dBS.push_back(tempmuon.dB(pat::Muon::BS2D));
        Muon_IP2dBSError.push_back(tempmuon.edB(pat::Muon::BS2D));

	// GlobalTrack
	const reco::TrackRef globalTrack = tempmuon.globalTrack();
	Bool_t hasGlobalTrack = globalTrack.isNonnull();
	
	Muon_HasGlobalTrack.push_back(hasGlobalTrack);
	
	Muon_GlobalTrack_D0.push_back((hasGlobalTrack) ? globalTrack->d0() : -666);
	Muon_GlobalTrack_Z0.push_back((hasGlobalTrack) ? globalTrack->dz() : -666);
	Muon_GlobalTrack_D0Error.push_back((hasGlobalTrack) ? globalTrack->d0Error() : -666);
	Muon_GlobalTrack_Z0Error.push_back((hasGlobalTrack) ? globalTrack->dzError() : -666);
	Muon_GlobalTrack_PV_Dxy.push_back((hasGlobalTrack) ? globalTrack->dxy(primVtx->position()) : -666);
	Muon_GlobalTrack_PV_Z0.push_back((hasGlobalTrack) ? globalTrack->dz(primVtx->position()) : -666);	
	Muon_GlobalTrack_RP_Dxy.push_back((hasGlobalTrack) ? globalTrack->dxy(globalTrack->referencePoint()) : -666);
	Muon_GlobalTrack_RP_Z0.push_back((hasGlobalTrack) ? globalTrack->dz(globalTrack->referencePoint()) : -666);
	Muon_GlobalTrack_BS_Dxy.push_back((hasGlobalTrack) ? globalTrack->dxy(beamspot.position()) : -666);
	Muon_GlobalTrack_BS_Z0.push_back((hasGlobalTrack) ? globalTrack->dz(beamspot.position()) : -666);	
	Muon_GlobalTrack_DxyError.push_back((hasGlobalTrack) ? globalTrack->dxyError() : -666);
	//Muon_GlobalTrack_Z0Error.push_back((hasGlobalTrack) ? globalTrack->dzError() : -666);	
	Muon_GlobalTrack_NormalizedChi2.push_back((hasGlobalTrack) ? globalTrack->normalizedChi2() : -666);
	
	Muon_GlobalTrack_Pt.push_back((hasGlobalTrack) ? globalTrack->pt() : -666);
	Muon_GlobalTrack_Eta.push_back((hasGlobalTrack) ? globalTrack->eta() : -666);
	Muon_GlobalTrack_Phi.push_back((hasGlobalTrack) ? globalTrack->phi() : -666);
	Muon_GlobalTrack_PtError.push_back((hasGlobalTrack) ? globalTrack->ptError() : -666);
	Muon_GlobalTrack_EtaError.push_back((hasGlobalTrack) ? globalTrack->etaError() : -666);
	Muon_GlobalTrack_PhiError.push_back((hasGlobalTrack) ? globalTrack->phiError() : -666);
	Muon_GlobalTrack_Charge.push_back((hasGlobalTrack) ? globalTrack->charge() : -666);

	// Muon_GlobalTrack_vx.push_back((hasGlobalTrack) ? globalTrack->vx() : -666);
	// Muon_GlobalTrack_vy.push_back((hasGlobalTrack) ? globalTrack->vy() : -666);
	// Muon_GlobalTrack_vz.push_back((hasGlobalTrack) ? globalTrack->vz() : -666);

	// InnerTrack
	const reco::TrackRef innerTrack = tempmuon.innerTrack();
	Bool_t hasInnerTrack = innerTrack.isNonnull();
	
	Muon_HasInnerTrack.push_back(hasInnerTrack);

	Muon_InnerTrack_D0.push_back((hasInnerTrack) ? innerTrack->d0() : -666);
	Muon_InnerTrack_Z0.push_back((hasInnerTrack) ? innerTrack->dz() : -666);
	Muon_InnerTrack_D0Error.push_back((hasInnerTrack) ? innerTrack->d0Error() : -666);
	Muon_InnerTrack_Z0Error.push_back((hasInnerTrack) ? innerTrack->dzError() : -666);
	Muon_InnerTrack_PV_Dxy.push_back((hasInnerTrack) ? innerTrack->dxy(primVtx->position()) : -666);
	Muon_InnerTrack_PV_Z0.push_back((hasInnerTrack) ? innerTrack->dz(primVtx->position()) : -666);	
	Muon_InnerTrack_RP_Dxy.push_back((hasInnerTrack) ? innerTrack->dxy(innerTrack->referencePoint()) : -666);
	Muon_InnerTrack_RP_Z0.push_back((hasInnerTrack) ? innerTrack->dz(innerTrack->referencePoint()) : -666);
	Muon_InnerTrack_BS_Dxy.push_back((hasInnerTrack) ? innerTrack->dxy(beamspot.position()) : -666);
	Muon_InnerTrack_BS_Z0.push_back((hasInnerTrack) ? innerTrack->dz(beamspot.position()) : -666);	
	Muon_InnerTrack_DxyError.push_back((hasInnerTrack) ? innerTrack->dxyError() : -666);
	//Muon_InnerTrack_Z0Error.push_back((hasInnerTrack) ? innerTrack->dzError() : -666);	
	Muon_InnerTrack_NormalizedChi2.push_back((hasInnerTrack) ? innerTrack->normalizedChi2() : -666);

	Muon_InnerTrack_Pt.push_back((hasInnerTrack) ? innerTrack->pt() : -666);
	Muon_InnerTrack_Eta.push_back((hasInnerTrack) ? innerTrack->eta() : -666);
	Muon_InnerTrack_Phi.push_back((hasInnerTrack) ? innerTrack->phi() : -666);
	Muon_InnerTrack_PtError.push_back((hasInnerTrack) ? innerTrack->ptError() : -666);
	Muon_InnerTrack_EtaError.push_back((hasInnerTrack) ? innerTrack->etaError() : -666);
	Muon_InnerTrack_PhiError.push_back((hasInnerTrack) ? innerTrack->phiError() : -666);

	
	// BestTrack
	Muon_BestTrackType.push_back(tempmuon.muonBestTrackType());
	const reco::TrackRef bestTrack = tempmuon.muonBestTrack();
	Bool_t hasBestTrack = bestTrack.isNonnull();
	
	Muon_HasBestTrack.push_back(hasBestTrack);
	
	Muon_BestTrack_D0.push_back((hasBestTrack) ? bestTrack->d0() : -666);
	Muon_BestTrack_Z0.push_back((hasBestTrack) ? bestTrack->dz() : -666);
	Muon_BestTrack_D0Error.push_back((hasBestTrack) ? bestTrack->d0Error() : -666);
	Muon_BestTrack_Z0Error.push_back((hasBestTrack) ? bestTrack->dzError() : -666);
	Muon_BestTrack_PV_Dxy.push_back((hasBestTrack) ? bestTrack->dxy(primVtx->position()) : -666);
	Muon_BestTrack_PV_Z0.push_back((hasBestTrack) ? bestTrack->dz(primVtx->position()) : -666);	
	Muon_BestTrack_RP_Dxy.push_back((hasBestTrack) ? bestTrack->dxy(bestTrack->referencePoint()) : -666);
	Muon_BestTrack_RP_Z0.push_back((hasBestTrack) ? bestTrack->dz(bestTrack->referencePoint()) : -666);
	Muon_BestTrack_BS_Dxy.push_back((hasBestTrack) ? bestTrack->dxy(beamspot.position()) : -666);
	Muon_BestTrack_BS_Z0.push_back((hasBestTrack) ? bestTrack->dz(beamspot.position()) : -666);	
	Muon_BestTrack_DxyError.push_back((hasBestTrack) ? bestTrack->dxyError() : -666);
	//Muon_BestTrack_Z0Error.push_back((hasBestTrack) ? bestTrack->dzError() : -666);	
	Muon_BestTrack_NormalizedChi2.push_back((hasBestTrack) ? bestTrack->normalizedChi2() : -666);

	Muon_BestTrack_Pt.push_back((hasBestTrack) ? bestTrack->pt() : -666);
	Muon_BestTrack_Eta.push_back((hasBestTrack) ? bestTrack->eta() : -666);
	Muon_BestTrack_Phi.push_back((hasBestTrack) ? bestTrack->phi() : -666);
	Muon_BestTrack_PtError.push_back((hasBestTrack) ? bestTrack->ptError() : -666);
	Muon_BestTrack_EtaError.push_back((hasBestTrack) ? bestTrack->etaError() : -666);
	Muon_BestTrack_PhiError.push_back((hasBestTrack) ? bestTrack->phiError() : -666);


      }

   //****************************************************************************
   //Taus
   //****************************************************************************
   
    edm::Handle<pat::TauCollection> taus;
    iEvent.getByLabel("slimmedTaus",taus);
    
    Int_t nTau = taus->size();
    
    for(Int_t iTau = 0; iTau<nTau; iTau++)
      {
        const pat::Tau& temptau = taus->at(iTau);
       
        Tau_Pt.push_back     (temptau.pt());
        Tau_Eta.push_back    (temptau.eta());
        Tau_Phi.push_back    (temptau.phi());
        Tau_M.push_back      (temptau.mass());
        Tau_E.push_back      (temptau.energy());
        Tau_Id.push_back     (temptau.pdgId());
        Tau_Charge.push_back (temptau.charge());

	
	Tau_DecayMode.push_back (temptau.decayMode());
	Tau_IsCaloTau.push_back (temptau.isCaloTau());


	float tau_leadingTrackPt = -666;
	float tau_leadingTrackEta = -666;
	float tau_leadingTrackPhi = -666;
	float tau_leadingTrackM = -666;
	float tau_leadingTrackE = -666;
	float tau_leadingTrackEt = -666;
 
	int tau_leadingTrackCharge = -666;
	int tau_leadingTrackId = -666;

	Tau_hasLeadChargedHadrCand.push_back(temptau.leadChargedHadrCand().isNonnull());
	
	if( temptau.leadChargedHadrCand().isNonnull() )
	  {
	    tau_leadingTrackPt     = temptau.leadChargedHadrCand()->pt();
	    tau_leadingTrackEta    = temptau.leadChargedHadrCand()->eta();
	    tau_leadingTrackPhi    = temptau.leadChargedHadrCand()->phi();
	    tau_leadingTrackM      = temptau.leadChargedHadrCand()->mass();
	    tau_leadingTrackE      = temptau.leadChargedHadrCand()->energy();
	    tau_leadingTrackEt     = temptau.leadChargedHadrCand()->et();
	    tau_leadingTrackId     = temptau.leadChargedHadrCand()->pdgId();
	    tau_leadingTrackCharge = temptau.leadChargedHadrCand()->charge();
	    
	  }	

	
	Tau_LeadingTrackPt.push_back(tau_leadingTrackPt);
	Tau_LeadingTrackEta.push_back(tau_leadingTrackEta);
	Tau_LeadingTrackPhi.push_back(tau_leadingTrackPhi);
	Tau_LeadingTrackM.push_back(tau_leadingTrackM);
	Tau_LeadingTrackE.push_back(tau_leadingTrackE);
	Tau_LeadingTrackEt.push_back(tau_leadingTrackEt);
	Tau_LeadingTrackId.push_back(tau_leadingTrackId);
	Tau_LeadingTrackCharge.push_back(tau_leadingTrackCharge);







	//no lead track??????????
	
	//	std::cout<<"\tDecayMode\t"<<temptau.decayMode()<<endl;
	//	if(temptau.isCaloTau())
	//	std::cout<<"\tDecayMode\t"<<temptau.correctedP4()<<endl;

	//	const reco::TrackRef leadTrack = temptau.leadTrack();
	//Bool_t hasLeadTrack = leadTrack.isNonnull();
	
	//	std::cout<<"\tinvariant mass\t"<<temptau.TracksInvariantMass()<<endl;

	//	if(hasLeadTrack) std::cout<<"\tlead track\t"<<leadTrack->d0()<<endl;
	



      }

    
    //****************************************************************************
    //Jets
    //****************************************************************************
    edm::Handle<pat::JetCollection> jets;
    iEvent.getByLabel("slimmedJets",jets);
    //    iEvent.getByLabel("slimmedJetsPuppi",jets);

    Int_t nJet = jets->size();
    for(Int_t iJet=0; iJet<nJet; iJet++)
      {
	const pat::Jet& tempjet = jets->at(iJet);
	
	Jet_Pt.push_back (tempjet.pt());
	Jet_Eta.push_back(tempjet.eta());
	Jet_Phi.push_back(tempjet.phi());
	Jet_M.push_back  (tempjet.mass());
	Jet_E.push_back  (tempjet.energy());
	
	// std::cout<<"\n\n\n\n\n\tJet PtEtaPhiE\t"<< tempjet.pt()<<"\t"<<tempjet.eta()<<"\t"<<tempjet.phi()<<"\t"<<tempjet.energy()<<endl;

	//	std::cout<<"\tThe oneesss\t"<<tempjet.vz()<<endl;


	Jet_bDis_JBP.push_back(tempjet.bDiscriminator("pfJetBProbabilityBJetTags"));
	Jet_bDis_JP.push_back(tempjet.bDiscriminator("pfJetProbabilityBJetTags"));
	Jet_bDis_TCHP.push_back(tempjet.bDiscriminator("pfTrackCountingHighPurBJetTags"));
	Jet_bDis_TCHE.push_back(tempjet.bDiscriminator("pfTrackCountingHighEffBJetTags"));
	Jet_bDis_SVHP.push_back(tempjet.bDiscriminator("pfSimpleSecondaryVertexHighPurBJetTags"));
	Jet_bDis_SVHE.push_back(tempjet.bDiscriminator("pfSimpleSecondaryVertexHighEffBJetTags"));
	Jet_bDis_CMVA.push_back(tempjet.bDiscriminator("pfCombinedMVABJetTags"));

	// Discriminator Tags
	// 	discriminatorSources = cms.VInputTag(
	//     cms.InputTag("combinedSecondaryVertexBJetTags"),
	//     cms.InputTag("pfJetBProbabilityBJetTags"),
	//     cms.InputTag("pfJetProbabilityBJetTags"),
	//     cms.InputTag("pfTrackCountingHighPurBJetTags"),
	//     cms.InputTag("pfTrackCountingHighEffBJetTags"),
	//     cms.InputTag("pfSimpleSecondaryVertexHighEffBJetTags"),
	//     cms.InputTag("pfSimpleSecondaryVertexHighPurBJetTags"),
	//     cms.InputTag("pfCombinedSecondaryVertexV2BJetTags"),
	//     cms.InputTag("pfCombinedInclusiveSecondaryVertexV2BJetTags"),
	//     cms.InputTag("pfCombinedSecondaryVertexSoftLeptonBJetTags"),
	//     cms.InputTag("pfCombinedMVABJetTags")
	// ),


	//	std::cout<<tempjet.bDiscriminator("pfCombinedMVABJetTags")<<endl;

	Jet_JetArea.push_back(tempjet.jetArea());
	Jet_nTks.push_back(tempjet.associatedTracks().size());
	Jet_ChargedMultiplicity.push_back(tempjet.chargedMultiplicity());
	Jet_NeutralMultiplicity.push_back(tempjet.neutralMultiplicity());

	//	std::cout<<"\tassociatedtracks\t"<<tempjet.associatedTracks().size()<<endl;


	Jet_NeutralHadronEnergyFraction.push_back (tempjet.neutralHadronEnergyFraction());
	Jet_NeutralEmEnergyFraction.push_back     (tempjet.neutralEmEnergyFraction());
	Jet_ChargedHadronEnergyFraction.push_back (tempjet.chargedHadronEnergyFraction());
	Jet_MuonEnergyFraction.push_back          (tempjet.muonEnergyFraction());
	Jet_ChargedEmEnergyFraction.push_back     (tempjet.chargedEmEnergyFraction());

	const reco::GenParticle* tempgenParton = tempjet.genParton();
	//Int_t jetgenFlavor = -666;
	if(tempgenParton)
	  {
	    // jetgenFlavor = tempgenParton->pdgId();
	    // std::cout<<"\tGen Parton PtEtaPhiE\t"<< tempgenParton->pt()<<"\t"<<tempgenParton->eta()<<"\t"<<tempgenParton->phi()<<"\t"<<tempgenParton->energy()<<endl;

	  }
	// Jet_GenPartonFlavor.push_back(jetgenFlavor);



	//if(testGen)std::cout<<"\tthe Gen parton be.\t"<<testGen->pdgId();
	
	const reco::GenJet* tempgenJet = tempjet.genJet();
	Bool_t hasGenInfo = (tempgenJet);
	Jet_HasGenJet.push_back(hasGenInfo);
	
	float tempgen_jet_pt = -666;
	float tempgen_jet_eta = -666;
	float tempgen_jet_phi = -666;
	float tempgen_jet_m = -666;
	float tempgen_jet_E = -666;
	float tempgen_jet_emE = -666;
	float tempgen_jet_hadE = -666;
	float tempgen_jet_invE = -666;

	if( hasGenInfo )
	  {
	     tempgen_jet_pt     = tempgenJet->pt();
	     tempgen_jet_eta    = tempgenJet->eta();
	     tempgen_jet_phi    = tempgenJet->phi();
	     tempgen_jet_m      = tempgenJet->mass();
	     tempgen_jet_E      = tempgenJet->energy();
	     tempgen_jet_emE    = tempgenJet->emEnergy();
	     tempgen_jet_hadE   = tempgenJet->hadEnergy();
	     tempgen_jet_invE   = tempgenJet->invisibleEnergy();

	     //	     std::cout<<"\tGen Jet PtEtaPhiE\t"<< tempgenJet->pt()<<"\t"<<tempgenJet->eta()<<"\t"<<tempgenJet->phi()<<"\t"<<tempgenJet->energy()<<endl;
	     
	  }
	
	Jet_GenJet_Pt.push_back       (tempgen_jet_pt);
	Jet_GenJet_Eta.push_back      (tempgen_jet_eta);
	Jet_GenJet_Phi.push_back      (tempgen_jet_phi);
	Jet_GenJet_M.push_back        (tempgen_jet_m);
	Jet_GenJet_E.push_back        (tempgen_jet_E);
	Jet_GenJet_EMEnergy.push_back (tempgen_jet_emE);
	Jet_GenJet_HadEnergy.push_back(tempgen_jet_hadE);
	Jet_GenJet_InvisibleEnergy.push_back(tempgen_jet_hadE);



      }

    // //****************************************************************************
    // //PU-Jets
    // //****************************************************************************
    // edm::Handle<pat::JetCollection> pujets;
    // iEvent.getByLabel("slimmedJetsPuppi",jets);

    // Int_t nPUJet = pujets->size();
    // for(Int_t iPUJet=0; iPUJet<nPUJet; iPUJet++)
    //   {
    // 	const pat::Jet& temppujet = pujets->at(iPUJet);
	
    // 	PUJet_Pt.push_back (temppujet.pt());
    // 	PUJet_Eta.push_back(temppujet.eta());
    // 	PUJet_Phi.push_back(temppujet.phi());
    // 	PUJet_M.push_back  (temppujet.mass());
    // 	PUJet_E.push_back  (temppujet.energy());
	
    // 	PUJet_bDis_JBP.push_back(temppujet.bDiscriminator("pfJetBProbabilityBJetTags"));
    // 	PUJet_bDis_JP.push_back(temppujet.bDiscriminator("pfJetProbabilityBJetTags"));
    // 	PUJet_bDis_TCHP.push_back(temppujet.bDiscriminator("pfTrackCountingHighPurBJetTags"));
    // 	PUJet_bDis_TCHE.push_back(temppujet.bDiscriminator("pfTrackCountingHighEffBJetTags"));
    // 	PUJet_bDis_SVHP.push_back(temppujet.bDiscriminator("pfSimpleSecondaryVertexHighPurBJetTags"));
    // 	PUJet_bDis_SVHE.push_back(temppujet.bDiscriminator("pfSimpleSecondaryVertexHighEffBJetTags"));
    // 	PUJet_bDis_CMVA.push_back(temppujet.bDiscriminator("pfCombinedMVABJetTags"));

    // 	// Discriminator Tags
    // 	// 	discriminatorSources = cms.VInputTag(
    // 	//     cms.InputTag("combinedSecondaryVertexBJetTags"),
    // 	//     cms.InputTag("pfJetBProbabilityBJetTags"),
    // 	//     cms.InputTag("pfJetProbabilityBJetTags"),
    // 	//     cms.InputTag("pfTrackCountingHighPurBJetTags"),
    // 	//     cms.InputTag("pfTrackCountingHighEffBJetTags"),
    // 	//     cms.InputTag("pfSimpleSecondaryVertexHighEffBJetTags"),
    // 	//     cms.InputTag("pfSimpleSecondaryVertexHighPurBJetTags"),
    // 	//     cms.InputTag("pfCombinedSecondaryVertexV2BJetTags"),
    // 	//     cms.InputTag("pfCombinedInclusiveSecondaryVertexV2BJetTags"),
    // 	//     cms.InputTag("pfCombinedSecondaryVertexSoftLeptonBJetTags"),
    // 	//     cms.InputTag("pfCombinedMVABJetTags")
    // 	// ),


    // 	//	std::cout<<tempjet.bDiscriminator("pfCombinedMVABJetTags")<<endl;

    // 	PUJet_JetArea.push_back(temppujet.jetArea());
    // 	PUJet_nTks.push_back(temppujet.associatedTracks().size());
    // 	PUJet_ChargedMultiplicity.push_back(temppujet.chargedMultiplicity());
    // 	PUJet_NeutralMultiplicity.push_back(temppujet.neutralMultiplicity());


    // 	PUJet_NeutralHadronEnergyFraction.push_back (temppujet.neutralHadronEnergyFraction());
    // 	PUJet_NeutralEmEnergyFraction.push_back     (temppujet.neutralEmEnergyFraction());
    // 	PUJet_ChargedHadronEnergyFraction.push_back (temppujet.chargedHadronEnergyFraction());
    // 	PUJet_MuonEnergyFraction.push_back          (temppujet.muonEnergyFraction());
    // 	PUJet_ChargedEmEnergyFraction.push_back     (temppujet.chargedEmEnergyFraction());

	
    // 	const reco::GenJet* tempgenpuJet = temppujet.genJet();
    // 	Bool_t hasGenPUInfo = (tempgenpuJet);
    // 	PUJet_HasGenJet.push_back(hasGenPUInfo);
	
    // 	float tempgen_pujet_pt = -666;
    // 	float tempgen_pujet_eta = -666;
    // 	float tempgen_pujet_phi = -666;
    // 	float tempgen_pujet_m = -666;
    // 	float tempgen_pujet_E = -666;
    // 	int   tempgen_pujet_status = -666;
    // 	int   tempgen_pujet_id = -666;

    // 	if( hasGenPUInfo )
    // 	  {
    // 	     tempgen_pujet_pt     = tempgenpuJet->pt();
    // 	     tempgen_pujet_eta    = tempgenpuJet->eta();
    // 	     tempgen_pujet_phi    = tempgenpuJet->phi();
    // 	     tempgen_pujet_m      = tempgenpuJet->mass();
    // 	     tempgen_pujet_E      = tempgenpuJet->energy();
    // 	     tempgen_pujet_status = tempgenpuJet->status();
    // 	     tempgen_pujet_id     = tempgenpuJet->pdgId();
    // 	  }
	
    // 	PUJet_GenJet_Pt.push_back     (tempgen_pujet_pt);
    // 	PUJet_GenJet_Eta.push_back    (tempgen_pujet_eta);
    // 	PUJet_GenJet_Phi.push_back    (tempgen_pujet_phi);
    // 	PUJet_GenJet_M.push_back      (tempgen_pujet_m);
    // 	PUJet_GenJet_E.push_back      (tempgen_pujet_E);
    // 	PUJet_GenJet_Status.push_back (tempgen_pujet_status);
    // 	PUJet_GenJet_PdgId.push_back  (tempgen_pujet_id);



    //   }



    /// Fill the tree
    EvtTree->Fill();
    
    /// Reset the tree containers
    InitializeContainers();
    
#ifdef THIS_IS_AN_EVENT_EXAMPLE


    Handle<ExampleData> pIn;
    iEvent.getByLabel("example",pIn);
#endif
    
#ifdef THIS_IS_AN_EVENTSETUP_EXAMPLE
    ESHandle<SetupData> pSetup;
    iSetup.get<SetupRecord>().get(pSetup);
#endif
}


// ------------ method called once each job just before starting event loop  ------------
void 
MyNtupleMaker::beginJob()
{
  
  
  //  edm::Service<TFileService> fs;
  // TFile& f = fs->file();
  //f.SetCompressionAlgorithm(ROOT::kZLIB);
  //f.SetCompressionLevel(9);
  /// Assign Branches/Variables for Ntuple
  EvtTree = fs->make<TTree>("EvtTree", "Evt Tree");
  
  /// Event
  EvtTree->Branch("RunNumber"                  , &RunNumber);
  EvtTree->Branch("EvtNumber"                  , &EvtNumber);

  //MET
  EvtTree->Branch("MET_Px"               , &MET_Px);
  EvtTree->Branch("MET_Py"               , &MET_Py);
  EvtTree->Branch("MET_Pt"               , &MET_Pt);
  EvtTree->Branch("MET_Phi"              , &MET_Phi);
  EvtTree->Branch("MET_SumEt"            , &MET_SumEt);
  
  EvtTree->Branch("MET_UncorrectedPt"    , &MET_UncorrectedPt);
  EvtTree->Branch("MET_UncorrectedPhi"   , &MET_UncorrectedPhi);
  EvtTree->Branch("MET_UncorrectedSumEt" , &MET_UncorrectedSumEt);
  
  EvtTree->Branch("MET_CaloMETPt"        , &MET_CaloMETPt);
  EvtTree->Branch("MET_CaloMETPhi"       , &MET_CaloMETPhi);
  EvtTree->Branch("MET_CaloMETSumEt"     , &MET_CaloMETSumEt);
  
  //GenJets
  EvtTree->Branch("GenJet_N"                    , &GenJet_N);
  EvtTree->Branch("GenJet_Pt"                   , &GenJet_Pt);
  EvtTree->Branch("GenJet_Eta"                  , &GenJet_Eta);
  EvtTree->Branch("GenJet_Phi"                  , &GenJet_Phi);
  EvtTree->Branch("GenJet_M"                    , &GenJet_M);
  EvtTree->Branch("GenJet_E"                    , &GenJet_E);
  EvtTree->Branch("GenJet_emE"                  , &GenJet_emE);
  EvtTree->Branch("GenJet_hadE"                 , &GenJet_hadE);
  EvtTree->Branch("GenJet_invE"                 , &GenJet_invE);
  EvtTree->Branch("GenJet_auxE"                 , &GenJet_auxE);
  EvtTree->Branch("GenJet_VertexX"              , &GenJet_VertexX);
  EvtTree->Branch("GenJet_VertexY"              , &GenJet_VertexY);
  EvtTree->Branch("GenJet_VertexZ"              , &GenJet_VertexZ);
  EvtTree->Branch("GenJet_GenpPdgId"            , &GenJet_GenpPdgId);
  EvtTree->Branch("GenJet_GenpPt"               , &GenJet_GenpPt);
  EvtTree->Branch("GenJet_GenpEta"              , &GenJet_GenpEta);
  EvtTree->Branch("GenJet_GenpPhi"              , &GenJet_GenpPhi);
  EvtTree->Branch("GenJet_GenpE"                , &GenJet_GenpE);
 


  //GenP
  EvtTree->Branch("GenP_N"                     , &GenP_N);
  EvtTree->Branch("GenP_Pt"                    , &GenP_Pt);
  EvtTree->Branch("GenP_Eta"                   , &GenP_Eta);
  EvtTree->Branch("GenP_Phi"                   , &GenP_Phi);
  EvtTree->Branch("GenP_M"                     , &GenP_M);
  EvtTree->Branch("GenP_E"                     , &GenP_E);
  EvtTree->Branch("GenP_PdgId"                 , &GenP_PdgId);
  EvtTree->Branch("GenP_Charge"                , &GenP_Charge);
  EvtTree->Branch("GenP_Status"                , &GenP_Status);
  EvtTree->Branch("GenP_VertexX"               , &GenP_VertexX);
  EvtTree->Branch("GenP_VertexY"               , &GenP_VertexY);
  EvtTree->Branch("GenP_VertexZ"               , &GenP_VertexZ);
  EvtTree->Branch("GenP_Mothers"               , &GenP_Mothers);
  EvtTree->Branch("GenP_Daughters"             , &GenP_Daughters);

  //Electrons
  EvtTree->Branch("Elec_N"                       , &Elec_N);
  EvtTree->Branch("Elec_Pt"                      , &Elec_Pt);
  EvtTree->Branch("Elec_Eta"                     , &Elec_Eta);
  EvtTree->Branch("Elec_Phi"                     , &Elec_Phi);
  EvtTree->Branch("Elec_M"                       , &Elec_M);
  EvtTree->Branch("Elec_E"                       , &Elec_E);
  EvtTree->Branch("Elec_Id"                      , &Elec_Id);
  EvtTree->Branch("Elec_Charge"                  , &Elec_Charge);
  
  EvtTree->Branch("Elec_SCl_Eta"                 , &Elec_SCl_Eta);
  EvtTree->Branch("Elec_SCl_EtaWidth"            , &Elec_SCl_EtaWidth);
  EvtTree->Branch("Elec_SCl_Phi"                 , &Elec_SCl_Phi);
  EvtTree->Branch("Elec_SCl_PhiWidth"            , &Elec_SCl_PhiWidth);
  EvtTree->Branch("Elec_SCl_E"                   , &Elec_SCl_E);
  EvtTree->Branch("Elec_SCl_RawE"                , &Elec_SCl_RawE);
  EvtTree->Branch("Elec_SCl_PreShowerE"          , &Elec_SCl_PreShowerE);
  EvtTree->Branch("Elec_SCl_PreShower1E"         , &Elec_SCl_PreShower1E);
  EvtTree->Branch("Elec_SCl_PreShower2E"         , &Elec_SCl_PreShower2E);
  EvtTree->Branch("Elec_SCl_PositionR"           , &Elec_SCl_PositionR);

  EvtTree->Branch("Elec_HasGsfTrack"             , &Elec_HasGsfTrack);
  EvtTree->Branch("Elec_GsfTrack_D0"             , &Elec_GsfTrack_D0);
  EvtTree->Branch("Elec_GsfTrack_Z0"             , &Elec_GsfTrack_Z0);
  EvtTree->Branch("Elec_GsfTrack_D0Error"        , &Elec_GsfTrack_D0Error);             
  EvtTree->Branch("Elec_GsfTrack_Z0Error"        , &Elec_GsfTrack_Z0Error);
  EvtTree->Branch("Elec_GsfTrack_PV_Dxy"         , &Elec_GsfTrack_PV_Dxy);
  EvtTree->Branch("Elec_GsfTrack_PV_Z0"          , &Elec_GsfTrack_PV_Z0);
  EvtTree->Branch("Elec_GsfTrack_RP_Dxy"         , &Elec_GsfTrack_RP_Dxy);
  EvtTree->Branch("Elec_GsfTrack_RP_Z0"          , &Elec_GsfTrack_RP_Z0);
  EvtTree->Branch("Elec_GsfTrack_BS_Dxy"         , &Elec_GsfTrack_BS_Dxy);
  EvtTree->Branch("Elec_GsfTrack_BS_Z0"          , &Elec_GsfTrack_BS_Z0);
  EvtTree->Branch("Elec_GsfTrack_DxyError"       , &Elec_GsfTrack_DxyError);
  //EvtTree->Branch("Elec_GsfTrack_Z0Error"        , &Elec_GsfTrack_Z0Error);
  EvtTree->Branch("Elec_GsfTrack_NormalizedChi2" , &Elec_GsfTrack_NormalizedChi2);

  EvtTree->Branch("Elec_IP3d"                    , &Elec_IP3d);
  EvtTree->Branch("Elec_IP3dError"               , &Elec_IP3dError);
  EvtTree->Branch("Elec_IP2d"                    , &Elec_IP2d);
  EvtTree->Branch("Elec_IP2dError"               , &Elec_IP2dError);
  EvtTree->Branch("Elec_IP3dBS"                  , &Elec_IP3dBS);
  EvtTree->Branch("Elec_IP3dBSError"             , &Elec_IP3dBSError);
  EvtTree->Branch("Elec_IP2dBS"                  , &Elec_IP2dBS);
  EvtTree->Branch("Elec_IP2dBSError"             , &Elec_IP2dBSError);



  //Mouns
  EvtTree->Branch("Muon_Pt"                    , &Muon_Pt);
  EvtTree->Branch("Muon_Eta"                   , &Muon_Eta);
  EvtTree->Branch("Muon_Phi"                   , &Muon_Phi);
  EvtTree->Branch("Muon_M"                     , &Muon_M);
  EvtTree->Branch("Muon_E"                     , &Muon_E);
  EvtTree->Branch("Muon_Id"                    , &Muon_Id);
  EvtTree->Branch("Muon_Charge"                , &Muon_Charge);

  EvtTree->Branch("Muon_IP3d"                  , &Muon_IP3d);
  EvtTree->Branch("Muon_IP3dError"             , &Muon_IP3dError);
  EvtTree->Branch("Muon_IP2d"                  , &Muon_IP2d);
  EvtTree->Branch("Muon_IP2dError"             , &Muon_IP2dError);
  EvtTree->Branch("Muon_IP3dBS"                , &Muon_IP3dBS);
  EvtTree->Branch("Muon_IP3dBSError"           , &Muon_IP3dBSError);
  EvtTree->Branch("Muon_IP2dBS"                , &Muon_IP2dBS);
  EvtTree->Branch("Muon_IP2dBSError"           , &Muon_IP2dBSError);

  EvtTree->Branch("Muon_HasGlobalTrack"            , &Muon_HasGlobalTrack);
  EvtTree->Branch("Muon_GlobalTrack_D0"            , &Muon_GlobalTrack_D0);
  EvtTree->Branch("Muon_GlobalTrack_Z0"            , &Muon_GlobalTrack_Z0);
  EvtTree->Branch("Muon_GlobalTrack_D0Error"       , &Muon_GlobalTrack_D0Error);
  EvtTree->Branch("Muon_GlobalTrack_Z0Error"       , &Muon_GlobalTrack_Z0Error);
  EvtTree->Branch("Muon_GlobalTrack_PV_Dxy"        , &Muon_GlobalTrack_PV_Dxy);
  EvtTree->Branch("Muon_GlobalTrack_PV_Z0"         , &Muon_GlobalTrack_PV_Z0);
  EvtTree->Branch("Muon_GlobalTrack_RP_Dxy"        , &Muon_GlobalTrack_RP_Dxy);
  EvtTree->Branch("Muon_GlobalTrack_RP_Z0"         , &Muon_GlobalTrack_RP_Z0);
  EvtTree->Branch("Muon_GlobalTrack_BS_Dxy"        , &Muon_GlobalTrack_BS_Dxy);
  EvtTree->Branch("Muon_GlobalTrack_BS_Z0"         , &Muon_GlobalTrack_BS_Z0);
  EvtTree->Branch("Muon_GlobalTrack_DxyError"      , &Muon_GlobalTrack_DxyError);
  //EvtTree->Branch("Muon_GlobalTrack_Z0Error"       , &Muon_GlobalTrack_Z0Error);
  EvtTree->Branch("Muon_GlobalTrack_NormalizedChi2", &Muon_GlobalTrack_NormalizedChi2);
  EvtTree->Branch("Muon_GlobalTrack_Pt"            , &Muon_GlobalTrack_Pt);
  EvtTree->Branch("Muon_GlobalTrack_Eta"           , &Muon_GlobalTrack_Eta);
  EvtTree->Branch("Muon_GlobalTrack_Phi"           , &Muon_GlobalTrack_Phi);
  EvtTree->Branch("Muon_GlobalTrack_PtError"       , &Muon_GlobalTrack_PtError);;
  EvtTree->Branch("Muon_GlobalTrack_EtaError"      , &Muon_GlobalTrack_EtaError);;
  EvtTree->Branch("Muon_GlobalTrack_PhiError"      , &Muon_GlobalTrack_PhiError);
  EvtTree->Branch("Muon_GlobalTrack_Charge"        , &Muon_GlobalTrack_Charge);


  EvtTree->Branch("Muon_HasInnerTrack"            , &Muon_HasInnerTrack);
  EvtTree->Branch("Muon_InnerTrack_D0"            , &Muon_InnerTrack_D0);
  EvtTree->Branch("Muon_InnerTrack_Z0"            , &Muon_InnerTrack_Z0);
  EvtTree->Branch("Muon_InnerTrack_D0Error"       , &Muon_InnerTrack_D0Error);
  EvtTree->Branch("Muon_InnerTrack_Z0Error"       , &Muon_InnerTrack_Z0Error);
  EvtTree->Branch("Muon_InnerTrack_PV_Dxy"        , &Muon_InnerTrack_PV_Dxy);
  EvtTree->Branch("Muon_InnerTrack_PV_Z0"         , &Muon_InnerTrack_PV_Z0);
  EvtTree->Branch("Muon_InnerTrack_RP_Dxy"        , &Muon_InnerTrack_RP_Dxy);
  EvtTree->Branch("Muon_InnerTrack_RP_Z0"         , &Muon_InnerTrack_RP_Z0);
  EvtTree->Branch("Muon_InnerTrack_BS_Dxy"        , &Muon_InnerTrack_BS_Dxy);
  EvtTree->Branch("Muon_InnerTrack_BS_Z0"         , &Muon_InnerTrack_BS_Z0);
  EvtTree->Branch("Muon_InnerTrack_DxyError"      , &Muon_InnerTrack_DxyError);
  //EvtTree->Branch("Muon_InnerTrack_Z0Error"       , &Muon_InnerTrack_Z0Error);
  EvtTree->Branch("Muon_InnerTrack_NormalizedChi2", &Muon_InnerTrack_NormalizedChi2);
  EvtTree->Branch("Muon_InnerTrack_Pt"            , &Muon_InnerTrack_Pt);
  EvtTree->Branch("Muon_InnerTrack_Eta"           , &Muon_InnerTrack_Eta);
  EvtTree->Branch("Muon_InnerTrack_Phi"           , &Muon_InnerTrack_Phi);
  EvtTree->Branch("Muon_InnerTrack_PtError"       , &Muon_InnerTrack_PtError);;
  EvtTree->Branch("Muon_InnerTrack_EtaError"      , &Muon_InnerTrack_EtaError);;
  EvtTree->Branch("Muon_InnerTrack_PhiError"      , &Muon_InnerTrack_PhiError);
  EvtTree->Branch("Muon_InnerTrack_Charge"        , &Muon_InnerTrack_Charge);

  EvtTree->Branch("Muon_HasBestTrack"            , &Muon_HasBestTrack);
  EvtTree->Branch("Muon_BestTrackType"           , &Muon_BestTrackType);
  EvtTree->Branch("Muon_BestTrack_D0"            , &Muon_BestTrack_D0);
  EvtTree->Branch("Muon_BestTrack_Z0"            , &Muon_BestTrack_Z0);
  EvtTree->Branch("Muon_BestTrack_D0Error"       , &Muon_BestTrack_D0Error);
  EvtTree->Branch("Muon_BestTrack_Z0Error"       , &Muon_BestTrack_Z0Error);
  EvtTree->Branch("Muon_BestTrack_PV_Dxy"        , &Muon_BestTrack_PV_Dxy);
  EvtTree->Branch("Muon_BestTrack_PV_Z0"         , &Muon_BestTrack_PV_Z0);
  EvtTree->Branch("Muon_BestTrack_RP_Dxy"        , &Muon_BestTrack_RP_Dxy);
  EvtTree->Branch("Muon_BestTrack_RP_Z0"         , &Muon_BestTrack_RP_Z0);
  EvtTree->Branch("Muon_BestTrack_BS_Dxy"        , &Muon_BestTrack_BS_Dxy);
  EvtTree->Branch("Muon_BestTrack_BS_Z0"         , &Muon_BestTrack_BS_Z0);
  EvtTree->Branch("Muon_BestTrack_DxyError"      , &Muon_BestTrack_DxyError);
  //EvtTree->Branch("Muon_BestTrack_Z0Error"       , &Muon_BestTrack_Z0Error);
  EvtTree->Branch("Muon_BestTrack_NormalizedChi2", &Muon_BestTrack_NormalizedChi2);
  EvtTree->Branch("Muon_BestTrack_Pt"            , &Muon_BestTrack_Pt);
  EvtTree->Branch("Muon_BestTrack_Eta"           , &Muon_BestTrack_Eta);
  EvtTree->Branch("Muon_BestTrack_Phi"           , &Muon_BestTrack_Phi);
  EvtTree->Branch("Muon_BestTrack_PtError"       , &Muon_BestTrack_PtError);;
  EvtTree->Branch("Muon_BestTrack_EtaError"      , &Muon_BestTrack_EtaError);;
  EvtTree->Branch("Muon_BestTrack_PhiError"      , &Muon_BestTrack_PhiError);
  EvtTree->Branch("Muon_BestTrack_Charge"        , &Muon_BestTrack_Charge);

  //Taus
  EvtTree->Branch("Tau_Pt"                    , &Tau_Pt);
  EvtTree->Branch("Tau_Eta"                   , &Tau_Eta);
  EvtTree->Branch("Tau_Phi"                   , &Tau_Phi);
  EvtTree->Branch("Tau_M"                     , &Tau_M);
  EvtTree->Branch("Tau_E"                     , &Tau_E);
  EvtTree->Branch("Tau_Id"                    , &Tau_Id);
  EvtTree->Branch("Tau_Charge"                , &Tau_Charge);
  EvtTree->Branch("Tau_DecayMode"             , &Tau_DecayMode);
  EvtTree->Branch("Tau_IsCaloTau"             , &Tau_IsCaloTau);

  EvtTree->Branch("Tau_hasLeadChargedHadrCand" , &Tau_hasLeadChargedHadrCand);
  EvtTree->Branch("Tau_LeadingTrackPt"         , &Tau_LeadingTrackPt);
  EvtTree->Branch("Tau_LeadingTrackEta"        , &Tau_LeadingTrackEta);
  EvtTree->Branch("Tau_LeadingTrackPhi"        , &Tau_LeadingTrackPhi);
  EvtTree->Branch("Tau_LeadingTrackM"          , &Tau_LeadingTrackM);
  EvtTree->Branch("Tau_LeadingTrackE"          , &Tau_LeadingTrackE);
  EvtTree->Branch("Tau_LeadingTrackEt"         , &Tau_LeadingTrackEt);
  EvtTree->Branch("Tau_LeadingTrackId"         , &Tau_LeadingTrackId);
  EvtTree->Branch("Tau_LeadingTrackCharge"     , &Tau_LeadingTrackCharge);

  
  
  //Jets
  EvtTree->Branch("Jet_Pt"                          , &Jet_Pt);
  EvtTree->Branch("Jet_Eta"                         , &Jet_Eta);
  EvtTree->Branch("Jet_Phi"                         , &Jet_Phi);
  EvtTree->Branch("Jet_M"                           , &Jet_M);
  EvtTree->Branch("Jet_E"                           , &Jet_E);
  EvtTree->Branch("Jet_JetArea"                     , &Jet_JetArea);
  EvtTree->Branch("Jet_nTks"                        , &Jet_nTks);
  EvtTree->Branch("Jet_ChargedMultiplicity"         , &Jet_ChargedMultiplicity);
  EvtTree->Branch("Jet_NeutralMultiplicity"         , &Jet_NeutralMultiplicity);
  EvtTree->Branch("Jet_NeutralHadronEnergyFraction" , &Jet_NeutralHadronEnergyFraction);
  EvtTree->Branch("Jet_NeutralEmEnergyFraction"     , &Jet_NeutralEmEnergyFraction);
  EvtTree->Branch("Jet_ChargedHadronEnergyFraction" , &Jet_ChargedHadronEnergyFraction);
  EvtTree->Branch("Jet_MuonEnergyFraction"          , &Jet_MuonEnergyFraction);
  EvtTree->Branch("Jet_ChargedEmEnergyFraction"     , &Jet_ChargedEmEnergyFraction);

  EvtTree->Branch("Jet_bDis_JBP"                    , &Jet_bDis_JBP);
  EvtTree->Branch("Jet_bDis_JP"                     , &Jet_bDis_JP);
  EvtTree->Branch("Jet_bDis_TCHP"                   , &Jet_bDis_TCHP);
  EvtTree->Branch("Jet_bDis_TCHE"                   , &Jet_bDis_TCHE);
  EvtTree->Branch("Jet_bDis_SVHP"                   , &Jet_bDis_SVHP);
  EvtTree->Branch("Jet_bDis_SVHE"                   , &Jet_bDis_SVHE);
  EvtTree->Branch("Jet_bDis_CMVA"                   , &Jet_bDis_CMVA);
  
  EvtTree->Branch("Jet_HasGenJet"                   , &Jet_HasGenJet);
  EvtTree->Branch("Jet_GenJet_Pt"                   , &Jet_GenJet_Pt);
  EvtTree->Branch("Jet_GenJet_Eta"                  , &Jet_GenJet_Eta);
  EvtTree->Branch("Jet_GenJet_Phi"                  , &Jet_GenJet_Phi);
  EvtTree->Branch("Jet_GenJet_M"                    , &Jet_GenJet_M);
  EvtTree->Branch("Jet_GenJet_E"                    , &Jet_GenJet_E);
  EvtTree->Branch("Jet_GenJet_Status"               , &Jet_GenJet_Status);
  EvtTree->Branch("Jet_GenJet_PdgId"                , &Jet_GenJet_PdgId);



  //PU-Jets
  EvtTree->Branch("PUJet_Pt"                          , &PUJet_Pt);
  EvtTree->Branch("PUJet_Eta"                         , &PUJet_Eta);
  EvtTree->Branch("PUJet_Phi"                         , &PUJet_Phi);
  EvtTree->Branch("PUJet_M"                           , &PUJet_M);
  EvtTree->Branch("PUJet_E"                           , &PUJet_E);
  EvtTree->Branch("PUJet_JetArea"                     , &PUJet_JetArea);
  EvtTree->Branch("PUJet_nTks"                        , &PUJet_nTks);
  EvtTree->Branch("PUJet_ChargedMultiplicity"         , &PUJet_ChargedMultiplicity);
  EvtTree->Branch("PUJet_NeutralMultiplicity"         , &PUJet_NeutralMultiplicity);
  EvtTree->Branch("PUJet_NeutralHadronEnergyFraction" , &PUJet_NeutralHadronEnergyFraction);
  EvtTree->Branch("PUJet_NeutralEmEnergyFraction"     , &PUJet_NeutralEmEnergyFraction);
  EvtTree->Branch("PUJet_ChargedHadronEnergyFraction" , &PUJet_ChargedHadronEnergyFraction);
  EvtTree->Branch("PUJet_MuonEnergyFraction"          , &PUJet_MuonEnergyFraction);
  EvtTree->Branch("PUJet_ChargedEmEnergyFraction"     , &PUJet_ChargedEmEnergyFraction);

  EvtTree->Branch("PUJet_bDis_JBP"                    , &PUJet_bDis_JBP);
  EvtTree->Branch("PUJet_bDis_JP"                     , &PUJet_bDis_JP);
  EvtTree->Branch("PUJet_bDis_TCHP"                   , &PUJet_bDis_TCHP);
  EvtTree->Branch("PUJet_bDis_TCHE"                   , &PUJet_bDis_TCHE);
  EvtTree->Branch("PUJet_bDis_SVHP"                   , &PUJet_bDis_SVHP);
  EvtTree->Branch("PUJet_bDis_SVHE"                   , &PUJet_bDis_SVHE);
  EvtTree->Branch("PUJet_bDis_CMVA"                   , &PUJet_bDis_CMVA);
  
  EvtTree->Branch("PUJet_HasGenJet"                   , &PUJet_HasGenJet);
  EvtTree->Branch("PUJet_GenJet_Pt"                   , &PUJet_GenJet_Pt);
  EvtTree->Branch("PUJet_GenJet_Eta"                  , &PUJet_GenJet_Eta);
  EvtTree->Branch("PUJet_GenJet_Phi"                  , &PUJet_GenJet_Phi);
  EvtTree->Branch("PUJet_GenJet_M"                    , &PUJet_GenJet_M);
  EvtTree->Branch("PUJet_GenJet_E"                    , &PUJet_GenJet_E);
  EvtTree->Branch("PUJet_GenJet_Status"               , &PUJet_GenJet_Status);
  EvtTree->Branch("PUJet_GenJet_PdgId"                , &PUJet_GenJet_PdgId);

  
  InitializeContainers();

}

// ------------ method called once each job just after ending the event loop  ------------
void 
MyNtupleMaker::endJob() 
{
}

void MyNtupleMaker::InitializeContainers(void)
{
  
  /// Event
  RunNumber     = -1;
  EvtNumber     = -1;
  
  //MET
  MET_Px = -666.;
  MET_Py = -666.;
  MET_Pt = -666.;
  MET_Phi = -666.;
  MET_SumEt = -666.;
  MET_UncorrectedPt = -666.;
  MET_UncorrectedPhi = -666.;
  MET_UncorrectedSumEt = -666.;
  MET_CaloMETPt = -666.;
  MET_CaloMETPhi = -666.;
  MET_CaloMETSumEt = -666.;
  
  //GenJets
  GenJet_N = -1;
  GenJet_Pt.clear();
  GenJet_Eta.clear();
  GenJet_Phi.clear();
  GenJet_M.clear();
  GenJet_E.clear();
  GenJet_emE.clear();
  GenJet_hadE.clear();
  GenJet_invE.clear();
  GenJet_auxE.clear();
  GenJet_VertexX.clear();
  GenJet_VertexY.clear();
  GenJet_VertexZ.clear();
  GenJet_GenpPdgId.clear();
  GenJet_GenpPt.clear();
  GenJet_GenpEta.clear();
  GenJet_GenpPhi.clear();
  GenJet_GenpE.clear();

  

  //GenP
  GenP_N = -1;
  GenP_Pt.clear();
  GenP_Eta.clear();
  GenP_Phi.clear();
  GenP_M.clear();
  GenP_E.clear();
  GenP_PdgId.clear();
  GenP_Charge.clear();
  GenP_Status.clear();
  GenP_VertexX.clear();
  GenP_VertexY.clear();
  GenP_VertexZ.clear();
  GenP_Mothers.clear();
  GenP_Daughters.clear();


  /// Electrons
  Elec_N = -1;
  Elec_Pt.clear();
  Elec_Eta.clear();
  Elec_Phi.clear();
  Elec_M.clear();
  Elec_E.clear();
  Elec_Id.clear();
  Elec_Charge.clear();

  Elec_SCl_Eta.clear();
  Elec_SCl_EtaWidth.clear();
  Elec_SCl_Phi.clear();
  Elec_SCl_PhiWidth.clear();
  Elec_SCl_E.clear();
  Elec_SCl_RawE.clear();
  Elec_SCl_PreShowerE.clear();
  Elec_SCl_PreShower1E.clear();
  Elec_SCl_PreShower2E.clear();
  Elec_SCl_PositionR.clear();

  Elec_HasGsfTrack.clear();
  Elec_GsfTrack_D0.clear();
  Elec_GsfTrack_Z0.clear();
  Elec_GsfTrack_D0Error.clear();
  Elec_GsfTrack_Z0Error.clear();
  Elec_GsfTrack_PV_Dxy.clear();
  Elec_GsfTrack_PV_Z0.clear();
  Elec_GsfTrack_RP_Dxy.clear();
  Elec_GsfTrack_RP_Z0.clear();
  Elec_GsfTrack_BS_Dxy.clear();
  Elec_GsfTrack_BS_Z0.clear();
  Elec_GsfTrack_DxyError.clear();
  //Elec_GsfTrack_Z0Error.clear();
  Elec_GsfTrack_NormalizedChi2.clear();

  Elec_IP3d.clear();
  Elec_IP3dError.clear();
  Elec_IP2d.clear();
  Elec_IP2dError.clear();
  Elec_IP3dBS.clear();
  Elec_IP3dBSError.clear();
  Elec_IP2dBS.clear();
  Elec_IP2dBSError.clear();


  //Muons
  Muon_Pt.clear();
  Muon_Eta.clear();
  Muon_Phi.clear();
  Muon_M.clear();
  Muon_E.clear();
  Muon_Id.clear();
  Muon_Charge.clear();
  
  Muon_IP3d.clear();
  Muon_IP3dError.clear();
  Muon_IP2d.clear();
  Muon_IP2dError.clear();
  Muon_IP3dBS.clear();
  Muon_IP3dBSError.clear();
  Muon_IP2dBS.clear();
  Muon_IP2dBSError.clear();

  Muon_HasGlobalTrack.clear();
  Muon_GlobalTrack_D0.clear();
  Muon_GlobalTrack_Z0.clear();
  Muon_GlobalTrack_D0Error.clear();
  Muon_GlobalTrack_Z0Error.clear();
  Muon_GlobalTrack_PV_Dxy.clear();
  Muon_GlobalTrack_PV_Z0.clear();
  Muon_GlobalTrack_RP_Dxy.clear();
  Muon_GlobalTrack_RP_Z0.clear();
  Muon_GlobalTrack_BS_Dxy.clear();
  Muon_GlobalTrack_BS_Z0.clear();
  Muon_GlobalTrack_DxyError.clear();
  //Muon_GlobalTrack_Z0Error.clear();
  Muon_GlobalTrack_NormalizedChi2.clear();
  
  Muon_GlobalTrack_Pt.clear();
  Muon_GlobalTrack_Eta.clear();
  Muon_GlobalTrack_Phi.clear();
  Muon_GlobalTrack_PtError.clear();
  Muon_GlobalTrack_EtaError.clear();
  Muon_GlobalTrack_PhiError.clear();
  Muon_GlobalTrack_Charge.clear();


  Muon_HasInnerTrack.clear();
  Muon_InnerTrack_D0.clear();
  Muon_InnerTrack_Z0.clear();
  Muon_InnerTrack_D0Error.clear();
  Muon_InnerTrack_Z0Error.clear();
  Muon_InnerTrack_PV_Dxy.clear();
  Muon_InnerTrack_PV_Z0.clear();
  Muon_InnerTrack_RP_Dxy.clear();
  Muon_InnerTrack_RP_Z0.clear();
  Muon_InnerTrack_BS_Dxy.clear();
  Muon_InnerTrack_BS_Z0.clear();
  Muon_InnerTrack_DxyError.clear();
  //Muon_InnerTrack_Z0Error.clear();
  Muon_InnerTrack_NormalizedChi2.clear();
  
  Muon_InnerTrack_Pt.clear();
  Muon_InnerTrack_Eta.clear();
  Muon_InnerTrack_Phi.clear();
  Muon_InnerTrack_PtError.clear();
  Muon_InnerTrack_EtaError.clear();
  Muon_InnerTrack_PhiError.clear();
  Muon_InnerTrack_Charge.clear();


  Muon_HasBestTrack.clear();
  Muon_BestTrackType.clear();
  Muon_BestTrack_D0.clear();
  Muon_BestTrack_Z0.clear();
  Muon_BestTrack_D0Error.clear();
  Muon_BestTrack_Z0Error.clear();
  Muon_BestTrack_PV_Dxy.clear();
  Muon_BestTrack_PV_Z0.clear();
  Muon_BestTrack_RP_Dxy.clear();
  Muon_BestTrack_RP_Z0.clear();
  Muon_BestTrack_BS_Dxy.clear();
  Muon_BestTrack_BS_Z0.clear();
  Muon_BestTrack_DxyError.clear();
  //Muon_BestTrack_Z0Error.clear();
  Muon_BestTrack_NormalizedChi2.clear();
  
  Muon_BestTrack_Pt.clear();
  Muon_BestTrack_Eta.clear();
  Muon_BestTrack_Phi.clear();
  Muon_BestTrack_PtError.clear();
  Muon_BestTrack_EtaError.clear();
  Muon_BestTrack_PhiError.clear();
  Muon_BestTrack_Charge.clear();


  //Taus
  Tau_Pt.clear();
  Tau_Eta.clear();
  Tau_Phi.clear();
  Tau_M.clear();
  Tau_E.clear();
  Tau_Id.clear();
  Tau_Charge.clear();
  Tau_DecayMode.clear();
  Tau_IsCaloTau.clear();
  
  Tau_hasLeadChargedHadrCand.clear();
  Tau_LeadingTrackPt.clear();
  Tau_LeadingTrackEta.clear();
  Tau_LeadingTrackPhi.clear();
  Tau_LeadingTrackM.clear();
  Tau_LeadingTrackE.clear();
  Tau_LeadingTrackEt.clear();
  Tau_LeadingTrackId.clear();
  Tau_LeadingTrackCharge.clear();

  

  //Jets
  Jet_Pt.clear();
  Jet_Eta.clear();
  Jet_Phi.clear();
  Jet_M.clear();
  Jet_E.clear();
  Jet_JetArea.clear();
  Jet_nTks.clear();
  Jet_ChargedMultiplicity.clear();
  Jet_NeutralMultiplicity.clear();
  Jet_NeutralHadronEnergyFraction.clear();
  Jet_NeutralEmEnergyFraction.clear();
  Jet_ChargedHadronEnergyFraction.clear();
  Jet_MuonEnergyFraction.clear();
  Jet_ChargedEmEnergyFraction.clear();

  Jet_bDis_JBP.clear();
  Jet_bDis_JP.clear();
  Jet_bDis_TCHP.clear();
  Jet_bDis_TCHE.clear();
  Jet_bDis_SVHP.clear();
  Jet_bDis_SVHE.clear();
  Jet_bDis_CMVA.clear();

  Jet_HasGenJet.clear();
  Jet_GenJet_Pt.clear();
  Jet_GenJet_Eta.clear();
  Jet_GenJet_Phi.clear();
  Jet_GenJet_M.clear();
  Jet_GenJet_E.clear();
  Jet_GenJet_Status.clear();
  Jet_GenJet_PdgId.clear();


  //PU-Jets
  PUJet_Pt.clear();
  PUJet_Eta.clear();
  PUJet_Phi.clear();
  PUJet_M.clear();
  PUJet_E.clear();
  PUJet_JetArea.clear();
  PUJet_nTks.clear();
  PUJet_ChargedMultiplicity.clear();
  PUJet_NeutralMultiplicity.clear();
  PUJet_NeutralHadronEnergyFraction.clear();
  PUJet_NeutralEmEnergyFraction.clear();
  PUJet_ChargedHadronEnergyFraction.clear();
  PUJet_MuonEnergyFraction.clear();
  PUJet_ChargedEmEnergyFraction.clear();

  PUJet_bDis_JBP.clear();
  PUJet_bDis_JP.clear();
  PUJet_bDis_TCHP.clear();
  PUJet_bDis_TCHE.clear();
  PUJet_bDis_SVHP.clear();
  PUJet_bDis_SVHE.clear();
  PUJet_bDis_CMVA.clear();

  PUJet_HasGenJet.clear();
  PUJet_GenJet_Pt.clear();
  PUJet_GenJet_Eta.clear();
  PUJet_GenJet_Phi.clear();
  PUJet_GenJet_M.clear();
  PUJet_GenJet_E.clear();
  PUJet_GenJet_Status.clear();
  PUJet_GenJet_PdgId.clear();

}

// ------------ method called when starting to processes a run  ------------
/*
void 
MyNtupleMaker::beginRun(edm::Run const&, edm::EventSetup const&)
{
}
*/

// ------------ method called when ending the processing of a run  ------------
/*
void 
MyNtupleMaker::endRun(edm::Run const&, edm::EventSetup const&)
{
}
*/

// ------------ method called when starting to processes a luminosity block  ------------
/*
void 
MyNtupleMaker::beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}
*/

// ------------ method called when ending the processing of a luminosity block  ------------
/*
void 
MyNtupleMaker::endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}
*/

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
MyNtupleMaker::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(MyNtupleMaker);
