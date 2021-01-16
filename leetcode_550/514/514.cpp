#include "utils.h"

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n1=ring.size(),n2=key.size();
        ll dp[n2][n1];
        REP(i,n2){
            REP(j,n1){
                if(key[i]==ring[j]){
                    if(!i)dp[i][j]=min(j,n1-j)+1;
                    else{
                        dp[i][j]=INT_MAX;
                        REP(k,n1){
                            chmin(dp[i][j],dp[i-1][k]+min((j-k+n1)%n1,(k-j+n1)%n1)+1);
                        }
                    }
                }
                else dp[i][j]=INT_MAX;
            }
        }
        return *min_element(dp[n2-1],dp[n2-1]+n1);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string ring="godding";
    string key="gd";
    auto ans=sol.findRotateSteps(ring,key);
    DBG(ans);

    system("pause");
    return 0;
}
