#pragma once
#ifndef CIC
#define CIC

#include <vector>
using namespace std;

vector<double> integration(vector<double> s, int level);
vector<double> comb(vector<double> s, int level);
vector<double> downSample(vector<double> s, int rate);
vector<double> upSample(vector<double> s, int rate);

#endif