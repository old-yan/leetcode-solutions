#include "utils.h"

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head)return nullptr;
        ListNode*slow=head,*fast=head;
        do{
            fast=fast->next;
            if(!fast)return nullptr;
            fast=fast->next;
            if(!fast)return nullptr;
            slow=slow->next;
        }while(slow!=fast);
        fast=head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    ListNode*head=makelistnode({3,2,0,-4});
    int pos=1;
    if(head){
        auto v=listtoarr(head);
        v.back()->next=v[pos];
    }
    auto ans=sol.detectCycle(head);
    DBG(ans->val);

    system("pause");
    return 0;
}
