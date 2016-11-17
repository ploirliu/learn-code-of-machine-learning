#pragma once
#include <vector>
#include <iostream>
using namespace std;

class perceptron
{
public:
	perceptron();
	~perceptron();
	virtual void compute_data(vector<vector<double>> &t1, vector<vector<double>> &t2) = 0;
	void show(){
		cout << "the perceptron function is :" << endl;
		for (int i = 0; i < w.size(); ++i){
			if (i != 0)
				cout << " + ";
			cout << w[i] << " * x" << i;
		}
		if (b>0.0000001f){
			cout << " + " << b;
		}
		if (b < -0.0000001f){
			cout << " + (" << b << ")";
		}
		cout << endl;
	}
protected:
	vector<double> w;
	double b;
};

class ori_p :public perceptron{
public:
	void compute_data(vector<vector<double>> &t1, vector<vector<double>> &t2);
private:
	bool change(vector<double> &data, int flag,double nita, vector<double> &_w, double &_b);
};


class pair_p :public perceptron{
public:
	void compute_data(vector<vector<double>> &t1, vector<vector<double>> &t2);
};


