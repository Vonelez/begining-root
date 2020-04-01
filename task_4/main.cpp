#include "TCanvas.h"
#include "TH1.h"
#include "TTree.h"
#include "TFile.h"
#include "TGraph.h"
#include "TF1.h"
#include "TRandom.h"

void generate_event()
{
	Double_t stations[5] = {100.0, 120.0, 140.0, 160.0, 180.0};
	Int_t nEvents = 9000;
	Double_t a_min = -0.27778;
	Double_t a_max = 0.27778;
	Double_t b_min = -1;
	Double_t b_max = 1;
	Double_t aParam, bParam;
	Double_t Y_det[5], X = 0;
	TRandom rnd;
	TFile  *hfile = new TFile ("events.root", "RECREATE");
	TTree tree ("T","Coordinates");
	tree.Branch ("X_coord", &X, "X/D");
	tree.Branch ("Y_detector1", &Y_det, "Y_det/D");
	tree.Branch ("Y_detector2", &Y_det[1], "Y_det[1]/D");
	tree.Branch ("Y_detector3", &Y_det[2], "Y_det[2]/D");
	tree.Branch ("Y_detector4", &Y_det[3], "Y_det[3]/D");
	tree.Branch ("Y_detector5", &Y_det[4], "Y_det[4]/D");
	tree.SetEntries(9000);
	for (int i = 0; i < nEvents; ++i) {
		aParam = rnd.Uniform(a_min, a_max);
		bParam = rnd.Uniform(b_min, b_max);
		for (int k = 0; k < 5; ++k){
			X = stations[k];
			tree.GetBranch("X_coord") -> Fill();
			Y_det[k] = gRandom -> Gaus(aParam * stations[k] + bParam, 0.0150); 
}
		tree.GetBranch("Y_detector1") -> Fill ();
		tree.GetBranch("Y_detector2") -> Fill ();
		tree.GetBranch("Y_detector3") -> Fill ();
		tree.GetBranch("Y_detector4") -> Fill ();
		tree.GetBranch("Y_detector5") -> Fill ();
		for (int j = 0; j < 5; ++j){
			Y_det[j] = 0;
}
}
	hfile -> Write();
}

int main() {
	generate_event();
	Double_t stations[5] = {100.0, 120.0, 140.0, 160.0, 180.0};
	Double_t x = 0, y = 0;
	Double_t y_det[5], y_fit[5];
	TString dir("/home/sonya/task_4/");
	TString fileName("events");
  	TString ending(".root");
	TString RootName(dir + fileName + ending);
	TFile *file = new TFile();
  	file = TFile::Open(RootName, "read");
	TTree *t = new TTree();
	file -> GetObject("T", t);
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

