#include "utils.h"

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head)return false;
        ListNode*slow=head,*fast=head;
        do{
            fast=fast->next;
            if(!fast)return false;
            fast=fast->next;
            if(!fast)return false;
            slow=slow->next;
        }while(slow!=fast);
        return true;
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
    auto ans=sol.hasCycle(head);
    DBG(ans);

    system("pause");
    return 0;
}
