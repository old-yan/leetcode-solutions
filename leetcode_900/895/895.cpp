#include "Heap.h"
#include "utils.h"

class FreqStack {
    struct node{
        int val;
        vi timeStamps;
        node(){}
        node(int _val,int _timeStamp):val(_val),timeStamps({_timeStamp}){
            cout<<"hello";
        }
        bool operator<(const node&other)const{
            if(timeStamps.size()!=other.timeStamps.size())return timeStamps.size()<other.timeStamps.size();
            return timeStamps.size()&&timeStamps.back()<other.timeStamps.back();
        }
    };
    unordered_map<int,node>M;
    Heap<int>H;
    int timer;
public:
    FreqStack():timer(0),H([&](int x,int y){return M[x]<M[y];}) {}
    void push(int val) {
        if(M.count(val)){
            M[val].timeStamps.pb(timer++);
            H.push(val);
        }
        else{
            M[val]=node(val,timer++);
            H.push(val);
        }
    }
    int pop() {
        auto p=H.top();
        nodes[p].timeStamps.pop_back();
        H.sink(p);
        return nodes[p].val;
    }
};

int main()
{
    cout<<boolalpha;

	FreqStack*obj=new FreqStack();
	obj->push(4);
	obj->push(0);
	obj->push(9);
	obj->push(3);
	obj->push(4);
	obj->push(2);
	obj->pop();
	obj->push(6);
	obj->pop();
	obj->push(1);
	obj->pop();
	obj->push(1);
	obj->pop();
	obj->push(4);
	obj->pop();
	obj->pop();
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