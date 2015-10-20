#ifndef TreeAnalyserReco_h
#define TreeAnalyserReco_h

#include "TreeAnalyserBase.C"
#include "TreeReaderReco.C"

class L1Tracks;

class TreeAnalyserReco : public TreeAnalyserBase, public TreeReaderReco
{
 public:
    TreeAnalyserReco() { 
      std::cout << " TreeAnalyserReco : Constructor needs some arguments \n"; 
    }; 
    TreeAnalyserReco(const std::string MyName_, 
		     const std::string SampleName, 
		     const std::string text_, 
		     const int maxEvents_ = -1,
		     TTree* tree=0) : 
                     TreeAnalyserBase(MyName_, SampleName, text_, maxEvents_), 
                     TreeReaderReco(SampleName, tree) { InitSelector(); };
  
    friend class L1Tracks;

 private:
    void InitSelector();
    L1Tracks* s;
};

 
#endif // TreeAnalyserFull_h
