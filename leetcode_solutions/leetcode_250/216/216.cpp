#include "utils.h"

class Solution {
    bool dp[11][46]={0};
    int k;
    vvi ans;
    void dfs(int i,int rest,vi&path){
        path.pb(i);
        if(!rest){
            if(path.size()==k)ans.pb(path);
        }
        else if(path.size()<k){
            FOR(j,i+1,10){
                if(dp[j][rest]){
                    dfs(j,rest-j,path);
                }
            }
        }
        path.pop_back();
    }
public:
    vector<vector<int>> combinationSum3(int _k, int n) {
        if(n>45)return ans;
        k=_k;
        bool appeared[46]={0};
        appeared[0]=true;
        FORR(i,9,1){
            REP(j,46){
                if(j>=i&&appeared[j-i]){
                    dp[i][j]=true;
                    appeared[j]=true;
                }
            }
        }
        FOR(i,1,10){
            vi path;
            if(dp[i][n])dfs(i,n-i,path);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int k=3;
    int n=9;
    auto ans=sol.combinationSum3(k,n);
    DBGVV(ans);

    system("pause");
    return 0;
}
