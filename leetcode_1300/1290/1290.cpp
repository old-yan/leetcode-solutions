#include "ListNode.h"
#include "utils.h"

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        auto v=listtoarr(head);
        int cur=0;
        for(auto a:v){
            cur=cur*2+a->val;
        }
        return cur;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    ListNode*head=makelistnode({1,0,1});
    auto ans=sol.getDecimalValue(head);
    DBG(ans);

    system("pause");
    return 0;
}
