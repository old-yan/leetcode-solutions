#include "ListNode.h"
#include "utils.h"

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        auto v=listtoarr(head);
        return v[v.size()/2];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    ListNode*head=makelistnode({1,2,3,4,5});
    auto ans=sol.middleNode(head);
    DBG(ans);

    system("pause");
    return 0;
}
