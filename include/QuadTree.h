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