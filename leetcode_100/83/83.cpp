#include "utils.h"

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        auto v=listtoarr(head);
        vi nums;
        unordered_set<int>S;
        for(auto a:v){
            if(S.insert(a->val).second){
                nums.pb(a->val);
            }
        }
        return makelistnode(nums);
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
