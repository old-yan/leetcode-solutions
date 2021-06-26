#include "Union.h"
#include "utils.h"

char grid[20][20];
class Solution {
    pair<int,int>posB,posS,posT;
    int dp[20][20][4],state[20][20],m,n;
    void init(vector<vector<char>>& _grid){
        m=_grid.size(),n=_grid[0].size();
        REP(i,m)REP(j,n){
            grid[i][j]=_grid[i][j];
            if(grid[i][j]=='B')posB={i,j};
            else if(grid[i][j]=='S')posS={i,j};
            else if(grid[i][j]=='T')posT={i,j};
        }
    }
    bool isValid(int i,int j){return i>=0&&i<m&&j>=0&&j<n;}
    int checkConnect(int i,int j){
        if(state[i][j])return state[i][j];
        grid[i][j]='#';
        Union u(m*n);
        REP(i,m)REP(j,n)if(grid[i][j]=='.')REP(k,4){
            int ii=i+di[k],jj=j+dj[k];
            if(VALID&&grid[ii][jj]=='.')u.unite(i*n+j,ii*n+jj);
        }
        grid[i][j]='.';
        int res=0x8421;
        REP(k1,4)if(isValid(i+di[k1],j+dj[k1])){
            REP(k2,k1)if(isValid(i+di[k2],j+dj[k2])){
                if(u.same((i+di[k1])*n+j+dj[k1],(i+di[k2])*n+j+dj[k2]))res|=(1<<(k1*4+k2))|(1<<(k2*4+k1));
            }
        }
        return state[i][j]=res;
    }
public:
    int minPushBox(vector<vector<char>>&_grid) {
        memset(dp,0x3f,sizeof(dp));
        memset(state,0,sizeof(state));
        init(_grid);
        grid[posS.first][posS.second]='.';
        grid[posT.first][posT.second]='.';
        queue<tuple<int,int,int>>Q;
        {
            Union u(m*n);
            REP(i,m)REP(j,n)if(grid[i][j]=='.')REP(k,4){
                int ii=i+di[k],jj=j+dj[k];
                if(VALID&&grid[ii][jj]=='.')u.unite(i*n+j,ii*n+jj);
            }
            grid[posB.first][posB.second]='.';
            REP(k,4){
                int ii=posB.first+di[k],jj=posB.second+dj[k];
                if(VALID&&u.same(ii*n+jj,posS.first*n+posS.second)){
                    ii=posB.first-di[k],jj=posB.second-dj[k];
                    if(VALID&&grid[ii][jj]=='.'){
                        dp[ii][jj][k]=1;
                        Q.emplace(ii,jj,k);
                    }
                }
            }
        }
        while(Q.size()){
            auto [i,j,dir]=Q.front();
            int dis=dp[i][j][dir];
            Q.pop();
            auto res=checkConnect(i,j);
            REP(k,4)if(res>>(dir*4+k)&1){
                int ii=i-di[k],jj=j-dj[k];
                if(ii==posT.first&&jj==posT.second)return dis+1;
                if(VALID&&grid[ii][jj]=='.'&&chmin(dp[ii][jj][k],dis+1)){
                    Q.emplace(ii,jj,k);
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

    vector<vector<char>>grid={
        {'#','.','.','#','T','#','#','#','#'},
        {'#','.','.','#','.','#','.','.','#'},
        {'#','.','.','#','.','#','B','.','#'},
        {'#','.','.','.','.','.','.','.','#'},
        {'#','.','.','.','.','#','.','S','#'},
        {'#','.','.','#','.','#','#','#','#'}
    };
    auto ans=sol.minPushBox(grid);
    DBG(ans);

    system("pause");
    return 0;
}
