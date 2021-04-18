#include "LCA.h"
#include "utils.h"

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        LCA lca(root);
        return lca.getlca(p,q);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[3,5,1,6,2,0,8,null,null,7,4]");
    DBG(root);
    TreeNode*p=root->left;
    TreeNode*q=root->right;
    auto ans=sol.lowestCommonAncestor(root,p,q);
    DBG(ans);

    system("pause");
    return 0;
}
