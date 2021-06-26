#include "utils.h"

class RandomizedSet {
    unordered_map<int,int>M;
    vector<int>v;
public:
    RandomizedSet() {}
    bool insert(int val) {
        if(!M.count(val)){
            M[val]=v.size();
            v.pb(val);
            return true;
        }
        else return false;
    }
    bool remove(int val) {
        if(M.count(val)){
            if(M[val]!=v.size()-1){
                swap(v[M[val]],v[v.size()-1]);
                M[v[M[val]]]=M[val];
            }
            M.erase(val);
            v.pop_back();
            return true;
        }
        else return false;
    }
    int getRandom() {
        return v[rand()%v.size()];
    }
};

int main()
{
    cout<<boolalpha;

    RandomizedSet*obj=new RandomizedSet();
	obj->insert(1);
	obj->remove(2);
	obj->insert(2);
	obj->getRandom();
	obj->remove(1);
	obj->insert(2);
	obj->getRandom();

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