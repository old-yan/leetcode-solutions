#include "utils.h"

class StockSpanner {
    stack<pair<int,int>>S;
    int idx;
public:
    StockSpanner():idx(1) {
        S.emplace(100001,0);
    }
    int next(int price) {
        while(S.top().first<=price)S.pop();
        int ans=idx-S.top().second;
        S.emplace(price,idx++);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;

	StockSpanner*obj=new StockSpanner();
	obj->next(100);
	obj->next(80);
	obj->next(60);
	obj->next(70);
	obj->next(60);
	obj->next(75);
	obj->next(85);

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