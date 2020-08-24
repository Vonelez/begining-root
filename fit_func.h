#include "TH1.h"
#include "TROOT.h"
#include "TF1.h"
#include "TMath.h"
#include "TCanvas.h"
#include <iostream>
#include <cmath>

class Fit_Func{
public:
	Fit_Func(TH1F *full);
	virtual ~Fit_Func();
	void fitting(TH1F *full);
	TH1F *full;
};
