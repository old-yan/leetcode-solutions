#include "Trie.h"
#include "utils.h"

//静态Trie树方便继承修改
//提交时记得TRIEN修改为30
class mytrie:public StaticTrie{
public:
    mytrie():StaticTrie(){}
    int insert(int cur,const string&word,int i,int val) {
        int res=0;
        if(i==word.size()){
            if((*this)[cur][26]<0){
                (*this)[cur][26]=1;
            }
            res=val-(*this)[cur][28];
            (*this)[cur][28]+=res;
        }
        else{
            if(!(*this)[cur][word[i]-'a']){
                Malloc((*this)[cur][word[i]-'a']);
            }
            res=insert((*this)[cur][word[i]-'a'],word,i+1,val);
        }
        (*this)[cur][29]+=res;
        return res;
    }
    void insert(const string&word,int val) {
        insert(0,word,0,val);
    }
};

mytrie T;
class MapSum {
public:
    MapSum(){
        T.clear();
    }
    void insert(string key, int val) {
        T.insert(key,val);
    }
    int sum(string prefix) {
        int cur=0;
        for(char c:prefix){
            if(!T[cur][29])return 0;
            if(!(cur=T[cur][c-'a']))return 0;
        }
        return T[cur][29];
    }
};

int main()
{
    cout<<boolalpha;

	MapSum*obj=new MapSum();
	obj->insert("a",3);
	//obj->sum("ap");
	obj->insert("b",2);
	DBG(obj->sum("a"));

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