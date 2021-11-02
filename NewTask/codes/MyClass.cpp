#define MyClass_cxx
#include "MyClass.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void MyClass::Loop()
{
//   In a ROOT session, you can do:
//      root> .L MyClass.C
//      root> MyClass t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;
   TH1F * hist = new TH1F("hits_ distribution", "hits_ distribution", 100, 0, 20000);

      for (int i = 0; i < fChain -> GetEntries(); i++) {
        b_hits_ -> GetEntry(i);
        hist -> Fill(hits_);
      }

   TCanvas *c1 = new TCanvas ("c1", "", 1200, 1200);
   c1 -> cd();
   gStyle->SetOptStat(111);
   hist -> GetXaxis() -> SetMaxDigits(4);
   gPad -> SetLogy();
   hist -> Draw();
   c1 -> Update();
   c1 -> Modified();
   c1 -> Print("hits.png");
}
