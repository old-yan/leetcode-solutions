#include "utils.h"

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        sort(ALL(nums));
        ll ans=0,left=0,right=0,sum=0;
        while(true){
            while(sum>k){
                sum-=nums[right]-nums[left++];
            }
            chmax(ans,right-left+1);
            if(++right<n){
                sum+=(right-left)*(nums[right]-nums[right-1]);
            }
            else break;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,2,4};
    int k=5;
    auto ans=sol.maxFrequency(nums,k);
    DBG(ans);

    system("pause");
    return 0;
}
