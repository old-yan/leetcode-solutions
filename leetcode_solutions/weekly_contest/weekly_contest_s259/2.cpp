#include "utils.h"

class Solution {
public:
    //本题考查的是类似前缀和的知识，如何求前缀最大/最小等信息
    int sumOfBeauties(vector<int>& nums) {
        vector<int>premax(nums),postmin(nums);
        //求出前缀最大
        partial_sum(ALL(premax),premax.begin(),[](int x,int y){return max(x,y);});
        //求出后缀最小
        partial_sum(ALLR(postmin),postmin.rbegin(),[](int x,int y){return min(x,y);});
        int ans=0;
        //按题意模拟
        for(int i=1;i+1<nums.size();i++){
            if(premax[i-1]<nums[i] and nums[i]<postmin[i+1])ans+=2;
            else if(nums[i-1]<nums[i] and nums[i]<nums[i+1])ans++;
            else continue;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{2,4,6,4};
    auto ans=sol.sumOfBeauties(nums);
    DBG(ans);

    system("pause");
    return 0;
}