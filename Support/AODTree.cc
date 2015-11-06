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


// system include files
#include <memory>

#include <iostream>
#include <sstream>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"


#include "TFile.h"
#include "TTree.h"
#include "TThreadSlots.h"
#include "TROOT.h"
#include "Compression.h"

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

  
    //Genp
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

 //****************************************************************************
   // GenParticles
   //****************************************************************************
   edm::Handle<reco::GenParticleCollection> genParticlesHandle;                            
   iEvent.getByLabel("genParticles",genParticlesHandle);
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


  InitializeContainers();
}

void AODTree::InitializeContainers(void)
{
   RunNumber     = -1;
  EvtNumber     = -1;

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
