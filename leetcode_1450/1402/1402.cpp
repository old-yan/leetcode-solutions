#include "utils.h"

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n=satisfaction.size();
        sort(ALL(satisfaction));
        ll ans=0;
        REP(i,n){
            ll res=0;
            FOR(j,i,n){
                res+=(ll)satisfaction[j]*(j-i+1);
            }
            chmax(ans,res);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi satisfaction{-1,-8,0,5,-9};
    auto ans=sol.maxSatisfaction(satisfaction);
    DBG(ans);

    system("pause");
    return 0;
}
