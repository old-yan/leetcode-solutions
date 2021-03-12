#include "utils.h"

class Solution {
    int dp[16384];
public:
    int racecar(int target){
        memset(dp,0x3f,sizeof(dp));
        dp[0]=0;
        for(int i=1;i<=target;i<<=1){
            dp[i*2-1]=__builtin_popcount(i*2-1);
            for(int cur=i;cur<=i*2-2;cur++){
                for(int back=0;back<i-1;back=back*2+1){
                    chmin(dp[cur],dp[i-1]+2+dp[back]+dp[cur-i+1+back]);
                }
                chmin(dp[cur],dp[i*2-1]+1+dp[i*2-1-cur]);
            }
        }
        return dp[target];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int target=3;
    auto ans=sol.racecar(target);
    DBG(ans);

    system("pause");
    return 0;
}
