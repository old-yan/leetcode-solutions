#include "utils.h"

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vi row(m,0),col(n,0);
        REP(i,m)REP(j,n){
            if(grid[i][j]){
                row[i]++;
                col[j]++;
            }
        }
        int ans=0;
        REP(i,m)REP(j,n){
            if(grid[i][j]){
                if(row[i]>1||col[j]>1)ans++;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi grid=makevvi("[[1,1,0,0],[0,0,1,0],[0,0,1,0],[0,0,0,1]]");
    auto ans=sol.countServers(grid);
    DBG(ans);

    system("pause");
    return 0;
}
