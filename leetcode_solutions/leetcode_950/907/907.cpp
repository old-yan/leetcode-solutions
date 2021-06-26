#include "utils.h"

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int>S;
        ll dp[arr.size()];
        REP(i,arr.size()){
            while(S.size()&&arr[S.top()]>=arr[i]){
                S.pop();
            }
            if(S.empty())dp[i]=(i+1)*arr[i]%MOD;
            else dp[i]=(dp[S.top()]+(i-S.top())*arr[i])%MOD;
            S.push(i);
        }
        return accumulate(dp,dp+arr.size(),0ll)%MOD;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr{3,1,2,4};
    auto ans=sol.sumSubarrayMins(arr);
    DBG(ans);

    system("pause");
    return 0;
}
