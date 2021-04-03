#include "TreeNode.h"
#include "utils.h"

class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(!root1&&!root2)return true;
        if(!root1||!root2)return false;
        if(root1->val!=root2->val)return false;
        return (flipEquiv(root1->left,root2->left)&&flipEquiv(root1->right,root2->right))||(flipEquiv(root1->left,root2->right)&&flipEquiv(root1->right,root2->left));
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root1=new TreeNode("[1,2,3,4,5,6,null,null,null,7,8]");
    DBGT(root1);
    TreeNode*root2=new TreeNode("[1,3,2,null,6,4,5,null,null,null,null,8,7]");
    DBGT(root2);
    auto ans=sol.flipEquiv(root1,root2);
    DBG(ans);

    system("pause");
    return 0;
}
