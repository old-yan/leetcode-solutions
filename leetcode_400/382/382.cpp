#include "utils.h"

class Solution {
    ListNode*head;
public:
    Solution(ListNode*_head):head(_head) {}
    int getRandom() {
        int count=0;
        ListNode*node;
        for(auto p=head;p;p=p->next){
            count++;
            if(rand()%count==0)node=p;
        }
        return node->val;
    }
};

int main()
{
    cout<<boolalpha;

    Solution*obj=new Solution(makelistnode({1,2,3}));
	obj->getRandom();
	obj->getRandom();
	obj->getRandom();
	obj->getRandom();
	obj->getRandom();

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