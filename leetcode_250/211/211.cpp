#include "utils.h"

class WordDictionary{
    WordDictionary*child[27];
public:
    WordDictionary(){
        memset(child,0,sizeof(child));
    }
    void addWord(string word) {
        auto p=this;
        REP(i,word.size()){
            if(!p->child[word[i]-'a']){
                p->child[word[i]-'a']=new WordDictionary;
            }
            p=p->child[word[i]-'a'];
        }
        p->child[26]=(WordDictionary*)1;
    }
    bool fun(string&word,int idx){
        if(idx==word.size()){
            return child[26];
        }
        else{
            if(word[idx]=='.'){
                REP(i,26){
                    if(child[i]&&child[i]->fun(word,idx+1))return true;
                }
                return false;
            }
            else{
                return child[word[idx]-'a']&&child[word[idx]-'a']->fun(word,idx+1);
            }
        }
    }
    bool search(string word) {
        return fun(word,0);
    }
};

int main()
{
    cout<<boolalpha;

    WordDictionary*obj=new WordDictionary();
	obj->addWord("bad");
	obj->addWord("dad");
	obj->addWord("mad");
	obj->search("pad");
	obj->search("bad");
	obj->search(".ad");
	obj->search("b..");

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