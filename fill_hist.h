#include "TROOT.h"
#include "TH1F.h"
#include "TTree.h"
#include "TCanvas.h"
#include "TString.h"
#include "read_tree.h"
#include <iostream>

class Filling_Hist{
public:
	Filling_Hist(TTree *st);
	virtual ~Filling_Hist();
	virtual TH1F *get_hist();
	void solution();
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
