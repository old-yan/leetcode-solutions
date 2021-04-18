#include "Trie.h"
#include "utils.h"

class StreamChecker {
    StaticTrie T;
    vector<char>v;
public:
    StreamChecker(vector<string>& words) {
        for(string&s:words){
            reverse(ALL(s));
            T.insert(s);
        }
    }
    bool query(char letter) {
        v.pb(letter);
        int cur=0;
        REPR(i,v.size()-1){
            int nxt=T[cur][v[i]-'a'];
            if(!nxt)return false;
            cur=nxt;
            if(T[cur][26]>=0)return true;
        }
        return false;
    }
};

int main()
{
    cout<<boolalpha;

    vector<string>words{"cd","f","kl"};
	StreamChecker*obj=new StreamChecker(words);
	obj->query('a');
	obj->query('b');
	obj->query('c');
	obj->query('d');
	obj->query('e');
	obj->query('f');
	obj->query('g');
	obj->query('h');
	obj->query('i');
	obj->query('j');
	obj->query('k');
	obj->query('l');

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