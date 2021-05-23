#include "utils.h"

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int ans=INT_MAX;
        REP(i,nums.size()){
            if(nums[i]==target){
                chmin(ans,abs(int(i)-start));
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
