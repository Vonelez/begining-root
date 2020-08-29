#include "fit_func.h"

Fit_Func::Fit_Func(TH1F *data){
	this -> data = data;
	do_fit(data);
}

Fit_Func::~Fit_Func() = default;

void Fit_Func::do_fit(TH1F *data){

	TF1 *func = new TF1("func", "[0] + [1]*(1 + [2]*exp(([4] - x)/[3]))/((1 + exp(([4] - x)/[6]))*(1 + exp((x - [5])/[7])))", -100., 1000.);

	func -> SetParLimits(0, 0., 6.);
	func -> SetParLimits(1, 4000., 4500.);
	func -> SetParLimits(2, 6., 10.);
	func -> SetParLimits(3, 40., 60.);
	func -> SetParLimits(4, -35., -20.);
	func -> SetParLimits(5, 680., 720.);
	func -> SetParLimits(6, 0., 0.00040);
	func -> SetParLimits(7, 40., 45.);

	func -> SetParameter(0, 5.);
	func -> SetParameter(1, 4130);
	func -> SetParameter(2, 8.);
	func -> SetParameter(3, 49.9);
	func -> SetParameter(4, -28.5);
	func -> SetParameter(5, 702.);
	func -> SetParameter(6, 0.0000035);
	func -> SetParameter(7, 43.9);

	TCanvas *c2 = new TCanvas ("c2", "c2", 1000, 1000);
	c2 -> cd();
	data -> Fit("func");
	c2 -> Update();
	c2 -> Modified();
	c2 -> Print("Fitted_Data.pdf");
	delete func;
}
