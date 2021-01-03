#include "utils.h"

class RandomizedCollection {
    unordered_multimap<int,int>M;
    vector<int>v;
public:
    RandomizedCollection() {}
    bool insert(int val) {
        M.insert(make_pair(val,v.size()));
        v.pb(val);
        return M.count(val)>1;
    }
    bool remove(int val) {
        auto find=M.find(val);
        if(find!=M.end()){
            if(find->second!=v.size()-1){
                swap(v[find->second],v[v.size()-1]);
                auto find2=M.find(v[find->second]);
                while(find2->second!=v.size()-1)++find2;
                M.erase(find2);
                M.insert(make_pair(v[find->second],find->second));
            }
            M.erase(find);
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

    RandomizedCollection*obj=new RandomizedCollection();
	obj->insert(1);
	obj->insert(1);
	obj->insert(2);
	obj->getRandom();
	obj->remove(1);
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