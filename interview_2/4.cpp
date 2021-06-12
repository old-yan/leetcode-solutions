#include "ListNode.h"
#include "utils.h"

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        vector<ListNode*>v1,v2;
        auto v=listtoarr(head);
        for(auto p:v){
            if(p->val<x)v1.pb(p);
            else v2.pb(p);
        }
        v1.insert(v1.end(),ALL(v2));
        return arrtolist(v1);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    ListNode*head=makelistnode({3,5,8,5,10,2,1});
    int x=5;
    auto ans=sol.partition(head,x);
    DBG(ans);

    system("pause");
    return 0;
}
