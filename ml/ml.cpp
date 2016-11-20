// ml.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "perceptron.h"
#include "kdTree.h"
#include "knn_force.h"
#include "my_math.h"
#include "my_rand_data.h"
void perceptron_test(){
	vector<vector<double>> t1 = { { 3, 3 }, { 4, 3 } };
	vector<vector<double>> t2 = { { 1, 1 } };

	perceptron *t = new ori_p();
	t->compute_data(t1, t2);
	t->show();
}

void knn_show(const vector<vector<double>> &a1, const vector<double> &a2){
	for (auto i : a1){
		for (auto j : i){
			cout << j << ' ';
		}
		cout << len(i, a2) << endl;
	}
}
void kdTree_test(){
	kdTree *t = new kdTree();
	//vector<vector<double>> all = { { 2, 3 }, { 5, 4 }, { 9, 6 }, { 4, 7 }, { 8, 1 }, { 7, 2 } };
	vector<vector<double>> all = rand_vv_data(50);
	vector<double> f = rand_v_data();
	v_show(f);


	t->build(all);
	//vector<double> f = { 1, 1 };
	auto out1 = t->find(f,5);
	auto out2=knn_force(all, f,5);
	sort(out1.begin(), out1.end());
	sort(out2.begin(), out2.end());
	cout << "kd-tree" << endl;
	//vv_show(out1);
	knn_show(out1, f);
	cout << "knn-force" << endl;
	//vv_show(out2);
	knn_show(out2, f);
}

int _tmain(int argc, _TCHAR* argv[])
{
	kdTree_test();
	return 0;
}

