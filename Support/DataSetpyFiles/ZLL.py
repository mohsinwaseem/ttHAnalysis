import FWCore.ParameterSet.Config as cms

maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )
readFiles = cms.untracked.vstring()
secFiles = cms.untracked.vstring() 
source = cms.Source ("PoolSource",fileNames = readFiles, secondaryFileNames = secFiles)
readFiles.extend( [
       '/store/mc/RunIISpring15DR74/ZLLGJets_MonoPhoton_PtG-130_TuneCUETP8M1_13TeV-madgraph/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/20000/0A4BBF11-F57F-E511-86AF-008CFA111320.root',
       '/store/mc/RunIISpring15DR74/ZLLGJets_MonoPhoton_PtG-130_TuneCUETP8M1_13TeV-madgraph/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/20000/4A867062-F57F-E511-A202-F45214939740.root',
       '/store/mc/RunIISpring15DR74/ZLLGJets_MonoPhoton_PtG-130_TuneCUETP8M1_13TeV-madgraph/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/80000/0A91E90F-FA7F-E511-B197-008CFA1979A0.root',
       '/store/mc/RunIISpring15DR74/ZLLGJets_MonoPhoton_PtG-130_TuneCUETP8M1_13TeV-madgraph/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/80000/10C31E1B-FA7F-E511-872D-002590D9D98E.root',
       '/store/mc/RunIISpring15DR74/ZLLGJets_MonoPhoton_PtG-130_TuneCUETP8M1_13TeV-madgraph/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/80000/26A54227-FA7F-E511-A406-008CFAF0751E.root',
       '/store/mc/RunIISpring15DR74/ZLLGJets_MonoPhoton_PtG-130_TuneCUETP8M1_13TeV-madgraph/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/80000/30E9F7B5-F97F-E511-BF22-008CFA1974CC.root',
       '/store/mc/RunIISpring15DR74/ZLLGJets_MonoPhoton_PtG-130_TuneCUETP8M1_13TeV-madgraph/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/80000/5A6CA90B-FA7F-E511-AF87-008CFA197CD0.root',
       '/store/mc/RunIISpring15DR74/ZLLGJets_MonoPhoton_PtG-130_TuneCUETP8M1_13TeV-madgraph/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/80000/66067427-FA7F-E511-A251-00A0D1EE05D0.root',
       '/store/mc/RunIISpring15DR74/ZLLGJets_MonoPhoton_PtG-130_TuneCUETP8M1_13TeV-madgraph/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/80000/66E57D20-FA7F-E511-9BDF-047D7BD6DF22.root',
       '/store/mc/RunIISpring15DR74/ZLLGJets_MonoPhoton_PtG-130_TuneCUETP8M1_13TeV-madgraph/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/80000/70E8CC1E-FA7F-E511-90EC-002590DB918A.root',
       '/store/mc/RunIISpring15DR74/ZLLGJets_MonoPhoton_PtG-130_TuneCUETP8M1_13TeV-madgraph/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/80000/7C917417-FA7F-E511-A8B2-F45214C748C8.root',
       '/store/mc/RunIISpring15DR74/ZLLGJets_MonoPhoton_PtG-130_TuneCUETP8M1_13TeV-madgraph/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/80000/8A0AE1FB-F97F-E511-9981-008CFA1974CC.root',
       '/store/mc/RunIISpring15DR74/ZLLGJets_MonoPhoton_PtG-130_TuneCUETP8M1_13TeV-madgraph/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/80000/966FED19-FA7F-E511-B3C7-E41D2D08E0B0.root',
       '/store/mc/RunIISpring15DR74/ZLLGJets_MonoPhoton_PtG-130_TuneCUETP8M1_13TeV-madgraph/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/80000/9EB6F4D2-F97F-E511-91A7-34E6D7E3879B.root',
       '/store/mc/RunIISpring15DR74/ZLLGJets_MonoPhoton_PtG-130_TuneCUETP8M1_13TeV-madgraph/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/80000/DC307102-FA7F-E511-AA03-008CFAF06690.root',
       '/store/mc/RunIISpring15DR74/ZLLGJets_MonoPhoton_PtG-130_TuneCUETP8M1_13TeV-madgraph/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/80000/F081D614-FA7F-E511-B224-E41D2D08E0E0.root',
       '/store/mc/RunIISpring15DR74/ZLLGJets_MonoPhoton_PtG-130_TuneCUETP8M1_13TeV-madgraph/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/80000/F20F090C-FA7F-E511-B527-0002C92DB46C.root',
       '/store/mc/RunIISpring15DR74/ZLLGJets_MonoPhoton_PtG-130_TuneCUETP8M1_13TeV-madgraph/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/80000/FC17EC6B-FA7F-E511-83B9-000F530E46D8.root' ] );


secFiles.extend( [
               ] )
