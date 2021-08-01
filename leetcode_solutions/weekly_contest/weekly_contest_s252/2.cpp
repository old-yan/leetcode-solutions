#include "utils.h"

class Solution {
public:
    //经典安排座位问题：
    //  结论：只要最多的一种物品不超过一半，肯定可以让相邻的两个物品为异类
    //  方法：优先安排剩余数量最多的物品
    long long numberOfWeeks(vector<int>& milestones) {
        long long Max=*max_element(milestones.begin(),milestones.end());
        long long sum=accumulate(milestones.begin(),milestones.end(),0ll);
        if(Max*2-1<=sum)return sum;
        else return (sum-Max)*2+1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi milestones{1,2,3};
    auto ans=sol.numberOfWeeks(milestones);
    DBG(ans);

    system("pause");
    return 0;
}
