#include "utils.h"

class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m=grid.size(),n=grid[0].size(),total=0;
        int starti,startj;
        REP(i,m){
            REP(j,n){
                if(islower(grid[i][j])){
                    total|=(1<<(grid[i][j]-'a'));
                }
                else if(grid[i][j]=='@'){
                    grid[i][j]='.';
                    starti=i;
                    startj=j;
                }
            }
        }
        int dp[total+1][m][n];
        memset(dp,0x3f,sizeof(dp));
        dp[0][starti][startj]=0;
        queue<tuple<int,int,int,int>>Q;
        Q.emplace(0,starti,startj,0);
        while(Q.size()){
            auto [state,i,j,dis]=Q.front();
            Q.pop();
            if(state==total)return dis;
            REP(k,4){
                int ii=i+di[k],jj=j+dj[k];
                if(!VALID)continue;
                if(grid[ii][jj]=='.'){
                    if(chmin(dp[state][ii][jj],dis+1)){
                        Q.emplace(state,ii,jj,dis+1);
                    }
                }
                else if(islower(grid[ii][jj])){
                    int next=state|(1<<(grid[ii][jj]-'a'));
                    if(chmin(dp[next][ii][jj],dis+1)){
                        Q.emplace(next,ii,jj,dis+1);
                    }
                }
                else if(isupper(grid[ii][jj])&&(state&(1<<(grid[ii][jj]-'A')))){
                    if(chmin(dp[state][ii][jj],dis+1)){
                        Q.emplace(state,ii,jj,dis+1);
                    }
                }
            }
        }
        return -1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>grid={
        "@.a.#",
        "###.#",
        "b.A.B"
    };
    auto ans=sol.shortestPathAllKeys(grid);
    DBG(ans);

    system("pause");
    return 0;
}
