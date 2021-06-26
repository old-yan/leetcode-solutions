#include "utils.h"

class Solution {
    int m,n;
    int belong[50][50];
    int ans=0;
    int findMaxDamage(int&maxDamager,vvi&grid){
        memset(belong,0,sizeof(belong));
        int maxDamage=0;
        int group=0;
        REP(i,m){
            REP(j,n){
                if(belong[i][j]>0)continue;
                if(grid[i][j]==1){
                    group++;
                    static bitset<2500>risky;
                    risky.reset();
                    static queue<pair<int,int>>Q;
                    belong[i][j]=group;
                    Q.emplace(i,j);
                    while(Q.size()){
                        auto [i,j]=Q.front();
                        Q.pop();
                        REP(k,4){
                            int ii=i+di[k],jj=j+dj[k];
                            if(VALID){
                                if(!grid[ii][jj])risky.set(ii*n+jj);
                                else if(grid[ii][jj]==1&&!belong[ii][jj]){
                                    belong[ii][jj]=group;
                                    Q.emplace(ii,jj);
                                }
                            }
                        }
                    }
                    if(chmax(maxDamage,int(risky.count())))maxDamager=group;
                }
            }
        }
        return maxDamage;
    }
    void buildWall(int maxDamager,vvi&grid){
        REP(i,m){
            REP(j,n){
                if(belong[i][j]==maxDamager){
                    grid[i][j]=-1;
                    REP(k,4){
                        int ii=i+di[k],jj=j+dj[k];
                        if(VALID&&!grid[ii][jj]){
                            ans++;
                        }
                    }
                }
            }
        }
    }
    void virusSpread(vvi&grid){
        queue<pair<int,int>>tobeInfected;
        REP(i,m){
            REP(j,n){
                if(!grid[i][j]){
                    REP(k,4){
                        int ii=i+di[k],jj=j+dj[k];
                        if(VALID&&grid[ii][jj]==1){
                            tobeInfected.emplace(i,j);
                            break;
                        }
                    }
                }
            }
        }
        while(tobeInfected.size()){
            auto [i,j]=tobeInfected.front();
            grid[i][j]=1;
            tobeInfected.pop();
        }
    }
public:
    int containVirus(vector<vector<int>>&grid) {
        m=grid.size();
        n=grid[0].size();
        while(true){
            int maxDamage=0,maxDamager;
            if(!findMaxDamage(maxDamager,grid))break;
            buildWall(maxDamager,grid);
            virusSpread(grid);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi grid=makevvi("[[0,1,0,1,1,1,1,1,1,0],[0,0,0,1,0,0,0,0,0,0],[0,0,1,1,1,0,0,0,1,0],[0,0,0,1,1,0,0,1,1,0],[0,1,0,0,1,0,1,1,0,1],[0,0,0,1,0,1,0,1,1,1],[0,1,0,0,1,0,0,1,1,0],[0,1,0,1,0,0,0,1,1,0],[0,1,1,0,0,1,1,0,0,1],[1,0,1,1,0,1,0,1,0,1]]");
    auto ans=sol.containVirus(grid);
    DBG(ans);

    system("pause");
    return 0;
}
