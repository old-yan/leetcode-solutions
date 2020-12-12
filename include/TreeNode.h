#pragma once
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
// TreeNode* maketreenode(vector<int>v) {
// 	TreeNode* p;
// 	if (v[0] == null)return nullptr;
// 	else p = new TreeNode(v[0]);
// 	queue<TreeNode*>Q;
// 	Q.push(p);
// 	int cursor = 1;
// 	while (Q.size()) {
// 		TreeNode* q = Q.front();
// 		Q.pop();
// 		if (cursor < v.size()) {
// 			if (v[cursor] == null)q->left = nullptr;
// 			else {
// 				q->left = new TreeNode(v[cursor]);
// 				Q.push(q->left);
// 			}
// 			cursor++;
// 		}
// 		else {
// 			q->left = nullptr;
// 		}
// 		if (cursor < v.size()) {
// 			if (v[cursor] == null)q->right = nullptr;
// 			else {
// 				q->right = new TreeNode(v[cursor]);
// 				Q.push(q->right);
// 			}
// 			cursor++;
// 		}
// 		else {
// 			q->right = nullptr;
// 		}
// 	}
// 	return p;
// }