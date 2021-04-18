#include "TreeNode.h"
#include "utils.h"

class Solution {
    int cnt=0;
    void reverse_traverse(TreeNode*root){
        if(root->right)reverse_traverse(root->right);
        cnt+=root->val;
        root->val=cnt;
        if(root->left)reverse_traverse(root->left);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        if(root)reverse_traverse(root);
        return root;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]");
    DBG(root);
    auto ans=sol.convertBST(root);
    DBG(ans);

    system("pause");
    return 0;
}
