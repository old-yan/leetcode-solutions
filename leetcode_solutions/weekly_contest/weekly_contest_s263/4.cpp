#include "utils.h"

class Solution {
    vector<int>adj[10000];
    //dis[cur][0] 表示到达 cur 最快的时间
    //dis[cur][1] 表示到达 cur 次快的时间
    long long dis[10000][2];
public:
    //显然本题和最短路有关，要求次短路那么我们在求最短路的时候同时记录次短路就可以了
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        for(auto&e:edges){
            int a=e[0],b=e[1];
            adj[a-1].push_back(b-1);
            adj[b-1].push_back(a-1);
        }
        memset(dis,0x3f,sizeof(dis));
        //使用 dijkstra 算法是可行的，但是本题其实路长都是一样的，可以认为是无权图，BFS就够用
        //pair的组成为{点编号，最短 or 次短}
        queue<pair<int,int>>Q;
        dis[0][0]=0,Q.emplace(0,0);
        while(Q.size()){
            auto [cur,i]=Q.front();Q.pop();
            long long d=dis[cur][i];
            //虽然在 d 时刻到达 cur，但不一定能立刻离开
            //如果是绿灯可以立刻离开
            //如果是红灯，需要等到下一个绿灯
            //d2 才是真正可以离开的时间
            long long d2=d%(change*2)<change?d:d-d%(change*2)+change*2;
            for(int a:adj[cur]){
                if(dis[a][0]>d2+time){
                    dis[a][0]=d2+time;
                    Q.emplace(a,0);
                }
                else if(d2+time!=dis[a][0]&&dis[a][1]>d2+time){
                    dis[a][1]=d2+time;
                    Q.emplace(a,1);
                }
            }
        }
        return dis[n-1][1];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=5;
    vector<vector<int>>edges=makevvi("[[1,2],[1,3],[1,4],[3,4],[4,5]]");
    int time=3;
    int change=5;
    auto ans=sol.secondMinimum(n,edges,time,change);
    DBG(ans);

    system("pause");
    return 0;
}