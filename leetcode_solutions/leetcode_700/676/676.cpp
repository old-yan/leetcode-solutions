#include "utils.h"

class MagicDictionary {
    vector<string>dictionary;
public:
    MagicDictionary() {
    }
    void buildDict(vector<string>&&_dictionary) {
        dictionary=move(_dictionary);
    }
    bool search(string searchWord) {
        for(string&word:dictionary){
            if(word.size()==searchWord.size()){
                int cnt=0;
                REP(i,word.size()){
                    if(word[i]!=searchWord[i])cnt++;
                }
                if(cnt==1)return true;
            }
        }
        return false;
    }
};

int main()
{
    cout<<boolalpha;

	MagicDictionary*obj=new MagicDictionary();
	obj->buildDict({"hello","leetcode"});
	obj->search("hello");
	obj->search("hhllo");
	obj->search("hell");
	obj->search("leetcoded");

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