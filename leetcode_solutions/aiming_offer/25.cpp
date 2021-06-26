#include "ListNode.h"
#include "utils.h"

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        auto v1=listtoarr(l1);
        auto v2=listtoarr(l2);
        vector<ListNode*>v(v1.size()+v2.size());
        merge(ALL(v1),ALL(v2),v.begin(),[](ListNode*x,ListNode*y){return x->val<y->val;});
        return arrtolist(v);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    ListNode*l1=makelistnode({1,2,4});
    ListNode*l2=makelistnode({1,3,4});
    auto ans=sol.mergeTwoLists(l1,l2);
    DBG(ans);

    system("pause");
    return 0;
}
