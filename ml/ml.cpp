// ml.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "perceptron.h"
#include "kdTree.h"
#include "knn_force.h"
void perceptron_test(){
	vector<vector<double>> t1 = { { 3, 3 }, { 4, 3 } };
	vector<vector<double>> t2 = { { 1, 1 } };

	perceptron *t = new ori_p();
	t->compute_data(t1, t2);
	t->show();
}

void kdTree_test(){
	kdTree *t = new kdTree();
	t->build({ { 2, 3 }, { 5, 4 }, { 9, 6 }, { 4, 7 }, { 8, 1 }, { 7, 2 }});

	auto out2=knn_force({ { 2, 3 }, { 5, 4 }, { 9, 6 }, { 4, 7 }, { 8, 1 }, { 7, 2 } }, { 1, 1 });
	for (auto i : out2){
		for (auto j : i){
			cout << j << ' ';
		}
		cout << endl;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	kdTree_test();
	return 0;
}

