#include "utils.h"

class Solution {
    int m,n,l;
    vector<pair<int,int>>keys,stones,start,end;
    int turn[17][17]={0};
    void get_dis(vector<string>& maze){
        l=keys.size();
        int disfromkey[l][m][n];
        memset(disfromkey,0x3f,sizeof(disfromkey));
        REP(idx,l){
            queue<tuple<int,int,int>>Q;
            auto [i,j]=keys[idx];
            disfromkey[idx][i][j]=0;
            Q.emplace(i,j,0);
            while(Q.size()){
                auto [i,j,d]=Q.front();
                Q.pop();
                REP(k,4){
                    int ii=i+di[k],jj=j+dj[k];
                    if(!VALID||maze[ii][jj]=='#')continue;
                    if(chmin(disfromkey[idx][ii][jj],d+1)){
                        Q.emplace(ii,jj,d+1);
                    }
                }
            }
        }
        REP(i,l)REP(j,i){
            int dis=0x3f3f3f3f;
            for(auto [ii,jj]:stones){
                chmin(dis,disfromkey[i][ii][jj]+disfromkey[j][ii][jj]);
            }
            turn[i][j]=turn[j][i]=dis;
        }
    }
public:
    int minimalSteps(vector<string>& maze) {
        m=maze.size(),n=maze[0].size();
        REP(i,m)REP(j,n){
            if(maze[i][j]=='O')stones.emplace_back(i,j);
            else if(maze[i][j]=='M')keys.emplace_back(i,j);
            else if(maze[i][j]=='S')start.emplace_back(i,j);
            else if(maze[i][j]=='T')end.emplace_back(i,j);
        }
        keys.emplace_back(start[0]);
        get_dis(maze);
        int ans=0x3f3f3f3f;
        int dp[1<<(l-1)][l];
        memset(dp,0x3f,sizeof(dp));
        dp[0][l-1]=0;
        FOR(state,1,1<<(l-1)){
            REP(j,l-1)if(state>>j&1){
                REP(pre,l-1)if((state-(1<<j))>>pre&1){
                    chmin(dp[state][j],dp[state-(1<<j)][pre]+turn[pre][j]);
                }
                if(__builtin_popcount(state)==1){
                    chmin(dp[state][j],dp[0][l-1]+turn[l-1][j]);
                }
            }
        }
        int disfromend[m][n];
        memset(disfromend,0x3f,sizeof(disfromend));
        queue<tuple<int,int,int>>Q;
        disfromend[end[0].first][end[0].second]=0;
        Q.emplace(end[0].first,end[0].second,0);
        while(Q.size()){
            auto [i,j,d]=Q.front();
            Q.pop();
            REP(k,4){
                int ii=i+di[k],jj=j+dj[k];
                if(!VALID||maze[ii][jj]=='#')continue;
                if(chmin(disfromend[ii][jj],d+1)){
                    Q.emplace(ii,jj,d+1);
                }
            }
        }
        REP(idx,l){
            auto [i,j]=keys[idx];
            chmin(ans,dp[(1<<l)-1][idx]+disfromend[i][j]);
        }
        return ans==0x3f3f3f3f?-1:ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>maze{
        "S#O",
        "M..",
        "M.T"
    };
    auto ans=sol.minimalSteps(maze);
    DBG(ans);

    system("pause");
    return 0;
}
