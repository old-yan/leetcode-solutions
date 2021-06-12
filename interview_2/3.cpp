#include "ListNode.h"
#include "utils.h"

class Solution {
public:
    void deleteNode(ListNode* node) {
        *node=*node->next;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    ListNode*head=makelistnode({4,5,1,9});
    ListNode*node=head->next;
    sol.deleteNode(node);
    DBG(node);

    system("pause");
    return 0;
}
