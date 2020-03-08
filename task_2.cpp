void task_2() {
	Double_t stations[5] = {100.0, 120.0, 140.0, 160.0, 180.0};
	Int_t nEvents = 1000;
	Double_t aParam, bParam;
	Double_t a_min = -0.27778;
	Double_t a_max = 0.27778;
	Double_t b_min = -1;
	Double_t b_max = 1;
	Double_t Y_det[4], X = 0;
	TFile  *hfile = new TFile ("tree.root", "RECREATE");
	TTree tree("T","Coordinates");
	tree.Branch("X_coord", &X, "X/D");
	tree.Branch("Y_detector", &Y_det, "Y_det/D");
	TRandom rnd;
	tree.SetEntries(1000);
	for (int i = 0; i < nEvents; ++i) {
		aParam = rnd.Uniform(a_min, a_max);
		bParam = rnd.Uniform(b_min, b_max);
		for (int k = 0; k < 5; ++k){
			X = stations[k];
			Y_det[k] = gRandom -> Gaus(aParam * stations[k] + bParam, 0.0150);
			tree.GetBranch("X_coord") -> Fill(); 
}
		tree.GetBranch("Y_detector") -> Fill ();
		for (int j = 0; j < 5; ++j){
			Y_det[j] = 0;
}
}
	hfile -> Write();
}
