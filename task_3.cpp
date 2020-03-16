void task_3() {
	TFile file("tree.root");
	TTree *t;
	file.GetObject("T", t);
	Double_t x_coord[5] = {100.0, 120.0, 140.0, 160.0, 180.0};
	Double_t x = 0, y = 0, errory[5];
	Double_t y_det[5];
	TGraph *g = new TGraph();
	t -> SetBranchAddress("Y_detector1", &y_det[0]);
	t -> SetBranchAddress("Y_detector2", &y_det[1]);
	t -> SetBranchAddress("Y_detector3", &y_det[2]);
	t -> SetBranchAddress("Y_detector4", &y_det[3]);
	t -> SetBranchAddress("Y_detector5", &y_det[4]);
	Int_t n = t -> GetEntries();
	for (int nn = 0; nn < n; nn++){
	t -> GetEntry(nn);
	for (int i = 0; i < 5; ++i){
		x = 100 + i*20;
		y = y_det[i];
		g -> SetPoint(i, x, y);
}
	TF1 *appr = new TF1("appr", "[0]*x + [1]", -50, 50);
	g -> Fit(appr, "Gaus");
	cout << "\n" << endl;
	for (int i = 0; i < 5; ++i){
		errory[i] = g -> GetPointY(i);
		cout << errory[i] - y_det[i] << endl;
}
}
}
