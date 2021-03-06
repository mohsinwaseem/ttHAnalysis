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
import text as m_text
import ROOT

###############################################################
### Define class here
###############################################################
class StyleClass(object):
    def __init__(self, verbose = False):
        self.verbose = verbose
        self.bEnableColourPalette   = False
        self.TextObject             = m_text.TextClass(verbose=self.verbose)
        self.styleTypeList          = []
        self.styleTypeSpecialList   = []
        self.datasetBank            = ["MinBias", "SinglePionPlus", "SinglePionMinus", "SingleTauOneProng", "TauThreeProngsEnr", "VBF", "TTbar",  "HPlus160", "HPlus200"]
        self.colourPaletteList      = [ROOT.kRed-4, ROOT.kAzure+6, ROOT.kSpring+2, ROOT.kMagenta-2, ROOT.kYellow-4, ROOT.kGray, ROOT.kOrange+8, ROOT.kBlue-4, ROOT.kGreen-2, 
                                       ROOT.kViolet-5, ROOT.kPink-8, ROOT.kTeal-1, ROOT.kCyan-7]
        self.markerStyleCounterList = [ROOT.kFullCircle, ROOT.kFullSquare, ROOT.kFullTriangleUp, ROOT.kFullTriangleDown, ROOT.kFullCross, ROOT.kOpenCircle, ROOT.kOpenSquare, 
                                       ROOT.kOpenTriangleUp, ROOT.kOpenTriangleDown, ROOT.kOpenCross, ROOT.kFullDiamond, ROOT.kOpenDiamond, ROOT.kFullStar, ROOT.kOpenStar]
        self.fillStyleCounterList   = [3001, 3002, 3003, 3004, 3005, 3006, 3007, 3144, 3244, 3444]
        self.lineStyleCounterList   = [i for i in range(+1, +10, +1)]
        self.colourShadeList        = [i for i in range(-9, +4, +3)]
        self.colourPalette          = {}
        self.markerStyleCounter     = {}
        self.fillStyleCounter       = {}
        self.lineStyleCounter       = {}
        self.colourShade            = {}
        self.MsgCounter             = 0
        ### CMSSW_612
        self._SetDefaults("taugun-1pr-nopu", colour=ROOT.kTeal, markerStyle=ROOT.kOpenCircle, lineWidth=2, lineStyle=0, fillStyle=1001, drawOptions="HIST", legOptions="F")
        self._SetDefaults("taugun-1pr-pu140", colour=ROOT.kTeal, markerStyle=ROOT.kFullCircle, lineWidth=2, lineStyle=0, fillStyle=1001, drawOptions="HIST", legOptions="F")
        self._SetDefaults("taugun-3pr-nopu", colour=ROOT.kPink, markerStyle=ROOT.kOpenCircle, lineWidth=2, lineStyle=0, fillStyle=1001, drawOptions="HIST", legOptions="F")
        self._SetDefaults("taugun-3pr-pu140", colour=ROOT.kPink, markerStyle=ROOT.kFullCircle, lineWidth=2, lineStyle=0, fillStyle=1001, drawOptions="HIST", legOptions="F")
        self._SetDefaults("tautaugun", colour=ROOT.kOrange, markerStyle=ROOT.kFullCircle, lineWidth=2, lineStyle=0, fillStyle=1001, drawOptions="HIST", legOptions="F")
        self._SetDefaults("ttbar", colour=ROOT.kSpring, markerStyle=ROOT.kFullTriangleUp, lineWidth=2, lineStyle=0, fillStyle=1001, drawOptions="HIST", legOptions="F")
        self._SetDefaults("vbf", colour=ROOT.kBlue, markerStyle=ROOT.kFullTriangleDown, lineWidth=2, lineStyle=0, fillStyle=1001, drawOptions="HIST", legOptions="F")
        self._SetDefaults("htotautau", colour=ROOT.kRed+2, markerStyle=ROOT.kFullSquare, lineWidth=2, lineStyle=0, fillStyle=1001, drawOptions="HIST", legOptions="F")
        self._SetDefaults("minbias", colour=ROOT.kViolet, markerStyle=ROOT.kFullCircle, lineWidth=2, lineStyle=0, fillStyle=1001, drawOptions="HIST", legOptions="F")
        ### CMSSW_620
        self._SetDefaults("MinBias"          , colour=ROOT.kGray  , markerStyle=ROOT.kFullCircle      , lineWidth=2, lineStyle=0, fillStyle=1001, drawOptions="HIST", legOptions="F")
        self._SetDefaults("SinglePionPlus"   , colour=ROOT.kTeal  , markerStyle=ROOT.kOpenCircle      , lineWidth=2, lineStyle=0, fillStyle=1001, drawOptions="HIST", legOptions="F")
        self._SetDefaults("SinglePionMinus"  , colour=ROOT.kTeal  , markerStyle=ROOT.kOpenCircle      , lineWidth=2, lineStyle=0, fillStyle=1001, drawOptions="HIST", legOptions="F")
        self._SetDefaults("SingleTauOneProng", colour=ROOT.kOrange, markerStyle=ROOT.kOpenSquare      , lineWidth=2, lineStyle=0, fillStyle=1001, drawOptions="HIST", legOptions="F")
        self._SetDefaults("TauThreeProngsEnr", colour=ROOT.kRed   , markerStyle=ROOT.kFullSquare      , lineWidth=2, lineStyle=0, fillStyle=1001, drawOptions="HIST", legOptions="F")
        self._SetDefaults("VBF"              , colour=ROOT.kBlue  , markerStyle=ROOT.kFullTriangleDown, lineWidth=2, lineStyle=0, fillStyle=1001, drawOptions="HIST", legOptions="F")
        self._SetDefaults("TTbar"            , colour=ROOT.kSpring, markerStyle=ROOT.kFullTriangleUp  , lineWidth=2, lineStyle=0, fillStyle=1001, drawOptions="HIST", legOptions="F")
        self._SetDefaults("HPlus200"         , colour=ROOT.kViolet, markerStyle=ROOT.kFullCross       , lineWidth=2, lineStyle=0, fillStyle=1001, drawOptions="HIST", legOptions="F")
        self._SetDefaults("HPlus160"         , colour=ROOT.kAzure , markerStyle=ROOT.kFullCross       , lineWidth=2, lineStyle=0, fillStyle=1001, drawOptions="HIST", legOptions="F")
        ### other
        self._SetSpecials("random", colour = cycle(self.colourPaletteList).next(), markerStyle=ROOT.kFullCircle, lineWidth=3, lineStyle=0, fillStyle=3001, drawOptions="HIST", legOptions="F")
        self.Verbose()
        

    def Verbose(self, messageList=None):
        '''
        Custome made verbose system. Will print all messages in the messageList
        only if the verbosity boolean is set to true.
        '''
        if self.verbose == False:
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


    def SetVerbose(self, verbose):
        '''
        Manually enable/disable verbosity.
        '''
        self.verbose = verbose
        self.Verbose(["Verbose mode = ", self.verbose])
        return


    def _SetDefaults(self, name, **kwargs):
        '''
        Call this function to initialise some default self values when an object is first created.
        Append the style name to a list so that the object is aware of all available pre-defined defaults.
        '''
        self.Verbose()

        ### Remove dependence on upper-case characters
        name = name.lower()

        self.colourPalette[name]      = cycle(self.colourPaletteList)
        self.colourShade[name]        = cycle(self.colourShadeList)
        self.lineStyleCounter[name]   = cycle(self.lineStyleCounterList)
        self.fillStyleCounter[name]   = cycle(self.fillStyleCounterList)
        self.markerStyleCounter[name] = cycle(self.markerStyleCounterList)

        ### Set all arguments and their values
        for argument, value in kwargs.iteritems():
            setattr(self, name + "_" + argument, value)
            #self.drawOptions  = kwargs.get("drawOptions", None)
            #print "'%s': '%s' =  '%s'" % (name, argument , value)

        self.styleTypeList.append( name.lower() )
        return


    def _SetSpecials(self, name, **kwargs):
        '''
        Call this function to initialise some special self values when an object is first created.
        Append the style name to a list so that the object is aware of all available pre-defined defaults.
        '''
        self.Verbose()

        self.colourPalette[name]      = cycle(self.colourPaletteList)
        self.colourShade[name]        = cycle(self.colourShadeList)
        self.lineStyleCounter[name]   = cycle(self.lineStyleCounterList)
        self.fillStyleCounter[name]   = cycle(self.fillStyleCounterList)
        self.markerStyleCounter[name] = cycle(self.markerStyleCounterList)

        ### Set all arguments and their values
        for argument, value in kwargs.iteritems():
            setattr(self, name + "_" + argument, value)
            #print "'%s': '%s' =  '%s'" % (name, argument , value)

        self.styleTypeSpecialList.append(name)
        return


    def EnableColourPalette(self, bEnable):
        '''
        This boolean controls whether the fillColour is the same for each dataset (just a shade change)
        or if it is different (full colour change).
        '''
        self.Verbose()
        self.bEnableColourPalette=bEnable
        return


    def _GetTH1Values(self, styleType):
        '''
        '''
        self.Verbose()
        
        self.Verbose(["Using styleType '%s'" % (styleType)])

        if self.bEnableColourPalette==True:
            fillColour  = self.colourPalette[styleType].next()
        else:
            fillColour  = getattr(self, styleType + "_colour" ) + self.colourShade[styleType].next()

        markerStyle = self.markerStyleCounter[styleType].next()
        markerSize  = 1.0
        lineColour  = fillColour
        lineWidth   = getattr(self, styleType + "_lineWidth"   )
        lineStyle   = getattr(self, styleType + "_lineStyle"   )
        fillStyle   = getattr(self, styleType + "_fillStyle"   )
        drawOptions = getattr(self, styleType + "_drawOptions" )
        legOptions  = getattr(self, styleType + "_legOptions"  )
        return (fillColour, lineColour, markerStyle, markerSize, lineWidth, lineStyle, fillStyle, drawOptions, legOptions)


    def _GetTGraphValues(self, styleType):
        self.Verbose()
        
        if self.bEnableColourPalette==True:
            fillColour  = self.colourPalette[styleType].next()
        else:
            fillColour  = getattr(self, styleType + "_colour" ) + self.colourShade[styleType].next()

        markerStyle = self.markerStyleCounter[styleType].next()
        markerSize  = 1.0
        lineColour  = fillColour
        lineWidth   = getattr(self, styleType + "_lineWidth" )
        lineStyle   = getattr(self, styleType + "_lineStyle" )
        fillStyle   = 3002 #self.fillStyleCounter[styleType].next()
        drawOptions = getattr(self, styleType + "_drawOptions" )
        legOptions  = getattr(self, styleType + "_legOptions" )
        return (fillColour, lineColour, markerStyle, markerSize, lineWidth, lineStyle, fillStyle, drawOptions, legOptions)


    def _GetTH1SpecialValues(self, styleType):
        '''
        '''
        self.Verbose()
        
        if self.bEnableColourPalette==True:
            fillColour  = self.colourPalette[styleType].next()
        else:
            fillColour  = getattr(self, styleType + "_colour" ) + self.colourShade[styleType].next()

        markerStyle = self.markerStyleCounter[styleType].next()
        markerSize  = 1.0
        lineColour  = fillColour
        lineWidth   = getattr(self, styleType + "_lineWidth" )
        lineStyle   = getattr(self, styleType + "_lineStyle" )
        fillStyle   = getattr(self, styleType + "_fillStyle" )
        drawOptions = getattr(self, styleType + "_drawOptions" )
        legOptions  = getattr(self, styleType + "_legOptions" )
        return (fillColour, lineColour, markerStyle, markerSize, lineWidth, lineStyle, fillStyle, drawOptions, legOptions)


    def _GetTH2Values(self, styleType):
        '''
        '''
        self.Verbose()
        
        if self.bEnableColourPalette==True:
            fillColour  = self.colourPalette[styleType].next()
        else:
            fillColour  = getattr(self, styleType + "_colour" ) + self.colourShade[styleType].next()

        markerStyle = self.markerStyleCounter[styleType].next()
        markerSize  = 1.0

        lineColour  = fillColour
        lineWidth   = getattr(self, styleType + "_lineWidth" )
        lineStyle   = getattr(self, styleType + "_lineStyle" ) # + self.lineStyleCounter[styleType].next()

        fillStyle   = getattr(self, styleType + "_fillStyle" ) # + self.fillStyleCounter[styleType].next()

        drawOptions = "COL"
        legOptions  = getattr(self, styleType + "_legOptions" )
        return (fillColour, lineColour, markerStyle, markerSize, lineWidth, lineStyle, fillStyle, drawOptions, legOptions)


    def PrintAttributes(self):
        '''
        Call this function to print all histogram attributes.
        '''
        self.Verbose(["Attributes: %s" % (self.__dict__)])
        return


    def GetTH1Styles(self, histoObject):
        '''
        Get the style attributes for a ROOT.TH1 histogram, such as colour, markerStyle, markerSize, lineWidth, lineStyle, fillStyle and options.
        '''
        self.Verbose()
        
        styleType = None

        if histoObject.styleType != None:
            styleType = histoObject.styleType.lower()
        else:
            styleType = histoObject.dataset.lower()


        if styleType in self.styleTypeList:
            return self._GetTH1Values(styleType)
        elif styleType in self.styleTypeSpecialList:
            return self._GetTH1SpecialValues(styleType)
        else:
            return self._GetTH1Values("random")


    def GetTH2Styles(self, histoObject):
        '''
        Get the style attributes for a ROOT.TH2 histogram, such as colour, markerStyle, markerSize, lineWidth, lineStyle, fillStyle and options.
        '''
        self.Verbose()
        
        styleType = None
        
        if histoObject.styleType != None:
            styleType = histoObject.styleType.lower()
        else:
            styleType = histoObject.dataset.lower()

        if styleType in self.styleTypeList:
            return self._GetTH2Values(styleType)
        else:
            return self._GetTH2Values("random")


    def GetTGraphStyles(self, styleType, dataset = None):
        '''
        Get the style attributes for a ROOT.TH1 histogram, such as colour, markerStyle, markerSize, lineWidth, lineStyle, fillStyle and options.
        '''
        self.Verbose()
        
        if dataset == None:
            if (styleType == None or styleType == "") and dataset == None:
                self.Print( ["ERROR! Could not find the style type '%s' ['%s']. Please select one of the following style names:" % (styleType, type(styleType)), 
                             "\n\t".join(self.styleTypeList), "EXIT"])
                sys.exit()
            else:
                pass
        else:
            styleType = self.TextObject.ConvertLatexToText(dataset).lower()


        styleType = styleType.lower()
        if styleType in self.styleTypeList:
            return self._GetTGraphValues(styleType)
        elif styleType in self.styleTypeSpecialList:
            return self._GetTH1SpecialValues(styleType)
        else:
            return self._GetTH2Values("random")
