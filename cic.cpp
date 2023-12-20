#include "cic.h"
#include <cstring>
using namespace std;

CIC::CIC(int Order, int DownRate) {
	order = Order;
	downRate = DownRate;

	delayI = new double[Order];
	currentI = new double[Order];
	memset(delayI, 0, Order * sizeof(double));

	delayC = new double[Order];
	currentC = new double[Order];
	memset(delayC, 0, Order * sizeof(double));

	counter = 0;
}

CIC::~CIC() {
	delete[] delayI;
	delete[] delayC;
	delete[] currentI;
	delete[] currentC;
}

double CIC::integral(double signal) {
	currentI[0] = signal;
	for (int i = 1; i < order; i++) {
		currentI[i] = currentI[i - 1] + delayI[i];
	}
	memcpy(delayI, currentI, order * sizeof(double));
	return currentI[order - 1];
}

double CIC::comb(double signal) {
	currentC[0] = signal;
	for (int i = 1; i < order; i++) {
		currentC[i] = currentC[i - 1] - delayC[i - 1];
	}
	memcpy(delayC, currentC, order * sizeof(double));
	return currentC[order - 1];
}

void CIC::reset() {
	memset(delayI, 0, order * sizeof(double));
	memset(delayC, 0, order * sizeof(double));
}

bool CIC::downCounter() {
	if (++counter == downRate) {
		counter = 0;
		return true;
	}
	return false;
}
