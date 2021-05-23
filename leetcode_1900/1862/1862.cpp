#include "utils.h"

class Solution {
public:
    int sumOfFlooredPairs(vector<int>& nums) {
        int Max=*max_element(ALL(nums));
        ll cnt[Max+1],presum[Max+1];
        memset(cnt,0,sizeof(cnt));
        for(int a:nums)cnt[a]++;
        partial_sum(cnt,cnt+Max+1,presum);
        ll ans=0;
        FOR(a,1,Max+1)if(cnt[a]){
            for(int r=1;a*r<=Max;r++){
                if(a*r+a-1<=Max)
                    ans+=cnt[a]*r*(presum[a*r+a-1]-presum[a*r-1]);
                else
                    ans+=cnt[a]*r*(presum[Max]-presum[a*r-1]);
            }
        }
        return ans%MOD;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{2,5,9};
    auto ans=sol.sumOfFlooredPairs(nums);
    DBG(ans);

    system("pause");
    return 0;
}
