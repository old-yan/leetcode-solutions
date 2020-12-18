#include "utils.h"

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head)return nullptr;
        auto v=listtoarr(head);
        REP(i,v.size()){
            for(int j=i;j>0&&v[j]->val<v[j-1]->val;j--)swap(v[j],v[j-1]);
        }
        return arrtolist(v);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    ListNode*head=makelistnode({1,5,3,4,0});
    auto ans=sol.insertionSortList(head);
    DBGL(ans);

    system("pause");
    return 0;
}
