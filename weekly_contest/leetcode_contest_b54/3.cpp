#include "utils.h"

class Solution {
public:
    //直接模拟的时间复杂度，比赛时没算，估计是可以过的。比赛后算了一下最大时间复杂度，虽然是k的6次方，但是常数比较小，最终是在千万量级
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        //r1,r2为最上行，最下行的行号
        //c1,c2为最左列，最右列的列号
        auto check=[&](int r1,int r2,int c1,int c2){
            int sum=-1;
            //检查行
            FOR(i,r1,r2+1){
                int cnt=0;
                FOR(j,c1,c2+1)cnt+=grid[i][j];
                if(sum<0)sum=cnt;
                if(cnt!=sum)return false;
            }
            //检查列
            FOR(j,c1,c2+1){
                int cnt=0;
                FOR(i,r1,r2+1)cnt+=grid[i][j];
                if(cnt!=sum)return false;
            }
            //检查左上-右下对角
            {
                int cnt=0;
                FOR(i,r1,r2+1){
                    cnt+=grid[i][c1+(i-r1)];
                }
                if(cnt!=sum)return false;
            }
            //检查右上-左下对角
            {
                int cnt=0;
                FOR(j,c1,c2+1){
                    cnt+=grid[r2-(j-c1)][j];
                }
                if(cnt!=sum)return false;
            }
            return true;
        };
        for(int k=min(m,n);k>1;k--){
            for(int i=0;i+k<=m;i++){
                for(int j=0;j+k<=n;j++){
                    if(check(i,i+k-1,j,j+k-1)){
                        return k;
                    }
                }
            }
        }
        return 1;
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
