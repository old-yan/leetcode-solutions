#include "utils.h"

class Solution {
    int m,n;
    bool dp[99][8][8][8][8];
public:
    bool canMouseWin(vector<string>& grid, int catJump, int mouseJump) {
        int m=grid.size(),n=grid[0].size();
        auto getpos=[&](int&r,int&c,char t){
            REP(i,m)REP(j,n)if(grid[i][j]==t){
                r=i,c=j;return;
            }
        };
        int rc,cc,rm,cm;
        getpos(rc,cc,'C');
        getpos(rm,cm,'M');
        auto check=[&](int i1,int j1,int i2,int j2){
            if(grid[i1][j1]=='#'||grid[i1][j1]=='#')return 0;
            else if(i1==i2&&j1==j2)return 1;
            else if(grid[i1][j1]=='F')return 1;
            else if(grid[i2][j2]=='F')return 2;
            else return 3;
        };
        REP(i1,m)REP(j1,n)REP(i2,m)REP(j2,n){
            int res=check(i1,j1,i2,j2);
            dp[98][i1][j1][i2][j2]=res<=1;
        }
        REPR(step,97){
            REP(i1,m)REP(j1,n)REP(i2,m)REP(j2,n){
                int res=check(i1,j1,i2,j2);
                if(res==1||res==2)dp[step][i1][j1][i2][j2]=res%2==step%2;
                else if(!res)dp[step][i1][j1][i2][j2]=true;
                else if(step%2){
                    bool&res=dp[step][i1][j1][i2][j2];
                    res=false;
                    FOR(i,i1,i1+catJump+1){
                        if(i>=m||grid[i][j1]=='#')break;
                        if(!dp[step+1][i][j1][i2][j2]){
                            res=true;
                            break;
                        }
                    }
                    FORR(i,i1-1,i1-catJump){
                        if(i<0||grid[i][j1]=='#')break;
                        if(!dp[step+1][i][j1][i2][j2]){
                            res=true;
                            break;
                        }
                    }
                    FOR(j,j1,j1+catJump+1){
                        if(j>=n||grid[i1][j]=='#')break;
                        if(!dp[step+1][i1][j][i2][j2]){
                            res=true;
                            break;
                        }
                    }
                    FORR(j,j1-1,j1-catJump){
                        if(j<0||grid[i1][j]=='#')break;
                        if(!dp[step+1][i1][j][i2][j2]){
                            res=true;
                            break;
                        }
                    }
                }
                else{
                    bool&res=dp[step][i1][j1][i2][j2];
                    res=false;
                    FOR(i,i2,i2+mouseJump+1){
                        if(i>=m||grid[i][j2]=='#')break;
                        if(!dp[step+1][i1][j1][i][j2]){
                            res=true;
                            break;
                        }
                    }
                    FORR(i,i2-1,i2-mouseJump){
                        if(i<0||grid[i][j2]=='#')break;
                        if(!dp[step+1][i1][j1][i][j2]){
                            res=true;
                            break;
                        }
                    }
                    FOR(j,j2,j2+mouseJump+1){
                        if(j>=n||grid[i2][j]=='#')break;
                        if(!dp[step+1][i1][j1][i2][j]){
                            res=true;
                            break;
                        }
                    }
                    FORR(j,j2-1,j2-mouseJump){
                        if(j<0||grid[i2][j]=='#')break;
                        if(!dp[step+1][i1][j1][i2][j]){
                            res=true;
                            break;
                        }
                    }
                }
            }
            if(step%2==0&&dp[step][rc][cc][rm][cm])return true;
        }
        return false;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>grid{
        "####F",
        "#C...",
        "M...."
    };
    int catJump=1;
    int mouseJump=2;
    auto ans=sol.canMouseWin(grid,catJump,mouseJump);
    DBG(ans);

    system("pause");
    return 0;
}
