#include "utils.h"

class Solution {
    int cnt[100001]={0};
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans=0;
        nums[0]%=2;
        partial_sum(ALL(nums),nums.begin(),[](int x,int y){return x+y%2;});
        cnt[0]=1;
        for(int a:nums){
            if(a>=k)ans+=cnt[a-k];
            cnt[a]++;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{2,2,2,1,2,2,1,2,2,2};
    int k=2;
    auto ans=sol.numberOfSubarrays(nums,k);
    DBG(ans);

    system("pause");
    return 0;
}
