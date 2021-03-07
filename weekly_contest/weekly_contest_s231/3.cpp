#include "utils.h"

class Solution {
    //邻接表，使用pair保存邻居编号以及之间的距离
    vector<pair<int,int>>adj[20001];
    long mindis[20001];
    long ways[20001];
    int deg[20001];
    //使用Dijkstra算法求单源最短路
    void get_mindis(int n,vector<vector<int>>&edges){
        //建立邻接表
        for(auto&edge:edges){
            int i=edge[0],j=edge[1],dis=edge[2];
            adj[i].emplace_back(j,dis);
            adj[j].emplace_back(i,dis);
        }
        //使用堆结构维护"陌生点"的距离远近
        auto comp=[](pair<int,int>&x,pair<int,int>&y){
            return x.second>y.second;
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(comp)>Q(comp);
        mindis[n]=0;
        Q.emplace(n,mindis[n]);
        while(Q.size()){
            //找出最近的"陌生点"near
            auto [near,near_dis]=Q.top();
            Q.pop();
            //如果是过时的结点，直接跳过
            if(near_dis!=mindis[near])continue;
            //near已经入伙了，再来帮忙拉拢邻居
            for(auto&a:adj[near]){
                if(mindis[a.first]>near_dis+a.second){
                    mindis[a.first]=near_dis+a.second;
                    Q.emplace(a.first,mindis[a.first]);
                }
            }
        }
    }
    //按拓扑顺序将路数从1传递到n
    void getways(int n,vector<vector<int>>&edges){
        for(auto&edge:edges){
            int i=edge[0],j=edge[1];
            if(mindis[i]>mindis[j])deg[j]++;
            else if(mindis[i]<mindis[j])deg[i]++;
        }
        ways[1]=1;
        queue<int>Q;
        for(int i=1;i<=n;i++)if(!deg[i])Q.push(i);
        while(Q.size()){
            auto i=Q.front();
            Q.pop();
            //将自己的路数传给邻居
            for(auto&[j,dis]:adj[i]){
                if(mindis[j]<mindis[i]){
                    ways[j]=(ways[j]+ways[i])%MOD;
                    if(!--deg[j]){
                        Q.push(j);
                    }
                }
            }
        }
    }
public:
    //按题意一步一步来，先算出所有点到终点距离，再按这个距离从大到小传递路数
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        //初始化
        memset(mindis,0x3f,sizeof(mindis));
        memset(ways,0,sizeof(ways));
        memset(deg,0,sizeof(deg));
        get_mindis(n,edges);
        getways(n,edges);
        return ways[n];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=5;
    vvi edges=makevvi("[[1,2,3],[1,3,3],[2,3,1],[1,4,2],[5,2,2],[3,5,1],[5,4,10]]");
    auto ans=sol.countRestrictedPaths(n,edges);
    DBG(ans);

    system("pause");
    return 0;
}
