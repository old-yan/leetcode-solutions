#include "utils.h"

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int Max=*max_element(ALL(candies));
        vector<bool>ans;
        for(auto&c:candies){
            ans.pb(c>=Max-extraCandies);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi candies{2,3,5,1,3};
    int extraCandies=3;
    auto ans=sol.kidsWithCandies(candies,extraCandies);
    DBGV(ans);

    system("pause");
    return 0;
}
