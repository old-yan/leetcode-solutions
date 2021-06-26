#include "Sum.h"
#include "utils.h"

Sumer2d<ll,0x0f>S;
class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        S.build(grid);
        auto check=[&](int r1,int r2,int c1,int c2){
            int sum=S.query_row(r1,c1,c2);
            FOR(r,r1,r2+1)if(sum!=S.query_row(r,c1,c2))return false;
            FOR(c,c1,c2+1)if(sum!=S.query_col(c,r1,r2))return false;
            if(sum!=S.query_dif(r1,c1,r2,c2))return false;
            if(sum!=S.query_sum(r1,c2,r2,c1))return false;
            return true;
        };
        REPR(k,min(m,n)){
            REP(i,m-k+1){
                REP(j,n-k+1){
                    if(check(i,i+k-1,j,j+k-1))return k;
                }
            }
        }
        return -1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi grid=makevvi("[[7,1,4,5,6],[2,5,1,6,4],[1,5,4,3,2],[1,2,7,3,4]]");
    auto ans=sol.largestMagicSquare(grid);
    DBG(ans);

    system("pause");
    return 0;
}
