#include "utils.h"

class Operations {
public:
    Operations() {}
    int minus(int a, int b) {
        return a-b;
    }
    int multiply(int a, int b) {
        return a*b;
    }
    int divide(int a, int b) {
        return a/b;
    }
};

int main()
{
    cout<<boolalpha;

	Operations*obj=new Operations();
	obj->minus(0,-2147483647);
	obj->minus(-1,2147483647);
	obj->multiply(-1,-2147483647);
	obj->multiply(-100,21474836);
	obj->divide(2147483647,-1);
	obj->divide(-2147483648,1);

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