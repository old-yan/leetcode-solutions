#include "utils.h"

class Solution {
    int _dp[40001][2]={0};
public:
    int maxTurbulenceSize(vector<int>& arr) {
        auto dp=_dp+1;
        REP(i,arr.size()-1){
            if(arr[i]<arr[i+1]){
                dp[i][0]=dp[i-1][1]+1;
                dp[i][1]=0;
            }
            else if(arr[i]>arr[i+1]){
                dp[i][1]=dp[i-1][0]+1;
                dp[i][0]=0;
            }
            else dp[i][0]=dp[i][1]=0;
        }
        return *max_element(dp[0],dp[arr.size()])+1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr{9,4,2,10,7,8,8,1,9};
    auto ans=sol.maxTurbulenceSize(arr);
    DBG(ans);

    system("pause");
    return 0;
}
