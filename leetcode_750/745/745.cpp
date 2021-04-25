#include "Trie.h"
#include "utils.h"

class mytrie:public StaticTrie{
    int res;
public:
    mytrie():StaticTrie(){}
    void insert(const string&word,int val){
        int cur=0;
        for(int i=0;i<word.size();i++){
            data[cur][27]=val;
            data[cur][28]|=(1<<int(word.size()-i));
            if(!data[cur][word[i]-'a'])Malloc(data[cur][word[i]-'a']);
            cur=data[cur][word[i]-'a'];
        }
        data[cur][26]=data[cur][27]=val;
        data[cur][28]=1;
    }
    void fun(int cur,string&prefix,int i,string&suffix,int j){
        if((*this)[cur][27]<=res)return;
        if(!((*this)[cur][28]>>(suffix.size()-j)))return;
        if(j&&!((*this)[cur][28]&(1<<(suffix.size()-j))))return;
        if(prefix[i]){
            int next=(*this)[cur][prefix[i]-'a'];
            if(!next)return;
            if(prefix[i]==suffix[j]&&suffix.size()+i>=prefix.size()){
                fun(next,prefix,i+1,suffix,j+1);
            }
            if(!j)fun(next,prefix,i+1,suffix,0);
        }
        else{
            if(!suffix[j])chmax(res,(*this)[cur][26]);
            REP(k,26){
                int next=(*this)[cur][k];
                if(next){
                    if(k==suffix[j]-'a')fun(next,prefix,i,suffix,j+1);
                    fun(next,prefix,i,suffix,0);
                }
            }
        }
    }
    int find(string&prefix,string&suffix){
        res=-1;
        fun(0,prefix,0,suffix,0);
        return res;
    }
};

mytrie T;
class WordFilter {
public:
    WordFilter(vector<string>& words) {
        T.clear();
        REP(i,words.size()){
            T.insert(words[i],i);
        }
    }
    int f(string prefix, string suffix) {
        return T.find(prefix,suffix);
    }
};

int main()
{
    cout<<boolalpha;

    vector<string>words{"cabaabaaaa","ccbcababac","bacaabccba","bcbbcbacaa","abcaccbcaa","accabaccaa","cabcbbbcca","ababccabcb","caccbbcbab","bccbacbcba"};
	WordFilter*obj=new WordFilter(words);
	DBG(obj->f("bccbacbcba","a"));
	DBG(obj->f("ab","abcaccbcaa"));
	DBG(obj->f("a","aa"));
	DBG(obj->f("cabaaba","abaaaa"));
	DBG(obj->f("cacc","accbbcbab"));
	DBG(obj->f("ccbcab","bac"));
	DBG(obj->f("bac","cba"));
	DBG(obj->f("ac","accabaccaa"));
	DBG(obj->f("bcbb","aa"));
	DBG(obj->f("ccbca","cbcababac"));

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