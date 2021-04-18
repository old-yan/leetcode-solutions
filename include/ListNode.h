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
ostream&operator<<(ostream&out,ListNode*head){
	if(!head){
		out<<"empty listnode\n";
		return out;
	}
	int len=0;
	for(auto p=head;p;p=p->next)len++;
	out<<"length="<<len<<" ";
	for(auto p=head;p;p=p->next){
		out<<p->val;
		if(p->next)out<<"->";
		else out<<"\n";
	}
	return out;
}