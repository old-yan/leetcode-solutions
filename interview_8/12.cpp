#include "utils.h"

class Solution {
    vector<vector<string>>ans;
    vector<string>path;
    int n;
    bool col[10]={0},sum[20]={0},dif[20]={0};
    void dfs(int i){
        REP(j,n)if(!col[j]&&!sum[i+j]&&!dif[n+i-j]){
            col[j]=sum[i+j]=dif[n+i-j]=true;
            path[i][j]='Q';
            if(i==0)ans.pb(path);
            else dfs(i-1);
            col[j]=sum[i+j]=dif[n+i-j]=false;
            path[i][j]='.';
        }
    }
public:
    vector<vector<string>> solveNQueens(int _n) {
        n=_n;
        path.resize(n,string(n,'.'));
        dfs(n-1);
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
