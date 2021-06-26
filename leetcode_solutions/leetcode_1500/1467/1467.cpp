#include "utils.h"

class Solution {
public:
    double getProbability(vector<int>& balls) {
        int n=balls.size();
        int all=accumulate(ALL(balls),0);
        double dp[n+1][all/2+1][n*2+1];
        memset(dp,0,sizeof(dp));
        #define a(idx,resta,type_dif) dp[idx][resta][type_dif+n]
        REP(i,n+1)a(n,0,0)=1;
        int rest=0;
        REPR(idx,n-1){
            rest+=balls[idx];
            REPR(resta,rest){
                int restb=rest-resta;
                if(restb>all/2)break;
                if(resta>all/2)continue;
                FOR(type_dif,-idx,idx+1){
                    REP(a,balls[idx]+1){
                        int b=balls[idx]-a;
                        if(b>restb)continue;
                        if(a>resta)break;
                        a(idx,resta,type_dif)+=a(idx+1,resta-a,type_dif+(a==balls[idx])-(b==balls[idx]))*combination(resta,a)*combination(rest-resta,balls[idx]-a)/combination(rest,balls[idx]);
                    }
                }
            }
        }
        return a(0,all/2,0);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi balls{2,1,1};
    auto ans=sol.getProbability(balls);
    DBG(ans);

    system("pause");
    return 0;
}
