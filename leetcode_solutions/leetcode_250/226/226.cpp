#include "TreeNode.h"
#include "utils.h"

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root)return root;
        TreeNode*temp=invertTree(root->left);
        root->left=invertTree(root->right);
        root->right=temp;
        return root;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[4,2,7,1,3,6,9]");
    DBG(root);
    auto ans=sol.invertTree(root);
    DBG(ans);

    system("pause");
    return 0;
}
