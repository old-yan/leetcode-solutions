#include "utils.h"

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        ll maxBefore=INT_MIN;
        ll ans=0;
        REP(i,values.size()){
            chmax(ans,values[i]-i+maxBefore);
            chmax(maxBefore,values[i]+i);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi values{8,1,5,2,6};
    auto ans=sol.maxScoreSightseeingPair(values);
    DBG(ans);

    system("pause");
    return 0;
}
