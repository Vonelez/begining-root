
#include <iostream>
#include <TH1.h>
#include <TFile.h>
#include <TRandom.h>

using namespace std;

void task_1_original() {
	TH1F *hist = new TH1F("hgaus", "A Gauss Function", 100, -5., 5.);
	TRandom rnd;
	Double_t x = 0;

	for (int i = 0; i < 10000; ++i) {
		x = rnd.Gaus(1.5, 1.0);
		hist->Fill(x);
		x = 0;
	}

	TFile outfile ("output.root", "RECREATE");
	hist->Write("Gauss");
	outfile.Close();
}
