#include "TreeNode.h"
#include "utils.h"

class Solution {
    int target;
    void traverse(TreeNode*&root){
        if(root->left)traverse(root->left);
        if(root->right)traverse(root->right);
        if(!root->left&&!root->right&&root->val==target){
            root=nullptr;
        }
    }
public:
    TreeNode* removeLeafNodes(TreeNode* root, int _target) {
        target=_target;
        traverse(root);
        return root;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[1,2,3,2,null,2,4]");
    DBG(root);
    int target=2;
    auto ans=sol.removeLeafNodes(root,target);
    DBG(ans);

    system("pause");
    return 0;
}
