#include "utils.h"

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head)return head;
        auto v=listtoarr(head);
        REP(i,v.size()){
            if(i%2==0&&i+1<v.size()){
                swap(v[i],v[i+1]);
            }
        }
        FOR(i,1,v.size()){
            v[i-1]->next=v[i];
        }
        v.back()->next=nullptr;
        return v[0];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    ListNode*head=makelistnode({1,2,3,4});
    auto ans=sol.swapPairs(head);
    DBGL(ans);

    system("pause");
    return 0;
}
