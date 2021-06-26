#include "ListNode.h"
#include "utils.h"

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        auto v=listtoarr(head);
        stack<int>S;
        vi ans(v.size(),-1);
        REP(i,v.size()){
            while(S.size()&&v[S.top()]->val<v[i]->val){
                ans[S.top()]=v[i]->val;
                S.pop();
            }
            S.push(i);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    ListNode*head=makelistnode({2,1,5});
    auto ans=sol.nextLargerNodes(head);
    DBGV(ans);

    system("pause");
    return 0;
}
