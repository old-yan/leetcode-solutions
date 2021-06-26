#include "utils.h"

class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        ll sum=accumulate(ALL(nums),0ll);
        ll dif=abs(goal-sum);
        return (dif+limit-1)/limit;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,-1,1};
    int limit=3;
    int goal=-4;
    auto ans=sol.minElements(nums,limit,goal);
    DBG(ans);

    system("pause");
    return 0;
}
