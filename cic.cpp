#include <vector>
using namespace std;

vector<double> integration(vector<double> s, int level) {
	int length = s.size();
	vector<double> buffer;
	for (int l = 0; l < level; l++) {
		buffer.push_back(s[0]);
		for (int i = 1; i < length; i++) {
			buffer.push_back(buffer[i - 1] + s[i]);
		}
		s.clear();
		buffer.swap(s);
	}
	return s;
}

vector<double> comb(vector<double> s, int level) {
	vector<double> buffer;
	int length = s.size();
	for (int l = 0; l < level; l++) {
		buffer.push_back(0);
		for (int i = 1; i < length; i++) {
			buffer.push_back(s[i] - s[i - 1]);
		}
		s.clear();
		buffer.swap(s);
	}
	return s;
}

vector<double> downSample(vector<double> s, int rate) {
	vector<double> ans;
	for (int i = 0; i < s.size(); i++) {
		if (i % rate == 0) {
			ans.push_back(s[i]);
		}
	}
	return ans;
}

vector<double> upSample(vector<double> s, int rate) {
	vector<double> ans;
	for (double& n : s) {
		ans.push_back(n);
		for (int i = 0; i < rate - 1; i++) {
			ans.push_back(0);
		}
	}
	return ans;
}