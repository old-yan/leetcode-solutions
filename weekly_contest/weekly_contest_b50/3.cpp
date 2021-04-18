#include "utils.h"

class Solution {
public:
    //注意到题目中为连续异或，换成加号那就是前缀和，换成异或号，那就是前缀异或和
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        FOR(i,1,nums.size()){
            nums[i]^=nums[i-1];
        }
        //采用性质：a^(a^k)=k，所以让数组元素异或最大化的结果，就可以求得相应的k
        for(int&a:nums)a^=(1<<maximumBit)-1;
        //注意前后翻转
        reverse(ALL(nums));
        return nums;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{0,1,1,3};
    int maximumBit=2;
    auto ans=sol.getMaximumXor(nums,maximumBit);
    DBGV(ans);

    system("pause");
    return 0;
}
