#include "SegTree.h"
#include "utils.h"

SegTree<int>T(100000,[](int x,int y){return x+y;});
class MedianFinder {
public:
    MedianFinder() {
        T.set(0);
    }
    void addNum(int num) {
        T.step_forward(num+5);
    }
    double findMedian() {
        if(T.data[1]%2){
            return T.find_nth(T.data[1]/2)-5;
        }
        else{
            return (T.find_nth(T.data[1]/2-1)+T.find_nth(T.data[1]/2))/2.0-5;
        }
    }
};

int main()
{
    cout<<boolalpha;

	MedianFinder*obj=new MedianFinder();
	obj->addNum(1);
	obj->addNum(2);
	obj->findMedian();
	obj->addNum(3);
	obj->findMedian();

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