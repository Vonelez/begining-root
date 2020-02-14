#include <iostream>
#include <TH1.h>
#include <TFile.h>
#include <TRandom.h>
#include <TBrowser.h>
using namespace std;
void idk() {
TH1F *hist = new TH1F("hgaus", "A Gauss Function", 1000, -5., 5.);
TRandom rnd;
Double_t x = 0;
for (int i = 0; i < 1000; ++i) {
x = rnd.Gaus(2.5, 1.0);
hist->Fill(x);
x = 0;
}
TFile outfile ("output_4.root", "RECREATE");
hist->Write("Gauss");
outfile.Close();
}
