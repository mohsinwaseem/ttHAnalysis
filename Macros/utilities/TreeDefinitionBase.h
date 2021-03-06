#ifndef TreeDefinitionBase_h
#define TreeDefinitionBase_h

#include "TChain.h"

class TreeDefinitionBase 
{
   public:
     TTree   *fChain;   //! pointer to the analysed Tree or Chain
     Int_t   fCurrent;  //! Current Tree number in a Chain
     virtual Bool_t  Notify();
     virtual void    Show(Long64_t entry = -1);
     virtual Int_t   GetEntry(Long64_t entry);
};

Int_t TreeDefinitionBase::GetEntry(Long64_t entry)
{
  // Read contents of entry
  if (!fChain) return 0;
  return fChain->GetEntry(entry);
}

Bool_t TreeDefinitionBase::Notify()
{
  // The Notify() function is called when a new file is opened. This
  // can be either for a new TTree in a TChain or when when a new TTree
  // is started when using PROOF. It is normally not necessary to make changes
  // to the generated code, but the routine can be extended by the
  // user if needed. The return value is currently not used.

  return kTRUE;
}

void TreeDefinitionBase::Show(Long64_t entry)
{
  // Print contents of entry.
  // If entry is not specified, print current entry
  if (!fChain) return;
  fChain->Show(entry);
}

#endif // TreeDefinitionBase_h
