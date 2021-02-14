#include "utils.h"

class Solution {
    const int di[8]={-1,-2,-2,-1,1,2,2,1};
    const int dj[8]={2,1,-1,-2,-2,-1,1,2};
public:
    double knightProbability(int N, int K, int r, int c) {
        long double dp[K+1][N][N];
        memset(dp,0,sizeof(dp));
        dp[0][r][c]=1;
        int m=N,n=N;
        FOR(l,1,K+1){
            REP(i,N){
                REP(j,N){
                    REP(k,8){
                        int ii=i+di[k],jj=j+dj[k];
                        if(VALID){
                            dp[i][j]+=dp[ii][jj]/8;
                        }
                    }
                }
            }
        }
        double sum=0;
        REP(i,N){
            REP(j,N){
                sum+=dp[K][i][j];
            }
        }
        return sum;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int N=3;
    int K=2;
    int r=0;
    int c=0;
    auto ans=sol.knightProbability(N,K,r,c);
    DBG(ans);

    system("pause");
    return 0;
}
