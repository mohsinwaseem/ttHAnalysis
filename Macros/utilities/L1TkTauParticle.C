#ifndef L1TkTauParticle_cxx
#define L1TkTauParticle_cxx

#include "L1TkTauParticle.h"

//****************************************************************************
L1TkTauParticle::L1TkTauParticle()
//****************************************************************************
{
  
}


 //****************************************************************************
 L1TkTauParticle::L1TkTauParticle(int caloTau_Index, 
				  int matchTk_Index, 
				  double matchTk_deltaR, 
				  vector<int> sigTks_Index, 
				  vector<int> isoTks_Index,
				  double vtxIso, 
				  double relIso,
				  double sigCone_minDeltaR, 
				  double sigCone_maxDeltaR, 
				  double isoCone_minDeltaR, 
				  double isoCone_maxDeltaR)
 //****************************************************************************
 {
  
   SetCaloTau(caloTau_Index);
   SetMatchTk(matchTk_Index);
   SetMatchTkDeltaR(matchTk_deltaR);
   SetSigConeTks(sigTks_Index);
   SetIsoConeTks(isoTks_Index);
   SetVtxIso(vtxIso);
   SetRelIso(relIso);
   SetMatchGenp(-1.0, 9999.9);
   SetSignalConeSize(sigCone_minDeltaR,  sigCone_maxDeltaR);
   SetIsolationConeSize(isoCone_minDeltaR, isoCone_maxDeltaR);
}



//****************************************************************************
void L1TkTauParticle::SetSignalConeSize(double deltaR_min, double deltaR_max)
//****************************************************************************
{
  sigCone_minDeltaR_ = deltaR_min;
  sigCone_maxDeltaR_ = deltaR_max;
  
  return;
}



//****************************************************************************
void L1TkTauParticle::SetIsolationConeSize(double deltaR_min, double deltaR_max)
//****************************************************************************
{
  isoCone_minDeltaR_ = deltaR_min;
  isoCone_maxDeltaR_ = deltaR_max;
  
  return;
}



//****************************************************************************
void L1TkTauParticle::SetMatchGenp(int matchGenp_Index, double matchGenp_deltaR) 
//****************************************************************************
{ 
  matchGenp_Index_  = matchGenp_Index;
  matchGenp_deltaR_ = matchGenp_deltaR;
  
  return;
}



//****************************************************************************
void L1TkTauParticle::PrintProperties(void)
//****************************************************************************
{
  
  Table general("iCalo | Match Tk | Match GenP | dR (Match GenP) | VtxIso (cm) | RelIso | Sig. Tks | Iso. Tks. | Sig_R (min) | Sig_R (max) | Iso_R (min) | Iso_R (max)", "Text");
  general.AddRowColumn(0, auxTools.ToString( caloTau_Index_    ) );
  general.AddRowColumn(0, auxTools.ToString( matchTk_Index_    ) );
  general.AddRowColumn(0, auxTools.ToString( matchGenp_Index_  ) );
  general.AddRowColumn(0, auxTools.ToString( matchGenp_deltaR_ ) );
  general.AddRowColumn(0, auxTools.ToString( vtxIso_           ) );
  general.AddRowColumn(0, auxTools.ToString( relIso_           ) );
  general.AddRowColumn(0, auxTools.ConvertIntVectorToString(sigTks_Index_) );
  general.AddRowColumn(0, auxTools.ConvertIntVectorToString(isoTks_Index_) );
  general.AddRowColumn(0, auxTools.ToString(sigCone_minDeltaR_ ) );
  general.AddRowColumn(0, auxTools.ToString(sigCone_maxDeltaR_ ) );
  general.AddRowColumn(0, auxTools.ToString(isoCone_minDeltaR_ ) );
  general.AddRowColumn(0, auxTools.ToString(isoCone_maxDeltaR_ ) );

  general.Print();

  return;
}

#endif
