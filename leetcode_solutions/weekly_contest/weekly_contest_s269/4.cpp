#include "utils.h"

class Solution {
    vector<pair<int,int>>adj[100000];
public:
    //本题可以建图跑最短路，求出每一个人(点)获取信息的时间
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        //邻接表
        for(auto&m:meetings){
            int a=m[0],b=m[1],t=m[2];
            adj[a].emplace_back(t,b);
            adj[b].emplace_back(t,a);
        }
        vector<int>dist(n,0x3f3f3f3f);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>Q;
        // 0 和 firstPerson 是出发点
        for(int a:{0,firstPerson}){
            dist[a]=0;
            Q.emplace(0,a);
        }
        //堆优化的最短路
        while(Q.size()){
            auto [curt,cur]=Q.top();Q.pop();
            if(curt!=dist[cur])continue;
            for(auto [t,a]:adj[cur]){
                if(t<curt)continue;
                else if(t<dist[a]){
                    dist[a]=t;
                    Q.emplace(t,a);
                }
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++)if(dist[i]<0x3f3f3f3f)ans.push_back(i);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=6;
    vector<vector<int>>meetings=makevvi("[[1,2,5],[2,3,8],[1,5,10]]");
    int firstPerson=1;
    auto ans=sol.findAllPeople(n,meetings,firstPerson);
    DBGV(ans);

    system("pause");
    return 0;
}