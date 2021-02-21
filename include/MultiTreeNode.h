#pragma once
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define OLDYAN_MULTITREENODE


struct MultiTreeNode {
	int val;
	vector<MultiTreeNode*>children;
	MultiTreeNode():val(-1) {}
	MultiTreeNode(int _val) : val(_val){}
	MultiTreeNode(int _val, vector<MultiTreeNode*>_children) : val(_val), children(_children){}
	MultiTreeNode(string s){
        auto readmultitreenode=[&](int &i){
            vector<int>v;
            while(s[i]!='n'){
                int signal=1;
                if(s[i]=='-'){
                    signal=-1;
                    i++;
                }
                int val=0;
                while(isdigit(s[i]))val=val*10+s[i++]-'0';
                v.push_back(val);
                if(s[i])i++;
                else return v;
            }
            i+=4;
            if(s[i])i++;
            return v;
        };
        s.erase(remove(s.begin(),s.end(),' '),s.end());
		s.erase(remove(s.begin(),s.end(),'['),s.end());
		s.erase(remove(s.begin(),s.end(),']'),s.end());
        queue<MultiTreeNode*>Q;
        int i=0;
        auto v=readmultitreenode(i);
        if(!v.size())return;
        val=v[0];
        Q.push(this);
        while(i<s.size()){
            auto p=Q.front();
            Q.pop();
            auto v=readmultitreenode(i);
            for(int a:v){
                p->children.push_back(new MultiTreeNode(a));
                Q.push(p->children.back());
            }
        }
	}
};