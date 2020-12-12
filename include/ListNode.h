#pragma once
#include <iostream>
#include <fstream>
#include <tuple>
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

struct ListNode {
	int val;
	ListNode* next;
	ListNode() :val(-1), next(NULL) {}
	ListNode(int x) : val(x), next(NULL) {}
};
