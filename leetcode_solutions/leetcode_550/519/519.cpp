#include "utils.h"

class Solution {
    int row,col;
    unordered_map<int,int>M;
    int rest;
public:
    Solution(int n_rows, int n_cols):row(n_rows),col(n_cols),rest(n_rows*n_cols){}
    vector<int> flip() {
        int n=rand()%rest--;
        int res;
        if(M.count(n)){
            res=M[n];
        }
        else{
            res=n;
        }
        M[n]=M.count(rest)?M[rest]:rest;
        return {res/col,res%col};
    }
    void reset() {
        M.clear();
        rest=row*col;
    }
};

int main()
{
    cout<<boolalpha;

    Solution*obj=new Solution(2,2);
	DBGV(obj->flip());
	DBGV(obj->flip());
    DBGV(obj->flip());
    DBGV(obj->flip());

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