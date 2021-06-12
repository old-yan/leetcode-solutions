#include "ListNode.h"
#include "utils.h"

class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        bool appear[20001]={0};
        auto v=listtoarr(head);
        vector<ListNode*>v2;
        for(auto p:v){
            if(appear[p->val])continue;
            appear[p->val]=true;
            v2.pb(p);
        }
        return arrtolist(v2);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    ListNode*head=makelistnode({1,2,3,3,2,1});
    auto ans=sol.removeDuplicateNodes(head);
    DBG(ans);

    system("pause");
    return 0;
}
