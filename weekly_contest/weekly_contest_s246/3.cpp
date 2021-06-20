#include "Union.h"
#include "utils.h"

Union u1(250000),u2(250000);
class Solution {
    int m,n;
    void work(vvi&g,Union&u){
        REP(i,m)REP(j,n)if(g[i][j])REP(k,4){
            int ii=i+di[k],jj=j+dj[k];
            if(!VALID)continue;
            if(g[ii][jj])u.unite(i*n+j,ii*n+jj);
        }
    }
public:
    //本题算是套路题了
    //  首先把grid1、grid2各自跑一遍并查集
    //  然后对grid2的每个组分，查询它们在grid1里是不是属于同一块岛屿
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        u1.reset(),u2.reset();
        m=grid2.size(),n=grid2[0].size();
        //grid1在u1上建立并查集
        work(grid1,u1);
        //grid2在u2上建立并查集
        work(grid2,u2);
        //groups收集grid2的每块岛屿
        unordered_map<int,vi>groups;
        REP(i,m)REP(j,n)if(grid2[i][j]){
            groups[u2.Find(i*n+j)].pb(i*n+j);
        }
        int ans=0;
        for(auto&group:groups){
            //belong表示这块岛屿在grid1里的归属，初始为-1
            int belong=-1;
            //flag表示这块岛屿是否从属于同一块大岛
            bool flag=true;
            for(auto i:group.second){
                int find=u1.Find(i);
                if(belong<0){
                    int ii=find/n,jj=find%n;
                    //如果归属于某块水域，那么flag置为false
                    if(!grid1[ii][jj]){
                        flag=false;
                        break;
                    }
                    belong=find;
                }
                else if(find!=belong){
                    flag=false;
                    break;
                }
            }
            //如果flag为true，那么子岛屿数量加一
            if(flag)ans++;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi grid1=makevvi("[[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]]");
    vvi grid2=makevvi("[[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]");
    auto ans=sol.countSubIslands(grid1,grid2);
    DBG(ans);

    system("pause");
    return 0;
}
