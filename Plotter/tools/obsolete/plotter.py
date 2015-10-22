###############################################################
### Author .........: Alexandros X. Attikis 
### Institute ......: University Of Cyprus (UCY)
### Email ..........: attikis@cern.ch
###############################################################
### Normal assignment operations (a = b) will simply point the new variable towards the existing object.
### A deep copy ( copy.deepcopy() ) constructs a new compound object and then, recursively, inserts copies into it of the objects found in the original.
### A shallow copy ( copy.copy() ) constructs a new compound object and then (to the extent possible) inserts references into it to the objects found in the original.

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
import itertools
import time
import numpy #to replace "const double *something" in ROOT with "numpy.array([1,2,3])" in pyROOT
import time
from array import array
import re
import progressbar
### Other 
import ROOT
from ROOT import std
import tdrstyle as m_tdrstyle
import text as m_text
import aux as m_aux
#import latex as m_latex
import styles as m_styles
import histos as m_histos
import tools.tree as m_tree
import tools.datasets as m_datasets

###############################################################
### Define class
###############################################################
class Plotter(object): 
    def __init__(self, Verbose=False, BatchMode=True):
        self.bVerbose          = Verbose
        self.BatchMode         = BatchMode
        self.SetupROOT()       
        self.TDRStyleObject    = m_tdrstyle.TDRStyle()
        self.StyleObject       = m_styles.StyleClass(verbose = self.bVerbose)
        self.TextObject        = m_text.TextClass(verbose=self.bVerbose)
        self.AuxObject         = m_aux.AuxClass(verbose=self.bVerbose)
        #self.LatexObject       = m_latex.LatexClass(verbose=self.bVerbose)
        self.DatasetObject     = m_datasets.DatasetClass(verbose=self.bVerbose)
        self.CanvasFactor      = 1.25
        self.CanvasHeightCorr  = 0.022
        self.DatasetToTFileMap = {} 
        self.DatasetToTHMap    = {}
        self.DatasetToGraphMap = {}
        self.DivisionPoint     = 1-1/self.CanvasFactor
        self.DrawObjectList    = []
        self.DrawObjectListR   = []
        self.HistoObjectList   = []
        self.TCanvas           = None
        self.TLegend           = None
        self.PadCover          = None
        self.PadPlot           = None
        self.PadRatio          = None
        self.DatasetList       = []
        self.TBoxList          = []
        self.xTLineList        = []
        self.yTLineList        = []
        self.TFileList         = []
        self.THList            = []
        self.THRatio           = None
        self.THDumbie          = None
        self.THStack           = ROOT.THStack("THStack", "Stack for PadPlot Histograms")
        self.THStackHistoList  = [] #needed because looping over self.THSTack.GetHists() crashes!
        self.THStackRatio      = ROOT.THStack("THStackRatio", "Stack for PadRatio Histograms")
        self.bInvPadRatio      = False
        self.bPadRatio         = False
        self.RatioErrorType    = None
        self.bStackInclusive   = False
        self.TreeObject        = m_tree.TreeClass(verbose=self.bVerbose)
        self.TMultigraph       = ROOT.TMultiGraph("TMultigraph", "ROOT.TMultiGraph holding various ROOT.TGraphs")
        self.startTime         = time.time()
        self.TTree             = None
        self.TreeStartIndex    = None
        self.TreeEndIndex      = None
        self.TreeEntries       = None
        self.TBranch           = {}
        self.TBranchFunction   = {}
        self.TBranchFormula    = {}
        self.MsgCounter        = 0
        self.CutOption         = None
        self.IsTH2             = False
        self.CutLineColour     = ROOT.kGray
        self.SaveContourPoints = False
        self.LdgJetAxis        = None
        self.MinEtDiffBetweenLdgJetWP = None
        self.MaxDecimals       = None
        print "[0] class Plotter(object):"

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

        self.MsgCounter = self.MsgCounter  + 1
        print "[%s] %s:" % (self.MsgCounter, self.__class__.__name__ + "." + sys._getframe(1).f_code.co_name + "()")
        for message in messageList:
            print "\t", message
        return


    def SetupROOT(self):
        '''
        Setup ROOT before doing anything else. Reset ROOT settings, disable statistics box,
        apply Techical Design Report (TDR) style.
        '''
        self.Verbose()
        
        ROOT.gROOT.Reset()
        ROOT.gStyle.SetOptStat(0)
        ROOT.TGaxis.SetMaxDigits(4)
        #m_tdrstyle.TDRStyle() # fotis
        ROOT.gROOT.SetBatch(self.BatchMode)
        self.SetupROOTErrorIgnoreLevel(2000)
        #ROOT.gStyle.SetNumberContours(999)
        ROOT.gStyle.SetNumberContours(100)
        return


    def SetupStatsBox(self, options = 000001111):
        '''
        The "mode" has up to nine digits that can be set to on(1 or 2), off(0).
        mode = iourmen  (default = 000001111)
        i = 1;  integral of bins printed
        o = 1;  number of overflows printed
        u = 1;  number of underflows printed
        r = 1;  rms printed
        r = 2;  rms and rms error printed
        m = 1;  mean value printed
        m = 2;  mean and mean error values printed
        e = 1;  number of entries printed
        n = 1;  name of histogram is printed
        k = 1;  kurtosis printed
        k = 2;  kurtosis and kurtosis error printed
        s = 1;  skewness printed
        s = 2;  skewness and skewness error printed
        '''
        self.Verbose()
        ROOT.gStyle.SetOptStat(options)
        
        return


    def SetupROOTErrorIgnoreLevel(self, level):
        '''
        Available options (const Int_t):
        kUnset    =  -1
        kPrint    =   0
        kInfo     =   1000
        kWarning  =   2000
        kError    =   3000
        kBreak    =   4000
        kSysError =   5000
        kFatal    =   6000
        '''
        self.Verbose()

        ROOT.gErrorIgnoreLevel = level
        return
    

    def AddDataset(self, datasetName, rootFilePath):
        '''
        Add a new dataset and associate it to a root file.
        '''
        self.Verbose()        

        self.Verbose(["From '%s', adding dataset '%s'." % (rootFilePath.rsplit("/", 1)[-1], datasetName)])

        ### Ensure that dataset is unique (dictionaries must have unique keys)
        if datasetName in self.DatasetList:
            raise Exception("Dataset '%s' already exists. Cannot add duplicate. Please ensure that only 1 instance of a given dataset is created." % (datasetName) )
        elif rootFilePath in self.TFileList:
            raise Exception("The ROOT file '%s' already exists. Cannot add duplicate. Please ensure that only 1 instance of a given ROOT file is created." % (rootFilePath) )
        else:
            ### Map dataset to ROOT file, append dataset (name) to datasetlist, append ROOT file (name) to TFile list
            self.DatasetToTFileMap[datasetName] = self.GetTFile(rootFilePath)
            self.DatasetList.append(datasetName)
            self.TFileList.append(rootFilePath)
        return


    def GetDatasets(self, McProduction, MulticrabDirPath, datasetList=[""]):
        '''
        '''
        self.Verbose()

        ### First setup the datasets object
        self.DatasetObject.SetMulticrabDirPath(MulticrabDirPath)
        self.DatasetObject.SetMcProduction(McProduction)

        ### Get the dataset to file maps
        for dataset in datasetList:
            dataset = dataset.lower()
            if dataset in self.DatasetObject.GetDatasetToFileMap().keys():
                self.DatasetToTFileMap[dataset] = self.GetTFile(self.DatasetObject.GetFile(dataset))
                self.DatasetList.append(dataset)
                self.TFileList.append(self.DatasetObject.GetFile(dataset))
            else:
                raise Exception("The dataset provided ('%s') is not valid. Please select one of the following options:\n\t%s" % (dataset, "\n\t".join(self.DatasetObject.GetDatasetToFileMap().keys())) )
        return


    def SetVerbose(self, verbose):
        '''
        Manually enable/disable verbosity.
        '''
        self.Verbose()

        self.bVerbose = verbose
        self.Verbose(["Verbose mode = ", self.verbose])
        return


    def GetTFile(self, rootFilePath, mode = "READ"):
        '''
        Open a TFile from a given rootFilePath in a given mode (default = "READ") and return it.
        Ensure that file does exist.
        '''

        self.Verbose()

        fileName = rootFilePath.rsplit("/", 1)[-1]

        ### Check that the path actually exists
        if os.path.exists(rootFilePath) == False:
            raise Exception("ROOT file '%s' does not exist! Please make sure the provided path for the file is correct." % (rootFilePath) )
        else:
            rootFile = ROOT.TFile.Open( rootFilePath, mode, fileName, 1, 0)

        ### Ensure that file being accessed is indeed a ROOT file. If so return it, else raise exception
        if isinstance(rootFile, ROOT.TFile) == True:
            return rootFile
        else:
            raise Exception("The file '%s' exists but it is not a ROOT file!" % (rootFile.GetName()) )
            

    def _CreateCanvas(self):
        '''
        Create a name for a TCanvas and then create it. 
        This name will later on be used to save the canvas under a user specific format ("png", "pdf", "eps", etc..)
        '''                    
        self.Verbose()

        ### Normal assignment operations (a = b) will simply point the new variable towards the existing object.
        histo = self.THDumbie 

        ### Create a name for the TCanvas
        if histo.saveName == None:
            canvasName = histo.name
        else:
            canvasName = histo.saveName

        ### Create TCanvas and activate it
        self.Verbose(["Creating canvas with name '%s'" % ( canvasName)])
        self.TCanvas = ROOT.TCanvas( canvasName, canvasName, 1)
        self._SetLogAxesCanvas()
        self.TCanvas.cd()
        return


    def _Create2PadCanvas(self):
        '''
        Create a 2-pad TCanvas to accomodate a ratio plot and customise it.
        '''                    
        self.Verbose()

        if ( len(self.DatasetList)>1 and len(self.THList)>1 ):
            #raise Exception( "A 2-pad canvas is not supported yet for plotting multiple (not a single) histogram with multiple datasets.")
            pass

        ### Normal assignment operations (a = b) will simply point the new variable towards the existing object.
        histo = self.THDumbie 

        ### Create the THRatio histogram (PadRatio equivalent of PadPlot's THDumbie)
        self.THRatio = copy.deepcopy(histo)
        self.THRatio.TH1orTH2.SetName("THRatio")

        ### Create TCanvas name that included the dataset name
        if histo.saveName == None:
            canvasName = histo.name
        else:
            canvasName = histo.saveName

        ### Create TCanvas and divide it into two pads: one for plot pad, one for ratio pad
        self.Verbose(["Creating canvas with name '%s'" % ( canvasName)])
        self.TCanvas = ROOT.TCanvas( canvasName, canvasName, ROOT.gStyle.GetCanvasDefW(), int(ROOT.gStyle.GetCanvasDefH()*self.CanvasFactor))
        self.TCanvas.Divide(1,2)

        ### Remove x-axis title and labels from the THDumbie to avoid overlap with those THRatio
        self._RemoveXaxisBinLabels(histo.TH1orTH2)
        self._RemoveXaxisTitle(histo.TH1orTH2)

        ### Create plot, ratio and cover pads
        self._CreatePads()
        
        ### Take care of log-axis settings
        self._SetLogAxes2PadCanvas()

        ### Update canvas and change back to the PadPlot
        self.TCanvas.Update()
        self.PadPlot.cd()

        return


    def _CreatePads(self):
        '''
        Create the plot, ratio and cover pads.
        '''
        self.Verbose()

        self._CreatePadPlot()
        self._CreatePadRatio()
        self._CreatePadCover()
        return

    
    def _CreatePadCover(self, xMin=0.09, yMin=0.285, xMax=0.16, yMax=0.32):
        '''
        Creates a cover pad to cover the overlap of the y-axis divisions between the PadPlot and the PadRatio.
        '''
        self.Verbose()
        
        self.TCanvas.cd()
        self.PadCover = ROOT.TPad("PadCover", "PadCover", xMin, yMin, xMax, yMax)
        self.PadCover.SetName("PadCover")
        self.PadCover.SetBorderMode(0)
        self.PadCover.SetFillStyle(1001)
        self.PadCover.SetFillColor(ROOT.kWhite) #ROOT.kRed
        self.PadCover.Draw()
        self.PadRatio.Draw() # Re-draw PadRatio to put back the covered y-axis numbers
        self.TCanvas.Update()
        return


    def _CreatePadPlot(self):
        '''
        Creates a plot pad to draw the histogram stack.
        '''
        self.Verbose()

        self.PadPlot  = self.TCanvas.cd(1)
        self.PadPlot.SetName("PadPlot")
        (xlow, ylow, xup, yup) = [ROOT.Double(x) for x in [0.0]*4]
        self.PadPlot.GetPadPar(xlow, ylow, xup, yup)
        self.PadPlot.SetPad(xlow, self.DivisionPoint, xup, yup)
        self.PadPlot.Draw()
        self.TCanvas.Update()
        return


    def _CreatePadRatio(self):
        '''
        Creates a ratio pad to draw the histogram ratio stack.
        '''
        self.Verbose()

        self.PadRatio = self.TCanvas.cd(2)
        self.PadRatio.SetName("PadRatio")
        (xlow, ylow, xup, yup) = [ROOT.Double(x) for x in [0.0]*4]
        self.PadRatio.GetPadPar(xlow, ylow, xup, yup)
        self.PadRatio.SetPad(xlow, ylow, xup, self.DivisionPoint + ROOT.gStyle.GetPadBottomMargin() - ROOT.gStyle.GetPadTopMargin() + self.CanvasHeightCorr)
        self.PadRatio.SetFillStyle(4000)
        self.PadRatio.SetTopMargin(0.0)
        self.PadRatio.SetBottomMargin(self.PadRatio.GetBottomMargin()+0.16)
        self.PadRatio.Draw()
        self.TCanvas.Update()
        return


    def _RemoveXaxisBinLabels(self, histo):
        '''
        Removes all the x-axis labels from the histogram pass as argument.
        '''
        self.Verbose()

        bIsTH1 = isinstance(histo, ROOT.TH1)
        if bIsTH1 == False:
            self.Print(["The histogram '%s' is not a ROOT.TH1 instance. Doing nothing" % histo.name])
            return
        histo.GetXaxis().SetLabelSize(0)
        return


    def _RemoveXaxisTitle(self, histo):
        '''
        Removes the x-axis title from the histogram passed as argument.
        '''
        self.Verbose()

        bIsTH1 = isinstance(histo, ROOT.TH1)
        if bIsTH1 == False:
            self.Print(["The histogram '%s' is not a ROOT.TH1 instance. Doing nothing" % histo.name])
            return
        histo.GetXaxis().SetTitleSize(0)
        return


    def _SetLogAxesCanvas(self):
        '''
        Apply axes customisations to a TCanvas.
        '''
        self.Verbose()

        ### Determine whether to set log for y- and x- axis.
        self._SetLogY(self.THDumbie, self.TCanvas)
        self._SetLogX(self.THDumbie, self.TCanvas)
        self._SetLogZ(self.THDumbie, self.TCanvas)
        return


    def _SetLogX(self, histo, PadOrCancas):
        '''
        Determine whether to set log for x-axis.
        '''
        self.Verbose()

        if histo.logX==False:
            return

        ### Set log-scale for x-axis 
        if histo.xMin == None:
            histo.xMin = histo.TH1orTH2.GetXaxis().GetXmin()

        if histo.xMin > 0:
            PadOrCancas.SetLogx(True)
        else:
            raise Exception("Request for TCanvas::SetLogx(True) rejected. The '%s' minimum x-value is '%s'." % (histo.name, histo.xMin))
        return


    def _SetLogY(self, histo, PadOrCancas):
        '''
        Determine whether to set log for y-axis.
        '''
        self.Verbose()

        if histo.logY==False:
            return

        if histo.yMin == None:
            histo.yMin = histo.TH1orTH2.GetMinimum()

        if histo.yMin > 0:
            PadOrCancas.SetLogy(True)
        else:
            raise Exception("Request for TCanvas::SetLogy(True) rejected. The '%s' minimum y-value is '%s'." % (histo.name, histo.yMin))
        return


    def _SetLogZ(self, histo, PadOrCancas):
        '''
        Determine whether to set log for z-axis.
        '''
        self.Verbose()

        if histo.logZ==False or isinstance(histo.TH1orTH2, ROOT.TH2) == False:
            return

        ### Set log-scale for z-axis 
        if histo.zMin == None:
            histo.zMin = histo.TH1orTH2.GetZaxis().GetXmin()

        if histo.zMin > 0:
            PadOrCancas.SetLogz(True)
        else:
            raise Exception("Request for TCanvas::SetLogz(True) rejected. The '%s' minimum z-value is '%s'." % (histo.name, histo.zMin))
        return


    def _SetLogXYRatio(self, histo, PadOrCancas):
        '''
        Determine whether to set log for x-axis.
        '''
        self.Verbose()

        ### Set log-scale for y-axis 
        if histo.logYRatio==True:
            if histo.yMin == None:
                histo.yMin = histo.TH1orTH2.GetMinimum()
            
            if histo.yMin > 0:
                PadOrCancas.SetLogy(True)
            else:
                raise Exception("Request for TCanvas::SetLogy(True) rejected. The '%s' minimum y-value is '%s'." % (histo.name, histo.yMin))

        ### Set log-scale for x-axis 
        if histo.logXRatio==True:
            if histo.xMin == None:
                histo.xMin = histo.TH1orTH2.GetXaxis().GetXmin()

            if histo.xMin > 0:
                PadOrCancas.SetLogx(True)
            else:
                raise Exception("Request for TCanvas::SetLogx(True) rejected. The '%s' minimum x-value is '%s'." % (histo.name, histo.xMin))
        return


    def _SetLogAxes2PadCanvas(self):
        '''
        Apply customisations to a 2-pad TCanvas.
        '''
        self.Verbose()

        ### Determine whether to set log for y- and x- axis.
        self._SetLogY(self.THDumbie, self.PadPlot)
        self._SetLogX(self.THDumbie, self.PadPlot)
        self._SetLogZ(self.THDumbie, self.PadPlot)
        self._SetLogXYRatio(self.THRatio, self.PadRatio)
        return


    def _CreateLegend(self):
        '''
        Create a TLegend, customise it and return it.
        '''
        self.Verbose()
        
        if isinstance(self.TLegend, ROOT.TLegend) == True:
            raise Exception("A TLegend has already been created. Only 1 allowed per Plotter object.")
        else:
            histo = self.THDumbie
            self.TLegend = ROOT.TLegend(histo.xLegMin, histo.yLegMin, histo.xLegMax, histo.yLegMax, self._GetLegendTitle(), "brNDC")
            self._CustomiseLegend()
            self.DrawObjectList.append( self.TLegend )
        return


    def _CustomiseLegend(self):
        '''
        Customise a TLegend.
        '''
        self.Verbose()
        self.TLegend.SetName("legend")
        self.TLegend.SetFillStyle(0)
        self.TLegend.SetLineColor(ROOT.kBlack)
        self.TLegend.SetLineWidth(1)
        self.TLegend.SetBorderSize(0)
        self.TLegend.SetShadowColor(ROOT.kWhite)
        self.TLegend.SetTextSize(0.03)
        self.TLegend.SetTextFont(62)
        #self.TLegend.SetTextAlign(13)
        return


    def _GetLegendTitle(self):
        '''
        Create a TLegend title and return it.
        '''
        self.Verbose()

        legendTitle  = ""
        histo = self.THDumbie         

        ### Create TLegend name
        if len(self.DatasetList) > 1:
            if len(self.THList)==1:
                legendTitle  = histo.legTitle
        elif len(self.DatasetList) == 1 and len(self.THList)==1:
            if histo.legTitle == "" or  histo.legTitle == None:
                legendTitle  = self.DatasetObject.ConvertDatasetToLatex(histo.dataset)
            else:
                legendTitle = histo.legTitle
        else:
            legendTitle  = self.DatasetObject.ConvertDatasetToLatex(histo.dataset)
        return legendTitle


    def AddHisto(self, histoObjectList):
        '''
        Loop over all histogram object in the list. Check that they are of type TH1 or TH2. Get the 
        actual ROOT.TH1 from the root files for all datasets. Assign the "ROOT.TH1", "dataset" and 
        "TFileName" attributes to the histogram objects.        
        '''
        self.Verbose()
        
        ### Sanity check. At least one dataset is present 
        if len(self.DatasetList) < 1:
            raise Exception("No datasets found! Cannot add histograms to the drawing list unless a dataset exists. Please used the Plotter.AddDataset() method before using Plotter.AddHisto().")
        
        ### Copy the histoObjectList
        self.HistoObjectList = copy.deepcopy(histoObjectList)

        ### Loop over all histograms objects in the list
        for histoObject in histoObjectList:
            self.IsTH2 = self.CheckHistoTypeIsCorrect(histoObject)
            if self.IsTH2:
                self.TDRStyleObject.setWide(True)

            ### Loop over all datasets
            for dataset in self.DatasetList:
                f = self.DatasetToTFileMap[dataset]
                self.CheckThatHistoExists(f, histoObject)
                mapKey = dataset + ":" + histoObject.name

                ### Map histo to dataset
                self.Verbose(["Mapping '%s' to key '%s'." % ( histoObject.name, mapKey)])
                self.DatasetToTHMap[mapKey] = copy.deepcopy(histoObject)
                
                ### Get a reference to our mapped histo object 
                h = self.DatasetToTHMap[mapKey]
                if h.path == "" or h.path==None:
                    h.TH1orTH2  = f.Get(h.name)
                else:
                    h.TH1orTH2  = f.Get(h.path + "/" + h.name)
                h.TFileName = f.GetName()
                h.dataset   = dataset
                
                ### Make sure a TH2 is not drawn with more that 1 dataset!
                self._CheckThatNoTH2WithMoreThanOneDatasets(h)

                ### Assign some global values
                self.bPadRatio      = h.ratio
                self.bInvPadRatio   = h.invRatio
                self.RatioErrorType = h.ratioErrorType
                if h.TH1orTH2.Integral() == 0:
                    self.Print(["WARNING! Histogram with zero entries.", "Dataset: '%s'" % (dataset), "HistoName: '%s'" % (h.name), "Integral(): '%s'" % (h.TH1orTH2.Integral()) ])

                ### Save integrals
                h.histoRangeIntegral = h.TH1orTH2.Integral()
                if self.IsTH2 == True:
                    h.inclusiveIntegral  = h.TH1orTH2.Integral(0, h.TH1orTH2.GetNbinsX()+1, 0, h.TH1orTH2.GetNbinsY()+1)
                else:
                    h.inclusiveIntegral  = h.TH1orTH2.Integral(0, h.TH1orTH2.GetNbinsX()+1)

        return


    def AddTreeHisto(self, histoObjectList, GlobalCuts="", myWeights=[""], option= "", nentries= -1, firstentry = 0):    
        '''
        Loop over all histogram object in the list. Check that they are of type TH1 or TH2. Project
        the desired variable expression to a new ROOT.TH1 instance. If TH1::Sumw2 is called before projecting
        the TH1 from the tree, the sum of squares of weights is also stored. Do these for all ROOT.TH1 in the 
        histoObjectList from the root files for all datasets. Assign the "ROOT.TH1", "dataset" and 
        "TFileName" attributes to the histogram objects.
        '''
        self.Verbose()

        ### Copy the histoObjectList
        self.HistoObjectList = copy.deepcopy(histoObjectList)
        
        ### Loop over all histograms objects in the list        
        for histoObject in histoObjectList:
            self.IsTH2 = self.CheckHistoTypeIsCorrect(histoObject)
            if self.IsTH2:
                self.TDRStyleObject.setWide(True)

            ### Loop over all datasets
            for dataset in self.DatasetList:
                f = self.DatasetToTFileMap[dataset]
                self.CheckThatTreeExists(f, histoObject)
                h      = copy.deepcopy(histoObject)
                tree   = f.Get(h.path)
                nBinsX  = int((h.xMax - h.xMin)/h.binWidthX)
                if self.IsTH2 == True:
                    nBinsY  = int((h.yMax - h.yMin)/h.binWidthY)
                mapKey = dataset + ":" + h.name
                self.DatasetToTHMap[mapKey] = copy.deepcopy(histoObject)
                h = self.DatasetToTHMap[mapKey]
                if self.IsTH2 == True:
                    h.TH1orTH2  = ROOT.TH2D( h.name + "_" + dataset, h.name + "_" + dataset, nBinsX, h.xMin, h.xMax, nBinsY, h.yMin, h.yMax)
                else:
                    h.TH1orTH2  = ROOT.TH1D( h.name + "_" + dataset, h.name + "_" + dataset, nBinsX, h.xMin, h.xMax)
                h.TFileName = f.GetName()
                h.dataset   = dataset
                ### Call weights before projecting the histogram
                h.TH1orTH2.Sumw2() 

                ### Assign some global values
                self.bPadRatio      = h.ratio
                self.bInvPadRatio   = h.invRatio
                self.RatioErrorType = h.ratioErrorType

                ### Prepare for TTree Projection
                histoName     = h.TH1orTH2.GetName()
                varExpression = h.treeVarExp
                if h.treeCuts == "" and GlobalCuts == "":
                    selectionCuts = ""
                elif h.treeCuts != "" and GlobalCuts != "":
                    selectionCuts = GlobalCuts + " && " + h.treeCuts
                elif h.treeCuts != "":
                    selectionCuts = h.treeCuts
                elif  GlobalCuts != "":
                    selectionCuts = GlobalCuts
                else:
                    raise Exception("Selected TCuts not valid. Please check your 'histo.treeCuts' expression '%s' and 'GlobalCuts' expression '%s'." % (h.treeCuts, GlobalCuts))

                selectionsAndWeights = selectionCuts + "*".join(myWeights)

                ### Project Histogram
                if nentries == None or nentries == -1:
                    nentries = tree.GetEntries()

                tree.Project(histoName, varExpression, selectionCuts, option, nentries, firstentry)
                #tree.Draw( varExpression + " >>  " + histoName, selectionCuts, option, nentries, firstentry) #can be slow! (plotting script bottleneck)
                #tree.Draw( "x:y")

                ### Save Default integral now!
                h.histoRangeIntegral = h.TH1orTH2.Integral()
                if self.IsTH2 == True:
                    h.inclusiveIntegral  = h.TH1orTH2.Integral(0, h.TH1orTH2.GetNbinsX()+1, 0, h.TH1orTH2.GetNbinsY()+1)
                else:
                    h.inclusiveIntegral  = h.TH1orTH2.Integral(0, h.TH1orTH2.GetNbinsX()+1)

                self.PrintHistoInfo(h, selectionCuts, varExpression)
        return



    def TreeScan(self, rootFilePath, treePath, varExpList=["*"], treeCutList=[""], nEntriesPerPrint=0, layout=""):
        '''
        See: 
        ftp://root.cern.ch/root/doc/ROOTUsersGuideHTML/ch12s20.html
        and:
        http://root.cern.ch/root/html/TTree.html

        Options:
        
        "nEntriesPerPrint": Determines the number of entries to be printed before pausing. The value 0 means to print all without stopping.
        "layout"          : Refers to the layout of the table printed by the TTree::Scan.
                            lenmax=dd    - where 'dd' is the maximum number of elements per array that should be printed. If 'dd' is 0, all elements are printed (default).
                            colsize=ss   - where 'ss' will be used as the default size for all the column. The default column size is 9.
                            precision=pp - where 'pp' will be used as the default 'precision' for the printing format.
                            col=xxx      - where 'xxx' is colon (:) delimited list of printing format for each column.
        For example: tree->Scan("a:b:c","","colsize=30 precision=3 col=::20.10");
        will print 3 columns, the first 2 columns will be 30 characters long, the third columns will be 20 characters long. The printf format for the columns will be %30.3g %30.3g %20.10g.
        '''
        self.Verbose()

        ### Get the TFile of any random dataset
        f    = self.GetTFile(rootFilePath)

        ### Get the TTree
        tree = f.Get(treePath)

        ### Get the variables to be printed
        if len(varExpList) > 1:
            varExpression = ":".join(varExpList)
        else:
            varExpression = varExpList[0]

        ### Take care of the tree cuts
        if len(treeCutList) > 1:
            cutExpression = " && ".join(treeCutList)
        else:
            cutExpression = treeCutList[0]

        ### Scan the TTree
        tree.SetScanField(nEntriesPerPrint)
        tree.Scan(varExpression, cutExpression, layout)
        return


    def PrintHistoInfo(self, histo, selectionCuts, varExpression):
        '''
        '''
        self.Verbose()
                
        if histo.TH1orTH2.Integral() == 0:
            self.Print(["Dataset: '%s'" % (histo.dataset), "Tree: '%s'" % (histo.path), "HistoName: '%s'" % (histo.name), "VarExp: '%s'" % (varExpression), "Selections: '%s'" % (selectionCuts), 
                        "Integral(): '%s'" % (histo.histoRangeIntegral), "Integral(0, nBins+1): '%s'" % (histo.inclusiveIntegral)])
        else:
            self.Verbose(["Dataset: '%s'" % (histo.dataset), "Tree: '%s'" % (histo.path), "HistoName: '%s'" % (histo.name), "VarExp: '%s'" % (varExpression), "Selections: '%s'" % (selectionCuts), 
                        "Integral(): '%s'" % (histo.histoRangeIntegral), "Integral(0, nBins+1): '%s'" % (histo.inclusiveIntegral)])
        return



    def AddTreeHistoForLoop(self, histoObjectList, GlobalCuts="", myWeights=[""], option= "", nentries= -1, firstentry = 0):
        '''
        ftp://root.cern.ch/root/doc/ROOTUsersGuideHTML/ch19.html

        # loop over array tree element
        for d in mychain.mydoubles:
        print d
        
        # direct access into an array tree element
        i5 = mychain.myints[5]
        '''
        self.Verbose()

        ### Copy the histoObjectList
        self.HistoObjectList = copy.deepcopy(histoObjectList)
        
        ### Loop over all histograms objects in the list        
        for histoObject in histoObjectList:
            self.IsTH2 = self.CheckHistoTypeIsCorrect(histoObject)
            
            ### Loop over all datasets
            for dataset in self.DatasetList:
                f = self.DatasetToTFileMap[dataset]
                self.CheckThatTreeExists(f, histoObject)
                h      = copy.deepcopy(histoObject)
                tree   = f.Get(h.path)
                nBins  = int((h.xMax - h.xMin)/h.binWidthX)
                mapKey = dataset + ":" + h.name
                self.Verbose(["Mapping '%s' to key '%s'." % ( h.name, mapKey)])
                self.DatasetToTHMap[mapKey] = copy.deepcopy(histoObject)
                h = self.DatasetToTHMap[mapKey]
                h.TH1orTH2  = ROOT.TH1D( h.name + "_" + dataset, h.name + "_" + dataset, nBins, h.xMin, h.xMax)
                h.TFileName = f.GetName()
                h.dataset   = dataset
                ### Call weights before projecting the histogram
                h.TH1orTH2.Sumw2() 

                ### Assign some global values
                self.bPadRatio      = h.ratio
                self.bInvPadRatio   = h.invRatio
                self.RatioErrorType = h.ratioErrorType
                
                ### Prepare for TTree Projection
                histoName     = h.TH1orTH2.GetName()
                varExpression = h.treeVarExp
                if h.treeCuts == "" and GlobalCuts == "":
                    selectionCuts = ""
                elif h.treeCuts != "" and GlobalCuts != "":
                    selectionCuts = GlobalCuts + " && " + h.treeCuts
                elif h.treeCuts != "":
                    selectionCuts = h.treeCuts
                elif  GlobalCuts != "":
                    selectionCuts = GlobalCuts
                else:
                    raise Exception("Selected TCuts not valid. Please check your 'histo.treeCuts' expression '%s' and 'GlobalCuts' expression '%s'." % (h.treeCuts, GlobalCuts))

                selectionsAndWeights = selectionCuts + "*".join(myWeights)

                ### Project Histogram
                self.TTree = tree
                self.DrawForLoop(h, varExpression, selectionCuts, option, nentries, firstentry)

                ### Save Default integral now!
                h.histoRangeIntegral = h.TH1orTH2.Integral()
                h.inclusiveIntegral  = h.TH1orTH2.Integral(0, h.TH1orTH2.GetNbinsX()+1)

                self.PrintHistoInfo(h, selectionCuts, varExpression)
        return



    def DrawForLoop(self, histoObject, varExp, selectionCuts, option = "", nEntries = -1, firstEntry = 0):
        '''
        '''
        self.Verbose()

        
        ### Determine number of TTree entries to process
        if nEntries == None or nEntries == -1:
            nEntries = self.TTree.GetEntries()

        ### Take care of cut-option
        cutOptions = ["AllBranchEntriesPassCuts", "IndividualBranchEntryPassesCuts"]
        self.CutOption  = option

        if self.CutOption not in cutOptions:
            raise Exception("Invalid cutOption '%s'. Please select one of the following cutOptions:\n\t%s" % (self.CutOption, "\n\t".join(cutOptions) ) )
        else:
            pass

        ### Initialise variables. NOTE: range(startIndex, endIndex) in python stops at endIndex-1. Therefore no need to subtract 1 from nEntries here
        self.TreeStartIndex    = firstEntry
        self.TreeEndIndex      = firstEntry + nEntries
        self.TreeEntries       = nEntries
        funcName    = ""
        bBranchEntryPassedCutsDict = {}

        ### De-couple branch and function from variable expression
        branchName, branchFormula, branchFunction, arrayIndex = self._AppendInfoToBranchLists( varExp )

        ### De-couple branch and function from cut expressions
        cutList, cutDictionary = self.TreeObject.GetCutListFromSelectionCuts(selectionCuts)
        maxPbarValue           = (self.TreeEndIndex - self.TreeStartIndex) * len(self.TBranch) 
        pBar                   = self.AuxObject.StartProgressBar( maxPbarValue )
                       
        ### Loop over all TTree entries
        for iEntry in range(self.TreeStartIndex, self.TreeEndIndex):
                        
            ### Get the desired entry of the TTree
            self.TTree.GetEntry(iEntry)

            ### Skip event if selection cuts are not satisfied 
            bContinue = False
            if cutDictionary:
                bBranchEntryPassedCutsDict = self._ForLoopPassedCutsInEvent(histoObject, iEntry, nEntries, cutDictionary)
                for cut in bBranchEntryPassedCutsDict:
                    bBranchEntryPassedCutsList = bBranchEntryPassedCutsDict[cut]
                    if True not in bBranchEntryPassedCutsList:
                        bContinue = True
                        break
                    else:
                        pass
                if bContinue == True:
                    self.Verbose(["Event: '%i'" % (iEntry), "BranchName: '%s'" % (branchName), "NumOfFillValues: 0"])
                    continue
            else:
                pass

            branch         = self.TBranch[ branchName ]
            branchFunction = self.TBranchFunction[ branchName ] 
            branchFormula  = self.TBranchFormula[ branchName ] 
            branchType, branchEntries = self.GetBranchEntries(branchName)

            self.Verbose( ["Event: '%s'" % (iEntry), "BranchName: '%s'" % (branchName), "BranchEntries: '%s'" % (branchEntries)] )
            self._ForLoopFillTreeHisto(histoObject, selectionCuts, iEntry, nEntries, arrayIndex, branchEntries, branchType, branchName, branchFormula, branchFunction, bBranchEntryPassedCutsDict)

            ### Inform user of current status using a progress bar-
            self.AuxObject.UpdateProgressBar(pBar, iEntry-self.TreeStartIndex)

        pBar = self.AuxObject.StopProgressBar(pBar)
        return
        

    def _AppendInfoToBranchLists(self, varExp ):
        '''
        '''
        self.Verbose()
        
        branchName, branchFormula, branchFunction, arrayIndex = self.TreeObject.GetBranchNameAndFormulaAndFunctionFromVarExp(varExp)
        branch         = self.TTree.GetBranch(branchName)
        branchType     = type(branch)

        if branchName not in self.TBranch:
            self.TBranch[ branchName ]         = branch
            self.TBranchFunction[ branchName ] = branchFunction
            self.TBranchFormula[ branchName ]  = branchFormula
            self.Verbose( ["Branch   : '%s'" % (branchName), "BranchType: '%s'" % (branchType), "Function : '%s'" % (branchFunction)] )
        return branchName, branchFormula, branchFunction, arrayIndex

        
    def _ForLoopPassedCutsInEvent(self, histoObject, iEvent, nEntries, cutDictionary):
        '''
        '''
        self.Verbose()
        
        ### If no selection cuts are defined return true
        if not cutDictionary:
            return True

        branchType      = None
        branchEntries   = None
        bPassedCuts     = True
        arrayIndex      = None
        startIndex      = 0
        endIndex        = 0
        bBranchEntryPassedCutsDict = {}

        ### Skip event if selection cuts are not satisfied 
        for cut in sorted(cutDictionary):
            bBranchEntryPassedCutsList = []            
            varName, varFormula, varFunction, arrayIndex = self.TreeObject.GetBranchNameAndFormulaAndFunctionFromVarExp( cut )
            branchType, branchEntries = self.GetBranchEntries( varName )
            
            ### NOTE: In python, the expression range(startIndex, endIndex) stops at endIndex-1. Therefore no need to subtract 1 from branchEnties below
            if arrayIndex != None:
                startIndex = int(arrayIndex)
                endIndex   = int(arrayIndex)+1
            else:                
                startIndex = 0
                endIndex   = branchEntries 

            if branchEntries == 0:
                self.Verbose( ["Zero Branch entries! Skipping ...", "iEvent: '%s'" % (iEvent) , "Cut: '%s'" % (cutDictionary) ] )
                return bBranchEntryPassedCutsDict
            else:
                pass

            ### Loop over all TBranch entries for a given event and fill corresponding histogram object
            for jBranch in range(startIndex, endIndex):
                if "vector" in str(branchType):
                    if varFunction != None:
                        expression = varName + "[" + str(jBranch) + "]" + "." + varFunction
                    else:
                        expression = varName + "[" + str(jBranch) + "]"
                else:
                    expression = varName + varFunction

                ### Determine and evaluate the variable and cut expressions
                expression  = expression.replace(" ", "")
                varExp      = expression
                cutExp      = expression + cutDictionary[cut]
                varValue    = eval( "self.TTree." + varExp )
                bPassedCuts = eval( "self.TTree." + cutExp )
                bBranchEntryPassedCutsList.append(bPassedCuts)
                self.Verbose( ["Event: '%i/%i'" % (iEvent, self.TreeEndIndex-1), "BranchIndex: '%i/%i'" % (jBranch, endIndex-1), "Selection: '%s'" % (cutExp), 
                             "Variable: '%s' = '%s'" % (varExp, varValue), "Passed: '%s'" % (bPassedCuts), "CutOption: '%s'" % (self.CutOption) ])

            bBranchEntryPassedCutsDict[cut] = bBranchEntryPassedCutsList
        return bBranchEntryPassedCutsDict


    def GetBranchEntries(self, branchName):
        '''
        '''
        self.Verbose()

        branchType = type( eval("self.TTree." + branchName) )

        if "vector" in str(branchType):
            branchEntries =  eval("self.TTree." + branchName + ".size()")
        else:
            branchEntries = 1

        self.Verbose([ "BranchName: '%s'" % (branchName), "BranchType: '%s'" % (branchType), "BranchEntries: '%s'" % (branchEntries) ])
        return branchType, branchEntries


    def _ForLoopFillTreeHisto(self, histoObject, selectionCuts, iEntry, nEntries, arrayIndex, branchEntries, branchType, branchName, branchFormula, branchFunction, bBranchEntryPassedCutsDict):
        '''
        '''
        self.Verbose()

        ### Initialise variables
        bApplyTreeFormula  = False
        fillValuesList     = []
        startIndex         = 0
        endIndex           = 0
        expression         = ""

        if arrayIndex != None:
            startIndex = int(arrayIndex)
            endIndex   = int(arrayIndex)+1
        else:
            startIndex = 0
            endIndex   = branchEntries

        ### If branch has zero entries skip loop
        if  branchEntries <= 0:
            self.Verbose(["Event: '%i/%i'" % (iEntry, self.TreeEndIndex-1), "BranchEntries: '%s'" % (branchEntries), "NumOfFillValues: '%i'" % (len(fillValuesList))])
            return

        if branchFormula==None or branchFormula == "":
            bApplyTreeFormula = False
        else:
            bApplyTreeFormula = True

        ### Loop over all TBranch entries for a given event and fill corresponding histogram object
        for jBranch in range(startIndex, endIndex):

            ### Does this branch pass the cuts? If not continue
            bContinue = False        
            for cut in bBranchEntryPassedCutsDict:
                bBranchEntryPassedCutsList = bBranchEntryPassedCutsDict[cut]
                bBreakLoop = self.SkipThisBranchEntry(bBranchEntryPassedCutsList)
                if bBreakLoop == True:
                    bContinue = True
                    break
                else:
                    if bBranchEntryPassedCutsList[jBranch] == False:
                        bContinue = True
                        break
                    else:
                        pass
            if bContinue == True:
                continue

            ### Now determine the value to fill the histogram with. Treat differently if a TTree formula is applied
            if branchEntries > 1 or "vector" in str(branchType):
                expression = branchName + "[" + str(jBranch) + "]" + "." + branchFunction
            elif branchEntries == 1:
                expression = branchName + "." + branchFunction
            else:
                raise Exception("Unable to determine the fill value of the TBranch with name '%s'" % (branchName) )

            ### Evaluate the fill value
            fillValue = eval( "self.TTree." + expression )            
            fillValuesList.append(fillValue)                        

        if bApplyTreeFormula == True:
            fillValue = self.TreeObject.ApplyTreeFormulaToListOfValues(branchFormula, fillValuesList)
            histoObject.TH1orTH2.Fill( fillValue )
            self.Verbose(["Event: '%i/%i'" % (iEntry, self.TreeEndIndex-1), "BranchIndex: '%i/%i'" % (jBranch, branchEntries-1), "NumOfFillValues: '%i'" % (len(fillValuesList)), "FillValue: '%s'" % (fillValue) ])
        else:
            for val in fillValuesList:
                histoObject.TH1orTH2.Fill( fillValue )
                self.Verbose(["Event: '%i/%i'" % (iEntry, self.TreeEndIndex-1), "BranchIndex: '%i/%i'" % (jBranch, branchEntries-1), "NumOfFillValues: '%i'" % (len(fillValuesList)), "FillValue: '%s'" % (fillValuesList) ])
        return


    def SkipThisBranchEntry(self, bBranchEntryPassedCutsList):
        '''
        '''
        self.Verbose()
        
        ### If no selection cuts are defined return true
        if self.CutOption == "AllBranchEntriesPassCuts":
            if False in bBranchEntryPassedCutsList:
                return True
            else:
                return False
        elif self.CutOption == "IndividualBranchEntryPassesCuts":
            if True in bBranchEntryPassedCutsList:
                return False
            else:
                return True
        else:
            raise Exception("Invalid cutOption '%s'. Please select one of the following cutOptiosn" % (self.CutOption, "\n\t".join(cutOptions) ) )


    def ConvertToRateHistos(self):
        '''
        '''
        self.Verbose()
    
        for mapKey in sorted(self.DatasetToTHMap):
            h = self.DatasetToTHMap[mapKey]
            self._ConvertToRateHisto(h.TH1orTH2)
        return


    def ConvertToEfficiencyHistos(self, cutDirection = ">"):
        '''
        '''
        self.Verbose()
        
        for mapKey in sorted(self.DatasetToTHMap):
            h = self.DatasetToTHMap[mapKey]
            self._ConvertToEfficiencyHisto(h, cutDirection)
        return


    def _ConvertToEfficiencyHisto(self, h, cutDirection):
        '''
        Replaces bin content with the efficiency of the given bin. Cut direction can be chosen.
        '''
        self.Verbose()
        
        self.Print( ["Converting histo '%s' into an efficiency histogram" % ( h.TH1orTH2.GetName() )] )
        ### Change some histoObject attributes
        h.yUnits      = ""
        h.yMax        = 1.05
        h.normaliseTo = None
        h.ratio       = False
        h.invRatio    = False
        h.yLabel      = "Efficiency (" + cutDirection +  ") / % 0.1f"
        if cutDirection == ">":
            h.name        = h.name + "_GreaterThan"
            h.saveName    = h.saveName + "_GreaterThan"
        elif cutDirection == "<":
            h.name        = h.name + "_LessThan"
            h.saveName    = h.saveName + "_LessThan"
        else:
            raise Exception("Invalid cut-direction '%s' selected for efficiency plot. Please select either '<' or '>'." % (cutDirection) )
                
        ### Loop over all histogram bins
        nBins  = h.TH1orTH2.GetNbinsX()
        nTotal = h.TH1orTH2.Integral( 0, nBins+1 )

        ### Loop over all bins and convert their bin content
        for b in range(0, nBins+1):
            
            nPass     = h.TH1orTH2.Integral( b, nBins+1 )
            eff, err  = self.AuxObject.Efficiency(nPass, nTotal, errType = "binomial")
            
            if cutDirection == ">":
                pass
            else:
                eff  = 1-eff
            h.TH1orTH2.SetBinContent( b, eff )
            h.TH1orTH2.SetBinError(   b, err )

        return


    def _ConvertToRateHisto(self, h):
        '''
        This method convert a given histogram to a rate histogram. What it does is simply loop over all bins of a given histogram.
        If the cut conditions are satisfied and if the bin-threshold of a given bin is found to be above an Et threshold, then 
        then bin content is replaced by all entries found to satisfy criteria.
        '''
        self.Verbose()
        self.Print( ["Converting histo '%s' into a rate histogram" % ( h.GetName() )] )

        ### Loop over all histogram bins
        if isinstance(h, ROOT.TH1D) == True:
            nBins = h.GetNbinsX()+1
            for b in range(0, nBins+1):
                h.SetBinContent( b, h.Integral(b, nBins+1) )
                h.SetBinError( b, math.sqrt(h.GetBinContent(b) ) )
        elif isinstance(h, ROOT.TH2D) == True:
            nBinsX = h.GetNbinsX()+1
            nBinsY = h.GetNbinsY()+1
            for bX in range(0, nBinsX+1):
                for bY in range(0, nBinsY+1):
                    # Draw only y<= x values
                    if bY >= bX and self.SaveContourPoints == False: 
                        break
                    else: #if you want to calculate thresholds proceed as normal
                        pass
                    h.SetBinContent( bX, bY, h.Integral(bX, nBinsX+1, bY, nBinsY+1) )
                    h.SetBinError( bX, bY,  math.sqrt( h.GetBinContent(bX, bY) ) )
        else:
            raise Exception("Cannot only convert a TH1D or a TH2D into a rate histogram, but instead got an object of type '%s'." % (type(h) ) )
            
        return


    def _CheckThatNoTH2WithMoreThanOneDatasets(self, histoObject):
        ''''
        Ensure that no TH2 is drawn where more than 1 dataset is created. Very difficult to distinguish so we need to take care.
        '''
        self.Verbose()
        
        hType = type(histoObject.TH1orTH2)
        
        if len(self.DatasetList)>1 and "TH2" in str(hType):
            raise Exception("Cannot draw a TH2 while more than 1 datasets are present.")
        else:
            return


    def CheckHistoTypeIsCorrect(self, histoObject):
        ''''
        Ensure that the histoObject is of valid type (m_histos.TH1 or m_histos.TH2). Raise an exception otherwise.
        '''
        self.Verbose()

        if isinstance(histoObject, m_histos.TH1orTH2):
            self.THList.append(histoObject)
        else:
            raise Exception( "Unknown histo type added. Please make sure the histo object '%s' (type = '%s') is either a TH1 or a TH2" % (histoObject, type(histoObject)) )

        bIsTH2 = False
        if ":" in histoObject.treeVarExp and not "::" in  histoObject.treeVarExp:
            bIsTH2 = True
            self.Print(["histo: '%s'" % (histoObject.name), "treeVarExp: '%s'" % (histoObject.treeVarExp)])
            
        return bIsTH2


    def CheckThatHistoExists(self, rootFile, hObject):
        '''
        Ensure that the histogram you are trying to get from a TFile really exists.
        '''
        self.Verbose()
        
        
        hPath = ""
        if (hObject.path == "") or (hObject.path == None):
            hPath = hObject.name
        else:
            hPath = hObject.path + "/" + hObject.name

        bExistsTH1 = isinstance( rootFile.Get(hPath), ROOT.TH1)
        bExistsTH2 = isinstance( rootFile.Get(hPath), ROOT.TH2)

        if bExistsTH1 == False and bExistsTH2 == False :
            raise Exception( "Could not find histo object '%s' in TFile '%s' under folder '%s'." % (hObject.name, rootFile.GetName(), hObject.path) )
        else:
            self.Verbose(["From '%s', getting histo '%s/%s'." % (rootFile.GetName().rsplit("/", 1)[-1], hObject.path, hObject.name)])
            return


    def CheckThatTreeExists(self, rootFile, histoObject):
        '''
        '''
        self.Verbose()

        bExists = isinstance( rootFile.Get(histoObject.path), ROOT.TTree)
        if bExists == False:
            raise Exception( "Could not find histo TTree '%s' in TFile '%s'." % (histoObject.path, rootFile.GetName()) )
        else:
            self.Verbose(["From '%s', getting TTree '%s'." % (rootFile.GetName().rsplit("/", 1)[-1], histoObject.path)])
            return


    def CreateDumbie(self):
        '''
        Create a dumbie histogram that will be the first to be drawn on each canvas. 
        This should have zero entries but have exactly the same attribues  (binning, axes titles etc..) as the ones to be drawn.
        '''
        self.Verbose()

        myMax = -1E10
        myMin = +1E10
        ### Loop over all TH1's and determine dataset histo with yMax
        for dataset in sorted(self.DatasetToTHMap): #sorted to ensure the first histogram is used in copying (ensures canvas name same everytime)
            h = self.DatasetToTHMap[dataset]
            tmpMax =  h.TH1orTH2.GetMaximum()
            if tmpMax > myMax:
                myMax = h.yMax
                myMin = h.yMin
                self.THDumbie = copy.deepcopy(self.DatasetToTHMap[dataset])                
                self.THDumbie.TH1orTH2.SetName("THDumbie")
            else:
                continue

        ### Reset only Integral, Contents, Errors and Statistics (not Minimum and Maximum)
        self.THDumbie.TH1orTH2.Reset("ICES")

        ### Set custom range for x- and y- axis and pad margins            
        self.THDumbie.TH1orTH2.GetYaxis().SetRangeUser(myMin, myMax)
        self.THDumbie.TH1orTH2.GetXaxis().SetRangeUser(h.xMin, h.xMax) #does nothing if xMax > max x-value when histogram was created

        ### Set Number of divisions! 
        self.THDumbie.TH1orTH2.GetXaxis().SetNdivisions(510)
        #self.THDumbie.TH1orTH2.GetXaxis().SetNdivisions(505)

        ### Set Line Colour and Width
        self.THDumbie.TH1orTH2.SetLineColor(ROOT.kBlack)
        self.THDumbie.TH1orTH2.SetLineWidth(1)

        ### Increase right pad margin to accomodate z-axis scale and title
        if isinstance(self.THDumbie.TH1orTH2, ROOT.TH2) == True:
            ROOT.gStyle.SetPadRightMargin(0.15)
        return
                

    def AppendToDrawObjectList(self, objectToBeDrawn):
        '''
        Append a drawable object of any type (TCanvas, TLegend, TLine, TBox, etc..) to a list.
        This list will be used later on to draw all objects.
        '''
        self.Verbose()

        self.DrawObjectList.append(objectToBeDrawn)
        self.DrawObjectListR.append(copy.deepcopy(objectToBeDrawn))
        return 

        
    def EnableColourPalette(self):
        '''
        Changes colour for each histogram within a given dataset only if 1 dataset is present.
        '''
        self.Verbose()
        
        if len(self.DatasetList)==1:
            self.StyleObject.EnableColourPalette(bEnable=True)
        else:
            self.StyleObject.EnableColourPalette(bEnable=False)
        return


    def _CustomiseHistograms(self):
        '''
        Customise all histograms found inside the DatasetToTHMap.
        '''
        self.Verbose()
        
        ### Loop over all datasets: Ensure that histogram order defined at histogram-list creation time is respected.
        for dataset in self.DatasetList:
        ### Nested loop (over all datasets) over all histograms
            for histo in self.HistoObjectList:
                mapKey = dataset + ":" + histo.name
                h = self.DatasetToTHMap[mapKey]
                h.ApplyStyles( self.StyleObject, type(h.TH1orTH2), len(self.DatasetList) )
        return

    
    def _NormaliseHistograms(self):
        '''
        Normalise all histograms found inside the DatasetToTHMap.
        '''
        self.Verbose()
        
        ### Loop over all histograms and normalise according to user options
        for mapKey in sorted(self.DatasetToTHMap):
            h = self.DatasetToTHMap[mapKey]
            self._NormaliseHisto(h)
        return


    def _NormaliseHisto(self, h):
        '''
        Normalise the histoObject passed to this function according to user-specified criteria. 
        '''
        self.Verbose()
        
        if h.normaliseTo==None:
            return

        scaleFactor = 1
        if h.TH1orTH2.GetEntries() == 0:
            self.Print(["WARNING! Cannot normalise histogram.", "HistoName: '%s'" % (h.name), "Entries: '%s'" % (h.TH1orTH2.GetEntries()), "TFile: '%s'" % (h.TFileName)])
            return

        if h.normaliseTo == "One":
            scaleFactor = h.inclusiveIntegral #Note: Using h.histoRangeIntegral is wrong, as it might depend on histogram binning and maximum of x-axis!
            if scaleFactor!=0:
                h.scaleFactor = 1.0/scaleFactor
                h.TH1orTH2.Scale(h.scaleFactor)
                self.Print( ["Histo: '%s'" % (h.name), "Dataset: '%s'" % (h.dataset), "NormFactor: '%s'" % (scaleFactor)])
            else:
                self.Print(["WARNING! Cannot normalise histogram. Will do nothing.", "HistoName: '%s'" % (h.name), "TFile: '%s'" % (h.TFileName), "ScaleFactor: '%s'" % (scaleFactor)])
                return
        elif h.normaliseTo == "MB@40MHz":
            ConvertRateTokHz  = 1.0E-3
            CrossingRate      = 40.0E+6 #Hz
            MCEventsTotal     = self.DatasetObject.GetEvents(h.dataset)
            scaleFactor       = (CrossingRate)/(MCEventsTotal)*ConvertRateTokHz
            h.scaleFactor     = scaleFactor
            h.TH1orTH2.Scale(scaleFactor)
            self.Print( ["Histo: '%s'" % (h.name), "Dataset: '%s'" % (h.dataset), "Menu: 40 MHZ",  "McEvents: '%s'" % (MCEventsTotal), "NormFactor: '%s'" % (scaleFactor)])
        elif h.normaliseTo == "MB@30MHz":
            ConvertRateTokHz  = 1.0E-3
            CrossingRate      = 30.0E+6 #Hz
            MCEventsTotal     = self.DatasetObject.GetEvents(h.dataset)
            scaleFactor       = (CrossingRate)/(MCEventsTotal)*ConvertRateTokHz
            h.scaleFactor     = scaleFactor
            h.TH1orTH2.Scale(scaleFactor)
            self.Print( ["Histo: '%s'" % (h.name), "Dataset: '%s'" % (h.dataset), "Menu: 30 MHZ",  "McEvents: '%s'" % (MCEventsTotal), "NormFactor: '%s'" % (scaleFactor)])
        elif type(h.normaliseTo) == float:
            h.scaleFactor     = float(h.normaliseTo)
            h.TH1orTH2.Scale(1.0/h.scaleFactor)
        else:
            raise Exception("Unknown histoObject normalisation option '%s'.!" % (h.normaliseTo))
        return


    def Draw(self, THStackDrawOpt="nostack", bStackInclusive=False):
        '''
        Draw all necessary histograms for all datasets.
        '''
        self.Verbose()

        self.bStackInclusive = bStackInclusive
        self.EnableColourPalette()
        self._NormaliseHistograms()
        self._CustomiseHistograms()
        self._CreateCanvasAndLegendAndDumbie()
        self._CheckHistogramBinning()
        self._AddHistogramsToStack()
        self.Verbose(["Drawing histo '%s'" % (self.THDumbie.name), "THStackDrawOpt: '%s'" % (THStackDrawOpt), "bStackInclusive: '%s'" % (bStackInclusive)])
        self._DrawHistograms(THStackDrawOpt)
        self._DrawRatioHistograms()
        self._DrawNonHistoObjects()
        self._CustomiseStack()
        self.THDumbie.TH1orTH2.Draw("same")
        #self.TLegend.Draw("same") #re-draw legend
        return


    def Draw2D(self, THStackDrawOpt, bStackInclusive, ProfileAxis=None, firstBin=1, lastBin=-1):
        '''
        '''
        self.Verbose()

        if ProfileAxis == None:
            self.Draw(THStackDrawOpt, bStackInclusive)
        else:
            self.Draw2DProfile(THStackDrawOpt, bStackInclusive, ProfileAxis, firstBin, lastBin)
        return



    def Draw2DProfile(self, THStackDrawOpt="nostack", bStackInclusive=False, ProfileAxis=None, firstBin=1, lastBin=-1):
        '''
        Draw a ProfileX or ProfileY of a TH2D. Basically, this will plot a weighted 2D histo with a single entry replacing 
        all entries in X (or Y axis). The entry that replaces all other entries in the Profile direction is the average.

        Profile histograms are used to display the mean value of Y and its error for each bin in X. The displayed error is by default the
        standard error on the mean (i.e. the standard deviation divided by the sqrt(n) ). Profile histograms are in many cases an elegant 
        replacement of two-dimensional histograms : the inter-relation of two histogram or scatter-plot; its representation on the line-printer 
        is not particularly satisfactory, except for sparse data. If Y is an unknown (but single-valued) approximate function of X, this function
        is displayed by a profile histogram with much better precision than by a scatter-plot.
        See: http://root.cern.ch/root/html/TProfile.html
        '''
        self.Verbose()

        allowedValues = [None, "x", "y"]
        if ProfileAxis not in allowedValues:
            raise Exception("Invalid ProfileAxis option selected ('%s'). You need to speficy the axis of the Profile (x or y). Available options are 'x' and 'y'." % (ProfileAxis) )

        #self.TDRStyleObject.setWide(True)         
        self.bStackInclusive = bStackInclusive
        self.EnableColourPalette()
        self._NormaliseHistograms()
        self._CustomiseHistograms()
        self._CreateCanvasAndLegendAndDumbie()
        self._CheckHistogramBinning()
        self._AddHistogramsToStack2D(ProfileAxis, firstBin, lastBin)
        self.Verbose(["Drawing histo '%s'" % (self.THDumbie.name), "THStackDrawOpt: '%s'" % (THStackDrawOpt), "bStackInclusive: '%s'" % (bStackInclusive)])
        self._DrawHistograms(THStackDrawOpt)
        self._DrawRatioHistograms()
        self._DrawNonHistoObjects()
        self._CustomiseStack()
        self.THDumbie.TH1orTH2.Draw("same")
        #self.TLegend.Draw("same") #re-draw legend
        return

    def _AddHistogramsToStack2D(self, ProfileAxis, firstBin, LastBin):
        '''
        Add all histograms (except Dumbie) to a THStack. For each histogram add a TLegend entry
        and automatically extend the size of the TLegend to accomodate the next entry.
        '''
        self.Verbose()

        entryLabel = ""
        if  ProfileAxis =="x" or  ProfileAxis =="y":
            bAddLegendEntries = True
        else:
            bAddLegendEntries = False
        self.TCanvas.SetName( self.TCanvas.GetName() + "_Profile%s" % (ProfileAxis.upper()) )

        ### Loop over all datasets: Ensure that histogram order defined at histogram-list creation time is respected.
        for dataset in self.DatasetList:

            ### Nested loop (over all datasets) over all histograms
            for histo in self.HistoObjectList:
                mapKey = dataset + ":" + histo.name

                h = self.DatasetToTHMap[mapKey]

                self.Print( ["Creating Profile%s for histogram '%s'  and adding to THStack." % ( ProfileAxis.upper(), h.name)] )
                if ProfileAxis == "x":
                    hProfileX_Name = h.name +"_ProfileX"
                    hProfileX      = h.TH1orTH2.ProfileX(hProfileX_Name, firstBin, LastBin)
                    self.THStack.Add( hProfileX )
                    self.THStackHistoList.append(hProfileX) #new
                    self.WriteCaloTauEtCorrectionsToFile( h, hProfileX, hProfileX_Name + "_" + dataset )
                else:
                    raise Exception("Although this works, some validation would have to be carried out with a simple a well undestood 2D histo")
                    hProfileY_Name = h.name +"_ProfileY"
                    hProfileY      = h.TH1orTH2.ProfileY(hProfileY_Name + "_" + dataset, firstBin, LastBin)
                    self.THStack.Add( hProfileX )
                    self.THStackHistoList.append(hProfileX) #new
                    self.WriteCaloTauEtCorrectionsToFile( h, hProfileY, hProfileY_Name + "_" + dataset )

                ### Add legend entries for THStack?
                if bAddLegendEntries == True:
                    self.TLegend.AddEntry( h.TH1orTH2, self._GetLegEntryLabel(h), self._GetLegEntryOptions(h) )
                    self.TLegend.SetY1( self.TLegend.GetY1() - 0.02)
                else:
                    pass
        return


    def WriteCaloTauEtCorrectionsToFile(self, histoObject, histo, histoName):
        '''
        '''
        self.Verbose()
        xVals = []
        yVals = []

        for bin in range(1, histo.GetNbinsX(), 1):
            #xValue = histo.GetBinContent(bin)
            xValue = histo.GetXaxis().GetBinCenter(bin)
            yValue = histo.GetBinContent(bin)
            
            ### Store values into arrays
            xVals.append(xValue)
            yVals.append(yValue)

        ### Now write results to a file
        maxDecimals = 2
        fileName    = histoName + ".txt"
        f           = open( fileName, 'w')
        self.Print(["Saving Profile histogram x- and y-values to file '%s'." % (fileName), "Numbers are rounded to '%s' decimal places." % (maxDecimals)])

        ### Define the column widths: 10 each
        template = "{0:20} & {1:20} & {2:20}" + r"\\"

        ### Create the table headers
        pre_header = "\multicolumn{3}{c}{$" + histoObject.legTitle.replace("#", "\\") + "$} " + r"\\"
        header     = template.format("$\eta$", "f", "1/f")
        f.write( r"\begin{tabular}{ %s }" % ( " c " * 3 ) + "\n" )
        f.write( r"\hline"  + "\n" )
        f.write( pre_header + "\n" )
        f.write( header + "\n" )
        f.write( r"\hline"  + "\n" )
     
        ### Now write the actual values
        for x, y  in zip(xVals, yVals):
            
            column1  = str( round( x  , maxDecimals) )
            column2  = str( round( y  , maxDecimals) )
            if y>0.0:
                column3  = str( round( 1.0/y  , maxDecimals) )
            else:
                column3  = "n/a"
            f.write( template.format(column1, column2, column3) + "\n" )
        f.write( r"\hline"  + "\n" )
        f.write( r"\end{tabular}" + "\n" )
        f.close()

        return


    def _AddHistogramsToStack(self):
        '''
        Add all histograms (except Dumbie) to a THStack. For each histogram add a TLegend entry
        and automatically extend the size of the TLegend to accomodate the next entry.
        '''
        self.Verbose()

        bAddLegendEntries = "TH1" in str(type(self.THDumbie.TH1orTH2)) and isinstance(self.TLegend, ROOT.TLegend)
        entryLabel = ""
        
        ### Loop over all datasets: Ensure that histogram order defined at histogram-list creation time is respected.
        for dataset in self.DatasetList:

            ### Nested loop (over all datasets) over all histograms
            for histo in self.HistoObjectList:
                mapKey = dataset + ":" + histo.name

                h = self.DatasetToTHMap[mapKey]
                self.Verbose(["Adding '%s' to the THStack." % (h.name)])
                self.THStack.Add(h.TH1orTH2)
                self.THStackHistoList.append(h.TH1orTH2) #new
                ### Add legend entries for THStack?
                if bAddLegendEntries == True:
                    self.TLegend.AddEntry( h.TH1orTH2, self._GetLegEntryLabel(h), self._GetLegEntryOptions(h) )
                    self.TLegend.SetY1( self.TLegend.GetY1() - 0.02)
                else:
                    pass
        return



    def _CustomiseStack(self):
        '''
        Customise the THStack. Apply x- and y-axis range. Can also implement the inclusive error bar (if histos stacks) in the future,
        by cloning the stack and drawing only the errors with "E1" option?
        '''
        self.Verbose()
        self.THStack.GetYaxis().SetRangeUser(self.THDumbie.yMin, self.THDumbie.yMax)
        self.THStack.GetXaxis().SetRangeUser(self.THDumbie.xMin, self.THDumbie.xMax)
        return


    def _CreateCanvasAndLegendAndDumbie(self):
        '''
        Create a TCanvas, a TLegend, and a dubmie TH1.
        '''
        self.Verbose()

        self.CreateDumbie()
        if self.bPadRatio == True or self.bInvPadRatio == True:
            self._Create2PadCanvas()
        else:
            self._CreateCanvas()

        self._CreateLegend()
        return

        
    def CreateCutLines(self):
        '''
        Create TLines for each cut-line defined by the user when creating a histo instance. 
        Append them to the DrawObjectList so that they can be drawn later on.
        '''
        self.Verbose(["Creating cut-lines."])

        ### Create the TLines for each axis
        self._AppendXYCutLinesToTLineList("x")
        self._AppendXYCutLinesToTLineList("y")
        self._DoZCutLines()

        ### Extend the DrawObjectList with the TLineList
        self.DrawObjectList.extend(self.xTLineList)
        self.DrawObjectList.extend(self.yTLineList)

        self.DrawObjectListR.extend( copy.deepcopy(self.xTLineList) )
        if (self.THDumbie.yCutLinesRatioPad == True):
            self.DrawObjectListR.extend( copy.deepcopy(self.yTLineList) )
        return


    def _AppendXYCutLinesToTLineList(self, axis):
        '''
        Create, customise and append x- or y-axis cut lines to the TLineList. Also add entry to TLegend and provide extra space for another TLegened entry.
        '''
        self.Verbose()

        bXaxisCut = False
        bYaxisCut = False

        if axis == "x":
            bXaxisCut = True
            cLines = self.THDumbie.xCutLines
        elif axis == "y":
            bYaxisCut = True
            cLines = self.THDumbie.yCutLines
        else:
            raise Exception("The option 'axis' can either be \"x\" or \"y\". Passed option was \"%s\"." % (axis) )

        if cLines == None:
            return
                
        ### Loop over all x-axis cut values
        for value in cLines:
            if bXaxisCut == True:
                xMin = value
                xMax = value
            else:
                xMin = self.THDumbie.xMin
                xMax = self.THDumbie.xMax

            if bYaxisCut == True:
                yMin = value
                yMax = value
            else:
                yMin = self.THDumbie.yMin
                yMax = self.THDumbie.yMax

            line = ROOT.TLine(xMin, yMin, xMax, yMax)
            self._CustomiseTLine(line, lineColour=self.CutLineColour, lineWidth=3, lineStyle=ROOT.kSolid)
            if bXaxisCut == True:
                self.TLegend.AddEntry( line, "%s %s" % (value, self.THDumbie.xUnits), "L" )
            else:
                self.TLegend.AddEntry( line, "%s %s" % (value, self.THDumbie.yUnits), "L" )
            self.TLegend.SetY1( self.TLegend.GetY1() - 0.02)
            self.AppendToTLineList( line, axis)

        return


    def _DoZCutLines(self):
        '''
        Create, customise and append z-axis cut lines to the TLineList. Also add entry to TLegend and provide extra space for another TLegened entry.
        "CONT"	 Draw a contour plot (same as CONT0).
        "CONT0"	 Draw a contour plot using surface colors to distinguish contours.
        "CONT1"	 Draw a contour plot using line styles to distinguish contours.
        "CONT2"	 Draw a contour plot using the same line style for all contours.
        "CONT3"	 Draw a contour plot using fill area colors.
        "CONT4"	 Draw a contour plot using surface colors (SURF option at theta = 0).
        "CONT5"	 (TGraph2D only) Draw a contour plot using Delaunay triangles.
        See http://root.cern.ch/root/html/THistPainter.html for contour draw options!
        '''
        self.Verbose()

        zCutLines = self.THDumbie.zCutLines
        if zCutLines == None or len(zCutLines)==0:
            return

        ### Copy list into a numpy array, otherwise ROOT will complain
        contours = numpy.asarray(self.THDumbie.zCutLines)
        if (self.THDumbie.zCutLinesErrors == True):
            self._DrawZCutLinesWithErrors(zCutLines)
        else:
            self.DrawZCutLines(zCutLines)
        return


    def _DrawZCutLinesWithErrors(self, zCutLines):
        '''
        Draw z-cut lines defined by the user at histogram creation time.
        Add error bands around the nominal contour that correspond to +/- 1 sigma.
        For information regarding the extraction of the contours as TGraphs see:
        http://root.cern.ch/root/html/THistPainter.html
        [ Look for Draw("CONT LIST") option ]
        '''
        ### Copy list into a numpy array, otherwise ROOT will complain
        contours = numpy.asarray(self.THDumbie.zCutLines)

        ### Set Contour bands
        contourBands   = [1.0, 1.0/self.THDumbie.scaleFactor, 1.0/self.THDumbie.scaleFactor]
        lineStyles     = [ROOT.kSolid, ROOT.kSolid, ROOT.kSolid] #,ROOT.kDashed, ROOT.kDashed]
        lineColours    = [ROOT.kGray, ROOT.kRed-4, ROOT.kAzure+6, ROOT.kSpring+2, ROOT.kMagenta-2, ROOT.kYellow-4, ROOT.kGray, ROOT.kOrange+8, 
                          ROOT.kBlue-4, ROOT.kGreen-2, ROOT.kViolet-5, ROOT.kPink-8, ROOT.kTeal-1, ROOT.kCyan-7, 
                          ROOT.kGray, ROOT.kRed-4, ROOT.kAzure+6, ROOT.kSpring+2, ROOT.kMagenta-2, ROOT.kYellow-4, ROOT.kGray, ROOT.kOrange+8,
                          ROOT.kBlue-4, ROOT.kGreen-2, ROOT.kViolet-5, ROOT.kPink-8, ROOT.kTeal-1, ROOT.kCyan-7]
        lineShades     = [+0, -3, -3]
        lineWidths     = [+3, +1, +1]
        
        ### Get Last histogram in the stack and customise it
        hStackList = []
        total = len(zCutLines)*len(contourBands)
        for i in range(0, total ):
            hStackList.append(copy.deepcopy(self.THStack.GetStack()))

        ### Declare the arrays where the contours values (nominal, Up, Down) will be saved
        tmpHistoDict = {}

        ### for-Loop: Over all histogram types (Nominal, FluctuateUp, FluctuateDown)
        for iBand in range(0, len(contourBands)): 

            ### Get the total histogram
            h = hStackList[iBand].Last()

            ### Default, Fluctuate up or Fluctuate down
            if iBand == 0:
                histoType = "Nominal"
            elif iBand == 1: # +1sigma
                self.FluctuateHisto(h, contourBands[iBand], True)
                histoType = "FluctuateUp"
            elif iBand == 2: # -1sigma
                self.FluctuateHisto(h, contourBands[iBand], False)
                histoType = "FluctuateDown"
            else:
                pass

            h.SetName(h.GetName() + "_" + histoType )
            tmpHistoList = []

            ### for-Loop: Over all z-cuts, for the given iBand(0 = Nominal, 1 = +1sigma, 2 = -1sigma)
            for i in range(0, len(zCutLines)):
                self.Verbose( ["iHistoType: '%s'/'%s' (Nominal, FluctuateUp, FluctuateDown)" % (iBand+1, len(contourBands) ), "zCutNumber: '%s'/'%s'" % (i+1, len(zCutLines)) ] )
                h.SetLineColor( lineColours[i] )
                h.SetFillColor( lineColours[i] + lineShades[iBand] )
                h.SetLineStyle( lineStyles[iBand] )
                h.SetLineWidth( lineWidths[iBand] )
                h.SetContour(i+1, contours) #should start at 1

                ### Before drawing, save the histogram to some list
                if self.SaveContourPoints == True:
                    tmpHistoList.append(h)

                ### Draw the histogram
                h.Draw("cont3same9")

                if iBand == 0:
                    self.TLegend.AddEntry( h, "%s %s #pm 1#sigma" % (zCutLines[i], self.THDumbie.zUnits), "L" )
                    self.TLegend.SetY1( self.TLegend.GetY1() - 0.02)

            ### Save the Nominal, FluctuateUp, FluctuateDown histos for the specific cut value
            tmpHistoDict[ histoType ] = tmpHistoList

        self.SaveContourPointsToFile(tmpHistoDict)
        return


    def DrawZCutLines(self, zCutLines):
        '''
        Draw z-cut lines defined by the user at histogram creation time.
        '''
        ### Copy list into a numpy array, otherwise ROOT will complain
        contours = numpy.asarray(self.THDumbie.zCutLines)

        ### Set Contour bands
        lineColours    = [ROOT.kWhite, ROOT.kYellow, ROOT.kRed, ROOT.kBlack]
        
        ### Get Last histogram in the stack and customise it
        hStackList = []
        total = len(zCutLines)
        for i in range(0, total ):
            hStackList.append(copy.deepcopy(self.THStack.GetStack()))
        
        ### Loop over all z-cuts
        for i in range(0, len(zCutLines)):
            ### Get the total histogram
            h = hStackList[i].Last()
            h.SetLineColor( lineColours[i] )
            h.SetFillColor( lineColours[i] )
            h.SetLineStyle( ROOT.kSolid )
            h.SetLineWidth( 3 )
            h.SetContour(i+1, contours) #should start at 1
            h.Draw("cont3same9")
            self.TLegend.AddEntry( h, "%s %s" % (zCutLines[i], self.THDumbie.zUnits), "L" )
            self.TLegend.SetY1( self.TLegend.GetY1() - 0.02)
        return



    def FluctuateHisto(self, histo, scaleFactor, bFluctuateUp):
        '''
        Statistical fluctuation of histograms to enable contour error bands.
        '''
        ### Reverse scaleFactor
        histo.Scale( scaleFactor )
        zeroEntriesPoissonError = 1.7 #As instructed by Ptochos

        if "TH1" in str(type(histo)):
            ### Fluctate with bin content with sqrt(N)
            for x in range(0, histo.GetNbinsX()):
                binContent = histo.GetBinContent(x)
                if (bFluctuateUp == True):
                    if binContent < 1.0:
                        histo.SetBinContent(x, histo.GetBinContent(x) + scaleFactor*zeroEntriesPoissonError )
                    else:
                        histo.SetBinContent(x, histo.GetBinContent(x) + scaleFactor*math.sqrt(histo.GetBinContent(x)) )
                else:
                    if binContent > 0.0:
                        histo.SetBinContent(x, histo.GetBinContent(x ) - scaleFactor*math.sqrt(histo.GetBinContent(x)) )
                    else:
                        histo.SetBinContent(x, binContent) # do nothing
        elif "TH2" in str(type(histo)):
            ### Fluctate with bin content with sqrt(N)
            for x in range(0, histo.GetNbinsX()):
                for y in range(0, histo.GetNbinsY()):
                    binContent = histo.GetBinContent(x, y)
                    if (bFluctuateUp == True):
                        if binContent < 1.0:
                            histo.SetBinContent(x, y, histo.GetBinContent(x, y) + scaleFactor*zeroEntriesPoissonError )
                        else:
                            histo.SetBinContent(x, y, histo.GetBinContent(x, y) + scaleFactor*math.sqrt(histo.GetBinContent(x, y)) )
                    elif (bFluctuateUp == False):
                        if binContent > 0.0:
                            histo.SetBinContent(x, y, histo.GetBinContent(x, y) - scaleFactor*math.sqrt(histo.GetBinContent(x, y)) )
                        else:
                            histo.SetBinContent(x, y, binContent) # do nothing
        else:
            raise Exception("Unsupported histo type '%s'. Cannot proceed." % (type(histo) ) )

        ### Scale back to normal
        histo.Scale( 1.0/scaleFactor )
        return
        

    def CreateCutBoxes(self):
        '''
        Create TBoxes with associated TLines (custom colour) for each list of cut-range defined by the user when creating a histo instance. 
        Append them to the DrawObjectList so that they can be drawn later on.
        '''
        self.Verbose()
        
        ### Loop over list of xMin-xMax-colour pairs (also a list)
        self._AppendXYCutBoxesToTBoxList("x")
        self._AppendXYCutBoxesToTBoxList("y")

        ### Extend the DrawObjectList with the TLineList and TBoxList
        self.DrawObjectList.extend(self.xTLineList)
        self.DrawObjectList.extend(self.yTLineList)
        self.DrawObjectList.extend(self.TBoxList)

        self.DrawObjectListR.extend(copy.deepcopy(self.xTLineList))
        if (self.THDumbie.yCutLinesRatioPad == True):
            self.DrawObjectListR.extend(copy.deepcopy(self.yTLineList))
            self.DrawObjectListR.extend(copy.deepcopy(self.TBoxList))
        return


    def _AppendXYCutBoxesToTBoxList(self, axis):
        '''
        Create, customise and append x- or y-axis cut boxes to the TBoxList. Also add entry to TLegend and provide extra space for another TLegened entry.
        '''
        self.Verbose()


        bXaxisCut = False
        bYaxisCut = False
        if axis == "x":
            bXaxisCut = True
            cBoxes = self.THDumbie.xCutBoxes
        elif axis == "y":
            bYaxisCut = True
            cBoxes = self.THDumbie.yCutBoxes
        else:
            raise Exception("The option 'axis' can either be \"x\" or \"y\". Passed option was \"%s\"." % (axis) )

        if cBoxes == None:
            return

        for v in cBoxes:
            if bXaxisCut == True:
                xMin = v[0]
                xMax = v[1]
            else:
                xMin = self.THDumbie.xMin
                xMax = self.THDumbie.xMax

            if bYaxisCut == True:
                yMin = v[0]
                yMax = v[1]
            else:
                yMin = self.THDumbie.yMin
                yMax = self.THDumbie.yMax

            cutBox  = ROOT.TBox( xMin, yMin, xMax, yMax)
            if bXaxisCut == True:
                cLine1  = ROOT.TLine(xMin, yMin, xMin, yMax)
                cLine2  = ROOT.TLine(xMax, yMin, xMax, yMax)
            else:
                cLine1  = ROOT.TLine(xMin, yMin, xMax, yMin)
                cLine2  = ROOT.TLine(xMax, yMax, xMax, yMax)
            cLine1.SetLineColor(v[2])
            cLine2.SetLineColor(v[2])
            cLine1.SetLineWidth(1)
            cLine2.SetLineWidth(1)
            self.TLegend.AddEntry( cLine1, "%s #leq x #leq %s" % (v[0], v[1]), "FL" )
            self.TLegend.SetY1( self.TLegend.GetY1() - 0.02)
            self.AppendToTLineList( cLine1, axis)
            self.AppendToTLineList( cLine2, axis )
            self.AppendToTBoxList(cutBox, boxColour= v[2] )
        return


    def _DrawHistograms(self, THStackDrawOpt):
        '''
        Draw the THDumbie. Draw the THStack . Create the CutBoxes and CutLines. 
        Re-draw the TH1Dubmie to unhide the hidden tickmards (true when drawing histograms 
        will fill style 1001. Draw all objects in the DrawObjectList.
        For drawing options (TH1, TH2, THStack etc..) see:
        http://root.cern.ch/root/html/THistPainter.html
        '''
        self.Verbose()

        self.THDumbie.TH1orTH2.Draw(self.THDumbie.drawOptions)
        self.DrawStackInclusive()
        self.THStack.Draw(self.THDumbie.drawOptions + ",9same," + THStackDrawOpt) #"PADS"
        ROOT.gPad.RedrawAxis() #the histo fill area may hide the axis tick marks. Force a redraw of the axis over all the histograms.
        self.AddDefaultCmsText()
        self.TCanvas.Update()
        self.TCanvas.SetGridx(self.THDumbie.gridX)
        self.TCanvas.SetGridy(self.THDumbie.gridY)
        return


    def _DrawRatioHistograms(self, bAddReferenceHisto=False):
        '''
        Draw all plots on the PadRatio (if applicable).
        For efficiencies and errors see:
        http://steve.cooleysekula.net/goingupalleys/2011/08/09/python-and-root-tricks-efficiency-graphs/
        '''
        self.Verbose()

        if self.bPadRatio == False and self.bInvPadRatio == False:
            return

        self.PadRatio.cd()        

        ### Create the histogram that will divide all other histograms in the THStackRatio (Normalisation histogram)
        UnityTH1 = self.GetUnityTH1()
        hDenominator = copy.deepcopy( self.THStackHistoList[0] ) 
        self.Verbose(["Using histogram '%s' as denominator for ratio plots! " % (hDenominator.GetName())])

        ### Loop over all histograms in the THStack and create the THStackRatio.
        for h in self.THStackHistoList:
            if h == self.THStackHistoList[0]:                
                continue

            ### Copy Active histogram
            hRatio     = copy.deepcopy(h)
            hNumerator = copy.deepcopy(h)

            ### Divide the active histogram with the notmalisation histogram
            hRatio.Divide(hNumerator, hDenominator, 1.0, 1.0, self.RatioErrorType)

            ### Inverts ratio histogram if requested (i.e. each bin has content 1/bin)
            if self.bInvPadRatio == True:
                hRatio.Divide(UnityTH1, hRatio) 

            ### Save histogram values to a txt file (for later processing if needed)
            self.SaveRatioHistoXYValuesToFile(hRatio)

            ### Finally, add this ratio histogram to the THStackRatio
            self.THStackRatio.Add(hRatio)

        ### Customise axes and titles
        self.CustomiseTHRatio()

        ### Draw the Ratio Stack with "nostack" option
        self.THRatio.TH1orTH2.Draw()
        self.THStackRatio.Draw("nostack9sameAP")
        
        ### Finally add the reference ratio plot (to enable the identification of the histogram used for the normalisation)
        ### Note: Do not add the hReference histogram  before calling the function self.CustomiseTHRatio(). 
        if bAddReferenceHisto:
            hReference = copy.deepcopy(hDenominator)
            hReference.Divide(hReference)
            self.THStackRatio.Add(hReference)

        ### Switch back to the PadPlot (necessary)
        self.PadPlot.cd()
        return

    
    def SaveRatioHistoXYValuesToFile(self, h):
        '''
        '''
        self.Verbose()

        xVals     = []
        xErrDown  = []
        xErrUp    = []
        yVals     = []
        yErrDown  = []
        yErrUp    = []

        ### Loop over all histogram bins (except under/over bins)
        binZeroWidth = h.GetXaxis().GetBinWidth(0)
        for iBin in range (1, h.GetNbinsX()+1):

            xVals.append( h.GetBinCenter(iBin) ) #h.GetBinCenter(iBin)
            xErrUp.append( binZeroWidth/2.0 )
            xErrDown.append( binZeroWidth/2.0 )

            yVals.append( h.GetBinContent(iBin) )
            yErrUp.append( h.GetBinErrorUp(iBin) )
            yErrDown.append( h.GetBinErrorLow(iBin) )
        self.SaveTGraphArraysDataToFile( h.GetName() + ".txt", xVals, xErrUp, xErrDown, yVals, yErrUp, yErrDown, 3)
        return



    def CustomiseTHRatio(self):
        '''
        Apply all necessary customisations to self.THRatio histogram.
        '''

        ### Customise axes and titles
        if self.THRatio.yMinRatio == None:
            self.THRatio.yMinRatio = self.THStackRatio.GetMinimum("nostack")*self.THRatio.GetYMinFactor(self.THRatio.logYRatio)
        if self.THRatio.yMaxRatio == None:
            self.THRatio.yMaxRatio = self.THStackRatio.GetMaximum("nostack")*self.THRatio.GetYMaxFactor(self.THRatio.logYRatio)

        ### Customise the title
        self.THRatio.TH1orTH2.GetXaxis().SetTitleOffset(3.1)
        if self.THRatio.ratioLabel == None:
            if self.bInvPadRatio == False:
                self.THRatio.ratioLabel = "Ratio"
            else:
                self.THRatio.ratioLabel = "1/Ratio"
        self.THRatio.TH1orTH2.GetYaxis().SetTitle(self.THRatio.ratioLabel)

        ### Customise the y-axis
        self.THRatio.yMax = self.THRatio.yMinRatio
        self.THRatio.yMin = self.THRatio.yMaxRatio
        #self.THRatio.TH1orTH2.GetYaxis().SetNdivisions(510) 
        self.THRatio.TH1orTH2.GetYaxis().SetNdivisions(505) 
        self.THRatio.TH1orTH2.GetYaxis().SetRangeUser(self.THRatio.yMinRatio, self.THRatio.yMaxRatio)
        self.THRatio.TH1orTH2.GetYaxis().SetTitleOffset(1.8) 
        self.THDumbie.TH1orTH2.GetYaxis().SetTitleOffset(1.8)

        ### Enable grid to easy readout of histo
        self.PadRatio.SetGridx(self.THDumbie.gridX)
        self.PadRatio.SetGridy(self.THDumbie.gridY)
        return


    def DrawStackInclusive(self):
        '''
        The GetStack function returns a TObjArray* of TH1* where the TH1 at index i is the sum of histograms 0->i.
        TObjArray::Last() returns the last TH1 in the list, hence the sum of all TH1.
        For help see: http://root.cern.ch/phpBB3/viewtopic.php?f=3&t=12138
        '''
        self.Verbose()
        if self.bStackInclusive==False:
            return

        inclusive = self.THStack.GetStack().Last()
        inclusive.SetFillStyle(0)
        inclusive.SetFillColor(ROOT.kGray)
        inclusive.SetLineColor(ROOT.kGray)
        inclusive.SetLineStyle(ROOT.kSolid)
        inclusive.SetLineWidth(3)

        if self.THDumbie.yMax < inclusive.GetMaximum():
            yMaxNew = inclusive.GetMaximum()
            h       = self.THDumbie
            h.yMax  = yMaxNew*h.GetYMaxFactor(self.THDumbie.logY)
            h.TH1orTH2.GetYaxis().SetRangeUser(h.yMin, h.yMax)        
        else:
            pass
        inclusive.Draw("HISTsame9")
        
        ### Add histogram entry to the legend
        self.TLegend.AddEntry( inclusive, "inclusive", "L" )
        self.TLegend.SetY1( self.TLegend.GetY1() - 0.02)

        return

    
    def _GetLegEntryLabel(self, histoObject):
        '''
        Determine and retrun the TLegenend entry label for this instance of histogram object.
        '''
        self.Verbose()

        entryLabel = None

        if len(self.THList)==1: 
            entryLabel = self.DatasetObject.ConvertDatasetToLatex(histoObject.dataset)
        else:
            entryLabel = histoObject.legTitle

        if isinstance(entryLabel, str) == True:
            return entryLabel
        else:
            raise Exception("The TLegend entry label cannot be returned as it is not of type string but instead of type '%s'." % ( type(entryLabel) ) )
 

    def _GetLegEntryOptions(self, histoObject):
        '''
        Determine the draw options for all histograms in the THStack by examining the TLegend entry styles:
        "L": draw line associated with TAttLine if obj inherits from TAttLine
        "P": draw polymarker associated with TAttMarker if obj inherits from TAttMarker
        "F": draw a box with fill associated wit TAttFill if obj inherits TAttFill
        "E": draw vertical error bar
        '''
        self.Verbose()
        
        if self.bPadRatio == False and  self.bInvPadRatio == False:
            options = histoObject.legOptions
        else:
            options = histoObject.legOptions + "P"
        return options


    def AppendToTLineList(self, line, axis):
        '''
        Append a TLine to the TLineList. 
        '''
        self.Verbose()

        if axis == "x":
            self.xTLineList.append(line)
        elif axis == "y":
            self.yTLineList.append(line)
        else:
            raise Exception("The option 'axis' can either be \"x\" or \"y\". Passed option was \"%s\"." % (axis) )

        return


    def _CustomiseTLine(self, line, lineColour=ROOT.kBlack, lineWidth=3, lineStyle=ROOT.kSolid):
        '''
        '''
        self.Verbose()

        line.SetLineWidth(lineWidth)
        line.SetLineStyle(lineStyle)
        line.SetLineColor(lineColour)
        line.Draw()
        return


    def AppendToTBoxList(self, box, boxColour=18):
        '''
        Append a TBox to the TBoxList. 
        '''
        self.Verbose()

        box.SetFillStyle(3001) #1001, 3002
        box.SetFillColor(boxColour)
        self.TBoxList.append(box)
        return


    def _DrawNonHistoObjects(self):
        '''
        Draw all drawable objects found in self.DrawObjectList.
        '''
        self.Verbose()                

        if (self.bPadRatio == True or self.bInvPadRatio == True):
            self._DrawNonHistoObjectsWithPadRatio()
        else:
            self._DrawNonHistoObjectsNoPadRatio()        
        return


    def _DrawNonHistoObjectsNoPadRatio(self):
        '''
        Draw all drawable objects found in self.DrawObjectList.
        '''
        self.Verbose()                

        ### First create the draw objects (TLines, TBoxes etc..)
        self.CreateCutBoxes()
        self.CreateCutLines()
        
        ### Draw all objects on the PadPlot
        for o in self.DrawObjectList:
            o.Draw("same")
        return


    def _DrawNonHistoObjectsWithPadRatio(self):
        '''
        Draw all drawable objects found in self.DrawObjectList.
        '''
        self.Verbose()                

        ### First create the draw objects (TLines, TBoxes etc..)
        self.CreateCutBoxes()
        self.CreateCutLines()
        
        ### Draw all objects on the PadPlot
        self.PadPlot.cd()
        for o in self.DrawObjectList:
            o.Draw("same")

        ### Update modified canvas and re-draw the PadPlot axes
        self.PadPlot.Modified()
        self.PadPlot.RedrawAxis()
        self.PadPlot.SetGridx(self.THDumbie.gridX)
        self.PadPlot.SetGridy(self.THDumbie.gridY)

        self.PadRatio.Modified()
        self.PadRatio.RedrawAxis()


        ### Draw all objects on the PadRatio
        self.PadRatio.cd()
        for o in self.DrawObjectListR:
            if isinstance(o, ROOT.TLegend) == True:
                continue

            if ( ( o.GetY1() != o.GetY2() ) and (o.GetX1() == self.THRatio.xMin ) and ( self.THRatio.xMax == o.GetX2() ) ):
                continue
            elif( o.GetX1() == o.GetX2() ):
                o.SetY1(self.THDumbie.yMinRatio)
                o.SetY2(self.THDumbie.yMaxRatio)
            else:
                #o.SetY1(self.THDumbie.yMinRatio)
                #o.SetY2(self.THDumbie.yMaxRatio)
                continue
            o.Draw("same")

        ### Update modified canvas and re-draw the PadPlot axes
        self.PadRatio.Modified()
        self.PadRatio.RedrawAxis()
        
        self.PadPlot.cd()
        return

    
    def _CheckHistoBinning(self, histoObject):
        '''
        Ensure that the histoObject has exactly the same binning as the TH1Dubmie.
        '''
        self.Verbose()

        binningIsOk       = False
        binWidthX         = self.THDumbie.binWidthX
        binZeroWidth      = self.THDumbie.TH1orTH2.GetXaxis().GetBinWidth(0)
        tmpBinWidthX      = histoObject.binWidthX
        tmpBinZeroWidth   = histoObject.TH1orTH2.GetXaxis().GetBinWidth(0)
        if (tmpBinWidthX != binWidthX or tmpBinZeroWidth!=binZeroWidth):
            raise Exception("At least one of the histogram in the plotting queue has a different x-axis binning! Please make sure all your histogram bins are identical.")
        return 


    def _CheckHistogramBinning(self):
        '''
        Ensure that all histoObjects have exactly the same binning as the TH1Dubmie.
        '''
        self.Verbose()

        binningIsOk  = False
        binWidthX    = self.THDumbie.binWidthX
        binZeroWidth = self.THDumbie.TH1orTH2.GetXaxis().GetBinWidth(0)
        
        ### Check that the x-axis bin is same for all histograms
        for mapKey in sorted(self.DatasetToTHMap):
            h = self.DatasetToTHMap[mapKey]
            self._CheckHistoBinning(h)
        return 


    def AddDefaultCmsText(self):
        '''
        Add the default CMS text on the canvas. Several defaults are available. 
        For available options see the class TextClass(object) under tools/text.py.
        '''
        self.Verbose()
        
        self.TCanvas.cd()
        self.TextObject.AddEnergyText( text = " " ) #text = "#sqrt{s}=14 TeV" )
        #self.TextObject.AddCmsSimulationText( text = None )
        self.TextObject.AddCmsSimulationPhaseTwoText(self.IsTH2)
        #self.TextObject.AddCmsPreliminarySimulationPhaseTwoText()
        self.TextObject.AddIntLumiText( text = "" )

        self.TCanvas.Update()
        return
    

    def SaveHistos(self, bSave=False, savePath=os.getcwd() + "/", saveFormats=[".png", ".C", ".eps", ".pdf"]):
        '''
        Save all canvases to specified path and with the desirable format.
        '''
        self.Verbose()
        
        
        if bSave == False:
            return
        else:
            saveName = savePath + self.TCanvas.GetName()
            
        ### Sanity check
        if savePath == "" or savePath == None:
            savePath = os.getcwd() + "/"

        if os.path.exists(savePath) == False: 
            raise Exception("The path '%s' does not exist! Please make sure the provided path is correct." % (savePath) )

        self.Print(["Destination: '%s'" % (savePath), "SaveName: '%s' " % (saveName), "Formats: '%s' " % (saveFormats)])
        for ext in saveFormats:
            self.TCanvas.Update()
            self.TCanvas.SaveAs( saveName + "." + ext )

        return


    def GetCanvasName(self):
        '''
        Return canvas name upon which the plotter objects histograms will be saved on.
        '''
        self.Verbose()
        
        return self.TCanvas.GetName()


    def GetUnityTH1(self):
        '''
        Returns a TH1 with identical attributes to those of self.TH1Dubmie. But, all its bins
        are filled with 1. So you have a flat distribution histogram at y=1, over the entire x-axis range.
        '''
        self.Verbose()
        hUnity = copy.deepcopy(self.THRatio)
        hUnity.TH1orTH2.Reset()

        nBins = hUnity.TH1orTH2.GetNbinsX()
        for i in range (0, nBins+1):
            #hUnity.TH1orTH2.Fill(i, 1) # error bars are quite large. need to investigate if they are correct.
            ### In the meantime, set the bin-error to zero. I think this is the correct way to do it
            hUnity.TH1orTH2.SetBinContent(i, 1)
            hUnity.TH1orTH2.SetBinError(i, 0)
            
        return hUnity.TH1orTH2


    def PrintPSet(self, psetFolderPath, rootFileName = None):
        ''' 
        Print the PSet used when generating a particular ROOT file.
        '''

        self.Verbose()

        ### Loop over all datasets
        if rootFileName == None:

            if len(self.DatasetList) < 1:
                raise Exception("Cannot find PSets as no datasets are available. Either add a dataset or provide explicitly the ROOT file you want to read the PSets from." )
            else:
                for dataset in self.DatasetList:
                    f     = self.DatasetToTFileMap[dataset]
                    named = f.Get(psetFolderPath)
                    rootFileName = f.GetName()
                    break
        else:
            named = self.GetTFile(rootFileName).Get(psetFolderPath)

        self.Print(["Printing PSets for ROOT file '%s':" % (rootFileName), named.GetTitle() ])
        return



    def SaveTriggerEfficienciesToFile(self, treePath, triggerHisto, preSelections, selections, etValueList, etStepList, savePath, bDiTau = False):
        '''
        '''
        self.Verbose()
        
        ### Variable declaration
        nPass               = -1
        nTotal              = -1
        self.Verbose(["Looping over '%s' dataset(s)" % ( len(self.DatasetList) ) ])

        ### Loop over all datasets
        for dataset in self.DatasetList:
            f    = self.DatasetToTFileMap[dataset]
            tree = f.Get(treePath)

            ### Declare a new list for each dataset
            effVals = []
            effErrs = []
            
            ### Loop over all etThresholds
            for val in etValueList:

                if bDiTau:
                    ### Combine cuts if necessary
                    if selections == None or selections == "":
                        mySelections = triggerHisto.treeVarExp.rsplit(":", 1)[0] + " > " + str(val) + " && " + triggerHisto.treeVarExp.rsplit(":", 1)[-1] + " > " + str(val) 
                    else:
                        mySelections = triggerHisto.treeVarExp.rsplit(":", 1)[0] + " > " + str(val) + " && " + triggerHisto.treeVarExp.rsplit(":", 1)[-1] + " > " + str(val) + " && " + selections
                else:
                    ### Combine cuts if necessary
                    if selections == None or selections == "":
                        mySelections = triggerHisto.treeVarExp + ">" + str(val)
                    else:
                        mySelections = triggerHisto.treeVarExp + ">" + str(val) + " && " + selections

                ### Calculate efficiency and its error
                #self.TreeObject.bVerbose = True
                nPass, nTotal          = self.TreeObject.TreePassFailCut(tree, preSelections, mySelections )
                eff, err               = self.AuxObject.Efficiency(nPass, nTotal, errType = "binomial")
                self.Verbose(["dataset: '%s'" % (dataset), "preSelections: '%s'" % (preSelections), "selections: '%s'" % (selections), "efficiency: '%s'+/-'%s'" % ( eff, err) ])
                effVals.append(eff)
                effErrs.append(err)

            self.Verbose(["Saving trigger efficiencies for dataset '%s' to file '%s'" % ( dataset, savePath ) ])
            columnWidths = ["15" for i in range(0, 2*3)] #xenios: x*3, y*3

            columnTitles = []
            columnTitles.append("x")
            columnTitles.append("x+")
            columnTitles.append("x-")
            columnTitles.append("y")
            columnTitles.append("y+")
            columnTitles.append("y-")
            
            columnValues = []
            columnValues.append(etValueList)
            columnValues.append(etStepList)
            columnValues.append(etStepList)
            columnValues.append(effVals)
            columnValues.append(effErrs)
            columnValues.append(effErrs)

            self.AuxObject.SaveListsToFile(savePath + "Eff_" + triggerHisto.name + ".txt", columnWidths, columnTitles, columnValues, nDecimals=3, delimiter = "~", align = " c ", bLatexTable = True)
        return


    def GetTriggerEfficiencies(self, triggerName, preSelections, selectionsList, etThresholds, treePath = "TauTriggerTree/eventTree"):
        '''
        Calculates the efficiency of a given set of selections (TTree cuts) when applied to a TTree. 
        The TTree could be  pre-filtered to some set of pre-selections (if needed). 
        Returns  per-event efficiencies of the selections (preSelections are applied before the calculation).       
        '''
        self.Verbose()
        
        ### Variable declaration
        nPass               = -1
        nTotal              = -1
        effValsToDatasetMap = {}
        effErrsToDatasetMap = {}
        effEtThresholdsToDatasetMap = {}

        self.Verbose(["Looping over '%s' dataset(s) and '%s' threshold(s)" % ( len(self.DatasetList), len(etThresholds) ) ])
        ### Loop over all datasets
        for dataset in self.DatasetList:
            f    = self.DatasetToTFileMap[dataset]
            tree = f.Get(treePath)

            ### Declare a new list for each dataset
            effVals = []
            effErrs = []
            
            ### Loop over all etThresholds
            for threshold in etThresholds:

                ### Remove escape characters (relevant only when reading values from a file)
                threshold  = threshold.replace("\n", "").replace("\t", "")
                
                if selectionsList == None or len(selectionsList) == 0:
                    selectionsList = [""]
                ### Loop over all selections (i.e. Triggers)
                for mySelections in selectionsList:

                    if mySelections != "":
                        selections     = mySelections + " && " + threshold
                    else:
                        selections     = threshold
                        
                ### Calculate efficiency and its error
                #self.TreeObject.bVerbose = True
                nPass, nTotal          = self.TreeObject.TreePassFailCut(tree, preSelections, selections )
                eff, err               = self.AuxObject.Efficiency(nPass, nTotal, errType = "binomial")
                self.Verbose(["dataset: '%s'" % (dataset), "preSelections: '%s'" % (preSelections), "selections: '%s'" % (selections), "efficiency: '%s'+/-'%s'" % ( eff, err) ])
                effVals.append(eff)
                effErrs.append(err)

            self.Verbose(["Creating efficiency map for dataset '%s'" % ( dataset ) ])
            effValsToDatasetMap[ dataset + ":" + triggerName ] = effVals
            effErrsToDatasetMap[ dataset + ":" + triggerName ] = effErrs
            effEtThresholdsToDatasetMap[ dataset + ":" + triggerName ] = etThresholds
        return  effValsToDatasetMap, effErrsToDatasetMap, effEtThresholdsToDatasetMap


    def GetTriggerEfficienciesDiTau(self, triggerName, preSelections, selectionsList, treePath = "TauTriggerTree/eventTree"):
        '''
        '''
        self.Verbose()

        ### Variable declaration
        nPass               = -1
        nTotal              = -1
        effValsToDatasetMap = {}
        effErrsToDatasetMap = {}
        #self.TreeObject.bVerbose = True

        self.Verbose(["Looping over '%s' dataset(s)" % ( len(self.DatasetList) )])
        ### Loop over all datasets
        for dataset in self.DatasetList:
            f    = self.DatasetToTFileMap[dataset]
            tree = f.Get(treePath)

            ### Declare a new list for each dataset
            effVals = []
            effErrs = []
            
            ### Loop over all selections (i.e. Triggers)
            for mySelections in selectionsList:
                
                ### Calculate efficiency and its error
                nPass, nTotal          = self.TreeObject.TreePassFailCut(tree, preSelections, mySelections )
                eff, err               = self.AuxObject.Efficiency(nPass, nTotal, errType = "binomial")
                self.Verbose(["dataset: '%s'" % (dataset), "efficiency: '%s'+/-'%s'" % ( eff, err) ])
                effVals.append(eff)
                effErrs.append(err)

            self.Verbose(["Creating efficiency map for dataset '%s'" % ( dataset ) ])
            effValsToDatasetMap[ dataset + ":" + triggerName ] = effVals
            effErrsToDatasetMap[ dataset + ":" + triggerName ] = effErrs

        return effValsToDatasetMap, effErrsToDatasetMap


    def SaveEtVsRatesTableToFile(self, mySavePath, inputFilePath=None):
        '''
        '''
        self.Verbose()

        if inputFilePath!=None:
            return self.GetEtVsRatesTableFromFile(inputFilePath)

        ### Variable declaration
        rateVals       = self.GetRateValuesList()
        treeVarExp     = []
        selections     = []
        thresholds     = []
        thresholdsUp   = []
        thresholdsDown = []
        rateValsUp     = []
        rateValsDown   = []        
        hName  = ""

        ### Loop over all datasets and get corresponding histograms
        for dataset in sorted(self.DatasetToTHMap): 
            
            ### Get histograms that will be used to determine the thresholds and its errors
            histo  = self.DatasetToTHMap[dataset]
            h      = histo.TH1orTH2
            hUp    = copy.deepcopy(h) 
            hDown  = copy.deepcopy(h) 
            hName  = histo.name  + "_" + histo.dataset

            self.FluctuateHisto(hUp, 1.0/self.THDumbie.scaleFactor, True)
            self.FluctuateHisto(hDown, 1.0/self.THDumbie.scaleFactor, False)

            nBins = h.GetNbinsX()
            ### Loop over all rate thresholds that the user has defined in the "targetRates" list
            for rateThreshold in rateVals:

                self.Verbose( ["Attempting to determine eT threshold for target rate '%s'" % (rateThreshold) ])

                ### Find et-threshold where rate target threshold is met. Save the error in the rate (fluctuate the rate histo up and down)
                iBin, etThreshold, rate = self.FindFirstBinBelowValue(h, rateThreshold)
                thresholds.append( etThreshold )

                iBin, etThresholdUp, rateUp = self.FindFirstBinBelowValue(hUp, rateThreshold)
                thresholdsUp.append( etThresholdUp )
                errUp = abs( rateThreshold - rateUp )
                rateValsUp.append( errUp )

                iBin, etThresholdDown, rateDown = self.FindFirstBinBelowValue(hDown, rateThreshold)
                thresholdsDown.append( etThresholdDown )
                errDown = abs( rateThreshold - rateDown )
                rateValsDown.append( errDown )

            ### Save the selections (TTree cuts) that correspond to this etThreshold
            for i in range(0, len(thresholds) ):
                selections.append(histo.treeCuts)
                treeVarExp.append(histo.treeVarExp + " >= ")

            columnTitles = []
            columnTitles.append("Selections")
            columnTitles.append("TreeVarExp")
            columnTitles.append("eT  (GeV)")
            columnTitles.append("eT+ (GeV)")
            columnTitles.append("eT- (GeV)")
            columnTitles.append("rate  (kHz)")
            columnTitles.append("rate+ (kHz)")
            columnTitles.append("rate- (kHz)")
            
            columnValues = []
            columnValues.append(selections)
            columnValues.append(treeVarExp)
            columnValues.append(thresholds)
            columnValues.append(thresholdsUp)
            columnValues.append(thresholdsDown)
            columnValues.append(rateVals)
            columnValues.append(rateValsUp)
            columnValues.append(rateValsDown)

            columnWidths = []
            columnWidths.append("10")
            columnWidths.append("30")
            columnWidths.append("15")
            columnWidths.append("15")
            columnWidths.append("15")
            columnWidths.append("15")
            columnWidths.append("15")
            columnWidths.append("15")

            filePath = mySavePath + hName + ".txt"
            self.AuxObject.SaveListsToFile(filePath, columnWidths, columnTitles, columnValues, nDecimals=1, delimiter = "~", align = " c ", bLatexTable = True)

            ### Reset variables
            treeVarExp     = []
            selections     = []
            thresholds     = []
            thresholdsUp   = []
            thresholdsDown = []
            rateValsUp     = []
            rateValsDown   = []        

        return selections, treeVarExp, thresholds, thresholdsUp, thresholdsDown, rateVals, rateValsUp, rateValsDown



    def GetEtVsRatesTableFromFile(self, filePath):
        '''
        '''
        self.Verbose()

        if os.path.exists(filePath) == False:
            raise Exception("File '%s' does not exist! Please make sure the provided path for the file is correct." % (filePath) )

        listOfLists = self.AuxObject.ReadListsFromFile(filePath, delimiter = "~")

        ### Remove first element of each list as it contains the title!
        for l in listOfLists:
            del l[0]
            
        ### Assign lists
        selections     = listOfLists[0]
        treeVarExp     = listOfLists[1]
        thresholds     = listOfLists[2]
        thresholdsUp   = listOfLists[3]
        thresholdsDown = listOfLists[4]
        rateVals       = listOfLists[5]
        rateValsUp     = listOfLists[6]
        rateValsDown   = listOfLists[7]

        return selections, treeVarExp, thresholds, thresholdsUp, thresholdsDown, rateVals, rateValsUp, rateValsDown


    def GetEtVsRatesTableFromFileDiTau(self, filePath, delimiter = ":"):
        '''
        '''
        self.Verbose()

        if os.path.exists(filePath) == False:
            raise Exception("File '%s' does not exist! Please make sure the provided path for the file is correct." % (filePath) )

        listOfLists = self.AuxObject.ReadListsFromFile(filePath, delimiter)

        ### Remove first element of each list as it contains the title!
        for l in listOfLists:
            del l[0]
            
        ### Assign lists
        ldgEt          = listOfLists[0]
        ldgEtUp        = listOfLists[1]
        ldgEtDown      = listOfLists[2]
        subLdgEt       = listOfLists[3]
        subLdgEtUp     = listOfLists[4]
        subLdgEtDown   = listOfLists[5]
        rates          = listOfLists[6]
        ratesUp        = listOfLists[7]
        ratesDown      = listOfLists[8]
        return ldgEt, ldgEtUp, ldgEtDown, subLdgEt, subLdgEtUp, subLdgEtDown, rates, ratesUp, ratesDown


    def CustomiseTGraph(self, graph, histoObject, dataset, kwargs):
        '''
        '''
        self.Verbose()
        
        ### Once drawn, the TGraph can be customised
        if kwargs.get("xMin") != None and kwargs.get("xMax") != None:
            graph.GetXaxis().SetRangeUser( kwargs.get("xMin"), kwargs.get("xMax") ) 
            #graph.GetXaxis().SetLimits(kwargs.get("xMin"), kwargs.get("xMax") ) #doesn't work as good as I expected
        if kwargs.get("yMin") != None and kwargs.get("yMax") != None:
            graph.GetYaxis().SetRangeUser( kwargs.get("yMin"), kwargs.get("yMax") ) 
            graph.GetYaxis().SetLimits( kwargs.get("yMin"), kwargs.get("yMax") ) 
        
            
        ### Customise TGraph (colours/styles)
        if dataset == None:
            raise Exception("Could not determine dataset('%s'). Cannot continue." % (dataset) )
        elif ":" in dataset:
            styleType = dataset.rsplit(":", 1)[0].lower()    
        else:
            styleType = dataset

        (fillColour, lineColour, markerStyle, markerSize, lineWidth, lineStyle, fillStyle, drawOptions, legOptions) = self.StyleObject.GetTGraphStyles( styleType )
        graph.SetFillColor(fillColour)
        graph.SetFillStyle(fillStyle)
        graph.SetLineColor(lineColour)
        graph.SetLineStyle(lineStyle)
        graph.SetLineWidth(lineWidth)
        graph.SetMarkerColor(fillColour)
        graph.SetMarkerStyle(markerStyle)
        #marker.SetMarkerColorAlpha(fillColour, 0.35) #0=fully transparent, 1=fully opaque
        graph.SetMarkerSize(markerSize)
        
        ### Create legend if there isn't one already
        if self.TLegend == None:
            if ":" in dataset:
                datasetLatex = self.DatasetObject.ConvertDatasetToLatex( dataset.rsplit(":", 1)[0] )
            else:
                datasetLatex = self.DatasetObject.ConvertDatasetToLatex( dataset )
            self.TLegend = ROOT.TLegend( kwargs.get("xLegMin"), kwargs.get("yLegMin"), kwargs.get("xLegMax"), kwargs.get("yLegMax"), datasetLatex, "brNDC")
            self._CustomiseLegend()
            
        ### Add TGraph entry to legend
        self.TLegend.AddEntry( graph, histoObject.legTitle, kwargs.get("legOptions") )
        self.TLegend.SetY1( self.TLegend.GetY1() - 0.02)
        return        
        

    def DrawMGraph(self, bSave, savePath, saveFormats, **kwargs):
        '''
        Draws a ROOT.TMultiGraph object that has been created before-hand, using the options provided with the keywords arguments.
        '''
        self.Verbose()
        
        ### Create canvas
        self.TCanvas = ROOT.TCanvas( kwargs.get("saveName"), kwargs.get("saveName"), 1)
        self.TCanvas.cd()

        ### Draw the multigraph and customise it 
        self.Verbose(["Drawing ROOT.TMultiGraph '%s'" % self.TMultigraph.GetName() ])
        self.TMultigraph.Draw( kwargs.get("drawOptions") )
        self.CustomiseMGraph(kwargs)

        ### Loop over all y-axis cut values
        if kwargs.get("yCutLines"):
            for value in kwargs.get("yCutLines"):
                xMin = self.TMultigraph.GetXaxis().GetBinUpEdge(1)
                xMax = self.TMultigraph.GetXaxis().GetBinUpEdge(self.TMultigraph.GetXaxis().GetNbins())
                line = ROOT.TLine( xMin, value, xMax, value)
                self._CustomiseTLine(line, lineColour=self.CutLineColour, lineWidth=3, lineStyle=ROOT.kSolid)
                self.TLegend.AddEntry( line, "%s %s" % (value, kwargs.get("yUnits") ), "L" )
                self.TLegend.SetY1( self.TLegend.GetY1() - 0.02)
                line.Draw("same")  
        
        if kwargs.get("xCutLines"):
            for value in kwargs.get("xCutLines"):
                yMin = self.TMultigraph.GetYaxis().GetBinUpEdge(0)
                yMax = self.TMultigraph.GetYaxis().GetBinUpEdge(self.TMultigraph.GetYaxis().GetNbins())
                line = ROOT.TLine( value, yMin, value, yMax)
                self._CustomiseTLine(line, lineColour=self.CutLineColour, lineWidth=3, lineStyle=ROOT.kSolid)
                self.TLegend.AddEntry( line, "%s %s" % (value, kwargs.get("yUnits") ), "L" )
                self.TLegend.SetY1( self.TLegend.GetY1() - 0.02)
                line.Draw("same")  

        ### Draw all objects on the PadPlot
        for o in self.DrawObjectList:
            o.Draw("same")

        self.SaveHistos(bSave, savePath, saveFormats)
        return


    def CustomiseMGraph(self, kwargs):
        '''
        '''
        self.Verbose()
        
        ### Once drawn, the TMultiGraph can be customised
        self.TMultigraph.GetXaxis().SetTitle( kwargs.get("xLabel") + " " + kwargs.get("xUnits") )
        #self.TMultigraph.GetYaxis().SetTitle( kwargs.get("yLabel")  % (kwargs.get("binWidthX")) + " "  + str(kwargs.get("xUnits")) )
        self.TMultigraph.GetYaxis().SetTitle( kwargs.get("yLabel") + " " + kwargs.get("yUnits") )
        if kwargs.get("xMin") != None and kwargs.get("xMax") != None:
            self.TMultigraph.GetXaxis().SetRangeUser( kwargs.get("xMin"), kwargs.get("xMax") ) 
            self.TMultigraph.GetXaxis().SetLimits(kwargs.get("xMin"), kwargs.get("xMax") )
        if kwargs.get("yMin") != None and kwargs.get("yMax") != None:
            self.TMultigraph.GetYaxis().SetRangeUser( kwargs.get("yMin"), kwargs.get("yMax") ) 


        self.TLegend.Draw()
        self.AddDefaultCmsText()
        self.TCanvas.SetLogx( kwargs.get("logX") )
        self.TCanvas.SetLogy( kwargs.get("logY") )
        self.TCanvas.SetGridx( kwargs.get("gridX") )
        self.TCanvas.SetGridy( kwargs.get("gridY") )
        self.TCanvas.Update()
        return        
        

    def SaveTGraphArraysDataToFile(self, fileName, xVals, xErrUp, xErrDown, yVals, yErrUp, yErrDown, maxDecimals = 1, bWriteHeader=True):
        '''
        Reading and Writing Files in Python. The modes can be:
        
        'r' when the file will only be read
        
        'w' for only writing (an existing file with the same name will be erased)
        
        'a' opens the file for appending; any data written to the file is automatically
        added to the end. 
        
        'r+' opens the file for both reading and writing.
        '''
        self.Verbose()

        ### Loop over all lines in myFile. Append info to file
        self.Verbose( ["SaveName: '%s' " % (fileName), "MaxDecimals: '%s'" % (maxDecimals)])
        
        ### Open file in append ("a") mode
        f = open(fileName, "a")

        ### Define the column widths: 10 each
        template = "{0:10} : {1:10} : {2:10} : {3:10} : {4:10} : {5:10}"

        ### Create the table headers
        header = template.format("x", "xErrUp", "xErrDown", "y", "yErrUp", "yErrDown")
        if bWriteHeader == True:
            f.write( header + "\n" )
     
        ### Now write the actual values
        for x, xUp, xDown, y, yUp, yDown in  zip(xVals, xErrUp, xErrDown, yVals, yErrUp, yErrDown):
            column1  = str( round( x    , maxDecimals) )
            column2  = str( round( xUp  , maxDecimals) ) 
            column3  = str( round( xDown, maxDecimals) )
        
            column4  = str( round( y    , maxDecimals) )
            column5  = str( round( yUp  , maxDecimals) ) 
            column6  = str( round( yDown, maxDecimals) )

            row = column1 + column2 + column3 + column4 + column5 + column6

            line = template.format(column1, column2, column3, column4, column5, column6) + "\n"
            self.Verbose( ["Writing line: %s " % (line) ] )
            f.write( line  )

        f.close()
        return



    def SaveTGraphArraysDataToFileWithZ(self, fileName, xVals, xErrUp, xErrDown, yVals, yErrUp, yErrDown, zVals, zErrUp, zErrDown, maxDecimals = 1, bWriteHeader=True):
        '''
        Reading and Writing Files in Python. The modes can be:
        
        'r' when the file will only be read
        
        'w' for only writing (an existing file with the same name will be erased)
        
        'a' opens the file for appending; any data written to the file is automatically
        added to the end. 
        
        'r+' opens the file for both reading and writing.
        '''
        self.Verbose()

        ### Sanity check: All value lists have the same number of entries
        length = len(xVals)
        if all(len(lst) != length for lst in [xErrUp, xErrDown, yVals, yErrDown, zVals, zErrUp, zErrDown]):
            self.Print( ["len(xVals) = '%s'"    % (len(xVals)), "len(xErrUp) = '%s'"   % (len(xErrUp)), "len(xErrDown) = '%s'" % (len(xErrDown)), 
                         "len(yVals) = '%s'"    % (len(yVals)), "len(yErrUp) = '%s'"   % (len(yErrUp)), "len(yErrDown) = '%s'" % (len(yErrDown)), 
                         "len(zVals) = '%s'"    % (len(zVals)), "len(zErrUp) = '%s'"   % (len(zErrUp)), "len(zErrDown) = '%s'" % (len(zErrDown)), "EXIT"] )

        ### Loop over all lines in myFile. Append info to file
        self.Verbose( ["SaveName: '%s' " % (fileName), "MaxDecimals: '%s'" % (maxDecimals)])
        
        ### Open file in append ("a") mode
        f = open(fileName, "a")

        ### Define the column widths: 10 each
        template = "{0:10} : {1:10} : {2:10} : {3:10} : {4:10} : {5:10} : {6:10} : {7:10} : {8:10}"

        ### Create the table headers
        header = template.format("x", "xErrUp", "xErrDown", "y", "yErrUp", "yErrDown", "z", "zErrUp", "zErrDown")
        if bWriteHeader == True:
            f.write( header + "\n" )

        self.Verbose( ["(x , y , z) = (%s , %s , %s)" % (xVals , yVals , zVals)]  )
        self.Verbose( ["(x+ , y+ , z+) = (%s , %s , %s)" % (xErrUp , yErrUp , zErrUp)]  )
        self.Verbose( ["(x- , y- , z-) = (%s , %s , %s)" % (xErrDown , yErrDown , zErrDown)]  )
        ### Now write the actual values
        for x, xUp, xDown, y, yUp, yDown, z, zUp, zDown in  zip(xVals, xErrUp, xErrDown, yVals, yErrUp, yErrDown, zVals, zErrUp, zErrDown):
            column1  = str( round( x    , maxDecimals) )
            column2  = str( round( xUp  , maxDecimals) ) 
            column3  = str( round( xDown, maxDecimals) )
        
            column4  = str( round( y    , maxDecimals) )
            column5  = str( round( yUp  , maxDecimals) ) 
            column6  = str( round( yDown, maxDecimals) )

            column7  = str( round( z    , maxDecimals) )
            column8  = str( round( zUp  , maxDecimals) ) 
            column9  = str( round( zDown, maxDecimals) )

            row = column1 + column2 + column3 + column4 + column5 + column6 + column7 + column8 + column9

            line = template.format(column1, column2, column3, column4, column5, column6, column7, column8, column9) + "\n"
            self.Verbose( ["Writing line: %s " % (line) ] )
            f.write( line  )

        f.close()
        return


    def GetTGraphArraysDataFromFile(self, inputFilePath):
        '''
        '''
        self.Verbose()

        if os.path.exists(inputFilePath) == False:
            raise Exception("File '%s' does not exist! Please make sure the provided path for the file is correct." % (inputFilePath) )
        else:
            pass

        ### Variable declaration            
        xVals    = []
        xErrUp   = []
        xErrDown = []
        yVals    = []
        yErrUp   = []
        yErrDown = []

        ### Loop over all lines in myFile
        with open(inputFilePath) as f:
            ### Skip the header row and start reading a file from line2
            next(f)
            ### Loop over all lines
            for line in f:
                
                x     = ( line.rsplit(":", 5)[0] ).replace(" ", "")
                xUp   = ( line.rsplit(":", 5)[1] ).replace(" ", "")
                xDown = ( line.rsplit(":", 5)[2] ).replace(" ", "")
                y     = ( line.rsplit(":", 5)[3] ).replace(" ", "")
                yUp   = ( line.rsplit(":", 5)[4] ).replace(" ", "")
                yDown = ( line.rsplit(":", 5)[5] ).replace(" ", "").replace("\n", "")

                xVals   .append( x     )
                xErrUp  .append( xUp   )
                xErrDown.append( xDown )
                yVals   .append( y     )
                yErrUp  .append( yUp   )
                yErrDown.append( yDown )

        return xVals, xErrUp, xErrDown, yVals, yErrUp, yErrDown


    def GetTGraphArraysDataFromFileWithZ(self, inputFilePath):
        '''
        '''
        self.Verbose()

        if os.path.exists(inputFilePath) == False:
            raise Exception("File '%s' does not exist!" % (inputFilePath) )

        ### Variable declaration            
        xVals    = []
        xErrUp   = []
        xErrDown = []

        yVals    = []
        yErrUp   = []
        yErrDown = []

        zVals    = []
        zErrUp   = []
        zErrDown = []
        
        nColumns = 8

        ### Loop over all lines in myFile
        with open(inputFilePath) as f:
            
            ### Skip the header row and start reading a file from line2
            #next(f)
            
            ### Loop over all lines
            for line in f:

                ### Skip headers column titles (quick and dirty fix)
                if "x" in line:
                    continue

                x     = ( line.rsplit(":", nColumns)[0] ).replace(" ", "")
                xUp   = ( line.rsplit(":", nColumns)[1] ).replace(" ", "")
                xDown = ( line.rsplit(":", nColumns)[2] ).replace(" ", "")
         
                y     = ( line.rsplit(":", nColumns)[3] ).replace(" ", "")
                yUp   = ( line.rsplit(":", nColumns)[4] ).replace(" ", "")
                yDown = ( line.rsplit(":", nColumns)[5] ).replace(" ", "")

                z     = ( line.rsplit(":", nColumns)[6] ).replace(" ", "")
                zUp   = ( line.rsplit(":", nColumns)[7] ).replace(" ", "")
                zDown = ( line.rsplit(":", nColumns)[8] ).replace(" ", "").replace("\n", "")

                xVals   .append( x     )
                xErrUp  .append( xUp   )
                xErrDown.append( xDown )

                yVals   .append( y     )
                yErrUp  .append( yUp   )
                yErrDown.append( yDown )

                zVals   .append( z     )
                zErrUp  .append( zUp   )
                zErrDown.append( zDown )

        return xVals, xErrUp, xErrDown, yVals, yErrUp, yErrDown, zVals, zErrUp, zErrDown



    def AddTGraphErrorsFromFile(self, savePath, histoObject, x, xUp, xDown, y, yUp, yDown, **kwargs):
        '''
        '''
        self.Verbose()

        ### Convert array items from string to float!
        x     = [ float(item) for item in x     ]
        xUp   = [ float(item) for item in xUp   ]
        xDown = [ float(item) for item in xDown ]
        y     = [ float(item) for item in y     ]
        yUp   = [ float(item) for item in yUp   ]
        yDown = [ float(item) for item in yDown ]

        ### Create the numpy arrays as input to TGraph
        xVals     = numpy.asarray( x     )
        xErrsUp   = numpy.asarray( xUp   )
        xErrsDown = numpy.asarray( xDown )

        yVals     = numpy.asarray( y     )
        yErrsUp   = numpy.asarray( yUp   )
        yErrsDown = numpy.asarray( yDown )
        
        ### Create TGraphAsymmErrors
        histoObject.dataset = kwargs.get("dataset")
        g = ROOT.TGraphAsymmErrors( len(xVals), xVals, yVals, xErrsUp, xErrsDown, yErrsUp, yErrsDown)
        
        ### Draw graph to enable its customisation
        g.Draw()
        self.CustomiseTGraph(g, histoObject, histoObject.dataset, kwargs)

        ### Finally, add the TGraph to the TMultiGraph and save values to a txt file
        self.TMultigraph.Add(g)
        return



    def AddTGraphErrors(self, savePath, histoObject, effValsToDatasetMap, effErrsToDatasetMap, effEtThresholdsToDatasetMap, rateVals, rateValsUp, rateValsDown, etVals, **kwargs):
        '''
        Constucts a ROOT.TGraphErrors object with the list of numbers provided in the form of maps. This is done for each dataset in the map.
        After constuction it add the ROOT.TGraphErrors object to a ROOT.TMultiGraph which can be plotted later on.
        Finally, it save all the x-axis and y-axis values (and their corresponding errors) to a txt file.
        '''                    
        self.Verbose()
        xLatex = []
        yLatex = []
        tLatex = []

        ### Ensure values are of type float
        etVals = [ float(item) for item in etVals ]
        rateVals = [ float(item) for item in rateVals ]
        rateValsUp = [ float(item) for item in rateValsUp ]
        rateValsDown = [ float(item) for item in rateValsDown ]


        saveName = savePath + "ROC"
                
        ### Loop over all dataset and get efficiency/rate values
        for dataset in effValsToDatasetMap:

            datasetName = dataset.rsplit(":", 1)[0].lower()
            if ( len(effValsToDatasetMap[dataset]) != len(effErrsToDatasetMap[dataset]) ):
                raise Exception("The values (and errors lists do not have the same size  ('%s' and '%s' respectively)." % (len(effValsToDatasetMap[dataset]), len(effErrsToDatasetMap[dataset]) )  )

            ### Create the arrays
            xVals     = numpy.asarray(effValsToDatasetMap[dataset])
            xErrsUp   = numpy.asarray(effErrsToDatasetMap[dataset])
            xErrsDown = numpy.asarray(effErrsToDatasetMap[dataset])

            yVals     = numpy.asarray(rateVals) 
            yErrsUp   = numpy.asarray(rateValsUp) 
            yErrsDown = numpy.asarray(rateValsDown) 
            
            ### Create TGraphAsymmErrors
            self.Verbose(["xVals: '%s'" % (xVals), "xErrsUp: '%s'" % (xErrsUp), "xErrsDown: '%s'" % (xErrsDown), "yVals: '%s'" % (yVals), "xErrsUp: '%s'" % (yErrsUp), "yErrsDown: '%s'" % (yErrsDown)])
            g = ROOT.TGraphAsymmErrors(len(xVals), xVals, yVals, xErrsUp, xErrsDown, yErrsUp, yErrsDown)
            g.SetName( "ROC_" + dataset )

            ### Draw graph to enable its customisation
            self.Verbose(["Dataset: '%s' " % (dataset), "XY-Values: '%s'" %  (len(effValsToDatasetMap[dataset])), "SaveName: '%s'" % ( saveName )])
            g.Draw()
            self.CustomiseTGraph(g, histoObject, dataset, kwargs)

            ### Add text at each point
            for i in range( 0, len(xVals) ):
                if rateVals[i] != 50.0:
                    continue
                etVal = int( round( etVals[i] , 0) )
                l = ROOT.TLatex( xVals[i], yVals[i], str(etVal) )
                l.SetTextSize(10)
                l.SetTextAngle(45)
                self.DrawObjectList.append(l)

            ### Finally, add the TGraph to the TMultiGraph and save values to a txt file
            self.TMultigraph.Add(g)
            self.SaveTGraphErrorsDataToFile( saveName, dataset, effValsToDatasetMap[dataset], effErrsToDatasetMap[dataset], effErrsToDatasetMap[dataset], effEtThresholdsToDatasetMap[dataset], rateVals, rateValsUp, rateValsDown )
        return xLatex, yLatex, tLatex



    def AddTGraphErrorsDiTau(self, savePath, histoObject, effValsToDatasetMap, effErrsToDatasetMap, rateVals, rateValsUp, rateValsDown, etVals, bAddText = False, **kwargs):
        '''
        Constucts a ROOT.TGraphErrors object with the list of numbers provided in the form of maps. This is done for each dataset in the map.
        After constuction it add the ROOT.TGraphErrors object to a ROOT.TMultiGraph which can be plotted later on.
        Finally, it save all the x-axis and y-axis values (and their corresponding errors) to a txt file.
        '''                    
        self.Verbose()
        xLatex = []
        yLatex = []
        tLatex = []
        saveName = savePath + "ROC"    

        ### Loop over all dataset and get efficiency/rate values
        for dataset in effValsToDatasetMap:

            datasetName = dataset.rsplit(":", 1)[0].lower()
            if ( len(effValsToDatasetMap[dataset]) != len(effErrsToDatasetMap[dataset]) ):
                raise Exception("The values (and errors lists do not have the same size  ('%s' and '%s' respectively)." % (len(effValsToDatasetMap[dataset]), len(effErrsToDatasetMap[dataset]) )  )

            ### Create the arrays
            xVals     = numpy.asarray(effValsToDatasetMap[dataset])
            xErrsUp   = numpy.asarray(effErrsToDatasetMap[dataset])
            xErrsDown = numpy.asarray(effErrsToDatasetMap[dataset])

            yVals     = numpy.asarray(rateVals) 
            yErrsUp   = numpy.asarray(rateValsUp) 
            yErrsDown = numpy.asarray(rateValsDown) 

            ### Create TGraphAsymmErrors
            self.Verbose(["xVals: '%s'" % (xVals), "xErrsUp: '%s'" % (xErrsUp), "xErrsDown: '%s'" % (xErrsDown), "yVals: '%s'" % (yVals), "xErrsUp: '%s'" % (yErrsUp), "yErrsDown: '%s'" % (yErrsDown)])
            g = ROOT.TGraphAsymmErrors(len(xVals), xVals, yVals, xErrsUp, xErrsDown, yErrsUp, yErrsDown)
            g.SetName("ROC_" + dataset)

            ### Draw graph to enable its customisation
            self.Verbose(["Dataset: '%s' " % (dataset), "XY-Values: '%s'" %  (len(effValsToDatasetMap[dataset])), "SaveName: '%s'" % ( saveName )])
            g.Draw()
            self.CustomiseTGraph(g, histoObject, dataset, kwargs)

            ### Add text at each point
            if bAddText: 
                if type(etVals[0]) == float:
                    for i in range( 0, len(xVals) ):
                        etList = int( round( etVals[i], 0) )
                        label = "(" + str(etList[0]) + " , " + str(etList[1]) + ")"
                        l = ROOT.TLatex( xVals[i], yVals[i], label )
                        l.SetTextSize(10)
                        l.SetTextAngle(45) #30
                        self.DrawObjectList.append(l)
                elif type(etVals[0]) == list:
                    for i in range( 0, len(xVals) ):
                        if rateVals[i] != 50.0:
                            continue
                        etList = etVals[i]
                        label = "(" + str(etList[0]).rsplit(".", 1)[0] + " , " + str(etList[1]).rsplit(".", 1)[0] + ")"
                        l = ROOT.TLatex( xVals[i], yVals[i], label )
                        l.SetTextSize(10)
                        l.SetTextAngle(45) #30
                        self.DrawObjectList.append(l)
                else:
                    raise Exception("Wrong type of variable passed. Expected a 'list of floats' or a 'list of lists of floats'.")

            ### Finally, add the TGraph to the TMultiGraph and save values to a txt file
            self.TMultigraph.Add(g)
            self.SaveTGraphErrorsDataToFileDiTau( saveName, dataset, effValsToDatasetMap[dataset], effErrsToDatasetMap[dataset], effErrsToDatasetMap[dataset], rateVals, rateValsUp, rateValsDown )
        return xLatex, yLatex, tLatex



    def SaveTGraphErrorsDataToFile(self, fileName, dataset, effVals, effErrUp, effErrDown, effEtThresholds, rateVals, rateValsUp, rateValsDown):
        '''
        Save all the x-axis and y-axis values (and their corresponding errors) to a txt file. 
        The txt file's name is given as the parameter 'fileName' and also contains the dataset information.
        '''
        self.Verbose()

        ### Declarations
        datasetName = dataset
        maxDecimals = 1
        fileName    = fileName + "_"  + datasetName.replace(":", "_") + ".txt"
        f           = open( fileName, 'w')

        self.Print( ["Dataset: '%s'" % (datasetName), "SaveName: '%s' " % (fileName), "MaxDecimals: '%s'" % (maxDecimals)])

        ### Define the column widths: 10 each
        template = "{0:20} & {1:20} & {2:20}" + r"\\"

        ### Create the table headers
        header = template.format("Efficiency (\%)", "Rate (kHZ)", "Ldg CaloTau E_{T} (GeV)")
        f.write( r"\begin{tabular}{ %s }" % ( " c " * 3 ) + "\n" )
        f.write( r"\hline"  + "\n" )
        f.write( header + "\n" )
        f.write( r"\hline"  + "\n" )
     
        ### Now write the actual values
        for effVal, effErrUp, effErrDown, rateVal, rateValUp, rateValDown, etThreshold in zip(effVals, effErrUp, effErrDown, rateVals, rateValsUp, rateValsDown, effEtThresholds):
            column1  = str( round( effVal*100  , maxDecimals) ) + "\pm " + str( round( effErrDown*100  , maxDecimals) )
            column2  = str( round( rateVal , maxDecimals) ) + " + " + str( round( rateValUp , maxDecimals) ) + " - " + str( round( rateValDown , maxDecimals) )
            column3  = str( etThreshold.rsplit(">=", 1)[-1] )
            row      = column1 + column2 + column3
            f.write( template.format(column1, column2, column3) + "\n" )

        f.write( r"\hline"  + "\n" )
        f.write( r"\end{tabular}" )
        f.close()
        return


    def SaveTGraphErrorsDataToFileDiTau(self, fileName, dataset, effVals, effErrUp, effErrDown, rateVals, rateValsUp, rateValsDown):
        '''
        Save all the x-axis and y-axis values (and their corresponding errors) to a txt file. 
        The txt file's name is given as the parameter 'fileName' and also contains the dataset information.
        '''
        self.Verbose()

        ### Declarations
        datasetName = dataset
        maxDecimals = 1
        fileName    = fileName + "_"  + datasetName.replace(":", "_") + ".txt"
        f           = open( fileName, 'w')

        self.Print( ["Dataset: '%s'" % (datasetName), "SaveName: '%s' " % (fileName), "MaxDecimals: '%s'" % (maxDecimals)])

        ### Define the column widths: 10 each
        template = "{0:20} & {1:20} & {2:20}" + r"\\"

        ### Create the table headers
        header = template.format("Efficiency (\%)", "Rate (kHZ)", "Ldg CaloTau E_{T} (GeV)")
        f.write( r"\begin{tabular}{ %s }" % ( " c " * 3 ) + "\n" )
        f.write( r"\hline"  + "\n" )
        f.write( header + "\n" )
        f.write( r"\hline"  + "\n" )
     
        ### Now write the actual values
        for effVal, effErrUp, effErrDown, rateVal, rateValUp, rateValDown in zip(effVals, effErrUp, effErrDown, rateVals, rateValsUp, rateValsDown):
            column1  = str( round( effVal*100  , maxDecimals) ) + "\pm " + str( round( effErrDown*100  , maxDecimals) )
            column2  = str( round( rateVal , maxDecimals) ) + " + " + str( round( rateValUp , maxDecimals) ) + " - " + str( round( rateValDown , maxDecimals) )
            column3  = "empty"
            row      = column1 + column2 + column3
            f.write( template.format(column1, column2, column3) + "\n" )

        f.write( r"\hline"  + "\n" )
        f.write( r"\end{tabular}" )
        f.close()
        return


    def PrintElapsedTime(self, units = "seconds", marker = ""):
        '''
        Print the time elapses since the creation of the plotter object.
        
        '''
        self.Verbose()
        
        deltaT = time.time() - self.startTime
        if units == "seconds":
            pass
        elif units == "minutes":
            deltaT = deltaT/60.0
        elif units == "hours":
            deltaT = deltaT/(60.0*60)
        else:
            raise Exception("Unsupported units of time. Please choose from 'seconds', 'minutes' and 'hours'.")
            
        self.Print(["Elapsed time%s: '%s' %s" % (marker, deltaT, units) ])
        return


    def FindFirstBinBelowValue(self, histo, targetValue):
        '''
        '''
        self.Verbose()
        
        nBins      = histo.GetNbinsX()+1
        iBin       = histo.FindLastBinAbove(targetValue)
        if iBin == -1:
            raise Exception("Could not find target value '%s'!" % (targetValue))
        binCenter  = histo.GetBinCenter( iBin+1 )
        binContent = histo.GetBinContent( iBin+1 )

        ### Sanity check
        if binContent != 0:
            percentageOffset = ((binContent - targetValue)/binContent )*100
        else:
            percentageOffset = 99999.9

        if abs(percentageOffset) > 50:
            self.Verbose( ["Target: '%s'" % (targetValue) , "BinContent: '%s'" % (binContent), "BinCenter: '%s'" % (binCenter), "Offset (%%): '%f'" % (percentageOffset)] )
        return iBin, binCenter, binContent


    def GetTGraphValuesAsLists(self, myTGraph):
        '''
        See: 
        http://root.cern.ch/phpBB3/viewtopic.php?t=2499

        d1, d2 = ROOT.Long(0), ROOT.Long(0)
        myGraph.GetPoint( 41, d1, d2 )        
        '''
        self.Verbose()
        
        ### Get ploted array dimension
        nPoints = myTGraph.GetN()
        xVals = [None]*nPoints
        yVals = [None]*nPoints

        for p in range(0, nPoints):
            x = ROOT.Double(0) 
            y = ROOT.Double(0)                
	    myTGraph.GetPoint(p, x, y)
            xVals[p] = x
            yVals[p] = y

        ### Filter the x- and y-value lists. Keep only entries that are non-None
        xVals = filter(lambda a: a != None, xVals)
        yVals = filter(lambda a: a != None, yVals)
        return xVals, yVals        


    def GetTGraphValuesAsListsContours(self, myTGraph):
        '''
        See: 
        http://root.cern.ch/phpBB3/viewtopic.php?t=2499

        d1, d2 = ROOT.Long(0), ROOT.Long(0)
        myGraph.GetPoint( 41, d1, d2 )        
        '''
        self.Verbose()
        
        ### Get ploted array dimension
        nPoints = myTGraph.GetN()
        xVals = [None]*nPoints
        yVals = [None]*nPoints

        for p in range(0, nPoints):
            x = ROOT.Double(0) 
            y = ROOT.Double(0)                
	    myTGraph.GetPoint(p, x, y)
            ### Ensure that leading jet has a greater eT than the subLdg jet
            if self.LdgJetAxis == "x":
                if x < y:
                    continue 
            elif self.LdgJetAxis == "y":
                if y < x:
                    continue 
            ### Save only values that are 5 GeV appart from last Ldg
            xVals[p] = x
            yVals[p] = y

        ### Filter the x- and y-value lists. Keep only entries that are non-None
        xVals = filter(lambda a: a != None, xVals)
        yVals = filter(lambda a: a != None, yVals)

        ### Round-up values to a maximum of "MaxDecimals" decimals
        xVals = [ round(x, self.MaxDecimals) for x in xVals ]
        yVals = [ round(y, self.MaxDecimals) for y in yVals ]

        ### Return values
        if self.MinEtDiffBetweenLdgJetWP == None:
            self.Verbose(["GraphName: '%s'" % ( myTGraph.GetName() ), "LdgJetAxis: '%s'" % (self.LdgJetAxis),                           
                          "MinEtDiffBetweenLdgJetWP: '%s'" % (self.MinEtDiffBetweenLdgJetWP), "LdgJet ET: '%s'" % (xVals), "SubLdgJet ET: '%s'" % (yVals)] )
            return xVals, yVals
        elif self.MinEtDiffBetweenLdgJetWP == -1: # say 3 key values; first, middle, last.
            arrayLength = len(xVals)
            middleIndex = 0
            ### If list length is even/odd treat differently
            if arrayLength % 2 == 0:
                middleIndex = arrayLength/2
            else:
                middleIndex = (arrayLength+1)/2
            xValsNew = [xVals[0], xVals[middleIndex], xVals[-1]]
            yValsNew = [yVals[0], yVals[middleIndex], yVals[-1]]
            self.Verbose(["GraphName: '%s'" % ( myTGraph.GetName() ), "LdgJetAxis: '%s'" % (self.LdgJetAxis), 
                        "MinEtDiffBetweenLdgJetWP: '%s'" % (self.MinEtDiffBetweenLdgJetWP), "LdgJet ET: '%s'" % (xValsNew), "SubLdgJet ET: '%s'" % (yValsNew)] )
            return xValsNew, yValsNew
        elif self.MinEtDiffBetweenLdgJetWP == "middle": #
            arrayLength = len(xVals)
            middleIndex = 0
            ### If list length is even/odd treat differently
            if arrayLength % 2 == 0:
                middleIndex = arrayLength/2
            else:
                middleIndex = (arrayLength+1)/2
            xValsNew = [xVals[middleIndex]]
            yValsNew = [yVals[middleIndex]]
            self.Verbose(["GraphName: '%s'" % ( myTGraph.GetName() ), "LdgJetAxis: '%s'" % (self.LdgJetAxis), 
                        "MinEtDiffBetweenLdgJetWP: '%s'" % (self.MinEtDiffBetweenLdgJetWP), "LdgJet ET: '%s'" % (xValsNew), "SubLdgJet ET: '%s'" % (yValsNew)] )
            return xValsNew, yValsNew
        elif self.MinEtDiffBetweenLdgJetWP == "first": #
            arrayLength = len(xVals)
            middleIndex = 0
            xValsNew = [xVals[0]]
            yValsNew = [yVals[0]]
            self.Verbose(["GraphName: '%s'" % ( myTGraph.GetName() ), "LdgJetAxis: '%s'" % (self.LdgJetAxis), 
                          "MinEtDiffBetweenLdgJetWP: '%s'" % (self.MinEtDiffBetweenLdgJetWP), "LdgJet ET: '%s'" % (xValsNew), "SubLdgJet ET: '%s'" % (yValsNew)] )
            return xValsNew, yValsNew
        elif self.MinEtDiffBetweenLdgJetWP == "last":
            arrayLength = len(xVals)
            middleIndex = 0
            xValsNew = [xVals[-1]]
            yValsNew = [yVals[-1]]
            self.Verbose(["GraphName: '%s'" % ( myTGraph.GetName() ), "LdgJetAxis: '%s'" % (self.LdgJetAxis), 
                          "MinEtDiffBetweenLdgJetWP: '%s'" % (self.MinEtDiffBetweenLdgJetWP), "LdgJet ET: '%s'" % (xValsNew), "SubLdgJet ET: '%s'" % (yValsNew)] )
            return xValsNew, yValsNew
        else:
            iIndex = []
            jIndex = []
            if self.LdgJetAxis == "x":
                tmpVals = xVals
            elif self.LdgJetAxis == "y":
                tmpVals = yVals
            else:
                raise Exception("Expected 'x' or 'y' for axis, instead got '%s'." % (self.LdgJetAxis))

            ### Keep only list pairs that satisfy the self.MinEtDiffBetweenLdgJetWP condition. 
            ### Always keep the first and last values though
            i = 0
            while i < ( len(tmpVals) ):
                j = i + 1
                while j < len(tmpVals)-1:
                    diff = abs( tmpVals[i] - tmpVals[j] )
                    if diff >= self.MinEtDiffBetweenLdgJetWP:
                        iIndex.append(i)
                        jIndex.append(j)
                        i = j-1
                        break
                    else:
                        j += 1
                i += 1

            ### Merge indices and remove duplicates
            myIndices = iIndex + jIndex
            myIndices = sorted(set(myIndices))
            myIndices.append( len(xVals)-1 )

            ### Keep array pairs that satisfy the self.MinEtDiffBetweenLdgJetWP condition
            xValsNew = []
            yValsNew = []
            for index in myIndices:
                xValsNew.append( xVals[index] )
                yValsNew.append( yVals[index] )

            self.Verbose(["GraphName: '%s'" % ( myTGraph.GetName() ), "LdgJetAxis: '%s'" % (self.LdgJetAxis), 
                        "MinEtDiffBetweenLdgJetWP: '%s'" % (self.MinEtDiffBetweenLdgJetWP), "x: '%s'" % (xValsNew), "y: '%s'" % (yValsNew)] )

            return xValsNew, yValsNew


        
    def SaveContourPointsToFile(self, tmpHistoDict):
        '''
        When option "LIST" is specified together with option "CONT", the points used to draw the contours are saved in TGraph objects:
        
        h->Draw("CONT LIST");
        gPad->Update();
    
        The contour are saved in TGraph objects once the pad is painted. Therefore to use this functionnality in a macro, gPad->Update() should be performed after the histogram drawing. 
        Once the list is built, the contours are accessible in the following way:

        TObjArray *contours = gROOT->GetListOfSpecials()->FindObject("contours")
        Int_t ncontours     = contours->GetSize();
        TList *list         = (TList*)contours->At(i);
        Where "i" is a "contour number", and "list" contains a "list of TGraph objects".     
        For one given contour, more than one disjoint polyline may be generated. The number of TGraphs per contour is given by:
        
        list->GetSize();
        
        To access the first graph in the list one should do:
        
        TGraph *gr1 = (TGraph*)list->First();       
        '''
        self.Verbose()

        if self.SaveContourPoints == False:
            return
    
        ### Variable declaration
        bWriteHeader = True

        ### x = LdgJet ET
        xVals        = []
        xErrUp       = []
        xErrDown     = []

        ### y = SubLdgJet ET
        yVals        = []
        yErrUp       = []
        yErrDown     = []
        
        ### z = Rate (kHz)
        zVals        = []
        zErrUp       = []
        zErrDown     = []
        
        ### 
        failList     = []
        failTypeList = []

        ### for-Loop: Over all histo types (Nominal, FluctuateUp, FluctuateDown) 
        for typeCounter, histoType in enumerate(tmpHistoDict):

            ### Sanity check
            hList       = tmpHistoDict[histoType]
            nHistoTypes = len(tmpHistoDict)
            if nHistoTypes != 3:
                raise Exception("Expected the list to have size 3 (Nominal, FluctuateUp, FluctuateDown) but is '%s' instead." % (nHistoTypes) )

            bSkipThisCut = False
            ### for-Loop: Over all zCutValues
            for nZCutCounter, h in enumerate(hList):

                if nZCutCounter == len(hList):
                    break

                h.Draw("cont list")
                ROOT.gPad.Update()
                ### Save Contours values by first converting them to TGraphs...
                contours  = ROOT.gROOT.GetListOfSpecials().FindObject("contours")
                nContoursPerHisto = contours.GetSize()
                self.Verbose( ["HistoNumber: '%s'/'%s'" % (nZCutCounter, len(hList)-1), "HistoType (Counter): '%s' ('%s'/'%s')" % (histoType, typeCounter, len(tmpHistoDict)-1), 
                               "HistoName: '%s'" % (h.GetName()), "CutValue (Counter): '%s' ('%s'/'%s')" % (self.THDumbie.zCutLines[nZCutCounter], nZCutCounter, len(self.THDumbie.zCutLines)-1) ] )

                ### Access the first graph in the list
                list = contours.At(nZCutCounter)
                myTGraph = list.First()
                if not myTGraph:
                    bSkipThisCut = True
                    continue
                    
                myTGraph.SetName( h.GetName() + "_zCut" + str(self.THDumbie.zCutLines[nZCutCounter]) )
                x, y = self.GetTGraphValuesAsListsContours( myTGraph )
                zVal = []
                zErr = []
                ### In case multiple values are saved from the contour (advise against this)
                for val in range( 0, len(x) ):
                    if bSkipThisCut==True:
                        break
                    zVal.append( self.THDumbie.zCutLines[nZCutCounter] )
                    zErr.append( h.GetBinContent( h.GetXaxis().FindBin(x[val]) , h.GetYaxis().FindBin(y[val]) ) )

                if histoType == "Nominal":
                    xVals.append(x)
                    yVals.append(y)
                    zVals.append( zVal )
                elif histoType == "FluctuateUp":
                    xErrUp.append(x)
                    yErrUp.append(y)
                    zErrUp.append( zErr )
                elif histoType == "FluctuateDown":
                    xErrDown.append(x)
                    yErrDown.append(y)
                    zErrDown.append( zErr )
                else:
                    raise Exception("Unexpected histoType '%s'. Expected histoType to be one of 'Nominal', 'FluctuateUp' or 'FluctuateDown'." % ( histoType ) )

        ### Sanity check
        nValues = len(xVals)
        nDiff   = 0
        if all(len(lst) != nValues for lst in [yVals, zVals]):
            self.Verbose( ["xVals ('%s') = '%s'" % (len(xVals), xVals), "yVals ('%s') = '%s'" % (len(yVals), yVals), "zVals ('%s') = '%s'" % (len(zVals), zVals)] )
            self.Verbose( ["xErrUp ('%s') = '%s'" % (len(xErrUp), xErrUp), "yErrUp ('%s') = '%s'" % (len(yErrUp), yErrUp), "zErrUp ('%s') = '%s'" % (len(zErrUp), zErrUp)] )
            self.Verbose( ["xErrDown ('%s') = '%s'" % (len(xErrDown), xErrDown), "yErrDown ('%s') = '%s'" % (len(yErrDown), yErrDown), "zErrDown ('%s') = '%s'" % (len(zErrDown), zErrDown)])
            nDiff = ( nValues - len(yVals) ) + ( nValues - len(zVals) )
        elif all(len(lst) != nValues for lst in [xErrUp, yErrUp]):
            self.Verbose( ["xVals ('%s') = '%s'" % (len(xVals), xVals), "yVals ('%s') = '%s'" % (len(yVals), yVals), "zVals ('%s') = '%s'" % (len(zVals), zVals)] )
            self.Verbose( ["xErrUp ('%s') = '%s'" % (len(xErrUp), xErrUp), "yErrUp ('%s') = '%s'" % (len(yErrUp), yErrUp), "zErrUp ('%s') = '%s'" % (len(zErrUp), zErrUp)] )
            self.Verbose( ["xErrDown ('%s') = '%s'" % (len(xErrDown), xErrDown), "yErrDown ('%s') = '%s'" % (len(yErrDown), yErrDown), "zErrDown ('%s') = '%s'" % (len(zErrDown), zErrDown)])
            nDiff = ( nValues - len(xErrUp) ) + ( nValues - len(yErrUp) ) + ( nValues - len(zErrUp) )
        elif all(len(lst) != nValues for lst in [xErrDown, yErrDown]):
            self.Verbose( ["xVals ('%s') = '%s'" % (len(xVals), xVals), "yVals ('%s') = '%s'" % (len(yVals), yVals), "zVals ('%s') = '%s'" % (len(zVals), zVals)] )
            self.Verbose( ["xErrUp ('%s') = '%s'" % (len(xErrUp), xErrUp), "yErrUp ('%s') = '%s'" % (len(yErrUp), yErrUp), "zErrUp ('%s') = '%s'" % (len(zErrUp), zErrUp)] )
            self.Verbose( ["xErrDown ('%s') = '%s'" % (len(xErrDown), xErrDown), "yErrDown ('%s') = '%s'" % (len(yErrDown), yErrDown), "zErrDown ('%s') = '%s'" % (len(zErrDown), zErrDown)])
            nDiff = ( nValues - len(xErrDown) ) + ( nValues - len(yErrDown) ) + ( nValues - len(zErrDown) )
        else:
            pass
        

        ### Wait untill all three are filled (x, xErrUp, xErrDown  [ditto for y, yErrUp, yErrDown] )  and then save to file
        nPoints = nValues - abs(nDiff)
        for i in range( 0, nPoints, +1 ):
            
            ### Convert error values to absolute errors
            xErrUpAbs   = []
            xErrDownAbs = []
            yErrUpAbs   = []
            yErrDownAbs = []
            zErrUpAbs   = []
            zErrDownAbs = []

            for j in range( 0, len(xVals[i]), +1 ):

                xErrUpAbs  .append( round(abs( xVals[i][j] - xErrUp  [i][j] ), 2) )
                xErrDownAbs.append( round(abs( xVals[i][j] - xErrDown[i][j] ), 2) )

                yErrUpAbs  .append( round(abs( yVals[i][j] - yErrUp  [i][j] ), 2) )
                yErrDownAbs.append( round(abs( yVals[i][j] - yErrDown[i][j] ), 2) )

                zErrUpAbs  .append( round(abs( zVals[i][j] - zErrUp  [i][j] ), 2) )
                zErrDownAbs.append( round(abs( zVals[i][j] - zErrDown[i][j] ), 2) )
            
            self.Verbose( ["HistoType: '%s'" % (histoType), "CutValue (%s): '%s'" % (i, self.THDumbie.zCutLines[i]), 
                         "xVals[%s]: '%s'" % (i, xVals[i]), "xErrUp: '%s'" % (xErrUpAbs), "xErrDown: '%s'" % (xErrDownAbs), 
                         "yVals[%s]: '%s'" % (i, yVals[i]), "yErrUp: '%s'" % (yErrUpAbs), "xErrDown: '%s'" % (yErrDownAbs),
                         "zVals[%s]: '%s'" % (i, zVals[i]), "zErrUp: '%s'" % (zErrUpAbs), "zErrDown: '%s'" % (zErrDownAbs) ] )

            self.SaveTGraphArraysDataToFileWithZ( self.THDumbie.name + "_ContourValues.txt", 
                                             xVals[i], xErrUpAbs, xErrDownAbs, 
                                             yVals[i], yErrUpAbs, yErrDownAbs, 
                                             zVals[i], zErrUpAbs, zErrDownAbs, 
                                             3, bWriteHeader )
            bWriteHeader = False
        return


    def SaveTH2ContourPoints(self, bSaveContourPoints = False, leadingJetAxis = "x", MinEtDiffBetweenLdgJetWP = None, MaxDecimals = 1):
        '''
        '''
        self.Verbose()
        self.SaveContourPoints = bSaveContourPoints
        self.LdgJetAxis = leadingJetAxis
        self.MinEtDiffBetweenLdgJetWP = MinEtDiffBetweenLdgJetWP
        self.MaxDecimals = MaxDecimals
        return



    def GetRateValuesList(self):
        '''
        In kHz.
        '''
        self.Verbose()

        rateVals_v1 = []
        rateVals_v1.append(  5.0)
        rateVals_v1.append( 10.0)
        rateVals_v1.append( 20.0)
        rateVals_v1.append( 40.0)
        rateVals_v1.append( 50.0)
        rateVals_v1.append( 60.0)
        rateVals_v1.append( 80.0)
        rateVals_v1.append(100.0)
        for i in range(100, 600, 100):
            rate =  i*1.0
            rateVals_v1.append( rate )

        rateVals_v2 = []
        #rateVals_v2.append(  2.0)
        rateVals_v2.append(  5.0)
        rateVals_v2.append( 10.0)
        rateVals_v2.append( 20.0)
        rateVals_v2.append( 30.0)
        rateVals_v2.append( 40.0)
        rateVals_v2.append( 50.0)
        rateVals_v2.append( 60.0)
        rateVals_v2.append( 70.0)
        rateVals_v2.append( 80.0)
        rateVals_v2.append( 90.0)
        rateVals_v2.append(100.0)
        rateVals_v2.append(150.0)
        rateVals_v2.append(200.0)
        rateVals_v2.append(250.0)
        rateVals_v2.append(300.0)

        return rateVals_v2
