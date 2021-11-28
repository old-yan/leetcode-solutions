#include "utils.h"

class Solution {
public:
    //本题可以使用双指针，维护一个大小为 k*2+1 的窗口
    //也可以使用前缀和计算子数组的和
    vector<int> getAverages(vector<int>& nums, int k) {
        //求出前缀和数组
        vector<long long >presum{0};
        for(int a:nums)presum.push_back(presum.back()+a);
        vector<int>ans(nums.size(),-1);
        for(int i=0;i<nums.size();i++){
            //判断以 i 为中心的子数组长度够不够
            if(i-k>=0 and i+k<nums.size()){
                long long sum=presum[i+k+1]-presum[i-k];
                ans[i]=sum/(k*2+1);
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<int>nums{7,4,3,9,1,8,5,2,6};
    int k=3;
    auto ans=sol.getAverages(nums,k);
    DBGV(ans);

    system("pause");
    return 0;
}