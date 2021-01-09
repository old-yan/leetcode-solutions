#include "utils.h"

class NestedIterator {
    stack<const NestedInteger*>S;
public:
    NestedIterator(const vector<NestedInteger>&nestedList){
        for(auto it=nestedList.rbegin();it!=nestedList.rend();++it){
            S.push(&(*it));
        }
    }
    int next() {
        while(S.size()&&!S.top()->isInteger()){
            auto p=S.top();
            S.pop();
            for(auto it=p->getList().rbegin();it!=p->getList().rend();++it){
                S.push(&(*it));
            }
        }
        int res=S.top()->getInteger();
        S.pop();
        return res;
    }
    bool hasNext() {
        while(S.size()&&!S.top()->isInteger()){
            auto p=S.top();
            S.pop();
            for(auto it=p->getList().rbegin();it!=p->getList().rend();++it){
                S.emplace(&(*it));
            }
        }
        return S.size();
    }
};

int main()
{
    cout<<boolalpha;

    NestedInteger ni=makenestedinteger("[1,[4,[6]]]").getList();
    DBG(ni);
    NestedIterator*obj=new NestedIterator(ni.getList());
    while(obj->hasNext()){
        DBG(obj->next());
    }

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