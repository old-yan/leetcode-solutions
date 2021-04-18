#include "TreeNode.h"
#include "utils.h"

class Solution {
    void fun(TreeNode*&root){
        if(!root)return;
        fun(root->left);
        fun(root->right);
        if(!root->left&&!root->right&&!root->val){
            root=nullptr;
        }
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        fun(root);
        return root;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("1,null,0,0,1");
    DBG(root);
    auto ans=sol.pruneTree(root);
    DBG(ans);

    system("pause");
    return 0;
}
