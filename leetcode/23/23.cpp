#include "utils.h"

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto comp=[&](ListNode*x,ListNode*y){return x->val>y->val;};
        priority_queue<ListNode*,vector<ListNode*>,decltype(comp)>Q(comp);
        for(ListNode*a:lists)if(a)Q.push(a);
        vi ans;
        while(Q.size()){
            auto a=Q.top();
            Q.pop();
            ans.pb(a->val);
            if(a->next)Q.push(a->next);
        }
        return makelistnode(ans);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<ListNode*>lists={
        makelistnode({1,4,5}),
        makelistnode({1,3,4}),
        makelistnode({2,6})
    };
    auto ans=sol.mergeKLists(lists);
    DBGL(ans);

    system("pause");
    return 0;
}
