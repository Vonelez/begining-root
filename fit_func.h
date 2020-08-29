#include "TH1.h"
#include "TROOT.h"
#include "TF1.h"
#include "TMath.h"
#include "TCanvas.h"
#include "TTree.h"
#include <iostream>
#include <cmath>

class Fit_Func{
public:
	Fit_Func(TH1F *data);
	virtual ~Fit_Func();
	void do_fit(TH1F *data);
private:
	TH1F *data;
};
