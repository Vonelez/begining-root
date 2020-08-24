#include "fill_hist.h"
Filling_Hist::Filling_Hist(TTree *st){
	this -> st = st;
	solution();
}

Filling_Hist::~Filling_Hist() = default;

void Filling_Hist::solution(){
	auto *tree = new Read_Tree(st);
	TH1F *full = new TH1F("full", "time; t(ns); n", 100, -100., 1000.);
	N = st -> GetEntries();
	//std::cout << N << std::endl;
	for (Int_t i = 0; i < N; i++){
		st -> GetEntry(i);
		fill_hist(tree, full);
	}
	TCanvas *c1 = new TCanvas ("c1", "", 1000, 1000);
	c1 -> cd();
	full -> Draw();
	c1 -> Update();
	c1 -> Modified();
	c1 -> Print("Time_Histogram.pdf");
	std::cout << "The Hist was filled" << std::endl;
}

void Filling_Hist::fill_hist(Read_Tree *tree, TH1F *time){
	if ((tree -> nt00 == 1) && (tree -> nt08 == 1)){
		time -> Fill(0.0244*(tree -> tt00 - tree -> tt08));
	}
}

TH1F *Filling_Hist::get_hist(){
	return full;
}
