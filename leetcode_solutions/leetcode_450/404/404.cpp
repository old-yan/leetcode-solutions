#include "utils.h"

class Solution {
    int ans=0;
    void dfs(TreeNode*root,bool isleft){
        if(!root->left&&!root->right){
            if(isleft)ans+=root->val;
        }
        else{
            if(root->left)dfs(root->left,true);
            if(root->right)dfs(root->right,false);
        }
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root)dfs(root,false);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("3,9,20,null,null,15,7");
    auto ans=sol.sumOfLeftLeaves(root);
    DBG(ans);

    system("pause");
    return 0;
}
