#pragma once
#include <vector>
#include <iostream>
using namespace std;

template<class T>
vector<T> operator+(const vector<T> &left, const vector<T> &right){
	if (left.size() != right.size()){
		throw exception("vector add error\n");
	}
	vector<T> out;
	for (int i = 0; i < left.size(); ++i){
		out.push_back(left[i] + right[i]);
	}
	return out;
}

template<class T>
vector<T> operator-(const vector<T> &left, const vector<T> &right){
	if (left.size() != right.size()){
		throw exception("vector sub error\n");
	}
	vector<T> out;
	for (int i = 0; i < left.size(); ++i){
		out.push_back(left[i] - right[i]);
	}
	return out;
}

template<class T>
T operator*(const vector<T> &left, const vector<T> &right){
	if (left.size() != right.size()){
		throw exception("vector multi error\n");
	}
	T out=0;
	for (int i = 0; i < left.size(); ++i){
		out+=left[i] * right[i];
	}
	return out;
}

template<class T>
void v_show(const vector<T> &a){
	for (int i = 0; i < a.size(); ++i){
		cout << a[i] << " ";
	}
	cout << endl;
}

template<class T>
void vv_show(const vector<vector<T>> &a){
	for (auto i : a){
		v_show(i);
	}
	cout << endl;
}