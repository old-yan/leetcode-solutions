#include "utils.h"

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        auto rnk=getrank2(nums);
        int Max=*max_element(ALL(rnk));
        int n=rnk.size();
        int dp[2][Max+1];
        memset(dp,0x80,sizeof(dp));
        REP(i,n){
            chmax(dp[0][rnk[i]],1);
            if(rnk[i])chmax(dp[0][rnk[i]],*max_element(dp[0],dp[0]+rnk[i])+1);
            if(rnk[i]<Max){
                int a=*max_element(dp[0]+rnk[i]+1,dp[1]);
                int b=*max_element(dp[1]+rnk[i]+1,dp[2]);
                if(max(a,b)>=2)chmax(dp[1][rnk[i]],max(a,b)+1);
            }
        }
        return *max_element(dp[1],dp[2]);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,3,1};
    auto ans=sol.minimumMountainRemovals(nums);
    DBG(ans);

    system("pause");
    return 0;
}
