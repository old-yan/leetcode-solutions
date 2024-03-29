#include "Trie.h"
#include "utils.h"

//继承静态Trie树
//为什么必须要重写虚函数：因为模板里的Trie的search方法返回的是int类型
class Trie:public StaticTrie{
public:
    bool search(const string&word){
        return StaticTrie::search(word)>=0;
    }
    bool startsWith(const string&prefix){
        int cur=0;
        for(char c:prefix){
            if(!data[cur][c-'a'])return false;
            cur=data[cur][c-'a'];
        }
        return true;
    }
};

int main()
{
    cout<<boolalpha;

    Trie*obj=new Trie();
	obj->insert("apple");
	DBG(obj->search("apple"));
	DBG(obj->search("app"));
	DBG(obj->startsWith("app"));
	obj->insert("app");
	DBG(obj->search("app"));

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