#include "ListNode.h"
#include "utils.h"

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)return nullptr;
        auto v=listtoarr(head);
        vector<ListNode*> v2;
        k%=v.size();
        FOR(i,v.size()-k,v.size())v2.pb(v[i]);
        FOR(i,0,v.size()-k)v2.pb(v[i]);
        return arrtolist(v2);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    ListNode*head=makelistnode({1,2,3,4,5});
    auto ans=sol.rotateRight(head,2);
    DBG(ans);

    system("pause");
    return 0;
}
