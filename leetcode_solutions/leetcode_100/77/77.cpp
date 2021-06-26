#include "utils.h"

class Solution {
    vvi ans;
    int path[20];
    int n,k;
    void dfs(int curnum,int last){
        if(curnum==k){
            ans.pb(vi(path,path+k));
        }
        else{
            FOR(j,last+1,n+1){
                if(curnum+n-j+1>=k){
                    path[curnum]=j;
                    dfs(curnum+1,j);
                }
            }
        }
    }
public:
    vector<vector<int>> combine(int _n, int _k) {
        n=_n,k=_k;
        dfs(0,0);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    auto ans=sol.combine(4,2);
    DBGVV(ans);

    system("pause");
    return 0;
}
