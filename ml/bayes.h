#pragma once
#include "stdafx.h"

class naive_bayes{
	vector<double> py;
	vector<vector<vector<double>>> px_y;
	virtual void init(const vector<vector<double>> &data, const vector<double> &label);
	virtual void count(const vector<vector<double>> &data, const vector<double> &label);
	virtual void compute(const vector<vector<double>> &data, const vector<double> &label);
public:
	void setdata(const vector<vector<double>> &data, const vector<double> &label);
	int predict(const vector<double> &f);
};


void naive_bayes::init(const vector<vector<double>> &data, const vector<double> &label){
	py.clear();
	px_y.clear();
	int len_y = 0;
	for (double tmp : label){
		len_y = max(len_y, (int)tmp);
	}
	py.resize(len_y, 0);

	int x_len = data.begin()->size();
	vector<vector<double>> base(x_len);
	for (int i = 0; i < x_len; ++i){
		int len_tmp = 0;
		for (int j = 0; j < data.size(); ++j){
			len_tmp = max(len_tmp, (int)data[j][i]);
		}
		base[i].resize(len_tmp,0);
	}
	for (int i = 0; i < len_y; ++i){
		px_y.push_back(base);
	}
}

void naive_bayes::count(const vector<vector<double>> &data, const vector<double> &label){
	for (double tmp : label){
		++py[tmp];
	}
	for (int i = 0; i < data.size(); ++i){
		for (int j = 0; j < data[i].size(); ++j){
			++px_y[label[i]][j][data[i][j]];
		}
	}
}
void naive_bayes::compute(const vector<vector<double>> &data, const vector<double> &label){
	for (int i = 0; i < py.size(); ++i){
		for (int j = 0; j < px_y[i].size(); ++j){
			for (int k = 0; k < px_y[i][j].size(); ++k){
				px_y[i][j][k] = (double)px_y[i][j][k] / (double)label[i];
			}
		}
	}
	for (int i = 0; i < py.size(); ++i){
		py[i] = (double)py[i] / (double)label.size();
	}
}

void naive_bayes::setdata(const vector<vector<double>> &data, const vector<double> &label){
	init(data, label);
	count(data, label);
	compute(data, label);
}

int naive_bayes::predict(const vector<double> &f){
	int outid = -1;
	int tmax = -1;
	for (int i = 0; i < py.size(); ++i){
		double tmp = py[i];
		for (int j = 0; j < px_y[i].size(); ++j){
			tmp = (double)tmp*(double)px_y[i][j][f[j]];
		}
		if (outid == -1 || tmax < tmp){
			outid = i;
			tmax = tmp;
		}
	}
	return outid;
}

//class bayes : public naive_bayes{
//	double limta;
//	void count(const vector<vector<double>> &data, const vector<double> &label);
//	void compute(const vector<vector<double>> &data, const vector<double> &label);
//public:
//	bayes(double _limta=1.0f) :limta(_limta){}
//};
//
//void bayes::count(const vector<vector<double>> &data, const vector<double> &label){
//
//}
//
//void bayes::compute(const vector<vector<double>> &data, const vector<double> &label){
//
//}