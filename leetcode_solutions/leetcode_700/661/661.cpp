#include "utils.h"

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int m=M.size(),n=M[0].size();
        vvi ans(m,vi(n,0));
        REP(i,m){
            REP(j,n){
                int cnt=0;
                FOR(ii,i-1,i+2){
                    FOR(jj,j-1,j+2){
                        if(VALID){
                            ans[i][j]+=M[ii][jj];
                            cnt++;
                        }
                    }
                }
                ans[i][j]/=cnt;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi M{
        {1,1,1},{1,0,1},{1,1,1}
    };
    auto ans=sol.imageSmoother(M);
    DBGVV(ans);

    system("pause");
    return 0;
}
