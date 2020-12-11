#include "utils.h"

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto v=listtoarr(head);
        v.erase(v.begin()+v.size()-n);
        vi num;
        for(auto a:v)num.pb(a->val);
        return makelistnode(num);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    auto head=makelistnode(vi{1,2,3,4,5});
    auto ans=sol.removeNthFromEnd(head,2);
    DBGL(ans);

    system("pause");
    return 0;
}
