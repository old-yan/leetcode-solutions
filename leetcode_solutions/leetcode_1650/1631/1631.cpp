#include "utils.h"

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size(),n=heights[0].size();
        int dp[m][n];
        memset(dp,0x3f,sizeof(dp));
        auto comp=[&](pair<int,int>&x,pair<int,int>&y){
            return dp[x.first][x.second]>dp[y.first][y.second];
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(comp)>Q(comp);
        dp[0][0]=0;
        Q.emplace(0,0);
        while(Q.size()){
            auto [i,j]=Q.top();
            Q.pop();
            REP(k,4){
                int ii=i+di[k],jj=j+dj[k];
                if(!VALID)continue;
                if(chmin(dp[ii][jj],max(dp[i][j],abs(heights[i][j]-heights[ii][jj])))){
                    Q.emplace(ii,jj);
                }
            }
        }
        return dp[m-1][n-1];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi heights=makevvi("[[1,2,2],[3,8,2],[5,3,5]]");
    auto ans=sol.minimumEffortPath(heights);
    DBG(ans);

    system("pause");
    return 0;
}
