#include "TreeNode.h"
#include "utils.h"

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root||root->val==val)return root;
        if(val<root->val)return searchBST(root->left,val);
        else return searchBST(root->right,val);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[4,2,7,1,3]");
    DBGT(root);
    int val=2;
    auto ans=sol.searchBST(root,val);
    DBGT(ans);

    system("pause");
    return 0;
}
