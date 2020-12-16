#include "utils.h"

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        auto v=listtoarr(head);
        reverse(v.begin()+m-1,v.begin()+n);
        vi nums;
        for(auto a:v)nums.pb(a->val);
        return makelistnode(nums);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    ListNode*head=makelistnode({1,2,3,4,5});
    int m=2;
    int n=4;
    auto ans=sol.reverseBetween(head,m,n);
    DBGL(ans);

    system("pause");
    return 0;
}
