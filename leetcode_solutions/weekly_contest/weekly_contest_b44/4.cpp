#include "EulerPrime.h"
#include "utils.h"

class Solution {
public:
    vector<int> waysToFillArray(vector<vector<int>>& queries) {
        static EulerPrime<10000>ep;
        vi ans(queries.size());
        REP(i,queries.size()){
            int n=queries[i][0],k=queries[i][1];
            ep.getPrimeFactors<1>(k);
            ll res=1;
            REP(_,ep.plen){
                int j=ep.pcnt[_];
                res=res*combination(n+j-1,j)%MOD;
            }
            ans[i]=res;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi queries{
        {73,660},{1,1},{2,2},{3,3},{4,4},{5,5}
    };
    auto ans=sol.waysToFillArray(queries);
    DBGV(ans);

    system("pause");
    return 0;
}
