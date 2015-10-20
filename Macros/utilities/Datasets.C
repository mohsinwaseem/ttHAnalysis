//This is new
#ifndef Datasets_cxx
#define Datasets_cxx

#include "Datasets.h"

//****************************************************************************
Datasets::Datasets(string alias,
		   string datasetPath, 
		   string datasetPathExt, 
		   string productionType,
		   string cmssw,
		   string geometry,
		   int nPileUp, 
		   int nEvents,
		   int McTauMomPdgId,
		   int nMcTaus)
//****************************************************************************
{
  
  alias_          = alias;
  productionType_ = productionType;
  cmssw_          = cmssw;
  geometry_       = geometry;
  datasetPath_    = datasetPath;
  datasetPathExt_ = datasetPathExt;
  nPileUp_        = nPileUp;
  nEvents_        = nEvents;
  nMcTaus_        = nMcTaus;
  McTauMomPdgId_  = McTauMomPdgId;

}


//****************************************************************************
void Datasets::PrintSamples(const string mcProduction, 
			    const string textFormat, 
			    bool bCompact)
//****************************************************************************
{
  
  // Declarations
  vector<Datasets> myDatasets;

  // First create the tables for the known MC Productions
  if (datasets_Spring15MiniAOD.size() < 1 ) CreateMcProductions_();

  // Check that the mcProduction variable is valid
  IsValidMcProduction_(mcProduction, myDatasets);

  // Print full or compact infromation table
  PrintDatasetsVector_(myDatasets, textFormat, bCompact);

  return;
}


//****************************************************************************
void Datasets::IsValidMcProduction_(const string mcProduction, 
				    vector<Datasets> &myDatasets)
//****************************************************************************
{

  // Declare currently supported MC-Productions
  mcProductions.push_back("Spring15MiniAOD");

  // Check if the selected MC Prodution is valid
  for( int i = 0 ; i < (int) mcProductions.size(); i++){

    if ( mcProduction.compare(mcProductions.at(i)) == 0) {
      myDatasets = datasets_Spring15MiniAOD;
      return;
    }

  }

  // If this is reached then the MC-Production is invalid  
  cout << "\nE R R O R ! Datasets::PrintSamples(...) - Unknown MC Production \"" << mcProduction << "\"." << endl;
  cout << "EXIT" << endl;
  exit(1);
      
  return;
}


//****************************************************************************
void Datasets::IsValidDatasetName(const string datasetName)
//****************************************************************************
{


  // First create the tables for the known MC Productions
  if (datasets_Spring15MiniAOD.size() < 1 ) CreateMcProductions_();

  // Check if the selected MC Prodution is valid
  for( int iD = 0 ; iD < (int) datasets_Spring15MiniAOD.size(); iD++){
    if ( datasetName.compare( datasets_Spring15MiniAOD.at(iD).datasetPath_) == 0) return;
  }
  
  // If this is reached then the dataset sample is invalid
  cout << "\nE R R O R ! Datasets::IsValidDataset(...) - Unknown dataset name \"" << datasetName << "\". See below all available dataset names." << endl;
  for( int iD = 0 ; iD < (int) datasets_Spring15MiniAOD.size(); iD++){
    cout << "\"" << datasets_Spring15MiniAOD.at(iD).datasetPath_ << "\"" << endl;
  }
  cout << "EXIT" << endl;
  exit(1);
  
  return;
}


//****************************************************************************
void Datasets::IsValidDatasetAlias(const string datasetName)
//****************************************************************************
{


  // First create the tables for the known MC Productions
  if (datasets_Spring15MiniAOD.size() < 1 ) CreateMcProductions_();

  // Check if the selected MC Prodution is valid
  for( int iD = 0 ; iD < (int) datasets_Spring15MiniAOD.size(); iD++){
    if ( datasetName.compare( datasets_Spring15MiniAOD.at(iD).alias_) == 0) return;
  }
  
  // If this is reached then the dataset sample is invalid
  cout << "\nE R R O R ! Datasets::IsValidDatasetAlias(...) - Unknown dataset alias \"" << datasetName << "\". See below all available dataset aliases. EXIT" << endl;
  PrintDatasetsVector_(datasets_Spring15MiniAOD, "Text", true);
  cout << "EXIT" << endl;
  exit(1);
  
  return;
}


//****************************************************************************
void Datasets::PrintDatasetsVector_(const vector<Datasets> myDatasets, 
				    const string textFormat, 
				    bool bCompact)
//****************************************************************************
{

  if (myDatasets.size() < 1) return;
  if (bCompact)
    {
      Table mcSamples("Alias | Dataset | Production | CMSSW | PU | Events", textFormat, "l l l c c c");
      for (int i = 0; i < (int) myDatasets.size(); i++){

	mcSamples.AddRowColumn(i, myDatasets.at(i).alias_);
	mcSamples.AddRowColumn(i, myDatasets.at(i).datasetPath_);
	mcSamples.AddRowColumn(i, myDatasets.at(i).productionType_);
	mcSamples.AddRowColumn(i, myDatasets.at(i).cmssw_);
	mcSamples.AddRowColumn(i, auxTools_.ToString( myDatasets.at(i).nPileUp_) );
	mcSamples.AddRowColumn(i, auxTools_.ToString( myDatasets.at(i).nEvents_) );

      }
      mcSamples.Print();
    }
  else
    {
      Table mcSamples("Alias | Dataset | Dataset (CMS DAS) | Production | CMSSW | Geometry | PU | Events", textFormat, "l l l l c c c c");
      for (int i = 0; i < (int) myDatasets.size(); i++){
	
	mcSamples.AddRowColumn(i, myDatasets.at(i).alias_);
	mcSamples.AddRowColumn(i, myDatasets.at(i).datasetPath_);
	mcSamples.AddRowColumn(i, myDatasets.at(i).datasetPathExt_); 	// mcSamples.AddRowColumn(i, "X");
	mcSamples.AddRowColumn(i, myDatasets.at(i).productionType_);
	mcSamples.AddRowColumn(i, myDatasets.at(i).cmssw_);
	mcSamples.AddRowColumn(i, myDatasets.at(i).geometry_);
	mcSamples.AddRowColumn(i, auxTools_.ToString( myDatasets.at(i).nPileUp_) );
	mcSamples.AddRowColumn(i, auxTools_.ToString( myDatasets.at(i).nEvents_) );
	
      }
      mcSamples.Print();
    }
      
  return;
}


//****************************************************************************
void Datasets::CreateMcProductions_(void)
//****************************************************************************
{

  // TTI2023Upgd14D
  // string path     = "TTI2023Upg14D-PU140bx25";
  // string pathExt1 = "/" + path + "_PH2_1K_FB_V3-v2/GEN-SIM-DIGI-RAW";
  // string pathExt2 = "/" + path + "_PH2_1K_FB_V3-v1/GEN-SIM-DIGI-RAW";
  string cmssw    = "7_4_7";
  string geometry = "CMS";
  string PP       = "Private";
  string CP       = "Central";

  // Private Production
  Datasets ttHNonbb_M120 ("ttH120" ,"ttHJetToNonbb_M120_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix","ttHJetToNonbb_M120_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix",CP, cmssw, geometry,   0, 0, 0, 0);
  Datasets ttHNonbb_M125 ("ttH125" ,"ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix","ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix",CP, cmssw, geometry,   0, 0, 0, 0);
  Datasets ttHNonbb_M130 ("ttH130" ,"ttHJetToNonbb_M130_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix","ttHJetToNonbb_M130_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix",CP, cmssw, geometry,   0, 0, 0, 0);
  Datasets DYLL_M10_50   ("DYLLM10","DYJetsToLL_M-10to50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8","DYJetsToLL_M-10to50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8",CP, cmssw, geometry,   0, 0, 0, 0);
  Datasets DYLL_M50      ("DYLLM50","DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8","DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8",CP, cmssw, geometry,   0, 0, 0, 0);
  Datasets ST_tchannel  ("STtchannel","ST_t-channel_4f_leptonDecays_13TeV-amcatnlo-pythia8_TuneCUETP8M1","ST_t-channel_4f_leptonDecays_13TeV-amcatnlo-pythia8_TuneCUETP8M1",CP, cmssw, geometry,   0, 0, 0, 0);
  Datasets ST_tW        ("STWt","ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1","ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1",CP, cmssw, geometry,   0, 0, 0, 0);
  Datasets ST_tbarW     ("STWtbar","ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1","ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1",CP, cmssw, geometry,   0, 0, 0, 0);
  Datasets TTbar        ("TTBar","TTJets_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8","TTJets_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8",CP, cmssw, geometry,   0, 0, 0, 0);
  Datasets TTW          ("TTW","TTWJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-madspin-pythia8","TTWJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-madspin-pythia8",CP, cmssw, geometry,   0, 0, 0, 0);
  Datasets TTZ          ("TTZ","TTZToLLNuNu_M-10_TuneCUETP8M1_13TeV-amcatnlo-pythia8","TTZToLLNuNu_M-10_TuneCUETP8M1_13TeV-amcatnlo-pythia8",CP, cmssw, geometry,   0, 0, 0, 0);
  Datasets WW           ("WW","WWTo2L2Nu_13TeV-powheg","WWTo2L2Nu_13TeV-powheg",CP, cmssw, geometry,   0, 0, 0, 0);
  Datasets ZZ           ("ZZ","ZZ_TuneCUETP8M1_13TeV-pythia8","ZZ_TuneCUETP8M1_13TeV-pythia8",CP, cmssw, geometry,   0, 0, 0, 0);
  Datasets WZ           ("WZ","WZ_TuneCUETP8M1_13TeV-pythia8","WZ_TuneCUETP8M1_13TeV-pythia8",CP, cmssw, geometry,   0, 0, 0, 0);

  // 
  datasets_Spring15MiniAOD.push_back(ttHNonbb_M120);
  datasets_Spring15MiniAOD.push_back(ttHNonbb_M125);
  datasets_Spring15MiniAOD.push_back(ttHNonbb_M130);
  datasets_Spring15MiniAOD.push_back(DYLL_M10_50);
  datasets_Spring15MiniAOD.push_back(DYLL_M50);
  datasets_Spring15MiniAOD.push_back(ST_tchannel);
  datasets_Spring15MiniAOD.push_back(ST_tW);
  datasets_Spring15MiniAOD.push_back(ST_tbarW);
  datasets_Spring15MiniAOD.push_back(TTbar);
  datasets_Spring15MiniAOD.push_back(TTW);
  datasets_Spring15MiniAOD.push_back(TTZ);
  datasets_Spring15MiniAOD.push_back(WW);
  datasets_Spring15MiniAOD.push_back(ZZ);
  datasets_Spring15MiniAOD.push_back(WZ);

  return;
}


//****************************************************************************
Datasets Datasets::GetDataset(const string datasetAlias)
//****************************************************************************
{

  Datasets d;
  bool bSuccess = false;

  // First create the tables for the known MC Productions
  if (datasets_Spring15MiniAOD.size() < 1 ) CreateMcProductions_();

  // Check if the selected MC Prodution is valid
  for( int iD = 0 ; iD < (int) datasets_Spring15MiniAOD.size(); iD++){

    if ( datasetAlias.compare( datasets_Spring15MiniAOD.at(iD).alias_) != 0) continue;
    bSuccess = true;
    d = datasets_Spring15MiniAOD.at(iD);
  }
  
  if(!bSuccess){
    cout << "\nE R R O R ! Datasets::GetDataset(...) - Unexpected error! Could not find dataset alias \"" << datasetAlias << "\"." << endl;
    exit(1);
  }

  return d;
}


//****************************************************************************
const string Datasets::GetDatasetPathFromAlias(const string datasetAlias)
//****************************************************************************
{

  string datasetPath = "none";

  // First create the tables for the known MC Productions
  if (datasets_Spring15MiniAOD.size() < 1 ) CreateMcProductions_();

  // Ensure that the supplied sample name is valids
  IsValidDatasetAlias(datasetAlias);  

  // Check if the selected MC Prodution is valid
  for( int iD = 0 ; iD < (int) datasets_Spring15MiniAOD.size(); iD++){

    if ( datasetAlias.compare( datasets_Spring15MiniAOD.at(iD).alias_) == 0){
      datasetPath = datasets_Spring15MiniAOD.at(iD).datasetPath_;
      return datasetPath;
    }

  }
  
  // If this is reached then the dataset sample is invalid
  cout << "\nE R R O R ! Datasets::GetDatasetPathFromAlias(...) - Unexpected error! Could not find dataset path for dataset alias \"" << datasetAlias << "\"." << endl;
  cout << "EXIT" << endl;
  exit(1);

  return datasetPath;
}

#endif
