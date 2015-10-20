#ifndef TreeAnalyserReco_cxx
#define TreeAnalyserReco_cxx

#include <typeinfo>

#define TREEDEFINITIONRECO TreeDefinitionReco

#include "TreeAnalyserReco.h"
#include "L1Tracks.C"

void TreeAnalyserReco::InitSelector()
{
  s = new L1Tracks(this);
}

#endif // TreeAnalyserReco_cxx
