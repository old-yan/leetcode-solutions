#include "utils.h"

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int>S;
        for(int i=0,j=0;j<nums.size();){
            if(j<=i+k){
                if(S.count(nums[j]))return true;
                S.insert(nums[j++]);
            }
            else{
                S.erase(nums[i++]);
            }
        }
        return false;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,2,3,1,2,3};
    auto ans=sol.containsNearbyDuplicate(nums,2);
    DBG(ans);

    system("pause");
    return 0;
}
