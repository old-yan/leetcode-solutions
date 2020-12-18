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

pair<bool,int> readtreenode(string&s,int &i){
	if(s[i]=='n'){
		i+=4;
		if(s[i])i++;
		return make_pair(false,0);
	}
	else{
		int signal=1;
		if(s[i]=='-'){
			signal=-1;
			i++;
		}
		int val=0;
		while(isdigit(s[i]))val=val*10+s[i++]-'0';
		if(s[i])i++;
		return make_pair(true,val*signal);
	}
}
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(NULL), right(NULL) {}
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	TreeNode(int x, TreeNode* _left, TreeNode* _right) : val(x), left(_left), right(_right) {}
	TreeNode(string s){
		if(s[0]=='['&&s.back()==']')s=s.substr(1,s.size()-2);
		else if(s[0]=='[')s=s.substr(1,s.size()-1);
		else if(s.back()==']')s.pop_back();
		int i=0;
		val=0,left=nullptr,right=nullptr;
		pair<bool,int>pp=readtreenode(s,i);
		if (!pp.first)return;
		val=pp.first;
		queue<TreeNode*>Q;
		Q.push(this);
		while (Q.size()) {
			TreeNode* q = Q.front();
			Q.pop();
			if (s[i]) {
				pp=readtreenode(s,i);
				if (!pp.first)q->left = nullptr;
				else {
					q->left = new TreeNode(pp.second);
					Q.push(q->left);
				}
			}
			else q->left = nullptr;
			if (s[i]) {
				pp=readtreenode(s,i);
				if (!pp.first)q->right = nullptr;
				else {
					q->right = new TreeNode(pp.second);
					Q.push(q->right);
				}
			}
			else q->right = nullptr;
		}
	}
};
ostream&operator<<(ostream&out,TreeNode*root){
	if(!root){
		out<<"empty treenode\n";
		return out;
	}
	int maxdepth=0;
	{
		queue<TreeNode*>Q;
		int depth=0;
		Q.push(root);
		while(Q.size()){
			maxdepth=max(maxdepth,++depth);
			int l=Q.size();
			while(l--){
				auto p=Q.front();
				Q.pop();
				if(p->left)Q.push(p->left);
				if(p->right)Q.push(p->right);
			}
		}
	}
	string s[maxdepth];
	{
		int width=6;
		for(int i=0;i<maxdepth;i++){
			s[i].resize(((1<<maxdepth)-1)*width);
			for(char&c:s[i])c=' ';
		}
		queue<pair<pair<TreeNode*,int>,int>>Q;
		int row=0,arm=(1<<maxdepth)/4;
		Q.push(make_pair(make_pair(root,((1<<maxdepth)-1)/2),0));
		while(Q.size()){
			int l=Q.size();
			while(l--){
				auto p=Q.front();
				Q.pop();
				string temp=to_string(p.first.first->val);
				int rr=(width-temp.size())/2;
				int ll=width-temp.size()-rr;
				for(int i=ll;temp[i-ll];i++)s[row][p.first.second*width+i]=temp[i-ll];
				if(p.second){
					if(p.second==1){
						s[row-1][p.first.second*width+ll+temp.size()-2]='\\';
						for(int i=p.first.second*width+ll+temp.size()-3;s[row-1][i]==' ';i--)s[row-1][i]='=';
					}
					else{
						s[row-1][p.first.second*width+ll]='/';
						for(int i=p.first.second*width+ll+1;s[row-1][i]==' ';i++)s[row-1][i]='=';
					}
				}
				if(p.first.first->left)Q.push(make_pair(make_pair(p.first.first->left,p.first.second-arm),-1));
				if(p.first.first->right)Q.push(make_pair(make_pair(p.first.first->right,p.first.second+arm),1));
			}
			row++;
			arm>>=1;
		}
	}
	string res[maxdepth];
	bool makeup=true;
	for(int j=0;j<s[0].size();){
		bool needmakeup=false,clear=true;
		for(int i=0;i<maxdepth;i++){
			if(s[i][j]!=' '&&s[i][j]!='=')clear=false;
			if((s[i][j]=='-'||isdigit(s[i][j]))&&res[0].size()&&res[i].back()=='/')needmakeup=true;
		}
		if(needmakeup&&!makeup){
			for(int i=0;i<maxdepth;i++){
				if(res[i].size()&&(res[i].back()=='='||isdigit(res[i].back())))res[i]+='=';
				else res[i]+=' ';
			}
			makeup=true;
		}
		else{
			if(!clear)for(int i=0;i<maxdepth;i++)res[i]+=s[i][j];
			makeup=false;
			j++;
		}
	}
	unordered_map<char,string>M{{'=',"═"},{'/',"╔"},{'\\',"╗"}};
	for(int i=0;i<maxdepth;i++){
		out<<"\n ";
		for(int j=0;j<res[i].size();j++){
			if(res[i][j]=='='){
				if(M.count(res[i][j+1]))out<<M[res[i][j]];
				else out<<' ';
			}
			else if(M.count(res[i][j]))out<<M[res[i][j]];
			else out<<res[i][j];
		}
	}
	return out;
}