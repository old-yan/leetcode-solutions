#include "utils.h"

class StackOfPlates {
    int cap;
    vector<stack<int>>S;
public:
    StackOfPlates(int _cap):cap(_cap) {}
    void push(int val) {
        if(!cap)return;
        if(S.empty()||S.back().size()==cap){
            S.pb(stack<int>());
        }
        S.back().push(val);
    }
    int pop() {
        if(S.empty())return -1;
        int res=S.back().top();
        S.back().pop();
        if(S.back().empty())S.pop_back();
        return res;
    }
    int popAt(int index) {
        if(index<0||index>=S.size())return -1;
        int res=S[index].top();
        S[index].pop();
        if(S[index].empty())S.erase(S.begin()+index);
        return res;
    }
};

int main()
{
    cout<<boolalpha;

	StackOfPlates*obj=new StackOfPlates(1);
	obj->push(1);
	obj->push(2);
	obj->popAt(1);
	obj->pop();
	obj->pop();

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