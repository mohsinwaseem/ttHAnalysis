###############################################################
### Author .........: Alexandros X. Attikis 
### Institute ......: University Of Cyprus (UCY)
### Email ..........: attikis@cern.ch
###############################################################

###############################################################
### All imported modules
###############################################################
### System modules
import sys
import array
import math
import copy
### Other 
import ROOT

###############################################################
### Define class here
###############################################################
class CutClass(object): 
    def __init__(self, verbose=True):
        self.bVerbose   = verbose
        self.MsgCounter = 0

    def Verbose(self, messageList=None):
        '''
        Custome made verbose system. Will print all messages in the messageList
        only if the verbosity boolean is set to true.
        '''
        if self.bVerbose == False:
            return

        self.MsgCounter = self.MsgCounter  + 1            
        print "[%s] %s:" % (self.MsgCounter, self.__class__.__name__ + "." + sys._getframe(1).f_code.co_name + "()")
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
    
    def GetLdgMemberP3(self, branchName):
        '''
        '''
        self.Verbose()

        return "TMath::Sqrt("+ branchName + ".perp2()) > 0" + " && " + "TMath::Sqrt("+ branchName + ".perp2())" + "==" + "Max$(TMath::Sqrt("+ branchName + ".perp2()))"
