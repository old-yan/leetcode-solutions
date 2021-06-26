#include "TreeNode.h"
#include "utils.h"

class Solution {
    int ans=0;
    void traverse(TreeNode*root,int d){
        chmax(ans,d);
        if(root->left)traverse(root->left,d+1);
        if(root->right)traverse(root->right,d+1);
    }
public:
    int maxDepth(TreeNode* root) {
        if(root)traverse(root,1);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[3,9,20,null,null,15,7]");
    DBG(root);
    auto ans=sol.maxDepth(root);
    DBG(ans);

    system("pause");
    return 0;
}
