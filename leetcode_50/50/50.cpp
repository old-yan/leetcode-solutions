#include "utils.h"

class Solution {
public:
    double myPow(double x, int n) {
        if(n==INT_MIN)return 1/myPow(x,INT_MAX)/x;
        if(n<0)return 1/myPow(x,-n);
        if(n==0)return 1;
        double dp[31];
        REP(i,31){
            if(!i)dp[i]=x;
            else dp[i]=dp[i-1]*dp[i-1];
        }
        double ans=1;
        REP(i,32){
            if(n&(1<<i)){
                ans*=dp[i];
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    double x=2.0;
    int n=10;
    auto ans=sol.myPow(x,n);
    DBG(ans);

    system("pause");
    return 0;
}
