#include "utils.h"

class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n=locations.size();
        ll dp[n][fuel+1];
        memset(dp,0,sizeof(dp));
        dp[start][fuel]=1;
        FORR(i,fuel,1){
            REP(j,n){
                if(dp[j][i]){
                    REP(k,n){
                        if(k!=j&&i>=abs(locations[k]-locations[j])){
                            dp[k][i-abs(locations[k]-locations[j])]=(dp[k][i-abs(locations[k]-locations[j])]+dp[j][i])%MOD;
                        }
                    }
                }
            }
        }
        return accumulate(dp[finish],dp[finish+1],0ll)%MOD;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi locations{2,3,6,8,4};
    int start=1;
    int finish=3;
    int fuel=5;
    auto ans=sol.countRoutes(locations,start,finish,fuel);
    DBG(ans);

    system("pause");
    return 0;
}
