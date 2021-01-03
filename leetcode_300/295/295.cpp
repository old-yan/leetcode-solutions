#include "utils.h"

class MedianFinder {
    multiset<int>S1,S2;
public:
    MedianFinder() {}
    void addNum(int num) {
        if(S1.size()>=S2.size()){
            S1.insert(num);
            S2.insert(*S1.rbegin());
            S1.erase(S1.find(*S1.rbegin()));
        }
        else{
            S2.insert(num);
            S1.insert(*S2.begin());
            S2.erase(S2.begin());
        }
    }
    double findMedian() {
        if(S1.size()==S2.size()){
            return ((double)*S1.rbegin()+*S2.begin())/2;
        }
        else if(S1.size()>S2.size())return *S1.rbegin();
        else return *S2.begin();
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