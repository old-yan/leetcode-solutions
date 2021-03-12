#include "Union.h"
#include "utils.h"

class Solution {
public:
    int largestIsland(vector<vector<int>>&grid) {
        int m=grid.size(),n=grid[0].size();
        Union u(m*n);
        int ans=0;
        REP(i,m){
            REP(j,n){
                if(!grid[i][j])continue;
                REP(k,4){
                    int ii=i+di[k],jj=j+dj[k];
                    if(VALID&&grid[ii][jj])u.unite(i*n+j,ii*n+jj);
                }
            }
        }
        REP(i,m*n)chmax(ans,u.size[i]);
        REP(i,m){
            REP(j,n){
                if(grid[i][j])continue;
                unordered_set<int>S;
                int sum=0;
                REP(k,4){
                    int ii=i+di[k],jj=j+dj[k];
                    if(VALID&&grid[ii][jj]){
                        int find=u.Find(ii*n+jj);
                        if(S.insert(find).second)sum+=u.size[find];
                    }
                }
                chmax(ans,sum+1);
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi grid=makevvi("[[1, 0], [0, 1]]");
    auto ans=sol.largestIsland(grid);
    DBG(ans);

    system("pause");
    return 0;
}
