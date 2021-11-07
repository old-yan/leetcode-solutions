#include "utils.h"

class Solution {
    vector<int>values;
    vector<vector<int>>edges;
    int maxTime;
    vector<tuple<int,int,int>>adj[1000];
    bool vertex_visit[1000]={0};
    bool edge_visit[4000]={0};
    int ans=0;
    void dfs(int cur,int curvalue,int curtime){
        if(curtime>maxTime)return;
        if(cur==0)ans=max(ans,curvalue);
        for(auto [a,c,e_idx]:adj[cur]){
            if(edge_visit[e_idx])continue;
            edge_visit[e_idx]=true;
            if(vertex_visit[a]){
                dfs(a,curvalue,curtime+c);
            }
            else{
                vertex_visit[a]=true;
                dfs(a,curvalue+values[a],curtime+c);
                vertex_visit[a]=false;
            }
            edge_visit[e_idx]=false;
        }
    }
public:
    //遇到可以重复遍历结点，但却只算一次的value的题目，肯定得dfs
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        this->values=values;
        this->edges=edges;
        this->maxTime=maxTime;
        //邻接表保存邻居编号、边权值、边的下标，注意正向反向边的下标区别开来
        for(int i=0;i<edges.size();i++){
            int a=edges[i][0],b=edges[i][1],c=edges[i][2];
            adj[a].emplace_back(b,c,i*2);
            adj[b].emplace_back(a,c,i*2+1);
        }
        vertex_visit[0]=true;
        dfs(0,values[0],0);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<int>values{5,10,15,20};
    vector<vector<int>>edges=makevvi("[[0,1,10],[1,2,10],[0,3,10]]");
    int maxTime=30;
    auto ans=sol.maximalPathQuality(values,edges,maxTime);
    DBG(ans);

    system("pause");
    return 0;
}