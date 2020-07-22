#include <iostream>
Double_t fitfunc(Double_t *x, Double_t *par)
{
	Double_t arg = par[4] - x[0];
	Double_t top = par[1]*(1 + par[2]*TMath::Exp(arg/par[3]));
	Double_t bot = ((1 + TMath::Exp(arg/par[6]))*(1 + TMath::Exp((x[0] - par[5])/par[7])));
	Double_t func = par[0] + top/bot;
	return func;
}
void task_5() {
	Double_t conversion = 0.0244;
	Int_t nt00;
	Int_t tt00;
    	Int_t nt08;
    	Int_t tt08;
	Int_t ntrk;
	TString dir("/home/sonya/");
	TString fileName("Synchronized_data_run_222-");
	Long_t runNum = 224;
	TString ending(".root");
	TString RootName(dir + fileName + runNum + ending);
	TFile *analysis;
	analysis = TFile::Open(RootName, "read");
	TTree *st;
	analysis->GetObject("ADC1", st);
	st -> SetBranchAddress("nt00", &nt00);
	st -> SetBranchAddress("tt00", &tt00);
	st -> SetBranchAddress("nt08", &nt08);
	st -> SetBranchAddress("tt08", &tt08);
	Int_t N = st -> GetEntries();
	TH1F *time = new TH1F("time", "time; t(ns); n", 100, -100., 1000.);
	for (int i = 0; i < N; i++) {
		st->GetEntry(i);
		if (nt00 == 1 && nt08 == 1){
		time -> Fill(0.0244*(tt00 - tt08));
		}
	}
	TF1 *fitting = new TF1("fitting", fitfunc, -100., 1000., 8);
	Double_t par[8];
	par[0] = 162.6;
	par[1] = 328.7;
	par[2] = 106.90;
	par[3] = -2.5367;
	par[4] = -33.672;
	par[5] = 733.45;
	par[6] = -2.5097;
	par[7] = 21.5561;
	Double_t P1 = par[0];
	Double_t P2 = par[1];
	Double_t P3 = par[2];
	Double_t P4 = par[3];
	Double_t P5 = par[4];
	Double_t P6 = par[5];
	Double_t P7 = par[6];
	Double_t P8 = par[7];
	fitting -> SetParameters(P1, P2, P3, P4, P5, P6, P7, P8);
	fitting -> SetParNames("P1", "P2", "P3", "P4", "P5", "P6", "P7", "P8");
	fitting -> SetParLimits(0, 92., 164.);
	fitting -> SetParLimits(1, 327., 350.);
	fitting -> SetParLimits(2, 105., 127.);
	fitting -> SetParLimits(3, -2.537, -2.49);
	fitting -> SetParLimits(4, -40., -33.7);
	fitting -> SetParLimits(5, 720., 734.);
	fitting -> SetParLimits(6, -2.51, -2.5097);
	fitting -> SetParLimits(7, 21., 23.5);
	TCanvas *c1 = new TCanvas ("c1", "", 1000, 1000);
	c1 -> cd();
	time -> Fit(fitting);
	c1->Update();
	c1 -> Modified();
	c1 -> Print("time.pdf");
}
