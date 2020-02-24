#include <TRandom.h>

void task_2() {
	Double_t stations[5] = {100.0, 120.0, 140.0, 160.0, 180.0}; //coordinates in cm
	Int_t nEvents = 100; //put here the number of events
	Double_t aParam, bParam;
	Double_t a_min = 0;
	Double_t a_max = 10;
	Double_t b_min = 0;
	Double_t b_max = 10;

	TRandom rnd;

	for (int i = 0; i < nEvents; ++i) {
		aParam = rnd.Uniform(a_min, a_max);
		bParam = rnd.Uniform(b_min, b_max);
		//put your code here
	}
}