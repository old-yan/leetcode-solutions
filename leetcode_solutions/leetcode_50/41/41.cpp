#include "utils.h"

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int haveone=0;
        for(int a:nums)if(a==1)haveone=1;
        if(!haveone)return 1;
        for(int&a:nums)if(a<=0)a=1;
        for(int a:nums){
            int b=abs(a);
            if(b<=nums.size())nums[b-1]=-abs(nums[b-1]);
        }
        REP(i,nums.size())if(nums[i]>0)return i+1;
        return nums.size()+1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{3,4,-1,1};
    auto ans=sol.firstMissingPositive(nums);
    DBG(ans);

    system("pause");
    return 0;
}
