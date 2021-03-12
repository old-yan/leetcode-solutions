#include "utils.h"

class Solution {
    bool check(int i,int j,vvi&grid){
        bitset<10>b;
        int row[3]={0},col[3]={0},xie[2]={0};
        FOR(ii,i,i+3){
            FOR(jj,j,j+3){
                if(grid[ii][jj]<1||grid[ii][jj]>9||b[grid[ii][jj]])return false;
                b.set(grid[ii][jj]);
                row[ii-i]+=grid[ii][jj];
                col[jj-j]+=grid[ii][jj];
                if(ii-i==jj-j){
                    xie[0]+=grid[ii][jj];
                }
                if(ii-i+jj-j==2){
                    xie[1]+=grid[ii][jj];
                }
            }
        }
        REP(i,3)if(row[i]!=15)return false;
        REP(i,3)if(col[i]!=15)return false;
        REP(i,2)if(xie[i]!=15)return false;
        return true;
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        if(m<3||n<3)return 0;
        int ans=0;
        REP(i,m-2){
            REP(j,n-2){
                if(check(i,j,grid))ans++;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi grid=makevvi("[[4,3,8,4],[9,5,1,9],[2,7,6,2]]");
    auto ans=sol.numMagicSquaresInside(grid);
    DBG(ans);

    system("pause");
    return 0;
}
