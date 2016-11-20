#include <vector>
#include <map>
#include <algorithm>
#include <math.h>
using namespace std;

template<class T>
double len(const vector<T> &left, const vector<T> &right,int k=2){
	double out = 0;
	if (left.size() != right.size()){
		throw exception("vector len error, left's len not equal to right's len\n");
	}
	for (int i = 0; i < left.size(); ++i){
		double tmp = (double)left[i] - (double)right[i];
		out += pow(tmp, k);
	}
	return pow(out, 1.0 / (double)k);
}

vector<vector<double>> knn_force(const vector<vector<double>> &nums,const vector<double> &f,int k=1){
	map<double, vector<vector<double>>> cache;
	for (auto i : nums){
		double l = len(i, f);
		cache[l].push_back(i);
	}
	vector<vector<double>> out;
	for (auto i : cache){
		for (auto j : i.second){
			out.push_back(j);
			if (out.size() >= k)
				break;
		}
		if (out.size() >= k)
			break;
	}
	return out;
}