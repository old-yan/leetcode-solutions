#include "ListNode.h"
#include "utils.h"

class Solution {
public:
    void deleteNode(ListNode*node) {
        auto next=node->next;
        *node=*next;
        delete next;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    ListNode*head=makelistnode({4,5,1,9});
    ListNode*node=head->next;
    sol.deleteNode(node);
    DBG(head);

    system("pause");
    return 0;
}
