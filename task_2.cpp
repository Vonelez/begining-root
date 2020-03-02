#include <iostream>
#include <TH1.h>
#include <TFile.h>
#include <TRandom.h>
#include <TCanvas.h>
#include <cstdio>
#include <cmath>

void task_2() {
	Double_t stations[5] = {100.0, 120.0, 140.0, 160.0, 180.0}; //coordinates in cm
	Float_t X = 0.0;
	Int_t nEvents = 100; //put here the number of events
	Double_t aParam, bParam;
	Double_t a_min = -0.27778;
	Double_t a_max = 0.27778;
	Double_t b_min = -50.0;
	Double_t b_max = 50.0;
	Float_t Y = 0.0;
	Float_t Y_det = 0.0;
	TCanvas *c1 = new TCanvas ("Detect", "coordinates", 1200, 1200);
	TFile  *hfile = new TFile ("tree.root", "RECREATE");
	TTree tree("T","Coordinates");
	tree.Branch("aParam", &aParam, "aParam/D");
	tree.Branch("bParam", &bParam, "bParam/D");
	tree.Branch("Y_coord", &Y, "Y/F");
	tree.Branch("Y_detector", &Y_det, "Y_det/F");
	c1 -> Divide(2, 1);
	TH1D *Y_coord = new TH1D("Y coord", "Y coord distribution; Y; N", nEvents, -100., 100.);
	TH1D *Y_coord_detected = new TH1D("Y detector", "detected Y coord distribution; detected Y; N", nEvents, -50., 50.);
	TRandom rnd;
	for (int i = 0; i < nEvents; ++i) {
		aParam = rnd.Uniform(a_min, a_max);
		bParam = rnd.Uniform(b_min, b_max);
		X = rnd.Uniform(0.0, 100.0);
		Y = aParam * X + bParam;
		for (int k = 0; k<5; ++k){
		X = stations[k];
		Y_det = aParam * X + bParam;
		if (Y_det < 50 && Y_det > -50){
		Y_coord -> Fill(Y);
		Y_coord_detected -> Fill(Y_det);
	tree.SetEntries(400);
	tree.GetBranch("aParam") -> Fill ();
	tree.GetBranch("bParam") -> Fill ();
	tree.GetBranch("Y_coord") -> Fill ();
	tree.GetBranch("Y_detector") -> Fill ();
}
}
}		
	c1 -> cd(1);
	Y_coord -> SetMarkerStyle(0);
	Y_coord -> SetMarkerColor(69);
	gStyle -> SetErrorX(0.150);
	Y_coord -> Draw("E1");
	c1 -> cd(2);
	Y_coord_detected -> SetMarkerStyle(1);
	Y_coord_detected -> SetMarkerColor(69);
	gStyle -> SetErrorX(0.150);
	Y_coord_detected -> Draw("E1");
	c1 -> cd();
	hfile -> Write();
	c1->Update();
	c1 -> Modified();
	c1 -> Print("muon.pdf");
}
