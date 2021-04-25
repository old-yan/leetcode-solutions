#include "utils.h"

class Solution {
public:
    //本题数据量较大，考虑O(n)做法，那么就是双指针做法
    int maxFrequency(vector<int>& nums, int k) {
        sort(ALL(nums));
        int n=nums.size();
        ll ans=0;
        //枚举每一个右端
        for(ll left=0,right=0,cost=0;right<n;right++){
            //如果左端太靠左了（也就是把区间内的数字都加到right所需的代价太大）
            //那么就把最左端的一个元素舍弃
            while(cost>k){
                cost-=nums[right]-nums[left];
                left++;
            }
            chmax(ans,right-left+1);
            if(right+1<n)cost+=(right-left+1)*(nums[right+1]-nums[right]);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,4,8,13};
    int k=5;
    auto ans=sol.maxFrequency(nums,k);
    DBG(ans);

    system("pause");
    return 0;
}
