#include "ListNode.h"
#include "utils.h"

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        auto v=listtoarr(head);
        vector<ListNode*>newv(v.size());
        for(int i=0,j=0;i<v.size();i++,j=(j+2)>=v.size()?1:j+2){
            newv[i]=v[j];
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
    DBG(ans);

    system("pause");
    return 0;
}
