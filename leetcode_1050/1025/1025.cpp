#include "EulerPrime.h"
#include "utils.h"

class Solution {
    bool dp[1001]={0};
public:
    bool divisorGame(int n) {
        static EulerPrime<1000>ep;
        dp[1]=false;
        for(int i=2;i<=n;i++){
            ep.getFactors(i);
            for(int _=1;_<ep.flen-1;_++){
                int f=ep.factors[_];
                if(!dp[i-f]){
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

    int n=100;
    auto ans=sol.divisorGame(n);
    DBG(ans);

    system("pause");
    return 0;
}
