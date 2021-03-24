#include "utils.h"

BiTrie T;
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        T.clear();
        int ans=0;
        REP(i,nums.size()){
            chmax(ans,T.searchMax(nums[i]^0xffffffff));
            T.insert(nums[i]);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{2,4};
    auto ans=sol.findMaximumXOR(nums);
    DBG(ans);

    system("pause");
    return 0;
}
