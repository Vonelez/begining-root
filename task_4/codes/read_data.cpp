#include "../includes/read_data.h"
Read_data::Read_data(TTree *t){
	read_data();
}
Read_data::~Read_data() = default;
void Read_data::read_data(){
	TTree *t = new TTree();
	TString dir("/home/sonya/task_4/");
	TString fileName("t");
  	TString ending(".root");
	TString RootName(dir + fileName + ending);
	TFile *file = new TFile();
  	file = TFile::Open(RootName, "read");
	file -> GetObject("t", t);
	TGraph *g = new TGraph();
	TCanvas *c1 = new TCanvas ("c1", "residuals", 1200, 1200);
	c1 -> Divide(2, 3);
	TH1F *h1 = new TH1F("h1", "First detector; residuals, cm; N", 1000, -0.1, 0.1);
	TH1F *h2 = new TH1F("h2", "Second detector; residuals, cm; N", 1000, -0.1, 0.1);
	TH1F *h3 = new TH1F("h3", "Third detector; residuals, cm; N", 1000, -0.1, 0.1);
	TH1F *h4 = new TH1F("h4", "Fourth detector; residuals, cm; N", 1000, -0.1, 0.1);
	TH1F *h5 = new TH1F("h5", "Fifth detector; residuals, cm; N", 1000, -0.1, 0.1);	
	TF1 *appr = new TF1("appr", "[0]*x + [1]", 0, 180);
	t -> SetBranchAddress("Y_detector1", &y_det[0]);
	t -> SetBranchAddress("Y_detector2", &y_det[1]);
	t -> SetBranchAddress("Y_detector3", &y_det[2]);
	t -> SetBranchAddress("Y_detector4", &y_det[3]);
	t -> SetBranchAddress("Y_detector5", &y_det[4]);
	Int_t n = t -> GetEntries();
	for (int nn = 0; nn < n; nn++){
	t -> GetEntry(nn);
	for (int i = 0; i < 5; ++i){
		x = stations[i];
		y = y_det[i];
		g -> SetPoint(i, x, y);
}
	g -> Fit(appr);
	Double_t aParam = appr -> GetParameter(0);
	Double_t bParam = appr -> GetParameter(1);
	for (int i = 0; i < 5; ++i){
		x = stations[i];
		y_fit[i] = aParam*x + bParam;
}
	h1 -> Fill(y_fit[0] - y_det[0]);
	h2 -> Fill(y_fit[1] - y_det[1]);
	h3 -> Fill(y_fit[2] - y_det[2]);
	h4 -> Fill(y_fit[3] - y_det[3]);
	h5 -> Fill(y_fit[4] - y_det[4]);
}
	h1->SetMarkerStyle(8);
	h1->SetLineColor(70);
	h1->SetFillColor(70);
	h2->SetLineColor(88);
	h2->SetFillColor(88);
	h3->SetLineColor(17);
	h3->SetFillColor(17);
	h4->SetLineColor(45);
	h4->SetFillColor(45);
	h5->SetLineColor(13);
	h5->SetFillColor(13);

	c1 -> cd(1);
	h1 -> Fit("gaus");
	h1->Draw();
	c1 -> cd(2);
	h2 -> Fit("gaus");
	h2->Draw();
	c1 -> cd(3);
	h3 -> Fit("gaus");
	h3->Draw();
	c1 -> cd(4);
	h4 -> Fit("gaus");
	h4->Draw();
	c1 -> cd(5);
	h5 -> Fit("gaus");
	h5->Draw();

	c1 -> cd();
	c1->Update();
	c1 -> Modified();
	c1 -> Print("residuals.pdf");
}
