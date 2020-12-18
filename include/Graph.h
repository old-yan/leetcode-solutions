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
using namespace std;

struct GraphNode{
    int val;
    vector<GraphNode*>neighbors;
    GraphNode(int _val):val(_val){}
};

struct Graph {
    int m;
    vector<GraphNode*>vertices;
    Graph():m(0){}
    Graph(int _m):m(_m){
        for(int i=0;i<m;i++)vertices.push_back(new GraphNode(i+1));
    }
    Graph(vector<vector<int>>adj_list):m(adj_list.size()){
        for(int i=0;i<m;i++){
            vertices.push_back(new GraphNode(i+1));
        }
        for(int i=0;i<m;i++){
            for(int j:adj_list[i]){
                vertices[i]->neighbors.push_back(vertices[j-1]);
            }
        }
    }
    Graph(GraphNode*p){//限定连通图
        m=0;
        vertices.resize(100);
        queue<GraphNode*>Q;
        if(p){
            Q.push(p);
            vertices[p->val-1]=p;
        }
        while(Q.size()){
            auto a=Q.front();
            Q.pop();
            m=max(m,a->val);
            for(auto b:a->neighbors){
                if(!vertices[b->val-1]){
                    Q.push(b);
                    vertices[b->val-1]=b;
                }
            }
        }
        vertices.resize(m);
    }
};

ostream&operator<<(ostream&out,GraphNode*p){
    Graph g(p);
    if(!g.m){
        out<<"empty graph\n";
        return out;
    }
    if(g.m>1)out<<g.m<<" graphnodes in the graph:\n";
    else out<<"1 graphnode in the graph:\n";
    for(int i=1;i<=g.m;i++){
        out<<"node No."<<setw(2)<<i<<" : ";
        sort(g.vertices[i-1]->neighbors.begin(),g.vertices[i-1]->neighbors.end(),[](GraphNode*x,GraphNode*y)->bool{return x->val<y->val;});
        auto it=g.vertices[i-1]->neighbors.begin();
        int cursor=1;
        while(it!=g.vertices[i-1]->neighbors.end()){
            while(cursor++<(*it)->val)out<<"   ";
            out<<setw(3)<<(*it++)->val;
        }
        out<<endl;
    }
    return out;
}

ostream&operator<<(ostream&out,Graph*g){
    if(!g->m){
        out<<"empty graph\n";
        return out;
    }
    if(g->m>1)out<<g->m<<" graphnodes in the graph:\n";
    else out<<"1 graphnode in the graph:\n";
    for(int i=1;i<=g->m;i++){
        out<<"node No."<<setw(2)<<i<<" : ";
        sort(g->vertices[i-1]->neighbors.begin(),g->vertices[i-1]->neighbors.end(),[](GraphNode*x,GraphNode*y)->bool{return x->val<y->val;});
        auto it=g->vertices[i-1]->neighbors.begin();
        int cursor=1;
        while(it!=g->vertices[i-1]->neighbors.end()){
            while(cursor++<(*it)->val)out<<"   ";
            out<<setw(3)<<(*it++)->val;
        }
        out<<endl;
    }
    return out;
}