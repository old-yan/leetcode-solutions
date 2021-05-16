#include "utils.h"

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        bool appear[10001]={0};
        int ans=0;
        for(int i=0,j=0,k=0;i<nums.size();i++){
            while(appear[nums[i]]){
                k-=nums[j];
                appear[nums[j++]]=false;
            }
            k+=nums[i];
            appear[nums[i]]=true;
            chmax(ans,k);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{5,2,1,2,5,2,1,2,5};
    auto ans=sol.maximumUniqueSubarray(nums);
    DBG(ans);

    system("pause");
    return 0;
}
