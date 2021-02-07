#include "utils.h"

class Solution {
    //getSubsequenceSum()用来获取一个数组中所有数可能的子序列和（升序放置）
    //如果nums长度为n，那么可能的子序列和最多有2^n种（去重前）
public:
    //本题如果要求40个数所能组合成的和，2^40肯定超出时间范围，所以拆解成两个2^20的问题
    int minAbsDifference(vector<int>& nums, int goal) {
        //half1表示数组前一半
        vector<int>half1(vector<int>(nums.begin(),nums.begin()+nums.size()/2));
        auto sum1=getSubsequenceSum(half1);
        //half2表示数组后一半
        vector<int>half2(vector<int>(nums.begin()+nums.size()/2,nums.end()));
        auto sum2=getSubsequenceSum(half2);
        int ans=INT_MAX;
        //双指针i,j去拼凑，使sum1[i]+sum2[j]和接近jgoal
        for(int i=0,j=sum2.size()-1;;){
            int sum=sum1[i]+sum2[j];
            if(sum==goal)return 0;
            if(sum>goal){
                if(ans>sum-goal)ans=sum-goal;
                if(--j<0)break;
            }
            else{
                if(ans>goal-sum)ans=goal-sum;
                if(++i==sum1.size())break;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{7,-9,15,-2};
    int goal=-5;
    auto ans=sol.minAbsDifference(nums,goal);
    DBG(ans);

    system("pause");
    return 0;
}
