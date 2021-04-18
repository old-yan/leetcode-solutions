#include "ListNode.h"
#include "utils.h"

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        auto v=listtoarr(head);
        vector<ListNode*>v1,v2;
        for(auto a:v){
            if(a->val<x)v1.pb(a);
            else v2.pb(a);
        }
        for(auto a:v2)v1.pb(a);
        return arrtolist(v1);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    ListNode*head=makelistnode({1,4,3,2,5,2});
    auto ans=sol.partition(head,3);
    DBG(ans);

    system("pause");
    return 0;
}
