#include "utils.h"

class Solution {
    vector<int>adj[100000];
public:
    //这道题是典型的最短路问题，对于每个点
    //  1.计算到 0 的距离；
    //  2.分别计算出收到回复的时间、最后一次呼叫的时间、呼叫消失的时间
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n=patience.size();
        for(auto&e:edges){
            int a=e[0],b=e[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        //BFS找出从 0 到每个点的最短距离
        vector<int>dist(n,0x3f3f3f3f);
        dist[0]=0;
        queue<int>Q;
        Q.push(0);
        while(Q.size()){
            auto p=Q.front();
            Q.pop();
            for(int a:adj[p]){
                if(dist[a]>dist[p]+1){
                    dist[a]=dist[p]+1;
                    Q.push(a);
                }
            }
        }
        int ans=0;
        for(int i=1;i<n;i++){
            int receive_time=dist[i]*2;
            //注意这里的减一是因为当收到回复后就不再呼叫；
            //先除后乘是为了把余数抹掉，因为只有整数倍时间会呼叫
            int last_call=(receive_time-1)/patience[i]*patience[i];
            int wait=last_call+dist[i]*2+1;
            ans=max(ans,wait);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<vector<int>>edges=makevvi("[[0,1],[0,2],[1,2]]");
    vector<int>patience{0,10,10};
    auto ans=sol.networkBecomesIdle(edges,patience);
    DBG(ans);

    system("pause");
    return 0;
}