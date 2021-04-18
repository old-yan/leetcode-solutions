#include "TreeNode.h"
#include "utils.h"

class Solution {
    int ans=1;
    int fun(TreeNode*root){
        if(!root)return 0;
        auto p=fun(root->left);
        auto q=fun(root->right);
        chmax(ans,p+q+1);
        return max(p,q)+1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        fun(root);
        return ans-1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[1,2,3,4,5]");
    DBG(root);
    auto ans=sol.diameterOfBinaryTree(root);
    DBG(ans);

    system("pause");
    return 0;
}
