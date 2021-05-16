#include "utils.h"

class Solution {
    int cnt[100001]={0};
public:
    //既可以枚举每个数作为分子，也可以枚举每个数作为分母。这里采用枚举分子的方法
    int sumOfFlooredPairs(vector<int>& nums) {
        int n=nums.size();
        //预处理前缀和，方便查询某个数值区间的数量
        for(int a:nums)cnt[a]++;
        partial_sum(cnt,cnt+100001,cnt);
        ll ans=0;
        for(int i=0;i<n;i++){
            int cur=nums[i];
            int r=sqrt(cur);
            for(int j=1;j<=r;j++){
                //对分数值为j的部分，进行累加（也就是分数值小于r的
                ans+=(cnt[cur/j]-cnt[cur/(j+1)])*j;
                //对分母值为j的部分，进行累加（也就是分数值大于r的
                if(cur/j>r)ans+=(cnt[j]-cnt[j-1])*(cur/j);
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
