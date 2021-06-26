#include "ListNode.h"
#include "utils.h"

class Solution {
    pair<ListNode*,ListNode*>fun(ListNode*p,int count){
        if(count==1)return make_pair(p,p);
        else{
            auto a=fun(p,count/2);
            auto b=fun(a.second->next,(count+1)/2);
            auto next=b.second->next;
            ListNode*q1,*q2,*h=nullptr,*t=nullptr;
            for(q1=a.first,q2=b.first;q1&&q2;){
                if(q1->val<q2->val){
                    if(!t){
                        h=t=q1;
                    }
                    else{
                        t->next=q1;
                        t=q1;
                    }
                    q1=q1==a.second?nullptr:q1->next;
                }
                else{
                    if(!t){
                        h=t=q2;
                    }
                    else{
                        t->next=q2;
                        t=q2;
                    }
                    q2=q2==b.second?nullptr:q2->next;
                }
            }
            while(q1){
                t->next=q1;
                t=q1;
                q1=q1==a.second?nullptr:q1->next;
            }
            while(q2){
                t->next=q2;
                t=q2;
                q2=q2==b.second?nullptr:q2->next;
            }
            t->next=next;
            return make_pair(h,t);
        }
    }
public:
    ListNode* sortList(ListNode* head) {
        if(!head)return head;
        int count=0;
        for(auto p=head;p;p=p->next)count++;
        return fun(head,count).first;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    ListNode*head=makelistnode({1,5,3,4,0});
    auto ans=sol.sortList(head);
    DBG(ans);

    system("pause");
    return 0;
}
