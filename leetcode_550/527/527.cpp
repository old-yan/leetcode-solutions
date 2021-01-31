#include "utils.h"

class Solution {
    zkwTree T;
    int total;
public:
    Solution(vector<int>& w):T(w){
        total=T.data[1];
    }
    int pickIndex() {
        return T.find_nth(rand()%total);
    }
};

int main()
{
    cout<<boolalpha;

    vi w{1,3};
    Solution*obj=new Solution(w);
	DBG(obj->pickIndex());
    DBG(obj->pickIndex());
    DBG(obj->pickIndex());
    DBG(obj->pickIndex());
    DBG(obj->pickIndex());
    DBG(obj->pickIndex());
    DBG(obj->pickIndex());
    DBG(obj->pickIndex());
    DBG(obj->pickIndex());
    DBG(obj->pickIndex());

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