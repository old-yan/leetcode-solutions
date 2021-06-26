#include "ListNode.h"
#include "utils.h"

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        auto v=listtoarr(head);
        vector<ListNode*>v2;
        for(auto a:v){
            if(a->val!=val)v2.pb(a);
        }
        return arrtolist(v2);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    ListNode*head=makelistnode({1,2,6,3,4,5,6});
    auto ans=sol.removeElements(head,6);
    DBG(ans);

    system("pause");
    return 0;
}
