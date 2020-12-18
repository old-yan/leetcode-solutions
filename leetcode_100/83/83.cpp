#include "utils.h"

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        auto v=listtoarr(head);
        vector<ListNode*>v2;
        unordered_set<int>S;
        for(auto a:v){
            if(S.insert(a->val).second){
                v2.pb(a);
            }
        }
        return arrtolist(v2);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    ListNode*head=makelistnode({1,1,2,3,3});
    auto ans=sol.deleteDuplicates(head);
    DBGL(ans);

    system("pause");
    return 0;
}
