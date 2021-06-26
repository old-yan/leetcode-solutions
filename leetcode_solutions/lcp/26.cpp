#include "TreeNode.h"
#include "utils.h"

class Solution {
    int dfs(TreeNode*root){
        if(!root)return 0;
        auto l=dfs(root->left);
        auto r=dfs(root->right);
        if(!root->left||!root->right)return l+r;
        else return max(1,l+r);
    }
public:
    int navigation(TreeNode* root) {
        return max(1,dfs(root));
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[1,2,null,3,4]");
    DBG(root);
    auto ans=sol.navigation(root);
    DBG(ans);

    system("pause");
    return 0;
}
