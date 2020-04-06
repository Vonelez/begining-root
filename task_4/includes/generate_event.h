//generate tree headline file
#include "TTree.h"
#include "TFile.h"
#include "TRandom.h"
#include <iostream>
class Generate_event {
public:
	Generate_event(Int_t nEvents);
	Int_t nEvents;
	virtual ~Generate_event();
	void generate_event();
private:
	Double_t stations[5] = {100.0, 120.0, 140.0, 160.0, 180.0};
	Double_t aParam, bParam;
	Double_t a_min = -0.27778;
	Double_t a_max = 0.27778;
	Double_t b_min = -1;
	Double_t b_max = 1;
	Double_t Y_det[5], X = 0;
};
