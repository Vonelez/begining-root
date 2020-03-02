#include <iostream>
#include <TH1.h>
#include <TFile.h>
#include <TRandom.h>
#include <TCanvas.h>
#include <cstdio>
#include <cmath>

void task_2() {
	Double_t stations[5] = {100.0, 120.0, 140.0, 160.0, 180.0}; //coordinates in cm
	Int_t nEvents = 1000; //put here the number of events
	Double_t aParam, bParam;
	Double_t a_min = -0.27778;
	Double_t a_max = 0.27778;
	Double_t b_min = -50.0;
	Double_t b_max = 50.0;
	Double_t X = 0;
	Float_t Y = 0.0;
	Float_t Y_det = 0.0;
	TFile  *hfile = new TFile ("tree.root", "RECREATE");
	TTree tree("T","Coordinates");
	tree.Branch("Y_coord", &Y, "Y/F");
	tree.Branch("Y_detector", &Y_det, "Y_det/F");
	TRandom rnd;
	for (int i = 0; i < nEvents; ++i) {
		aParam = rnd.Uniform(a_min, a_max);
		bParam = rnd.Uniform(b_min, b_max);
		for (int k = 0; k<5; ++k){
		X = stations[k];
		Y = aParam * X + bParam;
		if (Y < 50 && Y > -50){
	Y_det = gRandom ->  Gaus(Y, 0.0150);
	tree.SetEntries(4000);
	tree.GetBranch("Y_coord") -> Fill ();
	tree.GetBranch("Y_detector") -> Fill ();
}
}
}		
	hfile -> Write();
}
