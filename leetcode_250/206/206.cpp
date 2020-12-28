#include "utils.h"

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        auto v=listtoarr(head);
        reverse(ALL(v));
        return arrtolist(v);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    ListNode*head=makelistnode({1,2,3,4,5});
    auto ans=sol.reverseList(head);
    DBGL(ans);

    system("pause");
    return 0;
}
