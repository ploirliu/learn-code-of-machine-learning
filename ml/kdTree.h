#pragma once
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <unordered_set>
#include "my_math.h"
using namespace std;

class tree{
public:
	vector<double> nums;
	int id;
	tree* left;
	tree* right;
	tree() :left(NULL), right(NULL){};
	tree(const vector<double> &_nums) :nums(_nums), left(NULL), right(NULL){};
	~tree(){
		if (left)
			delete left;
		if (right)
			delete right;
	};
};

class kdTree
{
	tree *root;
	void clear(){
		if (root)
			delete root;
		root = NULL;
	}
	//double findmid(const vector<double> &nums);
	double findmid(vector<double> nums);
	tree* my_build(const vector<vector<double>> &nums, int id = 0,int tree_id=1);
	void my_find(tree* root, const vector<double> &f, int k, multiset<vector<double>> &out, double &now_max, int id = 0);
	void my_find_brother(tree* root, const vector<double> &f, int k, multiset<vector<double>> &out, double &now_max, int id);
	double len(const vector<double> &left,const vector<double> &right,int k=2);
	int find_node(tree* root, const vector<double> &f, int id = 0);
	void out_insert(const vector<double> &f, int k, multiset<vector<double>> &out,const vector<double> &now,double &now_max);
public:
	kdTree();
	~kdTree();
	void build(const vector<vector<double>> &nums);
	vector<vector<double>> find(const vector<double> &f, int k = 1);
	int find_node(const vector<double> &f);

	int find_count;
};

