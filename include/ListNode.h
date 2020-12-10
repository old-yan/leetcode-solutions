#pragma once
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() :val(-1), next(NULL) {}
	ListNode(int x) : val(x), next(NULL) {}
};
// ListNode* head;
// ListNode* makelistnode(vector<int>v) {
// 	if (v.empty())return nullptr;
// 	ListNode* p = new ListNode(-1);
// 	ListNode* q = p;
// 	for (int b : v) {
// 		q->next = new ListNode(b);
// 		q = q->next;
// 	}
// 	return p->next;
// }
