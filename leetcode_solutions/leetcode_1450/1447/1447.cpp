#include "utils.h"

class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string>ans;
        FOR(b,2,n+1){
            FOR(a,1,b){
                if(mygcd(a,b)==1){
                    ans.pb(i2s(a)+"/"+i2s(b));
                }
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=10;
    auto ans=sol.simplifiedFractions(n);
    DBGV(ans);

    system("pause");
    return 0;
}
