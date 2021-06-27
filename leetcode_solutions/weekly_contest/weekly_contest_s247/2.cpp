#include "utils.h"

class Solution {
    struct node{
        int i,j,val;
        node(int _i,int _j,int _val):i(_i),j(_j),val(_val){}
    };
public:
    //按照从外到内的顺序，一环一环地处理
    //对于每个环，把所有行号/列号/值取出来，行号/列号保持不动，只让值进行循环轮转
    //转完之后，按照 行号/列号/新的值 的对应关系填充矩阵
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int K) {
        int m=grid.size();
        int n=grid[0].size();
        for(int r1=0,r2=m-1,c1=0,c2=n-1;r1<r2&&c1<c2;r1++,r2--,c1++,c2--){
            vector<node>v;
            for(int j=c1;j<=c2;j++)v.emplace_back(r1,j,grid[r1][j]);
            for(int i=r1+1;i<r2;i++)v.emplace_back(i,c2,grid[i][c2]);
            for(int j=c2;j>=c1;j--)v.emplace_back(r2,j,grid[r2][j]);
            for(int i=r2-1;i>r1;i--)v.emplace_back(i,c1,grid[i][c1]);
            int k=K%v.size();
            while(k--){
                int t=v[0].val;
                for(int i=0;i+1<v.size();i++){
                    v[i].val=v[i+1].val;
                }
                v.back().val=t;
            }
            for(auto [i,j,val]:v){
                grid[i][j]=val;
            }
        }
        return grid;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi grid=makevvi("[[40,10],[30,20]]");
    int k=1;
    auto ans=sol.rotateGrid(grid,k);
    DBGVV(ans);

    system("pause");
    return 0;
}
