#include "../includes/generate_event.h"
Generate_event::Generate_event(Int_t nEvents){
	generate_event();
}
Generate_event::~Generate_event() = default;
void Generate_event::generate_event(){
	TFile  *hfile = new TFile ("t.root", "RECREATE");
	TTree tree ("t","Coordinates");
	tree.Branch ("X_coord", &X, "X/D");
	tree.Branch ("Y_detector1", &Y_det, "Y_det/D");
	tree.Branch ("Y_detector2", &Y_det[1], "Y_det[1]/D");
	tree.Branch ("Y_detector3", &Y_det[2], "Y_det[2]/D");
	tree.Branch ("Y_detector4", &Y_det[3], "Y_det[3]/D");
	tree.Branch ("Y_detector5", &Y_det[4], "Y_det[4]/D");
	TRandom rnd;
	tree.SetEntries(10000);
	for (int i = 0; i < 10000; ++i) {
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
