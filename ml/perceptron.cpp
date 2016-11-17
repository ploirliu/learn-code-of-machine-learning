#include "stdafx.h"
#include "perceptron.h"


perceptron::perceptron()
{
}


perceptron::~perceptron()
{
}


bool ori_p::change(vector<double> &data,int flag, double nita,vector<double> &_w, double _b){
	for (int i = 0; i < _w.size(); ++i)
		_w[i] = 0;

	double stu = 0;
	for (int i = 0; i < data.size(); ++i){
		stu += (double)data[i] * (double)w[i];
	}
	stu += b;
	stu *= flag;
	if (stu <= 0){
		for (int i = 0; i < data.size(); ++i){
			_w[i] += (double)nita*(double)flag*(double)data[i];
		}
		_b += (double)nita*(double)flag;
		return true;
	}
	return false;
}

void ori_p::compute_data(vector<vector<double>> &t1, vector<vector<double>> &t2){
	w.clear();
	b = 0.0f;
	w.resize(t1.begin()->size(), 0);

	bool stu = true;
	vector<double> _w(w.size(), 0);
	double _b = 0;
	while (stu){
		stu = false;
		for (int i = 0; i < t1.size(); ++i){
			stu = change(t1[i], 1, 1, _w, _b)|stu;
			for (int j = 0; j < _w.size(); ++j){
				w[i] += _w[i];
			}
			b += _b;
		}
		for (int i = 0; i < t2.size(); ++i){
			stu = change(t2[i], -1, 1, _w, _b)|stu;
			for (int j = 0; j < _w.size(); ++j){
				w[i] += _w[i];
			}
			b += _b;
		}
	}
}


void pair_p::compute_data(vector<vector<double>> &t1, vector<vector<double>> &t2){}