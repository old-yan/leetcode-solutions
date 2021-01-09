#include "utils.h"

class NumMatrix {
    vvi sum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        if(!m)return;
        int n=matrix[0].size();
        sum=matrix;
        REP(i,m){
            REP(j,n){
                if(j)sum[i][j]+=sum[i][j-1];
                if(i)sum[i][j]+=sum[i-1][j];
                if(i&&j)sum[i][j]-=sum[i-1][j-1];
            }
        }
        DBGVV(sum);
    }
    #define a(i,j) (i>=0&&j>=0?sum[i][j]:0)
    int sumRegion(int row1, int col1, int row2, int col2) {
        return a(row2,col2)+a(row1-1,col1-1)-a(row1-1,col2)-a(row2,col1-1);
    }
};

class Solution {
    #define Node QuadTree//提交时注释本行
    int n;
    vvi grid;
    Node*fun(NumMatrix&NM,int i1,int i2,int j1,int j2){
        int sum=NM.sumRegion(i1,j1,i2-1,j2-1);
        if(sum==(i2-i1)*(j2-j1)){
            return new Node(1,true);
        }
        else if(!sum){
            return new Node(0,true);
        }
        else{
            return new Node(0,false,fun(NM,i1,(i1+i2)/2,j1,(j1+j2)/2),fun(NM,i1,(i1+i2)/2,(j1+j2)/2,j2),fun(NM,(i1+i2)/2,i2,j1,(j1+j2)/2),fun(NM,(i1+i2)/2,i2,(j1+j2)/2,j2));
        }
    }
public:
    Node* construct(vector<vector<int>>&_grid) {
        grid=_grid;
        n=grid.size();
        NumMatrix NM(grid);
        return fun(NM,0,n,0,n);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi grid{
        {1,1,1,1,0,0,0,0},
        {1,1,1,1,0,0,0,0},
        {1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1},
        {1,1,1,1,0,0,0,0},
        {1,1,1,1,0,0,0,0},
        {1,1,1,1,0,0,0,0},
        {1,1,1,1,0,0,0,0}
    };
    auto ans=sol.construct(grid);
    cout<<ans;

    system("pause");
    return 0;
}
