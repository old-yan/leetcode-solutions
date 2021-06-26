#include "utils.h"

class Solution {
    vi fun(int n){
        if(n<=10){
            vi v(100,0);
            REP(i,n+1){
                int k=0;
                for(int j=i;j;j/=10){
                    k+=j%10;
                }
                v[k]++;
            }
            return v;
        }
        else{
            auto v=fun(n/10-1);
            REPR(i,99)if(v[i]){
                FOR(j,i+1,i+10){
                    v[j]+=v[i];
                }
            }
            FOR(i,n/10*10,n+1){
                int k=0;
                for(int j=i;j;j/=10){
                    k+=j%10;
                }
                v[k]++;
            }
            return v;
        }
    }
public:
    int countBalls(int lowLimit, int highLimit) {
        vi v1=fun(lowLimit-1);
        vi v2=fun(highLimit);
        REP(i,v2.size())v2[i]-=v1[i];
        return *max_element(ALL(v2));
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int lowLimit=5;
    int highLimit=15;
    auto ans=sol.countBalls(lowLimit,highLimit);
    DBG(ans);

    system("pause");
    return 0;
}
