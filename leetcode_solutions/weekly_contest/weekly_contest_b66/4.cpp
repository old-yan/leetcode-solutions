#include "utils.h"

class Solution {
    //计算上三角形数量
    int solve(vector<vector<int>>& grid){
        int m=grid.size(),n=grid[0].size();
        //dp[i][j]表示以 (i,j) 为右底角的上三角形的数量，注意大小为一的上三角形不算答案
        int dp[m][n];
        int ans=0;
        for(int i=0;i<m;i++){
            // ones 表示左侧连续 1 的数量（包括当前）
            int ones=0;
            for(int j=0;j<n;j++){
                if(grid[i][j])ones++;
                else ones=0;
                //如果连续 1 数量小于等于 1，那么不可能凑出上三角形
                if(ones<=1)dp[i][j]=0;
                //如果不存在左上的邻点，那么不可能凑出上三角形
                else if(i==0 or j==0 or !grid[i-1][j-1])dp[i][j]=0;
                //如果存在左上的邻点，那么可以计算一下当前位置上三角形的数量
                else dp[i][j]=min(dp[i-1][j-1]+1,(ones-1)/2);
                ans+=dp[i][j];
            }
        }
        return ans;
    }
public:
    //本题显然是 dp ,而且三角形朝上和朝下是两个对称的问题，只要会算一种情况，把 grid 上下翻转就可以算出另一种情况
    //所以我们只讨论上三角形
    //不妨枚举每个上三角形的右底角，以某点为右底角的上三角形的大小取决于左侧连续 1 的数量，还依赖于该点左上点的情况
    int countPyramids(vector<vector<int>>& grid) {
        int ans1=solve(grid);
        reverse(grid.begin(),grid.end());
        int ans2=solve(grid);
        return ans1+ans2;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<vector<int>>grid=makevvi("[[1,1,1,1,0],[1,1,1,1,1],[1,1,1,1,1],[0,1,0,0,1]]");
    auto ans=sol.countPyramids(grid);
    DBG(ans);

    system("paused");
    return 0;
}