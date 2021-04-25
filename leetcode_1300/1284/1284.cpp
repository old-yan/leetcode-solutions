#include "utils.h"

class Solution {
    int dp[1<<9],inc[3][3],m,n;
    void init(vvi&mat){
        m=mat.size(),n=mat[0].size();
        REP(i,m)REP(j,n){
            int _inc=1<<(i*n+j);
            REP(k,4){
                int ii=i+di[k],jj=j+dj[k];
                if(VALID)_inc|=(1<<(ii*n+jj));
            }
            inc[i][j]=_inc;
        }
    }
public:
    int minFlips(vector<vector<int>>& mat) {
        init(mat);
        int mask=0;
        REP(i,m)REP(j,n)mask+=mat[i][j]*(1<<i*n+j);
        memset(dp,0x3f,sizeof(dp));
        queue<pair<int,int>>Q;
        dp[mask]=0;
        Q.emplace(mask,0);
        while(Q.size()){
            auto [curmask,curstep]=Q.front();
            Q.pop();
            REP(i,m)REP(j,n){
                if(chmin(dp[curmask^inc[i][j]],curstep+1)){
                    Q.emplace(curmask^inc[i][j],curstep+1);
                }
            }
        }
        return dp[0]==0x3f3f3f3f?-1:dp[0];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi mat=makevvi("[[0,0],[0,1]]");
    auto ans=sol.minFlips(mat);
    DBG(ans);

    system("pause");
    return 0;
}
