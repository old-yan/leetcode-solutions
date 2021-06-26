#include "ListNode.h"
#include "utils.h"

class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode*dummy=new ListNode(val+1,head);
        for(auto p=dummy;;p=p->next){
            if(p->next&&p->next->val==val){
                p->next=p->next->next;
                break;
            }
        }
        return dummy->next;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    ListNode*head=makelistnode({4,5,1,9});
    int val=5;
    auto ans=sol.deleteNode(head,val);
    DBG(ans);

    system("pause");
    return 0;
}
