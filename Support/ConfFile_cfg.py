import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")

process.load("FWCore.MessageService.MessageLogger_cfi")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
    fileNames = cms.untracked.vstring(
        '/store/mc/Summer12_DR53X/TTH_Inclusive_M-125_8TeV_pythia6/AODSIM/PU_S10_START53_V7A-v1/00000/0E1665E5-EE09-E211-ADFB-0025B3E05CF8.root'
    )
)

process.TFileService = cms.Service("TFileService", fileName = cms.string("output.root"))


process.demo = cms.EDAnalyzer('TestNTuple'
)


process.p = cms.Path(process.demo)
