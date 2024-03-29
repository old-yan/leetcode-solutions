#include "DLTree.h"
#include "utils.h"

DLTree<int,1,1>T(1000000000,0,0,[](int x,int y){return x+y;});
class RangeModule {
public:
    RangeModule() {
        T.clear();
    }
    void addRange(int left, int right) {
        T.step(left,right-1,1);
    }
    bool queryRange(int left, int right) {
        return T(left,right-1)==right-left;
    }
    void removeRange(int left, int right) {
        T.step(left,right-1,0);
    }
};

int main()
{
    cout<<boolalpha;

	RangeModule*obj=new RangeModule();
	obj->addRange(10,20);
	obj->removeRange(14,16);
	DBG(obj->queryRange(10,14));
	DBG(obj->queryRange(13,15));
	DBG(obj->queryRange(16,17));

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