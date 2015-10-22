###############################################################
### Author .........: Alexandros X. Attikis 
### Institute ......: University Of Cyprus (UCY)
### Email ..........: attikis@cern.ch
###############################################################

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
import tools.aux as m_aux

###############################################################
### Histogram Options
###############################################################
yMin       = 0.0
yMax       = None
yMinRatio  = 0.5
yMaxRatio  = 2.9
bRatio     = True
bInvRatio  = False
ratioLabel = "Ratio"
normFactor = "One"
bLogY      = False
bLogX      = False

###############################################################
### Histogram Attributes
###############################################################
kwargs   = {}

N = {"xLabel": "Multiplicity"     , "xUnits": ""       , "xMin": -0.5, "xMax": +9.5, "binWidthX": None, "xCutLines": [], "xCutBoxes": [], "gridX": True, "logX": False, "logXRatio": False, 
     "yLabel": "Entries / %0.0f"  , "yUnits": ""       , "yMin": +0.0, "yMax": +1.0, "binWidthY": None, "yCutLines": [], "yCutBoxes": [], "gridY": True, "logY": bLogY, "logYRatio": False, 
     "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": "One", "drawOptions": "P", "legOptions": "LP", 
     "xLegMin": 0.70, "xLegMax": 0.88, "yLegMin": 0.72, "yLegMax": 0.80 }

Pt = {"xLabel": "p_{T}"           , "xUnits": "GeV/c", "xMin": +0.00, "xMax": +150.0, "binWidthX": +5.0, "xCutLines": [20.0], "xCutBoxes": [], "gridX": True, "logX": False, "logXRatio": False,
      "yLabel": "Entries / %0.0f" , "yUnits": ""     , "yMin": yMin, "yMax": yMax   , "binWidthY": None, "yCutLines": [], "yCutBoxes": [], "gridY": True, "logY": bLogY, "logYRatio": False,
      "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": normFactor, "drawOptions": "P", "legOptions": "LP", 
      "xLegMin": 0.70, "xLegMax": 0.88, "yLegMin": 0.72, "yLegMax": 0.80 }

Et = {"xLabel": "E_{T}"           , "xUnits": "GeV"  , "xMin": +0.00, "xMax": +150.0, "binWidthX": None, "xCutLines": [20.0], "xCutBoxes": [], "gridX": True, "logX": False, "logXRatio": False,
      "yLabel": "Entries / %0.0f" , "yUnits": ""     , "yMin": yMin , "yMax": yMax  , "binWidthY": None, "yCutLines": []   , "yCutBoxes": [], "gridY": True, "logY": bLogY, "logYRatio": False,
      "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": normFactor, "drawOptions": "P", "legOptions": "LP", 
      "xLegMin": 0.70, "xLegMax": 0.88, "yLegMin": 0.72, "yLegMax": 0.80 }

Eta = {"xLabel": "#eta"            , "xUnits": ""     , "xMin": -3.0 , "xMax": +3.0 , "binWidthX": 0.2, "xCutLines": [], "xCutBoxes": [], "gridX": True, "logX": False, "logXRatio": False, 
       "yLabel": "Entries / %0.2f" , "yUnits": ""     , "yMin": yMin, "yMax": yMax  , "binWidthY": None, "yCutLines": []          , "yCutBoxes": [], "gridY": True, "logY": bLogY, "logYRatio": False, 
       "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": normFactor, "drawOptions": "P", "legOptions": "LP", 
       "xLegMin": 0.70, "xLegMax": 0.88, "yLegMin": 0.72, "yLegMax": 0.80 }

Phi = {"xLabel": "#phi"            , "xUnits": "rads" , "xMin": -3.6, "xMax": +3.6 , "binWidthX": 0.2 , "xCutLines": [], "xCutBoxes": [], "gridX": True, "logX": False, "logXRatio": False, 
       "yLabel": "Entries / %0.2f" , "yUnits": ""     , "yMin": yMin, "yMax": yMax , "binWidthY": None, "yCutLines": [], "yCutBoxes": [], "gridY": True, "logY": bLogY, "logYRatio": False, 
       "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": normFactor, "drawOptions": "P", "legOptions": "LP", 
       "xLegMin": 0.70, "xLegMax": 0.88, "yLegMin": 0.72, "yLegMax": 0.80 }

Mass = {"xLabel": "m_{inv}"        , "xUnits": "GeV/c^2" , "xMin": 0.0 , "xMax": +2.0 , "binWidthX": 0.02, "xCutLines": [], "xCutBoxes": [], "gridX": True, "logX": False, "logXRatio": False, 
        "yLabel": "Entries / %0.2f", "yUnits": ""        , "yMin": yMin, "yMax": yMax , "binWidthY": None, "yCutLines": [], "yCutBoxes": [], "gridY": True, "logY": bLogY, "logYRatio": False, 
        "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": normFactor, "drawOptions": "P", "legOptions": "LP", 
        "xLegMin": 0.70, "xLegMax": 0.88, "yLegMin": 0.72, "yLegMax": 0.80 }

Charge = {"xLabel": "Charge"         , "xUnits": "e", "xMin": -3.0 , "xMax": +3.0 , "binWidthX": None, "xCutLines": [], "xCutBoxes": [], "gridX": True, "logX": False, "logXRatio": False, 
          "yLabel": "Entries / %0.0f", "yUnits": "" , "yMin": yMin , "yMax": yMax , "binWidthY": None, "yCutLines": [], "yCutBoxes": [], "gridY": True, "logY": bLogY, "logYRatio": False, 
          "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": normFactor, "drawOptions": "P", "legOptions": "LP", 
          "xLegMin": 0.70, "xLegMax": 0.88, "yLegMin": 0.72, "yLegMax": 0.80 }

Status = {"xLabel": "Status"         , "xUnits": "", "xMin": 0.0 , "xMax": +3.0 , "binWidthX": None, "xCutLines": [], "xCutBoxes": [], "gridX": True, "logX": False, "logXRatio": False, 
          "yLabel": "Entries / %0.0f", "yUnits": "", "yMin": yMin , "yMax": yMax, "binWidthY": None, "yCutLines": [], "yCutBoxes": [], "gridY": True, "logY": bLogY, "logYRatio": False, 
          "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": normFactor, "drawOptions": "P", "legOptions": "LP", 
          "xLegMin": 0.70, "xLegMax": 0.88, "yLegMin": 0.72, "yLegMax": 0.80 }

VertexX = {"xLabel": "x_{vtx}"         , "xUnits": "cm", "xMin": -1.5, "xMax": +1.5, "binWidthX": None , "xCutLines": [], "xCutBoxes": [], "gridX": True, "logX": False, "logXRatio": False, 
           "yLabel": "Entries / %0.2f" , "yUnits": ""  , "yMin": yMin, "yMax": yMax, "binWidthY": None, "yCutLines": [] , "yCutBoxes": [], "gridY": True, "logY": bLogY, "logYRatio": False, 
           "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": normFactor, "drawOptions": "P", "legOptions": "LP",
           "xLegMin": 0.70, "xLegMax": 0.88, "yLegMin": 0.72, "yLegMax": 0.80 }

VertexY= {"xLabel": "y_{vtx}"         , "xUnits": "cm", "xMin": -1.5, "xMax": +1.5, "binWidthX": None, "xCutLines": [], "xCutBoxes": [], "gridX": True, "logX": False, "logXRatio": False, 
          "yLabel": "Entries / %0.2f" , "yUnits": ""  , "yMin": yMin, "yMax": yMax, "binWidthY": None, "yCutLines": [] , "yCutBoxes": [], "gridY": True, "logY": bLogY, "logYRatio": False, 
          "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": normFactor, "drawOptions": "P", "legOptions": "LP", 
          "xLegMin": 0.70, "xLegMax": 0.88, "yLegMin": 0.72, "yLegMax": 0.80 }

VertexZ = {"xLabel": "z_{vtx}"         , "xUnits": "cm", "xMin": -25.0, "xMax": +25.0, "binWidthX": None, "xCutLines": [], "xCutBoxes": [], "gridX": True, "logX": False, "logXRatio": False, 
           "yLabel": "Entries / %0.1f" , "yUnits": ""  , "yMin": yMin , "yMax": yMax , "binWidthY": None, "yCutLines": [] , "yCutBoxes": [], "gridY": True, "logY": bLogY, "logYRatio": False, 
           "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": normFactor, "drawOptions": "P", "legOptions": "LP",
           "xLegMin": 0.70, "xLegMax": 0.88, "yLegMin": 0.72, "yLegMax": 0.80 }

DecayMode = {"xLabel": "Decay Mode"     , "xUnits": "", "xMin": +0.0, "xMax": +30.0, "binWidthX": None, "xCutLines": [], "xCutBoxes": [[1.0, +8.0, ROOT.kGreen+2]], "gridX": True, "logX": False, 
             "yLabel": "Entries / %0.0f", "yUnits": "", "yMin": None, "yMax": None , "binWidthY": None, "yCutLines": [], "xCutBoxes": []                     , "gridY": True, "logY": bLogY, 
             "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": None, "drawOptions": "P", "legOptions": "LP",
             "xLegMin": 0.70, "xLegMax": 0.88, "yLegMin": 0.72, "yLegMax": 0.80 }

PdgId = {"xLabel": "PdgId"          , "xUnits": "", "xMin": -600.0, "xMax": +600.0, "binWidthX": 1.0 , "xCutLines": [], "xCutBoxes": [], "gridX": True, "logX": False, 
         "yLabel": "Entries / %0.0f", "yUnits": "", "yMin": yMin  , "yMax": yMax  , "binWidthY": None, "yCutLines": [], "xCutBoxes": [], "gridY": True, "logY": bLogY, 
         "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": normFactor, "drawOptions": "P", "legOptions": "LP" ,
         "xLegMin": 0.70, "xLegMax": 0.88, "yLegMin": 0.72, "yLegMax": 0.80 }

VisEt = {"xLabel": "E_{T}^{vis}"     , "xUnits": "GeV", "xMin": +0.00, "xMax": +150.0, "binWidthX": +5.0, "xCutLines": [20.0], "xCutBoxes": [], "gridX": True, "logX": False, "logXRatio": False,
         "yLabel": "Entries / %0.0f" , "yUnits": ""   , "yMin": yMin , "yMax": yMax  , "binWidthY": None, "yCutLines": [], "yCutBoxes": [], "gridY": True, "logY": bLogY, "logYRatio": False,
         "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": normFactor, "drawOptions": "P", "legOptions": "LP", 
         "xLegMin": 0.70, "xLegMax": 0.88, "yLegMin": 0.72, "yLegMax": 0.80 }

VisEta = {"xLabel": "#eta^{vis}"      , "xUnits": ""     , "xMin": -3.0 , "xMax": +3.0, "binWidthX": 0.04, "xCutLines": [-2.3, +2.3], "xCutBoxes": [], "gridX": True, "logX": False, "logXRatio": False, 
          "yLabel": "Entries / %0.2f" , "yUnits": ""     , "yMin": yMin, "yMax": yMax  , "binWidthY": None, "yCutLines": []          , "yCutBoxes": [], "gridY": True, "logY": bLogY, "logYRatio": False, 
          "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": normFactor, "drawOptions": "P", "legOptions": "LP", 
          "xLegMin": 0.70, "xLegMax": 0.88, "yLegMin": 0.72, "yLegMax": 0.80 }

VisPhi = {"xLabel": "#phi^{vis}"      , "xUnits": "rads" , "xMin": -3.6, "xMax": +3.6 , "binWidthX": 0.2 , "xCutLines": [], "xCutBoxes": [], "gridX": True, "logX": False, "logXRatio": False, 
          "yLabel": "Entries / %0.2f" , "yUnits": ""     , "yMin": yMin, "yMax": yMax , "binWidthY": None, "yCutLines": [], "yCutBoxes": [], "gridY": True, "logY": bLogY, "logYRatio": False, 
          "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": normFactor, "drawOptions": "P", "legOptions": "LP",
          "xLegMin": 0.70, "xLegMax": 0.88, "yLegMin": 0.72, "yLegMax": 0.80 }

VisMass = {"xLabel": "m_{inv}^{vis}"  , "xUnits": "GeV/c^2" , "xMin": 0.0 , "xMax": +2.0 , "binWidthX": 0.02, "xCutLines": [], "xCutBoxes": [], "gridX": True, "logX": False, "logXRatio": False, 
           "yLabel": "Entries / %0.2f", "yUnits": ""        , "yMin": yMin, "yMax": yMax , "binWidthY": None, "yCutLines": [], "yCutBoxes": [], "gridY": True, "logY": bLogY, "logYRatio": False, 
           "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": normFactor, "drawOptions": "P", "legOptions": "LP",
           "xLegMin": 0.70, "xLegMax": 0.88, "yLegMin": 0.72, "yLegMax": 0.80 }

LdgPt = {"xLabel": "p_{T}^{ldg}"     , "xUnits": "GeV/c", "xMin": 0.00, "xMax": 100.0, "binWidthX": +5.0, "xCutLines": [15.0], "xCutBoxes": [], "gridX": True, "logX": False, "logXRatio": False,
         "yLabel": "Entries / %0.0f" , "yUnits": ""     , "yMin": yMin, "yMax": yMax , "binWidthY": None, "yCutLines": [], "yCutBoxes": [], "gridY": True, "logY": bLogY, "logYRatio": False,
         "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": normFactor, "drawOptions": "P", "legOptions": "LP",
         "xLegMin": 0.70, "xLegMax": 0.88, "yLegMin": 0.72, "yLegMax": 0.80 }

LdgEt = {"xLabel": "E_{T}^{ldg}"     , "xUnits": "GeV", "xMin": 0.00, "xMax": 100.0, "binWidthX": +5.0, "xCutLines": [20.0], "xCutBoxes": [], "gridX": True, "logX": False, "logXRatio": False,
         "yLabel": "Entries / %0.0f" , "yUnits": ""   , "yMin": yMin, "yMax": yMax , "binWidthY": None, "yCutLines": [], "yCutBoxes": [], "gridY": True, "logY": bLogY, "logYRatio": False,
         "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": normFactor, "drawOptions": "P", "legOptions": "LP",
         "xLegMin": 0.70, "xLegMax": 0.88, "yLegMin": 0.72, "yLegMax": 0.80 }

LdgEta = {"xLabel": "#eta^{ldg}"      , "xUnits": "", "xMin": -3.0, "xMax": +3.0, "binWidthX": +0.2, "xCutLines": [], "xCutBoxes": [], "gridX": True, "logX": False, "logXRatio": False, 
          "yLabel": "Entries / %0.2f" , "yUnits": "", "yMin": yMin, "yMax": yMax, "binWidthY": None, "yCutLines": [], "yCutBoxes": [], "gridY": True, "logY": bLogY, "logYRatio": False, 
          "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": normFactor, "drawOptions": "P", "legOptions": "LP",
          "xLegMin": 0.70, "xLegMax": 0.88, "yLegMin": 0.72, "yLegMax": 0.80 }

LdgPhi = {"xLabel": "#phi^{ldg}"      , "xUnits": "rads" , "xMin": -3.6, "xMax": +3.6 , "binWidthX": +0.2, "xCutLines": [], "xCutBoxes": [], "gridX": True, "logX": False, "logXRatio": False, 
          "yLabel": "Entries / %0.2f" , "yUnits": ""     , "yMin": yMin, "yMax": yMax , "binWidthY": None, "yCutLines": [], "yCutBoxes": [], "gridY": True, "logY": bLogY, "logYRatio": False, 
          "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": normFactor, "drawOptions": "P", "legOptions": "LP",
          "xLegMin": 0.70, "xLegMax": 0.88, "yLegMin": 0.72, "yLegMax": 0.80 }

LdgMass = {"xLabel": "m_{inv}^{ldg}"        , "xUnits": "GeV/c^2" , "xMin": 0.0 , "xMax": +2.0 , "binWidthX": 0.02, "xCutLines": [], "xCutBoxes": [], "gridX": True, "logX": False, "logXRatio": False, 
           "yLabel": "Entries / %0.2f", "yUnits": ""        , "yMin": yMin, "yMax": yMax , "binWidthY": None, "yCutLines": [], "yCutBoxes": [], "gridY": True, "logY": bLogY, "logYRatio": False, 
           "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": normFactor, "drawOptions": "P", "legOptions": "LP", 
           "xLegMin": 0.70, "xLegMax": 0.88, "yLegMin": 0.72, "yLegMax": 0.80 }

LdgCharge = {"xLabel": "Charge^{ldg}"   , "xUnits": "e", "xMin": -3.0 , "xMax": +3.0 , "binWidthX": None, "xCutLines": [], "xCutBoxes": [], "gridX": True, "logX": False, "logXRatio": False, 
             "yLabel": "Entries / %0.0f", "yUnits": "" , "yMin": yMin , "yMax": yMax , "binWidthY": None, "yCutLines": [], "yCutBoxes": [], "gridY": True, "logY": bLogY, "logYRatio": False, 
             "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": normFactor, "drawOptions": "P", "legOptions": "LP",
             "xLegMin": 0.70, "xLegMax": 0.88, "yLegMin": 0.72, "yLegMax": 0.80 }

LdgPdgId = {"xLabel": "PdgId^{ldg}"    , "xUnits": "", "xMin": -600.0, "xMax": +600.0, "binWidthX": 1.0 , "xCutLines": [], "xCutBoxes": [], "gridX": True, "logX": False, 
            "yLabel": "Entries / %0.0f", "yUnits": "", "yMin": yMin  , "yMax": yMax  , "binWidthY": None, "yCutLines": []                         , "xCutBoxes": [], "gridY": True, "logY": bLogY, 
            "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": normFactor, "drawOptions": "P", "legOptions": "LP" ,
            "xLegMin": 0.70, "xLegMax": 0.88, "yLegMin": 0.72, "yLegMax": 0.80 }

LdgStatus = {"xLabel": "Status^{ldg}"   , "xUnits": "", "xMin": +0.0 , "xMax": +3.5 , "binWidthX": None, "xCutLines": [], "xCutBoxes": [], "gridX": True, "logX": False, "logXRatio": False, 
             "yLabel": "Entries / %0.0f", "yUnits": "", "yMin": yMin , "yMax": yMax , "binWidthY": None, "yCutLines": [] , "yCutBoxes": [], "gridY": True, "logY": bLogY, "logYRatio": False, 
             "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": normFactor, "drawOptions": "P", "legOptions": "LP",
             "xLegMin": 0.70, "xLegMax": 0.88, "yLegMin": 0.72, "yLegMax": 0.80 }

DeltaR = {"xLabel": "#DeltaR"        , "xUnits": "", "xMin": +0.0, "xMax": +2.0, "binWidthX": None, "xCutLines": [], "gridX": True, "logX": False, 
          "yLabel": "Entries / %0.2f", "yUnits": "", "yMin": yMin, "yMax": yMax, "binWidthY": None, "yCutLines": [], "gridY": True, "logY": bLogY, 
          "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": normFactor, "drawOptions": "P", "legOptions": "LP",
          "xLegMin": 0.70, "xLegMax": 0.88, "yLegMin": 0.72, "yLegMax": 0.80 }

Test   = {"xLabel": "z_{L1} - z_{GEN} / %0.0f", "xUnits": "cm", "xMin": -25.0 , "xMax": 25.0, "binWidthX": 0.4, "xCutLines": [], "xCutBoxes": [], "gridX": False, "logX": False,
          "yLabel": "# Tks from PV / %0.0f"   , "yUnits": ""  , "yMin": 0.0 , "yMax": None, "binWidthY": 1.0, "yCutLines": [], "yCutBoxes": [], "gridY": False, "logY": False ,
          "zLabel": "Entries"                 , "zUnits": ""  , "zMin": 1E+0, "zMax": 5E+04 , "zCutLinesErrors": True, "zCutLines": [], "zCutBoxes": [], "gridZ": False, "logZ": True,
          "drawOptions": "COLZ", "xLegMin": 0.62, "xLegMax": 0.85, "yLegMin": 0.68, "yLegMax": 0.82 }

### TF1
f1Args = {"lineColour": ROOT.kBlack, "lineStyle": ROOT.kSolid, "lineWidth": 3, "fillColour": ROOT.kBlack, "fillStyle": 0}

###############################################################
### Histograms
###############################################################
histoFolder = ""
legTitle    = ""

### Tau
hDistvsNumsumpT = m_histos.TH1orTH2( histoFolder, "hDistvsNumsumpT", legTitle , None, **Test)
h_Pt = m_histos.TH1orTH2( histoFolder, "h_Pt"     , legTitle , None, **Pt      )
