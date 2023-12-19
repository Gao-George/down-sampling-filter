#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include "cic.h"
using namespace std;

const double PI = 3.141592653589793;

int main() {
	vector<double> xAxis, original;
	
	// ��x��
	for (int x = -250; x < 251; x++) {
		xAxis.push_back(x);
	}
	// ��ԭ����ͼ��
	for (int i = 0; i < 100; i++) {
		original.push_back(sin(i * PI / 100));
	}
	for (int i = 0; i < 100; i++) {
		original.push_back(0);
	}
	for (int i = 0; i < 100; i++) {
		original.push_back(sin(i * PI / 100));
	}
	for (int i = 0; i < 100; i++) {
		original.push_back(0);
	}
	for (int i = 0; i < 100; i++) {
		original.push_back(sin(i * PI / 100));
	}

	// �ϱ�Ƶ
	vector<double> up = comb(original, 5); 
	up = upSample(up, 3);
	up = integration(up, 5);
	
	// �±�Ƶ
	vector<double> down = integration(original, 5);
	down = downSample(down, 3);
	down = comb(down, 5);
	
	// �����ݵ�д��CSV
	ofstream plt;
	plt.open("plot.csv");
	plt << "x,originalSignal,upSample,downSample" << endl;

	for (int i = 0; i < 500; i++) {
		if (i >= down.size() && i < (down.size()*2-1)) {
			plt << xAxis[i] << ',' << original[i] << ',' << up[i+500] << ',' << down[i-167] << endl;
		}
		else {
			plt << xAxis[i] << ',' << original[i] << ',' << up[i + 500] << ',' << 0 << endl;
		}
		
	}

	plt.close();
}
