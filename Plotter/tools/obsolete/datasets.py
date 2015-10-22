###############################################################
### Author .........: Alexandros X. Attikis 
### Institute ......: University Of Cyprus (UCY)
### Email ..........: attikis@cern.ch
###############################################################

###############################################################
### All imported modules
###############################################################
### System modules
import os, sys
import array
import math
import copy
import inspect
import glob
from optparse import OptionParser
from itertools import cycle
### Other
import ROOT

###############################################################
### Define class here
###############################################################
class DatasetClass(object):
    def __init__(self, verbose = False):
        self.bVerbose             = verbose
        self.MulticrabDirPath     = None
        self.McProduction         = None 
        self.McProductions        = ["TTI2023Upg14D", "UpgFall13d", "PrivateProduction2014"]
        self.DatasetToPileUpMap   = {}
        self.DatasetToTaskDirMap  = {}
        self.DatasetToFileMap     = {}
        self.DatasetToGeometryMap = {}
        self.DatasetToEventsMap   = {}
        self.DatasetToCmsswMap    = {}
        self.Verbose()


    def Verbose(self, messageList=None):
        '''
        Custome made verbose system. Will print all messages in the messageList
        only if the verbosity boolean is set to true.
        '''
        if self.bVerbose == False:
            return
        
        print "%s:" % (self.__class__.__name__ + "." + sys._getframe(1).f_code.co_name + "()")
        if messageList==None:
            return
        else:
            for message in messageList:
                print "\t", message
        return


    def Print(self, messageList=[""]):
        '''
        Custome made print system. Will print all messages in the messageList
        even if the verbosity boolean is set to false.
        '''
        print "%s:" % (self.__class__.__name__ + "." + sys._getframe(1).f_code.co_name + "()")
        for message in messageList:
            print "\t", message
        return


    def SetVerbose(self, verbose):
        '''
        Manually enable/disable verbosity.
        '''
        self.verbose = verbose
        self.Verbose(["Verbose mode = ", self.verbose])
        return


    def SetMcProduction(self, McProduction):
        '''
        '''
        self.Verbose()
        
        if McProduction not in self.McProductions:
            raise Exception("MC Production '%s' is not valid. Please select one of the following options:\n '%s'" % (self.McProductions) )
        else:
            if McProduction == "TTI2023Upg14D":
                self._TTI2023Upg14D()
            elif McProduction == "UpgFall13d":
                self._UpgFall13d()
            elif McProduction == "PrivateProduction2014":
                self._PrivateProduction2014()
            else:
                raise Exception("MC Production '%s' is not valid. Please select one of the following options:\n '%s'" % (self.McProductions) )                

        return


    def _TTI2023Upg14D(self):
        '''
        MC Production: TTI2023Upg14D (Technical Proposal)
        CMSSW        : 6_2_0_SLHC12
        HN Link      : https://hypernews.cern.ch/HyperNews/CMS/get/slhc-triggersim/285.html
        '''
        self.Verbose()
        
        self._SetDefaults("MinBias"          ,"6_2_0_SLHC12", PileUp = 140, Events = 284300,Geometry="TP", TaskDir="Neutrino_Pt2to20_gun_TTI2023Upg14D-PU140bx25", TaskSubDir = "/res/")
        self._SetDefaults("SinglePionPlus"   ,"6_2_0_SLHC12", PileUp = 140, Events = 50000 ,Geometry="TP", TaskDir="SinglePionPlusFlatPt0p2To50_TTI2023Upg14D-PU140bx25",TaskSubDir = "/res/")
        self._SetDefaults("SinglePionMinus"  ,"6_2_0_SLHC12", PileUp = 140, Events = 50000 ,Geometry="TP", TaskDir="SinglePionMinusFlatPt0p2To50_TTI2023Upg14D-PU140bx25",TaskSubDir = "/res/")
        self._SetDefaults("SingleTauOneProng","6_2_0_SLHC12", PileUp = 140, Events = 50000 ,Geometry="TP", TaskDir="SingleTauOneProngFlatPt10To100_TTI2023Upg14D-PU140bx25",TaskSubDir = "/res/")
        self._SetDefaults("TauThreeProngsEnr","6_2_0_SLHC12", PileUp = 140, Events = 50000 ,Geometry="TP", TaskDir="TauThreeProngsEnriched_TTI2023Upg14D-PU140bx25", TaskSubDir = "/res/")
        self._SetDefaults("VBF"              ,"6_2_0_SLHC12", PileUp = 140, Events = 24977 ,Geometry="TP", TaskDir="VBF_HToTauTau_125_14TeV_powheg_pythia6_TTI2023Upg14D-PU140bx25", TaskSubDir = "/res/")
        self._SetDefaults("TTbar"            ,"6_2_0_SLHC12", PileUp = 140, Events = 99535 ,Geometry="TP", TaskDir="PYTHIA6_Tauola_TTbar_TuneZ2star_14TeV_TTI2023Upg14D-PU140bx25", TaskSubDir = "/res/") 
        self._SetDefaults("HPlus160"         ,"6_2_0_SLHC12", PileUp = 140, Events = 49680 ,Geometry="TP", TaskDir="PYTHIA6_Tauola_TTbar_ChargedHiggs160_taunu_14TeV_TTI2023Upg14D-PU140bx25", TaskSubDir = "/res/") 
        self._SetDefaults("HPlus200"         ,"6_2_0_SLHC12", PileUp = 140, Events = 50000 ,Geometry="TP",TaskDir="PYTHIA_Tauola_TB_ChargedHiggs200_14TeV_TTI2023Upg14D-PU140bx25", TaskSubDir = "/res/") 

        return


    def _UpgFall13d(self):
        '''
        MC Production: UpgFall13d 
        CMSSW        : 6_1_2_SLHC6_patch1
        HN Link      : https://hypernews.cern.ch/HyperNews/CMS/get/slhc-triggersim/285.html
        '''
        self.Verbose()
        
        self._SetDefaults("tautaugun", CMSSW = "6_1_2_SLHC6_patch1", PileUp = 140, Events = 40000 , Geometry = "BE5D", TaskDir = "TauThreeProngs_UpgFall13d_PU140bx25", TaskSubDir = "/res/")
        self._SetDefaults("ttbar"    , CMSSW = "6_1_2_SLHC6_patch1", PileUp = 140, Events = 92044 , Geometry = "BE5D", TaskDir = "TTbar_TuneZ2star_14TeV_UpgFall13d_PU140bx25", TaskSubDir = "/res/") 
        self._SetDefaults("vbf"      , CMSSW = "6_1_2_SLHC6_patch1", PileUp = 140, Events = 23178 , Geometry = "BE5D", TaskDir = "VBF_HToTauTau_125_14TeV_Powheg_Pythia6_UpgFall13d_PU140bx25", TaskSubDir = "/res/")
        self._SetDefaults("htotautau", CMSSW = "6_1_2_SLHC6_patch1", PileUp = 140, Events = 23799 , Geometry = "BE5D", TaskDir = "HToTauTau_125_14TeV_Powheg_Pythia6_UpgFall13d_PU140bx25", TaskSubDir = "/res/")
        self._SetDefaults("minbias"  , CMSSW = "6_1_2_SLHC6_patch1", PileUp = 140, Events = 180000, Geometry = "BE5D", TaskDir = "Neutrino_Pt2to20_gun_UpgFall13d_PU140bx25", TaskSubDir = "/res/")
        return


    def _PrivateProduction2014(self):
        '''
        MC Production: Private
        CMSSW        : Can vary
        HN Link      : None
        '''
        self.Verbose()
        
        self._SetSpecials("taugun-1pr-pu140", CMSSW = "6_1_2_SLHC6_patch1", PileUp = 140, Events = 4100 , Geometry = "BE5D", TaskDir = "PU140/OneProng/", TaskSubDir = "", RootFileName = "output.root")
        self._SetSpecials("taugun-1pr-nopu" , CMSSW = "6_1_2_SLHC6_patch1", PileUp = 0  , Events = 0    , Geometry = "BE5D", TaskDir = "NoPU/OneProng/", TaskSubDir = "", RootFileName = "output.root")
        self._SetSpecials("taugun-3pr-pu140", CMSSW = "6_1_2_SLHC6_patch1", PileUp = 140, Events = 4300 , Geometry = "BE5D", TaskDir = "PU140/ThreeProng/", TaskSubDir = "", RootFileName = "output.root")
        self._SetSpecials("taugun-3pr-nopu" , CMSSW = "6_1_2_SLHC6_patch1", PileUp = 0  , Events = 5000 , Geometry = "BE5D", TaskDir = "NoPU/ThreeProng/", TaskSubDir = "", RootFileName = "output.root")

        return


    def _SetDefaults(self, dataset, CMSSW, PileUp, Events, Geometry, TaskDir, TaskSubDir, **kwargs):
        '''
        '''
        self.Verbose()

        ### Remove upper-case dependence
        dataset = dataset.lower()

        self.DatasetToPileUpMap[dataset]   = PileUp
        self.DatasetToGeometryMap[dataset] = Geometry
        self.DatasetToTaskDirMap[dataset]  = self.MulticrabDirPath + TaskDir
        self.DatasetToFileMap[dataset]     = self.MulticrabDirPath + TaskDir + TaskSubDir + "output-" + TaskDir + ".root"
        self.DatasetToEventsMap[dataset]   = Events
        self.DatasetToCmsswMap[dataset]    = CMSSW

        ### Set all arguments and their values
        for argument, value in kwargs.iteritems():
            setattr(self, name + "_" + argument, value)
        return


    def _SetSpecials(self, dataset, CMSSW, PileUp, Events, Geometry, TaskDir, TaskSubDir, RootFileName, **kwargs):
        '''
        '''
        self.Verbose()

        ### Remove upper-case dependence
        dataset = dataset.lower()

        self.DatasetToPileUpMap[dataset]   = PileUp
        self.DatasetToGeometryMap[dataset] = Geometry
        self.DatasetToTaskDirMap[dataset]  = self.MulticrabDirPath + TaskDir
        self.DatasetToFileMap[dataset]     = self.MulticrabDirPath + TaskDir + TaskSubDir + RootFileName
        self.DatasetToEventsMap[dataset]   = Events
        self.DatasetToCmsswMap[dataset]    = CMSSW

        ### Set all arguments and their values
        for argument, value in kwargs.iteritems():
            setattr(self, name + "_" + argument, value)
        return


    def GetTaskDir(self, dataset):
        '''
        '''
        self.Verbose()

        ### Remove upper-case dependence
        dataset = dataset.lower()
        return self.DatasetToTaskDirMap[dataset]


    def GetFile(self, dataset):
        '''
        '''
        self.Verbose()

        ### Remove upper-case dependence
        dataset = dataset.lower()
        return self.DatasetToFileMap[dataset]


    def GetGeometry(self, dataset):
        '''
        '''
        self.Verbose()

        ### Remove upper-case dependence
        dataset = dataset.lower()
        return self.DatasetToGeometryMap[dataset]


    def GetEvents(self, dataset):
        '''
        '''
        self.Verbose()
        
        ### Remove upper-case dependence
        dataset = dataset.lower()
        events  = raw_input("*** Please insert the normalisation factor (i.e. total number of MC events produced) for this dataset ('%s') or press 'Enter' if all events were processed: " % (dataset) )
        if len(events) == 0:
            if dataset in self.DatasetToEventsMap.keys():
                return self.DatasetToEventsMap[dataset]
            else:
                raise Exception("Invalid dataset '%s'. Cannot determine the number of events produced for this." % (dataset))
        else:
            return int(events)



    def GetPileUp(self, dataset):
        '''
        '''
        self.Verbose()

        ### Remove upper-case dependence
        dataset = dataset.lower()
        return self.DatasetToPileUpMap[dataset]


    def GetCMSSW(self, dataset):
        '''
        '''
        self.Verbose()

        ### Remove upper-case dependence
        dataset = dataset.lower()
        return self.DatasetToCmsswMap[dataset]


    def SetMulticrabDirPath(self, MulticrabDirPath=None):
        '''
        '''
        self.Verbose()

        self.MulticrabDirPath = MulticrabDirPath
        return


    def GetDatasetToPileUpMap(self):
        '''
        '''
        self.Verbose()

        return self.DatasetToPileUpMap


    def GetDatasetToTaskDirMap(self):
        '''
        '''
        self.Verbose()

        return self.DatasetToTaskDirMap


    def GetDatasetToFileMap(self):
        '''
        '''
        self.Verbose()

        return self.DatasetToFileMap


    def GetDatasetToGeometryMap(self):
        '''
        '''
        self.Verbose()

        return self.DatasetToGeometryMap


    def GetDatasetToEventsMap(self):
        '''
        '''
        self.Verbose()

        return self.DatasetToEventsMap


    def GetDatasetToCmsswMap(self):
        '''
        '''
        self.Verbose()

        return self.DatasetToCmsswMap


    def ConvertDatasetToLatex(self, dataset):
        '''
        '''
        self.Verbose()
        
        if dataset == None:
            return

        ### Remove upper-case dependence
        dataset = dataset.lower()

        if dataset == "tautaugun":
           return "#tau#tau gun"
        elif "taugun" in dataset:
            return "#tau gun"
        elif dataset == "minbias":
            return "MB"
        elif dataset == "ttbar":
            return "t#bar{t}"
        elif dataset == "vbf":
            return "VBF H^{0}#rightarrow#tau^{+}#tau^{-}"
        elif dataset == "htotautau":
            return "H^{0}#rightarrow#tau^{+}#tau^{-}"
            #return "H^{0}#rightarrow#tau^{#pm}#tau^{#mp}"
        elif dataset == "tauthreeprongsenr":
            return "#tau#tau gun (3-pr)"
        elif dataset == "singlepionplus":
            return "#pi^{+} gun"
        elif dataset == "singlepionminus":
            return "#pi^{-} gun"
        elif dataset == "singletauoneprong":
            return "#tau gun"
        elif dataset == "hplus200":
            return "H^{+}#rightarrow#tau^{+}#nu_{#tau} (200 GeV)"
            #return "H^{#pm}#rightarrow#tau^{#pm}#nu_{#tau} (m_{H^{#pm}} = 200 GeV)"
        elif dataset == "hplus160":
            return "H^{+}#rightarrow#tau^{+}#nu_{#tau} (160 GeV)"
            #return "H^{#pm}#rightarrow#tau^{#pm}#nu_{#tau} (m_{H^{#pm}} = 160 GeV)"
        else:
            raise Exception("Invalid dataset '%s'. Cannot determine it's LaTeX legend entry." % (dataset))            

