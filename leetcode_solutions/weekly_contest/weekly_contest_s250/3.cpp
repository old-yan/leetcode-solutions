#include "utils.h"

class Solution {
public:
    //所有带绝对值的问题，只要分情况讨论肯定没错
    long long maxPoints(vector<vector<int>>& points) {
        int m=points.size(),n=points[0].size();
        //令 dp[i][j] 表示从上到下走到第 i 行第 j 列此时的得分
        ll dp[m][n];
        memset(dp,0x80,sizeof(dp));
        //先特殊处理第一行
        {
            int i=0;
            for(int j=0;j<n;j++)
                dp[i][j]=points[i][j];
        }
        //处理 [1,m-1] 行
        for(int i=1;i<m;i++){
            //第一种可能：dp[i][j] 由 dp[i-1][k] 转移而来， k<j
            //dp[i][j] = points[i][j] + dp[i-1][k] + k-j
            //从左往右走一趟, opt 表示左侧最大的 dp[i-1][k]+k
            //dp[i][j] = points[i][j] + opt - j
            ll opt=INT_MIN;
            for(int j=0;j<n;j++){
                chmax(opt, dp[i-1][j]+j);
                chmax(dp[i][j],points[i][j]+opt-j);
            }
            //第二种可能：dp[i][j] 由 dp[i-1][k] 转移而来， k>j
            //dp[i][j] = points[i][j] + dp[i-1][k] + j-k
            //从右往左走一趟, opt 表示右侧最大的 dp[i-1][k]-k
            //dp[i][j] = points[i][j] + opt + j
            opt=INT_MIN;
            for(int j=n-1;j>=0;j--){
                chmax(opt, dp[i-1][j]-j);
                chmax(dp[i][j],points[i][j]+opt+j);
            }
        }
        return *max_element(dp[m-1],dp[m]);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi points=makevvi("[[1,2,3],[1,5,1],[3,1,1]]");
    auto ans=sol.maxPoints(points);
    DBG(ans);

    system("pause");
    return 0;
}
