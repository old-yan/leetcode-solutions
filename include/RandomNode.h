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
#include <iomanip>
#include <numeric>
using namespace std;
#define OLDYAN_RANDOMNODE

struct RandomNode{
    int val;
    RandomNode* next;
    RandomNode* random;
	RandomNode():val(0),next(nullptr),random(nullptr) {}
    RandomNode(int _val):val(_val),next(nullptr),random(nullptr) {}
	RandomNode(int _val,RandomNode*_next,RandomNode*_random):val(_val),next(_next),random(_random) {}
};
RandomNode*makerandomnode(const string&s){
	vector<RandomNode*>v;
	vector<int>v2;
	for(int i=0;i<s.size()&&s[i]!=']';){
		while(s[++i]=='[');
		int signal=1;
		if(s[i]=='-'){
			signal=-1;
			i++;
		}
		int val=0;
		while(isdigit(s[i])){
			val=val*10+s[i++]-'0';
		}
		v.push_back(new RandomNode(signal*val));
		i++;
		if(s[i]=='n'){
			v2.push_back(-1);
			i+=5;
		}
		else{
			int random=0;
			while(isdigit(s[i])){
				random=random*10+s[i++]-'0';
			}
			v2.push_back(random);
			i++;
		}
	}
	for(int i=0;i<v.size();i++){
		if(v2[i]>=0){
			v[i]->random=v[v2[i]];
		}
		if(i+1<v.size())v[i]->next=v[i+1];
	}
	return v[0];
}
ostream&operator<<(ostream&out,RandomNode*head){
	if(!head){
		out<<"empty randomnode\n";
		return out;
	}
	vector<RandomNode*>v;
	for(auto p=head;p;p=p->next)v.push_back(p);
	if(v.size()>1)out<<v.size()<<" nodes in the randomnode:\n";
	else out<<"1 node in the randomnode:\n";
	for(int i=0;i<v.size();i++){
		out<<"idx:"<<setw(2)<<i<<": val="<<setw(5)<<v[i]->val<<"  random=";
		if(v[i]->random)out<<setw(5)<<v[i]->random->val<<endl;
		else out<<setw(5)<<"null"<<endl;
	}
	return out;
}