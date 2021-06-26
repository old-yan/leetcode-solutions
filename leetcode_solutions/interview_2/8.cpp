#include "ListNode.h"
#include "utils.h"

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head)return nullptr;
        ListNode*slow=head,*fast=head;
        do{
            slow=slow->next;
            fast=fast->next;
            if(!fast)return nullptr;
            fast=fast->next;
            if(!fast)return nullptr;
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
    head->next->next->next->next=head->next;
    auto ans=sol.detectCycle(head);
    DBG(ans);

    system("pause");
    return 0;
}
