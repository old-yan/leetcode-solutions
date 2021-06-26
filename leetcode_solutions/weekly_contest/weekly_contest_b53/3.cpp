#include "utils.h"

class Solution {
public:
    //看数据范围，n=100，那么 n^3 的做法可以过。
    //枚举每个点，作为菱形的最下角；确定好最下角后，再枚举边长。
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vi opt;
        //枚举 (i,j) 作为菱形最下角
        REP(i,m)REP(j,n){
            //边长最大不能让左角出界，不能让右角出界，也不能让最上角出界
            int limit=min({i/2+1,j+1,n-j});
            FOR(k,1,limit+1){
                int sum=grid[i][j];
                if(k>1){
                    int topi=i-k*2+2;
                    //加上最上角
                    sum+=grid[topi][j];
                    //从最下角，水平上升，每一行要加两个数
                    FOR(d,1,k){
                        sum+=grid[i-d][j-d]+grid[i-d][j+d];
                    }
                    //从最上角，水平下降，每一行也要加两个数
                    FOR(d,1,k-1){
                        sum+=grid[topi+d][j-d]+grid[topi+d][j+d];
                    }
                }
                opt.pb(sum);
            }
        }
        //排序，去重，只要最大的三个
        sort(ALLR(opt));
        opt.resize(unique(ALL(opt))-opt.begin());
        if(opt.size()>3)opt.resize(3);
        return opt;
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
