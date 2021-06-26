#include "utils.h"

class Solution {
    vi groups[2000];
public:
    int minChanges(vector<int>& nums, int k) {
        int n=nums.size();
        REP(i,n){
            groups[i%k].pb(nums[i]);
        }
        int dp[k+1][1<<10];
        memset(dp,0x3f,sizeof(dp));
        dp[0][0]=0;
        REP(i,k){
            int cnt[1<<10]={0};
            for(int a:groups[i])cnt[a]++;
            int Minpre=min_element(dp[i],dp[i+1])-dp[i];
            REP(j,1<<10){
                dp[i+1][j]=dp[i][Minpre]+groups[i].size()-cnt[j^Minpre];
                for(int a:groups[i]){
                    chmin(dp[i+1][j],int(dp[i][j^a]+groups[i].size()-cnt[a]));
                }
            }
        }
        return dp[k][0];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,2,4,1,2,5,1,2,6};
    int k=3;
    auto ans=sol.minChanges(nums,k);
    DBG(ans);

    system("pause");
    return 0;
}
