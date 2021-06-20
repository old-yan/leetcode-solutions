#include "Union.h"
#include "utils.h"

class Solution {
public:
    int largestArea(vector<string>& grid) {
        int m=grid.size(),n=grid[0].size();
        Union u(m*n+1);
        REP(i,m)REP(j,n)if(grid[i][j])REP(k,4){
            int ii=i+di[k],jj=j+dj[k];
            if(!VALID||grid[ii][jj]=='0')u.unite(i*n+j,m*n);
            else if(grid[ii][jj]==grid[i][j])u.unite(i*n+j,ii*n+jj);
        }
        int ans=0;
        REP(i,m*n){
            if(u.Find(i)==i&&u.Find(i)!=u.Find(m*n)){
                chmax(ans,u.size[i]);
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>grid{
        "110","231","221"
    };
    auto ans=sol.largestArea(grid);
    DBG(ans);

    system("pause");
    return 0;
}
