#include "ListNode.h"
#include "utils.h"

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto v1=listtoarr(l1);
        auto v2=listtoarr(l2);
        vector<int>v(max(v1.size(),v2.size()),0);
        int up=0;
        REP(i,max(v1.size(),v2.size())){
            v[i]+=up+v1[i]->val+v2[i]->val;
            if(v[i]>=10){
                up=1;
                v[i]%=10;
            }
            else{
                up=0;
            }
        }
        if(up)v.pb(1);
        vector<ListNode*>vv;
        for(int a:v)vv.pb(new ListNode(a));
        return arrtolist(vv);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    ListNode*l1=makelistnode({7,1,6});
    ListNode*l2=makelistnode({5,9,2});
    auto ans=sol.addTwoNumbers(l1,l2);
    DBG(ans);

    system("pause");
    return 0;
}
