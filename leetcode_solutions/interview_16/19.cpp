#include "Union.h"
#include "utils.h"

Union u(1000000);
class Solution {
public:
    vector<int> pondSizes(vector<vector<int>>& land) {
        u.reset();
        int m=land.size(),n=land[0].size();
        REP(i,m)REP(j,n)if(!land[i][j]){
            FOR(ii,i-1,i+2)FOR(jj,j-1,j+2)if(VALID&&!land[ii][jj]){
                u.unite(i*n+j,ii*n+jj);
            }
        }
        vi ans;
        REP(i,m)REP(j,n)if(!land[i][j]&&u.Find(i*n+j)==i*n+j){
            ans.pb(u.size[i*n+j]);
        }
        sort(ALL(ans));
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi land=makevvi("[[0,2,1,0],[0,1,0,1],[1,1,0,1],[0,1,0,1]]");
    auto ans=sol.pondSizes(land);
    DBGV(ans);

    system("pause");
    return 0;
}
