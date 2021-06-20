#include "SegTree.h"
#include "utils.h"

SegTree<int>T(50000,[](int x,int y){return x+y;});
class StreamRank {
public:
    StreamRank() {
        T.set(0);
    }
    void track(int x) {
        T.step_forward(x);
    }
    int getRankOfNumber(int x) {
        return T(0,x-1);
    }
};

int main()
{
    cout<<boolalpha;

	StreamRank*obj=new StreamRank();
	obj->getRankOfNumber(1);
	obj->track(0);
	obj->getRankOfNumber(0);

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