#include "utils.h"

class OrderedStream {
    int ptr;
    vector<string>data;
public:
    OrderedStream(int n):ptr(1),data(n+2){}
    vector<string> insert(int idKey, string value) {
        data[idKey]=value;
        vector<string>ans;
        while(data[ptr].size()){
            ans.pb(data[ptr++]);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;

	OrderedStream*obj=new OrderedStream(5);
	obj->insert(3,"ccccc");
	obj->insert(1,"aaaaa");
	obj->insert(2,"bbbbb");
	obj->insert(5,"eeeee");
	obj->insert(4,"ddddd");

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