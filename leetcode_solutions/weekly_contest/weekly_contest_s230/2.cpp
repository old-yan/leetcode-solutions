#include "utils.h"

class Solution {
public:
    //toppingCosts里的数字可以选择性取舍，这又是一个背包问题
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        //因为toppingCosts中的数字可以选取最多两个，所以先把toppingCosts倍增
        toppingCosts.insert(toppingCosts.end(),toppingCosts.begin(),toppingCosts.end());
        //先写一个函数用来判断哪个答案更优
        auto better=[&](int x,int y){
            return (abs(x-target)<abs(y-target))||(abs(x-target)==abs(y-target)&&x<y);
        };
        int ans=-1000000;
        //用背包法找出toppingCosts的所有可能子序列和
        vi nums=getSubsequenceSum(toppingCosts);
        //对于每个base，二分法找出nums中合适的配方，使得和最接近目标
        //当然暴力遍历也是ok的
        for(int base:baseCosts){
            int low=0,high=nums.size()-1;
            while(low<high){
                int mid=(low+high)/2;
                if(base+nums[mid]>=target)high=mid;
                else low=mid+1;
            }
            if(better(base+nums[low],ans))ans=base+nums[low];
            if(low&&better(base+nums[low-1],ans))ans=base+nums[low-1];
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi baseCosts{2,3};
    vi toppingCosts{4,5,100};
    int target=18;
    auto ans=sol.closestCost(baseCosts,toppingCosts,target);
    DBG(ans);

    system("pause");
    return 0;
}
