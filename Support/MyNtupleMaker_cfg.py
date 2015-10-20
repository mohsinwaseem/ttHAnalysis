import FWCore.ParameterSet.Config as cms

process = cms.Process("MyNtuple")

process.load("FWCore.MessageService.MessageLogger_cfi")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(10) )


process.source = cms.Source("PoolSource",
                            #duplicateCheckMode = cms.untracked.string("noDuplicateCheck"), # WARNING / FIXME for test only !
                            fileNames = cms.untracked.vstring(
        ###############################
        ###### ttHJettoNonbb m125, GenSim, Initial studies
        ###############################
        #'/store/mc/RunIIWinter15GS/ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix/GEN-SIM/MCRUN2_71_V1-v1/60000/002811A1-1B19-E511-8E20-0025902008CC.root',
        #'/store/mc/RunIIWinter15GS/ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix/GEN-SIM/MCRUN2_71_V1-v1/60000/002A3500-3C19-E511-B22D-008CFA0A5740.root',
        #'/store/mc/RunIIWinter15GS/ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix/GEN-SIM/MCRUN2_71_V1-v1/60000/006A1094-8C19-E511-9E5C-00269E95B128.root',
        #'/store/mc/RunIIWinter15GS/ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix/GEN-SIM/MCRUN2_71_V1-v1/60000/006D0A81-1619-E511-B36A-002590200938.root',
        #'/store/mc/RunIIWinter15GS/ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix/GEN-SIM/MCRUN2_71_V1-v1/60000/0078CC8A-1C19-E511-92BA-0025902008CC.root',
        #'/store/mc/RunIIWinter15GS/ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix/GEN-SIM/MCRUN2_71_V1-v1/60000/00A000E3-1C19-E511-A484-002590200AE8.root',
        #'/store/mc/RunIIWinter15GS/ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix/GEN-SIM/MCRUN2_71_V1-v1/60000/00DA697D-1619-E511-B647-0025B3E06516.root',
        #'/store/mc/RunIIWinter15GS/ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix/GEN-SIM/MCRUN2_71_V1-v1/60000/00E0C650-EA18-E511-A9D3-0025905C3E36.root',
        #'/store/mc/RunIIWinter15GS/ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix/GEN-SIM/MCRUN2_71_V1-v1/60000/02034D65-8919-E511-A1EE-90B11C08AD7D.root',
        #'/store/mc/RunIIWinter15GS/ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix/GEN-SIM/MCRUN2_71_V1-v1/60000/020E4E9D-B819-E511-892E-D4AE526A0455.root',
        #'/store/mc/RunIIWinter15GS/ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix/GEN-SIM/MCRUN2_71_V1-v1/60000/021F53CC-7819-E511-9954-F01FAFE29BBE.root',
        #'/store/mc/RunIIWinter15GS/ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix/GEN-SIM/MCRUN2_71_V1-v1/60000/0235EBAF-5519-E511-B15A-002590DE6E7C.root'
        
        ###############################
        ####### MiniAODSIM ttHNonbb
        ###############################
        '/store/mc/RunIISpring15DR74/ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/20000/04A14FA4-2523-E511-9860-0025905C96A6.root',
       '/store/mc/RunIISpring15DR74/ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/20000/0C144E9E-2523-E511-8AE0-0025904C5DD8.root',
       '/store/mc/RunIISpring15DR74/ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/20000/22FE251A-5324-E511-9698-008CFA1CB740.root',
       '/store/mc/RunIISpring15DR74/ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/20000/2607A04D-BD22-E511-A117-00259073E4EA.root',
       '/store/mc/RunIISpring15DR74/ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/20000/26E5901C-2126-E511-8332-B083FED07198.root',
       '/store/mc/RunIISpring15DR74/ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/20000/288297D2-8123-E511-9F3D-008CFA00879C.root',
       '/store/mc/RunIISpring15DR74/ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/20000/2C81AC72-2423-E511-80C0-AC853DA0692A.root',
       '/store/mc/RunIISpring15DR74/ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/20000/30B0B890-1624-E511-9E3D-0002C92A1024.root',
       '/store/mc/RunIISpring15DR74/ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/20000/3216812F-0223-E511-AF55-D4AE5269FD24.root',
       '/store/mc/RunIISpring15DR74/ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/20000/36FF2833-0E24-E511-8980-0025904C66A4.root',
       '/store/mc/RunIISpring15DR74/ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/20000/3AB47518-2126-E511-8F3E-D4AE526A0CEC.root',
       '/store/mc/RunIISpring15DR74/ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/20000/3C0C71D8-B422-E511-BFF7-0CC47A4DEEEE.root',
       '/store/mc/RunIISpring15DR74/ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/20000/427C5905-7324-E511-A584-20CF3027A5D9.root',
       '/store/mc/RunIISpring15DR74/ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/20000/42F67024-8223-E511-BC75-549F358EB796.root',
       '/store/mc/RunIISpring15DR74/ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/20000/4A18B3CD-7B23-E511-95C6-00A0D1EE8A14.root',
       '/store/mc/RunIISpring15DR74/ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/20000/4C517C63-4D26-E511-8F97-0025905C42B8.root',
       '/store/mc/RunIISpring15DR74/ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/20000/52883F13-2323-E511-A7D2-782BCB27C5C0.root',
       '/store/mc/RunIISpring15DR74/ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/20000/528A9FF8-2623-E511-954F-B083FED73AA1.root',
       '/store/mc/RunIISpring15DR74/ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/20000/52C69CA2-2523-E511-ACA8-0025905C42B8.root',
       '/store/mc/RunIISpring15DR74/ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/20000/52F6FFCC-0224-E511-8056-A0040420FE80.root',
       '/store/mc/RunIISpring15DR74/ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/20000/54792D8F-2523-E511-8147-842B2B2B0CFE.root',
       '/store/mc/RunIISpring15DR74/ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/20000/54DF4823-9723-E511-ACE6-0025905C42B8.root',
       '/store/mc/RunIISpring15DR74/ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/20000/6420188E-2523-E511-954F-782BCB6A5183.root',
       '/store/mc/RunIISpring15DR74/ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/20000/64984CB3-5E27-E511-AF25-782BCB6E0F56.root',
       '/store/mc/RunIISpring15DR74/ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/20000/68D36082-8123-E511-B128-00266CFCC1B4.root',
       '/store/mc/RunIISpring15DR74/ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/20000/861E6E6E-D224-E511-9BB5-0002C90F8030.root',
       '/store/mc/RunIISpring15DR74/ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/20000/88E41B69-8123-E511-AA9F-549F358EB76F.root',
       '/store/mc/RunIISpring15DR74/ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/20000/8A43D7DC-C823-E511-93D0-001EC9AF1F29.root',
       '/store/mc/RunIISpring15DR74/ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/20000/8C2E8A4F-7825-E511-BF68-C4346BC00270.root',
       '/store/mc/RunIISpring15DR74/ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/20000/90E1A58B-2523-E511-BD74-842B2B298D13.root',
       '/store/mc/RunIISpring15DR74/ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/20000/94D9D096-2523-E511-9F3E-842B2B2922E2.root',
       '/store/mc/RunIISpring15DR74/ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/20000/96375111-4828-E511-8353-008CFA002830.root',
       '/store/mc/RunIISpring15DR74/ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/20000/9AEC9B2D-C823-E511-AA59-0025904C67A6.root',
       '/store/mc/RunIISpring15DR74/ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/20000/9C561E4E-6824-E511-B408-0CC47A4D99EE.root',
       '/store/mc/RunIISpring15DR74/ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/20000/9E483EEF-A225-E511-AA27-3417EBE53662.root',
       '/store/mc/RunIISpring15DR74/ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/20000/A07F7475-FF23-E511-B6C1-000F5327375C.root',
       '/store/mc/RunIISpring15DR74/ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/20000/A6C9179E-A723-E511-81D1-0025905C3DD0.root',
       '/store/mc/RunIISpring15DR74/ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/20000/A6D575E2-F823-E511-BE03-0002C90F8088.root',
       '/store/mc/RunIISpring15DR74/ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/20000/A80ABD7A-2423-E511-9CD8-0025905C3DF6.root',
       '/store/mc/RunIISpring15DR74/ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/20000/AC1673FA-5024-E511-8ED4-00266CFAE78C.root',
       '/store/mc/RunIISpring15DR74/ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/20000/AC2C0E2D-C823-E511-A94B-0025904C67A6.root',
       '/store/mc/RunIISpring15DR74/ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/20000/B239E4E7-8D23-E511-86BC-008CFA56D58C.root'

       )
                            )



process.TFileService = cms.Service("TFileService", fileName = cms.string("output.root"))


process.MyNtuple = cms.EDAnalyzer('MyNtupleMaker'
)


process.p = cms.Path(
#    process.JEC+
    process.MyNtuple)

