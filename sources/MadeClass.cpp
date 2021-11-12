#define MadeClass_cxx

#include "../headers/MadeClass.h"
#include <TH1.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <cmath>

// Returns number of digits besides the first
int HowManyDigits(int number) {

   int digits = 0;

   while( (number /= 10) != 0 ) {

      ++digits;
   }

   return digits;
}

void CustomizeAxis(TAxis * axis) {

   axis->CenterTitle(kTRUE);
   axis->SetLabelSize(0.056);
   axis->SetTitleSize(0.054);
}


void MadeClass::Loop(Bool_t rootShell)
{
//   In a ROOT session, you can do:
//      root> .L MadeClass.C
//      root> MadeClass t
//      root> t.Loop();       // Loop on all entries

   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   int maxX = 0;
   int firstDigit = kMaxhits / (pow( 10, HowManyDigits(kMaxhits) ));
   ++firstDigit; 
   maxX = firstDigit * pow( 10, HowManyDigits(kMaxhits) );
   // this four lines above make smth like this 18828 -> 20000
   //                                           5394  -> 6000 and so on

   TH1I * hist = new TH1I("hist", ";hits_;entries", 100, 0, maxX);


   for(Long64_t jentry = 0; jentry < nentries ; ++jentry) {

      Long64_t ientry = LoadTree(jentry);
      if(ientry < 0) { break; }

      fChain->GetEntry(jentry);

      hist->Fill(hits_);
   }

   TAxis * xax = hist->GetXaxis(),
         * yax = hist->GetYaxis();

   CustomizeAxis(xax);
   CustomizeAxis(yax);


   if(rootShell) {

      hist->Draw();
   }
   else {

      TCanvas * c = new TCanvas("can", "canvas", 1300, 700);
      c->cd();
      c->SetLogy();

      hist->Draw();

      char buffer[30];

      std::cout << "Enter any key to print and exit: ";
      std::cin >> buffer;

      c->Print("hist.png");
   }

}