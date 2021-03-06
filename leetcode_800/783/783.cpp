#include "TreeNode.h"
#include "utils.h"

class Solution {
    ll pre=INT_MIN;
    ll ans=INT_MAX;
    void fun(TreeNode*root){
        if(root->left)fun(root->left);
        chmin(ans,root->val-pre);
        pre=root->val;
        if(root->right)fun(root->right);
    }
public:
    int minDiffInBST(TreeNode* root) {
        fun(root);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[4,2,6,1,3,null,null]");
    DBGT(root);
    auto ans=sol.minDiffInBST(root);
    DBG(ans);

    system("pause");
    return 0;
}
