#include "ListNode.h"
#include "utils.h"

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vi ans;
        for(auto a:listtoarr(head)){
            ans.pb(a->val);
        }
        reverse(ALL(ans));
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    ListNode*head=makelistnode({1,3,2});
    auto ans=sol.reversePrint(head);
    DBGV(ans);

    system("pause");
    return 0;
}
