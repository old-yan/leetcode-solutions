#include "utils.h"

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int Max=*max_element(ALL(arr));
        if(Max<0)return Max;
        vi sum{0};
        sum.insert(sum.end(),ALL(arr));
        sum.pb(0);
        partial_sum(ALL(sum),sum.begin());
        auto preMin=premin(sum);
        auto postMax=postmax(sum);
        int ans=0;
        REP(i,arr.size()){
            if(arr[i]>=0)chmax(ans,arr[i]+sum[i]-preMin[i]+postMax[i+2]-sum[i+1]);
            else chmax(ans,sum[i]-preMin[i]+postMax[i+2]-sum[i+1]);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr{1,-2,-2,3};
    auto ans=sol.maximumSum(arr);
    DBG(ans);

    system("pause");
    return 0;
}
