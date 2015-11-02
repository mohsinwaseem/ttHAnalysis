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
#ti
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
dataset    = ""
nameExt    = "_NuMulti"


inputPath_ttH125     = inputPath + "ttH125%s.root"     %(nameExt)
inputPath_TTBar      = inputPath + "TTBar%s.root"      %(nameExt)
inputPath_TTW        = inputPath + "TTW%s.root"        %(nameExt)
inputPath_TTZ        = inputPath + "TTZ%s.root"        %(nameExt)
inputPath_WW         = inputPath + "WW%s.root"         %(nameExt)
inputPath_ZZ         = inputPath + "ZZ%s.root"         %(nameExt)
inputPath_WZ         = inputPath + "WZ%s.root"         %(nameExt)
inputPath_DYLLM10    = inputPath + "DYLLM10%s.root"    %(nameExt)
inputPath_DYLLM50    = inputPath + "DYLLM50%s.root"    %(nameExt)
inputPath_STtchannel = inputPath + "STtchannel%s.root" %(nameExt)
inputPath_STWt       = inputPath + "STWt%s.root"       %(nameExt)
inputPath_STWtbar    = inputPath + "STWtbar%s.root"    %(nameExt)



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
Pt = {"xLabel": "P_{T}"           , "xUnits": "GeV", "xMin": None , "xMax": 100, "binWidthX": 2.0 , "xCutLines": [], "xCutBoxes": [], 
      "gridX": True, "logX": False, "logXRatio": False,
      "yLabel": "Entries / %0.0f" , "yUnits": ""     , "yMin": 1E-5, "yMax": None , "binWidthY": None, "yCutLines": [] , "yCutBoxes": [], 
      "gridY": True, "logY": True , "logYRatio": False,
      "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": normFactor, 
      "drawOptions": "P", "legOptions": "LP" ,  "xLegMin":0.5, "xLegMax":0.7, "yLegMin":0.85, "yLegMax":0.99}

Eta = {"xLabel": "#eta"            , "xUnits": ""     , "xMin": None , "xMax": None , "binWidthX": None , "xCutLines": [], "xCutBoxes": [], 
       "gridX": True, "logX": False, "logXRatio": False, 
       "yLabel": "Entries / %0.2f" , "yUnits": ""     , "yMin": yMin, "yMax": yMax , "binWidthY": None, "yCutLines": [] , "yCutBoxes": [], 
       "gridY": True, "logY": True , "logYRatio": False, 
       "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": normFactor, 
       "drawOptions": "P", "legOptions": "LP" ,  "xLegMin":0.5, "xLegMax":0.7, "yLegMin":0.85, "yLegMax":0.99}

E = {"xLabel": "E"           , "xUnits": "GeV", "xMin": None , "xMax": None, "binWidthX": 2.0 , "xCutLines": [], "xCutBoxes": [], 
     "gridX": True, "logX": False, "logXRatio": False,
     "yLabel": "Entries / %0.0f" , "yUnits": ""     , "yMin": 1E-4, "yMax": None , "binWidthY": None, "yCutLines": [] , "yCutBoxes": [], 
     "gridY": True, "logY": True , "logYRatio": False,
     "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": normFactor, 
     "drawOptions": "P", "legOptions": "LP" ,  "xLegMin":0.5, "xLegMax":0.7, "yLegMin":0.85, "yLegMax":0.99}

Et = {"xLabel": "Et"           , "xUnits": "GeV", "xMin": None , "xMax": 3000, "binWidthX": None , "xCutLines": [], "xCutBoxes": [], 
      "gridX": True, "logX": False, "logXRatio": False,
      "yLabel": "Entries / %0.0f" , "yUnits": ""     , "yMin": 1E-5, "yMax": None , "binWidthY": None, "yCutLines": [] , "yCutBoxes": [], 
      "gridY": True, "logY": True , "logYRatio": False,
      "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": normFactor, 
      "drawOptions": "P", "legOptions": "LP" ,  "xLegMin":0.5, "xLegMax":0.7, "yLegMin":0.85, "yLegMax":0.99}


Ht = {"xLabel": "H_{T}"           , "xUnits": "GeV", "xMin": None , "xMax": None, "binWidthX": None , "xCutLines": [], "xCutBoxes": [], 
      "gridX": True, "logX": False, "logXRatio": False,
      "yLabel": "Entries / %0.0f" , "yUnits": ""     , "yMin": 1E-5, "yMax": None , "binWidthY": None, "yCutLines": [] , "yCutBoxes": [], 
      "gridY": True, "logY": True , "logYRatio": False,
      "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": normFactor, 
      "drawOptions": "P", "legOptions": "LP" ,  "xLegMin":0.5, "xLegMax":0.7, "yLegMin":0.85, "yLegMax":0.99}

MHt = {"xLabel": "MH_{T}"           , "xUnits": "GeV", "xMin": None , "xMax": None, "binWidthX": None , "xCutLines": [], "xCutBoxes": [], 
      "gridX": True, "logX": False, "logXRatio": False,
      "yLabel": "Entries / %0.0f" , "yUnits": ""     , "yMin": 1E-5, "yMax": None , "binWidthY": None, "yCutLines": [] , "yCutBoxes": [], 
      "gridY": True, "logY": True , "logYRatio": False,
      "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": normFactor, 
      "drawOptions": "P", "legOptions": "LP" ,  "xLegMin":0.5, "xLegMax":0.7, "yLegMin":0.85, "yLegMax":0.99}


Charge = {"xLabel": "Charge"           , "xUnits": "", "xMin": None , "xMax": None, "binWidthX": None , "xCutLines": [], "xCutBoxes": [], 
          "gridX": True, "logX": False, "logXRatio": False,
          "yLabel": "Entries / %0.0f" , "yUnits": ""     , "yMin": 1E-4, "yMax": None , "binWidthY": None, "yCutLines": [] , "yCutBoxes": [], 
          "gridY": True, "logY": True , "logYRatio": False,
          "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": normFactor, 
          "drawOptions": "P", "legOptions": "LP" ,  "xLegMin":0.5, "xLegMax":0.7, "yLegMin":0.85, "yLegMax":0.99}

X0 = {"xLabel": "X_{0}"            , "xUnits": "cm"     , "xMin": None , "xMax": None , "binWidthX": None , "xCutLines": [], "xCutBoxes": [], 
         "gridX": True, "logX": False, "logXRatio": False, 
         "yLabel": "Entries / %0.2f" , "yUnits": ""     , "yMin": 1E-4, "yMax": None , "binWidthY": None, "yCutLines": [] , "yCutBoxes": [], 
         "gridY": True, "logY": True , "logYRatio": False, 
         "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": normFactor, 
         "drawOptions": "P", "legOptions": "LP" ,  "xLegMin":0.63, "xLegMax":0.7, "yLegMin":0.85, "yLegMax":0.99}

Y0 = {"xLabel": "Y_{0}"            , "xUnits": "cm"     , "xMin": None , "xMax": None , "binWidthX": None , "xCutLines": [], "xCutBoxes": [], 
         "gridX": True, "logX": False, "logXRatio": False, 
         "yLabel": "Entries / %0.2f" , "yUnits": ""     , "yMin": 1E-4, "yMax": None , "binWidthY": None, "yCutLines": [] , "yCutBoxes": [], 
         "gridY": True, "logY": True , "logYRatio": False, 
         "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": normFactor, 
         "drawOptions": "P", "legOptions": "LP" ,  "xLegMin":0.63, "xLegMax":0.7, "yLegMin":0.85, "yLegMax":0.99}

Z0 = {"xLabel": "Z_{0}"            , "xUnits": "cm"     , "xMin": None , "xMax": None , "binWidthX": None , "xCutLines": [], "xCutBoxes": [], 
         "gridX": True, "logX": False, "logXRatio": False, 
         "yLabel": "Entries / %0.2f" , "yUnits": ""     , "yMin": 1E-4, "yMax": None , "binWidthY": None, "yCutLines": [] , "yCutBoxes": [], 
         "gridY": True, "logY": True , "logYRatio": False, 
         "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": normFactor, 
         "drawOptions": "P", "legOptions": "LP" ,  "xLegMin":0.63, "xLegMax":0.7, "yLegMin":0.85, "yLegMax":0.99}

D0 = {"xLabel": "d_{0}"            , "xUnits": "cm"     , "xMin": None , "xMax": None , "binWidthX": None , "xCutLines": [], "xCutBoxes": [], 
      "gridX": True, "logX": False, "logXRatio": False, 
      "yLabel": "Entries / %0.2f" , "yUnits": ""     , "yMin": 1E-4, "yMax": None , "binWidthY": None, "yCutLines": [] , "yCutBoxes": [], 
      "gridY": True, "logY": True , "logYRatio": False, 
      "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": normFactor, 
      "drawOptions": "P", "legOptions": "LP" ,  "xLegMin":0.63, "xLegMax":0.7, "yLegMin":0.85, "yLegMax":0.99}

IP3d = {"xLabel": "IP3D"            , "xUnits": "cm"     , "xMin": None , "xMax": None , "binWidthX": None , "xCutLines": [], "xCutBoxes": [], 
        "gridX": True, "logX": False, "logXRatio": False, 
        "yLabel": "Entries / %0.2f" , "yUnits": ""     , "yMin": 1E-4, "yMax": None , "binWidthY": None, "yCutLines": [] , "yCutBoxes": [], 
        "gridY": True, "logY": True , "logYRatio": False, 
        "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": normFactor, 
        "drawOptions": "P", "legOptions": "LP" ,  "xLegMin":0.63, "xLegMax":0.7, "yLegMin":0.85, "yLegMax":0.99}


IP2d = {"xLabel": "IP2D"            , "xUnits": "cm"     , "xMin": None , "xMax": None , "binWidthX": None , "xCutLines": [], "xCutBoxes": [], 
        "gridX": True, "logX": False, "logXRatio": False, 
        "yLabel": "Entries / %0.2f" , "yUnits": ""     , "yMin": 1E-4, "yMax": None , "binWidthY": None, "yCutLines": [] , "yCutBoxes": [], 
        "gridY": True, "logY": True , "logYRatio": False, 
        "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": normFactor, 
        "drawOptions": "P", "legOptions": "LP" ,  "xLegMin":0.63, "xLegMax":0.7, "yLegMin":0.85, "yLegMax":0.99}

Lxy = {"xLabel": "Lxy"            , "xUnits": "cm"     , "xMin": 0 , "xMax": None , "binWidthX": None , "xCutLines": [], "xCutBoxes": [], 
       "gridX": True, "logX": False, "logXRatio": False, 
       "yLabel": "Entries / %0.2f" , "yUnits": ""     , "yMin": 1E-4, "yMax": None , "binWidthY": None, "yCutLines": [] , "yCutBoxes": [], 
       "gridY": True, "logY": True , "logYRatio": False, 
       "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": normFactor, 
       "drawOptions": "P", "legOptions": "LP" ,  "xLegMin":0.63, "xLegMax":0.7, "yLegMin":0.85, "yLegMax":0.99}

Lxyz = {"xLabel": "Lxyz"            , "xUnits": "cm"     , "xMin": 0 , "xMax": None , "binWidthX": None , "xCutLines": [], "xCutBoxes": [], 
        "gridX": True, "logX": False, "logXRatio": False, 
        "yLabel": "Entries / %0.2f" , "yUnits": ""     , "yMin": 1E-4, "yMax": None , "binWidthY": None, "yCutLines": [] , "yCutBoxes": [], 
        "gridY": True, "logY": True , "logYRatio": False, 
        "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": normFactor, 
        "drawOptions": "P", "legOptions": "LP" ,  "xLegMin":0.63, "xLegMax":0.7, "yLegMin":0.85, "yLegMax":0.99}

IP3dError = {"xLabel": "IP3D Err"            , "xUnits": ""     , "xMin": None , "xMax": None , "binWidthX": None , "xCutLines": [], "xCutBoxes": [], 
             "gridX": True, "logX": False, "logXRatio": False, 
             "yLabel": "Entries / %0.2f" , "yUnits": ""     , "yMin": 1E-4, "yMax": None , "binWidthY": None, "yCutLines": [] , "yCutBoxes": [], 
             "gridY": True, "logY": True , "logYRatio": False, 
             "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": normFactor, 
             "drawOptions": "P", "legOptions": "LP" ,  "xLegMin":0.63, "xLegMax":0.7, "yLegMin":0.85, "yLegMax":0.99}


IP2dError = {"xLabel": "IP2D Err"            , "xUnits": ""     , "xMin": None , "xMax": None , "binWidthX": None , "xCutLines": [], "xCutBoxes": [], 
             "gridX": True, "logX": False, "logXRatio": False, 
             "yLabel": "Entries / %0.2f" , "yUnits": ""     , "yMin": 1E-4, "yMax": None , "binWidthY": None, "yCutLines": [] , "yCutBoxes": [], 
             "gridY": True, "logY": True , "logYRatio": False, 
             "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": normFactor, 
             "drawOptions": "P", "legOptions": "LP" ,  "xLegMin":0.63, "xLegMax":0.7, "yLegMin":0.85, "yLegMax":0.99}


Area = {"xLabel": "JetArea"            , "xUnits": "cm^{2}"     , "xMin": None , "xMax": None , "binWidthX": None , "xCutLines": [], "xCutBoxes": [], 
        "gridX": True, "logX": False, "logXRatio": False, 
        "yLabel": "Entries / %0.2f" , "yUnits": ""     , "yMin": 1E-4, "yMax": None , "binWidthY": None, "yCutLines": [] , "yCutBoxes": [], 
        "gridY": True, "logY": True , "logYRatio": False, 
        "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": normFactor, 
        "drawOptions": "P", "legOptions": "LP" ,  "xLegMin":0.63, "xLegMax":0.75, "yLegMin":0.85, "yLegMax":0.99}

dPhi = {"xLabel": "#Delta #phi"            , "xUnits": ""     , "xMin": None , "xMax": None , "binWidthX": None , "xCutLines": [], "xCutBoxes": [], 
        "gridX": True, "logX": False, "logXRatio": False, 
        "yLabel": "Entries / %0.2f" , "yUnits": ""     , "yMin": 1E-4, "yMax": None , "binWidthY": None, "yCutLines": [] , "yCutBoxes": [], 
        "gridY": True, "logY": True , "logYRatio": False, 
        "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": normFactor, 
        "drawOptions": "P", "legOptions": "LP" ,  "xLegMin":0.5, "xLegMax":0.7, "yLegMin":0.85, "yLegMax":0.99}

RIso = {"xLabel": "R^{Iso}"            , "xUnits": ""     , "xMin": None , "xMax": None , "binWidthX": None , "xCutLines": [], "xCutBoxes": [], 
        "gridX": True, "logX": False, "logXRatio": False, 
        "yLabel": "Entries / %0.2f" , "yUnits": ""     , "yMin": 1E-4, "yMax": None , "binWidthY": None, "yCutLines": [] , "yCutBoxes": [], 
        "gridY": True, "logY": True , "logYRatio": False, 
        "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": normFactor, 
        "drawOptions": "P", "legOptions": "LP" ,  "xLegMin":0.5, "xLegMax":0.7, "yLegMin":0.85, "yLegMax":0.99}

bDisPar = {"xLabel": "Parton Flavour"            , "xUnits": ""     , "xMin": None , "xMax": None , "binWidthX": None , "xCutLines": [], "xCutBoxes": [], 
           "gridX": True, "logX": False, "logXRatio": False, 
           "yLabel": "bDis Value / %0.2f" , "yUnits": ""     , "yMin": 1E-4, "yMax": None , "binWidthY": None, "yCutLines": [] , "yCutBoxes": [], 
           "gridY": True, "logY": True , "logYRatio": False, 
           "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": normFactor, 
           "drawOptions": "P", "legOptions": "LP" ,  "xLegMin":0.5, "xLegMax":0.7, "yLegMin":0.85, "yLegMax":0.99}

bDisHad = {"xLabel": "Hadron Flavour"            , "xUnits": ""     , "xMin": None , "xMax": None , "binWidthX": None , "xCutLines": [], "xCutBoxes": [], 
           "gridX": True, "logX": False, "logXRatio": False, 
           "yLabel": "bDis Value / %0.2f" , "yUnits": ""     , "yMin": 1E-4, "yMax": None , "binWidthY": None, "yCutLines": [] , "yCutBoxes": [], 
           "gridY": True, "logY": True , "logYRatio": False, 
           "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": normFactor, 
           "drawOptions": "P", "legOptions": "LP" ,  "xLegMin":0.5, "xLegMax":0.7, "yLegMin":0.85, "yLegMax":0.99}

D0sig = {"xLabel": "d_{0}/#sigma d_{0}"  , "xUnits": ""     , "xMin": None , "xMax": None , "binWidthX": None , "xCutLines": [], "xCutBoxes": [], 
         "gridX": True, "logX": False, "logXRatio": False, 
         "yLabel": "Entries / %0.2f" , "yUnits": ""     , "yMin": 1E-4, "yMax": None , "binWidthY": None, "yCutLines": [] , "yCutBoxes": [], 
         "gridY": True, "logY": True , "logYRatio": False, 
         "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": normFactor, 
         "drawOptions": "P", "legOptions": "LP" ,  "xLegMin":0.5, "xLegMax":0.7, "yLegMin":0.55, "yLegMax":0.69}

Z0sig = {"xLabel": "z_{0}/#sigma z_{0}"  , "xUnits": ""     , "xMin": None , "xMax": None , "binWidthX": 100 , "xCutLines": [], "xCutBoxes": [], 
         "gridX": True, "logX": False, "logXRatio": False, 
         "yLabel": "Entries / %0.2f" , "yUnits": ""     , "yMin": 1E-4, "yMax": None , "binWidthY": None, "yCutLines": [] , "yCutBoxes": [], 
         "gridY": True, "logY": True , "logYRatio": False, 
         "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": normFactor, 
         "drawOptions": "P", "legOptions": "LP" ,  "xLegMin":0.5, "xLegMax":0.7, "yLegMin":0.35, "yLegMax":0.49}

Ptsig = {"xLabel": "p_{T}/#sigma R^{-1}"  , "xUnits": ""     , "xMin": None , "xMax": None , "binWidthX": 2500 , "xCutLines": [], "xCutBoxes": [], 
         "gridX": True, "logX": False, "logXRatio": False, 
         "yLabel": "Entries / %0.2f" , "yUnits": ""     , "yMin": 1E-4, "yMax": None , "binWidthY": None, "yCutLines": [] , "yCutBoxes": [], 
         "gridY": True, "logY": True , "logYRatio": False, 
         "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": normFactor, 
         "drawOptions": "P", "legOptions": "LP" ,  "xLegMin":0.5, "xLegMax":0.7, "yLegMin":0.55, "yLegMax":0.69}


Tknum = {"xLabel": "Track Multiplicity"  , "xUnits": ""     , "xMin": None , "xMax": None , "binWidthX": None , "xCutLines": [], "xCutBoxes": [], 
         "gridX": True, "logX": False, "logXRatio": False, 
         "yLabel": "Entries / %0.2f" , "yUnits": ""     , "yMin": None, "yMax": None , "binWidthY": None, "yCutLines": [] , "yCutBoxes": [], 
         "gridY": True, "logY": False , "logYRatio": False, 
         "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": normFactor, 
         "drawOptions": "P", "legOptions": "LP" ,  "xLegMin":0.5, "xLegMax":0.7, "yLegMin":0.55, "yLegMax":0.69}

Chi = {"xLabel": "#chi^{2}"           , "xUnits": "", "xMin": None , "xMax": None, "binWidthX": 2.0 , "xCutLines": [], "xCutBoxes": [], 
       "gridX": True, "logX": False, "logXRatio": False,
       "yLabel": "Entries / %0.0f" , "yUnits": ""     , "yMin":  1E-4, "yMax": None , "binWidthY": None, "yCutLines": [] , "yCutBoxes": [], 
       "gridY": True, "logY": True , "logYRatio": False,
       "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": normFactor, 
       "drawOptions": "P", "legOptions": "LP" ,  "xLegMin":0.5, "xLegMax":0.7, "yLegMin":0.55, "yLegMax":0.69}

RedChi = {"xLabel": "#chi^{2}/n d.o.f"           , "xUnits": "", "xMin": None , "xMax": None, "binWidthX": None , "xCutLines": [], "xCutBoxes": [], 
          "gridX": True, "logX": False, "logXRatio": False,
          "yLabel": "Entries / %0.0f" , "yUnits": ""     , "yMin":  1E-4, "yMax": None , "binWidthY": None, "yCutLines": [] , "yCutBoxes": [], 
          "gridY": True, "logY": True , "logYRatio": False,
          "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": normFactor, 
          "drawOptions": "P", "legOptions": "LP" ,  "xLegMin":0.5, "xLegMax":0.7, "yLegMin":0.85, "yLegMax":0.99}

Id = {"xLabel": "PdgId"           , "xUnits": "", "xMin": None , "xMax": None, "binWidthX": None , "xCutLines": [], "xCutBoxes": [], 
      "gridX": True, "logX": False, "logXRatio": False,
      "yLabel": "Entries / %0.0f" , "yUnits": ""     , "yMin": None, "yMax": None , "binWidthY": None, "yCutLines": [] , "yCutBoxes": [], 
      "gridY": True, "logY": False , "logYRatio": False,
      "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": normFactor, 
      "drawOptions": "P", "legOptions": "LP" ,  "xLegMin":0.5, "xLegMax":0.7, "yLegMin":0.85, "yLegMax":0.99}

Multi = {"xLabel": "Multiplicity"           , "xUnits": "", "xMin": None , "xMax": None, "binWidthX": None , "xCutLines": [], "xCutBoxes": [], 
         "gridX": True, "logX": False, "logXRatio": False,
         "yLabel": "Entries / %0.0f" , "yUnits": ""     , "yMin": None, "yMax": None , "binWidthY": None, "yCutLines": [] , "yCutBoxes": [], 
         "gridY": True, "logY": False , "logYRatio": False,
         "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": normFactor, 
         "drawOptions": "P", "legOptions": "LP" ,  "xLegMin":0.5, "xLegMax":0.7, "yLegMin":0.85, "yLegMax":0.99}


SumPT2 = {"xLabel": "#SigmaP_{T}^2"           , "xUnits": "GeV^2", "xMin": None , "xMax": None, "binWidthX": 2.0 , "xCutLines": [], "xCutBoxes": [], 
          "gridX": True, "logX": False, "logXRatio": False,
          "yLabel": "Entries / %0.0f" , "yUnits": ""     , "yMin": None, "yMax": None , "binWidthY": None, "yCutLines": [] , "yCutBoxes": [], 
          "gridY": True, "logY": False , "logYRatio": False,
          "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": normFactor, 
          "drawOptions": "P", "legOptions": "LP" ,  "xLegMin":0.5, "xLegMax":0.7, "yLegMin":0.55, "yLegMax":0.69}

SumD0Err = {"xLabel": "#Sigma #sigma d_{0}/d_{0}"           , "xUnits": "", "xMin": None , "xMax": None, "binWidthX": 2.0 , "xCutLines": [], "xCutBoxes": [], 
            "gridX": True, "logX": False, "logXRatio": False,
            "yLabel": "Entries / %0.0f" , "yUnits": ""     , "yMin": None, "yMax": None , "binWidthY": None, "yCutLines": [] , "yCutBoxes": [], 
            "gridY": True, "logY": False , "logYRatio": False,
            "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": yMaxRatio, "normaliseTo": normFactor, 
            "drawOptions": "P", "legOptions": "LP" ,  "xLegMin":0.5, "xLegMax":0.7, "yLegMin":0.55, "yLegMax":0.69}

############################################################### 
### Group Histograms
############################################################### 
#L1CaloTau_Et  = m_histos.TH1orTH2( histoFolder, "L1CaloTau_Et" , "Legend Name", None, **Et  )
#L1CaloTau_Eta = m_histos.TH1orTH2( histoFolder, "L1CaloTau_Eta", "Legend Name", None, **Eta )

###
#Electron
###
ElecPt     = m_histos.TH1orTH2( histoFolder, "hElec_Pt"          , "Legend Name", None, **Pt )
ElecEta    = m_histos.TH1orTH2( histoFolder, "hElec_Eta"         , "Legend Name", None, **Eta )
ElecE      = m_histos.TH1orTH2( histoFolder, "hElec_E"           , "Legend Name", None, **E )
ElecCharge = m_histos.TH1orTH2( histoFolder, "hElec_Charge"      , "Legend Name", None, **Charge )

ElecIP3d      = m_histos.TH1orTH2( histoFolder, "hElec_IP3d"      , "Legend Name", None, **IP3d )
ElecIP3dError = m_histos.TH1orTH2( histoFolder, "hElec_IP3dError" , "Legend Name", None, **IP3dError )
ElecIP2d      = m_histos.TH1orTH2( histoFolder, "hElec_IP2d"      , "Legend Name", None, **IP2d )
ElecIP2dError = m_histos.TH1orTH2( histoFolder, "hElec_IP2dError" , "Legend Name", None, **IP2dError )
ElecdPhiMET   = m_histos.TH1orTH2( histoFolder, "hdPhi_Elec_MET"  , "Legend Name", None, **dPhi )
ElecIso       = m_histos.TH1orTH2( histoFolder, "hElec_RIso"      , "Legend Name", None, **RIso )

ElecTkD0   = m_histos.TH1orTH2( histoFolder, "hElec_GsfTrack_D0"             , "Legend Name", None, **D0 )
ElecTkZ0   = m_histos.TH1orTH2( histoFolder, "hElec_GsfTrack_Z0"             , "Legend Name", None, **Z0 )
ElecTkChi2 = m_histos.TH1orTH2( histoFolder, "hElec_GsfTrack_NormalizedChi2" , "Legend Name", None, **RedChi )


###
#Muon
###
MuonPt     = m_histos.TH1orTH2( histoFolder, "hMuon_Pt"          , "Legend Name", None, **Pt )
MuonEta    = m_histos.TH1orTH2( histoFolder, "hMuon_Eta"         , "Legend Name", None, **Eta )
MuonE      = m_histos.TH1orTH2( histoFolder, "hMuon_E"           , "Legend Name", None, **E )
MuonCharge = m_histos.TH1orTH2( histoFolder, "hMuon_Charge"      , "Legend Name", None, **Charge )

MuonIP3d      = m_histos.TH1orTH2( histoFolder, "hMuon_IP3d"      , "Legend Name", None, **IP3d )
MuonIP3dError = m_histos.TH1orTH2( histoFolder, "hMuon_IP3dError" , "Legend Name", None, **IP3dError )
MuonIP2d      = m_histos.TH1orTH2( histoFolder, "hMuon_IP2d"      , "Legend Name", None, **IP2d )
MuonIP2dError = m_histos.TH1orTH2( histoFolder, "hMuon_IP2dError" , "Legend Name", None, **IP2dError )
MuondPhiMET   = m_histos.TH1orTH2( histoFolder, "hdPhi_Muon_MET"  , "Legend Name", None, **dPhi )
MuonIso       = m_histos.TH1orTH2( histoFolder, "hMuon_RIso"      , "Legend Name", None, **RIso )

MuonITkD0   = m_histos.TH1orTH2( histoFolder, "hMuon_InnerTrack_D0"             , "Legend Name", None, **D0 )
MuonITkZ0   = m_histos.TH1orTH2( histoFolder, "hMuon_InnerTrack_Z0"             , "Legend Name", None, **Z0 )
MuonITkChi2 = m_histos.TH1orTH2( histoFolder, "hMuon_InnerTrack_NormalizedChi2" , "Legend Name", None, **RedChi )

MuonGTkD0   = m_histos.TH1orTH2( histoFolder, "hMuon_GlobalTrack_D0"             , "Legend Name", None, **D0 )
MuonGTkZ0   = m_histos.TH1orTH2( histoFolder, "hMuon_GlobalTrack_Z0"             , "Legend Name", None, **Z0 )
MuonGTkChi2 = m_histos.TH1orTH2( histoFolder, "hMuon_GlobalTrack_NormalizedChi2" , "Legend Name", None, **RedChi )

###
#Lep
###
LeadLepPt       = m_histos.TH1orTH2( histoFolder, "hLeadingLep"          , "Legend Name", None, **Pt )
SubLeadLepPt    = m_histos.TH1orTH2( histoFolder, "hSubLeadingLep"       , "Legend Name", None, **Pt )
SubSubLeadLepPt = m_histos.TH1orTH2( histoFolder, "hSubSubLeadingLep"    , "Legend Name", None, **Pt )


###
#Tau
###
TauPt        = m_histos.TH1orTH2( histoFolder, "hTau_Pt"          , "Legend Name", None, **Pt )
TauEta       = m_histos.TH1orTH2( histoFolder, "hTau_Eta"         , "Legend Name", None, **Eta )
TauE         = m_histos.TH1orTH2( histoFolder, "hTau_E"           , "Legend Name", None, **E )
TauCharge    = m_histos.TH1orTH2( histoFolder, "hTau_Charge"      , "Legend Name", None, **Charge )
TaudPhiMET   = m_histos.TH1orTH2( histoFolder, "hdPhi_Tau_MET"    , "Legend Name", None, **dPhi )
TauLdgCHPt     = m_histos.TH1orTH2( histoFolder, "hTau_LeadChHadCand_Pt"          , "Legend Name", None, **Pt )
TauLdgCHEta    = m_histos.TH1orTH2( histoFolder, "hTau_LeadChHadCand_Eta"         , "Legend Name", None, **Eta )
TauLdgCHE      = m_histos.TH1orTH2( histoFolder, "hTau_LeadChHadCand_E"           , "Legend Name", None, **E )
TauLdgCHEt     = m_histos.TH1orTH2( histoFolder, "hTau_LeadChHadCand_Et"          , "Legend Name", None, **Et )
TauLdgCHId     = m_histos.TH1orTH2( histoFolder, "hTau_LeadChHadCand_Id"          , "Legend Name", None, **Id )
TauLdgCHCharge = m_histos.TH1orTH2( histoFolder, "hTau_LeadChHadCand_Charge"      , "Legend Name", None, **Charge )
TauLdgCHX0     = m_histos.TH1orTH2( histoFolder, "hTau_LeadChHadCand_Vx"          , "Legend Name", None, **X0 )
TauLdgCHY0     = m_histos.TH1orTH2( histoFolder, "hTau_LeadChHadCand_Vy"          , "Legend Name", None, **Y0 )
TauLdgCHZ0     = m_histos.TH1orTH2( histoFolder, "hTau_LeadChHadCand_Vz"          , "Legend Name", None, **Z0 )

###
#MET
###
METPt    = m_histos.TH1orTH2( histoFolder, "hMET_Pt"          , "Legend Name", None, **Pt )
#m_histos.TH1orTH2( histoFolder, "hMET_Phi"         , "Legend Name", None, **Pt )
METSumEt = m_histos.TH1orTH2( histoFolder, "hMET_SumEt"       , "Legend Name", None, **Et )


###
#Jet
###
JetPt     = m_histos.TH1orTH2( histoFolder, "hJet_Pt"          , "Legend Name", None, **Pt )
JetEta    = m_histos.TH1orTH2( histoFolder, "hJet_Eta"         , "Legend Name", None, **Eta )
JetE      = m_histos.TH1orTH2( histoFolder, "hJet_E"           , "Legend Name", None, **E )
JetArea   = m_histos.TH1orTH2( histoFolder, "hJet_JetArea"        , "Legend Name", None, **Area )
JetdPhiMET= m_histos.TH1orTH2( histoFolder, "hdPhi_Jet_MET"    , "Legend Name", None, **dPhi )

JetContentsCh    = m_histos.TH1orTH2( histoFolder, "hJet_ChMulti"          , "Legend Name", None, **Multi )
JetContentsChHad = m_histos.TH1orTH2( histoFolder, "hJet_ChHadMulti"       , "Legend Name", None, **Multi )
JetContentsN     = m_histos.TH1orTH2( histoFolder, "hJet_NMulti"           , "Legend Name", None, **Multi )
JetContentsNHad  = m_histos.TH1orTH2( histoFolder, "hJet_NHadMulti"        , "Legend Name", None, **Multi )
JetContentsEl = m_histos.TH1orTH2( histoFolder, "hJet_ElecMulti"           , "Legend Name", None, **Multi )
JetContentsMu = m_histos.TH1orTH2( histoFolder, "hJet_MuonMulti"           , "Legend Name", None, **Multi )
JetContentsPh = m_histos.TH1orTH2( histoFolder, "hJet_PhotonMulti"         , "Legend Name", None, **Multi )

JetBDisParJP    = m_histos.TH1orTH2( histoFolder, "hJet_ParFl_bDisJP"           , "Legend Name", None, **bDisPar )
JetBDisHadJP    = m_histos.TH1orTH2( histoFolder, "hJet_HadFl_bDisJP"           , "Legend Name", None, **bDisHad )
JetBDisParCMVA  = m_histos.TH1orTH2( histoFolder, "hJet_ParFl_bDisCMVA"         , "Legend Name", None, **bDisPar )
JetBDisHadCMVA  = m_histos.TH1orTH2( histoFolder, "hJet_HadFl_bDisCMVA"         , "Legend Name", None, **bDisHad )

JetMulti        = m_histos.TH1orTH2( histoFolder, "hJet_Multiplicity"         , "Legend Name", None, **Multi )
JetbParMulti    = m_histos.TH1orTH2( histoFolder, "hbJetParFl_Multiplicity"   , "Legend Name", None, **Multi )
JetbDisMultiJPL = m_histos.TH1orTH2( histoFolder, "hbJetL_Multiplicity"       , "Legend Name", None, **Multi )
JetbDisMultiJPM = m_histos.TH1orTH2( histoFolder, "hbJetM_Multiplicity"       , "Legend Name", None, **Multi )
JetbDisMultiJPT = m_histos.TH1orTH2( histoFolder, "hbJetT_Multiplicity"       , "Legend Name", None, **Multi )


bJetPt     = m_histos.TH1orTH2( histoFolder, "hbJet_Pt"          , "Legend Name", None, **Pt )
bJetEta    = m_histos.TH1orTH2( histoFolder, "hbJet_Eta"         , "Legend Name", None, **Eta )
bJetE      = m_histos.TH1orTH2( histoFolder, "hbJet_E"           , "Legend Name", None, **E )
bJetArea   = m_histos.TH1orTH2( histoFolder, "hbJet_JetArea"        , "Legend Name", None, **Area )
bJetdPhiMET= m_histos.TH1orTH2( histoFolder, "hdPhi_bJet_MET"    , "Legend Name", None, **dPhi )

bJetContentsCh    = m_histos.TH1orTH2( histoFolder, "hbJet_ChMulti"          , "Legend Name", None, **Multi )
bJetContentsChHad = m_histos.TH1orTH2( histoFolder, "hbJet_ChHadMulti"       , "Legend Name", None, **Multi )
bJetContentsN     = m_histos.TH1orTH2( histoFolder, "hbJet_NMulti"           , "Legend Name", None, **Multi )
bJetContentsNHad  = m_histos.TH1orTH2( histoFolder, "hbJet_NHadMulti"        , "Legend Name", None, **Multi )
bJetContentsEl    = m_histos.TH1orTH2( histoFolder, "hbJet_ElecMulti"           , "Legend Name", None, **Multi )
bJetContentsMu    = m_histos.TH1orTH2( histoFolder, "hbJet_MuonMulti"           , "Legend Name", None, **Multi )
bJetContentsPh    = m_histos.TH1orTH2( histoFolder, "hbJet_PhotonMulti"         , "Legend Name", None, **Multi )



###
#Gen Level
###


GenPVX = m_histos.TH1orTH2( histoFolder,"hGenPV_X"      , "Legend Name", None, **X0 )
GenPVY = m_histos.TH1orTH2( histoFolder,"hGenPV_Y"      , "Legend Name", None, **Y0 )
GenPVZ = m_histos.TH1orTH2( histoFolder,"hGenPV_Z"      , "Legend Name", None, **Z0 )

GenMETEt   = m_histos.TH1orTH2( histoFolder,"hGenMET_Et"         , "Legend Name", None, **Et )
GenMETPt   = m_histos.TH1orTH2( histoFolder,"hGenMET_Pt"         , "Legend Name", None, **Pt )
GenNuMulti = m_histos.TH1orTH2( histoFolder,"hGenNuMultiplicity" , "Legend Name", None, **Multi )
GenHT      = m_histos.TH1orTH2( histoFolder,"hHT"                , "Legend Name", None, **Ht )
GenMHT     = m_histos.TH1orTH2( histoFolder,"hMHT"               , "Legend Name", None, **MHt )



GenElecPt      = m_histos.TH1orTH2( histoFolder,"hGenElec_Pt"        , "Legend Name", None, **Pt )
GenElecEta     = m_histos.TH1orTH2( histoFolder,"hGenElec_Eta"       , "Legend Name", None, **Eta )
GenElecE       = m_histos.TH1orTH2( histoFolder,"hGenElec_E"         , "Legend Name", None, **E )
GenElecRIso    = m_histos.TH1orTH2( histoFolder,"hGenElec_RIso"      , "Legend Name", None, **RIso )
GenElecLxy     = m_histos.TH1orTH2( histoFolder,"hGenElec_Lxy"       , "Legend Name", None, **Lxy )
GenElecLxyz    = m_histos.TH1orTH2( histoFolder,"hGenElec_Lxyz"      , "Legend Name", None, **Lxyz )
GenElecdPhiMET = m_histos.TH1orTH2( histoFolder,"hdPhi_GenElec_MET"  , "Legend Name", None, **dPhi )

GenMuonPt      = m_histos.TH1orTH2( histoFolder,"hGenMuon_Pt"        , "Legend Name", None, **Pt )
GenMuonEta     = m_histos.TH1orTH2( histoFolder,"hGenMuon_Eta"       , "Legend Name", None, **Eta )
GenMuonE       = m_histos.TH1orTH2( histoFolder,"hGenMuon_E"         , "Legend Name", None, **E )
GenMuonRIso    = m_histos.TH1orTH2( histoFolder,"hGenMuon_RIso"      , "Legend Name", None, **RIso )
GenMuonLxy     = m_histos.TH1orTH2( histoFolder,"hGenMuon_Lxy"       , "Legend Name", None, **Lxy )
GenMuonLxyz    = m_histos.TH1orTH2( histoFolder,"hGenMuon_Lxyz"      , "Legend Name", None, **Lxyz )
GenMuondPhiMET = m_histos.TH1orTH2( histoFolder,"hdPhi_GenMuon_MET"  , "Legend Name", None, **dPhi )


GenTauPt      = m_histos.TH1orTH2( histoFolder,"hGenTau_Pt"        , "Legend Name", None, **Pt )
GenTauEta     = m_histos.TH1orTH2( histoFolder,"hGenTau_Eta"       , "Legend Name", None, **Eta )
GenTauE       = m_histos.TH1orTH2( histoFolder,"hGenTau_E"         , "Legend Name", None, **E )
GenTauRIso    = m_histos.TH1orTH2( histoFolder,"hGenTau_RIso"      , "Legend Name", None, **RIso )
GenTaudPhiMET = m_histos.TH1orTH2( histoFolder,"hdPhi_GenTau_MET"  , "Legend Name", None, **dPhi )


bGenHadPt         = m_histos.TH1orTH2( histoFolder,"hbGenHad_Pt"          , "Legend Name", None, **Pt )
bGenHadEta        = m_histos.TH1orTH2( histoFolder,"hbGenHad_Eta"         , "Legend Name", None, **Eta )
bGenHadE          = m_histos.TH1orTH2( histoFolder,"hbGenHad_E"           , "Legend Name", None, **E )
bGenHaddPhiMET    = m_histos.TH1orTH2( histoFolder,"hdPhi_bGenHad_MET"    , "Legend Name", None, **dPhi )
bGenHadContentsCh = m_histos.TH1orTH2( histoFolder,"hbGenHad_ChMulti"     , "Legend Name", None, **Multi )
bGenHadContentsN  = m_histos.TH1orTH2( histoFolder,"hbGenHad_NMulti"      , "Legend Name", None, **Multi )
bGenHadMulti      = m_histos.TH1orTH2( histoFolder,"hbGenHad_Multiplicity", "Legend Name", None, **Multi )


GenJetPt         = m_histos.TH1orTH2( histoFolder,"hGenJet_Pt"          , "Legend Name", None, **Pt )
GenJetEta        = m_histos.TH1orTH2( histoFolder,"hGenJet_Eta"         , "Legend Name", None, **Eta )
GenJetE          = m_histos.TH1orTH2( histoFolder,"hGenJet_E"           , "Legend Name", None, **E )
GenJetdPhiMET    = m_histos.TH1orTH2( histoFolder,"hdPhi_GenJet_MET"    , "Legend Name", None, **dPhi )
GenJetContentsCh = m_histos.TH1orTH2( histoFolder,"hGenJet_ChMulti"     , "Legend Name", None, **Multi )
GenJetContentsN  = m_histos.TH1orTH2( histoFolder,"hGenJet_NMulti"      , "Legend Name", None, **Multi )
GenJetMulti      = m_histos.TH1orTH2( histoFolder,"hGenJet_Multiplicity", "Legend Name", None, **Multi )


#Elec Muon Tau Jet
###############################################################
### Main
###############################################################
def DoPlots(histoObjectList, dataset):
    '''
    '''
    p = m_plotter.Plotter(bVerbose, bBatchMode)
    p.EnableColourPalette(True)
   
    p.AddDataset( dataset + ":t#bar{t}H"            , inputPath_ttH125 )
    p.AddDataset( dataset + ":t#bar{t}"             , inputPath_TTBar)
    p.AddDataset( dataset + ":t#bar{t}W"            , inputPath_TTW)
    p.AddDataset( dataset + ":t#bar{t}Z"            , inputPath_TTZ)
    #p.AddDataset( dataset + ":WW"                    , inputPath_WW)
    #p.AddDataset( dataset + ":ZZ"                    , inputPath_ZZ)
    #p.AddDataset( dataset + ":WZ"                    , inputPath_WZ)
    #p.AddDataset( dataset + ":DY m_{ll} 10-50"       , inputPath_DYLLM10)
    #p.AddDataset( dataset + ":DY m_{ll} 50"          , inputPath_DYLLM50)
    #p.AddDataset( dataset + ":Single top - tchannel" , inputPath_STtchannel)
    #p.AddDataset( dataset + ":Single top - tW"       , inputPath_STWt)
    #p.AddDataset( dataset + ":Single top - #bar{t}W" , inputPath_STWtbar)
    
    p.AddHisto( histoObjectList )
    p.SetBoolUseDatasetAsLegEntry(True)
    p.Draw(THStackDrawOpt="nostack", bStackInclusive = False)
    p.GetTLegend().SetHeader( dataset )
    p.SaveHistos(bSavePlots, mySavePath, mySaveFormats)

    return
###############################################################
if __name__ == "__main__":

    #Elec
    #DoPlots(ElecPt     , dataset)
    #DoPlots(ElecEta    , dataset)
    #DoPlots(ElecE      , dataset)
    #DoPlots(ElecCharge , dataset)
    
    #DoPlots(ElecIP3d      , dataset)
    #DoPlots(ElecIP3dError , dataset)
    #DoPlots(ElecIP2d      , dataset)
    #DoPlots(ElecIP2dError , dataset)
    #DoPlots(ElecdPhiMET   , dataset)
    #DoPlots(ElecIso       , dataset)
    
    #DoPlots(ElecTkD0   , dataset)
    #DoPlots(ElecTkZ0   , dataset)
    #DoPlots(ElecTkChi2 , dataset)

    #Muon
    #DoPlots(MuonPt     , dataset)
    #DoPlots(MuonEta    , dataset)
    #DoPlots(MuonE      , dataset)
    #DoPlots(MuonCharge , dataset)
    
    #DoPlots(MuonIP3d      , dataset)
    #DoPlots(MuonIP3dError , dataset)
    #DoPlots(MuonIP2d      , dataset)
    #DoPlots(MuonIP2dError , dataset)
    #DoPlots(MuondPhiMET   , dataset)
    #DoPlots(MuonIso       , dataset)
    
    #DoPlots(MuonITkD0   , dataset)
    #DoPlots(MuonITkZ0   , dataset)
    #DoPlots(MuonITkChi2 , dataset)

    #DoPlots(MuonGTkD0   , dataset)
    #DoPlots(MuonGTkZ0   , dataset)
    #DoPlots(MuonGTkChi2 , dataset)

    #Combined
    #DoPlots(LeadLepPt        , dataset)
    #DoPlots(SubLeadLepPt     , dataset)
    #DoPlots(SubSubLeadLepPt  , dataset) 


    #Tau
    #DoPlots(TauPt            , dataset)
    #DoPlots(TauEta           , dataset)
    #DoPlots(TauE             , dataset)
    #DoPlots(TauCharge        , dataset)
    #DoPlots(TaudPhiMET       , dataset)
    #DoPlots(TauLdgCHPt       , dataset)
    #DoPlots(TauLdgCHEta      , dataset)
    #DoPlots(TauLdgCHE        , dataset)
    #DoPlots(TauLdgCHEt       , dataset)
    #DoPlots(TauLdgCHId       , dataset)
    #DoPlots(TauLdgCHCharge   , dataset)
    #DoPlots(TauLdgCHX0       , dataset)
    #DoPlots(TauLdgCHY0       , dataset)
    #DoPlots(TauLdgCHZ0       , dataset)

    #MET
    #DoPlots(METPt          , dataset)
    #DoPlots(METSumEt       , dataset)

    #Jet
    #DoPlots(JetPt                   , dataset)         
    #DoPlots(JetEta                  , dataset)
    #DoPlots(JetE                    , dataset)
    #DoPlots(JetArea                 , dataset)
    #DoPlots(JetdPhiMET              , dataset)
    
    #DoPlots(JetContentsCh           , dataset)
    #DoPlots(JetContentsChHad        , dataset)
    #DoPlots(JetContentsN            , dataset)
    #DoPlots(JetContentsNHad         , dataset)
    #DoPlots(JetContentsEl           , dataset)
    #DoPlots(JetContentsMu           , dataset)
    #DoPlots(JetContentsPh           , dataset)
    
    ##DoPlots(JetBDisParJP            , dataset)
    ##DoPlots(JetBDisHadJP            , dataset)
    ##DoPlots(JetBDisParCMVA          , dataset)
    ##DoPlots(JetBDisHadCMVA          , dataset)
    
    #DoPlots(JetMulti                , dataset)
    #DoPlots(JetbParMulti            , dataset)
    #DoPlots(JetbDisMultiJPL         , dataset)
    #DoPlots(JetbDisMultiJPM         , dataset)
    #DoPlots(JetbDisMultiJPT         , dataset)
    

    #DoPlots(bJetPt                  , dataset)
    #DoPlots(bJetEta                 , dataset)
    #DoPlots(bJetE                   , dataset)
    #DoPlots(bJetArea                , dataset)
    #DoPlots(bJetdPhiMET             , dataset)
    
    #DoPlots(bJetContentsCh          , dataset)
    #DoPlots(bJetContentsChHad       , dataset)
    #DoPlots(bJetContentsN           , dataset)
    #DoPlots(bJetContentsNHad        , dataset)
    #DoPlots(bJetContentsEl          , dataset)
    #DoPlots(bJetContentsMu          , dataset)
    #DoPlots(bJetContentsPh          , dataset)


    ######
    #Gen Level
    ######
    
    #DoPlots(GenPVX                , dataset)
    #DoPlots(GenPVY                , dataset)
    #DoPlots(GenPVZ                , dataset)
    
    DoPlots(GenMETEt              , dataset)
    #DoPlots(GenMETPt              , dataset)
    DoPlots(GenNuMulti            , dataset)
    DoPlots(GenHT                 , dataset)
    DoPlots(GenMHT                , dataset)
    
    #DoPlots(GenElecPt             , dataset)
    #DoPlots(GenElecEta            , dataset)
    #DoPlots(GenElecE              , dataset)
    #DoPlots(GenElecRIso           , dataset)
    #DoPlots(GenElecLxy            , dataset)
    #DoPlots(GenElecLxyz           , dataset)
    #DoPlots(GenElecdPhiMET        , dataset)
    
    #DoPlots(GenMuonPt             , dataset)
    #DoPlots(GenMuonEta            , dataset)
    #DoPlots(GenMuonE              , dataset)
    #DoPlots(GenMuonRIso           , dataset)
    #DoPlots(GenMuonLxy            , dataset)
    #DoPlots(GenMuonLxyz           , dataset)
    #DoPlots(GenMuondPhiMET        , dataset)
    
    
    #DoPlots(GenTauPt              , dataset)
    #DoPlots(GenTauEta             , dataset)
    #DoPlots(GenTauE               , dataset)
    #DoPlots(GenTauRIso            , dataset)
    #DoPlots(GenTaudPhiMET         , dataset)
    
    
    #DoPlots(bGenHadPt             , dataset)
    #DoPlots(bGenHadEta            , dataset)
    #DoPlots(bGenHadE              , dataset)
    #DoPlots(bGenHaddPhiMET        , dataset)
    #DoPlots(bGenHadContentsCh     , dataset)
    #DoPlots(bGenHadContentsN      , dataset)
    #DoPlots(bGenHadMulti         , dataset)
    
    
    #DoPlots(GenJetPt              , dataset)
    #DoPlots(GenJetEta             , dataset)
    #DoPlots(GenJetE               , dataset)
    #DoPlots(GenJetdPhiMET         , dataset)
    #DoPlots(GenJetContentsCh      , dataset)
    #DoPlots(GenJetContentsN       , dataset)
    #DoPlots(GenJetMulti          , dataset)
