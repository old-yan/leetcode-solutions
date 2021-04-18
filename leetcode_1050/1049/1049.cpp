#include "utils.h"

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum=accumulate(ALL(stones),0);
        auto v=getSubsequenceSum(stones);
        auto it=lower_bound(ALL(v),sum/2);
        return abs(*it*2-sum);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi stones{2,7,4,1,8,1};
    auto ans=sol.lastStoneWeightII(stones);
    DBG(ans);

    system("pause");
    return 0;
}
