#include "utils.h"

class Solution {
    vector<vector<string>>ans;
    vector<string>v;
    int n;
    int col[20]={0};
    int sum[40]={0};
    int d[40]={0};
    void dfs(int i){
        if(i==n){
            ans.pb(v);
        }
        REP(j,n){
            if(!col[j]&&!sum[i+j]&&!d[i-j+n]){
                col[j]=sum[i+j]=d[i-j+n]=1;
                v[i][j]='Q';
                dfs(i+1);
                v[i][j]='.';
                col[j]=sum[i+j]=d[i-j+n]=0;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int _n) {
        n=_n;
        v.resize(n);
        for(auto&s:v){
            s.resize(n);
            for(auto&c:s)c='.';
        }
        dfs(0);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=4;
    auto ans=sol.solveNQueens(n);
    DBGVV(ans);

    system("pause");
    return 0;
}
