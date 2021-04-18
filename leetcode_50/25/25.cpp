#include "ListNode.h"
#include "utils.h"

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head)return head;
        auto v=listtoarr(head);
        for(int i=0;i+k<=v.size();i+=k){
            reverse(v.begin()+i,v.begin()+i+k);
        }
        return arrtolist(v);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    ListNode*head=makelistnode({1,2,3,4,5});
    auto ans=sol.reverseKGroup(head,2);
    DBG(ans);

    system("pause");
    return 0;
}
