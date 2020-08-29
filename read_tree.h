#include "TTree.h"
#include "TFile.h"
#include "TROOT.h"
#include "TString.h"
#include "TH1.h"
#include "TCanvas.h"
#include <iostream>
class Read_Tree{
public:
	Read_Tree(TTree *straw);
	virtual ~Read_Tree();
	void read_tree(TTree *straw);
	Int_t nt00;
	Int_t tt00;
    	Int_t nt08;
    	Int_t tt08;
	Int_t ntrk;
};
