#include "includes/generate_event.h"
#include "includes/read_data.h"
#include <iostream>
int main(){
	Int_t nEvents = 10000;
	Generate_event *event = new Generate_event(nEvents);
	event -> Generate_event::generate_event();
	TTree *t = new TTree();
	TString dir("/home/sonya/task_4/");
	TString fileName("t");
  	TString ending(".root");
	TString RootName(dir + fileName + ending);
	TFile *file = new TFile();
  	file = TFile::Open(RootName, "read");
	file -> GetObject("t", t);
	Read_data *data = new Read_data(t);
	data -> Read_data::read_data();
}
