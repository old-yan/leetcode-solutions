#include "utils.h"

class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        int m=seats.size(),n=seats[0].size();
        int _dp[m+1][1<<n];
        memset(_dp,0x80,sizeof(_dp));
        auto dp=_dp+1;
        fill(dp[-1],dp[0],0);
        REP(i,m){
            REP(state,1<<n){
                if(state&(state<<1))continue;
                bool flag=false;
                REP(j,n)if((state>>j&1)&&seats[i][j]=='#'){
                    flag=true;
                    break;
                }
                if(flag)continue;
                REP(pre,1<<n){
                    if((state&(pre<<1))||(pre&(state<<1)))continue;
                    chmax(dp[i][state],dp[i-1][pre]+__builtin_popcount(state));
                }
            }
        }
        return *max_element(dp[m-1],dp[m]);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<vector<char>>seats{
        {'#','.','#','#','.','#'},
        {'.','#','#','#','#','.'},
        {'#','.','#','#','.','#'}
    };
    auto ans=sol.maxStudents(seats);
    DBG(ans);

    system("pause");
    return 0;
}