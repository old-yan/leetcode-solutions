#include "ListNode.h"
#include "utils.h"

class Solution {
public:
    int kthToLast(ListNode* head, int k) {
        auto v=listtoarr(head);
        return v[v.size()-k]->val;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    ListNode*head=makelistnode({1,2,3,4,5});
    int k=2;
    auto ans=sol.kthToLast(head,k);
    DBG(ans);

    system("pause");
    return 0;
}
