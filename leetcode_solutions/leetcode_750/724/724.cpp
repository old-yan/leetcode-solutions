#include "utils.h"

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        auto copy=nums;
        partial_sum(ALL(copy),copy.begin());
        int total=copy.back();
        REP(i,copy.size()){
            if(copy[i]*2-nums[i]==total)return i;
        }
        return -1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,7,3,6,5,6};
    auto ans=sol.pivotIndex(nums);
    DBG(ans);

    system("pause");
    return 0;
}
