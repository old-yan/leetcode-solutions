#include "utils.h"

//typedef DynamicTrie SOMETRIE;
typedef StaticTrie SOMETRIE;
//动态Trie树和静态Trie树，继承两者其一即可
//为什么必须要重写虚函数：因为调用的时候是值传参，而父类中都是引用传参

class Trie:public SOMETRIE{
public:
	virtual void insert(string word){
		SOMETRIE::insert(word);
	}
    virtual bool search(string word){
        return SOMETRIE::search(word)>=0;
    }
	virtual bool startsWith(string word){
        return SOMETRIE::startsWith(word);
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