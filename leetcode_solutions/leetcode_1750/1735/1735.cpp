#include "EulerPrime.h"
#include "utils.h"

class Solution {
public:
    vector<int> waysToFillArray(vector<vector<int>>& queries) {
        static EulerPrime<20000>ep;
        static vvi table=combinationTable(10100,13);
        vi ans;
        for(auto&q:queries){
            int n=q[0],k=q[1];
            ep.getPrimeFactors<1>(k);
            ll res=1;
            REP(_,ep.plen){
                int cur=ep.pf[_],cnt=ep.pcnt[_];
                res=res*table[n-1+cnt][cnt]%MOD;
            }
            ans.pb(res);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi queries=makevvi("[[2,6],[5,1],[73,660]]");
    auto ans=sol.waysToFillArray(queries);
    DBGV(ans);

    system("pause");
    return 0;
}
