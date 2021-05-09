#include "utils.h"

class Solution {
    string labels;
    vi adj[100000];
    int dp[100000][26]={0};
    void traverse(int cur,int parent){
        for(int a:adj[cur])if(a!=parent){
            traverse(a,cur);
            REP(i,26){
                dp[cur][i]+=dp[a][i];
            }
        }
        dp[cur][labels[cur]-'a']++;
    }
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string _labels) {
        for(auto&e:edges){
            adj[e[0]].pb(e[1]);
            adj[e[1]].pb(e[0]);
        }
        labels=_labels;
        traverse(0,-1);
        vi ans(n);
        REP(i,n)ans[i]=dp[i][labels[i]-'a'];
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=7;
    vvi edges=makevvi("[[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]]");
    string labels="abaedcd";
    auto ans=sol.countSubTrees(n,edges,labels);
    DBGV(ans);

    system("pause");
    return 0;
}
