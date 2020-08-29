#include "TROOT.h"
#include "TH1F.h"
#include "TF1.h"
#include "TTree.h"
#include "TCanvas.h"
#include "TString.h"
#include "read_tree.h"
#include <iostream>

class Filling_Hist{
public:
	Filling_Hist(TTree *st);
	virtual ~Filling_Hist();
	TH1F *solution();
private:
	TTree *st;
	TH1F *full;
	Int_t N;
	Int_t nt00;
	Int_t tt00;
    	Int_t nt08;
    	Int_t tt08;
	void fill_hist(Read_Tree *straw, TH1F *histo);
};
