#include "DLTree.h"
#include "utils.h"

DLTree<int,1,0>T(1000000000,0,0,[](int x,int y){return x+y;});
class MyCalendar {
public:
    MyCalendar(){
        T.clear();
    }
    bool book(int start, int end) {
        if(T(start,end-1))return false;
        T.step(start,end-1,1);
        return true;
    }
};

int main()
{
    cout<<boolalpha;

	MyCalendar*obj=new MyCalendar();
	obj->book(10,20);
	obj->book(15,25);
	obj->book(20,30);

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