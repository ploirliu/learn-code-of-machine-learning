#pragma once
#include <vector>
#include <set>
using namespace std;


vector<vector<double>> rand_vv_data(int h, int w = 2){
	set<vector<double>> cache;
	while (cache.size() < h){
		vector<double> tmp;
		for (int i = 0; i < w; ++i){
			double tmp2 = rand() % 100;
			tmp.push_back(tmp2);
		}
		cache.insert(tmp);
	}
	return vector<vector<double>>(cache.begin(), cache.end());
}


vector<double> rand_v_data(int w = 2){
	vector<double> out;
	for (int i = 0; i < w; ++i){
		double tmp2 = rand() % 100;
		out.push_back(tmp2);
	}
	return out;
}