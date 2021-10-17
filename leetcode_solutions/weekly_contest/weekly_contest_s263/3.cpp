#include "utils.h"

class Solution {
public:
    //看到数据范围，肯定是状态压缩，当然 dfs 也可以
    int countMaxOrSubsets(vector<int>& nums) {
        int n=nums.size();
        int ans_value=INT_MIN;
        int ans_count=0;
        for(int s=0;s<1<<n;s++){
            int t=0;
            for(int i=0;i<n;i++)if(s>>i&1)t|=nums[i];
            if(t>ans_value){
                ans_value=t;
                ans_count=1;
            }
            else if(t==ans_value){
                ans_count++;
            }
        }
        return ans_count;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<int>nums{3,2,1,5};
    auto ans=sol.countMaxOrSubsets(nums);
    DBG(ans);

    system("pause");
    return 0;
}