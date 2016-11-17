// ml.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "perceptron.h"

void my_test(){
	vector<vector<double>> t1 = { { 3, 3 }, { 4, 3 } };
	vector<vector<double>> t2 = { { 1, 1 } };

	perceptron *t = new ori_p();
	t->compute_data(t1, t2);
	t->show();
}

int _tmain(int argc, _TCHAR* argv[])
{
	my_test();
	return 0;
}

