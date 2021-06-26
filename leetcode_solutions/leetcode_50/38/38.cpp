#include "utils.h"

class Solution {
    string dp[30];
public:
    string countAndSay(int n) {
        REP(i,n){
            if(!i)dp[i]="1";
            else{
                for(int j=0,k;j<dp[i-1].size();j=k){
                    for(k=j+1;dp[i-1][k]==dp[i-1][j];k++);
                    dp[i]+=i2s(k-j);
                    dp[i]+=dp[i-1][j];
                }
            }
        }
        return dp[n-1];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    auto ans=sol.countAndSay(20);
    DBG(ans);

    system("pause");
    return 0;
}
