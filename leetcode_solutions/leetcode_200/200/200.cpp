#include "utils.h"

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        Union u(m*n+1);
        #define a(i,j) (i)*n+(j)
        REP(i,m){
            REP(j,n){
                if(grid[i][j]=='0'){
                    u.unite(a(i,j),m*n);
                }
                else{
                    if(i+1<m&&j<n&&grid[i+1][j]=='1')u.unite(a(i,j),a(i+1,j));
                    if(i<m&&j+1<n&&grid[i][j+1]=='1')u.unite(a(i,j),a(i,j+1));
                }
            }
        }
        return u.group-1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<vector<char>>grid{
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
    auto ans=sol.numIslands(grid);
    DBG(ans);

    system("pause");
    return 0;
}
