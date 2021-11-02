//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sun Oct 24 23:26:57 2021 by ROOT version 6.24/06
// from TTree hits/hits
// found on file: run0055_bc_40p000_tac_60_ccs_7_cs_3_dt_100_mst_0_spc_500_dp_100.root
//////////////////////////////////////////////////////////

#ifndef MyClass_h
#define MyClass_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class MyClass {
public :
   TTree          *fChain;
   Int_t           fCurrent;

// Fixed size dimensions of array or collections stored in the TTree if any.
   static constexpr Int_t kMaxhits = 18848;

   // Declaration of leaf types
   Int_t           hits_;
   UInt_t          hits_id[kMaxhits];   //[hits_]
   UChar_t         hits_det[kMaxhits];   //[hits_]
   UChar_t         hits_plane[kMaxhits];   //[hits_]
   UChar_t         hits_fec[kMaxhits];   //[hits_]
   UChar_t         hits_vmm[kMaxhits];   //[hits_]
   Double_t        hits_readout_time[kMaxhits];   //[hits_]
   Double_t        hits_time[kMaxhits];   //[hits_]
   UChar_t         hits_ch[kMaxhits];   //[hits_]
   UShort_t        hits_pos[kMaxhits];   //[hits_]
   UShort_t        hits_bcid[kMaxhits];   //[hits_]
   UShort_t        hits_tdc[kMaxhits];   //[hits_]
   UShort_t        hits_adc[kMaxhits];   //[hits_]
   Bool_t          hits_over_threshold[kMaxhits];   //[hits_]
   Double_t        hits_chip_time[kMaxhits];   //[hits_]

   // List of branches
   TBranch        *b_hits_;   //!
   TBranch        *b_hits_id;   //!
   TBranch        *b_hits_det;   //!
   TBranch        *b_hits_plane;   //!
   TBranch        *b_hits_fec;   //!
   TBranch        *b_hits_vmm;   //!
   TBranch        *b_hits_readout_time;   //!
   TBranch        *b_hits_time;   //!
   TBranch        *b_hits_ch;   //!
   TBranch        *b_hits_pos;   //!
   TBranch        *b_hits_bcid;   //!
   TBranch        *b_hits_tdc;   //!
   TBranch        *b_hits_adc;   //!
   TBranch        *b_hits_over_threshold;   //!
   TBranch        *b_hits_chip_time;   //!

   MyClass(TTree *tree=0);
   virtual ~MyClass();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef MyClass_cxx
MyClass::MyClass(TTree *tree) : fChain(0)
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("run0055_bc_40p000_tac_60_ccs_7_cs_3_dt_100_mst_0_spc_500_dp_100.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("run0055_bc_40p000_tac_60_ccs_7_cs_3_dt_100_mst_0_spc_500_dp_100.root");
      }
      f->GetObject("hits",tree);

   }
   Init(tree);
}

MyClass::~MyClass()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t MyClass::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain -> GetEntry(entry);
}
Long64_t MyClass::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void MyClass::Init(TTree *tree)
{
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("hits", &hits_, &b_hits_);
   fChain->SetBranchAddress("hits.id", hits_id, &b_hits_id);
   fChain->SetBranchAddress("hits.det", hits_det, &b_hits_det);
   fChain->SetBranchAddress("hits.plane", hits_plane, &b_hits_plane);
   fChain->SetBranchAddress("hits.fec", hits_fec, &b_hits_fec);
   fChain->SetBranchAddress("hits.vmm", hits_vmm, &b_hits_vmm);
   fChain->SetBranchAddress("hits.readout_time", hits_readout_time, &b_hits_readout_time);
   fChain->SetBranchAddress("hits.time", hits_time, &b_hits_time);
   fChain->SetBranchAddress("hits.ch", hits_ch, &b_hits_ch);
   fChain->SetBranchAddress("hits.pos", hits_pos, &b_hits_pos);
   fChain->SetBranchAddress("hits.bcid", hits_bcid, &b_hits_bcid);
   fChain->SetBranchAddress("hits.tdc", hits_tdc, &b_hits_tdc);
   fChain->SetBranchAddress("hits.adc", hits_adc, &b_hits_adc);
   fChain->SetBranchAddress("hits.over_threshold", hits_over_threshold, &b_hits_over_threshold);
   fChain->SetBranchAddress("hits.chip_time", hits_chip_time, &b_hits_chip_time);
   Notify();
}

Bool_t MyClass::Notify()
{
   return kTRUE;
}

void MyClass::Show(Long64_t entry)
{
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t MyClass::Cut(Long64_t entry)
{
   return 1;
}
#endif
