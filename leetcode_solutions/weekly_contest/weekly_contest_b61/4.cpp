#include "utils.h"

class Solution {
public:
    //贪心思想：令每一个数作为最小值，看看最多能保留多少个数在最终结果里
    int minOperations(vector<int>& nums) {
        //排序
        sort(ALL(nums));
        int n=nums.size();
        //keep表示最大保留数
        int keep=0;
        unordered_map<int,int>M;
        //双指针，i每次向前挪一位，nums[i]作为保留的最小数字
        for(int i=0,j=0;i<n;i++){
            //j也往前挪，只要nums[j]还在保留范围内就往前挪，直到出界
            for(;j<n&&nums[j]<=nums[i]+n-1;j++){
                M[nums[j]]++;
            }
            //刷新最大keep数
            keep=max(keep,int(M.size()));
            //记得在nums[i]滑出去之前，把nums[i]删掉
            M[nums[i]]--;
            if(M[nums[i]]==0)M.erase(nums[i]);
        }
        return n-keep;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,10,100,1000};
    auto ans=sol.minOperations(nums);
    DBG(ans);

    system("pause");
    return 0;
}