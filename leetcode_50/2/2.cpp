#include "utils.h"

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto a=listtoarr(l1);
        auto b=listtoarr(l2);
        vi c(max(a.size(),b.size()),0);
        int jinwei=0;
        REP(i,c.size()){
            if(i<a.size())c[i]+=a[i]->val;
            if(i<b.size())c[i]+=b[i]->val;
            c[i]+=jinwei;
            if(c[i]>=10){
                c[i]-=10;
                jinwei=1;
            }
            else jinwei=0;
        }
        if(jinwei)c.push_back(1);
        return makelistnode(c);
    }
};

int main(){
    Solution sol;

    auto l1=makelistnode(vi{2,4,3});
    DBGL(l1);
    auto l2=makelistnode(vi{5,6,4});
    DBGL(l2);
    auto ans=sol.addTwoNumbers(l1,l2);
    DBGL(ans);

    system("pause");
}