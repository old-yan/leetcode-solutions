#include "TreeNode.h"
#include "utils.h"

class Solution {
    int ans=0;
    void dfs(TreeNode*root,int cur){
        cur=cur*2+root->val;
        if(!root->left&&!root->right){
            ans+=cur;
        }
        else{
            if(root->left)dfs(root->left,cur);
            if(root->right)dfs(root->right,cur);
        }
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        dfs(root,0);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[1,0,1,0,1,0,1]");
    DBG(root);
    auto ans=sol.sumRootToLeaf(root);
    DBG(ans);

    system("pause");
    return 0;
}
