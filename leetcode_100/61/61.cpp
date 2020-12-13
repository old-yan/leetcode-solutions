#include "utils.h"

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        auto v=listtoarr(head);
        vi v2;
        k%=v.size();
        FOR(i,v.size()-k,v.size())v2.pb(v[i]->val);
        FOR(i,0,v.size()-k)v2.pb(v[i]->val);
        return makelistnode(v2);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    ListNode*head=makelistnode({1,2,3,4,5});
    auto ans=sol.rotateRight(head,2);
    DBGL(ans);

    system("pause");
    return 0;
}
