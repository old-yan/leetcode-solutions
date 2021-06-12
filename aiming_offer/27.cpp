#include "TreeNode.h"
#include "utils.h"

class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(root){
            swap(root->left,root->right);
            mirrorTree(root->left);
            mirrorTree(root->right);
        }
        return root;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[4,2,7,1,3,6,9]");
    DBG(root);
    auto ans=sol.mirrorTree(root);
    DBG(ans);

    system("pause");
    return 0;
}
