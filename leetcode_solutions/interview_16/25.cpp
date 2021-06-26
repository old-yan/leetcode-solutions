#include "utils.h"

class LRUCache {
    int cap;
    DuLinkList*head,*tail;
    unordered_map<int,DuLinkList*>M;
public:
    LRUCache(int capacity) :cap(capacity) {
        head=new DuLinkList;
        tail=new DuLinkList;
        head->next=tail;
        tail->prev=head;
    }
    int get(int key) {
        if(M.count(key)){
            DuLinkList*cur=M[key];
            erase(cur);
            insert(cur,head->next);
            return cur->val;
        }
        else return -1;
    }
    void put(int key, int value) {
        DuLinkList*cur;
        if(M.count(key)){
            cur=M[key];
            cur->val=value;
            erase(cur);
            insert(cur,head->next);
        }
        else{
            if(M.size()==cap){
                cur=tail->prev;
                erase(cur);
                M.erase(cur->key);
                //delete cur;
            }
            M[key]=cur=new DuLinkList(key,value);
            insert(cur,head->next);
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
将如下替换使用一次(也可以自己手打)：

\["(.+?)"(.*?)\]\[\[(.*?)\](.*)\]
\t$1*obj=new $1($3);\n[$2][$4]

将如下替换连续使用：

\[,"(.+?)"(.*?)\]\[,\[(.*?)\](.*)\]
\tobj->$1($3);\n[$2][$4]

*/