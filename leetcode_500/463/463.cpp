#include "utils.h"

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int ans=0;
        REP(i,m){
            REP(j,n){
                if(!grid[i][j])continue;
                REP(k,4){
                    int ii=i+di[k],jj=j+dj[k];
                    if(ii<0||ii>=m||jj<0||jj>=n||grid[ii][jj]==0){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi grid{
        {0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}
    };
    auto ans=sol.islandPerimeter(grid);
    DBG(ans);

    system("pause");
    return 0;
}
