#include "utils.h"

class Solution {
    vector<pair<int,int>>adj[100];
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        for(auto&flight:flights){
            adj[flight[0]].emplace_back(flight[1],flight[2]);
        }
        vi cur(n,INT_MAX);
        cur[src]=0;
        bitset<100>relaxed;
        relaxed.set(src);
        REP(i,K+1){
            if(relaxed.count()==0)break;
            vi pre=cur;
            bitset<100>preRelaxed=relaxed;
            for(int j=-1;(j=preRelaxed._Find_next(j))<100;){
                for(auto&a:adj[j]){
                    if(chmin(cur[a.first],pre[j]+a.second)){
                        relaxed.set(a.first);
                    }
                }
            }
        }
        return cur[dst]==INT_MAX?-1:cur[dst];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=3;
    vvi flights=makevvi("[[0,1,100],[1,2,100],[0,2,500]]");
    int src=0;
    int dst=2;
    int K=1;
    auto ans=sol.findCheapestPrice(n,flights,src,dst,K);
    DBG(ans);

    system("pause");
    return 0;
}
