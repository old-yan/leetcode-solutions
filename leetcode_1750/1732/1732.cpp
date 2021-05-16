#include "utils.h"

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        partial_sum(ALL(gain),gain.begin());
        return max(0,*max_element(ALL(gain)));
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi gain{-5,1,5,0,-7};
    auto ans=sol.largestAltitude(gain);
    DBG(ans);

    system("pause");
    return 0;
}
