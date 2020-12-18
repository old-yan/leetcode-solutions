#include "utils.h"

class Solution {
    bool fun(TreeNode*root,ll min,ll max){
        if(!root)return true;
        if(root->val<min||root->val>max)return false;
        return fun(root->left,min,(ll)(root->val)-1)&&fun(root->right,(ll)(root->val)+1,max);
    }
public:
    bool isValidBST(TreeNode* root) {
        if(!root)return true;
        return fun(root,LONG_MIN,LONG_MAX);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("5,1,4,null,null,3,6");
    DBGT(root);
    auto ans=sol.isValidBST(root);
    DBG(ans);

    system("pause");
    return 0;
}
