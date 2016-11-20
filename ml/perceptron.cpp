#include "stdafx.h"
#include "perceptron.h"
#include "my_math.h"



perceptron::perceptron()
{
}


perceptron::~perceptron()
{
}


bool ori_p::change(vector<double> &data,int flag, double nita,vector<double> &_w, double &_b){
	for (int i = 0; i < _w.size(); ++i)
		_w[i] = 0;
	_b = 0;

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
				w[j] += _w[j];
			}
			b += _b;
		}
		for (int i = 0; i < t2.size(); ++i){
			stu = change(t2[i], -1, 1, _w, _b)|stu;
			for (int j = 0; j < _w.size(); ++j){
				w[j] += _w[j];
			}
			b += _b;
		}
	}
}


void pair_p::compute_data(vector<vector<double>> &t1, vector<vector<double>> &t2){
	double nita = 1;
	vector<double> stu1;
	int len = t1.size() + t2.size();
	vector<vector<double>> stu2(len, vector<double>(len, 0));
	for (int i = 0; i < t1.size(); ++i){
		for (int j = 0; j < t1.size(); ++j){
			stu2[i][j] = t1[i] * t1[j];
		}
		for (int j = t1.size(); j < len; ++j){
			stu2[i][j] = t1[i] * t2[j - t1.size()];
		}
		stu1.push_back(1);
	}
	for (int i = t1.size(); i < len; ++i){
		for (int j = 0; j < t1.size(); ++j){
			stu2[i][j] = t2[i - t1.size()] * t1[j];
		}
		for (int j = t1.size(); j < len; ++j){
			stu2[i][j] = t2[i - t1.size()] * t2[j - t1.size()];
		}
		stu1.push_back(-1);
	}

	w.resize(len, 0);
	b = 0;
	bool stu = true;
	while (stu){
		stu = false;
		for (int i = 0; i < t1.size(); ++i){
			double tmp = 0;
			for (int j = 0; j < len; ++j){
				tmp += w[j] * stu1[j] * stu2[j][i];
			}
			tmp += b;
			tmp *= 1;
			if (tmp <= 0){
				w[i] += nita;
				b += 1 * nita;
				stu = true;
			}
			//vector_show(w);
		}

		for (int i = t1.size(); i < len; ++i){
			double tmp = 0;
			for (int j = 0; j < len; ++j){
				tmp += w[j] * stu1[j] * stu2[j][i];
			}
			tmp += b;
			tmp *= -1;
			if (tmp <= 0){
				w[i] += nita;
				b += (-1)*nita;
				stu = true;
			}
			//vector_show(w);
		}
	}
	vector<double> _w(t1.begin()->size(),0);
	for (int i = 0; i < t1.size(); ++i){
		for (int j = 0; j < _w.size(); ++j){
			_w[j] += t1[i][j] * 1 * w[i];
		}
	}
	for (int i = t1.size(); i < len; ++i){
		for (int j = 0; j < _w.size(); ++j){
			_w[j] += t2[i-t1.size()][j] * (-1) * w[i];
		}
	}
	w = _w;
}