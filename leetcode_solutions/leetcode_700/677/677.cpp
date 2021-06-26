#include "Trie.h"
#include "utils.h"

//静态Trie树方便继承修改
//提交时记得TRIEN修改为30
class mytrie:public StaticTrie{
public:
    mytrie():StaticTrie(){}
    //下标27表示以其为根的所有结点总权重
    //下标28表示本结点自己的权重
    //公私分明
    void insert(const string&s,int val){
        static stack<int>S;
        int cur=0;
        for(char c:s){
            S.push(cur);
            if(!data[cur][c-'a'])Malloc(data[cur][c-'a']);
            cur=data[cur][c-'a'];
        }
        data[cur][26]=0;
        int inc;
        if(data[cur][26]>=0)inc=val-data[cur][28];
        else inc=val;
        data[cur][27]+=inc;
        data[cur][28]=val;
        while(S.size()){
            data[S.top()][27]+=inc;
            S.pop();
        }
    }
};

mytrie T;
class MapSum {
public:
    MapSum(){
        T.clear();
    }
    void insert(const string&key, int val) {
        T.insert(key,val);
    }
    int sum(const string&prefix) {
        int cur=0;
        for(char c:prefix){
            if(!T[cur][27])return 0;
            cur=T[cur][c-'a'];
            if(!cur)return 0;
        }
        return T[cur][27];
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