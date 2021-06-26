#include "RandomNode.h"
#include "utils.h"

class Solution {
    #define Node RandomNode//提交时注释本行
public:
    Node* copyRandomList(Node* head) {
        Node*p;
        Node*dummy=new Node(-1),*tail=dummy;
        unordered_map<Node*,Node*>M;
        for(p=head;p;p=p->next){
            tail->next=new Node(p->val);
            tail=tail->next;
            M[p]=tail;
        }
        tail=dummy;
        for(p=head;p;p=p->next){
            tail=tail->next;
            tail->random=M[p->random];
        }
        return dummy->next;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    Node*head=makerandomnode("[[7,null],[13,0],[11,4],[10,2],[1,0]]");
    DBG(head);
    auto ans=sol.copyRandomList(head);
    DBG(ans);

    system("pause");
    return 0;
}
