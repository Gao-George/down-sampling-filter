#pragma once
#ifndef CICfilter
#define CICfilter

class CIC {
private:
	int order;
	int counter;
	int downRate;
	double* delayI, * currentI;
	double* delayC, * currentC;

public:
	CIC(int Order, int DownRate);
	~CIC();

	double integral(double signal);
	double comb(double signal);

	void reset();

	bool downCounter();
};

#endif