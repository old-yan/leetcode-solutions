#include "utils.h"

class Solution {
public:
    bool canCross(vector<int>& stones) {
        bool dp[stones.size()][stones.size()+1];
        memset(dp,0,sizeof(dp));
        dp[0][1]=true;
        REP(i,stones.size()-1){
            int next=i;
            FOR(j,1,stones.size()){
                if(dp[i][j]){
                    while(next<stones.size()&&stones[next]<stones[i]+j)next++;
                    if(next==stones.size())break;
                    if(stones[next]==stones[i]+j){
                        dp[next][j-1]=dp[next][j]=dp[next][j+1]=true;
                    }
                }
            }
        }
        REP(j,stones.size()+1){
            if(dp[stones.size()-1][j])return true;
        }
        return false;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi stones{0,1,3,5,6,8,12,17};
    auto ans=sol.canCross(stones);
    DBG(ans);

    system("pause");
    return 0;
}
