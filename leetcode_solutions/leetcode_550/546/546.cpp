#include "utils.h"

class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        //预处理，afterSame[i]是个数，表示boxes下标i后方有几个和自己相同的值
        vi afterSame(boxes.size());
        vi num(101,0);
        REPR(i,boxes.size()-1)afterSame[i]=++num[boxes[i]];
        //预处理，beforeSame[i]是个数组，表示boxes下标i前方和自己相同的值的下标
        vi beforeSame[boxes.size()];
        vi idx[101];
        REP(i,boxes.size()){
            idx[boxes[i]].pb(i);
            beforeSame[i]=idx[boxes[i]];
        }
        //开始转移
        //dp[l][r][k]表示l~r区间，配合后方k个boxes[r]所能得的分数
        ll dp[boxes.size()][boxes.size()][boxes.size()+1];
        #define a(l,r,k) (r>=0?dp[l][r][k]:0)
        memset(dp,0,sizeof(dp));
        REP(r,boxes.size()){
            for(int j:beforeSame[r]){
                REP(l,j+1){
                    REP(k,afterSame[r]){
                        if(j<r)chmax(dp[l][r][k],dp[l][j][k+1]+dp[j+1][r-1][0]);
                        else chmax(dp[l][r][k],a(l,r-1,0)+(k+1)*(k+1));
                    }
                }
            }
        }
        return dp[0][boxes.size()-1][0];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi boxes{
        1,3,2,2,2,3,4,3,1
    };
    auto ans=sol.removeBoxes(boxes);
    DBG(ans);

    system("pause");
    return 0;
}
