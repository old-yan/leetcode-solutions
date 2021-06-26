#include "utils.h"

class Solution {
public:
    bool escapeMaze(vector<vector<string>>& maze) {
        int m=maze[0].size(),n=maze[0][0].size(),T=maze.size();
        bool dp[T][m][n][2][3];
        memset(dp,0,sizeof(dp));
        dp[0][0][0][0][0]=dp[0][0][0][0][1]=dp[0][0][0][0][2]=dp[0][0][0][1][0]=dp[0][0][0][1][1]=dp[0][0][0][1][2]=true;
        FOR(t,1,T){
            REP(i,m){
                REP(j,n){
                    auto A=dp[t][i][j];
                    auto c=maze[t][i][j];
                    REP(k,5){
                        int ii=i+di[k],jj=j+dj[k];
                        if(!VALID)continue;
                        auto B=dp[t-1][ii][jj];
                        A[0][0]|=c=='.'&&B[0][0];
                        A[0][1]|=(c=='.'&&B[0][0])||(c=='#'&&B[0][0]);
                        A[0][2]|=(c=='.'&&B[0][2])||(c=='#'&&B[0][0]);
                        A[1][0]|=(c=='.'&&B[1][0])||(c=='#'&&B[0][0]);
                        A[1][1]|=(c=='.'&&B[1][0])||(c=='#'&&(B[0][1]||B[1][0]));
                        A[1][2]|=(c=='.'&&B[1][2])||(c=='#'&&(B[0][2]||B[1][0]));
                        if(k==4){
                            A[0][1]|=B[0][1];
                            A[0][2]|=B[0][1];
                            A[1][1]|=B[1][1];
                            A[1][2]|=B[1][1];
                        }
                    }
                }
            }
        }
        auto ans=dp[T-1][m-1][n-1];
        return ans[0][0]||ans[0][1]||ans[0][2]||ans[1][0]||ans[1][1]||ans[1][2];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<vector<string>>maze{
        {"..###..##."},
        {"..######.."},
        {".#.#..#.#."},
        {".##..#.##."},
        {".########."},
        {".#..##...."},
        {".#.#####.."},
        {".###.###.."},
        {".########."},
        {".##.##.##."},
        {".###...##."},
        {".#####.#.."},
        {".##..###.."},
        {"..#####.#."},
        {".####.###."},
        {".###.###.."},
        {"..######.."}
    };
    auto ans=sol.escapeMaze(maze);
    DBG(ans);

    system("pause");
    return 0;
}
