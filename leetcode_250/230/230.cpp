#include "utils.h"

class Solution {
    int ans;
    int k;
    int idx=0;
    void dfs(TreeNode*root){
        if(root->left)dfs(root->left);
        if(++idx==k)ans=root->val;
        if(idx<k&&root->right)dfs(root->right);
    }
public:
    int kthSmallest(TreeNode* root, int _k) {
        k=_k;
        dfs(root);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("5,3,6,2,4,null,null,1");
    auto ans=sol.kthSmallest(root,3);
    DBG(ans);

    system("pause");
    return 0;
}
