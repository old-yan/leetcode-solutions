#include "utils.h"

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        int dp[n+1];
        dp[n]=0;
        REPR(i,n-1){
            dp[i]=stoneValue[i]-dp[i+1];
            if(i+1<n)chmax(dp[i],stoneValue[i]+stoneValue[i+1]-dp[i+2]);
            if(i+2<n)chmax(dp[i],stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]-dp[i+3]);
        }
        if(dp[0]>0)return "Alice";
        else if(!dp[0])return "Tie";
        else return "Bob";
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi stoneValue{-1,-2,-3};
    auto ans=sol.stoneGameIII(stoneValue);
    DBG(ans);

    system("pause");
    return 0;
}
