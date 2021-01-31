#pragma once
#include <iostream>
using namespace std;
#define OLDYAN_LISTNODE

struct ListNode {
	int val;
	ListNode* next;
	ListNode() :val(-1), next(NULL) {}
	ListNode(int x) : val(x), next(NULL) {}
	ListNode(int x,ListNode*_next):val(x),next(_next){}
};
