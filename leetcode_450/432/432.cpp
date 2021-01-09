#include "utils.h"

class AllOne {
    struct DuList{
        int val;
        int num;
        vector<string>v;
        DuList*prev;
        DuList*next;
        DuList(int _val) : val(_val),num(0),prev(nullptr),next(nullptr){}
        DuList(int _val,int _num) : val(_val),num(_num),prev(nullptr),next(nullptr){}
    };
    DuList*head,*tail;
    unordered_map<string,pair<DuList*,int>>M;
public:
    AllOne() :head(new DuList(INT_MIN)),tail(new DuList(INT_MAX)){
        head->next=tail;
        tail->prev=head;
    }
    void inc(string key) {
        if(M.count(key)){
            auto find=M[key];
            auto p=find.first;
            if(p->num==1){
                if(p->next->val==p->val+1){
                    p->next->num++;
                    p->next->v.emplace_back(key);
                    p->next->prev=p->prev;
                    p->prev->next=p->next;
                    M[key]=make_pair(p->next,p->next->v.size()-1);
                    delete p;
                }
                else{
                    p->val++;
                }
            }
            else{
                p->num--;
                swap(p->v[find.second],p->v[p->v.size()-1]);
                p->v.pop_back();
                if(p->next->val!=p->val+1){
                    auto q=new DuList(p->val+1,0);
                    q->prev=p;
                    q->next=p->next;
                    p->next=q;
                    q->next->prev=q;
                }
                p->next->num++;
                p->next->v.emplace_back(key);
                M[key]=make_pair(p->next,p->next->v.size()-1);
            }
        }
        else{
            if(head->next->val!=1){
                auto q=new DuList(1,0);
                q->prev=head;
                q->next=head->next;
                head->next=q;
                q->next->prev=q;
            }
            head->next->num++;
            head->next->v.emplace_back(key);
            M[key]=make_pair(head->next,head->next->v.size()-1);
        }
    }
    void dec(string key) {
        if(M.count(key)){
            auto find=M[key];
            auto p=find.first;
            if(p->val==1){
                if(!--p->num){
                    p->prev->next=p->next;
                    p->next->prev=p->prev;
                    delete p;
                }
                else{
                    swap(p->v[find.second],p->v[p->v.size()-1]);
                    p->v.pop_back();
                }
                M.erase(key);
            }
            else if(p->num==1){
                if(p->prev->val==p->val-1){
                    p->prev->num++;
                    p->prev->v.emplace_back(key);
                    p->prev->next=p->next;
                    p->next->prev=p->prev;
                    M[key]=make_pair(p->prev,p->prev->v.size()-1);
                    delete p;
                }
                else{
                    p->val--;
                }
            }
            else{
                p->num--;
                swap(p->v[find.second],p->v[p->v.size()-1]);
                p->v.pop_back();
                if(p->prev->val!=p->val-1){
                    auto q=new DuList(p->val-1,0);
                    q->next=p;
                    q->prev=p->prev;
                    p->prev=q;
                    q->prev->next=q;
                }
                p->prev->num++;
                p->prev->v.emplace_back(key);
                M[key]=make_pair(p->prev,p->prev->v.size()-1);
            }
        }
    }
    string getMaxKey() {
        if(M.empty())return "";
        vector<string>v;
        for(auto it:M){
            if(it.second==tail->prev){
                v.emplace_back(it.first);
            }
        }
        return v[rand()%v.size()];
    }
    string getMinKey() {
        if(M.empty())return "";
        vector<string>v;
        for(auto it:M){
            if(it.second==head->next){
                v.emplace_back(it.first);
            }
        }
        return v[rand()%v.size()];
    }
};

int main()
{
    cout<<boolalpha;

    AllOne*obj=new AllOne();
	obj->getMaxKey();
	obj->getMinKey();

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