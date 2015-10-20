#ifndef TreeAnalyserMC_h
#define TreeAnalyserMC_h

#include "TreeAnalyserBase.C"
#include "TreeReaderMC.C"
#include "MCTools.C"
#include "ObjectMCAssociator.C"

class L1Tracks;

class TreeAnalyserMC : public TreeAnalyserBase, public TreeReaderMC, 
                       public virtual MCTools,  public virtual ObjectMCAssociator
{
 public: 
   TreeAnalyserMC() {
     std::cout << " TreeAnalyserMC : The constructor needs some arguments \n";
   };
   TreeAnalyserMC(const std::string MyName_, 
		  const std::string SamplePath, 
		  const std::string SampleName, 
		  const std::string text_, 
		  const int maxEvents_ = -1, 
		  TTree* tree=0) : 
   TreeAnalyserBase(MyName_, SamplePath, SampleName, text_, maxEvents_), 
     TreeReaderMC(SamplePath, SampleName, tree) { InitSelector(); };
   
   friend class L1Tracks;

 private:
   void InitSelector();
   L1Tracks* s;

};

#endif // TreeAnalyserMC_h
