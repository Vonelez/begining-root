//reading tree headline file
#include "TTree.h"
#include "TFile.h"
#include "TString.h"
#include "TGraph.h"
#include "TCanvas.h"
#include "TH1.h"
#include "TF1.h"
#include <iostream>
class Read_data {
public:
	Read_data(TTree *t);
	virtual ~Read_data();
	void read_data();
private:
	Double_t stations[5] = {100.0, 120.0, 140.0, 160.0, 180.0};
	Double_t x = 0, y = 0;
	Double_t y_det[5], y_fit[5];
};
