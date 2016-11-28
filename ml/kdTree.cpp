#include "stdafx.h"
#include "kdTree.h"


kdTree::kdTree() :root(NULL)
{
}


kdTree::~kdTree()
{
	clear();
}

//double kdTree::findmid(vector<double> nums){
//	if (nums.size() == 1)
//		return nums[0];
//	int id = nums.size() / 2;
//	multiset<double> cache;
//	for (double d : nums){
//		if (cache.size() < id){
//			cache.insert(d);
//		}
//		else if (d < *--cache.end()){
//			cache.erase(--cache.end());
//			cache.insert(d);
//		}
//	}
//	return *--cache.end();
//}

double kdTree::findmid(vector<double> nums){
	sort(nums.begin(), nums.end());
	return nums[nums.size() / 2];
}

void kdTree::build(const vector<vector<double>> &nums){
	clear();
	root=my_build(nums);
}

tree* kdTree::my_build(const vector<vector<double>> &nums, int id,int tree_id){
	if (nums.size() == 0)
		return NULL;
	vector<double> cache;
	for (int i = 0; i < nums.size(); ++i){
		cache.push_back(nums[i][id]);
	}
	double mid = findmid(cache);
	vector<double> now;
	now.clear();
	vector<vector<double>> left, right;
	for (int i = 0; i < nums.size(); ++i){
		if (cache[i] == mid && now.size() == 0){
			now = nums[i];
		}
		else if (cache[i] <= mid){
			left.push_back(nums[i]);
		}
		else if (cache[i] > mid){
			right.push_back(nums[i]);
		}
	}
	tree* out = new tree(now);
	out->id = tree_id;
	out->left = my_build(left, (id + 1) % nums.begin()->size(),2*tree_id);
	out->right = my_build(right, (id + 1) % nums.begin()->size(),2*tree_id+1);
	return out;
}

vector<vector<double>> kdTree::find(const vector<double> &f, int k){
	find_count = 0;
	multiset<vector<double>> out;
	double now_max=INT_MIN;
	my_find(root,f, k, out,now_max);
	vector<vector<double>> v_out;
	for (multiset<vector<double>>::iterator it = out.begin();
		it != out.end(); ++it){
		v_out.push_back(*it);
	}
	return v_out;
}

double kdTree::len(const vector<double> &left, const vector<double> &right,int k){
	if (left.size() != right.size()){
		throw exception("vector's len error , because left's len not equal to right's len\n");
	}
	double all = 0;
	for (int i = 0; i < left.size(); ++i){
		double tmp = left[i] - right[i];
		all += pow(tmp, k);
	}
	return sqrt(all);
}


void kdTree::my_find(tree* root, const vector<double> &f, int k, multiset<vector<double>> &out, double &now_max, int id){
	//cout << root->id << endl;
	//v_show(root->nums);

	int next_id = (id + 1) % f.size();
	double r_len = len(root->nums, f);

	//cout << r_len << endl;
	++find_count;
	bool left, right;
	left = right = true;
	if (now_max < 0){
		if (f[id]<=root->nums[id] && root->left){
			my_find(root->left, f, k, out, now_max, next_id);
			left = false;
		}
		else if (f[id]>root->nums[id]  && root->right){
			my_find(root->right, f, k, out, now_max, next_id);
			right = false;
		}
		else{
			left = right = false;
			if (root->left){
				my_find(root->left, f, k, out, now_max, next_id);
			}
			else if (root->right){
				my_find(root->right, f, k, out, now_max, next_id);
			}
			else{
				now_max = r_len;
				out.insert(root->nums);
				return;
			}
		}
	}
	
	out_insert(f, k, out, root->nums, now_max);

	double tmplen = abs(root->nums[id] - f[id]);
	if (tmplen <= now_max){
		if (left&& root->left)
			my_find_brother(root->left, f, k, out, now_max, next_id);
		if (right && root->right)
			my_find_brother(root->right, f, k, out, now_max, next_id);
	}
	return;
	if (left && root->left && abs((double)root->left->nums[next_id] - f[next_id]) < now_max){
		my_find_brother(root->left, f, k, out, now_max, next_id);
	}
	if (right && root->right && abs((double)root->right->nums[next_id] - f[next_id]) < now_max){
		my_find_brother(root->right, f, k, out, now_max, next_id);
	}

	//cout << root->id << ":" << out.size() << endl;
}

void kdTree::my_find_brother(tree* root, const vector<double> &f, int k, multiset<vector<double>> &out, double &now_max, int id){
	//cout << root->id << endl;
	//v_show(root->nums);

	int next_id = (id + 1) % f.size();
	out_insert(f, k, out, root->nums, now_max);

	++find_count;
	//if (root->left)
	//	my_find_brother(root->left, f, k, out, now_max, next_id);
	//if (root->right)
	//	my_find_brother(root->right, f, k, out, now_max, next_id);
	//return;
	double tmplen = abs(root->nums[id] - f[id]);
	if (tmplen <= now_max){
		if (root->left)
			my_find_brother(root->left, f, k, out, now_max, next_id);
		if (root->right)
			my_find_brother(root->right, f, k, out, now_max, next_id);
		return;
	}
	if (f[id] <= root->nums[id] && root->left){
		my_find_brother(root->left, f, k, out, now_max, next_id);
	}
	if (f[id] >= root->nums[id] && root->right){
		my_find_brother(root->right, f, k, out, now_max, next_id);
	}
	//cout << root->id <<":"<<out.size()<< endl;
}

int kdTree::find_node(tree* root, const vector<double> &f,int id){
	if (root == NULL)
		return INT_MAX;
	int next_id = (id + 1) % f.size();
	if (f == root->nums)
		return root->id;
	if (f[id] <= root->nums[id])
		return find_node(root->left, f, next_id);
	else
		return find_node(root->right, f, next_id); 
}

int kdTree::find_node(const vector<double> &f){
	return find_node(root, f);
}


void kdTree::out_insert(const vector<double> &f, int k, multiset<vector<double>> &out, const vector<double> &now,double &now_max){
	double r_len = len(now, f);
	if (out.size() < k){
		out.insert(now);
		now_max = max(now_max, r_len);
	}
	else if (r_len < now_max){
		double tmp = now_max;
		now_max = -1;
		out.insert(now);
		bool tmp_stu = true;
		for (multiset<vector<double>>::iterator it = out.begin();
			it != out.end();){
			double tmplen = len(*it, f);
			if (tmplen == tmp && tmp_stu){
				it = out.erase(it);
				tmp_stu = false;
			}
			else{
				now_max = max(now_max, tmplen);
				++it;
			}
		}
	}
}