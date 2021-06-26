#include "utils.h"

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(ALL(nums));
        auto next=next_different(nums);
        int ans=0;
        for(int i=0,j=0;i<nums.size();i=next[i]){
            while(j<nums.size()){
                if(j==i)j++;
                else if(nums[j]<nums[i]+k)j=next[j];
                else break;
            }
            if(j==nums.size())break;
            if(nums[j]==nums[i]+k){
                ans++;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{3,1,4,1,5};
    int k=2;
    auto ans=sol.findPairs(nums,k);
    DBG(ans);

    system("pause");
    return 0;
}
