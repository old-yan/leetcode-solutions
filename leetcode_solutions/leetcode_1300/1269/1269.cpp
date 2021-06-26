#include "utils.h"

int dp[1001]={0};
class Solution {
public:
    int numWays(int steps, int arrLen) {
        if(arrLen==1)return 1;
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        REP(i,steps){
            int end=min(int(i)+1,arrLen);
            int nxt=dp[0];
            REP(j,end){
                int inc=nxt;
                nxt=dp[j+1];
                if(j)dp[j-1]=(dp[j-1]+inc)%MOD;
                dp[j+1]=(dp[j+1]+inc)%MOD;
            }
        }
        return dp[0];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int steps=2;
    int arrlen=3;
    auto ans=sol.numWays(steps,arrlen);
    DBG(ans);

    system("pause");
    return 0;
}
