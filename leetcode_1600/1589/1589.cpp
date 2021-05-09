#include "utils.h"

class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n=nums.size();
        int cnt[n];
        memset(cnt,0,sizeof(cnt));
        for(auto&r:requests){
            cnt[r[0]]++;
            if(r[1]!=n-1)cnt[r[1]+1]--;
        }
        partial_sum(cnt,cnt+n,cnt);
        sort(ALLR(nums));
        sort(cnt,cnt+n,greater<int>());
        int ans=0;
        REP(i,n){
            ans+=cnt[i]*nums[i];
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,2,3,4,5};
    vvi requests=makevvi("[[1,3],[0,1]]");
    auto ans=sol.maxSumRangeQuery(nums,requests);
    DBG(ans);

    system("pause");
    return 0;
}
