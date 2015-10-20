## This has to be called from folder where multicrab job was created. (Python folder)

mv DYJetsToLL_M-10to50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/ ttHSigBkgSamples

mv DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/ ttHSigBkgSamples

mv ST_t-channel_4f_leptonDecays_13TeV-amcatnlo-pythia8_TuneCUETP8M1/ ttHSigBkgSamples

mv ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/ ttHSigBkgSamples

mv ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/ ttHSigBkgSamples

mv TTJets_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/ ttHSigBkgSamples

mv TTWJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-madspin-pythia8/ ttHSigBkgSamples

mv TTZToLLNuNu_M-10_TuneCUETP8M1_13TeV-amcatnlo-pythia8/ ttHSigBkgSamples

mv WJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/ ttHSigBkgSamples

mv WWTo2L2Nu_13TeV-powheg/ ttHSigBkgSamples

mv WZ_TuneCUETP8M1_13TeV-pythia8/ ttHSigBkgSamples

mv ZZ_TuneCUETP8M1_13TeV-pythia8/ ttHSigBkgSamples

mv ttHJetToNonbb_M120_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix_1/ ttHSigBkgSamples

mv ttHJetToNonbb_M120_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix_2/ ttHSigBkgSamples

mv ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix_1/ ttHSigBkgSamples

mv ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix_2/ ttHSigBkgSamples

mv ttHJetToNonbb_M130_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix_1/ ttHSigBkgSamples

mv ttHJetToNonbb_M130_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix_2/ ttHSigBkgSamples

cd ttHSigBkgSamples/

cd DYJetsToLL_M-10to50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/res
hadd output-DYJetsToLL_M-10to50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8.root output_*.root
rm output_*.root
rm *.stderr
rm *.stdout
rm *.xml
rm *.gz

cd ../../DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/res
hadd output-DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8.root output_*.root
rm output_*.root
rm *.stderr
rm *.stdout
rm *.xml
rm *.gz

cd ../../ST_t-channel_4f_leptonDecays_13TeV-amcatnlo-pythia8_TuneCUETP8M1/res
hadd output-ST_t-channel_4f_leptonDecays_13TeV-amcatnlo-pythia8_TuneCUETP8M1.root output_*.root
rm output_*.root
rm *.stderr
rm *.stdout
rm *.xml
rm *.gz

cd ../../ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/res
hadd output-ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1.root output_*.root
rm output_*.root
rm *.stderr
rm *.stdout
rm *.xml
rm *.gz

cd ../../ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/res
hadd output-ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1.root output_*.root
rm output_*.root
rm *.stderr
rm *.stdout
rm *.xml
rm *.gz

cd ../../TTJets_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/res
hadd output-TTJets_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8.root output_*.root
rm output_*.root
rm *.stderr
rm *.stdout
rm *.xml
rm *.gz

cd ../../TTWJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-madspin-pythia8/res
hadd output-TTWJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-madspin-pythia8.root output_*.root
rm output_*.root
rm *.stderr
rm *.stdout
rm *.xml
rm *.gz

cd ../../TTZToLLNuNu_M-10_TuneCUETP8M1_13TeV-amcatnlo-pythia8/res
hadd output-TTZToLLNuNu_M-10_TuneCUETP8M1_13TeV-amcatnlo-pythia8.root output_*.root
rm output_*.root
rm *.stderr
rm *.stdout
rm *.xml
rm *.gz

cd ../../WJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/res
hadd output-WJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8.root output_*.root
rm output_*.root
rm *.stderr
rm *.stdout
rm *.xml
rm *.gz

cd ../../WWTo2L2Nu_13TeV-powheg/res
hadd output-WWTo2L2Nu_13TeV-powheg.root output_*.root
rm output_*.root
rm *.stderr
rm *.stdout
rm *.xml
rm *.gz

cd ../../WZ_TuneCUETP8M1_13TeV-pythia8/res
hadd output-WZ_TuneCUETP8M1_13TeV-pythia8.root output_*.root
rm output_*.root
rm *.stderr
rm *.stdout
rm *.xml
rm *.gz

cd ../../ZZ_TuneCUETP8M1_13TeV-pythia8/res
hadd output-ZZ_TuneCUETP8M1_13TeV-pythia8.root output_*.root
rm output_*.root
rm *.stderr
rm *.stdout
rm *.xml
rm *.gz

cd ../../ttHJetToNonbb_M120_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix_1/res
hadd output-ttHJetToNonbb_M120_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix_1.root output_*.root
rm output_*.root
rm *.stderr
rm *.stdout
rm *.xml
rm *.gz

cd ../../ttHJetToNonbb_M120_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix_2/res
hadd output-ttHJetToNonbb_M120_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix_2.root output_*.root
rm output_*.root
rm *.stderr
rm *.stdout
rm *.xml
rm *.gz
hadd output-ttHJetToNonbb_M120_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix.root output-ttHJetToNonbb_M120_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix_2.root ../../ttHJetToNonbb_M120_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix_1/res/output-ttHJetToNonbb_M120_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix_1.root
rm output-ttHJetToNonbb_M120_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix_2.root
cd ../..
mv ttHJetToNonbb_M120_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix_2 ttHJetToNonbb_M120_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix
rm -r ttHJetToNonbb_M120_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix_1



cd ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix_1/res
hadd output-ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix_1.root output_*.root
rm output_*.root
rm *.stderr
rm *.stdout
rm *.xml
rm *.gz

cd ../../ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix_2/res
hadd output-ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix_2.root output_*.root
rm output_*.root
rm *.stderr
rm *.stdout
rm *.xml
rm *.gz
hadd output-ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix.root output-ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix_2.root ../../ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix_1/res/output-ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix_1.root
rm output-ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix_2.root
cd ../..
mv ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix_2 ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix
rm -r ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix_1


cd ttHJetToNonbb_M130_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix_1/res
hadd output-ttHJetToNonbb_M130_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix_1.root output_*.root
rm output_*.root
rm *.stderr
rm *.stdout
rm *.xml
rm *.gz

cd ../../ttHJetToNonbb_M130_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix_2/res
hadd output-ttHJetToNonbb_M130_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix_2.root output_*.root
rm output_*.root
rm *.stderr
rm *.stdout
rm *.xml
rm *.gz
hadd output-ttHJetToNonbb_M130_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix.root output-ttHJetToNonbb_M130_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix_2.root ../../ttHJetToNonbb_M130_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix_1/res/output-ttHJetToNonbb_M130_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix_1.root
rm output-ttHJetToNonbb_M130_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix_2.root
cd ../..
mv ttHJetToNonbb_M130_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix_2 ttHJetToNonbb_M130_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix
rm -r ttHJetToNonbb_M130_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix_1
