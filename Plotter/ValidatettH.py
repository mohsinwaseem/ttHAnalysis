#!/usr/bin/env python
###############################################################
### All imported modules
###############################################################
import ROOT
import os
import sys
import numpy
import math
import tools.plotter as m_plotter
import tools.histos as m_histos
import tools.styles as m_styles
import tools.cuts as m_cuts
import tools.aux as m_aux
#import rootplot
#from tools.variables import *

###############################################################
### Options here
###############################################################
bBatchMode     = True
bVerbose       = False
bSavePlots     = True

inputPath      = "/home/athermw/Research/ttHAnalysis/Macros/Validation/Validation_Histograms_"

mySavePath     = ""
mySaveFormats  = ["png"]
histoFolder    = ""
datasetList    = ["ttH125"]
nameExt        = ""

datasetPaths = {}
datasetPaths["ttH125"]            = inputPath + "ttH125%s.root"        %(nameExt)
#datasetPaths["VBF"]               = inputPath + "VBF%s.root"          %(nameExt)
#datasetPaths["SinglePionPlus"]    = inputPath + "onepionplus%s.root"  %(nameExt)
#datasetPaths["SinglePionMinus"]   = inputPath + "onepionminus%s.root" %(nameExt)
#datasetPaths["SingleTauOneProng"] = inputPath + "onetaugun1p%s.root"  %(nameExt)
#datasetPaths["TauThreeProngsEnr"] = inputPath + "twotaugun3p%s.root"  %(nameExt)
#datasetPaths["TTbar"]             = inputPath + "ttbar%s.root"        %(nameExt)
#datasetPaths["HPlus160"]          = inputPath + "litehiggs%s.root"    %(nameExt)
#datasetPaths["HPlus200"]          = inputPath + "heavyhiggs%s.root"   %(nameExt)

### Histogram Global Options
yMin       = 1E+00 #1E-04 #1E+00
yMax       = None  #1E+00 #None
yMinRatio  = 0.0
yMaxRatio  = 5.0
bRatio     = False
bInvRatio  = False
ratioLabel = "ratio"
normFactor = "One" #"One" #None

############################################################### 
### Histogram Options
############################################################### 
Et = {"xLabel": "E_{T}"           , "xUnits": "GeV", "xMin": 0.00 , "xMax": 100.0, "binWidthX": 2.0 , "xCutLines": [5], "xCutBoxes": [], 
      "gridX": True, "logX": False, "logXRatio": False,
      "yLabel": "Entries / %0.0f" , "yUnits": ""     , "yMin": yMin, "yMax": yMax , "binWidthY": None, "yCutLines": [] , "yCutBoxes": [], 
      "gridY": True, "logY": True , "logYRatio": False,
      "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": normFactor, 
      "drawOptions": "P", "legOptions": "LP" }

Eta = {"xLabel": "#eta"            , "xUnits": ""     , "xMin": -2.6 , "xMax": +2.6 , "binWidthX": 0.2 , "xCutLines": [0], "xCutBoxes": [], 
       "gridX": True, "logX": False, "logXRatio": False, 
       "yLabel": "Entries / %0.2f" , "yUnits": ""     , "yMin": yMin, "yMax": yMax , "binWidthY": None, "yCutLines": [] , "yCutBoxes": [], 
       "gridY": True, "logY": True , "logYRatio": False, 
       "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": normFactor, 
       "drawOptions": "P", "legOptions": "LP" }


ChiSigD = {"xLabel": "#chi^{2} / %0.1f"   , "xUnits": "", "xMin": None, "xMax": None, "binWidthX": None, "xCutLines": [], "xCutBoxes": [], 
           "gridX": False, "logX": False,
           "yLabel": "#sigma D0 /%f ", "yUnits": "cm", "yMin": None, "yMax": None, "binWidthY": None, "yCutLines": [], "yCutBoxes": [], 
           "gridY": False, "logY": False ,
           "zLabel": "Entries"            , "zUnits": ""   , "zMin": None, "zMax": None   , "zCutLinesErrors": False, "zCutLines": [], 
           "zCutBoxes": [], "gridZ": False, "logZ": False,
           "drawOptions": "COLZ", "xLegMin": 0.62, "xLegMax": 0.85, "yLegMin": 0.68, "yLegMax": 0.82 }

ChiSigZ = {"xLabel": "#chi^{2} / %0.1f"   , "xUnits": "", "xMin": None, "xMax": None, "binWidthX": None, "xCutLines": [], "xCutBoxes": [], 
           "gridX": False, "logX": False,
           "yLabel": "#sigma Z0/%f ", "yUnits": "cm", "yMin": None, "yMax": None, "binWidthY": None, "yCutLines": [], "yCutBoxes": [], 
           "gridY": False, "logY": False ,
           "zLabel": "Entries"            , "zUnits": ""   , "zMin": None, "zMax": None   , "zCutLinesErrors": False, "zCutLines": [], 
           "zCutBoxes": [], "gridZ": False, "logZ": False,
           "drawOptions": "COLZ", "xLegMin": 0.62, "xLegMax": 0.85, "yLegMin": 0.68, "yLegMax": 0.82 }

ChiSigPhi = {"xLabel": "#chi^{2} / %0.1f"   , "xUnits": "", "xMin": None, "xMax": None, "binWidthX": None, "xCutLines": [], "xCutBoxes": [], 
             "gridX": False, "logX": False,
             "yLabel": "#sigma #phi0/%f ", "yUnits": "", "yMin": None, "yMax": None, "binWidthY": None, "yCutLines": [], "yCutBoxes": [], 
             "gridY": False, "logY": False ,
             "zLabel": "Entries"            , "zUnits": ""   , "zMin": None, "zMax": None   , "zCutLinesErrors": False, "zCutLines": [], 
             "zCutBoxes": [], "gridZ": False, "logZ": False,
             "drawOptions": "COLZ", "xLegMin": 0.62, "xLegMax": 0.85, "yLegMin": 0.68, "yLegMax": 0.82 }

ChiSigT = {"xLabel": "#chi^{2} / %0.1f"   , "xUnits": "", "xMin": None, "xMax": None, "binWidthX": None, "xCutLines": [], "xCutBoxes": [], 
           "gridX": False, "logX": False,
           "yLabel": "#sigma T/%f ", "yUnits": "", "yMin": None, "yMax": None, "binWidthY": None, "yCutLines": [], "yCutBoxes": [], 
           "gridY": False, "logY": False ,
           "zLabel": "Entries"            , "zUnits": ""   , "zMin": None, "zMax": None   , "zCutLinesErrors": False, "zCutLines": [], 
           "zCutBoxes": [], "gridZ": False, "logZ": False,
           "drawOptions": "COLZ", "xLegMin": 0.62, "xLegMax": 0.85, "yLegMin": 0.68, "yLegMax": 0.82 }

ChiSigRinv = {"xLabel": "#chi^{2} / %0.1f"   , "xUnits": "", "xMin": None, "xMax": None, "binWidthX": None, "xCutLines": [], "xCutBoxes": [], 
              "gridX": False, "logX": False,
              "yLabel": "#sigma R^{-1} /%f", "yUnits": "cm^{-1}", "yMin": None, "yMax": None, "binWidthY": None, "yCutLines": [], "yCutBoxes": [], 
              "gridY": False, "logY": False ,
              "zLabel": "Entries"            , "zUnits": ""   , "zMin": None, "zMax": None   , "zCutLinesErrors": False, "zCutLines": [], 
              "zCutBoxes": [], "gridZ": False, "logZ": False,
              "drawOptions": "COLZ", "xLegMin": 0.62, "xLegMax": 0.85, "yLegMin": 0.68, "yLegMax": 0.82 }

D0SigD0 = {"xLabel": "#d_{0} / %0.1f"   , "xUnits": "cm", "xMin": None, "xMax": None, "binWidthX": None, "xCutLines": [], "xCutBoxes": [], 
           "gridX": False, "logX": False,
           "yLabel": "#sigma d_{0} /%f", "yUnits": "cm", "yMin": None, "yMax": None, "binWidthY": None, "yCutLines": [], "yCutBoxes": [], 
           "gridY": False, "logY": False ,
           "zLabel": "Entries"            , "zUnits": ""   , "zMin": None, "zMax": None   , "zCutLinesErrors": False, "zCutLines": [], 
           "zCutBoxes": [], "gridZ": False, "logZ": False,
           "drawOptions": None, "xLegMin": 0.62, "xLegMax": 0.85, "yLegMin": 0.68, "yLegMax": 0.82 }

Z0SigZ0 = {"xLabel": "#z_{0} / %0.1f"   , "xUnits": "cm", "xMin": None, "xMax": None, "binWidthX": None, "xCutLines": [], "xCutBoxes": [], 
           "gridX": False, "logX": False,
           "yLabel": "#sigma z_{0} /%f", "yUnits": "cm", "yMin": None, "yMax": None, "binWidthY": None, "yCutLines": [], "yCutBoxes": [], 
           "gridY": False, "logY": False ,
           "zLabel": "Entries"            , "zUnits": ""   , "zMin": None, "zMax": None   , "zCutLinesErrors": False, "zCutLines": [], 
           "zCutBoxes": [], "gridZ": False, "logZ": False,
           "drawOptions": "COLZ", "xLegMin": 0.62, "xLegMax": 0.85, "yLegMin": 0.68, "yLegMax": 0.82 }

PtSigRInv = {"xLabel": "#p_{T} / %0.1f"   , "xUnits": "GeV/c", "xMin": None, "xMax": None, "binWidthX": None, "xCutLines": [], "xCutBoxes": [], 
             "gridX": False, "logX": False,
             "yLabel": "#sigma R^{-1} /%f", "yUnits": "cm^{-1}", "yMin": None, "yMax": None, "binWidthY": None, "yCutLines": [], "yCutBoxes": [], 
             "gridY": False, "logY": False ,
             "zLabel": "Entries"            , "zUnits": ""   , "zMin": None, "zMax": None   , "zCutLinesErrors": False, "zCutLines": [], 
             "zCutBoxes": [], "gridZ": False, "logZ": False,
             "drawOptions": "COLZ", "xLegMin": 0.62, "xLegMax": 0.85, "yLegMin": 0.68, "yLegMax": 0.82 }

Cand = {"xLabel": "Candidates"  , "xUnits": "", "xMin": None , "xMax": None, "binWidthX": None , "xCutLines": [], "xCutBoxes": [], 
        "gridX": True, "logX": False, "logXRatio": False,
        "yLabel": "Entries / %0.0f" , "yUnits": ""     , "yMin": 0, "yMax": 1.1 , "binWidthY": None, "yCutLines": [] , "yCutBoxes": [], 
        "gridY": True, "logY": False , "logYRatio": False,
        "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": normFactor, 
        "drawOptions": "P",  "xLegMin": 0.62, "xLegMax": 0.85, "yLegMin": 0.68, "yLegMax": 0.82}

PV_match = {"xLabel": "|z_{L1}-z_{Genp}|", "xUnits": "cm", "xMin": 0 , "xMax": 2 , "binWidthX": None , "xCutLines": [], "xCutBoxes": [], 
            "gridX": True, "logX": False, "logXRatio": False, 
            "yLabel": "Entries / %0.2f" , "yUnits": "", "yMin": 0.6, "yMax": 1.0499 , "binWidthY": None, "yCutLines": [] , "yCutBoxes": [], 
            "gridY": True, "logY": False , "logYRatio": False, 
            "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": normFactor, 
            "drawOptions": "P", "legOptions": "LP",  "xLegMin":0.70, "xLegMax":0.89, "yLegMin":0.40, "yLegMax":0.54  }

PV = {"xLabel": "z_{L1}-z_{Genp}", "xUnits": "cm", "xMin": -10 , "xMax": +10 , "binWidthX": None , "xCutLines": [], "xCutBoxes": [], 
      "gridX": True, "logX": False, "logXRatio": False, 
      "yLabel": "Entries / %0.2f" , "yUnits": "", "yMin": 0.0001, "yMax": 2 , "binWidthY": None, "yCutLines": [] , "yCutBoxes": [], 
      "gridY": True, "logY": True , "logYRatio": False, 
      "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": normFactor, 
      "drawOptions": "P", "legOptions": "LP",  "xLegMin":0.70, "xLegMax":0.89, "yLegMin":0.68, "yLegMax":0.82  }


bDisPar = {"xLabel": "Parton Flavour"            , "xUnits": ""     , "xMin": None , "xMax": None , "binWidthX": None , "xCutLines": [], "xCutBoxes": [], 
           "gridX": True, "logX": False, "logXRatio": False, 
           "yLabel": "bDis Value / %0.2f" , "yUnits": ""     , "yMin": 1E-2, "yMax": None , "binWidthY": None, "yCutLines": [] , "yCutBoxes": [], 
           "gridY": True, "logY": False , "logYRatio": False, 
           "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": normFactor, 
           "drawOptions": "P", "legOptions": "LP" ,  "xLegMin":0.5, "xLegMax":0.7, "yLegMin":0.85, "yLegMax":0.99}

bDisHad = {"xLabel": "Hadron Flavour"            , "xUnits": ""     , "xMin": None , "xMax": None , "binWidthX": None , "xCutLines": [], "xCutBoxes": [], 
           "gridX": True, "logX": False, "logXRatio": False, 
           "yLabel": "bDis Value / %0.2f" , "yUnits": ""     , "yMin": 1E-2, "yMax": None , "binWidthY": None, "yCutLines": [] , "yCutBoxes": [], 
           "gridY": True, "logY": False , "logYRatio": False, 
           "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": normFactor, 
           "drawOptions": "P", "legOptions": "LP" ,  "xLegMin":0.5, "xLegMax":0.7, "yLegMin":0.85, "yLegMax":0.99}


DecayMode = {"xLabel": "Decay Mode"            , "xUnits": ""     , "xMin": None , "xMax": None , "binWidthX": None , "xCutLines": [], "xCutBoxes": [], 
             "gridX": True, "logX": False, "logXRatio": False, 
             "yLabel": "bDis Value / %0.2f" , "yUnits": ""     , "yMin": 1E-5, "yMax": None , "binWidthY": None, "yCutLines": [] , "yCutBoxes": [], 
             "gridY": True, "logY": True , "logYRatio": False, 
             "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": normFactor, 
             "drawOptions": "P", "legOptions": "LP" ,  "xLegMin":0.5, "xLegMax":0.7, "yLegMin":0.85, "yLegMax":0.99}

############################################################### 
### Group Histograms
############################################################### 
#L1CaloTau_Et  = m_histos.TH1orTH2( histoFolder, "L1CaloTau_Et" , "Legend Name", None, **Et  )
#L1CaloTau_Eta = m_histos.TH1orTH2( histoFolder, "L1CaloTau_Eta", "Legend Name", None, **Eta )

JetBDisParJP    = m_histos.TH1orTH2( histoFolder, "hJet_ParFl_bDisJP_px"           , "bDis_JP", None, **bDisPar )
JetBDisHadJP    = m_histos.TH1orTH2( histoFolder, "hJet_HadFl_bDisJP_px"           , "bDis_JP", None, **bDisHad )
#JetBDisParCMVA  = m_histos.TH1orTH2( histoFolder, "hJet_ParFl_bDisCMVA"         , "Legend Name", None, **bDisPar )
#JetBDisHadCMVA  = m_histos.TH1orTH2( histoFolder, "hJet_HadFl_bDisCMVA"         , "Legend Name", None, **bDisHad )

DecayMode    = m_histos.TH1orTH2( histoFolder, "hDecayMode"           , "DecayMode ttH", None, **DecayMode )

###############################################################
### Main
###############################################################
def DoPlots(hList, datasetList):

    p = m_plotter.Plotter( bVerbose, bBatchMode )
    for dataset in datasetList:
        p.AddDataset(dataset, datasetPaths[dataset])
    p.AddHisto(hList)
    p.Draw(THStackDrawOpt="nostack", bStackInclusive = False)
    p.SaveHistos(bSavePlots, mySavePath, mySaveFormats)

    return

###############################################################
if __name__ == "__main__":

    #DoPlots([JetBDisParJP],datasetList)
    DoPlots([DecayMode],datasetList)
