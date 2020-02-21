#include <iostream>
#include <TH1.h>
#include <TFile.h>
#include <TRandom.h>
#include <TCanvas.h>
#include <cstdio>
#include <TObject.h>

using namespace std;

void task_1_new() {
TCanvas *c1 = new TCanvas ("c1", "Three hists", 1200, 1200);
c1->SetGrid();
c1 -> cd();

TH1S *hist = new TH1S("hist", "Poisson distribution", 100, -5., 15.);
TH1S *h2 = new TH1S ("h2", "Distributions; X; Y", 100, -5., 15.);
TH1S *h3 = new TH1S ("h3", "Landau distribution; X; Y", 400, -5., 15.);

 hist->SetMarkerStyle(16);
   hist->SetFillColor(16);
   h2->SetFillColor(42);
   h3->SetFillColor(96);
   TSlider *slider = 0;

gRandom->SetSeed();
const Int_t kUPDATE = 500;
   Float_t xhist, xh2, xh3;
   for ( Int_t i=0; i<10000; i++) {
      xh2   = gRandom->Poisson(5);
      xhist = gRandom->Gaus(4,1.5);

int binmaxhist = hist -> GetMaximumBin();
      double histx = hist -> GetXaxis()->GetBinCenter(binmaxhist);


      xh3   = gRandom->Landau(1,0.15);
      hist-> Fill(xhist);
      h2-> Fill(xh2);
      h3-> Fill(xh3); 
      if (i && (i%kUPDATE) == 0) {
         if (i == kUPDATE) {
            h2->Draw();
            hist->Draw("same");
            h3->Draw("same");
            c1->Update();}
}
}
int maxix = hist -> GetMaximumBin();
double maxx = hist -> GetXaxis() -> GetBinCenter(maxix);
int maxiy = h2 -> GetMaximumBin();
double maxy = h2 -> GetXaxis() -> GetBinCenter(maxiy);
int maxiz = h3 -> GetMaximumBin();
double maxz = h3 -> GetXaxis() -> GetBinCenter(maxiz);

cout << "Gauss maximum: " << hist -> GetMaximum() << endl;
cout << "it's abscissa: " << maxx << endl;
cout << "Poisson maximum: " << h2 -> GetMaximum() << endl;
cout << "it's abscissa: " << maxy << endl;
cout << "Landau maximum: " <<  h3 -> GetMaximum() << endl;
cout << "it's abscissa: " << maxz << endl;

c1 -> Modified();
c1 -> Print("outfile.pdf");
hist->Write("threesome");

}
