#ifndef TreeDefinitionGenP_h
#define TreeDefinitionGenP_h

#include "TreeDefinitionBase.h"

class TreeDefinitionGenP : public virtual TreeDefinitionBase
{
 public:

   Int_t           RunNumber;
   Int_t           EvtNumber;
   //GenJets
   Int_t GenJet_N;
   std::vector<float> *GenJet_Pt;
   std::vector<float> *GenJet_Eta;
   std::vector<float> *GenJet_Phi;
   std::vector<float> *GenJet_M;
   std::vector<float> *GenJet_E;
   std::vector<float> *GenJet_emE;
   std::vector<float> *GenJet_hadE;
   std::vector<float> *GenJet_invE;
   std::vector<float> *GenJet_auxE;
   std::vector<float> *GenJet_VertexX;
   std::vector<float> *GenJet_VertexY;
   std::vector<float> *GenJet_VertexZ;
   std::vector<vector<Int_t > > *GenJet_GenpPdgId;
   std::vector<vector<float > > *GenJet_GenpPt;
   std::vector<vector<float > > *GenJet_GenpEta;
   std::vector<vector<float > > *GenJet_GenpPhi;
   std::vector<vector<float > > *GenJet_GenpE;
   
   
   //Genp
   Int_t GenP_N;
   std::vector<float> *GenP_Pt;
   std::vector<float> *GenP_Eta;
   std::vector<float> *GenP_Phi;
   std::vector<float> *GenP_M;
   std::vector<float> *GenP_E;
   std::vector<Int_t> *GenP_PdgId;
   std::vector<Int_t> *GenP_Charge;
   std::vector<Int_t> *GenP_Status;
   std::vector<float> *GenP_VertexX;
   std::vector<float> *GenP_VertexY;
   std::vector<float> *GenP_VertexZ;
   std::vector< std::vector<unsigned short> > *GenP_Mothers;
   std::vector< std::vector<unsigned short> > *GenP_Daughters; 
   
   // List of branches
   TBranch   *b_RunNumber;
   TBranch   *b_EvtNumber;
   //GenJets
   TBranch   *b_GenJet_N;
   TBranch   *b_GenJet_Pt;
   TBranch   *b_GenJet_Eta;
   TBranch   *b_GenJet_Phi;
   TBranch   *b_GenJet_M;
   TBranch   *b_GenJet_E;
   TBranch   *b_GenJet_emE;
   TBranch   *b_GenJet_hadE;
   TBranch   *b_GenJet_invE;
   TBranch   *b_GenJet_auxE;
   TBranch   *b_GenJet_VertexX;
   TBranch   *b_GenJet_VertexY;
   TBranch   *b_GenJet_VertexZ;
   TBranch   *b_GenJet_GenpPdgId;
   TBranch   *b_GenJet_GenpPt;
   TBranch   *b_GenJet_GenpEta;
   TBranch   *b_GenJet_GenpPhi;
   TBranch   *b_GenJet_GenpE;
   
   
   //Genp
   TBranch   *b_GenP_N;
   TBranch   *b_GenP_Pt;
   TBranch   *b_GenP_Eta;
   TBranch   *b_GenP_Phi;
   TBranch   *b_GenP_M;
   TBranch   *b_GenP_E;
   TBranch   *b_GenP_PdgId;
   TBranch   *b_GenP_Charge;
   TBranch   *b_GenP_Status;
   TBranch   *b_GenP_VertexX;
   TBranch   *b_GenP_VertexY;
   TBranch   *b_GenP_VertexZ;
   TBranch   *b_GenP_Mothers;
   TBranch   *b_GenP_Daughters;



   virtual void InitGenP(TTree *tree);

};

void TreeDefinitionGenP::InitGenP(TTree *tree)
{
  // The Init() function is called when the selector needs to initialize
  // a new tree or chain. Typically here the branch addresses and branch
  // pointers of the tree will be set.
  // It is normally not necessary to make changes to the generated
  // code, but the routine can be extended by the user if needed.
  // Init() will be called many times when running on PROOF
  // (once per file to be processed).

  // Set object pointer
  //GenJets
  GenJet_Pt = 0;
  GenJet_Eta = 0;
  GenJet_Phi = 0;
  GenJet_M = 0;
  GenJet_E = 0;
  GenJet_emE = 0;
  GenJet_hadE = 0;
  GenJet_invE = 0;
  GenJet_auxE = 0;
  GenJet_VertexX = 0;
  GenJet_VertexY = 0;
  GenJet_VertexZ = 0;
  GenJet_GenpPdgId = 0;
  GenJet_GenpPt = 0;
  GenJet_GenpEta = 0;
  GenJet_GenpPhi = 0;
  GenJet_GenpE = 0;
  
  
  //Genp
  GenP_Pt = 0;
  GenP_Eta = 0;
  GenP_Phi = 0;
  GenP_M = 0;
  GenP_E = 0;
  GenP_PdgId = 0;
  GenP_Charge = 0;
  GenP_Status = 0;
  GenP_VertexX = 0;
  GenP_VertexY = 0;
  GenP_VertexZ = 0;
  GenP_Mothers = 0;
  GenP_Daughters = 0;
  


   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("RunNumber", &RunNumber, &b_RunNumber);
   fChain->SetBranchAddress("EvtNumber", &EvtNumber, &b_EvtNumber);

   std::cout << "I N F O ! TreeDefinitionGenP::InitGenP(...) - Setting GenJet addresses." << std::endl;
   fChain->SetBranchAddress("GenJet_N"          , &GenJet_N         , &b_GenJet_N);
   fChain->SetBranchAddress("GenJet_Pt"         , &GenJet_Pt        , &b_GenJet_Pt);
   fChain->SetBranchAddress("GenJet_Eta"        , &GenJet_Eta       , &b_GenJet_Eta);
   fChain->SetBranchAddress("GenJet_Phi"        , &GenJet_Phi       , &b_GenJet_Phi);
   fChain->SetBranchAddress("GenJet_M"          , &GenJet_M         , &b_GenJet_M);
   fChain->SetBranchAddress("GenJet_E"          , &GenJet_E         , &b_GenJet_E);
   fChain->SetBranchAddress("GenJet_emE"        , &GenJet_emE       , &b_GenJet_emE);
   fChain->SetBranchAddress("GenJet_hadE"       , &GenJet_hadE      , &b_GenJet_hadE);
   fChain->SetBranchAddress("GenJet_invE"       , &GenJet_invE      , &b_GenJet_invE);
   fChain->SetBranchAddress("GenJet_auxE"       , &GenJet_auxE      , &b_GenJet_auxE);
   fChain->SetBranchAddress("GenJet_VertexX"    , &GenJet_VertexX   , &b_GenJet_VertexX);
   fChain->SetBranchAddress("GenJet_VertexY"    , &GenJet_VertexY   , &b_GenJet_VertexY);
   fChain->SetBranchAddress("GenJet_VertexZ"    , &GenJet_VertexZ   , &b_GenJet_VertexZ);
   fChain->SetBranchAddress("GenJet_GenpPdgId"  , &GenJet_GenpPdgId , &b_GenJet_GenpPdgId);
   fChain->SetBranchAddress("GenJet_GenpPt"     , &GenJet_GenpPt    , &b_GenJet_GenpPt);
   fChain->SetBranchAddress("GenJet_GenpEta"    , &GenJet_GenpEta   , &b_GenJet_GenpEta);
   fChain->SetBranchAddress("GenJet_GenpPhi"    , &GenJet_GenpPhi   , &b_GenJet_GenpPhi);
   fChain->SetBranchAddress("GenJet_GenpE"      , &GenJet_GenpE     , &b_GenJet_GenpE);


   std::cout << "I N F O ! TreeDefinitionGenP::InitGenP(...) - Setting GenPar addresses." << std::endl;
   fChain->SetBranchAddress("GenP_N"          , &GenP_N         , &b_GenP_N);
   fChain->SetBranchAddress("GenP_Pt"         , &GenP_Pt        , &b_GenP_Pt);
   fChain->SetBranchAddress("GenP_Eta"        , &GenP_Eta       , &b_GenP_Eta);
   fChain->SetBranchAddress("GenP_Phi"        , &GenP_Phi       , &b_GenP_Phi);
   fChain->SetBranchAddress("GenP_M"          , &GenP_M         , &b_GenP_M);
   fChain->SetBranchAddress("GenP_E"          , &GenP_E         , &b_GenP_E);
   fChain->SetBranchAddress("GenP_PdgId"      , &GenP_PdgId     , &b_GenP_PdgId);
   fChain->SetBranchAddress("GenP_Charge"     , &GenP_Charge    , &b_GenP_Charge);
   fChain->SetBranchAddress("GenP_Status"     , &GenP_Status    , &b_GenP_Status);
   fChain->SetBranchAddress("GenP_VertexX"    , &GenP_VertexX   , &b_GenP_VertexX);
   fChain->SetBranchAddress("GenP_VertexY"    , &GenP_VertexY   , &b_GenP_VertexY);
   fChain->SetBranchAddress("GenP_VertexZ"    , &GenP_VertexZ   , &b_GenP_VertexZ);
   fChain->SetBranchAddress("GenP_Mothers"    , &GenP_Mothers   , &b_GenP_Mothers);
   fChain->SetBranchAddress("GenP_Daughters"  , &GenP_Daughters , &b_GenP_Daughters);

}

#endif  // TreeDefinitionGenP_h
