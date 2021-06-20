#include "utils.h"

class WordsFrequency {
    unordered_map<string,int>M;
public:
    WordsFrequency(vector<string>& book) {
        for(auto&s:book){
            M[s]++;
        }
    }
    int get(string word) {
        return M[word];
    }
};

int main()
{
    cout<<boolalpha;

    vector<string>book{"i","have","an","apple","he","have","a","pen"};
	WordsFrequency*obj=new WordsFrequency(book);
	obj->get("you");
	obj->get("have");
	obj->get("an");
	obj->get("apple");
	obj->get("pen");

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