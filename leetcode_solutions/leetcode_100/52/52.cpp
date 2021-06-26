#include "utils.h"

class Solution {
    int n,ans=0;
    int col[20]={0};
    int sum[40]={0};
    int d[40]={0};
    void dfs(int i){
        if(i==n)ans++;
        else{
            REP(j,n){
                if(!col[j]&&!sum[i+j]&&!d[i-j+n]){
                    col[j]=sum[i+j]=d[i-j+n]=1;
                    dfs(i+1);
                    col[j]=sum[i+j]=d[i-j+n]=0;
                }
            }
        }
    }
public:
    int totalNQueens(int _n) {
        n=_n;
        dfs(0);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=8;
    auto ans=sol.totalNQueens(n);
    DBG(ans);

    system("pause");
    return 0;
}
