#include "utils.h"

class ThroneInheritance {
    vector<string>namelist;
    unordered_map<string,int>idmap;
    bool islive[100001]={0};
    int parent[100001];
    vi sons[100001];
    int count;
public:
    ThroneInheritance(string kingName){
        namelist.pb(kingName);
        islive[0]=true;
        idmap[kingName]=idmap.size();
        count=1;
    }
    void birth(string parentName, string childName) {
        int p=idmap[parentName];
        int c=idmap[childName]=idmap.size();
        namelist.pb(childName);
        islive[c]=true;
        parent[c]=p;
        sons[p].pb(c);
        count++;
    }
    void death(string name) {
        islive[idmap[name]]=false;
        count--;
    }
    void traverse(int x,vector<string>&cur){
        if(islive[x])cur.emplace_back(namelist[x]);
        if(sons[x].size()){
            for(auto&s:sons[x]){
                traverse(s,cur);
            }
        }
    }
    vector<string> getInheritanceOrder() {
        vector<string>ans;
        ans.reserve(count);
        traverse(0,ans);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;

	ThroneInheritance*obj=new ThroneInheritance("king");
	obj->birth("king","andy");
	obj->birth("king","bob");
	obj->birth("king","catherine");
	obj->birth("andy","matthew");
	obj->birth("bob","alex");
	obj->birth("bob","asha");
	obj->getInheritanceOrder();
	obj->death("bob");
	obj->getInheritanceOrder();

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