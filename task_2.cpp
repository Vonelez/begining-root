#include <iostream>
#include <cstdio>
#include <cmath>

void task_2() {
	Double_t stations[5] = {100.0, 120.0, 140.0, 160.0, 180.0}; //coordinates in cm
	Int_t nEvents = 1000; //put here the number of events
	Double_t aParam, bParam;
	Double_t a_min = -0.27778;
	Double_t a_max = 0.27778;
	Double_t b_min = -1;
	Double_t b_max = 1;
	Double_t X;
	Double_t Y[4];
	Double_t Y_det[4];
	TFile  *hfile = new TFile ("tree.root", "RECREATE");
	TTree tree("T","Coordinates");
	tree.Branch("X_coord", &X, "X/D");
	tree.Branch("Y_detector", &Y_det[4], "Y_det[4]/D");
	TRandom rnd;
	tree.SetEntries(4000);	
	for (int i = 0; i < nEvents; ++i) {
		aParam = rnd.Uniform(a_min, a_max);
		bParam = rnd.Uniform(b_min, b_max);
		for (int k = 0; k<5; ++k){
		X = stations[k];
		tree.GetBranch("X_coord") -> Fill ();
		Y[k] = aParam * X + bParam;
		Y_det[k] = gRandom ->  Gaus(Y[k], 0.0150);
		tree.GetBranch("Y_detector") -> Fill ();
}
}		
	hfile -> Write();
}
