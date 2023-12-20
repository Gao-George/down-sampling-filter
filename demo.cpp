#include <iostream>
#include <cmath>
#include <fstream>
#include "cic.h"
using namespace std;

int main() {
	const double PI = 3.1415926535;
	
	// generate a signal with carrier
	double carried[800];
	for (int i = 0; i < 800; i++) {
		carried[i] = sin(PI / 400 * i) * sin(PI / 12 * i);
	}

	// core part of CIC filtering
	CIC filter(5, 20);		// initiate a 5-order CIC filter, with a down sampling rate of 20
	double output[40];
	double integrated;
	for (int i = 0; i < 800; i++) {
		integrated = filter.integral(carried[i]);		// upon the input of each bit, do integration
		if (filter.downCounter()) {				// down sampling
			output[i / 20] = filter.comb(integrated);	// after down sanpling, use comb filter
		}
	}

	// plot the result
	double x[40];
	for (int i = 0; i < 40; i++) {
		x[i] = i;
	}
	ofstream plt;
	plt.open("plot.csv");
	plt << "filtered signal,x" << endl;
	for (int i = 0; i < 40; i++) {
		plt << output[i] << ',' << x[i] << endl;
	}
	plt.close();
}
