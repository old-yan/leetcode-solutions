#include "utils.h"

set<int>work,busy;
struct mystack{
    stack<int>*obj=nullptr;
    void push(int val){
        if(!obj)obj=new stack<int>();
        obj->push(val);
    }
    int pop(){
        int val=obj->top();
        obj->pop();
        return val;
    }
    bool empty(){
        return !obj||obj->empty();
    }
    size_t size(){
        if(!obj)return 0;
        else return obj->size();
    }
    void clear(){
        if(obj)stack<int>().swap(*obj);
    }
}S[100000];
class DinnerPlates {
    priority_queue<int,vector<int>,greater<int>>idle;
    int capacity;
public:
    DinnerPlates(int _capacity):capacity(_capacity) {
        idle.push(0);
        for(int i:work){
            S[i].clear();
        }
        set<int>().swap(work);
        for(int i:busy){
            S[i].clear();
        }
        set<int>().swap(busy);
    }
    void push(int val) {
        int index;
        if(work.empty()||idle.top()<*work.begin()){
            index=idle.top();
            idle.pop();
            if(idle.empty())idle.push(index+1);
            work.insert(index);
        }
        else index=*work.begin();
        S[index].push(val);
        if(S[index].size()==capacity){
            work.erase(index);
            busy.insert(index);
        }
    }
    int pop() {
        if(work.empty()&&busy.empty())return -1;
        int index;
        if(busy.size()&&(work.empty()||*work.rbegin()<*busy.rbegin())){
            index=*busy.rbegin();
            busy.erase(index);
            work.insert(index);
        }
        else index=*work.rbegin();
        int val=S[index].pop();
        if(S[index].empty()){
            work.erase(index);
            idle.push(index);
        }
        return val;
    }
    int popAtStack(int index) {
        if(S[index].empty())return -1;
        int val=S[index].pop();
        if(S[index].empty()){
            if(capacity==1)busy.erase(index);
            else work.erase(index);
            idle.push(index);
        }
        else if(S[index].size()==capacity-1){
            busy.erase(index);
            work.insert(index);
        }
        return val;
    }
};

int main()
{
    cout<<boolalpha;

	DinnerPlates*obj=new DinnerPlates(2);
	obj->push(1);
	obj->push(2);
	obj->push(3);
	obj->push(4);
	obj->push(5);
	obj->popAtStack(0);
	obj->push(20);
	obj->push(21);
	obj->popAtStack(0);
	obj->popAtStack(2);
	obj->pop();
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