#pragma once
#include <queue>
#include <iomanip>
using namespace std;
#define OLDYAN_QUADTREE

struct QuadTree{
    bool val;
    bool isLeaf;
    QuadTree* topLeft;
    QuadTree* topRight;
    QuadTree* bottomLeft;
    QuadTree* bottomRight;
    QuadTree() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    QuadTree(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    QuadTree(bool _val, bool _isLeaf, QuadTree* _topLeft, QuadTree* _topRight, QuadTree* _bottomLeft, QuadTree* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
    QuadTree(const string&s):QuadTree(){
        if(s.size()==2)return;
        QuadTree(s[4]-'0',s[2]-'0');
        queue<QuadTree*>Q;
        Q.emplace(this);
        int i=7;
        while(Q.size()){
            auto p=Q.front();
            Q.pop();
            if(i>=s.size())break;
            if(s[i]=='['){
                p->topLeft=new QuadTree(s[i+3]-'0',s[i+1]-'0');
                Q.emplace(p->topLeft);
                i+=6;
            }
            else{
                p->topLeft=nullptr;
                i+=5;
            }
            if(i>=s.size())break;
            if(s[i]=='['){
                p->topRight=new QuadTree(s[i+3]-'0',s[i+1]-'0');
                Q.emplace(p->topRight);
                i+=6;
            }
            else{
                p->topRight=nullptr;
                i+=5;
            }
            if(i>=s.size())break;
            if(s[i]=='['){
                p->bottomLeft=new QuadTree(s[i+3]-'0',s[i+1]-'0');
                Q.emplace(p->bottomLeft);
                i+=6;
            }
            else{
                p->bottomLeft=nullptr;
                i+=5;
            }
            if(i>=s.size())break;
            if(s[i]=='['){
                p->bottomRight=new QuadTree(s[i+3]-'0',s[i+1]-'0');
                Q.emplace(p->bottomRight);
                i+=6;
            }
            else{
                p->bottomRight=nullptr;
                i+=5;
            }
        }
        return;
    }
};
ostream&operator<<(ostream&out,QuadTree*root){
	if(!root){
		out<<"empty quadnode\n";
		return out;
	}
    int maxDepth=0;
    {
        queue<pair<QuadTree*,int>>Q;
        Q.emplace(root,0);
        while(Q.size()){
            auto a=Q.front();
            Q.pop();
            maxDepth=max(maxDepth,a.second);
            if(!a.first->isLeaf){
                Q.emplace(a.first->topRight,a.second+1);
                Q.emplace(a.first->topLeft,a.second+1);
                Q.emplace(a.first->bottomLeft,a.second+1);
                Q.emplace(a.first->bottomRight,a.second+1);
            }
        }
    }
    int n=1<<maxDepth;
    int matrix[n][n];
    {
        queue<tuple<QuadTree*,int,int,int,int>>Q;
        Q.emplace(root,0,n,0,n);
        while(Q.size()){
            auto a=Q.front();
            Q.pop();
            auto [p,i1,i2,j1,j2]=a;
            if(p->isLeaf){
                for(int i=i1;i<i2;i++){
                    for(int j=j1;j<j2;j++){
                        matrix[i][j]=p->val;
                    }
                }
            }
            else{
                Q.emplace(p->topRight,i1,(i1+i2)/2,(j1+j2)/2,j2);
                Q.emplace(p->topLeft,i1,(i1+i2)/2,j1,(j1+j2)/2);
                Q.emplace(p->bottomLeft,(i1+i2)/2,i2,j1,(j1+j2)/2);
                Q.emplace(p->bottomRight,(i1+i2)/2,i2,(j1+j2)/2,j2);
            }
        }
    }
    out<<"\n"<<n<<"*"<<n<<" matrix:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            out<<matrix[i][j]<<' ';
        }
        out<<endl;
    }
	return out;
}