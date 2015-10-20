#ifndef TreeReaderMC_h
#define TreeReaderMC_h

#include <vector>

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

#include "TreeDefinitionGenP.h"

#include "FileOpener.C"
#include "TreeReaderReco.C"

class TreeReaderMC : public TreeReaderReco, public virtual TREEDEFINITIONGENP
{
  public:
  TreeReaderMC() { 
    std::cout << " TreeReaderMC : The constructor needs some arguments \n"; 
  };
  TreeReaderMC(const std::string SamplePath, const std::string SampleName, TTree *tree=0) :
  TreeReaderReco(SamplePath, SampleName, tree) { InitGenP(fChain); };
};

#endif

#ifdef TreeReaderMC_cxx

// Nothing goes here

#endif // #ifdef TreeReaderMC_cxx
