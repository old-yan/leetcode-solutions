#include "utils.h"

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vi ans;
        int sum=accumulate(ALL(nums),0,[](int x,int y){return x^y;});
        REPR(i,nums.size()-1){
            ans.pb(~sum&((1<<maximumBit)-1));
            sum^nums[i];
        }
        return ans;
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
