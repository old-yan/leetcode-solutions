#include "utils.h"

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        auto v=listtoarr(head);
        vector<ListNode*>newv(v.size());
        REP(i,v.size()){
            newv[i]=v[i<=v.size()/2?i*2:(i-v.size()/2)];
        }
        return arrtolist(newv);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    ListNode*head=makelistnode({1,2,3,4,5,6,7,8});
    auto ans=sol.oddEvenList(head);
    DBGL(ans);

    system("pause");
    return 0;
}
