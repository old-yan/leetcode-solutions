#include "Sum.h"
#include "utils.h"

Sumer2d<int,12>S;
class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        S.build(grid);
        auto check=[&](int i,int j){
            return i>=0&&i<m&&j>=0&&j<n;
        };
        vi res;
        REP(i,m)REP(j,n){
            for(int k=1;;k++){
                if(k==1){
                    res.pb(grid[i][j]);
                }
                else{
                    int upi=i-k*2+2,upj=j;
                    int li=i-k+1,lj=j-k+1;
                    int ri=i-k+1,rj=j+k-1;
                    if(!check(upi,upj)||!check(li,lj)||!check(ri,rj))break;
                    int all=S.query_dif(li+1,lj+1,i,j)+S.query_dif(upi,upj,ri-1,rj-1)+S.query_sum(ri,rj,i-1,j+1)+S.query_sum(upi+1,upj-1,li,lj);
                    res.pb(all);
                }
            }
        }
        sort(ALLR(res));
        res.resize(min(3,int(unique(ALL(res))-res.begin())));
        return res;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi grid=makevvi("[[3,4,5,1,3],[3,3,4,2,3],[20,30,200,40,10],[1,5,5,4,1],[4,3,2,2,5]]");
    auto ans=sol.getBiggestThree(grid);
    DBGV(ans);

    system("pause");
    return 0;
}
