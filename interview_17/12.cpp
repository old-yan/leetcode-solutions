#include "TreeNode.h"
#include "utils.h"

class Solution {
    pair<TreeNode*,TreeNode*>func(TreeNode*root){
        if(!root->left){
            if(root->right){
                auto [rh,rt]=func(root->right);
                root->right=rh;
                return {root,rt};
            }
            else{
                return {root,root};
            }
        }
        else{
            if(root->right){
                auto [lh,lt]=func(root->left);
                auto [rh,rt]=func(root->right);
                lt->right=root;
                root->left=nullptr;
                root->right=rh;
                return {lh,rt};
            }
            else{
                auto [lh,lt]=func(root->left);
                lt->right=root;
                root->left=nullptr;
                return {lh,root};
            }
        }
    }
public:
    TreeNode* convertBiNode(TreeNode* root) {
        if(!root)return nullptr;
        return func(root).first;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("4,2,5,1,3,null,6,0");
    DBG(root);
    auto ans=sol.convertBiNode(root);
    DBG(ans);

    system("pause");
    return 0;
}
