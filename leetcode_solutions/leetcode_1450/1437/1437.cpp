#include "utils.h"

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int pre=-k-1;
        REP(i,nums.size())if(nums[i]==1){
            if(i-pre<=k)return false;
            pre=i;
        }
        return true;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,0,0,0,1,0,0,1};
    int k=2;
    auto ans=sol.kLengthApart(nums,k);
    DBG(ans);

    system("pause");
    return 0;
}
