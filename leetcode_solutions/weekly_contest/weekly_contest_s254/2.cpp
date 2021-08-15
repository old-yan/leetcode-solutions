#include "utils.h"

class Solution {
public:
    //一个简单的思路：如果一个数组的某个位置是“波峰”或者“波谷”，那么其必不是两侧的平均值
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(ALL(nums));
        vi ans;
        //一个小的、一个大的，交错放到数组里，可以保证要么波峰，要么波谷
        for(int l=0,r=nums.size()-1;l<r;l++,r--){
            ans.pb(nums[l]);
            ans.pb(nums[r]);
        }
        if(nums.size()%2)ans.pop_back();
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,2,3,4,5};
    auto ans=sol.rearrangeArray(nums);
    DBGV(ans);

    system("pause");
    return 0;
}
