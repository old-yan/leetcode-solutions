#include "ListNode.h"
#include "utils.h"

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        auto v=listtoarr(head);
        vector<ListNode*>v2;
        unordered_map<int,int>M;
        for(auto a:v)M[a->val]++;
        for(auto a:v){
            if(M[a->val]==1)v2.pb(a);
        }
        return arrtolist(v2);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    ListNode*head=makelistnode({1,2,3,3,4,4,5});
    auto ans=sol.deleteDuplicates(head);
    DBG(ans);

    system("pause");
    return 0;
}
