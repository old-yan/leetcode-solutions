#include "TreeNode.h"
#include "utils.h"

class Solution {
    bool fun(TreeNode*p,TreeNode*q){
        if(!p&&!q)return true;
        if(!p||!q)return false;
        return p->val==q->val&&fun(p->left,q->right)&&fun(p->right,q->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)return true;
        return fun(root->left,root->right);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("1,2,2,3,4,4,3");
    DBG(root);
    auto ans=sol.isSymmetric(root);
    DBG(ans);

    system("pause");
    return 0;
}
