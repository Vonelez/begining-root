#include "fill_hist.h"
#include "fit_func.h"

int main(){
	TString dir("/home/sonya/");
	TString fileName("Synchronized_data_run_222-");
	Long_t runNum = 224;
	TString ending(".root");
	TString RootName(dir + fileName + runNum + ending);
	TFile *analysis;
	analysis = TFile::Open(RootName, "read");
	TTree *t = new TTree();
	analysis->GetObject("ADC1", t);

	Filling_Hist *fill_my_hist = new Filling_Hist(t);
	Fit_Func *do_fit = new Fit_Func(fill_my_hist -> Filling_Hist::get_hist());
	/*do_fit -> Fit_Func::fitting(fill_my_hist -> Filling_Hist::get_hist());*/
}
