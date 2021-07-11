#include "utils.h"

class Solution {
public:
    //看数据范围，猜测要使用动态规划
    //令：dp[t][i] 表示 t 时刻到达 i 城市的最小花费
    //则：dp[t1][i] 若由 dp[t2][j] 转移而来，必有 t1 > t2 ，那我们可以按照第一维度从小到大进行处理
    //注意到 edges.size() 比较小，那么对于每个时刻，可以枚举所有的边，进行转移
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n=passingFees.size();
        int dp[maxTime+1][n];
        memset(dp,0x3f,sizeof(dp));
        dp[0][0]=passingFees[0];
        for(int t=1;t<=maxTime;t++){
            for(auto&e:edges){
                int i=e[0],j=e[1],d=e[2];
                if(d<=t){
                    chmin(dp[t][i],dp[t-d][j]+passingFees[i]);
                    chmin(dp[t][j],dp[t-d][i]+passingFees[j]);
                }
            }
        }
        int ans=0x3f3f3f3f;
        for(int t=0;t<=maxTime;t++)chmin(ans,dp[t][n-1]);
        return ans==0x3f3f3f3f?-1:ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int maxTime=30;
    vvi edges=makevvi("[[0,1,10],[1,2,10],[2,5,10],[0,3,1],[3,4,10],[4,5,15]]");
    vi passingFees{5,1,2,20,20,3};
    auto ans=sol.minCost(maxTime,edges,passingFees);
    DBG(ans);

    system("pause");
    return 0;
}
