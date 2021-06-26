#include "EulerPrime.h"
#include "utils.h"

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        static EulerPrime<100001>ep;
        vvi ans;
        ep.getFactors(target);
        REP(_,ep.flen){
            int f=ep.factors[_];
            int a=target/f;
            if(a%2&&a>1&&f-a/2>0){
                ans.pb(vi(a));
                iota(ALL(ans.back()),f-a/2);
            }
            if(f%2&&f/2-a>=0){
                ans.pb(vi(a*2));
                iota(ALL(ans.back()),f/2-a+1);
            }
        }
        sort(ALL(ans));
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int target=9;
    auto ans=sol.findContinuousSequence(target);
    DBGVV(ans);

    system("pause");
    return 0;
}
