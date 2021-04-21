#include "utils.h"

class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int ans=0;
        int Left[m][n],Up[m][n];
        memset(Left,0,sizeof(Left));
        REP(i,m){
            REP(j,n){
                if(grid[i][j])Left[i][j]=j?Left[i][j-1]+1:1;
            }
        }
        memset(Up,0,sizeof(Up));
        REP(i,m){
            REPR(j,n-1){
                if(grid[i][j])Up[i][j]=i?Up[i-1][j]+1:1;
            }
        }
        REP(i,m){
            REP(j,n){
                for(int ii=i,jj=j,k=1;ii>=0&&jj>=0;ii--,jj--){
                    if(Left[i][j]>=k&&Up[i][j]>=k&&Left[ii][j]>=k&&Up[i][jj]>=k){
                        chmax(ans,k*k);
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi grid=makevvi("[[1,1,1],[1,0,1],[1,1,1]]");
    auto ans=sol.largest1BorderedSquare(grid);
    DBG(ans);

    system("pause");
    return 0;
}
