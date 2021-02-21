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
    int getMinimumDifference(TreeNode* root) {
        fun(root);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[1,null,3,2]");
    DBGT(root);
    auto ans=sol.getMinimumDifference(root);
    DBG(ans);

    system("pause");
    return 0;
}
