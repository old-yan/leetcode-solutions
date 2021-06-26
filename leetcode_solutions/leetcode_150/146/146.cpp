#include "utils.h"

class LRUCache {
    struct node{
        int key,value;
        node*prev,*next;
        node():prev(nullptr),next(nullptr){}
    };
    int capacity;
    node*head;
    node*tail;
    unordered_map<int,node*>M;
public:
    LRUCache(int _capacity):capacity(_capacity) {
        head=new node;
        tail=new node;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        int get_res;
        if(M.count(key)){
            node*p=M[key];
            p->prev->next=p->next;
            p->next->prev=p->prev;
            p->prev=head;
            p->next=head->next;
            head->next->prev=p;
            head->next=p;
            get_res=p->value;
        }
        else{
            get_res=-1;
        }
        DBG(get_res);
        return get_res;
    }
    
    void put(int key, int value) {
        if(M.count(key)){
            node*p=M[key];
            p->value=value;
            p->prev->next=p->next;
            p->next->prev=p->prev;
            p->prev=head;
            p->next=head->next;
            head->next->prev=p;
            head->next=p;
        }
        else{
            if(M.size()==capacity){
                node*p=tail->prev;
                p->prev->next=tail;
                p->next->prev=p->prev;
                M.erase(p->key);
                delete p;
            }
            node*p=new node;
            p->key=key,p->value=value;
            p->prev=head;
            p->next=head->next;
            head->next->prev=p;
            head->next=p;
            M[key]=p;
        }
    }
};

int main()
{
    cout<<boolalpha;

    LRUCache*obj=new LRUCache(2);
	obj->put(1,1);
	obj->put(2,2);
	obj->get(1);
	obj->put(3,3);
	obj->get(2);
	obj->put(4,4);
	obj->get(1);
	obj->get(3);
	obj->get(4);

    system("pause");
    return 0;
}
/*
使用如下正则替换将leetcode测试用例转换为代码
首先将leetcode测试样例复制到代码正文中，把换行符删除，两行合并为一行;
将如下替换使用一次：

\["(.+?)"(.*?)\]\[\[(.*?)\](.*)\]
\t$1*obj=new $1($3);\n[$2][$4]

将如下替换连续使用：

\[,"(.+?)"(.*?)\]\[,\[(.*?)\](.*)\]
\tobj->$1($3);\n[$2][$4]

*/