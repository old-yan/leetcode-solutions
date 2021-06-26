#include "utils.h"

class Solution {
    bool dp[8][8][7]={0};
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        REP(i,bottom.size())dp[0][i][bottom[i]-'A']=true;
        FOR(i,1,bottom.size()){
            REP(j,bottom.size()-i){
                for(auto&allow:allowed){
                    if(dp[i-1][j][allow[0]-'A']&&dp[i-1][j+1][allow[1]-'A']){
                        dp[i][j][allow[2]-'A']=true;
                    }
                }
            }
        }
        return any_of(dp[bottom.size()-1][0],dp[bottom.size()-1][0]+7,[](bool x){return x;});
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string bottom="BCD";
    vector<string>allowed{"BCG", "CDE", "GEA", "FFF"};
    auto ans=sol.pyramidTransition(bottom,allowed);
    DBG(ans);

    system("pause");
    return 0;
}
