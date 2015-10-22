###############################################################
### Author .........: Alexandros X. Attikis 
### Institute ......: University Of Cyprus (UCY)
### Email ..........: attikis@cern.ch
###############################################################

###############################################################
### All imported modules
###############################################################
import ROOT
import tools.histos as m_histos
import tools.tauTriggerAux 

###############################################################
### Define default instances of histogram attributes
###############################################################
kwargs   = {}
Eta      = {"xMin" : -2.6, "xMax" : 2.6, "yMin" : 0.01, "yMax" : None, "xLegMin": 0.65, "xLegMax": 0.94, "yLegMin": 0.84, "yLegMax": 0.94, 
            "xCutLines": [], "xCutBoxes": [], "normaliseTo": None, "ratio": False, "logX": False, "logY": False, "binWidthX": None}
            #"xCutLines": [], "xCutBoxes": [[-0.9, -1.3, ROOT.kRed], [+0.9, +1.3, ROOT.kRed]], "normaliseTo": None, "ratio": False, "logX": False, "logY": False, "binWidthX": None}

DeltaEta = {"xUnits": "", "xMin" : None, "xMax" : 0.15, "yMin" : None, "yMax" : None, "xLegMin": 0.65, "xLegMax": 0.94, "yLegMin": 0.84, "yLegMax": 0.94, 
            "xCutLines": [], "xCutBoxes": [], "normaliseTo": None, "ratio": False, "logX": False, "logY": False, "binWidthX": None}

DeltaPhi = {"xUnits": "(rads)", "xMin" : None, "xMax" : 0.15, "yMin" : None, "yMax" : None, "xLegMin": 0.65, "xLegMax": 0.94, "yLegMin": 0.84, "yLegMax": 0.94,
            "xCutLines": [], "xCutBoxes": [], "normaliseToOne" : False, "ratio": False, "logX": False, "logY": False, "binWidthX": None, "styleType": None, "saveName": None}

DeltaR   = {"xMin" : 0.0, "xMax" : 0.2, "yMin" : None, "yMax" : None, "xLegMin": 0.65, "xLegMax": 0.94, "yLegMin": 0.84, "yLegMax": 0.94, 
            "xCutLines": [], "xCutBoxes": [], "normaliseTo": None, "ratio": False, "logX": False, "logY": False, "binWidthX": None}

Vtx     = {"xUnits": "cm", "xMin" : -30, "xMax" : +30, "yMin" : None, "yMax" : None, "xLegMin": 0.65, "xLegMax": 0.94, "yLegMin": 0.84, "yLegMax": 0.94, 
           "xCutLines": [0], "xCutBoxes": [], "normaliseTo": None, "ratio": False, "logX": False, "logY": False, "binWidthX": None, "styleType": None}

###############################################################
### Create customised histograms and associated lists here
###############################################################
folder = "TauTrigger"

### MCTau
###############################################################
MCTDecay  = {"xMin" : 0.0, "xMax" : 9.0, "yMin" : 1, "yMax" : 1E8, "normaliseTo": None, "ratio": False, "logX": False, "logY": True, "binWidthX": None, "saveName": "hMCT_Decay"}
hMCT_Decay0 = m_histos.TH1orTH2(folder, "hMCT_Decay_0", "#tau_{mc} decay type", "Entries / %0.0f", "Electron", **MCTDecay)
hMCT_Decay1 = m_histos.TH1orTH2(folder, "hMCT_Decay_1", "#tau_{mc} decay type", "Entries / %0.0f", "Muon", **MCTDecay)
hMCT_Decay2 = m_histos.TH1orTH2(folder, "hMCT_Decay_2", "#tau_{mc} decay type", "Entries / %0.0f", "1-prong (0 #pi^{0})", **MCTDecay)
hMCT_Decay3 = m_histos.TH1orTH2(folder, "hMCT_Decay_3", "#tau_{mc} decay type", "Entries / %0.0f", "1-prong (1 #pi^{0})", **MCTDecay)
hMCT_Decay4 = m_histos.TH1orTH2(folder, "hMCT_Decay_4", "#tau_{mc} decay type", "Entries / %0.0f", "1-prong (2 #pi^{0})", **MCTDecay)
hMCT_Decay5 = m_histos.TH1orTH2(folder, "hMCT_Decay_5", "#tau_{mc} decay type", "Entries / %0.0f", "3-prong (0 #pi^{0})", **MCTDecay)
hMCT_Decay6 = m_histos.TH1orTH2(folder, "hMCT_Decay_6", "#tau_{mc} decay type", "Entries / %0.0f", "3-prong (1 #pi^{0})", **MCTDecay)
hMCT_Decay7 = m_histos.TH1orTH2(folder, "hMCT_Decay_7", "#tau_{mc} decay type", "Entries / %0.0f", "Other", **MCTDecay)
hMCT_Decay8 = m_histos.TH1orTH2(folder, "hMCT_Decay_8", "#tau_{mc} decay type", "Entries / %0.0f", "Undefined", **MCTDecay)
hMCT_Decay9 = m_histos.TH1orTH2(folder, "hMCT_Decay_9", "#tau_{mc} decay type", "Entries / %0.0f", "?", **MCTDecay)
MCT_Decays = []
MCT_Decays.append(hMCT_Decay0)
MCT_Decays.append(hMCT_Decay1)
MCT_Decays.append(hMCT_Decay2)
MCT_Decays.append(hMCT_Decay3)
MCT_Decays.append(hMCT_Decay4)
MCT_Decays.append(hMCT_Decay5)
MCT_Decays.append(hMCT_Decay6)
MCT_Decays.append(hMCT_Decay7)
MCT_Decays.append(hMCT_Decay8)
#MCT_Decays.append(hMCT_Decay9)


MCTVisEt = {"xUnits": "(GeV)", "xMin" : 0.0, "xMax" : 100.0, "yMin" : None, "yMax" : None, "xLegMin": 0.65, "xLegMax": 0.94, "yLegMin": 0.84, "yLegMax": 0.94, 
           "xCutLines": [], "xCutBoxes": [], "normaliseTo": None, "ratio": False, "logX": False, "logY": False, "binWidthX": 2,  "saveName": "hMCT_VisEt"}
hMCT_VisEt0 = m_histos.TH1orTH2(folder, "hMCT_VisEt_0", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "Electron", **MCTVisEt)
hMCT_VisEt1 = m_histos.TH1orTH2(folder, "hMCT_VisEt_1", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "Muon", **MCTVisEt)
hMCT_VisEt2 = m_histos.TH1orTH2(folder, "hMCT_VisEt_2", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "1-prong (0 #pi^{0})", **MCTVisEt)
hMCT_VisEt3 = m_histos.TH1orTH2(folder, "hMCT_VisEt_3", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "1-prong (1 #pi^{0})", **MCTVisEt)
hMCT_VisEt4 = m_histos.TH1orTH2(folder, "hMCT_VisEt_4", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "1-prong (2 #pi^{0})", **MCTVisEt)
hMCT_VisEt5 = m_histos.TH1orTH2(folder, "hMCT_VisEt_5", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "3-prong (0 #pi^{0})", **MCTVisEt)
hMCT_VisEt6 = m_histos.TH1orTH2(folder, "hMCT_VisEt_6", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "3-prong (1 #pi^{0})", **MCTVisEt)
hMCT_VisEt7 = m_histos.TH1orTH2(folder, "hMCT_VisEt_7", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "Other", **MCTVisEt)
hMCT_VisEt8 = m_histos.TH1orTH2(folder, "hMCT_VisEt_8", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "Undefined", **MCTVisEt)
hMCT_VisEt9 = m_histos.TH1orTH2(folder, "hMCT_VisEt_9", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "?", **MCTVisEt)
MCT_VisEt = []
MCT_VisEt.append(hMCT_VisEt0)
MCT_VisEt.append(hMCT_VisEt1)
MCT_VisEt.append(hMCT_VisEt2)
MCT_VisEt.append(hMCT_VisEt3)
MCT_VisEt.append(hMCT_VisEt4)
MCT_VisEt.append(hMCT_VisEt5)
MCT_VisEt.append(hMCT_VisEt6)
#MCT_VisEt.append(hMCT_VisEt7)
#MCT_VisEt.append(hMCT_VisEt8)
#MCT_VisEt.append(hMCT_VisEt9)


MCTVisEta = {"xMin" : -3.0, "xMax" : 3.0, "yMin" : 0.01, "yMax" : None, "xLegMin": 0.65, "xLegMax": 0.94, "yLegMin": 0.84, "yLegMax": 0.94, 
"xCutLines": [], "xCutBoxes": [], "normaliseTo": None, "ratio": False, "logX": False, "logY": False, "binWidthX": None, "saveName": "hMCT_VisEta"}
hMCT_VisEta0 = m_histos.TH1orTH2(folder, "hMCT_VisEta_0", "#tau_{mc} #eta^{vis}", "Entries / %0.1f", "Electron", **MCTVisEta)
hMCT_VisEta1 = m_histos.TH1orTH2(folder, "hMCT_VisEta_1", "#tau_{mc} #eta^{vis}", "Entries / %0.1f", "Muon", **MCTVisEta)
hMCT_VisEta2 = m_histos.TH1orTH2(folder, "hMCT_VisEta_2", "#tau_{mc} #eta^{vis}", "Entries / %0.1f", "1-prong (0 #pi^{0})", **MCTVisEta)
hMCT_VisEta3 = m_histos.TH1orTH2(folder, "hMCT_VisEta_3", "#tau_{mc} #eta^{vis}", "Entries / %0.1f", "1-prong (1 #pi^{0})", **MCTVisEta)
hMCT_VisEta4 = m_histos.TH1orTH2(folder, "hMCT_VisEta_4", "#tau_{mc} #eta^{vis}", "Entries / %0.1f", "1-prong (2 #pi^{0})", **MCTVisEta)
hMCT_VisEta5 = m_histos.TH1orTH2(folder, "hMCT_VisEta_5", "#tau_{mc} #eta^{vis}", "Entries / %0.1f", "3-prong (0 #pi^{0})", **MCTVisEta)
hMCT_VisEta6 = m_histos.TH1orTH2(folder, "hMCT_VisEta_6", "#tau_{mc} #eta^{vis}", "Entries / %0.1f", "3-prong (1 #pi^{0})", **MCTVisEta)
hMCT_VisEta7 = m_histos.TH1orTH2(folder, "hMCT_VisEta_7", "#tau_{mc} #eta^{vis}", "Entries / %0.1f", "Other", **MCTVisEta)
hMCT_VisEta8 = m_histos.TH1orTH2(folder, "hMCT_VisEta_8", "#tau_{mc} #eta^{vis}", "Entries / %0.1f", "Undefined", **MCTVisEta)
hMCT_VisEta9 = m_histos.TH1orTH2(folder, "hMCT_VisEta_9", "#tau_{mc} #eta^{vis}", "Entries / %0.1f", "?", **MCTVisEta)
MCT_VisEta  = []
MCT_VisEta.append(hMCT_VisEta0)
MCT_VisEta.append(hMCT_VisEta1)
MCT_VisEta.append(hMCT_VisEta2)
MCT_VisEta.append(hMCT_VisEta3)
MCT_VisEta.append(hMCT_VisEta4)
MCT_VisEta.append(hMCT_VisEta5)
MCT_VisEta.append(hMCT_VisEta6)
#MCT_VisEta.append(hMCT_VisEta7)
#MCT_VisEta.append(hMCT_VisEta8)
#MCT_VisEta.append(hMCT_VisEta9)


MCTEt = {"xUnits": "(GeV)", "xMin" : 0.0, "xMax" : 100.0, "yMin" : None, "yMax" : None, "xLegMin": 0.65, "xLegMax": 0.94, "yLegMin": 0.84, "yLegMax": 0.94, 
         "xCutLines": [], "xCutBoxes": [], "normaliseTo": None, "ratio": False, "logX": False, "logY": False, "binWidthX": 2, "saveName": "hMCT_Et" }
hMCT_Et0 = m_histos.TH1orTH2(folder, "hMCT_Et_0", "#tau_{mc} E_{T}", "Entries / %0.0f", "Electron", **MCTEt)
hMCT_Et1 = m_histos.TH1orTH2(folder, "hMCT_Et_1", "#tau_{mc} E_{T}", "Entries / %0.0f", "Muon", **MCTEt)
hMCT_Et2 = m_histos.TH1orTH2(folder, "hMCT_Et_2", "#tau_{mc} E_{T}", "Entries / %0.0f", "1-prong (0 #pi^{0})", **MCTEt)
hMCT_Et3 = m_histos.TH1orTH2(folder, "hMCT_Et_3", "#tau_{mc} E_{T}", "Entries / %0.0f", "1-prong (1 #pi^{0})", **MCTEt)
hMCT_Et4 = m_histos.TH1orTH2(folder, "hMCT_Et_4", "#tau_{mc} E_{T}", "Entries / %0.0f", "1-prong (2 #pi^{0})", **MCTEt)
hMCT_Et5 = m_histos.TH1orTH2(folder, "hMCT_Et_5", "#tau_{mc} E_{T}", "Entries / %0.0f", "3-prong (0 #pi^{0})", **MCTEt)
hMCT_Et6 = m_histos.TH1orTH2(folder, "hMCT_Et_6", "#tau_{mc} E_{T}", "Entries / %0.0f", "3-prong (1 #pi^{0})", **MCTEt)
hMCT_Et7 = m_histos.TH1orTH2(folder, "hMCT_Et_7", "#tau_{mc} E_{T}", "Entries / %0.0f", "Other", **MCTEt)
hMCT_Et8 = m_histos.TH1orTH2(folder, "hMCT_Et_8", "#tau_{mc} E_{T}", "Entries / %0.0f", "Undefined", **MCTEt)
hMCT_Et9 = m_histos.TH1orTH2(folder, "hMCT_Et_9", "#tau_{mc} E_{T}", "Entries / %0.0f", "?", **MCTEt)
MCT_Et = []
MCT_Et.append(hMCT_Et0)
MCT_Et.append(hMCT_Et1)
MCT_Et.append(hMCT_Et2)
MCT_Et.append(hMCT_Et3)
MCT_Et.append(hMCT_Et4)
MCT_Et.append(hMCT_Et5)
MCT_Et.append(hMCT_Et6)
#MCT_Et.append(hMCT_Et7)
#MCT_Et.append(hMCT_Et8)
#MCT_Et.append(hMCT_Et9)


MCTEta = {"xMin" : -3.0, "xMax" : 3.0, "yMin" : 0.01, "yMax" : None, "xLegMin": 0.65, "xLegMax": 0.94, "yLegMin": 0.84, "yLegMax": 0.94, 
          "xCutLines": [], "xCutBoxes": [], "normaliseTo": None, "ratio": False, "logX": False, "logY": False, "binWidthX": None, "saveName": "hMCT_Eta"}
hMCT_Eta0 = m_histos.TH1orTH2(folder, "hMCT_Eta_0", "#tau_{mc} #eta", "Entries / %0.1f", "Electron", **MCTEta)
hMCT_Eta1 = m_histos.TH1orTH2(folder, "hMCT_Eta_1", "#tau_{mc} #eta", "Entries / %0.1f", "Muon", **MCTEta)
hMCT_Eta2 = m_histos.TH1orTH2(folder, "hMCT_Eta_2", "#tau_{mc} #eta", "Entries / %0.1f", "1-prong (0 #pi^{0})", **MCTEta)
hMCT_Eta3 = m_histos.TH1orTH2(folder, "hMCT_Eta_3", "#tau_{mc} #eta", "Entries / %0.1f", "1-prong (1 #pi^{0})", **MCTEta)
hMCT_Eta4 = m_histos.TH1orTH2(folder, "hMCT_Eta_4", "#tau_{mc} #eta", "Entries / %0.1f", "1-prong (2 #pi^{0})", **MCTEta)
hMCT_Eta5 = m_histos.TH1orTH2(folder, "hMCT_Eta_5", "#tau_{mc} #eta", "Entries / %0.1f", "3-prong (0 #pi^{0})", **MCTEta)
hMCT_Eta6 = m_histos.TH1orTH2(folder, "hMCT_Eta_6", "#tau_{mc} #eta", "Entries / %0.1f", "3-prong (1 #pi^{0})", **MCTEta)
hMCT_Eta7 = m_histos.TH1orTH2(folder, "hMCT_Eta_7", "#tau_{mc} #eta", "Entries / %0.1f", "Other", **MCTEta)
hMCT_Eta8 = m_histos.TH1orTH2(folder, "hMCT_Eta_8", "#tau_{mc} #eta", "Entries / %0.1f", "Undefined", **MCTEta)
hMCT_Eta9 = m_histos.TH1orTH2(folder, "hMCT_Eta_9", "#tau_{mc} #eta", "Entries / %0.1f", "?", **MCTEta)
MCT_Eta  = []
MCT_Eta.append(hMCT_Eta0)
MCT_Eta.append(hMCT_Eta1)
MCT_Eta.append(hMCT_Eta2)
MCT_Eta.append(hMCT_Eta3)
MCT_Eta.append(hMCT_Eta4)
MCT_Eta.append(hMCT_Eta5)
MCT_Eta.append(hMCT_Eta6)
#MCT_Eta.append(hMCT_Eta7)
#MCT_Eta.append(hMCT_Eta8)
#MCT_Eta.append(hMCT_Eta9)


MCTLeadPt   = {"xUnits": "(GeV/c)", "xMin" : 0.0, "xMax" : 100.0, "yMin" : 0.1, "yMax" : None, "xLegMin": 0.65, "xLegMax": 0.94, "yLegMin": 0.84, "yLegMax": 0.94, 
               "xCutLines": [], "normaliseTo": None, "ratio": False, "logX": False, "logY": True, "binWidthX": 2, "styleType": None, "saveName": "hMCT_LeadPt"}
hMCT_LeadPt0 = m_histos.TH1orTH2(folder, "hMCT_LeadPt_0", "#tau_{mc} p_{T}^{ldg}", "Entries / %0.1f", "Electron", **MCTLeadPt)
hMCT_LeadPt1 = m_histos.TH1orTH2(folder, "hMCT_LeadPt_1", "#tau_{mc} p_{T}^{ldg}", "Entries / %0.1f", "Muon", **MCTLeadPt)
hMCT_LeadPt2 = m_histos.TH1orTH2(folder, "hMCT_LeadPt_2", "#tau_{mc} p_{T}^{ldg}", "Entries / %0.1f", "1-prong (0 #pi^{0})", **MCTLeadPt)
hMCT_LeadPt3 = m_histos.TH1orTH2(folder, "hMCT_LeadPt_3", "#tau_{mc} p_{T}^{ldg}", "Entries / %0.1f", "1-prong (1 #pi^{0})", **MCTLeadPt)
hMCT_LeadPt4 = m_histos.TH1orTH2(folder, "hMCT_LeadPt_4", "#tau_{mc} p_{T}^{ldg}", "Entries / %0.1f", "1-prong (2 #pi^{0})", **MCTLeadPt)
hMCT_LeadPt5 = m_histos.TH1orTH2(folder, "hMCT_LeadPt_5", "#tau_{mc} p_{T}^{ldg}", "Entries / %0.1f", "3-prong (0 #pi^{0})", **MCTLeadPt)
hMCT_LeadPt6 = m_histos.TH1orTH2(folder, "hMCT_LeadPt_6", "#tau_{mc} p_{T}^{ldg}", "Entries / %0.1f", "3-prong (1 #pi^{0})", **MCTLeadPt)
hMCT_LeadPt7 = m_histos.TH1orTH2(folder, "hMCT_LeadPt_7", "#tau_{mc} p_{T}^{ldg}", "Entries / %0.1f", "Other", **MCTLeadPt)
hMCT_LeadPt8 = m_histos.TH1orTH2(folder, "hMCT_LeadPt_8", "#tau_{mc} p_{T}^{ldg}", "Entries / %0.1f", "Undefined", **MCTLeadPt)
hMCT_LeadPt9 = m_histos.TH1orTH2(folder, "hMCT_LeadPt_9", "#tau_{mc} p_{T}^{ldg}", "Entries / %0.1f", "?", **MCTLeadPt)
MCT_LeadPt  = []
MCT_LeadPt.append(hMCT_LeadPt0)
MCT_LeadPt.append(hMCT_LeadPt1)
MCT_LeadPt.append(hMCT_LeadPt2)
MCT_LeadPt.append(hMCT_LeadPt3)
MCT_LeadPt.append(hMCT_LeadPt4)
MCT_LeadPt.append(hMCT_LeadPt5)
MCT_LeadPt.append(hMCT_LeadPt6)
#MCT_LeadPt.append(hMCT_LeadPt7)
#MCT_LeadPt.append(hMCT_LeadPt8)
#MCT_LeadPt.append(hMCT_LeadPt9)


MCTLeadEta = {"xMin" : -3.0, "xMax" : 3.0, "yMin" : 0.01, "yMax" : None, "xLegMin": 0.65, "xLegMax": 0.94, "yLegMin": 0.84, "yLegMax": 0.94, 
              "xCutLines": [], "xCutBoxes": [], "normaliseTo": None, "ratio": False, "logX": False, "logY": False, "binWidthX": None, "saveName": "hMCT_LeadEta"}
hMCT_LeadEta0 = m_histos.TH1orTH2(folder, "hMCT_LeadEta_0", "#tau_{mc} #eta^{ldg}", "Entries / %0.1f", "Electron", **MCTLeadEta)
hMCT_LeadEta1 = m_histos.TH1orTH2(folder, "hMCT_LeadEta_1", "#tau_{mc} #eta^{ldg}", "Entries / %0.1f", "Muon", **MCTLeadEta)
hMCT_LeadEta2 = m_histos.TH1orTH2(folder, "hMCT_LeadEta_2", "#tau_{mc} #eta^{ldg}", "Entries / %0.1f", "1-prong (0 #pi^{0})", **MCTLeadEta)
hMCT_LeadEta3 = m_histos.TH1orTH2(folder, "hMCT_LeadEta_3", "#tau_{mc} #eta^{ldg}", "Entries / %0.1f", "1-prong (1 #pi^{0})", **MCTLeadEta)
hMCT_LeadEta4 = m_histos.TH1orTH2(folder, "hMCT_LeadEta_4", "#tau_{mc} #eta^{ldg}", "Entries / %0.1f", "1-prong (2 #pi^{0})", **MCTLeadEta)
hMCT_LeadEta5 = m_histos.TH1orTH2(folder, "hMCT_LeadEta_5", "#tau_{mc} #eta^{ldg}", "Entries / %0.1f", "3-prong (0 #pi^{0})", **MCTLeadEta)
hMCT_LeadEta6 = m_histos.TH1orTH2(folder, "hMCT_LeadEta_6", "#tau_{mc} #eta^{ldg}", "Entries / %0.1f", "3-prong (1 #pi^{0})", **MCTLeadEta)
hMCT_LeadEta7 = m_histos.TH1orTH2(folder, "hMCT_LeadEta_7", "#tau_{mc} #eta^{ldg}", "Entries / %0.1f", "Other", **MCTLeadEta)
hMCT_LeadEta8 = m_histos.TH1orTH2(folder, "hMCT_LeadEta_8", "#tau_{mc} #eta^{ldg}", "Entries / %0.1f", "Undefined", **MCTLeadEta)
hMCT_LeadEta9 = m_histos.TH1orTH2(folder, "hMCT_LeadEta_9", "#tau_{mc} #eta^{ldg}", "Entries / %0.1f", "?", **MCTLeadEta)
MCT_LeadEta  = []
MCT_LeadEta.append(hMCT_LeadEta0)
MCT_LeadEta.append(hMCT_LeadEta1)
MCT_LeadEta.append(hMCT_LeadEta2)
MCT_LeadEta.append(hMCT_LeadEta3)
MCT_LeadEta.append(hMCT_LeadEta4)
MCT_LeadEta.append(hMCT_LeadEta5)
MCT_LeadEta.append(hMCT_LeadEta6)
#MCT_LeadEta.append(hMCT_LeadEta7)
#MCT_LeadEta.append(hMCT_LeadEta8)
#MCT_LeadEta.append(hMCT_LeadEta9)


MCTNCharged = {"xMin" : 0.0, "xMax" : 10.0, "yMin" : 1, "yMax" : None, "xLegMin": 0.65, "xLegMax": 0.94, "yLegMin": 0.84, "yLegMax": 0.94, 
               "xCutLines": [], "normaliseToOne" : False, "ratio": False, "logX": False, "logY": True, "binWidthX": None, "saveName": "hMCT_NCharged"}
hMCT_NCharged0 = m_histos.TH1orTH2(folder, "hMCT_NCharged_0", "#tau_{mc} N_{h^{#pm}}", "Entries / %0.0f", "Electron", **MCTNCharged)
hMCT_NCharged1 = m_histos.TH1orTH2(folder, "hMCT_NCharged_1", "#tau_{mc} N_{h^{#pm}}", "Entries / %0.0f", "Muon", **MCTNCharged)
hMCT_NCharged2 = m_histos.TH1orTH2(folder, "hMCT_NCharged_2", "#tau_{mc} N_{h^{#pm}}", "Entries / %0.0f", "1-prong (0 #pi^{0})", **MCTNCharged)
hMCT_NCharged3 = m_histos.TH1orTH2(folder, "hMCT_NCharged_3", "#tau_{mc} N_{h^{#pm}}", "Entries / %0.0f", "1-prong (1 #pi^{0})", **MCTNCharged)
hMCT_NCharged4 = m_histos.TH1orTH2(folder, "hMCT_NCharged_4", "#tau_{mc} N_{h^{#pm}}", "Entries / %0.0f", "1-prong (2 #pi^{0})", **MCTNCharged)
hMCT_NCharged5 = m_histos.TH1orTH2(folder, "hMCT_NCharged_5", "#tau_{mc} N_{h^{#pm}}", "Entries / %0.0f", "3-prong (0 #pi^{0})", **MCTNCharged)
hMCT_NCharged6 = m_histos.TH1orTH2(folder, "hMCT_NCharged_6", "#tau_{mc} N_{h^{#pm}}", "Entries / %0.0f", "3-prong (1 #pi^{0})", **MCTNCharged)
hMCT_NCharged7 = m_histos.TH1orTH2(folder, "hMCT_NCharged_7", "#tau_{mc} N_{h^{#pm}}", "Entries / %0.0f", "Other", **MCTNCharged)
hMCT_NCharged8 = m_histos.TH1orTH2(folder, "hMCT_NCharged_8", "#tau_{mc} N_{h^{#pm}}", "Entries / %0.0f", "Undefined", **MCTNCharged)
hMCT_NCharged9 = m_histos.TH1orTH2(folder, "hMCT_NCharged_9", "#tau_{mc} N_{h^{#pm}}", "Entries / %0.0f", "?", **MCTNCharged)
MCT_NCharged  = []
MCT_NCharged.append(hMCT_NCharged0)
MCT_NCharged.append(hMCT_NCharged1)
MCT_NCharged.append(hMCT_NCharged2)
MCT_NCharged.append(hMCT_NCharged3)
MCT_NCharged.append(hMCT_NCharged4)
MCT_NCharged.append(hMCT_NCharged5)
MCT_NCharged.append(hMCT_NCharged6)
#MCT_NCharged.append(hMCT_NCharged7)
#MCT_NCharged.append(hMCT_NCharged8)
#MCT_NCharged.append(hMCT_NCharged9)


### L1 Tk Tracks (10 signifies selected tracks after signal track pt cut "MinTrackPt" in py_cfg file when running analyzer)
###############################################################
TkTrackPt = {"xUnits": "(GeV/c)", "xMin" : 0.0, "xMax" : 100.0, "yMin" : 0.1, "yMax" : None, "xLegMin": 0.65, "xLegMax": 0.94, "yLegMin": 0.84, "yLegMax": 0.94, 
             "xCutLines": [10], "normaliseTo": None, "ratio": False, "logX": False, "logY": True, "binWidthX": 2, "saveName": "hL1TkTrack10_Pt"}
hL1TkTrack10_Pt0 = m_histos.TH1orTH2(folder, "hL1TkTrack10_Pt_0", "L1 Tk p_{T}", "Entries / %0.0f", "Electron", **TkTrackPt)
hL1TkTrack10_Pt1 = m_histos.TH1orTH2(folder, "hL1TkTrack10_Pt_1", "L1 Tk p_{T}", "Entries / %0.0f", "Muon", **TkTrackPt)
hL1TkTrack10_Pt2 = m_histos.TH1orTH2(folder, "hL1TkTrack10_Pt_2", "L1 Tk p_{T}", "Entries / %0.0f", "1-prong (0 #pi^{0})", **TkTrackPt)
hL1TkTrack10_Pt3 = m_histos.TH1orTH2(folder, "hL1TkTrack10_Pt_3", "L1 Tk p_{T}", "Entries / %0.0f", "1-prong (1 #pi^{0})", **TkTrackPt)
hL1TkTrack10_Pt4 = m_histos.TH1orTH2(folder, "hL1TkTrack10_Pt_4", "L1 Tk p_{T}", "Entries / %0.0f", "1-prong (2 #pi^{0})", **TkTrackPt)
hL1TkTrack10_Pt5 = m_histos.TH1orTH2(folder, "hL1TkTrack10_Pt_5", "L1 Tk p_{T}", "Entries / %0.0f", "3-prong (0 #pi^{0})", **TkTrackPt)
hL1TkTrack10_Pt6 = m_histos.TH1orTH2(folder, "hL1TkTrack10_Pt_6", "L1 Tk p_{T}", "Entries / %0.0f", "3-prong (1 #pi^{0})", **TkTrackPt)
hL1TkTrack10_Pt7 = m_histos.TH1orTH2(folder, "hL1TkTrack10_Pt_7", "L1 Tk p_{T}", "Entries / %0.0f", "Other", **TkTrackPt)
hL1TkTrack10_Pt8 = m_histos.TH1orTH2(folder, "hL1TkTrack10_Pt_8", "L1 Tk p_{T}", "Entries / %0.0f", "Undefined", **TkTrackPt)
hL1TkTrack10_Pt9 = m_histos.TH1orTH2(folder, "hL1TkTrack10_Pt_9", "L1 Tk p_{T}", "Entries / %0.0f", "?", **TkTrackPt)
L1TkTrack10_Pt  = []
L1TkTrack10_Pt.append(hL1TkTrack10_Pt0)
L1TkTrack10_Pt.append(hL1TkTrack10_Pt1)
L1TkTrack10_Pt.append(hL1TkTrack10_Pt2)
L1TkTrack10_Pt.append(hL1TkTrack10_Pt3)
L1TkTrack10_Pt.append(hL1TkTrack10_Pt4)
L1TkTrack10_Pt.append(hL1TkTrack10_Pt5)
L1TkTrack10_Pt.append(hL1TkTrack10_Pt6)
#L1TkTrack10_Pt.append(hL1TkTrack10_Pt7)
#L1TkTrack10_Pt.append(hL1TkTrack10_Pt8)
#L1TkTrack10_Pt.append(hL1TkTrack10_Pt9)


TkTrackEta = {"xMin" : -3.0, "xMax" : 3.0, "yMin" : 0.01, "yMax" : None, "xLegMin": 0.65, "xLegMax": 0.94, "yLegMin": 0.84, "yLegMax": 0.94, 
              "xCutLines": [], "xCutBoxes": [], "normaliseTo": None, "ratio": False, "logX": False, "logY": False, "binWidthX": None, "saveName": "hL1TkTrack10_Eta"}
hL1TkTrack10_Eta0 = m_histos.TH1orTH2(folder, "hL1TkTrack10_Eta_0", "L1 Tk #eta", "Entries / %0.1f", "Electron", **TkTrackEta)
hL1TkTrack10_Eta1 = m_histos.TH1orTH2(folder, "hL1TkTrack10_Eta_1", "L1 Tk #eta", "Entries / %0.1f", "Muon", **TkTrackEta)
hL1TkTrack10_Eta2 = m_histos.TH1orTH2(folder, "hL1TkTrack10_Eta_2", "L1 Tk #eta", "Entries / %0.1f", "1-prong (0 #pi^{0})", **TkTrackEta)
hL1TkTrack10_Eta3 = m_histos.TH1orTH2(folder, "hL1TkTrack10_Eta_3", "L1 Tk #eta", "Entries / %0.1f", "1-prong (1 #pi^{0})", **TkTrackEta)
hL1TkTrack10_Eta4 = m_histos.TH1orTH2(folder, "hL1TkTrack10_Eta_4", "L1 Tk #eta", "Entries / %0.1f", "1-prong (2 #pi^{0})", **TkTrackEta)
hL1TkTrack10_Eta5 = m_histos.TH1orTH2(folder, "hL1TkTrack10_Eta_5", "L1 Tk #eta", "Entries / %0.1f", "3-prong (0 #pi^{0})", **TkTrackEta)
hL1TkTrack10_Eta6 = m_histos.TH1orTH2(folder, "hL1TkTrack10_Eta_6", "L1 Tk #eta", "Entries / %0.1f", "3-prong (1 #pi^{0})", **TkTrackEta)
hL1TkTrack10_Eta7 = m_histos.TH1orTH2(folder, "hL1TkTrack10_Eta_7", "L1 Tk #eta", "Entries / %0.1f", "Other", **TkTrackEta)
hL1TkTrack10_Eta8 = m_histos.TH1orTH2(folder, "hL1TkTrack10_Eta_8", "L1 Tk #eta", "Entries / %0.1f", "Undefined", **TkTrackEta)
hL1TkTrack10_Eta9 = m_histos.TH1orTH2(folder, "hL1TkTrack10_Eta_9", "L1 Tk #eta", "Entries / %0.1f", "?", **TkTrackEta)
L1TkTrack10_Eta  = []
L1TkTrack10_Eta.append(hL1TkTrack10_Eta0)
L1TkTrack10_Eta.append(hL1TkTrack10_Eta1)
L1TkTrack10_Eta.append(hL1TkTrack10_Eta2)
L1TkTrack10_Eta.append(hL1TkTrack10_Eta3)
L1TkTrack10_Eta.append(hL1TkTrack10_Eta4)
L1TkTrack10_Eta.append(hL1TkTrack10_Eta5)
L1TkTrack10_Eta.append(hL1TkTrack10_Eta6)
#L1TkTrack10_Eta.append(hL1TkTrack10_Eta7)
#L1TkTrack10_Eta.append(hL1TkTrack10_Eta8)
#L1TkTrack10_Eta.append(hL1TkTrack10_Eta9)


TkTrackVtxZ0 = {"xUnits": "cm", "xMin" : -30, "xMax" : +30, "yMin" : None, "yMax" : None, "xLegMin": 0.65, "xLegMax": 0.94, "yLegMin": 0.84, "yLegMax": 0.94, 
                "xCutLines": [0], "xCutBoxes": [], "normaliseTo": None, "ratio": False, "logX": False, "logY": False, "binWidthX": None, "saveName": "hL1TkTrack10_VtxZ0"}
hL1TkTrack10_VtxZ0_0 = m_histos.TH1orTH2(folder, "hL1TkTrack10_VtxZ0_0", "L1 Tk z_{vtx}", "Entries / %0.1f", "Electron", **TkTrackVtxZ0)
hL1TkTrack10_VtxZ0_1 = m_histos.TH1orTH2(folder, "hL1TkTrack10_VtxZ0_1", "L1 Tk z_{vtx}", "Entries / %0.1f", "Muon", **TkTrackVtxZ0)
hL1TkTrack10_VtxZ0_2 = m_histos.TH1orTH2(folder, "hL1TkTrack10_VtxZ0_2", "L1 Tk z_{vtx}", "Entries / %0.1f", "1-prong (0 #pi^{0})", **TkTrackVtxZ0)
hL1TkTrack10_VtxZ0_3 = m_histos.TH1orTH2(folder, "hL1TkTrack10_VtxZ0_3", "L1 Tk z_{vtx}", "Entries / %0.1f", "1-prong (1 #pi^{0})", **TkTrackVtxZ0)
hL1TkTrack10_VtxZ0_4 = m_histos.TH1orTH2(folder, "hL1TkTrack10_VtxZ0_4", "L1 Tk z_{vtx}", "Entries / %0.1f", "1-prong (2 #pi^{0})", **TkTrackVtxZ0)
hL1TkTrack10_VtxZ0_5 = m_histos.TH1orTH2(folder, "hL1TkTrack10_VtxZ0_5", "L1 Tk z_{vtx}", "Entries / %0.1f", "3-prong (0 #pi^{0})", **TkTrackVtxZ0)
hL1TkTrack10_VtxZ0_6 = m_histos.TH1orTH2(folder, "hL1TkTrack10_VtxZ0_6", "L1 Tk z_{vtx}", "Entries / %0.1f", "3-prong (1 #pi^{0})", **TkTrackVtxZ0)
hL1TkTrack10_VtxZ0_7 = m_histos.TH1orTH2(folder, "hL1TkTrack10_VtxZ0_7", "L1 Tk z_{vtx}", "Entries / %0.1f", "Other", **TkTrackVtxZ0)
hL1TkTrack10_VtxZ0_8 = m_histos.TH1orTH2(folder, "hL1TkTrack10_VtxZ0_8", "L1 Tk z_{vtx}", "Entries / %0.1f", "Undefined", **TkTrackVtxZ0)
hL1TkTrack10_VtxZ0_9 = m_histos.TH1orTH2(folder, "hL1TkTrack10_VtxZ0_9", "L1 Tk z_{vtx}", "Entries / %0.1f", "?", **TkTrackVtxZ0)
L1TkTrack10_VtxZ0   = []
L1TkTrack10_VtxZ0.append(hL1TkTrack10_VtxZ0_0)
L1TkTrack10_VtxZ0.append(hL1TkTrack10_VtxZ0_1)
L1TkTrack10_VtxZ0.append(hL1TkTrack10_VtxZ0_2)
L1TkTrack10_VtxZ0.append(hL1TkTrack10_VtxZ0_3)
L1TkTrack10_VtxZ0.append(hL1TkTrack10_VtxZ0_4)
L1TkTrack10_VtxZ0.append(hL1TkTrack10_VtxZ0_5)
L1TkTrack10_VtxZ0.append(hL1TkTrack10_VtxZ0_6)
#L1TkTrack10_VtxZ0.append(hL1TkTrack10_VtxZ0_7)
#L1TkTrack10_VtxZ0.append(hL1TkTrack10_VtxZ0_8)
#L1TkTrack10_VtxZ0.append(hL1TkTrack10_VtxZ0_9)


TkTrackN = {"xMin" : 0.0, "xMax" : 6.0, "yMin" : 1, "yMax" : None, "xLegMin": 0.65, "xLegMax": 0.94, "yLegMin": 0.84, "yLegMax": 0.94, 
            "xCutLines": [], "normaliseToOne" : False, "ratio": False, "logX": False, "logY": True, "binWidthX": None, "saveName": "hL1TkTrack10_N"}
hL1TkTrack10_N_0 = m_histos.TH1orTH2(folder, "hL1TkTrack10_N_0", "L1 Tks per #tau_{mc}", "Entries / %0.0f", "Electron", **TkTrackN)
hL1TkTrack10_N_1 = m_histos.TH1orTH2(folder, "hL1TkTrack10_N_1", "L1 Tks per #tau_{mc}", "Entries / %0.0f", "Muon", **TkTrackN)
hL1TkTrack10_N_2 = m_histos.TH1orTH2(folder, "hL1TkTrack10_N_2", "L1 Tks per #tau_{mc}", "Entries / %0.0f", "1-prong (0 #pi^{0})", **TkTrackN)
hL1TkTrack10_N_3 = m_histos.TH1orTH2(folder, "hL1TkTrack10_N_3", "L1 Tks per #tau_{mc}", "Entries / %0.0f", "1-prong (1 #pi^{0})", **TkTrackN)
hL1TkTrack10_N_4 = m_histos.TH1orTH2(folder, "hL1TkTrack10_N_4", "L1 Tks per #tau_{mc}", "Entries / %0.0f", "1-prong (2 #pi^{0})", **TkTrackN)
hL1TkTrack10_N_5 = m_histos.TH1orTH2(folder, "hL1TkTrack10_N_5", "L1 Tks per #tau_{mc}", "Entries / %0.0f", "3-prong (0 #pi^{0})", **TkTrackN)
hL1TkTrack10_N_6 = m_histos.TH1orTH2(folder, "hL1TkTrack10_N_6", "L1 Tks per #tau_{mc}", "Entries / %0.0f", "3-prong (1 #pi^{0})", **TkTrackN)
hL1TkTrack10_N_7 = m_histos.TH1orTH2(folder, "hL1TkTrack10_N_7", "L1 Tks per #tau_{mc}", "Entries / %0.0f", "Other", **TkTrackN)
hL1TkTrack10_N_8 = m_histos.TH1orTH2(folder, "hL1TkTrack10_N_8", "L1 Tks per #tau_{mc}", "Entries / %0.0f", "Undefined", **TkTrackN)
hL1TkTrack10_N_9 = m_histos.TH1orTH2(folder, "hL1TkTrack10_N_9", "L1 Tks per #tau_{mc}", "Entries / %0.0f", "?", **TkTrackN)
L1TkTrack10_N   = []
L1TkTrack10_N.append(hL1TkTrack10_N_0)
L1TkTrack10_N.append(hL1TkTrack10_N_1)
L1TkTrack10_N.append(hL1TkTrack10_N_2)
L1TkTrack10_N.append(hL1TkTrack10_N_3)
L1TkTrack10_N.append(hL1TkTrack10_N_4)
L1TkTrack10_N.append(hL1TkTrack10_N_5)
L1TkTrack10_N.append(hL1TkTrack10_N_6)
#L1TkTrack10_N.append(hL1TkTrack10_N_7)
#L1TkTrack10_N.append(hL1TkTrack10_N_8)
#L1TkTrack10_N.append(hL1TkTrack10_N_9)


TkTrackDeltaPt = {"xUnits": "(GeV/c)", "xMin" : 0.0, "xMax" : 50.0, "yMin" : None, "yMax" : None, "logX": False, "logY": False, "binWidthX": 2, "saveName": "hL1TkTrack10_DeltaPt"}
hL1TkTrack10_DeltaPt0 = m_histos.TH1orTH2(folder, "hL1TkTrack10_DeltaPt_0", "L1 Tk #Deltap_{T} (same #tau_{mc})", "Entries / %0.0f", "Electron", **TkTrackDeltaPt)
hL1TkTrack10_DeltaPt1 = m_histos.TH1orTH2(folder, "hL1TkTrack10_DeltaPt_1", "L1 Tk #Deltap_{T} (same #tau_{mc})", "Entries / %0.0f", "Muon", **TkTrackDeltaPt)
hL1TkTrack10_DeltaPt2 = m_histos.TH1orTH2(folder, "hL1TkTrack10_DeltaPt_2", "L1 Tk #Deltap_{T} (same #tau_{mc})", "Entries / %0.0f", "1-prong (0 #pi^{0})", **TkTrackDeltaPt)
hL1TkTrack10_DeltaPt3 = m_histos.TH1orTH2(folder, "hL1TkTrack10_DeltaPt_3", "L1 Tk #Deltap_{T} (same #tau_{mc})", "Entries / %0.0f", "1-prong (1 #pi^{0})", **TkTrackDeltaPt)
hL1TkTrack10_DeltaPt4 = m_histos.TH1orTH2(folder, "hL1TkTrack10_DeltaPt_4", "L1 Tk #Deltap_{T} (same #tau_{mc})", "Entries / %0.0f", "1-prong (2 #pi^{0})", **TkTrackDeltaPt)
hL1TkTrack10_DeltaPt5 = m_histos.TH1orTH2(folder, "hL1TkTrack10_DeltaPt_5", "L1 Tk #Deltap_{T} (same #tau_{mc})", "Entries / %0.0f", "3-prong (0 #pi^{0})", **TkTrackDeltaPt)
hL1TkTrack10_DeltaPt6 = m_histos.TH1orTH2(folder, "hL1TkTrack10_DeltaPt_6", "L1 Tk #Deltap_{T} (same #tau_{mc})", "Entries / %0.0f", "3-prong (1 #pi^{0})", **TkTrackDeltaPt)
hL1TkTrack10_DeltaPt7 = m_histos.TH1orTH2(folder, "hL1TkTrack10_DeltaPt_7", "L1 Tk #Deltap_{T} (same #tau_{mc})", "Entries / %0.0f", "Other", **TkTrackDeltaPt)
hL1TkTrack10_DeltaPt8 = m_histos.TH1orTH2(folder, "hL1TkTrack10_DeltaPt_8", "L1 Tk #Deltap_{T} (same #tau_{mc})", "Entries / %0.0f", "Undefined", **TkTrackDeltaPt)
hL1TkTrack10_DeltaPt9 = m_histos.TH1orTH2(folder, "hL1TkTrack10_DeltaPt_9", "L1 Tk #Deltap_{T} (same #tau_{mc})", "Entries / %0.0f", "?", **TkTrackDeltaPt)
L1TkTrack10_DeltaPt  = []
L1TkTrack10_DeltaPt.append(hL1TkTrack10_DeltaPt0)
L1TkTrack10_DeltaPt.append(hL1TkTrack10_DeltaPt1)
L1TkTrack10_DeltaPt.append(hL1TkTrack10_DeltaPt2)
L1TkTrack10_DeltaPt.append(hL1TkTrack10_DeltaPt3)
L1TkTrack10_DeltaPt.append(hL1TkTrack10_DeltaPt4)
L1TkTrack10_DeltaPt.append(hL1TkTrack10_DeltaPt5)
L1TkTrack10_DeltaPt.append(hL1TkTrack10_DeltaPt6)
#L1TkTrack10_DeltaPt.append(hL1TkTrack10_DeltaPt7)
#L1TkTrack10_DeltaPt.append(hL1TkTrack10_DeltaPt8)
#L1TkTrack10_DeltaPt.append(hL1TkTrack10_DeltaPt9)


TkTrackDeltaEta = {"xMin" : None, "xMax" : 0.15, "yMin" : 0.01, "yMax" : None, "xLegMin": 0.65, "xLegMax": 0.94, "yLegMin": 0.84, "yLegMax": 0.94, 
                   "xCutLines": [], "xCutBoxes": [], "normaliseTo": None, "ratio": False, "logX": False, "logY": False, "binWidthX": 0.005, "saveName": "hL1TkTrack10_DeltaEta"}
hL1TkTrack10_DeltaEta0 = m_histos.TH1orTH2(folder, "hL1TkTrack10_DeltaEta_0", "L1 Tk #Delta#eta (same #tau_{mc})", "Entries / %0.3f", "Electron", **TkTrackDeltaEta)
hL1TkTrack10_DeltaEta1 = m_histos.TH1orTH2(folder, "hL1TkTrack10_DeltaEta_1", "L1 Tk #Delta#eta (same #tau_{mc})", "Entries / %0.3f", "Muon", **TkTrackDeltaEta)
hL1TkTrack10_DeltaEta2 = m_histos.TH1orTH2(folder, "hL1TkTrack10_DeltaEta_2", "L1 Tk #Delta#eta (same #tau_{mc})", "Entries / %0.3f", "1-prong (0 #pi^{0})", **TkTrackDeltaEta)
hL1TkTrack10_DeltaEta3 = m_histos.TH1orTH2(folder, "hL1TkTrack10_DeltaEta_3", "L1 Tk #Delta#eta (same #tau_{mc})", "Entries / %0.3f", "1-prong (1 #pi^{0})", **TkTrackDeltaEta)
hL1TkTrack10_DeltaEta4 = m_histos.TH1orTH2(folder, "hL1TkTrack10_DeltaEta_4", "L1 Tk #Delta#eta (same #tau_{mc})", "Entries / %0.3f", "1-prong (2 #pi^{0})", **TkTrackDeltaEta)
hL1TkTrack10_DeltaEta5 = m_histos.TH1orTH2(folder, "hL1TkTrack10_DeltaEta_5", "L1 Tk #Delta#eta (same #tau_{mc})", "Entries / %0.3f", "3-prong (0 #pi^{0})", **TkTrackDeltaEta)
hL1TkTrack10_DeltaEta6 = m_histos.TH1orTH2(folder, "hL1TkTrack10_DeltaEta_6", "L1 Tk #Delta#eta (same #tau_{mc})", "Entries / %0.3f", "3-prong (1 #pi^{0})", **TkTrackDeltaEta)
hL1TkTrack10_DeltaEta7 = m_histos.TH1orTH2(folder, "hL1TkTrack10_DeltaEta_7", "L1 Tk #Delta#eta (same #tau_{mc})", "Entries / %0.3f", "Other", **TkTrackDeltaEta)
hL1TkTrack10_DeltaEta8 = m_histos.TH1orTH2(folder, "hL1TkTrack10_DeltaEta_8", "L1 Tk #Delta#eta (same #tau_{mc})", "Entries / %0.3f", "Undefined", **TkTrackDeltaEta)
hL1TkTrack10_DeltaEta9 = m_histos.TH1orTH2(folder, "hL1TkTrack10_DeltaEta_9", "L1 Tk #Delta#eta (same #tau_{mc})", "Entries / %0.3f", "?", **TkTrackDeltaEta)
L1TkTrack10_DeltaEta  = []
L1TkTrack10_DeltaEta.append(hL1TkTrack10_DeltaEta0)
L1TkTrack10_DeltaEta.append(hL1TkTrack10_DeltaEta1)
L1TkTrack10_DeltaEta.append(hL1TkTrack10_DeltaEta2)
L1TkTrack10_DeltaEta.append(hL1TkTrack10_DeltaEta3)
L1TkTrack10_DeltaEta.append(hL1TkTrack10_DeltaEta4)
L1TkTrack10_DeltaEta.append(hL1TkTrack10_DeltaEta5)
L1TkTrack10_DeltaEta.append(hL1TkTrack10_DeltaEta6)
#L1TkTrack10_DeltaEta.append(hL1TkTrack10_DeltaEta7)
#L1TkTrack10_DeltaEta.append(hL1TkTrack10_DeltaEta8)
#L1TkTrack10_DeltaEta.append(hL1TkTrack10_DeltaEta9)


TkTrackDeltaPhi = {"xUnits": "(rads)", "xMin" : None, "xMax" : 0.15, "yMin" : None, "yMax" : None, "xLegMin": 0.65, "xLegMax": 0.94, "yLegMin": 0.84, "yLegMax": 0.94,
                   "xCutBoxes": [], "normaliseToOne" : False, "ratio": False, "logX": False, "logY": False, "binWidthX": 0.005, "saveName": "hL1TkTrack10_DeltaPhi"}
hL1TkTrack10_DeltaPhi0 = m_histos.TH1orTH2(folder, "hL1TkTrack10_DeltaPhi_0", "L1 Tk #Delta#phi (same #tau_{mc})", "Entries / %0.3f", "Electron", **TkTrackDeltaPhi)
hL1TkTrack10_DeltaPhi1 = m_histos.TH1orTH2(folder, "hL1TkTrack10_DeltaPhi_1", "L1 Tk #Delta#phi (same #tau_{mc})", "Entries / %0.3f", "Muon", **TkTrackDeltaPhi)
hL1TkTrack10_DeltaPhi2 = m_histos.TH1orTH2(folder, "hL1TkTrack10_DeltaPhi_2", "L1 Tk #Delta#phi (same #tau_{mc})", "Entries / %0.3f", "1-prong (0 #pi^{0})", **TkTrackDeltaPhi)
hL1TkTrack10_DeltaPhi3 = m_histos.TH1orTH2(folder, "hL1TkTrack10_DeltaPhi_3", "L1 Tk #Delta#phi (same #tau_{mc})", "Entries / %0.3f", "1-prong (1 #pi^{0})", **TkTrackDeltaPhi)
hL1TkTrack10_DeltaPhi4 = m_histos.TH1orTH2(folder, "hL1TkTrack10_DeltaPhi_4", "L1 Tk #Delta#phi (same #tau_{mc})", "Entries / %0.3f", "1-prong (2 #pi^{0})", **TkTrackDeltaPhi)
hL1TkTrack10_DeltaPhi5 = m_histos.TH1orTH2(folder, "hL1TkTrack10_DeltaPhi_5", "L1 Tk #Delta#phi (same #tau_{mc})", "Entries / %0.3f", "3-prong (0 #pi^{0})", **TkTrackDeltaPhi)
hL1TkTrack10_DeltaPhi6 = m_histos.TH1orTH2(folder, "hL1TkTrack10_DeltaPhi_6", "L1 Tk #Delta#phi (same #tau_{mc})", "Entries / %0.3f", "3-prong (1 #pi^{0})", **TkTrackDeltaPhi)
hL1TkTrack10_DeltaPhi7 = m_histos.TH1orTH2(folder, "hL1TkTrack10_DeltaPhi_7", "L1 Tk #Delta#phi (same #tau_{mc})", "Entries / %0.3f", "Other", **TkTrackDeltaPhi)
hL1TkTrack10_DeltaPhi8 = m_histos.TH1orTH2(folder, "hL1TkTrack10_DeltaPhi_8", "L1 Tk #Delta#phi (same #tau_{mc})", "Entries / %0.3f", "Undefined", **TkTrackDeltaPhi)
hL1TkTrack10_DeltaPhi9 = m_histos.TH1orTH2(folder, "hL1TkTrack10_DeltaPhi_9", "L1 Tk #Delta#phi (same #tau_{mc})", "Entries / %0.3f", "?", **TkTrackDeltaPhi)
L1TkTrack10_DeltaPhi  = []
L1TkTrack10_DeltaPhi.append(hL1TkTrack10_DeltaPhi0)
L1TkTrack10_DeltaPhi.append(hL1TkTrack10_DeltaPhi1)
L1TkTrack10_DeltaPhi.append(hL1TkTrack10_DeltaPhi2)
L1TkTrack10_DeltaPhi.append(hL1TkTrack10_DeltaPhi3)
L1TkTrack10_DeltaPhi.append(hL1TkTrack10_DeltaPhi4)
L1TkTrack10_DeltaPhi.append(hL1TkTrack10_DeltaPhi5)
L1TkTrack10_DeltaPhi.append(hL1TkTrack10_DeltaPhi6)
#L1TkTrack10_DeltaPhi.append(hL1TkTrack10_DeltaPhi7)
#L1TkTrack10_DeltaPhi.append(hL1TkTrack10_DeltaPhi8)
#L1TkTrack10_DeltaPhi.append(hL1TkTrack10_DeltaPhi9)


TkTrackDeltaVtxZ0 = {"xUnits": "cm", "xMin" : None, "xMax" : 1.5, "yMin" : None, "yMax" : None, "xLegMin": 0.65, "xLegMax": 0.94, "yLegMin": 0.84, "yLegMax": 0.94, 
                     "xCutLines": [], "xCutBoxes": [], "normaliseTo": None, "ratio": False, "logX": False, "logY": False, "binWidthX": None, "saveName": "hL1TkTrack10_DeltaVtxZ0"}
hL1TkTrack10_DeltaVtxZ0_0 = m_histos.TH1orTH2(folder, "hL1TkTrack10_DeltaVtxZ0_0", "L1 Tk #Deltaz_{vtx} (same #tau_{mc})", "Entries / %0.1f", "Electron", **TkTrackDeltaVtxZ0)
hL1TkTrack10_DeltaVtxZ0_1 = m_histos.TH1orTH2(folder, "hL1TkTrack10_DeltaVtxZ0_1", "L1 Tk #Deltaz_{vtx} (same #tau_{mc})", "Entries / %0.1f", "Muon", **TkTrackDeltaVtxZ0)
hL1TkTrack10_DeltaVtxZ0_2 = m_histos.TH1orTH2(folder, "hL1TkTrack10_DeltaVtxZ0_2", "L1 Tk #Deltaz_{vtx} (same #tau_{mc})", "Entries / %0.1f", "1-prong (0 #pi^{0})", **TkTrackDeltaVtxZ0)
hL1TkTrack10_DeltaVtxZ0_3 = m_histos.TH1orTH2(folder, "hL1TkTrack10_DeltaVtxZ0_3", "L1 Tk #Deltaz_{vtx} (same #tau_{mc})", "Entries / %0.1f", "1-prong (1 #pi^{0})", **TkTrackDeltaVtxZ0)
hL1TkTrack10_DeltaVtxZ0_4 = m_histos.TH1orTH2(folder, "hL1TkTrack10_DeltaVtxZ0_4", "L1 Tk #Deltaz_{vtx} (same #tau_{mc})", "Entries / %0.1f", "1-prong (2 #pi^{0})", **TkTrackDeltaVtxZ0)
hL1TkTrack10_DeltaVtxZ0_5 = m_histos.TH1orTH2(folder, "hL1TkTrack10_DeltaVtxZ0_5", "L1 Tk #Deltaz_{vtx} (same #tau_{mc})", "Entries / %0.1f", "3-prong (0 #pi^{0})", **TkTrackDeltaVtxZ0)
hL1TkTrack10_DeltaVtxZ0_6 = m_histos.TH1orTH2(folder, "hL1TkTrack10_DeltaVtxZ0_6", "L1 Tk #Deltaz_{vtx} (same #tau_{mc})", "Entries / %0.1f", "3-prong (1 #pi^{0})", **TkTrackDeltaVtxZ0)
hL1TkTrack10_DeltaVtxZ0_7 = m_histos.TH1orTH2(folder, "hL1TkTrack10_DeltaVtxZ0_7", "L1 Tk #Deltaz_{vtx} (same #tau_{mc})", "Entries / %0.1f", "Other", **TkTrackDeltaVtxZ0)
hL1TkTrack10_DeltaVtxZ0_8 = m_histos.TH1orTH2(folder, "hL1TkTrack10_DeltaVtxZ0_8", "L1 Tk #Deltaz_{vtx} (same #tau_{mc})", "Entries / %0.1f", "Undefined", **TkTrackDeltaVtxZ0)
hL1TkTrack10_DeltaVtxZ0_9 = m_histos.TH1orTH2(folder, "hL1TkTrack10_DeltaVtxZ0_9", "L1 Tk #Deltaz_{vtx} (same #tau_{mc})", "Entries / %0.1f", "?", **TkTrackDeltaVtxZ0)
L1TkTrack10_DeltaVtxZ0   = []
L1TkTrack10_DeltaVtxZ0.append(hL1TkTrack10_DeltaVtxZ0_0)
L1TkTrack10_DeltaVtxZ0.append(hL1TkTrack10_DeltaVtxZ0_1)
L1TkTrack10_DeltaVtxZ0.append(hL1TkTrack10_DeltaVtxZ0_2)
L1TkTrack10_DeltaVtxZ0.append(hL1TkTrack10_DeltaVtxZ0_3)
L1TkTrack10_DeltaVtxZ0.append(hL1TkTrack10_DeltaVtxZ0_4)
L1TkTrack10_DeltaVtxZ0.append(hL1TkTrack10_DeltaVtxZ0_5)
L1TkTrack10_DeltaVtxZ0.append(hL1TkTrack10_DeltaVtxZ0_6)
#L1TkTrack10_DeltaVtxZ0.append(hL1TkTrack10_DeltaVtxZ0_7)
#L1TkTrack10_DeltaVtxZ0.append(hL1TkTrack10_DeltaVtxZ0_8)
#L1TkTrack10_DeltaVtxZ0.append(hL1TkTrack10_DeltaVtxZ0_9)


EtaPhi = {"xUnits": "(rads)", "xMin" : None, "xMax" : None, "yUnits": "", "yMin" : -2.5, "yMax" : 2.5, "xLegMin": 0.65, "xLegMax": 0.94, "yLegMin": 0.84, "yLegMax": 0.94, 
          "zLabel": "Entries", "zMin" : 1E-1, "zMax" : 1E+3, "logX": False, "logY": False, "logZ": True, "binWidthX": None, "binWidthY": None, "drawOptions": "COLZ"}
PtEta  = {"xUnits": "", "xMin" : -2.5, "xMax" : 2.5, "yUnits": "(GeV)", "yMin" : None, "yMax" : None, "xLegMin": 0.65, "xLegMax": 0.94, "yLegMin": 0.84, "yLegMax": 0.94, "xCutLines": [], 
          "zLabel": "Entries", "zMin" : 1E0, "zMax" : 1E+4, "logX": False, "logY": False, "logZ": True, "binWidthX": None, "binWidthY": None, "drawOptions": "COLZ",}
hL1TkTrack_Pt_Eta    = m_histos.TH1orTH2(folder, "hL1TkTrack_Pt_Eta"  , "L1 Tk #eta / %0.2f", "L1 Tk p_{T} / %0.0f", "", **PtEta)
hL1TkTrack10_Pt_Eta  = m_histos.TH1orTH2(folder, "hL1TkTrack10_Pt_Eta", "L1 Tk #eta / %0.2f", "L1 Tk p_{T} / %0.0f", "p_{T}>10 GeV/c", **PtEta)
hL1TkTrack_Eta_Phi   = m_histos.TH1orTH2(folder, "hL1TkTrack_Eta_Phi" , "L1 Tk #phi / %0.2f", "L1 Tk #eta / %0.2f", "", **EtaPhi)
hL1TkTrack10_Eta_Phi = m_histos.TH1orTH2(folder, "hL1TkTrack10_Eta_Phi", "L1 Tk #phi / %0.2f", "L1 Tk #eta / %0.2f", "p_{T}>10 GeV/c", **EtaPhi)


### L1 Track Clusters (L1 Tracker Tracks are clustered together iff deltaR(L1Track_i, L1Track_j) < 0.1
###############################################################
#TKTNTracks = {"xMin" : 0.0, "xMax" : 10.0, "yMin" : None, "yMax" : None, "normaliseTo": "One", "saveName": "hTKT_NTracks", "styleType": "SB"}
TKTNTracks = {"xMin" : 0.0, "xMax" : 10.0, "yMin" : None, "yMax" : None, "normaliseTo": None, "saveName": "hTKT_NTracks", "styleType": "SB"}
hTKT_NTracks_0 = m_histos.TH1orTH2(folder, "hTKT_NTracks_0", "L1 Tks per #tau_{tk} candidate ", "Entries / %0.0f", "MB/UE", **TKTNTracks)
hTKT_NTracks_1 = m_histos.TH1orTH2(folder, "hTKT_NTracks_1", "L1 Tks per #tau_{tk} candidate" , "Entries / %0.0f", "w/L1 tk^{ldg} from #tau_{tk}", **TKTNTracks)
TKT_NTracks = []
TKT_NTracks.append(hTKT_NTracks_0)
TKT_NTracks.append(hTKT_NTracks_1)


TKTLeadPt = {"xUnits": "(GeV/c)", "xMin" : 0.0, "xMax" : 100.0, "yMin" : 1E-04, "yMax" : 1, "normaliseTo": "One", "binWidthX": 2, "logY": True, "saveName": "hTKT_LeadPt", "styleType": "SB"}
hTKT_LeadPt_0 = m_histos.TH1orTH2(folder, "hTKT_LeadPt_0", "L1 Tk p_{T}^{ldg}", "Entries / %0.0f", "MB/UE", **TKTLeadPt)
hTKT_LeadPt_1 = m_histos.TH1orTH2(folder, "hTKT_LeadPt_1", "L1 Tk p_{T}^{ldg}", "Entries / %0.0f", "w/L1 tk^{ldg} from #tau_{tk}", **TKTLeadPt)
TKT_LeadPt = []
TKT_LeadPt.append(hTKT_LeadPt_0)
TKT_LeadPt.append(hTKT_LeadPt_1)

TKT_Eta = {"xMin" : -2.6, "xMax" : 2.6, "yMin" : None, "yMax" : None, "xLegMin": 0.65, "xLegMax": 0.94, "yLegMin": 0.84, "yLegMax": 0.94, "styleType": "SB",
           "xCutLines": [], "xCutBoxes": [], "normaliseTo": "One", "ratio": False, "logX": False, "logY": False, "binWidthX": None, "saveName": "hTKT_LeadEta"}
hTKT_LeadEta_0 = m_histos.TH1orTH2(folder, "hTKT_LeadEta_0", "L1 Tk #eta^{ldg}", "Entries / %0.2f", "MB/UE", **TKT_Eta)
hTKT_LeadEta_1 = m_histos.TH1orTH2(folder, "hTKT_LeadEta_1", "L1 Tk #eta^{ldg}", "Entries / %0.2f", "w/L1 tk^{ldg} from #tau_{tk}", **TKT_Eta)
TKT_LeadEta    = []
TKT_LeadEta.append(hTKT_LeadEta_0)
TKT_LeadEta.append(hTKT_LeadEta_1)


TKTLeadVtxZ0 = {"xUnits": "(cm)", "xMin" : -30, "xMax" : +30, "yMin" : None, "yMax" : None, "xLegMin": 0.65, "xLegMax": 0.94, "yLegMin": 0.84, "yLegMax": 0.94, "styleType": "SB",
                "xCutLines": [0], "xCutBoxes": [], "normaliseTo": "One", "ratio": False, "logX": False, "logY": False, "binWidthX": None, "saveName": "hTKT_LeadVtxZ0"}
hTKT_LeadVtxZ0_0 = m_histos.TH1orTH2(folder, "hTKT_LeadVtxZ0_0", "L1 Tk^{ldg} z_{vtx}", "Entries / %0.1f", "MB/UE", **TKTLeadVtxZ0)
hTKT_LeadVtxZ0_1 = m_histos.TH1orTH2(folder, "hTKT_LeadVtxZ0_1", "L1 Tk^{ldg} z_{vtx}",  "Entries / %0.1f", "w/L1 tk^{ldg} from #tau_{tk}", **TKTLeadVtxZ0)
TKT_LeadVtxZ0 = []
TKT_LeadVtxZ0.append(hTKT_LeadVtxZ0_0)
TKT_LeadVtxZ0.append(hTKT_LeadVtxZ0_1)


TKTDeltaEta = {"xMin" : 0.0, "xMax" : 0.15, "yMin" : None, "yMax" : None, "xLegMin": 0.65, "xLegMax": 0.94, "yLegMin": 0.84, "yLegMax": 0.94, "styleType": "SB",
               "xCutLines": [], "xCutBoxes": [], "normaliseTo": "One", "ratio": False, "logX": False, "logY": False, "binWidthX": 0.005, "saveName": "hTKT_DeltaEta"}
hTKT_DeltaEta_0 = m_histos.TH1orTH2(folder, "hTKT_DeltaEta_0", "#Delta#eta(L1 Tk^{ldg}, L1 Tk)", "Entries / %0.3f", "MB/UE", **TKTDeltaEta)
hTKT_DeltaEta_1 = m_histos.TH1orTH2(folder, "hTKT_DeltaEta_1", "#Delta#eta(L1 Tk^{ldg}, L1 Tk)", "Entries / %0.3f", "w/L1 tk^{ldg} from #tau_{tk}", **TKTDeltaEta)
TKT_DeltaEta = []
TKT_DeltaEta.append(hTKT_DeltaEta_0)
TKT_DeltaEta.append(hTKT_DeltaEta_1)


TKTDeltaPhi = {"xUnits": "(rads)", "xMin" : 0.0, "xMax" : 0.15, "yMin" : None, "yMax" : None, "xLegMin": 0.65, "xLegMax": 0.94, "yLegMin": 0.84, "yLegMax": 0.94,
               "normaliseTo": "One", "ratio": False, "logX": False, "logY": False, "binWidthX": 0.005, "saveName": "hTKT_DeltaPhi", "styleType": "SB"}
hTKT_DeltaPhi_0 = m_histos.TH1orTH2(folder, "hTKT_DeltaPhi_0", "#Delta#phi(L1 Tk^{ldg}, L1 Tk)", "Entries / %0.3f", "MB/UE", **TKTDeltaPhi)
hTKT_DeltaPhi_1 = m_histos.TH1orTH2(folder, "hTKT_DeltaPhi_1", "#Delta#phi(L1 Tk^{ldg}, L1 Tk)", "Entries / %0.3f", "w/L1 tk^{ldg} from #tau_{tk}", **TKTDeltaPhi)
TKT_DeltaPhi = []
TKT_DeltaPhi.append(hTKT_DeltaPhi_0)
TKT_DeltaPhi.append(hTKT_DeltaPhi_1)


TKTDeltaVtxZ0 = {"xUnits": "(cm)", "xMin" : 0.0, "xMax" : 1.5, "yMin" : None, "yMax" : None, "styleType": "SB", "normaliseTo": "One", 
                 "xCutLines": [], "xCutBoxes": [], "normaliseTo": "One", "ratio": False, "logX": False, "logY": False, "binWidthX": None, "saveName": "hTKT_DeltaVtxZ0"}
hTKT_DeltaVtxZ0_0 = m_histos.TH1orTH2(folder, "hTKT_DeltaVtxZ0_0", "#Deltaz_{vtx}(L1 Tk^{ldg}, L1 Tk)", "Entries / %0.2f", "MB/UE", **TKTDeltaVtxZ0)
hTKT_DeltaVtxZ0_1 = m_histos.TH1orTH2(folder, "hTKT_DeltaVtxZ0_1", "#Deltaz_{vtx}(L1 Tk^{ldg}, L1 Tk)", "Entries / %0.2f", "w/L1 tk^{ldg} from #tau_{tk}", **TKTDeltaVtxZ0)
TKT_DeltaVtxZ0 = []
TKT_DeltaVtxZ0.append(hTKT_DeltaVtxZ0_0)
TKT_DeltaVtxZ0.append(hTKT_DeltaVtxZ0_1)


TKTPtSum = {"xUnits": "(GeV/c)", "xMin" : 0.0, "xMax" : 100.0, "yMin" : None, "yMax" : None, "normaliseTo": None, "ratio": False, "logX": False, "logY": False, "binWidthX": 2, 
            "normaliseTo": "One", "styleType": "SB", "saveName": "hTKT_PtSum"}
hTKT_PtSum_0 = m_histos.TH1orTH2(folder, "hTKT_PtSum_0", "L1 Tks #Sigmap_{T}", "Entries / %0.0f", "MB/UE", **TKTPtSum)
hTKT_PtSum_1 = m_histos.TH1orTH2(folder, "hTKT_PtSum_1", "L1 Tks #Sigmap_{T}", "Entries / %0.0f", "w/L1 tk^{ldg} from #tau_{tk}", **TKTPtSum)
TKT_PtSum    = []
TKT_PtSum.append(hTKT_PtSum_0)
TKT_PtSum.append(hTKT_PtSum_1)


#TKTN     = {"xMin" : 0.0, "xMax" : 8.0, "yMin" : None, "yMax" : None, "xCutLines": [], "xCutBoxes": [], "normaliseTo": "One", "ratio": False, "logX": False, "logY": False, 
#            "styleType": "SB", "saveName": "hTKT_N"}
TKTN     = {"xMin" : 0.0, "xMax" : 8.0, "yMin" : None, "yMax" : None, "xCutLines": [], "xCutBoxes": [], "normaliseTo": None, "ratio": False, "logX": False, "logY": False, 
            "styleType": "SB", "saveName": "hTKT_N"}
hTKT_N   = m_histos.TH1orTH2(folder, "hTKT_N", "L1 Tks per event", "Entries / %0.0f", "All", **TKTN)
hTKT_N_0 = m_histos.TH1orTH2(folder, "hTKT_N_0", "L1 Tks per event", "Entries / %0.0f", "MB/UE", **TKTN)
hTKT_N_1 = m_histos.TH1orTH2(folder, "hTKT_N_1", "L1 Tks per event", "Entries / %0.0f", "w/L1 tk^{ldg} from #tau_{tk}", **TKTN)
TKT_N    = []
#TKT_N.append(hTKT_N) #not needed since I have "inclusive" histo.
TKT_N.append(hTKT_N_0)
TKT_N.append(hTKT_N_1)


### L1 Tk Tau matching a L1 Calo Tau 
###############################################################
oTKT_DeltaPhi = {"xUnits": "(rads)", "xMin" : None, "xMax" : 0.15, "yMin" : None, "yMax" : None, "xLegMin": 0.65, "xLegMax": 0.94, "yLegMin": 0.84, "yLegMax": 0.94, "styleType": "SB",
                "xCutLines": [], "xCutBoxes": [], "normaliseTo": "One", "ratio": False, "logX": False, "logY": False, "binWidthX": None, "saveName": "hTKT_Lead_Tau_DeltaPhi"}
hTKT_Lead_Tau_DeltaPhi_0 = m_histos.TH1orTH2(folder, "hTKT_Lead_Tau_DeltaPhi_0", "#Delta#phi(L1 #tau_{tk, ldg}, L1 #tau_{calo})", "Entries / %0.3f", "MB/UE", **oTKT_DeltaPhi)
hTKT_Lead_Tau_DeltaPhi_1 = m_histos.TH1orTH2(folder, "hTKT_Lead_Tau_DeltaPhi_1", "#Delta#phi(Ldg L1 Tk, L1Calo)", "Entries / %0.3f", "w/L1 tk^{ldg} from #tau_{tk}", **oTKT_DeltaPhi)
TKT_Lead_Tau_DeltaPhi    = []
TKT_Lead_Tau_DeltaPhi.append(hTKT_Lead_Tau_DeltaPhi_0)
TKT_Lead_Tau_DeltaPhi.append(hTKT_Lead_Tau_DeltaPhi_1)

oTKT_DeltaEta = {"xUnits": "", "xMin" : None, "xMax" : 0.15, "yMin" : None, "yMax" : None, "xLegMin": 0.65, "xLegMax": 0.94, "yLegMin": 0.84, "yLegMax": 0.94, "styleType": "SB",
                "xCutLines": [], "xCutBoxes": [], "normaliseTo": "One", "ratio": False, "logX": False, "logY": False, "binWidthX": None, "saveName": "hTKT_Lead_Tau_DeltaEta"}
hTKT_Lead_Tau_DeltaEta_0 = m_histos.TH1orTH2(folder, "hTKT_Lead_Tau_DeltaEta_0", "#Delta#eta(L1 #tau_{tk, ldg}, L1 #tau_{calo})", "Entries / %0.3f", "MB/UE", **oTKT_DeltaEta)
hTKT_Lead_Tau_DeltaEta_1 = m_histos.TH1orTH2(folder, "hTKT_Lead_Tau_DeltaEta_1", "#Delta#eta(L1 #tau_{tk, ldg}, L1 #tau_{calo})", "Entries / %0.3f", "w/L1 tk^{ldg} from #tau_{tk}", **oTKT_DeltaEta)
TKT_Lead_Tau_DeltaEta    = []
TKT_Lead_Tau_DeltaEta.append(hTKT_Lead_Tau_DeltaEta_0)
TKT_Lead_Tau_DeltaEta.append(hTKT_Lead_Tau_DeltaEta_1)

TKT_DeltaR = {"xUnits": "", "xMin" : None, "xMax" : 0.2, "yMin" : None, "yMax" : None, "xLegMin": 0.65, "xLegMax": 0.94, "yLegMin": 0.84, "yLegMax": 0.94, "styleType": "SB",
              "xCutLines": [], "xCutBoxes": [], "normaliseTo": "One", "ratio": False, "logX": False, "logY": False, "binWidthX": None, "saveName": "hTKT_Lead_Tau_DeltaR"}
hTKT_Lead_Tau_DeltaR_0 = m_histos.TH1orTH2(folder, "hTKT_Lead_Tau_DeltaR_0", "#DeltaR(L1 #tau_{tk, ldg}, L1 #tau_{calo})", "Entries / %0.3f", "MB/UE", **TKT_DeltaR)
hTKT_Lead_Tau_DeltaR_1 = m_histos.TH1orTH2(folder, "hTKT_Lead_Tau_DeltaR_1", "#DeltaR(L1 #tau_{tk, ldg}, L1 #tau_{calo})", "Entries / %0.3f", "w/L1 tk^{ldg} from #tau_{tk}", **TKT_DeltaR)
TKT_Lead_Tau_DeltaR    = []
TKT_Lead_Tau_DeltaR.append(hTKT_Lead_Tau_DeltaR_0)
TKT_Lead_Tau_DeltaR.append(hTKT_Lead_Tau_DeltaR_1)


DeltaPtEt = {"xMin" : None, "xMax" : None, "yMin" : None, "yMax" : None, "xCutLines": [], "xCutBoxes": [], "normaliseTo": "One", "saveName": "hTKT_Lead_Tau_DeltaPtEt", "styleType": "SB"}
hTKT_Lead_Tau_DeltaPtEt_0 = m_histos.TH1orTH2(folder, "hTKT_Lead_Tau_DeltaPtEt_0", "L1 #tau_{tk} #Sigmap_{T} - L1 #tau_{calo} E_{T}", "Entries / %0.0f", "MB/UE", **DeltaPtEt)
hTKT_Lead_Tau_DeltaPtEt_1 = m_histos.TH1orTH2(folder, "hTKT_Lead_Tau_DeltaPtEt_1", "L1 #tau_{tk} #Sigmap_{T} - L1 #tau_{calo} E_{T}", "Entries / %0.0f", "w/L1 tk^{ldg} from #tau_{tk}", **DeltaPtEt)
TKT_Lead_Tau_DeltaPtEt    = []
TKT_Lead_Tau_DeltaPtEt.append(hTKT_Lead_Tau_DeltaPtEt_0)
TKT_Lead_Tau_DeltaPtEt.append(hTKT_Lead_Tau_DeltaPtEt_1)

DeltaPtEtOverEt = {"xMin" : -1.5, "xMax" : 5.5, "yMin" : None, "yMax" : None, "normaliseTo": "One", "ratio": False, "saveName": "hTKT_Lead_Tau_DeltaPtEt_OverEt", "styleType": "SB"}
hTKT_Lead_Tau_DeltaPtEt_OverEt_0 = m_histos.TH1orTH2(folder, "hTKT_Lead_Tau_DeltaPtEt_OverEt_0", "(L1 #tau_{tk} #Sigmap_{T} / L1 #tau_{calo} E_{T}) - 1", "Entries / %0.2f", "MB/UE", **DeltaPtEtOverEt)
hTKT_Lead_Tau_DeltaPtEt_OverEt_1 = m_histos.TH1orTH2(folder, "hTKT_Lead_Tau_DeltaPtEt_OverEt_1", "(L1 #tau_{tk} #Sigmap_{T} / L1 #tau_{calo} E_{T}) - 1", "Entries / %0.2f", "w/L1 tk^{ldg} from #tau_{tk}", **DeltaPtEtOverEt)
TKT_Lead_Tau_DeltaPtEt_OverEt    = []
TKT_Lead_Tau_DeltaPtEt_OverEt.append(hTKT_Lead_Tau_DeltaPtEt_OverEt_0)
TKT_Lead_Tau_DeltaPtEt_OverEt.append(hTKT_Lead_Tau_DeltaPtEt_OverEt_1)


### L1 Calo Tau Vs (Matched) L1 Tk Tau
CaloVsTk_DeltaR = {"xMin" : None, "xMax" : None, "yMin" : None, "yMax" : None, "xCutLines": [0.15]}
hTau_L1TkTrack10_DeltaR = m_histos.TH1orTH2(folder, "hTau_L1TkTrack10_DeltaR", "#DeltaR(L1 #tau_{calo}, L1 #tau_{tk})", "Entries / %0.2f", "L1 Tk p_{T} > 10 GeV/c", **CaloVsTk_DeltaR)


CaloVsTk_EtEta = {"xUnits": "", "xMin" : -2.5, "xMax" : 2.5, "yUnits": "(GeV)", "yMin" : None, "yMax" : None, "zUnits": "", "zLabel": "Entries", "zMin" : 1E-1, "zMax" : None, 
                  "logX": False, "logY": False, "logZ": True, "binWidthX": None, "binWidthY": None, "drawOptions": "COLZ"}
hTau_Et_Eta    = m_histos.TH1orTH2(folder, "hTau_Et_Eta", "L1 #tau_{calo} #eta / %0.2f", "L1 #tau_{calo} E_{T} / %0.0f", "",  **CaloVsTk_EtEta)


CaloVsTk_EtaPhi = {"xUnits": "(rads)", "xMin" : -3.2, "xMax" : 3.2, "yUnits": "", "yMin" : -2.5, "yMax" : 2.5, "zUnits": "", "zLabel": "Entries", "zMin" : 1E-1, "zMax" : None, "xLegMin": 0.65,
                   "logX": False, "logY": False, "logZ": True, "binWidthX": None, "binWidthY": None, "drawOptions": "COLZ"}
hTau_Eta_Phi    = m_histos.TH1orTH2(folder, "hTau_Eta_Phi", "L1 #tau_{calo} #phi / %0.2f", "L1 #tau_{calo} #eta / %0.2f", "",  **CaloVsTk_EtaPhi)


CaloVsTk_EtPt   = {"xUnits": "(GeV/c)", "xMin" : None, "xMax" : None, "yUnits": "(GeV)", "yMin" : None, "yMax" : None, "zUnits": "", "zLabel": "Entries", "zMin" : 1E-1, "zMax" : None, "xLegMin": 0.5,
                   "logX": False, "logY": False, "logZ": True, "binWidthX": None, "binWidthY": None, "drawOptions": "COLZ"}
hTau_Et_L1TkTrack10_Pt = m_histos.TH1orTH2(folder, "hTau_Et_L1TkTrack10_Pt", "L1 Tk p_{T} / %0.0f", "L1 #tau_{calo} E_{T} / %0.0f", "",  **CaloVsTk_EtPt)


CaloVsTk_EtaEta = {"xUnits": "", "xMin" : -2.5, "xMax" : 2.5, "yUnits": "", "yMin" : -2.5, "yMax" : 2.5, "zUnits": "", "zLabel": "Entries", "zMin" : 1E-1, "zMax" : None, "xLegMin": 0.5,
                   "logX": False, "logY": False, "logZ": True, "binWidthX": None, "binWidthY": None, "drawOptions": "COLZ"}
hTau_Eta_L1TkTrack10_Eta = m_histos.TH1orTH2(folder, "hTau_Eta_L1TkTrack10_Eta", "L1 Tk #eta / %0.2f", "L1 #tau_{calo} #eta / %0.2f", "",  **CaloVsTk_EtaEta)


CaloVsTk_PhiPhi = {"xUnits": "", "xMin" : -3.2, "xMax" : 3.2, "yUnits": "", "yMin" : -3.2, "yMax" : 3.2, "zUnits": "", "zLabel": "Entries", "zMin" : 1E-1, "zMax" : None, "xLegMin": 0.5,
                "logX": False, "logY": False, "logZ": True, "binWidthX": None, "binWidthY": None, "drawOptions": "COLZ"}
hTau_Phi_L1TkTrack10_Phi = m_histos.TH1orTH2(folder, "hTau_Phi_L1TkTrack10_Phi", "L1 Tk #phi / %0.2f", "L1 #tau_{calo} #phi / %0.2f", "",  **CaloVsTk_PhiPhi)


### L1 Tau Rates: Single-Tau
#RateCalo = {"xUnits": "(GeV)", "xMin" : 15.0, "xMax" : None, "yUnits": "(kHz)", "yMin": 10, "yMax" : 3.5E4, "xLegMin": 0.65, "xLegMax": 0.94, "yLegMin": 0.84, "yLegMax": 0.94, 
#            "yCutLines": [50], "yCutBoxes": [], "normaliseTo": "MB@40MHz", "ratio": False, "invRatio": True, "logX": False, "logY": True, "logYRatio": False, "gridX": True, "gridY": True, 
#            "yMinRatio": 1.0, "yMaxRatio": 15.0, "ratioLabel": "Reduction", "binWidthX": None}
RateCalo = {"xUnits": "(GeV)", "xMin" : 15.0, "xMax" : None, "yUnits": "(kHz)", "yMin": 10, "yMax" : 3.5E4, "xLegMin": 0.65, "xLegMax": 0.94, "yLegMin": 0.84, "yLegMax": 0.94, 
            "yCutLines": [50], "yCutBoxes": [], "normaliseTo": "MB@40MHz", "ratio": False, "invRatio": True, "logX": False, "logY": True, "logYRatio": False, "gridX": True, "gridY": True, 
            "yMinRatio": 1.0, "yMaxRatio": 10.0, "ratioLabel": "Reduction", "binWidthX": None}
hRateCalo                   = m_histos.TH1orTH2(folder, "hRateCalo", "L1 #tau_{calo} E_{T}", "Rate (kHz) / %0.0f", "Calo",  **RateCalo)
hRateCalo_Confirm           = m_histos.TH1orTH2(folder, "hRateCalo_Confirm", "L1 #tau_{calo} E_{T}", "Rate (kHz) / %0.0f", "+ Tk", **RateCalo)
hRateCalo_Confirm_1cmVtxZ0  = m_histos.TH1orTH2(folder, "hRateCalo_Confirm_1cmVtxZ0", "L1 #tau_{calo} E_{T}", "Rate (kHz) / %0.0f", "+ VtxIso (1cm)", **RateCalo)
hRateCalo_Confirm_2cmVtxZ0  = m_histos.TH1orTH2(folder, "hRateCalo_Confirm_2cmVtxZ0", "L1 #tau_{calo} E_{T}", "Rate (kHz) / %0.0f", "+ VtxIso (2cm)", **RateCalo)
L1SingleTauRates = []
L1SingleTauRates.append(hRateCalo)
L1SingleTauRates.append(hRateCalo_Confirm)
L1SingleTauRates.append(hRateCalo_Confirm_1cmVtxZ0)
L1SingleTauRates.append(hRateCalo_Confirm_2cmVtxZ0)

### L1 Tau Rates: Double-Tau ("zMin" : 5, "zMax" : 3E4)
RateCalo2D = {"xUnits": "(GeV)", "xMin" : 10.0, "xMax" : None, "yUnits": "(GeV)", "yMin" : 10.0, "yMax" : None, "zUnits": "(kHz)", "zLabel": "Rate", "zMin" : 1, "zMax" : 3E4, "xLegMin": 0.17, 
              "xLegMax": 0.5, "zCutLines": [50.0], "zCutLinesErrors": True, "logX": False, "logY": False, "logZ": True, "normaliseTo": "MB@40MHz", "drawOptions": "COLZ"}
hRateCalo2D          = m_histos.TH1orTH2(folder, "hRateCalo2D", "Ldg L1 #tau_{calo} E_{T} / %0.0f", "SubLdg L1 #tau_{calo} E_{T} / %0.0f", "Calo",  **RateCalo2D)
hRateCalo2D_Confirm1 = m_histos.TH1orTH2(folder, "hRateCalo2D_Confirm1", "Ldg L1 #tau_{calo} E_{T} / %0.0f", "SubLdg L1 #tau_{calo} E_{T} / %0.0f", "+ 1Tk",  **RateCalo2D)
hRateCalo2D_Confirm1_1cmVtxZ01 = m_histos.TH1orTH2(folder, "hRateCalo2D_Confirm1_1cmVtxZ01", "Ldg L1 #tau_{calo} E_{T} / %0.0f", "SubLdg L1 #tau_{calo} E_{T} / %0.0f", "+ 1Tk + 1VtxIso (1cm)",  **RateCalo2D)
hRateCalo2D_Confirm1_2cmVtxZ01 = m_histos.TH1orTH2(folder, "hRateCalo2D_Confirm1_2cmVtxZ01", "Ldg L1 #tau_{calo} E_{T} / %0.0f", "SubLdg L1 #tau_{calo} E_{T} / %0.0f", "+ 1Tk + 1VtxIso (2cm)",  **RateCalo2D)

hRateCalo2D_Confirm2 = m_histos.TH1orTH2(folder, "hRateCalo2D_Confirm2", "Ldg L1 #tau_{calo} E_{T} / %0.0f", "SubLdg L1 #tau_{calo} E_{T} / %0.0f", "+ 2Tk",  **RateCalo2D)
hRateCalo2D_Confirm2_1cmVtxZ01 = m_histos.TH1orTH2(folder, "hRateCalo2D_Confirm2_1cmVtxZ01", "Ldg L1 #tau_{calo} E_{T} / %0.0f", "SubLdg L1 #tau_{calo} E_{T} / %0.0f", "+ 2Tk + 1VtxIso (1cm)",  **RateCalo2D)
hRateCalo2D_Confirm2_2cmVtxZ01 = m_histos.TH1orTH2(folder, "hRateCalo2D_Confirm2_2cmVtxZ01", "Ldg L1 #tau_{calo} E_{T} / %0.0f", "SubLdg L1 #tau_{calo} E_{T} / %0.0f", "+ 2Tk + 1VtxIso (2cm)",  **RateCalo2D)
hRateCalo2D_Confirm2_1cmVtxZ02 = m_histos.TH1orTH2(folder, "hRateCalo2D_Confirm2_1cmVtxZ02", "Ldg L1 #tau_{calo} E_{T} / %0.0f", "SubLdg L1 #tau_{calo} E_{T} / %0.0f", "+ 2Tk + 2VtxIso (1cm)",  **RateCalo2D)
hRateCalo2D_Confirm2_2cmVtxZ02 = m_histos.TH1orTH2(folder, "hRateCalo2D_Confirm2_2cmVtxZ02", "Ldg L1 #tau_{calo} E_{T} / %0.0f", "SubLdg L1 #tau_{calo} E_{T} / %0.0f", "+ 2Tk + 2VtxIso (1cm)",  **RateCalo2D)

hRateCalo2D_Confirm2_SameVtxZ  = m_histos.TH1orTH2(folder, "hRateCalo2D_Confirm2_SameVtxZ", "Ldg L1 #tau_{calo} E_{T} / %0.0f", "SubLdg L1 #tau_{calo} E_{T} / %0.0f", "+ 2Tk + SameVtx (1cm)",  **RateCalo2D)
hRateCalo2D_Confirm2_1cmVtxZ01_SameVtxZ = m_histos.TH1orTH2(folder, "hRateCalo2D_Confirm2_1cmVtxZ01_SameVtxZ", "Ldg L1 #tau_{calo} E_{T} / %0.0f", "SubLdg L1 #tau_{calo} E_{T} / %0.0f", "+ 2Tk + 1VtxIso (1cm) + SameVtx (1cm)",  **RateCalo2D)
hRateCalo2D_Confirm2_2cmVtxZ01_SameVtxZ = m_histos.TH1orTH2(folder, "hRateCalo2D_Confirm2_2cmVtxZ01_SameVtxZ", "Ldg L1 #tau_{calo} E_{T} / %0.0f", "SubLdg L1 #tau_{calo} E_{T} / %0.0f", "+ 2Tk + 1VtxIso (2cm) + SameVtx (1cm)",  **RateCalo2D)
hRateCalo2D_Confirm2_1cmVtxZ02_SameVtxZ = m_histos.TH1orTH2(folder, "hRateCalo2D_Confirm2_1cmVtxZ02_SameVtxZ", "Ldg L1 #tau_{calo} E_{T} / %0.0f", "SubLdg L1 #tau_{calo} E_{T} / %0.0f", "+ 2Tk + 2VtxIso (1cm) + SameVtx (1cm) ",  **RateCalo2D)
hRateCalo2D_Confirm2_2cmVtxZ02_SameVtxZ = m_histos.TH1orTH2(folder, "hRateCalo2D_Confirm2_2cmVtxZ02_SameVtxZ", "Ldg L1 #tau_{calo} E_{T} / %0.0f", "SubLdg L1 #tau_{calo} E_{T} / %0.0f", "+ 2Tk + 2VtxIso (2cm) + SameVtx (1cm) ",  **RateCalo2D)


### L1 Single-Tau Efficiencies: 
Et = {"xUnits": "(GeV)", "xMin" : 0.0, "xMax" : 100.0, "yMin" : 1, "yMax" : 1E6, "xLegMin": 0.20, "xLegMax": 0.49, "yLegMin": 0.84, "yLegMax": 0.94, "xCutLines": [], 
      "yMinRatio": None, "yMaxRatio": 1.05, "ratio": True, "invRatio": False, "ratioLabel": "Efficiency", "logX": False, "logY": True, "logXRatio":  False, "logYRatio": False, "binWidthX": 5}
hMCT_VisEt = m_histos.TH1orTH2(folder, "hMCT_VisEt", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "MC Tau", **Et)
hMCT_VisEt_Calo        = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "Calo", **Et)
hMCT_VisEt_Calo_EtGr5  = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_EtGr5" , "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "Calo, E_{T} > 5 GeV", **Et)
hMCT_VisEt_Calo_EtGr10 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_EtGr10", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "Calo, E_{T} > 10 GeV", **Et)
hMCT_VisEt_Calo_EtGr15 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_EtGr15", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "Calo, E_{T} > 15 GeV", **Et)
hMCT_VisEt_Calo_EtGr20 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_EtGr20", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "Calo, E_{T} > 20 GeV", **Et)
hMCT_VisEt_Calo_EtGr25 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_EtGr25", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "Calo, E_{T} > 25 GeV", **Et)
hMCT_VisEt_Calo_EtGr30 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_EtGr30", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "Calo, E_{T} > 30 GeV", **Et)
hMCT_VisEt_Calo_EtGr35 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_EtGr35", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "Calo, E_{T} > 35 GeV", **Et)
hMCT_VisEt_Calo_EtGr40 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_EtGr40", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "Calo, E_{T} > 40 GeV", **Et)
hMCT_VisEt_Calo_EtGr45 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_EtGr45", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "Calo, E_{T} > 45 GeV", **Et)
hMCT_VisEt_Calo_EtGr50 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_EtGr50", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "Calo, E_{T} > 50 GeV", **Et)
hMCT_VisEt_Calo_EtGr55 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_EtGr55", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "Calo, E_{T} > 55 GeV", **Et)
hMCT_VisEt_Calo_EtGr60 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_EtGr60", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "Calo, E_{T} > 60 GeV", **Et)
hMCT_VisEt_Calo_EtGr65 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_EtGr65", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "Calo, E_{T} > 65 GeV", **Et)
hMCT_VisEt_Calo_EtGr70 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_EtGr70", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "Calo, E_{T} > 70 GeV", **Et)
hMCT_VisEt_Calo_EtGr75 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_EtGr75", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "Calo, E_{T} > 75 GeV", **Et)
hMCT_VisEt_Calo_EtGr80 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_EtGr80", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "Calo, E_{T} > 80 GeV", **Et)
hMCT_VisEt_Calo_EtGr85 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_EtGr85", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "Calo, E_{T} > 85 GeV", **Et)
hMCT_VisEt_Calo_EtGr90 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_EtGr90", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "Calo, E_{T} > 90 GeV", **Et)

hMCT_VisEt_Calo_Confirm        = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_Confirm", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+ Tk", **Et)
hMCT_VisEt_Calo_Confirm_EtGr5  = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_Confirm_EtGr5" , "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+Tk, E_{T} > 5 GeV", **Et)
hMCT_VisEt_Calo_Confirm_EtGr10 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_Confirm_EtGr10", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+Tk, E_{T} > 10 GeV", **Et)
hMCT_VisEt_Calo_Confirm_EtGr15 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_Confirm_EtGr15", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+Tk, E_{T} > 15 GeV", **Et)
hMCT_VisEt_Calo_Confirm_EtGr20 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_Confirm_EtGr20", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+Tk, E_{T} > 20 GeV", **Et)
hMCT_VisEt_Calo_Confirm_EtGr25 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_Confirm_EtGr25", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+Tk, E_{T} > 25 GeV", **Et)
hMCT_VisEt_Calo_Confirm_EtGr30 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_Confirm_EtGr30", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+Tk, E_{T} > 30 GeV", **Et)
hMCT_VisEt_Calo_Confirm_EtGr35 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_Confirm_EtGr35", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+Tk, E_{T} > 35 GeV", **Et)
hMCT_VisEt_Calo_Confirm_EtGr40 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_Confirm_EtGr40", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+Tk, E_{T} > 40 GeV", **Et)
hMCT_VisEt_Calo_Confirm_EtGr45 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_Confirm_EtGr45", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+Tk, E_{T} > 45 GeV", **Et)
hMCT_VisEt_Calo_Confirm_EtGr50 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_Confirm_EtGr50", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+Tk, E_{T} > 50 GeV", **Et)
hMCT_VisEt_Calo_Confirm_EtGr55 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_Confirm_EtGr55", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+Tk, E_{T} > 55 GeV", **Et)
hMCT_VisEt_Calo_Confirm_EtGr60 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_Confirm_EtGr60", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+Tk, E_{T} > 60 GeV", **Et)
hMCT_VisEt_Calo_Confirm_EtGr65 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_Confirm_EtGr65", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+Tk, E_{T} > 65 GeV", **Et)
hMCT_VisEt_Calo_Confirm_EtGr70 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_Confirm_EtGr70", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+Tk, E_{T} > 70 GeV", **Et)
hMCT_VisEt_Calo_Confirm_EtGr75 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_Confirm_EtGr75", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+Tk, E_{T} > 75 GeV", **Et)
hMCT_VisEt_Calo_Confirm_EtGr80 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_Confirm_EtGr80", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+Tk, E_{T} > 80 GeV", **Et)
hMCT_VisEt_Calo_Confirm_EtGr85 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_Confirm_EtGr85", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+Tk, E_{T} > 85 GeV", **Et)
hMCT_VisEt_Calo_Confirm_EtGr90 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_Confirm_EtGr90", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+Tk, E_{T} > 90 GeV", **Et)

hMCT_VisEt_Calo_Confirm_1cmVtxZ0        = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_Confirm_1cmVtxZ0", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+VtxIso (1cm), E_{T} > 5 GeV", **Et)
hMCT_VisEt_Calo_Confirm_1cmVtxZ0_EtGr5  = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_Confirm_1cmVtxZ0_EtGr5" , "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+VtxIso (1cm), E_{T} > 5 GeV", **Et)
hMCT_VisEt_Calo_Confirm_1cmVtxZ0_EtGr10 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_Confirm_1cmVtxZ0_EtGr10", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+VtxIso (1cm), E_{T} > 10 GeV", **Et)
hMCT_VisEt_Calo_Confirm_1cmVtxZ0_EtGr15 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_Confirm_1cmVtxZ0_EtGr15", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+VtxIso (1cm), E_{T} > 15 GeV", **Et)
hMCT_VisEt_Calo_Confirm_1cmVtxZ0_EtGr20 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_Confirm_1cmVtxZ0_EtGr20", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+VtxIso (1cm), E_{T} > 20 GeV", **Et)
hMCT_VisEt_Calo_Confirm_1cmVtxZ0_EtGr25 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_Confirm_1cmVtxZ0_EtGr25", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+VtxIso (1cm), E_{T} > 25 GeV", **Et)
hMCT_VisEt_Calo_Confirm_1cmVtxZ0_EtGr30 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_Confirm_1cmVtxZ0_EtGr30", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+VtxIso (1cm), E_{T} > 30 GeV", **Et)
hMCT_VisEt_Calo_Confirm_1cmVtxZ0_EtGr35 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_Confirm_1cmVtxZ0_EtGr35", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+VtxIso (1cm), E_{T} > 35 GeV", **Et)
hMCT_VisEt_Calo_Confirm_1cmVtxZ0_EtGr40 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_Confirm_1cmVtxZ0_EtGr40", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+VtxIso (1cm), E_{T} > 40 GeV", **Et)
hMCT_VisEt_Calo_Confirm_1cmVtxZ0_EtGr45 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_Confirm_1cmVtxZ0_EtGr45", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+VtxIso (1cm), E_{T} > 45 GeV", **Et)
hMCT_VisEt_Calo_Confirm_1cmVtxZ0_EtGr50 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_Confirm_1cmVtxZ0_EtGr50", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+VtxIso (1cm), E_{T} > 50 GeV", **Et)
hMCT_VisEt_Calo_Confirm_1cmVtxZ0_EtGr55 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_Confirm_1cmVtxZ0_EtGr55", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+VtxIso (1cm), E_{T} > 55 GeV", **Et)
hMCT_VisEt_Calo_Confirm_1cmVtxZ0_EtGr60 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_Confirm_1cmVtxZ0_EtGr60", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+VtxIso (1cm), E_{T} > 60 GeV", **Et)
hMCT_VisEt_Calo_Confirm_1cmVtxZ0_EtGr65 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_Confirm_1cmVtxZ0_EtGr65", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+VtxIso (1cm), E_{T} > 65 GeV", **Et)
hMCT_VisEt_Calo_Confirm_1cmVtxZ0_EtGr70 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_Confirm_1cmVtxZ0_EtGr70", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+VtxIso (1cm), E_{T} > 70 GeV", **Et)
hMCT_VisEt_Calo_Confirm_1cmVtxZ0_EtGr75 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_Confirm_1cmVtxZ0_EtGr75", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+VtxIso (1cm), E_{T} > 75 GeV", **Et)
hMCT_VisEt_Calo_Confirm_1cmVtxZ0_EtGr80 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_Confirm_1cmVtxZ0_EtGr80", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+VtxIso (1cm), E_{T} > 80 GeV", **Et)
hMCT_VisEt_Calo_Confirm_1cmVtxZ0_EtGr85 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_Confirm_1cmVtxZ0_EtGr85", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+VtxIso (1cm), E_{T} > 85 GeV", **Et)
hMCT_VisEt_Calo_Confirm_1cmVtxZ0_EtGr90 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_Confirm_1cmVtxZ0_EtGr90", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+VtxIso (1cm), E_{T} > 90 GeV", **Et)

hMCT_VisEt_Calo_Confirm_2cmVtxZ0        = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_Confirm_2cmVtxZ0", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+VtxIso (2cm), E_{T} > 5 GeV", **Et)
hMCT_VisEt_Calo_Confirm_2cmVtxZ0_EtGr5  = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_Confirm_2cmVtxZ0_EtGr5" , "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+VtxIso (2cm), E_{T} > 5 GeV", **Et)
hMCT_VisEt_Calo_Confirm_2cmVtxZ0_EtGr10 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_Confirm_2cmVtxZ0_EtGr10", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+VtxIso (2cm), E_{T} > 10 GeV", **Et)
hMCT_VisEt_Calo_Confirm_2cmVtxZ0_EtGr15 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_Confirm_2cmVtxZ0_EtGr15", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+VtxIso (2cm), E_{T} > 15 GeV", **Et)
hMCT_VisEt_Calo_Confirm_2cmVtxZ0_EtGr20 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_Confirm_2cmVtxZ0_EtGr20", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+VtxIso (2cm), E_{T} > 20 GeV", **Et)
hMCT_VisEt_Calo_Confirm_2cmVtxZ0_EtGr25 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_Confirm_2cmVtxZ0_EtGr25", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+VtxIso (2cm), E_{T} > 25 GeV", **Et)
hMCT_VisEt_Calo_Confirm_2cmVtxZ0_EtGr30 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_Confirm_2cmVtxZ0_EtGr30", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+VtxIso (2cm), E_{T} > 30 GeV", **Et)
hMCT_VisEt_Calo_Confirm_2cmVtxZ0_EtGr35 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_Confirm_2cmVtxZ0_EtGr35", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+VtxIso (2cm), E_{T} > 35 GeV", **Et)
hMCT_VisEt_Calo_Confirm_2cmVtxZ0_EtGr40 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_Confirm_2cmVtxZ0_EtGr40", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+VtxIso (2cm), E_{T} > 40 GeV", **Et)
hMCT_VisEt_Calo_Confirm_2cmVtxZ0_EtGr45 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_Confirm_2cmVtxZ0_EtGr45", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+VtxIso (2cm), E_{T} > 45 GeV", **Et)
hMCT_VisEt_Calo_Confirm_2cmVtxZ0_EtGr50 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_Confirm_2cmVtxZ0_EtGr50", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+VtxIso (2cm), E_{T} > 50 GeV", **Et)
hMCT_VisEt_Calo_Confirm_2cmVtxZ0_EtGr55 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_Confirm_2cmVtxZ0_EtGr55", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+VtxIso (2cm), E_{T} > 55 GeV", **Et)
hMCT_VisEt_Calo_Confirm_2cmVtxZ0_EtGr60 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_Confirm_2cmVtxZ0_EtGr60", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+VtxIso (2cm), E_{T} > 60 GeV", **Et)
hMCT_VisEt_Calo_Confirm_2cmVtxZ0_EtGr65 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_Confirm_2cmVtxZ0_EtGr65", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+VtxIso (2cm), E_{T} > 65 GeV", **Et)
hMCT_VisEt_Calo_Confirm_2cmVtxZ0_EtGr70 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_Confirm_2cmVtxZ0_EtGr70", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+VtxIso (2cm), E_{T} > 70 GeV", **Et)
hMCT_VisEt_Calo_Confirm_2cmVtxZ0_EtGr75 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_Confirm_2cmVtxZ0_EtGr75", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+VtxIso (2cm), E_{T} > 75 GeV", **Et)
hMCT_VisEt_Calo_Confirm_2cmVtxZ0_EtGr80 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_Confirm_2cmVtxZ0_EtGr80", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+VtxIso (2cm), E_{T} > 80 GeV", **Et)
hMCT_VisEt_Calo_Confirm_2cmVtxZ0_EtGr85 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_Confirm_2cmVtxZ0_EtGr85", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+VtxIso (2cm), E_{T} > 85 GeV", **Et)
hMCT_VisEt_Calo_Confirm_2cmVtxZ0_EtGr90 = m_histos.TH1orTH2(folder, "hMCT_VisEt_Calo_Confirm_2cmVtxZ0_EtGr90", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+VtxIso (2cm), E_{T} > 90 GeV", **Et)
L1SingleTauEff = []
L1SingleTauEff.append(hMCT_VisEt)
L1SingleTauEff.append(hMCT_VisEt_Calo)
L1SingleTauEff.append(hMCT_VisEt_Calo_Confirm)
L1SingleTauEff.append(hMCT_VisEt_Calo_Confirm_1cmVtxZ0)
L1SingleTauEff.append(hMCT_VisEt_Calo_Confirm_2cmVtxZ0)
#
#L1SingleTauEff.append(hMCT_VisEt_Calo_EtGr5)
#L1SingleTauEff.append(hMCT_VisEt_Calo_EtGr10) 
#L1SingleTauEff.append(hMCT_VisEt_Calo_EtGr15)
#L1SingleTauEff.append(hMCT_VisEt_Calo_EtGr20)
#L1SingleTauEff.append(hMCT_VisEt_Calo_EtGr25)
#L1SingleTauEff.append(hMCT_VisEt_Calo_EtGr30)
#L1SingleTauEff.append(hMCT_VisEt_Calo_EtGr35)
#L1SingleTauEff.append(hMCT_VisEt_Calo_EtGr40)
#L1SingleTauEff.append(hMCT_VisEt_Calo_EtGr45)
#L1SingleTauEff.append(hMCT_VisEt_Calo_EtGr50)
#L1SingleTauEff.append(hMCT_VisEt_Calo_EtGr55)
#L1SingleTauEff.append(hMCT_VisEt_Calo_EtGr60)
#L1SingleTauEff.append(hMCT_VisEt_Calo_EtGr65)
#L1SingleTauEff.append(hMCT_VisEt_Calo_EtGr70)
#L1SingleTauEff.append(hMCT_VisEt_Calo_EtGr75)
#L1SingleTauEff.append(hMCT_VisEt_Calo_EtGr80)
#L1SingleTauEff.append(hMCT_VisEt_Calo_EtGr85)
#L1SingleTauEff.append(hMCT_VisEt_Calo_EtGr90)
##
#L1SingleTauEff.append(hMCT_VisEt_Calo_Confirm_EtGr5)
#L1SingleTauEff.append(hMCT_VisEt_Calo_Confirm_EtGr10)
#L1SingleTauEff.append(hMCT_VisEt_Calo_Confirm_EtGr15)
#L1SingleTauEff.append(hMCT_VisEt_Calo_Confirm_EtGr20)
#L1SingleTauEff.append(hMCT_VisEt_Calo_Confirm_EtGr25)
#L1SingleTauEff.append(hMCT_VisEt_Calo_Confirm_EtGr30)
#L1SingleTauEff.append(hMCT_VisEt_Calo_Confirm_EtGr35)
#L1SingleTauEff.append(hMCT_VisEt_Calo_Confirm_EtGr40)
#L1SingleTauEff.append(hMCT_VisEt_Calo_Confirm_EtGr45)
#L1SingleTauEff.append(hMCT_VisEt_Calo_Confirm_EtGr50)
#L1SingleTauEff.append(hMCT_VisEt_Calo_Confirm_EtGr55)
#L1SingleTauEff.append(hMCT_VisEt_Calo_Confirm_EtGr60)
#L1SingleTauEff.append(hMCT_VisEt_Calo_Confirm_EtGr65)
#L1SingleTauEff.append(hMCT_VisEt_Calo_Confirm_EtGr70)
#L1SingleTauEff.append(hMCT_VisEt_Calo_Confirm_EtGr75)
#L1SingleTauEff.append(hMCT_VisEt_Calo_Confirm_EtGr80)
#L1SingleTauEff.append(hMCT_VisEt_Calo_Confirm_EtGr85)
#L1SingleTauEff.append(hMCT_VisEt_Calo_Confirm_EtGr90)
##
#L1SingleTauEff.append(hMCT_VisEt_Calo_Confirm_1cmVtxZ0_EtGr5)
#L1SingleTauEff.append(hMCT_VisEt_Calo_Confirm_1cmVtxZ0_EtGr10) 
#L1SingleTauEff.append(hMCT_VisEt_Calo_Confirm_1cmVtxZ0_EtGr15) 
#L1SingleTauEff.append(hMCT_VisEt_Calo_Confirm_1cmVtxZ0_EtGr20) 
#L1SingleTauEff.append(hMCT_VisEt_Calo_Confirm_1cmVtxZ0_EtGr25) 
#L1SingleTauEff.append(hMCT_VisEt_Calo_Confirm_1cmVtxZ0_EtGr30) 
#L1SingleTauEff.append(hMCT_VisEt_Calo_Confirm_1cmVtxZ0_EtGr35) 
#L1SingleTauEff.append(hMCT_VisEt_Calo_Confirm_1cmVtxZ0_EtGr40) 
#L1SingleTauEff.append(hMCT_VisEt_Calo_Confirm_1cmVtxZ0_EtGr45) 
#L1SingleTauEff.append(hMCT_VisEt_Calo_Confirm_1cmVtxZ0_EtGr50) 
#L1SingleTauEff.append(hMCT_VisEt_Calo_Confirm_1cmVtxZ0_EtGr55) 
#L1SingleTauEff.append(hMCT_VisEt_Calo_Confirm_1cmVtxZ0_EtGr60) 
#L1SingleTauEff.append(hMCT_VisEt_Calo_Confirm_1cmVtxZ0_EtGr65) 
#L1SingleTauEff.append(hMCT_VisEt_Calo_Confirm_1cmVtxZ0_EtGr70) 
#L1SingleTauEff.append(hMCT_VisEt_Calo_Confirm_1cmVtxZ0_EtGr75) 
#L1SingleTauEff.append(hMCT_VisEt_Calo_Confirm_1cmVtxZ0_EtGr80) 
#L1SingleTauEff.append(hMCT_VisEt_Calo_Confirm_1cmVtxZ0_EtGr85) 
#L1SingleTauEff.append(hMCT_VisEt_Calo_Confirm_1cmVtxZ0_EtGr90) 
##
#L1SingleTauEff.append(hMCT_VisEt_Calo_Confirm_2cmVtxZ0_EtGr5)
#L1SingleTauEff.append(hMCT_VisEt_Calo_Confirm_2cmVtxZ0_EtGr10)
#L1SingleTauEff.append(hMCT_VisEt_Calo_Confirm_2cmVtxZ0_EtGr15)
#L1SingleTauEff.append(hMCT_VisEt_Calo_Confirm_2cmVtxZ0_EtGr20)
#L1SingleTauEff.append(hMCT_VisEt_Calo_Confirm_2cmVtxZ0_EtGr25)
#L1SingleTauEff.append(hMCT_VisEt_Calo_Confirm_2cmVtxZ0_EtGr30)
#L1SingleTauEff.append(hMCT_VisEt_Calo_Confirm_2cmVtxZ0_EtGr35)
#L1SingleTauEff.append(hMCT_VisEt_Calo_Confirm_2cmVtxZ0_EtGr40)
#L1SingleTauEff.append(hMCT_VisEt_Calo_Confirm_2cmVtxZ0_EtGr45)
#L1SingleTauEff.append(hMCT_VisEt_Calo_Confirm_2cmVtxZ0_EtGr50)
#L1SingleTauEff.append(hMCT_VisEt_Calo_Confirm_2cmVtxZ0_EtGr55)
#L1SingleTauEff.append(hMCT_VisEt_Calo_Confirm_2cmVtxZ0_EtGr60)
#L1SingleTauEff.append(hMCT_VisEt_Calo_Confirm_2cmVtxZ0_EtGr65)
#L1SingleTauEff.append(hMCT_VisEt_Calo_Confirm_2cmVtxZ0_EtGr70)
#L1SingleTauEff.append(hMCT_VisEt_Calo_Confirm_2cmVtxZ0_EtGr75)
#L1SingleTauEff.append(hMCT_VisEt_Calo_Confirm_2cmVtxZ0_EtGr80)
#L1SingleTauEff.append(hMCT_VisEt_Calo_Confirm_2cmVtxZ0_EtGr85)
#L1SingleTauEff.append(hMCT_VisEt_Calo_Confirm_2cmVtxZ0_EtGr90)

### 14 March 2014: Include L1TkTracks of L1TkTau in Isolation
L1SingleTauEff_InclL1TkTausInIso = []
L1SingleTauEff_InclL1TkTausInIso.append(hMCT_VisEt)
L1SingleTauEff_InclL1TkTausInIso.append(hMCT_VisEt_Calo_EtGr90)
L1SingleTauEff_InclL1TkTausInIso.append(hMCT_VisEt_Calo_Confirm_EtGr85)
L1SingleTauEff_InclL1TkTausInIso.append(hMCT_VisEt_Calo_Confirm_1cmVtxZ0_EtGr55)
L1SingleTauEff_InclL1TkTausInIso.append(hMCT_VisEt_Calo_Confirm_2cmVtxZ0_EtGr50)

L1SingleTauEff_Excl1TkTausInIso = []
L1SingleTauEff_Excl1TkTausInIso.append(hMCT_VisEt)
L1SingleTauEff_Excl1TkTausInIso.append(hMCT_VisEt_Calo_EtGr90)
L1SingleTauEff_Excl1TkTausInIso.append(hMCT_VisEt_Calo_Confirm_EtGr85)
L1SingleTauEff_Excl1TkTausInIso.append(hMCT_VisEt_Calo_Confirm_1cmVtxZ0_EtGr65)
L1SingleTauEff_Excl1TkTausInIso.append(hMCT_VisEt_Calo_Confirm_2cmVtxZ0_EtGr60)



### Distance between MCTau and L1CaloTau
hMCT_Tau_DeltaEta = m_histos.TH1orTH2(folder, "hMCT_Tau_DeltaEta", "#Delta#eta(#tau_{mc} , L1 #tau_{calo})", "Entries / %0.3f", "MCT_Tau_#Delta#eta", **DeltaEta)
hMCT_Tau_DeltaPhi = m_histos.TH1orTH2(folder, "hMCT_Tau_DeltaPhi", "#Delta#phi(#tau_{mc} , L1 #tau_{calo})", "Entries / %0.3f", "MCT_Tau_#Delta#phi", **DeltaPhi)
hMCT_Tau_DeltaR   = m_histos.TH1orTH2(folder, "hMCT_Tau_DeltaR", "#DeltaR(#tau_{mc} , L1 #tau_{calo})", "Entries / %0.3f", "MCT_Tau_#DeltaR", **DeltaR)


### L1 Di-Tau Efficiencies: 
Et = {"xUnits": "(GeV)", "xMin" : 0.0, "xMax" : 100.0, "yMin" : 1, "yMax" : 1E6, "xLegMin": 0.2, "xLegMax": 0.49, "yLegMin": 0.84, "yLegMax": 0.94, "xCutLines": [], "ratioLabel": "Efficiency",
      "yMinRatio": None, "yMaxRatio": 1.05, "ratio": True, "invRatio": False, "logX": False, "logY": True, "logXRatio": False, "logYRatio": False, "binWidthX": 5, "saveName": None}
hMCT2D_VisEt                       = m_histos.TH1orTH2(folder, "hMCT2D_VisEt", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "MC Tau", **Et)
hMCT2D_VisEt_Calo                  = m_histos.TH1orTH2(folder, "hMCT2D_VisEt_Calo", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "Calo", **Et)
hMCT2D_VisEt_Calo_Confirm          = m_histos.TH1orTH2(folder, "hMCT2D_VisEt_Calo_Confirm", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+ Tk", **Et)
hMCT2D_VisEt_Calo_Confirm_1cmVtxZ0 = m_histos.TH1orTH2(folder, "hMCT2D_VisEt_Calo_Confirm_1cmVtxZ0", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+ VtxIso (1cm)", **Et)
hMCT2D_VisEt_Calo_Confirm_2cmVtxZ0 = m_histos.TH1orTH2(folder, "hMCT2D_VisEt_Calo_Confirm_2cmVtxZ0", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+ VtxIso (2cm)", **Et)
L1DiTauEff = []
L1DiTauEff.append(hMCT2D_VisEt)
L1DiTauEff.append(hMCT2D_VisEt_Calo)
L1DiTauEff.append(hMCT2D_VisEt_Calo_Confirm)
L1DiTauEff.append(hMCT2D_VisEt_Calo_Confirm_1cmVtxZ0)
L1DiTauEff.append(hMCT2D_VisEt_Calo_Confirm_2cmVtxZ0)

Et20 = {"xUnits": "(GeV)", "xMin" : 0.0, "xMax" : 100.0, "yMin" : 1, "yMax" : 1E6, "xLegMin": 0.20, "xLegMax": 0.49, "yLegMin": 0.84, "yLegMax": 0.94, "xCutLines": [], "ratioLabel": "Efficiency",
        "yMinRatio": None, "yMaxRatio": 1.05, "ratio": True, "logY": True, "logYRatio": False, "binWidthX": 5, "styleType": None, "saveName":  "hMCT2D_VisEt_GenTauVisEt20"}
hMCT2D_VisEt_GenTauVisEt20                       = m_histos.TH1orTH2(folder, "hMCT2D_VisEt", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "MC Tau", **Et20)
hMCT2D_VisEt_GenTauVisEt20_Calo                  = m_histos.TH1orTH2(folder, "hMCT2D_VisEt_GenTauVisEt20_Calo", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "Calo, E_{T} > 90 GeV", **Et20)
hMCT2D_VisEt_GenTauVisEt20_Calo_Confirm          = m_histos.TH1orTH2(folder, "hMCT2D_VisEt_GenTauVisEt20_Calo_Confirm", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+ Tk", **Et20)
hMCT2D_VisEt_GenTauVisEt20_Calo_Confirm_1cmVtxZ0 = m_histos.TH1orTH2(folder, "hMCT2D_VisEt_GenTauVisEt20_Calo_Confirm_1cmVtxZ0", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+ VtxIso (1cm)", **Et20)
hMCT2D_VisEt_GenTauVisEt20_Calo_Confirm_2cmVtxZ0 = m_histos.TH1orTH2(folder, "hMCT2D_VisEt_GenTauVisEt20_Calo_Confirm_2cmVtxZ0", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+ VtxIso (2cm)", **Et20)
L1DiTauEffGenTauVisEt20 = []
L1DiTauEffGenTauVisEt20.append(hMCT2D_VisEt_GenTauVisEt20)
L1DiTauEffGenTauVisEt20.append(hMCT2D_VisEt_GenTauVisEt20_Calo)
L1DiTauEffGenTauVisEt20.append(hMCT2D_VisEt_GenTauVisEt20_Calo_Confirm)
L1DiTauEffGenTauVisEt20.append(hMCT2D_VisEt_GenTauVisEt20_Calo_Confirm_1cmVtxZ0)
L1DiTauEffGenTauVisEt20.append(hMCT2D_VisEt_GenTauVisEt20_Calo_Confirm_2cmVtxZ0)

EtNew = {"xUnits": "(GeV)", "xMin" : 0.0, "xMax" : 100.0, "yMin" : 1, "yMax" : 1E6, "xLegMin": 0.20, "xLegMax": 0.49, "yLegMin": 0.84, "yLegMax": 0.94, "xCutLines": [], "ratioLabel": "Efficiency",
        "yMinRatio": None, "yMaxRatio": 1.05, "ratio": True, "invRatio": False, "logX": False, "logY": True, "logXRatio": False, "logYRatio": False, "binWidthX": 5, "saveName": "hMCT2D_VisEt_New"}
hMCT2D_VisEt                            = m_histos.TH1orTH2(folder, "hMCT2D_VisEt", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "MC Tau", **EtNew)
hMCT2D_VisEt_Calo_EtGr_60Perc90         = m_histos.TH1orTH2(folder, "hMCT2D_VisEt_Calo_EtGr_60Perc90", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "Calo, E_{T} > 90 (54) GeV", **EtNew)
hMCT2D_VisEt_Calo_Confirm_EtGr_60Perc90 = m_histos.TH1orTH2(folder, "hMCT2D_VisEt_Calo_Confirm_EtGr_60Perc90", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+ Tk, E_{T} > 90 (54) GeV", **EtNew)
hMCT2D_VisEt_Calo_Confirm_1cmVtxZ0_EtGr_60Perc65 = m_histos.TH1orTH2(folder, "hMCT2D_VisEt_Calo_Confirm_1cmVtxZ0_EtGr_60Perc65", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+ VtxIso (1cm), E_{T} > 65 (39) GeV", **EtNew)
hMCT2D_VisEt_Calo_Confirm_2cmVtxZ0_EtGr_60Perc65 = m_histos.TH1orTH2(folder, "hMCT2D_VisEt_Calo_Confirm_2cmVtxZ0_EtGr_60Perc65", "#tau_{mc} E_{T}^{vis}", "Entries / %0.0f", "+ VtxIso (2cm), E_{T} > 65 (39) GeV", **EtNew)
L1DiTauEff_New = []
L1DiTauEff_New.append(hMCT2D_VisEt)
L1DiTauEff_New.append(hMCT2D_VisEt_Calo_EtGr_60Perc90)
L1DiTauEff_New.append(hMCT2D_VisEt_Calo_Confirm_EtGr_60Perc90)
L1DiTauEff_New.append(hMCT2D_VisEt_Calo_Confirm_1cmVtxZ0_EtGr_60Perc65)
L1DiTauEff_New.append(hMCT2D_VisEt_Calo_Confirm_2cmVtxZ0_EtGr_60Perc65)

#ino
#hMCT2D_VisEt_Calo_Confirm_1cmVtxZ0_EtGr_60Perc5;
#hMCT2D_VisEt_Calo_Confirm_1cmVtxZ0_EtGr_60Perc10;
#hMCT2D_VisEt_Calo_Confirm_1cmVtxZ0_EtGr_60Perc15;
#hMCT2D_VisEt_Calo_Confirm_1cmVtxZ0_EtGr_60Perc20;
#hMCT2D_VisEt_Calo_Confirm_1cmVtxZ0_EtGr_60Perc25;
#hMCT2D_VisEt_Calo_Confirm_1cmVtxZ0_EtGr_60Perc30;
#hMCT2D_VisEt_Calo_Confirm_1cmVtxZ0_EtGr_60Perc35;
#hMCT2D_VisEt_Calo_Confirm_1cmVtxZ0_EtGr_60Perc40;
#hMCT2D_VisEt_Calo_Confirm_1cmVtxZ0_EtGr_60Perc45;
#hMCT2D_VisEt_Calo_Confirm_1cmVtxZ0_EtGr_60Perc50;
#hMCT2D_VisEt_Calo_Confirm_1cmVtxZ0_EtGr_60Perc55;
#hMCT2D_VisEt_Calo_Confirm_1cmVtxZ0_EtGr_60Perc60;
#hMCT2D_VisEt_Calo_Confirm_1cmVtxZ0_EtGr_60Perc65;
#hMCT2D_VisEt_Calo_Confirm_1cmVtxZ0_EtGr_60Perc70;
#hMCT2D_VisEt_Calo_Confirm_1cmVtxZ0_EtGr_60Perc75;
#hMCT2D_VisEt_Calo_Confirm_1cmVtxZ0_EtGr_60Perc80;
#hMCT2D_VisEt_Calo_Confirm_1cmVtxZ0_EtGr_60Perc85;
#hMCT2D_VisEt_Calo_Confirm_1cmVtxZ0_EtGr_60Perc90;
#
#hMCT2D_VisEt_Calo_Confirm_1cmVtxZ0_EtGr_70Perc5;
#hMCT2D_VisEt_Calo_Confirm_1cmVtxZ0_EtGr_70Perc10;
#hMCT2D_VisEt_Calo_Confirm_1cmVtxZ0_EtGr_70Perc15;
#hMCT2D_VisEt_Calo_Confirm_1cmVtxZ0_EtGr_70Perc20;
#hMCT2D_VisEt_Calo_Confirm_1cmVtxZ0_EtGr_70Perc25;
#hMCT2D_VisEt_Calo_Confirm_1cmVtxZ0_EtGr_70Perc30;
#hMCT2D_VisEt_Calo_Confirm_1cmVtxZ0_EtGr_70Perc35;
#hMCT2D_VisEt_Calo_Confirm_1cmVtxZ0_EtGr_70Perc40;
#hMCT2D_VisEt_Calo_Confirm_1cmVtxZ0_EtGr_70Perc45;
#hMCT2D_VisEt_Calo_Confirm_1cmVtxZ0_EtGr_70Perc50;
#hMCT2D_VisEt_Calo_Confirm_1cmVtxZ0_EtGr_70Perc55;
#hMCT2D_VisEt_Calo_Confirm_1cmVtxZ0_EtGr_70Perc60;
#hMCT2D_VisEt_Calo_Confirm_1cmVtxZ0_EtGr_70Perc65;
#hMCT2D_VisEt_Calo_Confirm_1cmVtxZ0_EtGr_70Perc70;
#hMCT2D_VisEt_Calo_Confirm_1cmVtxZ0_EtGr_70Perc75;
#hMCT2D_VisEt_Calo_Confirm_1cmVtxZ0_EtGr_70Perc80;
#hMCT2D_VisEt_Calo_Confirm_1cmVtxZ0_EtGr_70Perc85;
#hMCT2D_VisEt_Calo_Confirm_1cmVtxZ0_EtGr_70Perc90;
#
#hMCT2D_VisEt_Calo_Confirm_1cmVtxZ0_EtGr_80Perc5;
#hMCT2D_VisEt_Calo_Confirm_1cmVtxZ0_EtGr_80Perc10;
#hMCT2D_VisEt_Calo_Confirm_1cmVtxZ0_EtGr_80Perc15;
#hMCT2D_VisEt_Calo_Confirm_1cmVtxZ0_EtGr_80Perc20;
#hMCT2D_VisEt_Calo_Confirm_1cmVtxZ0_EtGr_80Perc25;
#hMCT2D_VisEt_Calo_Confirm_1cmVtxZ0_EtGr_80Perc30;
#hMCT2D_VisEt_Calo_Confirm_1cmVtxZ0_EtGr_80Perc35;
#hMCT2D_VisEt_Calo_Confirm_1cmVtxZ0_EtGr_80Perc40;
#hMCT2D_VisEt_Calo_Confirm_1cmVtxZ0_EtGr_80Perc45;
#hMCT2D_VisEt_Calo_Confirm_1cmVtxZ0_EtGr_80Perc50;
#hMCT2D_VisEt_Calo_Confirm_1cmVtxZ0_EtGr_80Perc55;
#hMCT2D_VisEt_Calo_Confirm_1cmVtxZ0_EtGr_80Perc60;
#hMCT2D_VisEt_Calo_Confirm_1cmVtxZ0_EtGr_80Perc65;
#hMCT2D_VisEt_Calo_Confirm_1cmVtxZ0_EtGr_80Perc70;
#hMCT2D_VisEt_Calo_Confirm_1cmVtxZ0_EtGr_80Perc75;
#hMCT2D_VisEt_Calo_Confirm_1cmVtxZ0_EtGr_80Perc80;
#hMCT2D_VisEt_Calo_Confirm_1cmVtxZ0_EtGr_80Perc85;
#hMCT2D_VisEt_Calo_Confirm_1cmVtxZ0_EtGr_80Perc90;
#
#hMCT2D_VisEt_Calo_Confirm_2cmVtxZ0;
#hMCT2D_VisEt_Calo_Confirm_2cmVtxZ0_EtGr_60Perc5;
#hMCT2D_VisEt_Calo_Confirm_2cmVtxZ0_EtGr_60Perc10;
#hMCT2D_VisEt_Calo_Confirm_2cmVtxZ0_EtGr_60Perc15;
#hMCT2D_VisEt_Calo_Confirm_2cmVtxZ0_EtGr_60Perc20;
#hMCT2D_VisEt_Calo_Confirm_2cmVtxZ0_EtGr_60Perc25;
#hMCT2D_VisEt_Calo_Confirm_2cmVtxZ0_EtGr_60Perc30;
#hMCT2D_VisEt_Calo_Confirm_2cmVtxZ0_EtGr_60Perc35;
#hMCT2D_VisEt_Calo_Confirm_2cmVtxZ0_EtGr_60Perc40;
#hMCT2D_VisEt_Calo_Confirm_2cmVtxZ0_EtGr_60Perc45;
#hMCT2D_VisEt_Calo_Confirm_2cmVtxZ0_EtGr_60Perc50;
#hMCT2D_VisEt_Calo_Confirm_2cmVtxZ0_EtGr_60Perc55;
#hMCT2D_VisEt_Calo_Confirm_2cmVtxZ0_EtGr_60Perc60;
#hMCT2D_VisEt_Calo_Confirm_2cmVtxZ0_EtGr_60Perc65;
#hMCT2D_VisEt_Calo_Confirm_2cmVtxZ0_EtGr_60Perc70;
#hMCT2D_VisEt_Calo_Confirm_2cmVtxZ0_EtGr_60Perc75;
#hMCT2D_VisEt_Calo_Confirm_2cmVtxZ0_EtGr_60Perc80;
#hMCT2D_VisEt_Calo_Confirm_2cmVtxZ0_EtGr_60Perc85;
#hMCT2D_VisEt_Calo_Confirm_2cmVtxZ0_EtGr_60Perc90;
#
#hMCT2D_VisEt_Calo_Confirm_2cmVtxZ0_EtGr_70Perc5;
#hMCT2D_VisEt_Calo_Confirm_2cmVtxZ0_EtGr_70Perc10;
#hMCT2D_VisEt_Calo_Confirm_2cmVtxZ0_EtGr_70Perc15;
#hMCT2D_VisEt_Calo_Confirm_2cmVtxZ0_EtGr_70Perc20;
#hMCT2D_VisEt_Calo_Confirm_2cmVtxZ0_EtGr_70Perc25;
#hMCT2D_VisEt_Calo_Confirm_2cmVtxZ0_EtGr_70Perc30;
#hMCT2D_VisEt_Calo_Confirm_2cmVtxZ0_EtGr_70Perc35;
#hMCT2D_VisEt_Calo_Confirm_2cmVtxZ0_EtGr_70Perc40;
#hMCT2D_VisEt_Calo_Confirm_2cmVtxZ0_EtGr_70Perc45;
#hMCT2D_VisEt_Calo_Confirm_2cmVtxZ0_EtGr_70Perc50;
#hMCT2D_VisEt_Calo_Confirm_2cmVtxZ0_EtGr_70Perc55;
#hMCT2D_VisEt_Calo_Confirm_2cmVtxZ0_EtGr_70Perc60;
#hMCT2D_VisEt_Calo_Confirm_2cmVtxZ0_EtGr_70Perc65;
#hMCT2D_VisEt_Calo_Confirm_2cmVtxZ0_EtGr_70Perc70;
#hMCT2D_VisEt_Calo_Confirm_2cmVtxZ0_EtGr_70Perc75;
#hMCT2D_VisEt_Calo_Confirm_2cmVtxZ0_EtGr_70Perc80;
#hMCT2D_VisEt_Calo_Confirm_2cmVtxZ0_EtGr_70Perc85;
#hMCT2D_VisEt_Calo_Confirm_2cmVtxZ0_EtGr_70Perc90;
#
#hMCT2D_VisEt_Calo_Confirm_2cmVtxZ0_EtGr_80Perc5;
#hMCT2D_VisEt_Calo_Confirm_2cmVtxZ0_EtGr_80Perc10;
#hMCT2D_VisEt_Calo_Confirm_2cmVtxZ0_EtGr_80Perc15;
#hMCT2D_VisEt_Calo_Confirm_2cmVtxZ0_EtGr_80Perc20;
#hMCT2D_VisEt_Calo_Confirm_2cmVtxZ0_EtGr_80Perc25;
#hMCT2D_VisEt_Calo_Confirm_2cmVtxZ0_EtGr_80Perc30;
#hMCT2D_VisEt_Calo_Confirm_2cmVtxZ0_EtGr_80Perc35;
#hMCT2D_VisEt_Calo_Confirm_2cmVtxZ0_EtGr_80Perc40;
#hMCT2D_VisEt_Calo_Confirm_2cmVtxZ0_EtGr_80Perc45;
#hMCT2D_VisEt_Calo_Confirm_2cmVtxZ0_EtGr_80Perc50;
#hMCT2D_VisEt_Calo_Confirm_2cmVtxZ0_EtGr_80Perc55;
#hMCT2D_VisEt_Calo_Confirm_2cmVtxZ0_EtGr_80Perc60;
#hMCT2D_VisEt_Calo_Confirm_2cmVtxZ0_EtGr_80Perc65;
#hMCT2D_VisEt_Calo_Confirm_2cmVtxZ0_EtGr_80Perc70;
#hMCT2D_VisEt_Calo_Confirm_2cmVtxZ0_EtGr_80Perc75;
#hMCT2D_VisEt_Calo_Confirm_2cmVtxZ0_EtGr_80Perc80;
#hMCT2D_VisEt_Calo_Confirm_2cmVtxZ0_EtGr_80Perc85;
#hMCT2D_VisEt_Calo_Confirm_2cmVtxZ0_EtGr_80Perc90;
#
#hMCT2D_VisEt_Calo_Confirm_EtGr_60Perc5;
#hMCT2D_VisEt_Calo_Confirm_EtGr_60Perc10;
#hMCT2D_VisEt_Calo_Confirm_EtGr_60Perc15;
#hMCT2D_VisEt_Calo_Confirm_EtGr_60Perc20;
#hMCT2D_VisEt_Calo_Confirm_EtGr_60Perc25;
#hMCT2D_VisEt_Calo_Confirm_EtGr_60Perc30;
#hMCT2D_VisEt_Calo_Confirm_EtGr_60Perc35;
#hMCT2D_VisEt_Calo_Confirm_EtGr_60Perc40;
#hMCT2D_VisEt_Calo_Confirm_EtGr_60Perc45;
#hMCT2D_VisEt_Calo_Confirm_EtGr_60Perc50;
#hMCT2D_VisEt_Calo_Confirm_EtGr_60Perc55;
#hMCT2D_VisEt_Calo_Confirm_EtGr_60Perc60;
#hMCT2D_VisEt_Calo_Confirm_EtGr_60Perc65;
#hMCT2D_VisEt_Calo_Confirm_EtGr_60Perc70;
#hMCT2D_VisEt_Calo_Confirm_EtGr_60Perc75;
#hMCT2D_VisEt_Calo_Confirm_EtGr_60Perc80;
#hMCT2D_VisEt_Calo_Confirm_EtGr_60Perc85;
#hMCT2D_VisEt_Calo_Confirm_EtGr_60Perc90;
#
#hMCT2D_VisEt_Calo_Confirm_EtGr_70Perc5;
#hMCT2D_VisEt_Calo_Confirm_EtGr_70Perc10;
#hMCT2D_VisEt_Calo_Confirm_EtGr_70Perc15;
#hMCT2D_VisEt_Calo_Confirm_EtGr_70Perc20;
#hMCT2D_VisEt_Calo_Confirm_EtGr_70Perc25;
#hMCT2D_VisEt_Calo_Confirm_EtGr_70Perc30;
#hMCT2D_VisEt_Calo_Confirm_EtGr_70Perc35;
#hMCT2D_VisEt_Calo_Confirm_EtGr_70Perc40;
#hMCT2D_VisEt_Calo_Confirm_EtGr_70Perc45;
#hMCT2D_VisEt_Calo_Confirm_EtGr_70Perc50;
#hMCT2D_VisEt_Calo_Confirm_EtGr_70Perc55;
#hMCT2D_VisEt_Calo_Confirm_EtGr_70Perc60;
#hMCT2D_VisEt_Calo_Confirm_EtGr_70Perc65;
#hMCT2D_VisEt_Calo_Confirm_EtGr_70Perc70;
#hMCT2D_VisEt_Calo_Confirm_EtGr_70Perc75;
#hMCT2D_VisEt_Calo_Confirm_EtGr_70Perc80;
#hMCT2D_VisEt_Calo_Confirm_EtGr_70Perc85;
#hMCT2D_VisEt_Calo_Confirm_EtGr_70Perc90;
#
#hMCT2D_VisEt_Calo_Confirm_EtGr_80Perc5;
#hMCT2D_VisEt_Calo_Confirm_EtGr_80Perc10;
#hMCT2D_VisEt_Calo_Confirm_EtGr_80Perc15;
#hMCT2D_VisEt_Calo_Confirm_EtGr_80Perc20;
#hMCT2D_VisEt_Calo_Confirm_EtGr_80Perc25;
#hMCT2D_VisEt_Calo_Confirm_EtGr_80Perc30;
#hMCT2D_VisEt_Calo_Confirm_EtGr_80Perc35;
#hMCT2D_VisEt_Calo_Confirm_EtGr_80Perc40;
#hMCT2D_VisEt_Calo_Confirm_EtGr_80Perc45;
#hMCT2D_VisEt_Calo_Confirm_EtGr_80Perc50;
#hMCT2D_VisEt_Calo_Confirm_EtGr_80Perc55;
#hMCT2D_VisEt_Calo_Confirm_EtGr_80Perc60;
#hMCT2D_VisEt_Calo_Confirm_EtGr_80Perc65;
#hMCT2D_VisEt_Calo_Confirm_EtGr_80Perc70;
#hMCT2D_VisEt_Calo_Confirm_EtGr_80Perc75;
#hMCT2D_VisEt_Calo_Confirm_EtGr_80Perc80;
#hMCT2D_VisEt_Calo_Confirm_EtGr_80Perc85;
#hMCT2D_VisEt_Calo_Confirm_EtGr_80Perc90;
#
#hMCT2D_VisEt_Calo_EtGr_60Perc5;
#hMCT2D_VisEt_Calo_EtGr_60Perc10;
#hMCT2D_VisEt_Calo_EtGr_60Perc15;
#hMCT2D_VisEt_Calo_EtGr_60Perc20;
#hMCT2D_VisEt_Calo_EtGr_60Perc25;
#hMCT2D_VisEt_Calo_EtGr_60Perc30;
#hMCT2D_VisEt_Calo_EtGr_60Perc35;
#hMCT2D_VisEt_Calo_EtGr_60Perc40;
#hMCT2D_VisEt_Calo_EtGr_60Perc45;
#hMCT2D_VisEt_Calo_EtGr_60Perc50;
#hMCT2D_VisEt_Calo_EtGr_60Perc55;
#hMCT2D_VisEt_Calo_EtGr_60Perc60;
#hMCT2D_VisEt_Calo_EtGr_60Perc65;
#hMCT2D_VisEt_Calo_EtGr_60Perc70;
#hMCT2D_VisEt_Calo_EtGr_60Perc75;
#hMCT2D_VisEt_Calo_EtGr_60Perc80;
#hMCT2D_VisEt_Calo_EtGr_60Perc85;
#hMCT2D_VisEt_Calo_EtGr_60Perc90;
#
#hMCT2D_VisEt_Calo_EtGr_70Perc5;
#hMCT2D_VisEt_Calo_EtGr_70Perc10;
#hMCT2D_VisEt_Calo_EtGr_70Perc15;
#hMCT2D_VisEt_Calo_EtGr_70Perc20;
#hMCT2D_VisEt_Calo_EtGr_70Perc25;
#hMCT2D_VisEt_Calo_EtGr_70Perc30;
#hMCT2D_VisEt_Calo_EtGr_70Perc35;
#hMCT2D_VisEt_Calo_EtGr_70Perc40;
#hMCT2D_VisEt_Calo_EtGr_70Perc45;
#hMCT2D_VisEt_Calo_EtGr_70Perc50;
#hMCT2D_VisEt_Calo_EtGr_70Perc55;
#hMCT2D_VisEt_Calo_EtGr_70Perc60;
#hMCT2D_VisEt_Calo_EtGr_70Perc65;
#hMCT2D_VisEt_Calo_EtGr_70Perc70;
#hMCT2D_VisEt_Calo_EtGr_70Perc75;
#hMCT2D_VisEt_Calo_EtGr_70Perc80;
#hMCT2D_VisEt_Calo_EtGr_70Perc85;
#hMCT2D_VisEt_Calo_EtGr_70Perc90;
#hMCT2D_VisEt_Calo_EtGr_70Perc90;
#
#hMCT2D_VisEt_Calo_EtGr_80Perc5;
#hMCT2D_VisEt_Calo_EtGr_80Perc10;
#hMCT2D_VisEt_Calo_EtGr_80Perc15;
#hMCT2D_VisEt_Calo_EtGr_80Perc20;
#hMCT2D_VisEt_Calo_EtGr_80Perc25;
#hMCT2D_VisEt_Calo_EtGr_80Perc30;
#hMCT2D_VisEt_Calo_EtGr_80Perc35;
#hMCT2D_VisEt_Calo_EtGr_80Perc40;
#hMCT2D_VisEt_Calo_EtGr_80Perc45;
#hMCT2D_VisEt_Calo_EtGr_80Perc50;
#hMCT2D_VisEt_Calo_EtGr_80Perc55;
#hMCT2D_VisEt_Calo_EtGr_80Perc60;
#hMCT2D_VisEt_Calo_EtGr_80Perc65;
#hMCT2D_VisEt_Calo_EtGr_80Perc70;
#hMCT2D_VisEt_Calo_EtGr_80Perc75;
#hMCT2D_VisEt_Calo_EtGr_80Perc80;
#hMCT2D_VisEt_Calo_EtGr_80Perc85;
#hMCT2D_VisEt_Calo_EtGr_80Perc90;
##ino


### L1 DoubleTau Trigger: Misc
LdgTkDeltaVtxZ0 = {"xUnits": "(cm)", "xMin" : -2.5, "xMax" : +2.5, "yUnits": None, "yMin": 1E-4, "yMax" : 1, "xLegMin": 0.75, "xLegMax": 0.94, "yLegMin": 0.84, "yLegMax": 0.94,
                   "xCutLines": [-1.0, +1.0], "gridX": True, "gridY": True, "binWidthX": None, "normaliseTo": "One", "logY": True, "drawOptions": "P", "legOptions": "LP"}
hCalo2D_LdgTkDeltaVtxZ0 = m_histos.TH1orTH2(folder, "hCalo2D_LdgTkDeltaVtxZ0", "#Deltaz_{vtx}(L1TkTau, L1TkTau)", "Entries / %0.2f", "+2 Tk", **LdgTkDeltaVtxZ0)


############################################################### 
### New Efficiencies
############################################################### 
Et_VisCut = {"xUnits": "(GeV)", "xMin" : 0.0, "xMax" : 100.0, "yMin" : 1, "yMax" : 1E6, "xLegMin": 0.65, "xLegMax": 0.94, "yLegMin": 0.84, "yLegMax": 0.94, "xCutLines": [], 
             "yMinRatio": None, "yMaxRatio": None, "normaliseTo": None, "ratio": True, "invRatio": False, "ratioLabel": "Efficiency", "logX": False, "logY": True, "logXRatio": 
             False, "logYRatio": False, "binWidthX": 5}


############################################################### 
### Group Histogram Lists together into categories
############################################################### 
### Generator Tau properties
MCTau = []
MCTau.append(MCT_Decays)
MCTau.append(MCT_Et)
MCTau.append(MCT_Eta)
MCTau.append(MCT_NCharged)
MCTau.append(MCT_VisEt)
MCTau.append(MCT_VisEta)
MCTau.append(MCT_LeadPt)
MCTau.append(MCT_LeadEta)


### L1TkTracks (1D)
L1TkTracksSignal = []
L1TkTracksSignal.append(L1TkTrack10_Pt)
L1TkTracksSignal.append(L1TkTrack10_Eta)
L1TkTracksSignal.append(L1TkTrack10_VtxZ0)
L1TkTracksSignal.append(L1TkTrack10_N)
L1TkTracksSignal.append(L1TkTrack10_DeltaPt)
L1TkTracksSignal.append(L1TkTrack10_DeltaEta)
L1TkTracksSignal.append(L1TkTrack10_DeltaPhi)
L1TkTracksSignal.append(L1TkTrack10_DeltaVtxZ0)


### L1TkTracks (2D)
L1TkTracks2D = []
L1TkTracks2D.append([hL1TkTrack_Pt_Eta])
L1TkTracks2D.append([hL1TkTrack10_Pt_Eta])
L1TkTracks2D.append([hL1TkTrack_Eta_Phi])
L1TkTracks2D.append([hL1TkTrack10_Eta_Phi])


### L1TkTau Candidate (L1 Tk Cluster)
L1TkTauCandidate = []
L1TkTauCandidate.append(TKT_NTracks)
L1TkTauCandidate.append(TKT_LeadPt)
L1TkTauCandidate.append(TKT_LeadEta)
L1TkTauCandidate.append(TKT_LeadVtxZ0)
L1TkTauCandidate.append(TKT_DeltaEta)
L1TkTauCandidate.append(TKT_DeltaPhi)
L1TkTauCandidate.append(TKT_DeltaVtxZ0)
L1TkTauCandidate.append(TKT_PtSum) #scalar
L1TkTauCandidate.append(TKT_N)


### L1 Calo Tau matching a L1 Tk Tau: MinBias: bLdgTrackIsTau==False , Signal: bLdgTrackIsTau==True
L1CaloTau_L1TkTau_Match = []
L1CaloTau_L1TkTau_Match.append(TKT_Lead_Tau_DeltaPhi)
L1CaloTau_L1TkTau_Match.append(TKT_Lead_Tau_DeltaEta)
L1CaloTau_L1TkTau_Match.append(TKT_Lead_Tau_DeltaR)
L1CaloTau_L1TkTau_Match.append(TKT_Lead_Tau_DeltaPtEt)
L1CaloTau_L1TkTau_Match.append(TKT_Lead_Tau_DeltaPtEt_OverEt)


### L1 Calo Tau Vs L1 Tks (Filled only if a closest track is found)
L1CaloTau_Vs_L1Tk = []
L1CaloTau_Vs_L1Tk.append([hTau_L1TkTrack10_DeltaR])
L1CaloTau_Vs_L1Tk.append([hTau_Et_Eta])
L1CaloTau_Vs_L1Tk.append([hTau_Eta_Phi])
L1CaloTau_Vs_L1Tk.append([hTau_Et_L1TkTrack10_Pt])
L1CaloTau_Vs_L1Tk.append([hTau_Eta_L1TkTrack10_Eta])
L1CaloTau_Vs_L1Tk.append([hTau_Phi_L1TkTrack10_Phi])

### SingleTau Trigger: Rates
L1SingleTauTriggerRates = []
L1SingleTauTriggerRates.append(L1SingleTauRates)

### SingleTau Trigger: Efficiencies
L1SingleTauTriggerEfficiencies = []
#L1SingleTauTriggerEfficiencies.append(L1SingleTauEff_InclL1TkTausInIso)
L1SingleTauTriggerEfficiencies.append(L1SingleTauEff_Excl1TkTausInIso)


### DiTau Trigger: Rates
L1DiTauTriggerRates = []
L1DiTauTriggerRates.append([hRateCalo2D])
L1DiTauTriggerRates.append([hRateCalo2D_Confirm1])
L1DiTauTriggerRates.append([hRateCalo2D_Confirm1_1cmVtxZ01])
L1DiTauTriggerRates.append([hRateCalo2D_Confirm1_2cmVtxZ01])
L1DiTauTriggerRates.append([hRateCalo2D_Confirm2])
L1DiTauTriggerRates.append([hRateCalo2D_Confirm2_1cmVtxZ01])
L1DiTauTriggerRates.append([hRateCalo2D_Confirm2_2cmVtxZ01])
L1DiTauTriggerRates.append([hRateCalo2D_Confirm2_1cmVtxZ02])
L1DiTauTriggerRates.append([hRateCalo2D_Confirm2_2cmVtxZ02])
L1DiTauTriggerRates.append([hRateCalo2D_Confirm2_SameVtxZ])
L1DiTauTriggerRates.append([hRateCalo2D_Confirm2_1cmVtxZ01_SameVtxZ])
L1DiTauTriggerRates.append([hRateCalo2D_Confirm2_2cmVtxZ01_SameVtxZ])
L1DiTauTriggerRates.append([hRateCalo2D_Confirm2_1cmVtxZ02_SameVtxZ])
L1DiTauTriggerRates.append([hRateCalo2D_Confirm2_2cmVtxZ02_SameVtxZ])

### DiTau Trigger: Efficiencies
L1DiTauTriggerEfficiencies = []
L1DiTauTriggerEfficiencies.append(L1DiTauEff)
#L1DiTauTriggerEfficiencies.append(L1DiTauEff_New)
#L1DiTauTriggerEfficiencies.append(L1DiTauEffGenTauVisEt20)


### DiTau Trigger: Misc
L1DiTauTrigger = []
L1DiTauTrigger.append([hCalo2D_LdgTkDeltaVtxZ0])
L1DiTauTrigger.append([hMCT_Tau_DeltaEta])
L1DiTauTrigger.append([hMCT_Tau_DeltaPhi])
L1DiTauTrigger.append([hMCT_Tau_DeltaR])

