#include "ListNode.h"
#include "utils.h"

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        auto arr=listtoarr(head);
        swap(arr[k-1],arr[arr.size()-k]);
        return arrtolist(arr);
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
