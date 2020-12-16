#include "utils.h"

class Solution {
    vi nums;
    TreeNode*fun(int l,int r){
        if(l>r)return nullptr;
        int mid=(l+r)/2;
        TreeNode*p=new TreeNode(nums[mid]);
        p->left=fun(l,mid-1);
        p->right=fun(mid+1,r);
        return p;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        auto v=listtoarr(head);
        for(auto a:v)nums.pb(a->val);
        return fun(0,nums.size()-1);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    ListNode*head=makelistnode({-10, -3, 0, 5, 9});
    auto ans=sol.sortedListToBST(head);
    DBGT(ans);

    system("pause");
    return 0;
}
