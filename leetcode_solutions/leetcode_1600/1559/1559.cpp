#include "Union.h"
#include "utils.h"

class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size();
        Union u(m*n);
        REP(i,m)REP(j,n)REP(k,2){
            int ii=i+di[k],jj=j+dj[k];
            if(!VALID)continue;
            if(grid[ii][jj]==grid[i][j]){
                if(!u.unite(i*n+j,ii*n+jj))return true;
            }
        }
        return false;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<vector<char>>grid{
        {"a","a","a","a"},
        {"a","b","b","a"},
        {"a","b","b","a"},
        {"a","a","a","a"}
    };
    auto ans=sol.containsCycle(grid);
    DBG(ans);

    system("pause");
    return 0;
}
