#include "utils.h"

class Solution {
    int N;
    vi&blacklist;
public:
    Solution(int _N, vector<int>&_blacklist):N(_N),blacklist(_blacklist){
        sort(ALL(blacklist));
    }
    int pick() {
        int a=rand()%(N-blacklist.size())+1;
        int low=0,high=blacklist.size();
        while(low<high){
            int mid=(low+high)/2;
            if(blacklist[mid]-mid>=a)high=mid;
            else low=mid+1;
        }
        return low+a-1;
    }
};

int main()
{
    cout<<boolalpha;

    vi blacklist{2};
    Solution*obj=new Solution(4,blacklist);
    DBG(obj->pick());
    DBG(obj->pick());
    DBG(obj->pick());
    DBG(obj->pick());
    DBG(obj->pick());
    DBG(obj->pick());
    DBG(obj->pick());

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