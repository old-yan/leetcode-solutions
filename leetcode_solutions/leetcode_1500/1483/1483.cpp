#include "utils.h"

int _dp[50001][16];
auto dp=[](){
    fill(_dp[0],_dp[1],-1);
    return _dp+1;
}();
class TreeAncestor {
    int n,level;
public:
    TreeAncestor(int _n, vector<int>& parent):n(_n) {
        for(level=17;(1<<level)>=n;level--);
        REP(i,level+1){
            REP(j,n){
                dp[j][i]=i?dp[dp[j][i-1]][i-1]:parent[j];
            }
        }
    }
    int getKthAncestor(int node, int k) {
        if(k>=n)return -1;
        while(k){
            node=dp[node][__builtin_ctz(k)];
            k-=k&(-k);
        }
        return node;
    }
};


int main()
{
    cout<<boolalpha;

    vi parent{-1,0,0,1,1,2,2};
	TreeAncestor*obj=new TreeAncestor(7,parent);
	obj->getKthAncestor(3,1);
	obj->getKthAncestor(5,2);
	obj->getKthAncestor(6,3);

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