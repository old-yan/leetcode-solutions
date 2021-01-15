#include "utils.h"

class LFUCache {
    struct DuList;
    struct DuListHead{
        int count;
        DuListHead*prev;
        DuListHead*next;
        DuList*child;
        DuList*tail;
        DuListHead() : count(0),prev(nullptr),next(nullptr),tail(nullptr),child(nullptr){}
        DuListHead(int _count) : count(_count),prev(nullptr),next(nullptr),tail(nullptr),child(nullptr){}
    };
    struct DuList{
        int key;
        int value;
        DuList*prev;
        DuList*next;
        DuListHead*head;
        DuList() : key(0),value(0),prev(nullptr),next(nullptr),head(nullptr){}
        DuList(int _key,int _val) : key(_key),value(_val),prev(nullptr),next(nullptr),head(nullptr){}
    };
    int capacity;
    DuListHead*h,*t;
    DuList*M[10001];
    int used;
public:
    LFUCache(int _capacity):capacity(_capacity) {
        h=new DuListHead(0);
        t=new DuListHead(INT_MAX);
        h->next=t;
        t->prev=h;
        memset(M,0,sizeof(M));
        used=0;
    }
    void addCount(DuList*p,DuListHead*head){
        if(p->prev||p->next||head->count==0){
            if(p->prev){
                p->prev->next=p->next;
                if(p->next)p->next->prev=p->prev;
                else head->tail=p->prev;
            }
            else if(p->next){
                head->child=p->next;
                p->next->prev=nullptr;
            }
            else head->child=head->tail=nullptr;
            if(head->next->count==head->count+1){
                p->prev=head->next->tail;
                p->next=nullptr;
                head->next->tail->next=p;
                head->next->tail=p;
                p->head=head->next;
            }
            else{
                auto q=new DuListHead(head->count+1);
                q->prev=head;
                q->next=head->next;
                head->next->prev=q;
                head->next=q;
                q->child=q->tail=p;
                p->prev=p->next=nullptr;
                p->head=q;
            }
        }
        else{
            if(head->next->count==head->count+1){
                head->prev->next=head->next;
                head->next->prev=head->prev;
                p->prev=head->next->tail;
                p->next=nullptr;
                head->next->tail->next=p;
                head->next->tail=p;
                p->head=head->next;
                delete head;
            }
            else{
                head->count++;
            }
        }
    }
    int get(int key) {
        if(!M[key])return -1;
        auto p=M[key];
        addCount(p,p->head);
        return p->value;
    }
    void put(int key, int value) {
        if(!capacity)return;
        if(M[key]){
            auto p=M[key];
            p->value=value;
            addCount(p,p->head);
        }
        else{
            if(used==capacity){
                auto head=h->next;
                if(head->child==head->tail){
                    auto p=head->child;
                    M[p->key]=nullptr;
                    M[key]=p;
                    p->key=key;
                    p->value=value;
                    head->count=1;
                    return;
                }
                else{
                    auto p=head->child;
                    head->child=p->next;
                    p->next->prev=nullptr;
                    M[p->key]=nullptr;
                    delete p;
                    used--;
                }
            }
            auto p=new DuList(key,value);
            M[key]=p;
            h->child=h->tail=p;
            addCount(p,h);
            used++;
        }
    }
};

int main()
{
    cout<<boolalpha;

    LFUCache*obj=new LFUCache(2);
	obj->put(1,1);
	obj->put(2,2);
	DBG(obj->get(1));
	obj->put(3,3);
	DBG(obj->get(2));
	DBG(obj->get(3));
	obj->put(4,4);
	DBG(obj->get(1));
	DBG(obj->get(3));
	DBG(obj->get(4));

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