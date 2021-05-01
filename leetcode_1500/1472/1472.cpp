#include "utils.h"

class BrowserHistory {
    string cache[5000];
    int len,cur;
public:
    BrowserHistory(string homepage):len(0),cur(0) {
        visit(homepage);
    }
    void visit(string url) {
        cache[cur++]=url;
        len=cur;
    }
    string back(int steps) {
        cur=max(1,cur-steps);
        return cache[cur-1];
    }
    string forward(int steps) {
        cur=min(len,cur+steps);
        return cache[cur-1];
    }
};

int main()
{
    cout<<boolalpha;

	BrowserHistory*obj=new BrowserHistory("leetcode.com");
	obj->visit("google.com");
	obj->visit("facebook.com");
	obj->visit("youtube.com");
	obj->back(1);
	obj->back(1);
	obj->forward(1);
	obj->visit("linkedin.com");
	obj->forward(2);
	obj->back(2);
	obj->back(7);

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