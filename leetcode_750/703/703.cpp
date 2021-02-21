#include "utils.h"

class KthLargest {
    priority_queue<int,vi,greater<int>>Q;
    int k;
public:
    KthLargest(int _k, vector<int>& nums):k(_k) {
        for(int a:nums){
            Q.push(a);
            if(Q.size()>k)Q.pop();
        }
    }
    int add(int val) {
        Q.push(val);
        if(Q.size()>k)Q.pop();
        return Q.top();
    }
};

int main()
{
    cout<<boolalpha;

    vi nums{4,5,8,2};
	KthLargest*obj=new KthLargest(3,nums);
	obj->add(3);
	obj->add(5);
	obj->add(10);
	obj->add(9);
	obj->add(4);

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