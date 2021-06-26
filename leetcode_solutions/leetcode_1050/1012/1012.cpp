#include "utils.h"

const ll units[10]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
class Solution {
    int N;
    int ans=0;
    void dfs(ll cur,int idx,int mask){
        if(cur/units[idx+1]<N/units[idx+1]){
            ans+=combination(__builtin_popcount(mask),idx+1)*factorial(idx+1);
            return;
        }
        else if(cur/units[idx+1]>N/units[idx+1])return;
        else{
            if(idx>=0){
                REP(j,10){
                    if(mask>>j&1){
                        dfs(cur+j*units[idx],idx-1,mask-(1<<j));
                    }
                }
            }
            else ans++;
        }
    }
public:
    int numDupDigitsAtMostN(int _N) {
        N=_N;
        REPR(i,9){
            FOR(j,1,10){
                dfs(j*units[i],i-1,1023-(1<<j));
            }
        }
        return N-ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int N=200;
    auto ans=sol.numDupDigitsAtMostN(N);
    DBG(ans);

    system("pause");
    return 0;
}
