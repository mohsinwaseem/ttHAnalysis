#ifndef L1Tracks_h
#define L1Tracks_h

#include "TreeDefinitionReco.h"

#ifdef USING_MC
#include "TreeDefinitionGenP.h" 
#define TREEANALYSER TreeAnalyserMC
#include "TreeAnalyserMC.h"
#else
#include "TreeDefinitionReco.h"
#define TREEANALYSER TreeAnalyserReco
#include "TreeAnalyserReco.h"
#endif // USING_MC

using namespace std;

class L1Tracks
{
 public:
  // Constructors/Destructors
  L1Tracks(TREEANALYSER* t_) { t = t_; };

  // Member Functions
  bool SelectTracks(int iTrack, 
		    const string selectionType);

  bool SelectPixTracks(int iTrack, 
		       const string selectionType);
  
  double GetTrackCharge(const int iTrack);

  double GetPixTrackCharge(const int iTrack);

  double GetTrackPt(const int iTrack);

  double GetPixTrackPt(const int iTrack);
  
  double GetTrackD0(const int iTrack);

  double GetTrackD0Mag(const int iTrack);

  double GetTrackD0Sign(const int iTrack);

  double GetTrackD0Phi(const int iTrack);
  
  int GetPixelIndexOfTrack(const int tk_Index);

  double GetPixTrackD0(const int iTrack);

  double GetPixTrackD0Sig(const int iTrack);

  double GetTrackPOCAzSig(const int iTrack);

  double GetPixTrackPOCAzSig(const int iTrack);

  double GetTrackSigmaPt(const int iTrack);

  double GetPixTrackSigmaPt(const int iTrack);

  double GetTrackRedChiSq(const int iTrack, 
			  const int nFitParams);

  double GetPixTrackRedChiSq(const int iTrack);
  
  double GetTrackStubPtConsistency(const int iTrack);
      
  void PrintTrackProperties(const int iTrack);

  void PrintPixTrackProperties(const int iPixTrack,
			       bool bPrintRefTTTrack);

  unsigned int GetNumOfStubs(const int iTrack);

  unsigned int GetNumOfPSStubs(const int iTrack);

  unsigned int GetNumOfBarrelStubs(const int iTrack);
    
  unsigned int GetNumOfEndcapStubs(const int iTrack);

  TLorentzVector GetP4FromTracks(const vector<int> tks_Index);

  TLorentzVector GetP4FromPixTracks(const vector<int> tks_Index);

  int GetChargeFromTracks(const vector<int> tks_Index);

  int GetChargeFromPixTracks(const vector<int> tks_Index);

  // Variables
  TREEANALYSER* t;

 private:
  // Variables
  MCTools mcTools;
  AuxTools auxTools;

};

#endif //ObjectSelect_h
