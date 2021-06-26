#include "utils.h"

class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int ans=INT_MAX;
        {
            int cnt=0;
            for(int i=0;i<nums.size();i+=2){
                int val=nums[i];
                if(i)chmin(val,nums[i-1]-1);
                if(i+1<nums.size())chmin(val,nums[i+1]-1);
                cnt+=nums[i]-val;
            }
            chmin(ans,cnt);
        }
        {
            int cnt=0;
            for(int i=1;i<nums.size();i+=2){
                int val=nums[i];
                if(i)chmin(val,nums[i-1]-1);
                if(i+1<nums.size())chmin(val,nums[i+1]-1);
                cnt+=nums[i]-val;
            }
            chmin(ans,cnt);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,2,3};
    auto ans=sol.movesToMakeZigzag(nums);
    DBG(ans);

    system("pause");
    return 0;
}
