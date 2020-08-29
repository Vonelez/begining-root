#include "fit_func.h"
#include "fill_hist.h"
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

	Filling_Hist *data_to_fit = new Filling_Hist(t);
	TH1F *data = new TH1F("data", "", 100, -100., 1000.);
	data = data_to_fit -> solution();

	Fit_Func *my_fit = new Fit_Func(data);
	my_fit -> Fit_Func::do_fit(data);
}
