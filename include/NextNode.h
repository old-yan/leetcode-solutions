#pragma once
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <iomanip>
using namespace std;
#define OLDYAN_NEXTNODE

struct NextNode {
    int val;
    NextNode* left;
    NextNode* right;
    NextNode* next;
    NextNode() : val(0), left(NULL), right(NULL), next(NULL) {}
    NextNode(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    NextNode(int _val, NextNode* _left, NextNode* _right, NextNode* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
	NextNode(string&&s){
		auto readnextnode=[&](int &i){
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
		};
		s.erase(remove(s.begin(),s.end(),' '),s.end());
		s.erase(remove(s.begin(),s.end(),'['),s.end());
		s.erase(remove(s.begin(),s.end(),']'),s.end());
		int i=0;
		pair<bool,int>pp=readnextnode(i);
		if (!pp.first)return;
		val=0,left=nullptr,right=nullptr,next=nullptr;
		queue<NextNode*>Q;
		Q.push(this);
		while (Q.size()) {
			NextNode* q = Q.front();
			Q.pop();
			if (s[i]) {
				pp=readnextnode(i);
				if (!pp.first)q->left = nullptr;
				else {
					q->left = new NextNode(pp.second);
					Q.push(q->left);
				}
			}
			else q->left = nullptr;
			if (s[i]) {
				pp=readnextnode(i);
				if (!pp.first)q->right = nullptr;
				else {
					q->right = new NextNode(pp.second);
					Q.push(q->right);
				}
			}
			else q->right = nullptr;
		}
	}
};
ostream&operator<<(ostream&out,NextNode*root){
	if(!root){
		out<<"empty nextnode\n";
		return out;
	}
	int maxdepth=0;
	{
		queue<NextNode*>Q;
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
		int width=12;
		for(int i=0;i<maxdepth;i++){
			s[i].resize(((1<<maxdepth)-1)*width);
			for(char&c:s[i])c=' ';
		}
		queue<pair<pair<NextNode*,int>,int>>Q;
		int row=0,arm=(1<<maxdepth)/4;
		Q.push(make_pair(make_pair(root,((1<<maxdepth)-1)/2),0));
		while(Q.size()){
			int l=Q.size();
			while(l--){
				auto p=Q.front();
				Q.pop();
				string temp=to_string(p.first.first->val);
                if(!p.first.first->next)temp+="->null";
                else temp+="->"+to_string(p.first.first->next->val);
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