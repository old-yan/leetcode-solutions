#include "utils.h"

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<ll>S;
        for(int i=0,j=0;j<nums.size();){
            if(j<=i+k){
                auto it=S.lower_bound((ll)nums[j]-t);
                if(it!=S.end()&&*it<=(ll)nums[j]+t)return true;
                S.insert(nums[j++]);
            }
            else S.erase(nums[i++]);
        }
        return false;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{-3,3,-6};
    auto ans=sol.containsNearbyAlmostDuplicate(nums,2,3);
    DBG(ans);

    system("pause");
    return 0;
}
