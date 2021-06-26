#include "utils.h"

class Solution {
    struct state{
        int p[6];
        state(){}
        state(int _1,int _2,int _3,int _4,int _5){
            p[1]=_1,p[2]=_2,p[3]=_3,p[4]=_4,p[5]=_5;
        }
    };
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int m=2,n=3;
        static short dp[6][6][6][6][6]={0};
        if(!dp[0][1][2][3][5]){
            memset(dp,0xff,sizeof(dp));
            queue<state>Q;
            dp[0][1][2][3][4]=0;
            Q.emplace(0,1,2,3,4);
            while(Q.size()){
                auto p=Q.front();
                int q=dp[p.p[1]][p.p[2]][p.p[3]][p.p[4]][p.p[5]];
                Q.pop();
                int grid[m][n];
                FOR(i,1,6){
                    grid[p.p[i]/n][p.p[i]%n]=i;
                }
                p.p[0]=15-accumulate(p.p+1,p.p+6,0);
                int i=p.p[0]/n,j=p.p[0]%n;
                REP(k,4){
                    int ii=i+di[k],jj=j+dj[k];
                    if(VALID){
                        swap(p.p[0],p.p[grid[ii][jj]]);
                        if(dp[p.p[1]][p.p[2]][p.p[3]][p.p[4]][p.p[5]]<0){
                            dp[p.p[1]][p.p[2]][p.p[3]][p.p[4]][p.p[5]]=q+1;
                            Q.emplace(p);
                        }
                        swap(p.p[0],p.p[grid[ii][jj]]);
                    }
                }
            }
        }
        state p;
        REP(i,m)REP(j,n)p.p[board[i][j]]=i*n+j;
        return dp[p.p[1]][p.p[2]][p.p[3]][p.p[4]][p.p[5]];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi board=makevvi("[[1,2,3],[4,0,5]]");
    auto ans=sol.slidingPuzzle(board);
    DBG(ans);

    system("pause");
    return 0;
}
