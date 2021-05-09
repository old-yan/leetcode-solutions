#include "utils.h"

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        bool zero=false;
        for(int a:nums)if(!a)zero=true;
        if(!zero)return nums.size()-1;
        int ans=0;
        for(int left=0,right=0,cnt=0;right<nums.size();){
            cnt+=!nums[right++];
            while(cnt>1)cnt-=!nums[left++];
            chmax(ans,right-left-cnt);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{}

    system("pause");
    return 0;
}
