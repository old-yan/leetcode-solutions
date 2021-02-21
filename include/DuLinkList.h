#pragma once
#include <queue>
#include <stack>
#include <iomanip>
using namespace std;
#define OLDYAN_DULINKLIST

struct DuLinkList{
	int val;
    DuLinkList*prev;
    DuLinkList*next;
    DuLinkList*child;
	DuLinkList() :val(-1),prev(nullptr),next(NULL),child(nullptr) {}
	DuLinkList(int x) : val(x),prev(nullptr),next(nullptr),child(nullptr) {}
    DuLinkList(int x,DuLinkList*_prev,DuLinkList*_next) : val(x),prev(_prev),next(_next){}
    DuLinkList(int x,DuLinkList*_prev,DuLinkList*_next,DuLinkList*_child) : val(x),prev(_prev),next(_next),child(_child) {}
    DuLinkList(string&&s):DuLinkList(){
        auto readdulinklist=[&](int &i){
            if(s[i]=='n'){
                i+=4;
                if(s[i])i++;
                return make_pair(false,0);
            }
            else{
                int signal=1;
                if(s[i]=='-'){
                    signal=-1;
                    i++;
                }
                int val=0;
                while(isdigit(s[i]))val=val*10+s[i++]-'0';
                if(s[i])i++;
                return make_pair(true,val*signal);
            }
        };
        s.erase(remove(s.begin(),s.end(),' '),s.end());
		s.erase(remove(s.begin(),s.end(),'['),s.end());
		s.erase(remove(s.begin(),s.end(),']'),s.end());
        DuLinkList*cur;
        stack<queue<DuLinkList*>*>S;
        int i=0;
        auto pp=readdulinklist(i);
		if (!pp.first)return;
        S.push(new queue<DuLinkList*>);
        val=pp.second;
        cur=this;
        while(cur||S.size()){
            if(i==s.size())break;
            auto pp=readdulinklist(i);
            if(cur){
                S.top()->emplace(cur);
                if(pp.first){
                    cur->next=new DuLinkList(pp.second);
                    cur->next->prev=cur;
                    cur=cur->next;
                }
                else cur=nullptr;
            }
            else{
                auto p=S.top()->front();
                S.top()->pop();
                if(pp.first){
                    p->child=new DuLinkList(pp.second);
                    S.push(new queue<DuLinkList*>);
                    cur=p->child;
                }
                else while(S.top()->empty())S.pop();
            }
        }
    }
};
ostream&operator<<(ostream&out,DuLinkList*head){
	if(!head){
		out<<"empty dulinklist\n";
		return out;
	}
    queue<pair<int,DuLinkList*>>Q;
    Q.emplace(0,head);
    int level=0;
    while(int l=Q.size()){
        level++;
        while(l--){
            auto p=Q.front();
            Q.pop();
            DuLinkList*q=p.second;
            out<<"\nlevel "<<setw(2)<<level;
            if(level==1)out<<" as top level";
            else out<<" as"<<setw(2)<<p.first<<"'s child";
            out<<":"<<q->val;
            if(q->child)Q.emplace(q->val,q->child);
            while(q=q->next){
                out<<"->"<<q->val;
                if(q->child)Q.emplace(q->val,q->child);
            }
        }
    }
	return out;
}
