#include "Heap.h"
#include "utils.h"

class Solution {
    vector<pair<int,double>>adj[10000];
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        REP(i,edges.size()){
            int a=edges[i][0],b=edges[i][1];
            double c=succProb[i];
            adj[a].emplace_back(b,c);
            adj[b].emplace_back(a,c);
        }
        double dp[n];
        fill(dp,dp+n,0);
        Heap<int>H([&](int x,int y){return dp[x]<dp[y];});
        dp[start]=1;
        H.push(start);
        while(H.size()){
            auto p=H.top();
            H.pop();
            if(p==end)break;
            for(auto [a,dis]:adj[p]){
                if(chmax(dp[a],dp[p]*dis)){
                    H.push(a);
                }
            }
        }
        return dp[end];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=3;
    vvi edges=makevvi("[[0,1],[1,2],[0,2]]");
    vector<double>succProb{0.5,0.5,0.2};
    int start=0;
    int end=2;
    auto ans=sol.maxProbability(n,edges,succProb,start,end);
    DBG(ans);

    system("pause");
    return 0;
}
