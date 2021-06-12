#include "TreeNode.h"
#include "utils.h"

class Solution {
    pair<bool,int>traverse(TreeNode*root){
        if(!root)return {true,0};
        auto [lb,lh]=traverse(root->left);
        auto [rb,rh]=traverse(root->right);
        return {lb&&rb&&abs(lh-rh)<2,max(lh,rh)+1};
    }
public:
    bool isBalanced(TreeNode* root) {
        return traverse(root).first;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[3,9,20,null,null,15,7]");
    DBG(root);
    auto ans=sol.isBalanced(root);
    DBG(ans);

    system("pause");
    return 0;
}
