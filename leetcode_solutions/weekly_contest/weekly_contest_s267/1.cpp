#include "utils.h"

class Solution {
public:
    //由于数据范围不大，所以可以写个队列模拟，时间复杂度为 O(n * ticket[k])
    //当然可以有 O(n) 的方法
    //在 k 前面的人一定可以买到和 k 一样多的东西
    //在 k 后面的人只可以买到比 k 的东西少一
    //当然，每个人买到的东西不能超过自己的原计划
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans=0;
        for(int i=0;i<=k;i++)ans+=min(tickets[k],tickets[i]);
        for(int i=k+1;i<tickets.size();i++)ans+=min(tickets[k]-1,tickets[i]);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<int>tickets{2,3,2};
    int k=2;
    auto ans=sol.timeRequiredToBuy(tickets,k);
    DBG(ans);

    system("pause");
    return 0;
}