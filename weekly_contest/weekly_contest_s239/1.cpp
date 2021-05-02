#include "utils.h"

class Solution {
public:
    //遍历一遍，按要求取值
    int getMinDistance(vector<int>& nums, int target, int start) {
        ll ans=nums.size();
        REP(i,nums.size()){
            if(nums[i]==target){
                chmin(ans,abs(i-start));
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,2,3,4,5};
    int target=5;
    int start=3;
    auto ans=sol.getMinDistance(nums,target,start);
    DBG(ans);

    system("pause");
    return 0;
}
