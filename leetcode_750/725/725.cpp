#include "ListNode.h"
#include "utils.h"

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        auto v=listtoarr(root);
        int every=v.size()/k;
        int rest=v.size()%k;
        vector<ListNode*>ans(k);
        int cursor=0;
        REP(i,k){
            int len=rest-->0?every+1:every;
            auto vv=vector<ListNode*>(v.begin()+cursor,v.begin()+cursor+len);
            cursor+=len;
            ans[i]=arrtolist(vv);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    ListNode*root=makelistnode({1,2,3,4});
    int k=5;
    auto ans=sol.splitListToParts(root,k);
    REP(i,ans.size()){
        cout<<i<<' ';
        DBGL(ans[i]);
    }

    system("pause");
    return 0;
}
