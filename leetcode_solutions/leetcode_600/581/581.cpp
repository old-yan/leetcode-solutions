#include "utils.h"

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int minafter[nums.size()];
        REPR(i,nums.size()-1){
            minafter[i]=i==nums.size()-1?nums[i]:min(minafter[i+1],nums[i]);
        }
        int maxbefore[nums.size()];
        REP(i,nums.size()){
            maxbefore[i]=i==0?nums[i]:max(maxbefore[i-1],nums[i]);
        }
        int l,r;
        for(l=0;l<nums.size()&&minafter[l]==nums[l];l++);
        if(l==nums.size())return 0;
        for(r=nums.size()-1;r>=0&&maxbefore[r]==nums[r];r--);
        return r-l+1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{2,6,4,8,10,9,15};
    auto ans=sol.findUnsortedSubarray(nums);
    DBG(ans);

    system("pause");
    return 0;
}
