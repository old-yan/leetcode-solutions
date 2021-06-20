#include "utils.h"

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        if(count(ALL(nums),n)==0)return n;
        if(count(ALL(nums),0)==0)return 0;
        for(int a:nums){
            int b=a>=0?a:-1-a;
            if(b<n)nums[b]=-1-nums[b];
        }
        REP(i,n)if(nums[i]>=0)return i;
        return -1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{3,0,1};
    auto ans=sol.missingNumber(nums);
    DBG(ans);

    system("pause");
    return 0;
}
