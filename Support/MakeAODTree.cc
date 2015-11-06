// -*- C++ -*-
//
// Package:    AODTest/MakeAODTree
// Class:      AODTree
// 
/**\class AODTree AODTree.cc AODTest/AODTree/plugins/AODTree.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Mohsan Waseem Ather
//         Created:  Wed, 04 Nov 2015 10:29:36 GMT
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

class AODTree : public edm::EDAnalyzer {
   public:
      explicit AODTree(const edm::ParameterSet&);
      ~AODTree();

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
AODTree::AODTree(const edm::ParameterSet& iConfig)

{
  TFile& f = fs->file();
  f.SetCompressionAlgorithm(ROOT::kZLIB);
  f.SetCompressionLevel(9);

   //now do what ever initialization is needed

}


AODTree::~AODTree()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void
AODTree::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
using namespace edm;

   RunNumber   = iEvent.id().run();
   EvtNumber   = iEvent.id().event();

//   std::cout<< "This is a test Run"<<std::endl;


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
AODTree::beginJob()
{
EvtTree = fs->make<TTree>("EvtTree", "Evt Tree");


  /// Event
  EvtTree->Branch("RunNumber"                  , &RunNumber);
  EvtTree->Branch("EvtNumber"                  , &EvtNumber);



InitializeContainers();
}

void AODTree::InitializeContainers(void)
{
   RunNumber     = -1;
  EvtNumber     = -1;



}

// ------------ method called once each job just after ending the event loop  ------------
void 
AODTree::endJob() 
{
}

// ------------ method called when starting to processes a run  ------------
/*
void 
AODTree::beginRun(edm::Run const&, edm::EventSetup const&)
{
}
*/

// ------------ method called when ending the processing of a run  ------------
/*
void 
AODTree::endRun(edm::Run const&, edm::EventSetup const&)
{
}
*/

// ------------ method called when starting to processes a luminosity block  ------------
/*
void 
AODTree::beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}
*/

// ------------ method called when ending the processing of a luminosity block  ------------
/*
void 
AODTree::endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}
*/

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
AODTree::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(AODTree);
