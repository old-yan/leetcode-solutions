#include "utils.h"

class Solution {
    int fun(TreeNode*p){
        if(!p->left&&!p->right)return 1;
        int d=INT_MAX;
        if(p->left)chmin(d,fun(p->left)+1);
        if(p->right)chmin(d,fun(p->right)+1);
        return d;
    }
public:
    int minDepth(TreeNode* root) {
        if(!root)return 0;
        return fun(root);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("3,9,20,null,null,15,7");
    DBGT(root);
    auto ans=sol.minDepth(root);
    DBG(ans);

    system("pause");
    return 0;
}
