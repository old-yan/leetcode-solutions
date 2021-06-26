#include "utils.h"

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(ALL(arr));
        ll dp[arr.size()];
        fill(dp,dp+arr.size(),1);
        REP(i,arr.size()){
            for(j=0,k=i-1;j<=k;){
                if(arr[j]*arr[k]<arr[i])j++;
                else if(arr[j]*arr[k]>arr[i])k--;
                else{
                    if(j==k)dp[i]=(dp[i]+dp[j]*dp[j])%MOD;
                    else dp[i]=(dp[i]+dp[j]*dp[k]*2)%MOD;
                }
            }
        }
        return accumulate(dp,dp+arr.size(),0ll)%MOD;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr{2,4,5,10};
    auto ans=sol.numFactoredBinaryTrees(arr);
    DBG(ans);

    system("pause");
    return 0;
}
