#include "utils.h"

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        auto v=listtoarr(head);
        vi v1,v2;
        for(auto a:v){
            if(a->val<x)v1.pb(a->val);
            else v2.pb(a->val);
        }
        for(int b:v2)v1.pb(b);
        return makelistnode(v1);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    ListNode*head=makelistnode({1,4,3,2,5,2});
    auto ans=sol.partition(head,3);
    DBGL(ans);

    system("pause");
    return 0;
}
