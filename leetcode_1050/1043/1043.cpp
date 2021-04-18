#include "utils.h"

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        ll _dp[n+1];
        auto dp=_dp+1;
        memset(_dp,0,sizeof(_dp));
        REP(i,n){
            int Max=0;
            REPR(j,i){
                if(i-j+1>k)break;
                chmax(Max,arr[j]);
                chmax(dp[i],dp[j-1]+Max*(i-j+1));
            }
        }
        return dp[n-1];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr{1,15,7,9,2,5,10};
    int k=3;
    auto ans=sol.maxSumAfterPartitioning(arr,k);
    DBG(ans);

    system("pause");
    return 0;
}
