#include "utils.h"

class Solution {
public:
    bool winnerSquareGame(int n) {
        bool dp[n+1];
        dp[0]=false;
        FOR(i,1,n+1){
            dp[i]=false;
            for(int j=1;j*j<=i;j++){
                if(!dp[i-j*j]){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[n];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=7;
    auto ans=sol.winnerSquareGame(n);
    DBG(ans);

    system("pause");
    return 0;
}
