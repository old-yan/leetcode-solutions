#include "utils.h"

class Solution{
public:
    int findMaxConsecutiveOnes(vi&nums){
        int ans=0;
        for(int i=0,j;i<nums.size();i=j){
            while(i<nums.size()&&nums[i]!=1)i++;
            if(i==nums.size())break;
            for(j=i+1;j<nums.size()&&nums[j]==1;j++);
            ans=max(ans,j-i);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,1,1,1,0,1,1};
    auto ans=sol.findMaxConsecutiveOnes(nums);
    DBG(ans);

    system("pause");
    return 0;
}
