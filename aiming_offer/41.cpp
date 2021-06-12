#include "SegTree.h"
#include "utils.h"

class MedianFinder {
    priority_queue<int>minQ;
    priority_queue<int,vi,greater<int>>maxQ;
public:
    MedianFinder(){}
    void addNum(int num) {
        if(minQ.size()<=maxQ.size()){
            maxQ.push(num);
            minQ.push(maxQ.top());
            maxQ.pop();
        }
        else{
            minQ.push(num);
            maxQ.push(minQ.top());
            minQ.pop();
        }
    }
    double findMedian() {
        if(minQ.size()==maxQ.size()){
            return (maxQ.top()+minQ.top())/2.0;
        }
        else{
            return minQ.top();
        }
    }
};

int main()
{
    cout<<boolalpha;

    MedianFinder*obj=new MedianFinder();
	obj->addNum(1);
	obj->addNum(2);
	DBG(obj->findMedian());
	obj->addNum(3);
	DBG(obj->findMedian());

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