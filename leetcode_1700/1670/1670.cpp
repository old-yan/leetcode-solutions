#include "utils.h"

class FrontMiddleBackQueue {
    deque<int>Q;
public:
    FrontMiddleBackQueue() {}
    void pushFront(int val) {
        Q.push_front(val);
    }
    void pushMiddle(int val) {
        Q.insert(Q.begin()+Q.size()/2,val);
    }
    void pushBack(int val) {
        Q.pb(val);
    }
    int popFront() {
        if(Q.empty())return -1;
        int ans=Q.front();
        Q.pop_front();
        return ans;
    }
    int popMiddle() {
        if(Q.empty())return -1;
        int ans=Q[(Q.size()-1)/2];
        Q.erase(Q.begin()+(Q.size()-1)/2);
        return ans;
    }
    int popBack() {
        if(Q.empty())return -1;
        int ans=Q.back();
        Q.pop_back();
        return ans;
    }
};

int main()
{
    cout<<boolalpha;

	FrontMiddleBackQueue*obj=new FrontMiddleBackQueue();
	obj->pushFront(1);
	obj->pushBack(2);
	obj->pushMiddle(3);
	obj->pushMiddle(4);
	obj->popFront();
	obj->popMiddle();
	obj->popMiddle();
	obj->popBack();
	obj->popFront();

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