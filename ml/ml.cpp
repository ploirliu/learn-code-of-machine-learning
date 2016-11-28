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

set<double> knn_cmp(const vector<vector<double>> &a1, const vector<double> &a2){
	set<double> cache;
	for (auto i : a1){
		cache.insert(len(i, a2));
	}
	return cache;
}

void kdTree_test(int len){
	kdTree *t = new kdTree();
	vector<vector<double>> all = rand_vv_data(len,5);
	vector<double> f = rand_v_data(5);
	//if (len == 188){
	//	vv_show(all);
	//	v_show(f);
	//}
//	v_show(f);

	t->build(all);
	//vector<double> f = { 1, 1 };
	auto out1 = t->find(f,5);
	auto out2=knn_force(all, f,5);
	cout <<len<< " find " << t->find_count << endl;
	sort(out1.begin(), out1.end());
	sort(out2.begin(), out2.end());
	if (out1.size() != out2.size()){
		cout << len << " : error" << endl;
		//cout <<  " : error" << endl;
		return;
	}
	bool show_stu = false;
	set<double> cache_kd = knn_cmp(out1, f);
	set<double> cache_knn = knn_cmp(out2, f);
	if (cache_kd == cache_knn)
		show_stu = true;
	if (show_stu);
	//cout << len << " : right" << endl;
	//cout << " : right" << endl;
	else{
		cout << len << " : error" << endl;
		//cout << " : error" << endl;
		cout << "kd-tree" << endl;
		//vv_show(out1);
		knn_show(out1, f);
		cout << "knn-force" << endl;
		//vv_show(out2);
		knn_show(out2, f);
	}
	delete t;
}

void kdTree_test(){
	kdTree *t = new kdTree();
	vector<vector<double>> all = {
		{0 ,11 	},
		{0 ,55	},
		{1 ,5	},
		{1 ,24	},
		{2 ,3	},
		{2 ,29	},
		{2 ,75	},
		{2 ,83	},
		{3 ,0	},
		{3 ,90	},
		{4 ,25	},
		{4 ,48	},
		{5 ,80	},
		{5 ,86	},
		{6 ,15	},
		{7 ,37	},
		{7 ,40	},
		{8 ,72	},
		{9 ,27	},
		{10,74	},
		{11,45	},
		{11,50	},
		{11,61	},
		{11,62	},
		{15,48	},
		{15,55	},
		{15,83	},
		{16,70	},
		{16,97	},
		{17,33	},
		{17,71	},
		{17,72	},
		{18,16	},
		{18,62	},
		{20,19	},
		{20,33	},
		{20,61	},
		{21,25	},
		{22,55	},
		{23,97	},
		{24,54	},
		{25,2	},
		{25,19	},
		{25,26	},
		{25,96	},
		{26,38	},
		{26,62	},
		{27,48	},
		{28,53	},
		{28,66	},
		{29,6	},
		{30,18	},
		{30,52	},
		{31,59	},
		{32,43	},
		{33,29	},
		{33,39	},
		{33,53	},
		{33,67	},
		{34,16	},
		{34,36	},
		{34,66	},
		{35,93	},
		{36,40	},
		{37,50	},
		{39,13	},
		{39,15	},
		{40,9	},
		{40,71	},
		{40,89	},
		{41,57	},
		{41,84	},
		{41,96	},
		{42,11	},
		{42,16	},
		{42,60	},
		{42,61	},
		{43,29	},
		{44,38	},
		{44,55	},
		{44,58	},
		{44,93	},
		{45,32	},
		{45,60	},
		{45,99	},
		{46,44	},
		{46,61	},
		{50,71	},
		{51,32	},
		{51,68	},
		{52,12	},
		{54,60	},
		{54,79	},
		{55,14	},
		{55,69	},
		{55,71	},
		{55,79	},
		{55,83	},
		{55,93	},
		{56,60	},
		{56,68	},
		{56,87	},
		{57,62	},
		{57,76	},
		{58,11	},
		{58,57	},
		{58,96	},
		{59,17	},
		{59,23	},
		{59,60	},
		{60,86	},
		{61,47	},
		{62,19	},
		{63,18	},
		{64,43	},
		{64,62	},
		{64,75	},
		{64,84	},
		{64,94	},
		{65,12	},
		{66,7	},
		{66,48	},
		{66,58	},
		{66,91	},
		{66,97	},
		{67,19	},
		{67,42	},
		{67,49	},
		{68,0	},
		{68,21	},
		{68,24	},
		{68,68	},
		{69,40	},
		{70,72	},
		{71,39	},
		{71,66	},
		{72,81	},
		{73,8	},
		{73,48	},
		{73,75	},
		{74,64	},
		{74,76	},
		{75,20	},
		{75,36	},
		{76,98	},
		{77,0	},
		{77,25	},
		{78,27	},
		{78,76	},
		{79,4	},
		{79,24	},
		{79,25	},
		{80,23	},
		{80,98	},
		{81,10	},
		{82,90	},
		{83,43	},
		{84,18	},
		{85,49	},
		{87,10	},
		{88,1	},
		{88,9	},
		{88,32	},
		{88,39	},
		{88,92	},
		{89,8	},
		{89,38	},
		{90,38	},
		{90,57	},
		{91,15	},
		{91,43	},
		{93,60	},
		{93,71	},
		{94,9	},
		{94,19	},
		{94,70	},
		{96,30	},
		{96,35	},
		{96,49	},
		{96,95	},
		{97,7	},
		{97,18	},
		{97,61	},
		{97,92	},
		{98,35	},
		{99,31	},
		{99,55	},
		{99,84	}
	};
	vector<double> f = {43,25};

	t->build(all);
	cout << "id:" << t->find_node({ 33,29 }) << endl;
	//vector<double> f = { 1, 1 };
	auto out1 = t->find(f, 5);
	auto out2 = knn_force(all, f, 5);
	sort(out1.begin(), out1.end());
	sort(out2.begin(), out2.end());
	if (out1.size() != out2.size()){
		cout <<  " : error" << endl;
		return;
	}
	bool show_stu = false;
	set<double> cache_kd = knn_cmp(out1, f);
	set<double> cache_knn = knn_cmp(out2, f);
	if (cache_kd == cache_knn)
		show_stu = true;
	if (show_stu)
	cout << " : right" << endl;
	else{
		cout << " : error" << endl;
		cout << "kd-tree" << endl;
		//vv_show(out1);
		knn_show(out1, f);
		cout << "knn-force" << endl;
		//vv_show(out2);
		knn_show(out2, f);
	}
	delete t;
}

void test(){
	for (int i = 10; i < 5000; ++i){
		kdTree_test(i);
		if (i % 100==0)
			cout << i << " passed" << endl;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	//test();
	kdTree_test(100000);
	//kdTree_test();
	return 0;
}

