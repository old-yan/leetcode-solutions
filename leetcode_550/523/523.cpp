#include "utils.h"

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(!k)k=INT_MAX;
        partial_sum(ALL(nums),nums.begin());
        unordered_set<ll>S{0};
        FOR(i,1,nums.size()){
            if(S.count(nums[i]%k))return true;
            S.insert(nums[i-1]%k);
        }
        return false;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{23,2,4,6,7};
    int k=6;
    auto ans=sol.checkSubarraySum(nums,k);
    DBG(ans);

    system("pause");
    return 0;
}
