#include "TreeNode.h"
#include "utils.h"

class Solution {
    bool fun(TreeNode*p,int rest){
        rest-=p->val;
        if(rest==0){
            if(!p->left&&!p->right)return true;
        }
        if(p->left&&fun(p->left,rest))return true;
        if(p->right&&fun(p->right,rest))return true;
        return false;
    }
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)return false;
        return fun(root,sum);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("5,4,8,11,null,13,4,7,2,null,null,null,1");
    DBG(root);
    auto ans=sol.hasPathSum(root,22);
    DBG(ans);

    system("pause");
    return 0;
}
