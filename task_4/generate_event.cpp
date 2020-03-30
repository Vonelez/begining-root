#include "TTree.h"
#include "TFile.h"
#include "TRandom.h"
#include "functions.h"
#include <iostream>
using namespace std;
void generate_event() {
	Double_t stations[5] = {100.0, 120.0, 140.0, 160.0, 180.0};
	Int_t nEvents = 9000;
	Double_t a_min = -0.27778;
	Double_t a_max = 0.27778;
	Double_t b_min = -1;
	Double_t b_max = 1;
	Double_t aParam, bParam;
	Double_t Y_det[5], X = 0;
	TRandom rnd;
	TFile  *hfile = new TFile ("tree.root", "RECREATE");
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
