#include "utils.h"

class Solution {
    vi ans;
    void dfs(TreeNode*root){
        if(root->left)dfs(root->left);
        ans.pb(root->val);
        if(root->right)dfs(root->right);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root)dfs(root);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("1,null,2");
    DBGT(root);
    auto ans=sol.inorderTraversal(root);
    DBGV(ans);

    system("pause");
    return 0;
}