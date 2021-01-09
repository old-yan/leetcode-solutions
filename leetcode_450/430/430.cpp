#include "utils.h"

class Solution {
    #define Node DuLinkList
public:
    Node* flatten(Node* head) {
        Node*dummy=new Node;
        Node*tail=dummy;
        stack<Node*>S;
        if(head)S.emplace(head);
        while(S.size()){
            auto p=S.top();
            S.pop();
            tail->next=p;
            p->prev=tail;
            if(p->next)S.emplace(p->next);
            if(p->child)S.emplace(p->child);
            p->next=p->child=nullptr;
            tail=p;
        }
        if(dummy->next)dummy->next->prev=nullptr;
        return dummy->next;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    DuLinkList*head=new DuLinkList("[1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12,null,null,null,null,null,13]");
    DBGN(head);
    auto ans=sol.flatten(head);
    DBGN(ans);

    system("pause");
    return 0;
}
