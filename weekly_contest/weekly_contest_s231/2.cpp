#include "utils.h"

class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        //先求和
        long sum=accumulate(nums.begin(),nums.end(),long(0));
        //再求出差距
        long dif=abs(sum-goal);
        //贪心求最小步数
        return dif?(dif-1)/limit+1:0;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,-10,9,1};
    int limit=100;
    int goal=0;
    auto ans=sol.minElements(nums,limit,goal);
    DBG(ans);

    system("pause");
    return 0;
}
