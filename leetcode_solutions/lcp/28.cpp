#include "utils.h"

class Solution {
public:
    int purchasePlans(vector<int>& nums, int target) {
        sort(ALL(nums));
        ll ans=0;
        for(int i=0,j=nums.size()-1;i<nums.size();i++){
            while(j>=0&&nums[i]+nums[j]>target)j--;
            if(j<=i)break;
            ans+=j-i;
        }
        return ans%MOD;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{2,5,3,5};
    int target=6;
    auto ans=sol.purchasePlans(nums,target);
    DBG(ans);

    system("pause");
    return 0;
}
#include "utils.h"

class Solution {
public:
    int purchasePlans(vector<int>& nums, int target) {

    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{2,5,3,5};
    int target=6;
    auto ans=sol.purchasePlans(nums,target);
    DBG(ans);

    system("pause");
    return 0;
}
