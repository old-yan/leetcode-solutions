#include "ListNode.h"
#include "utils.h"

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto v1=listtoarr(l1);
        auto v2=listtoarr(l2);
        reverse(ALL(v1));
        reverse(ALL(v2));
        vi v(max(v1.size(),v2.size()),0);
        int jinwei=0;
        for(int i=0;i<v1.size()||i<v2.size();i++){
            if(i<v1.size())v[i]+=v1[i]->val;
            if(i<v2.size())v[i]+=v2[i]->val;
            v[i]+=jinwei;
            jinwei=v[i]/10;
            v[i]%=10;
        }
        if(jinwei)v.pb(1);
        reverse(ALL(v));
        return makelistnode(v);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    ListNode*l1=makelistnode({7,2,4,3});
    ListNode*l2=makelistnode({5,6,4});
    auto ans=sol.addTwoNumbers(l1,l2);
    DBG(ans);

    system("pause");
    return 0;
}
