#include "utils.h"

class Solution {
public:
    //模拟
    int maximumDifference(vector<int>& nums) {
        int n=nums.size();
        int ans=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(nums[i]<nums[j]){
                    ans=max(ans,nums[j]-nums[i]);
                }
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<int>nums{1,5,2,10};
    auto ans=sol.maximumDifference(nums);
    DBG(ans);

    system("pause");
    return 0;
}