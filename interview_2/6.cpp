#include "ListNode.h"
#include "utils.h"

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        auto v=listtoarr(head);
        for(int i=0,j=v.size()-1;i<j;i++,j--){
            if(v[i]->val!=v[j]->val)return false;
        }
        return true;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    ListNode*head=makelistnode({1,2,2,1});
    auto ans=sol.isPalindrome(head);
    DBG(ans);

    system("pause");
    return 0;
}
