#include "utils.h"

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxdis=0;
        REP(i,nums.size()){
            if(i>maxdis)return false;
            chmax(maxdis,int(i+nums[i]));
        }
        return true;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{2,3,1,1,4};
    auto ans=sol.canJump(nums);
    DBG(ans);

    system("pause");
    return 0;
}
