#include "ListNode.h"
#include "utils.h"

class Solution {
public:
    void reorderList(ListNode*&head) {
        if(!head)return;
        auto v=listtoarr(head);
        vector<ListNode*>v2;
        for(int i=0,j=v.size()-1;i<=j;){
            v2.pb(v[i++]);
            if(i<=j)v2.pb(v[j--]);
        }
        head=arrtolist(v2);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    ListNode*head=makelistnode({1,2,3,4,5});
    sol.reorderList(head);
    DBG(head);

    system("pause");
    return 0;
}
