#include "ListNode.h"
#include "utils.h"

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        auto v=listtoarr(head);
        swap(v[k-1],v[v.size()-k]);
        return arrtolist(v);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    ListNode*head=makelistnode({1,2,3,4,5});
    int k=2;
    auto ans=sol.swapNodes(head,k);
    DBG(ans);

    system("pause");
    return 0;
}
