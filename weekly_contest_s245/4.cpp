#include "utils.h"

class Solution {
    //自己写个数据结构表示最小-最大范围
    struct range{
        int Min=INT_MAX,Max=INT_MIN;
        void update(const range&other){
            chmin(Min,other.Min+1);
            chmax(Max,other.Max+1);
        }
    };
public:
    //本题可以进行动态规划
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        //令dp[l][i][j]表示：有l个选手参赛，要配对的两位选手离左右边界距离还有i和j，这种情况下他俩要匹配需要几步
        range dp[n+1][n][n];
        //优化策略：只考虑i<=j的情况。因为 dp[l][i][j] 和 dp[l][j][i] 是对称的
        //为了方便起见，称距边界距离i的选手为A，距边界距离j的选手为B
        FOR(l,2,n+1){
            REP(i,l/2){
                FOR(j,i,l-i-1){
                    //如果两位选手到边界一样远，说明马上就能匹配
                    if(i==j)dp[l][i][j]={1,1};
                    //如果两位选手分居中数两侧
                    else if(j<(l+1)/2)
                        //枚举A选手左侧的晋级数量
                        REP(a,i+1)
                            //枚举B选手右侧的晋级数量
                            FOR(b,i-a,j-a)
                                dp[l][i][j].update(dp[(l+1)/2][min(a,b)][max(a,b)]);
                    //如果两位选手位于中数的一侧
                    else
                        //枚举A选手左侧的晋级数量
                        REP(a,i+1){
                            //key为无论怎么选一定会落在B选手右侧的晋级数
                            int key=(j*2-l+1)/2+i-a;
                            //枚举B选手右侧未确定的晋级数
                            REP(b,l-i-j-1)
                                dp[l][i][j].update(dp[(l+1)/2][min(a,key+b)][max(a,key+b)]);
                        }
                }
            }
        }
        //最后记得答案不是dp[n][firstPlayer][secondPlayer]
        //需要手动计算出他俩到边界的距离，再去找答案
        int a=firstPlayer-1,b=n-secondPlayer;
        if(a>b)swap(a,b);
        return {dp[n][a][b].Min,dp[n][a][b].Max};
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=5;
    int firstPlayer=3;
    int secondPlayer=5;
    auto ans=sol.earliestAndLatest(n,firstPlayer,secondPlayer);
    DBGV(ans);

    system("pause");
    return 0;
}
