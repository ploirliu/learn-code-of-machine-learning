#pragma once
#include "stdafx.h"

class naive_bayes{
	vector<double> py;
	vector<vector<vector<double>>> px_y;
	void compute_py(const vector<double> &label);
	void compute_px_y();
public:
	void setdata(const vector<double> &data,const vector<double> &label);
	void predict(const vector<double> &f);
};

void naive_bayes::setdata(const vector<double> &data, const vector<double> &label){
	py.clear();
	px_y.clear();
}

void naive_bayes::predict(const vector<double> &f){}