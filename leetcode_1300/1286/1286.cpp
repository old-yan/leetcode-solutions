#include "utils.h"

class CombinationIterator {
    string characters;
    int len;
    vi cursor;
    int count;
public:
    CombinationIterator(string _characters, int _combinationLength) :characters(_characters),len(_combinationLength){
        sort(ALL(characters));
        count=combination(characters.size(),len);
    }
    string next() {
        string ans;
        if(cursor.empty()){
            cursor.resize(len);
            iota(ALL(cursor),0);
        }
        else{
            int idx;
            for(idx=len-1;cursor[idx]==idx+characters.size()-len;idx--);
            iota(cursor.begin()+idx,cursor.end(),cursor[idx]+1);
        }
        for(int a:cursor)ans.pb(characters[a]);
        count--;
        return ans;
    }
    bool hasNext() {
        return count>0;
    }
};

int main()
{
    cout<<boolalpha;

    CombinationIterator*obj=new CombinationIterator("abcdef",3);
	obj->next();
	obj->hasNext();
	obj->next();
	obj->hasNext();
	obj->next();
	obj->hasNext();

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