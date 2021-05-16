#include "utils.h"

class Solution {
public:
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        vi cnt;
        unordered_map<int,int>M;
        for(int a:nums)M[a]++;
        for(auto&it:M){
            cnt.pb(it.second);
        }

        int n=cnt.size(),m=quantity.size();
        int sum[1<<m];
        sum[0]=0;
        FOR(state,1,1<<m)sum[state]=sum[state-(1<<__builtin_ctz(state))]+quantity[__builtin_ctz(state)];
        bool dp[1<<m];
        memset(dp,0,sizeof(dp));
        dp[0]=true;
        REP(i,n){
            REPR(state,(1<<m)-1){
                if(!dp[state])
                    for(int s=state;s;s=(s-1)&state){
                        if(dp[state-s]&&cnt[i]>=sum[s]){
                            dp[state]=true;
                            break;
                        }
                    }
            }
        }
        return dp[(1<<m)-1];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,2,3,4};
    vi quantity{2};
    auto ans=sol.canDistribute(nums,quantity);
    DBG(ans);

    system("pause");
    return 0;
}
