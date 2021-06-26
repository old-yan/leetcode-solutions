#include "TreeNode.h"
#include "utils.h"

class Solution {
    bool check(TreeNode*root,ll floor,ll ceil){
        if(!root)return true;
        if(root->val<floor||root->val>ceil)return false;
        return check(root->left,floor,(ll)root->val-1)&&check(root->right,(ll)root->val+1,ceil);
    }
public:
    bool isValidBST(TreeNode* root) {
        return check(root,INT_MIN,INT_MAX);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[5,1,4,null,null,3,6]");
    DBG(root);
    auto ans=sol.isValidBST(root);
    DBG(ans);

    system("pause");
    return 0;
}
