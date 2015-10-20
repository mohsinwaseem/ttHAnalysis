#ifndef L1TkTauParticle_h
#define L1TkTauParticle_h

// System
#include <iostream>

// User
#include "AuxTools.C"

using namespace std;

class L1TkTauParticle{     
 public:
  // Constructors/Destructors
  L1TkTauParticle();
  
  L1TkTauParticle(int caloTau_Index,
		  int matchTk_Index,
		  double matchTk_deltaR,
		  vector<int> sigTks_Index,
		  vector<int> isoTks_Index,
		  double vtxIso,
		  double relIso,
		  double sigCone_minDeltaR, 
		  double sigCone_maxDeltaR, 
		  double isoCone_minDeltaR, 
		  double isoCone_maxDeltaR);

  ~L1TkTauParticle() {};
  
  // Function declaration
  int GetCaloTau() const { return caloTau_Index_;}

  int GetMatchTk()   const { return matchTk_Index_;}

  double GetVtxIso()  const { return vtxIso_;}

  double GetRelIso()  const { return relIso_;}

  vector<int> GetSigConeTks()  const { return sigTks_Index_;}

  vector<int> GetIsoConeTks()  const { return isoTks_Index_;} 

  void SetCaloTau(int caloTau_Index) { caloTau_Index_ = caloTau_Index;}

  void SetSignalConeSize(double deltaR_min, double deltaR_max);

  void SetIsolationConeSize(double deltaR_min, double deltaR_max);

  void SetMatchTk(int matchTk_Index) { matchTk_Index_ = matchTk_Index;}

  void SetMatchTkDeltaR(double matchTk_deltaR) { matchTk_deltaR_ = matchTk_deltaR;}

  void SetMatchGenp(int matchGenp_Index, double matchGenp_deltaR);

  void SetVtxIso(double vtxIso) { vtxIso_ = vtxIso;}

  void SetRelIso(double relIso) { relIso_ = relIso;}

  void SetSigConeTks(vector<int> sigTksIndices) { sigTks_Index_ = sigTksIndices;}

  void SetIsoConeTks(vector<int> isoTksIndices) { isoTks_Index_ = isoTksIndices;}

  void PrintProperties(void);

  // Variable declaration
  int caloTau_Index_;
  int matchTk_Index_;
  double matchTk_deltaR_;
  int matchGenp_Index_;
  double matchGenp_deltaR_;
  vector<int> sigTks_Index_;
  vector<int> isoTks_Index_;
  double vtxIso_;
  double relIso_;
  double sigCone_minDeltaR_;
  double sigCone_maxDeltaR_;
  double isoCone_minDeltaR_;
  double isoCone_maxDeltaR_;

 private:
  AuxTools auxTools; 
  
};

#endif
