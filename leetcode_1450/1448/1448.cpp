#include "TreeNode.h"
#include "utils.h"

class Solution {
    int ans=0;
    void traverse(TreeNode*root,int Max){
        if(Max<=root->val)ans++;
        chmax(Max,root->val);
        if(root->left)traverse(root->left,Max);
        if(root->right)traverse(root->right,Max);
    }
public:
    int goodNodes(TreeNode* root) {
        traverse(root,INT_MIN);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[3,1,4,3,null,1,5]");
    DBG(root);
    auto ans=sol.goodNodes(root);
    DBG(ans);

    system("pause");
    return 0;
}
