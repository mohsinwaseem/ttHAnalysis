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
histoFolder = ""
yMin        = 1
yMax        = None
yMinRatio   = 0.0
yMaxRatio   = 4.9
bRatio      = False
bInvRatio   = True
ratioLabel  = "1/Ratio"
normFactor  = None

###############################################################
### Histogram Attributes
###############################################################
kwargs   = {}

Rate   = {"xLabel": "E_{T}"             , "xUnits": "GeV", "xMin": 0.0 , "xMax": +100.0, "binWidthX": None, "xCutLines": []  , "xCutBoxes": [[0.0, 15.0, ROOT.kBlack]], "gridX": True, "logX": False,
          "yLabel": "Rate (kHz) / %0.0f", "yUnits": ""   , "yMin": 1E+1, "yMax": 5E+04 , "binWidthY": None, "yCutLines": [50], "yCutBoxes": []                        , "gridY": True, "logY": True ,
          "ratioLabel": ratioLabel, "ratio": bRatio, "invRatio": bInvRatio, "yMinRatio": yMinRatio, "yMaxRatio": 11.9, "normaliseTo": normFactor, "drawOptions": "PF", "legOptions": "LP",
          "xLegMin": 0.68, "xLegMax": 0.85, "yLegMin": 0.70, "yLegMax": 0.82 }

Rate2D   = {"xLabel": "E_{T}^{Ldg} / %0.0f"   , "xUnits": "GeV", "xMin": 0.0 , "xMax": +100.0, "binWidthX": 1, "xCutLines": [], "xCutBoxes": [], "gridX": False, "logX": False,
            "yLabel": "E_{T}^{subLdg} / %0.0f", "yUnits": "GeV", "yMin": 0.0 , "yMax": +100.0, "binWidthY": 1, "yCutLines": [], "yCutBoxes": [], "gridY": False, "logY": False ,
            "zLabel": "Rate"             , "zUnits": "kHz", "zMin": 1E+0, "zMax": 5E+04 , "zCutLinesErrors": True, "zCutLines": [50.0], "zCutBoxes": [], "gridZ": False, "logZ": True ,
            "drawOptions": "COLZ", "xLegMin": 0.62, "xLegMax": 0.85, "yLegMin": 0.70, "yLegMax": 0.82 }

Eff = {"xLabel": "E_{T}"             , "xUnits": "GeV", "xMin": 0.0 , "xMax": +100.0, "binWidthX": None, "xCutLines": [], "xCutBoxes": [[0.0, 15.0, ROOT.kBlack]], "gridX": True, "logX": False,
       "yLabel": "Signal Efficiency / %0.0f", "yUnits": ""   , "yMin": 0.0 , "yMax": +1.09 , "binWidthY": None, "yCutLines": [], "yCutBoxes":  [], "gridY": True, "logY": False,
       "ratioLabel": "Ratio", "ratio": bRatio, "invRatio": False, "yMinRatio": 0.35, "yMaxRatio": 1.1, "normaliseTo": normFactor, "drawOptions": "P", "legOptions": "LP",
       "xLegMin": 0.68, "xLegMax": 0.85, "yLegMin": 0.70, "yLegMax": 0.82 }

Eff2D = {"xLabel": "E_{T}^{Ldg} / %0.0f"   , "xUnits": "GeV", "xMin": 0.0, "xMax": +100.0, "binWidthX": 1, "xCutLines": [], "xCutBoxes": [], "gridX": False, "logX": False,
         "yLabel": "E_{T}^{subLdg} / %0.0f", "yUnits": "GeV", "yMin": 0.0, "yMax": +100.0, "binWidthY": 1, "yCutLines": [], "yCutBoxes": [], "gridY": False, "logY": False ,
         "zLabel": "Signal Efficiency"            , "zUnits": ""   , "zMin": 0.0, "zMax": 1.0   , "zCutLinesErrors": False, "zCutLines": [], "zCutBoxes": [], "gridZ": False, "logZ": False,
         "drawOptions": "COLZ", "xLegMin": 0.62, "xLegMax": 0.85, "yLegMin": 0.70, "yLegMax": 0.82 }

ROC    = {"xLabel": "Signal Efficiency"      , "xUnits": ""   , "xMin": 0.00, "xMax": +0.6 , "binWidthX": None, "xCutLines": []     , "xCutBoxes": [], "gridX": True, "logX": False,
          "yLabel": "Rate" , "yUnits": "kHz", "yMin": 1E+0, "yMax": +0.5E+03, "binWidthY": None, "yCutLines": [50.0], "yCutBoxes": [], "gridY": True, "logY": True,
          "legOptions": "FL", "drawOptions": "ACE3", "xLegMin": 0.60, "xLegMax": 0.80, "yLegMin": 0.20, "yLegMax": 0.46}

TurnOn = {"xLabel": "#tau_{MC} E_{T}^{vis}", "xUnits": "GeV", "xMin": 0.0 , "xMax": 200.0, "binWidthX": None, "xCutLines": [], "xCutBoxes": [], "gridX": True, "logX": False,
          "yLabel": "Signal Efficiency / %0.0f"   , "yUnits": ""   , "yMin": 0.0 , "yMax": +1.20 , "binWidthY": None, "yCutLines": []  , "yCutBoxes": [], "gridY": True, "logY": False,
          "ratioLabel": "Ratio", "ratio": False, "invRatio": False, "yMinRatio": yMinRatio, "yMaxRatio": 1.1, "normaliseTo": None, "drawOptions": "P", "legOptions": "LP",
          "xLegMin": 0.68, "xLegMax": 0.85, "yLegMin": 0.26, "yLegMax": 0.40 }

TurnOn50 = {"xLabel": "#tau_{MC} E_{T}^{vis}", "xUnits": "GeV", "xMin": 0.0 , "xMax": 200.0, "binWidthX": None, "xCutLines": [50], "xCutBoxes": [], "gridX": True, "logX": False,
            "yLabel": "Signal Efficiency / %0.0f"   , "yUnits": ""   , "yMin": 0.0 , "yMax": +1.20 , "binWidthY": None, "yCutLines": []  , "yCutBoxes": [], "gridY": True, "logY": False,
            "ratioLabel": "Ratio", "ratio": False, "invRatio": False, "yMinRatio": yMinRatio, "yMaxRatio": 1.1, "normaliseTo": None, "drawOptions": "P", "legOptions": "LP",
            "xLegMin": 0.68, "xLegMax": 0.85, "yLegMin": 0.26, "yLegMax": 0.40 }

TurnOn25 = {"xLabel": "#tau_{MC} E_{T}^{vis}", "xUnits": "GeV", "xMin": 0.0 , "xMax": +200.0, "binWidthX": None, "xCutLines": [25], "xCutBoxes": [], "gridX": True, "logX": False,
            "yLabel": "Signal Efficiency / %0.0f"   , "yUnits": ""   , "yMin": 0.0 , "yMax": +1.17 , "binWidthY": None, "yCutLines": []  , "yCutBoxes": [], "gridY": True, "logY": False,
            "ratioLabel": "Ratio", "ratio": False, "invRatio": False, "yMinRatio": yMinRatio, "yMaxRatio": 1.1, "normaliseTo": None, "drawOptions": "P", "legOptions": "LP",
            "xLegMin": 0.68, "xLegMax": 0.85, "yLegMin": 0.26, "yLegMax": 0.40 }

###############################################################
### SingleTau
###############################################################
hCalo_Rate       = m_histos.TH1orTH2( histoFolder, "Calo_Rate"      , "Calo"             , "SingleTau_Rate_Calo"      , **Rate )
hTk_Rate         = m_histos.TH1orTH2( histoFolder, "Tk_Rate"        , "+Tk"              , "SingleTau_Rate_Tk"        , **Rate )
hVtxIso1p00_Rate = m_histos.TH1orTH2( histoFolder, "VtxIso1p00_Rate", "+VtxIso (1.0 cm)", "SingleTau_Rate_VtxIso1p00", **Rate )
hRelIso0p10_Rate = m_histos.TH1orTH2( histoFolder, "RelIso0p10_Rate", "+RelIso (0.10)"   , "SingleTau_Rate_RelIso0p10", **Rate )

hCalo_Eff       = m_histos.TH1orTH2( histoFolder, "Calo_Eff"      , "Calo"             , "SingleTau_Eff_Calo"      , **Eff )
hTk_Eff         = m_histos.TH1orTH2( histoFolder, "Tk_Eff"        , "+Tk"              , "SingleTau_Eff_Tk"        , **Eff )
hVtxIso1p00_Eff = m_histos.TH1orTH2( histoFolder, "VtxIso1p00_Eff", "+VtxIso (1.0 cm)", "SingleTau_Eff_VtxIso1p00", **Eff )
hRelIso0p10_Eff = m_histos.TH1orTH2( histoFolder, "RelIso0p10_Eff", "+RelIso (0.10)"   , "SingleTau_Eff_RelIso0p10", **Eff )

hCalo_TurnOn50        = m_histos.TH1orTH2( histoFolder, "Calo_TurnOn50"      , "Calo"             , "TurnOn_Calo_50GeV"      , **TurnOn50 )
hTk_TurnOn50          = m_histos.TH1orTH2( histoFolder, "Tk_TurnOn50"        , "+Tk"              , "TurnOn_Tk_50GeV"        , **TurnOn50 )
hVtxIso1p00_TurnOn50  = m_histos.TH1orTH2( histoFolder, "VtxIso1p00_TurnOn50", "+VtxIso (1.0 cm)", "TurnOn_VtxIso1p00_50GeV", **TurnOn50 )
hRelIso0p10_TurnOn50  = m_histos.TH1orTH2( histoFolder, "RelIso0p10_TurnOn50", "+RelIso (0.10)"   , "TurnOn_RelIso0p10_50GeV", **TurnOn50 )

hCalo_TurnOn_SingleTau50KHz       = m_histos.TH1orTH2( histoFolder, "Calo_TurnOn_SingleTau50KHz"      , "Calo"              , "TurnOn_Calo_50kHz"       , **TurnOn )
hTk_TurnOn_SingleTau50KHz         = m_histos.TH1orTH2( histoFolder, "Tk_TurnOn_SingleTau50KHz"        , "+Tk"               , "TurnOn_Tk_50kHz"         , **TurnOn )
hVtxIso1p00_TurnOn_SingleTau50KHz = m_histos.TH1orTH2( histoFolder, "VtxIso1p00_TurnOn_SingleTau50KHz", "+VtxIso (1.0 cm)" , "TurnOn_VtxIso1p00_50kHz", **TurnOn )
hRelIso0p10_TurnOn_SingleTau50KHz = m_histos.TH1orTH2( histoFolder, "RelIso0p10_TurnOn_SingleTau50KHz", "+RelIso (0.10)"    , "TurnOn_RelIso0p10_50kHz", **TurnOn )

###############################################################
### DiTau (Indistinghuishable)
###############################################################
hDiTau_Rate_Calo       = m_histos.TH1orTH2( histoFolder, "DiTau_Rate_Calo"      , "Calo"             , "DiTau_Rate_Calo"      , **Rate )
hDiTau_Rate_Tk         = m_histos.TH1orTH2( histoFolder, "DiTau_Rate_Tk"        , "+Tk"              , "DiTau_Rate_Tk"        , **Rate )
hDiTau_Rate_VtxIso1p00 = m_histos.TH1orTH2( histoFolder, "DiTau_Rate_VtxIso1p00", "+VtxIso (1.0 cm)", "DiTau_Rate_VtxIso1p00", **Rate )
hDiTau_Rate_RelIso0p10 = m_histos.TH1orTH2( histoFolder, "DiTau_Rate_RelIso0p10", "+RelIso (0.10)"   , "DiTau_Rate_RelIso0p10", **Rate )

hDiTau_Eff_Calo       = m_histos.TH1orTH2( histoFolder, "DiTau_Eff_Calo"      , "Calo"             , "DiTau_Eff_Calo"      , **Eff )
hDiTau_Eff_Tk         = m_histos.TH1orTH2( histoFolder, "DiTau_Eff_Tk"        , "+Tk"              , "DiTau_Eff_Tk"        , **Eff )
hDiTau_Eff_VtxIso1p00 = m_histos.TH1orTH2( histoFolder, "DiTau_Eff_VtxIso1p00", "+VtxIso (1.0 cm)", "DiTau_Eff_VtxIso1p00", **Eff )
hDiTau_Eff_RelIso0p10 = m_histos.TH1orTH2( histoFolder, "DiTau_Eff_RelIso0p10", "+RelIso (0.10)"   , "DiTau_Eff_RelIso0p10", **Eff )

hCalo_TurnOn25        = m_histos.TH1orTH2( histoFolder, "Calo_TurnOn25"      , "Calo"             , "TurnOn_Calo_25GeV"      , **TurnOn25 )
hTk_TurnOn25          = m_histos.TH1orTH2( histoFolder, "Tk_TurnOn25"        , "+Tk"              , "TurnOn_Tk_25GeV"        , **TurnOn25 )
hVtxIso1p00_TurnOn25  = m_histos.TH1orTH2( histoFolder, "VtxIso1p00_TurnOn25", "+VtxIso (1.0 cm)", "TurnOn_VtxIso1p00_25GeV", **TurnOn25 )
hRelIso0p10_TurnOn25  = m_histos.TH1orTH2( histoFolder, "RelIso0p10_TurnOn25", "+RelIso (0.10)"   , "TurnOn_RelIso0p10_25GeV", **TurnOn25 )

hCalo_TurnOn_DiTau50KHz       = m_histos.TH1orTH2( histoFolder, "Calo_TurnOn_DiTau50KHz"      , "Calo"              , "Calo_TurnOn_DiTau_50KHz"      , **TurnOn )
hTk_TurnOn_DiTau50KHz         = m_histos.TH1orTH2( histoFolder, "Tk_TurnOn_DiTau50KHz"        , "+Tk"               , "Tk_TurnOn_DiTau_50KHz"        , **TurnOn )
hVtxIso1p00_TurnOn_DiTau50KHz = m_histos.TH1orTH2( histoFolder, "VtxIso1p00_TurnOn_DiTau50KHz", "+VtxIso (1.0 cm)" , "VtxIso1p00_TurnOn_DiTau_50KHz", **TurnOn )
hRelIso0p10_TurnOn_DiTau50KHz = m_histos.TH1orTH2( histoFolder, "RelIso0p10_TurnOn_DiTau50KHz", "+RelIso (0.10)"    , "RelIso0p10_TurnOn_DiTau_50KHz", **TurnOn )

###############################################################
### DiTau (Distinghuishable): Calo-Iso
###############################################################
hDiTau_Rate_Calo_Tk         = m_histos.TH1orTH2( histoFolder, "DiTau_Rate_Calo_Tk"        , "Calo, Tk"               , "DiTau_Rate_Calo_Tk"         , **Rate2D )
hDiTau_Rate_Calo_VtxIso1p00 = m_histos.TH1orTH2( histoFolder, "DiTau_Rate_Calo_VtxIso1p00", "Calo, +VtxIso (1.0 cm)", "DiTau_Rate_Calo_VtxIso1p00", **Rate2D )
hDiTau_Rate_Calo_RelIso0p10 = m_histos.TH1orTH2( histoFolder, "DiTau_Rate_Calo_RelIso0p10", "Calo, +RelIso (0.10)"   , "DiTau_Rate_Calo_RelIso0p10", **Rate2D )

hDiTau_Eff_Calo_Tk         = m_histos.TH1orTH2( histoFolder, "DiTau_Eff_Calo_RelIso0p10", "Calo, +Tk"              , "DiTau_Eff_Calo_Tk"        , **Eff2D )
hDiTau_Eff_Calo_VtxIso1p00 = m_histos.TH1orTH2( histoFolder, "DiTau_Eff_Calo_VtxIso1p00", "Calo, +VtxIso (1.0 cm)", "DiTau_Eff_Calo_VtxIso1p00", **Eff2D )
hDiTau_Eff_Calo_RelIso0p10 = m_histos.TH1orTH2( histoFolder, "DiTau_Eff_Calo_RelIso0p10", "Calo, +RelIso (0.10)"   , "DiTau_Eff_Calo_RelIso0p10", **Eff2D )


###############################################################
### DiTau (Distinghuishable): Calo-Iso
###############################################################
hDiTau_Rate_Tk_RelIso0p10 = m_histos.TH1orTH2( histoFolder, "DiTau_Rate_Tk_RelIso0p10"  , "+Tk, +RelIso (0.10)"   , "DiTau_Rate_Tk_RelIso0p10", **Rate2D )
hDiTau_Rate_Tk_VtxIso1p00 = m_histos.TH1orTH2( histoFolder, "DiTau_Rate_Tk_VtxIso1p00"  , "+Tk, +VtxIso (1.0 cm)", "DiTau_Rate_Tk_VtxIso1p00", **Rate2D )

hDiTau_Eff_Tk_RelIso0p10 = m_histos.TH1orTH2( histoFolder,"DiTau_Eff_Tk_RelIso0p10","+Tk, +RelIso (0.10)"   ,"DiTau_Eff_Tk_RelIso0p10",**Eff2D )
hDiTau_Eff_Tk_VtxIso1p00 = m_histos.TH1orTH2( histoFolder,"DiTau_Eff_Tk_VtxIso1p00","+Tk, +VtxIso (1.0 cm)","DiTau_Eff_Tk_VtxIso1p00",**Eff2D )

############################################################### 
### SingleTau 
############################################################### 
SingleTau_Rate = []
SingleTau_Rate.append(hCalo_Rate)
SingleTau_Rate.append(hTk_Rate)
SingleTau_Rate.append(hVtxIso1p00_Rate)
#SingleTau_Rate.append(hRelIso0p10_Rate)

SingleTau_Eff = []
SingleTau_Eff.append(hCalo_Eff)
SingleTau_Eff.append(hTk_Eff)
SingleTau_Eff.append(hVtxIso1p00_Eff)
#SingleTau_Eff.append(hRelIso0p10_Eff)

SingleTau_TurnOn = []
SingleTau_TurnOn.append(hCalo_TurnOn50)
SingleTau_TurnOn.append(hTk_TurnOn50)
SingleTau_TurnOn.append(hVtxIso1p00_TurnOn50)
#SingleTau_TurnOn.append(hRelIso0p10_TurnOn50)

SingleTau_TurnOn_50KHz = []
SingleTau_TurnOn_50KHz.append(hCalo_TurnOn_SingleTau50KHz)
SingleTau_TurnOn_50KHz.append(hTk_TurnOn_SingleTau50KHz)
SingleTau_TurnOn_50KHz.append(hVtxIso1p00_TurnOn_SingleTau50KHz)
#SingleTau_TurnOn_50KHz.append(hRelIso0p10_TurnOn_SingleTau50KHz)

SingleTau_ROCs = {}
SingleTau_ROCs[hCalo_Rate]       = hCalo_Eff
SingleTau_ROCs[hTk_Rate]         = hTk_Eff
SingleTau_ROCs[hVtxIso1p00_Rate] = hVtxIso1p00_Eff
#SingleTau_ROCs[hRelIso0p10_Rate] = hRelIso0p10_Eff

############################################################### 
### DiTau (Indistinguishable)
############################################################### 
DiTau_TurnOn = []
DiTau_TurnOn.append(hCalo_TurnOn25)
DiTau_TurnOn.append(hTk_TurnOn25)
DiTau_TurnOn.append(hVtxIso1p00_TurnOn25)
#DiTau_TurnOn.append(hRelIso0p10_TurnOn25)

DiTau_Rate = []
DiTau_Rate.append(hDiTau_Rate_Calo)
DiTau_Rate.append(hDiTau_Rate_Tk)
DiTau_Rate.append(hDiTau_Rate_VtxIso1p00)
#DiTau_Rate.append(hDiTau_Rate_RelIso0p10)

DiTau_Eff = []
DiTau_Eff.append(hDiTau_Eff_Calo)
DiTau_Eff.append(hDiTau_Eff_Tk)
DiTau_Eff.append(hDiTau_Eff_VtxIso1p00)
#DiTau_Eff.append(hDiTau_Eff_RelIso0p10)

DiTau_TurnOn_50KHz = []
DiTau_TurnOn_50KHz.append(hCalo_TurnOn_DiTau50KHz)
DiTau_TurnOn_50KHz.append(hTk_TurnOn_DiTau50KHz)
DiTau_TurnOn_50KHz.append(hVtxIso1p00_TurnOn_DiTau50KHz)
#DiTau_TurnOn_50KHz.append(hRelIso0p10_TurnOn_DiTau50KHz)

DiTau_ROCs = {}
DiTau_ROCs[hDiTau_Rate_Calo]       = hDiTau_Eff_Calo
DiTau_ROCs[hDiTau_Rate_Tk]         = hDiTau_Eff_Tk
DiTau_ROCs[hDiTau_Rate_VtxIso1p00] = hDiTau_Eff_VtxIso1p00
#DiTau_ROCs[hDiTau_Rate_RelIso0p10] = hDiTau_Eff_RelIso0p10

############################################################### 
### DiTau (Distinguishable: Calo-Iso
############################################################### 
DiTau_Rate_CaloIso = []
#DiTau_Rate_CaloIso.append(hDiTau_Rate_Calo_Tk)
DiTau_Rate_CaloIso.append(hDiTau_Rate_Calo_VtxIso1p00)
#DiTau_Rate_CaloIso.append(hDiTau_Rate_Calo_RelIso0p10)

DiTau_Eff_CaloIso = []
#DiTau_Eff_CaloIso.append(hDiTau_Eff_Calo_Tk)
DiTau_Eff_CaloIso.append(hDiTau_Eff_Calo_VtxIso1p00)
#DiTau_Eff_CaloIso.append(hDiTau_Eff_Calo_RelIso0p10)

DiTau_ROCs_CaloIso = {}
DiTau_ROCs_CaloIso[hDiTau_Rate_Calo]            = hDiTau_Eff_Calo
DiTau_ROCs_CaloIso[hDiTau_Rate_Tk]              = hDiTau_Eff_Tk
#DiTau_ROCs_CaloIso[hDiTau_Rate_Calo_Tk]         = hDiTau_Eff_Calo_Tk
DiTau_ROCs_CaloIso[hDiTau_Rate_Calo_VtxIso1p00] = hDiTau_Eff_Calo_VtxIso1p00
#DiTau_ROCs_CaloIso[hDiTau_Rate_Calo_RelIso0p10] = hDiTau_Eff_Calo_RelIso0p10

############################################################### 
### DiTau (Distinguishable: Tk-Iso
############################################################### 
DiTau_Rate_TkIso = []
DiTau_Rate_TkIso.append(hDiTau_Rate_Tk_VtxIso1p00)
#DiTau_Rate_TkIso.append(hDiTau_Rate_Tk_RelIso0p10)

DiTau_Eff_TkIso = []
DiTau_Eff_TkIso.append(hDiTau_Eff_Tk_VtxIso1p00)
#DiTau_Eff_TkIso.append(hDiTau_Eff_Tk_RelIso0p10)

DiTau_ROCs_TkIso = {}
DiTau_ROCs_TkIso[hDiTau_Rate_Calo]          = hDiTau_Eff_Calo
DiTau_ROCs_TkIso[hDiTau_Rate_Tk]            = hDiTau_Eff_Tk
DiTau_ROCs_TkIso[hDiTau_Rate_Tk_VtxIso1p00] = hDiTau_Eff_Tk_VtxIso1p00
#DiTau_ROCs_TkIso[hDiTau_Rate_Tk_RelIso0p10] = hDiTau_Eff_Tk_RelIso0p10

DiTau_ROCs_TP = {}
DiTau_ROCs_TP[hDiTau_Rate_Calo]            = hDiTau_Eff_Calo
DiTau_ROCs_TP[hDiTau_Rate_Tk]              = hDiTau_Eff_Tk
DiTau_ROCs_TP[hDiTau_Rate_VtxIso1p00]      = hDiTau_Eff_VtxIso1p00
#DiTau_ROCs_TP[hDiTau_Rate_RelIso0p10]      = hDiTau_Eff_RelIso0p10
DiTau_ROCs_TP[hDiTau_Rate_Calo_VtxIso1p00] = hDiTau_Eff_Calo_VtxIso1p00
#DiTau_ROCs_TP[hDiTau_Rate_Calo_RelIso0p10] = hDiTau_Eff_Calo_RelIso0p10
