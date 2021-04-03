#include "TreeNode.h"
#include "utils.h"

class Solution {
    int ans=0;
    void dfs(TreeNode*root,int low,int high){
        if(!root)return;
        if(root->val>=low&&root->val<=high)ans+=root->val;
        dfs(root->left,low,high);
        dfs(root->right,low,high);
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        dfs(root,low,high);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[10,5,15,3,7,null,18]");
    DBGT(root);
    int low=7;
    int high=15;
    auto ans=sol.rangeSumBST(root,low,high);
    DBG(ans);

    system("pause");
    return 0;
}
