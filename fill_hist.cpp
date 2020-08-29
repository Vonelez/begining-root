#include "fill_hist.h"
Filling_Hist::Filling_Hist(TTree *st){
	this -> st = st;
	this -> full = full;
}

Filling_Hist::~Filling_Hist() = default;

TH1F *Filling_Hist::solution(){
	auto *tree = new Read_Tree(st);
	TH1F *full = new TH1F("full", "time; t(ns); n", 100, -100., 1000.);
	N = st -> GetEntries();
	//std::cout << N << std::endl;
	for (Int_t i = 0; i < N; i++){
		st -> GetEntry(i);
		fill_hist(tree, full);
	}
	std::cout << "The Hist was filled" << std::endl;
	return full;
}

void Filling_Hist::fill_hist(Read_Tree *tree, TH1F *full){
	if ((tree -> nt00 == 1) && (tree -> nt08 == 1)){
		full -> Fill(0.0244*(tree -> tt00 - tree -> tt08));
	}
}
