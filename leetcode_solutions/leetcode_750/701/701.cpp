#include "TreeNode.h"
#include "utils.h"

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode*root, int val) {
        if(!root)return new TreeNode(val);
        else{
            if(val<root->val)root->left=insertIntoBST(root->left,val);
            else root->right=insertIntoBST(root->right,val);
            return root;
        }
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[4,2,7,1,3]");
    DBG(root);
    int val=5;
    auto ans=sol.insertIntoBST(root,val);
    DBG(ans);

    system("pause");
    return 0;
}
