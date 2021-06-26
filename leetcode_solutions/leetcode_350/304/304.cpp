#include "utils.h"

class NumMatrix {
    vvi sum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        sum=matrix;
        REP(i,m){
            REP(j,n){
                if(j)sum[i][j]+=sum[i][j-1];
                if(i)sum[i][j]+=sum[i-1][j];
                if(i&&j)sum[i][j]-=sum[i-1][j-1];
            }
        }
    }
    #define a(i,j) (i>=0&&j>=0?sum[i][j]:0)
    int sumRegion(int row1, int col1, int row2, int col2) {
        return a(row2,col2)+a(row1-1,col1-1)-a(row1-1,col2)-a(row2,col1-1);
    }
};

int main()
{
    cout<<boolalpha;

    vvi matrix{
        {3,0,1,4,2},
        {5,6,3,2,1},
        {1,2,0,1,5},
        {4,1,0,1,7},
        {1,0,3,0,5}
    };
    NumMatrix*obj=new NumMatrix(matrix);
	DBG(obj->sumRegion(2,1,4,3));
	DBG(obj->sumRegion(1,1,2,2));
	DBG(obj->sumRegion(1,2,2,4));

    system("pause");
    return 0;
}
/*
使用如下正则替换将leetcode测试用例转换为代码
首先将leetcode测试样例复制到代码正文中，把换行符删除，两行合并为一行;
将如下替换使用一次(也可以自己手打)：

\["(.+?)"(.*?)\]\[\[(.*?)\](.*)\]
\t$1*obj=new $1($3);\n[$2][$4]

将如下替换连续使用：

\[,"(.+?)"(.*?)\]\[,\[(.*?)\](.*)\]
\tobj->$1($3);\n[$2][$4]

*/