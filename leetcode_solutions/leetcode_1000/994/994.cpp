#include "utils.h"

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        queue<pair<int,int>>Q;
        REP(i,m){
            REP(j,n){
                if(grid[i][j]==2){
                    Q.emplace(i,j);
                }
            }
        }
        int ans=0;
        while(int l=Q.size()){
            while(l--){
                auto [i,j]=Q.front();
                Q.pop();
                REP(k,4){
                    int ii=i+di[k],jj=j+dj[k];
                    if(VALID&&grid[ii][jj]==1){
                        grid[ii][jj]=2;
                        Q.emplace(ii,jj);
                    }
                }
            }
            if(Q.size())ans++;
        }
        REP(i,m){
            REP(j,n){
                if(grid[i][j]==1)return -1;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi grid=makevvi("[[2,1,1],[1,1,0],[0,1,1]]");
    auto ans=sol.orangesRotting(grid);
    DBG(ans);

    system("pause");
    return 0;
}
