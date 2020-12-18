#include "utils.h"

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)return 0;
        return max(maxDepth(root->left),maxDepth(root->right))+1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("3,9,20,null,null,15,7");
    DBGT(root);
    auto ans=sol.maxDepth(root);
    DBG(ans);

    system("pause");
    return 0;
}
