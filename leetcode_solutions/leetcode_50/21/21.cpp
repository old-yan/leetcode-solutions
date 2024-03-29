#include "ListNode.h"
#include "utils.h"

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        auto v1=listtoarr(l1);
        auto v2=listtoarr(l2);
        vector<ListNode*>v;
        int i,j;
        for(i=0,j=0;i<v1.size()&&j<v2.size();){
            if(v1[i]->val<v2[j]->val)v.pb(v1[i++]);
            else v.pb(v2[j++]);
        }
        while(i<v1.size()){
            v.pb(v1[i++]);
        }
        while(j<v2.size()){
            v.pb(v2[j++]);
        }
        return arrtolist(v);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    auto l1=makelistnode({1,2,4});
    auto l2=makelistnode({1,3,4});
    auto ans=sol.mergeTwoLists(l1,l2);
    DBG(ans);

    system("pause");
    return 0;
}
