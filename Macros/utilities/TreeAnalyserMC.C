#ifndef TreeAnalyserMC_cxx
#define TreeAnalyserMC_cxx

#define USING_MC

#define TREEDEFINITIONGENP TreeDefinitionGenP
#define TREEDEFINITIONRECO TreeDefinitionReco

#include <typeinfo>

#include "TreeAnalyserMC.h"
#include "L1Tracks.C"

void TreeAnalyserMC::InitSelector()
{
  s = new L1Tracks(this);
}

#endif //TreeAnalyserMC_cxx
 
