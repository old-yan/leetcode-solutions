#include "utils.h"

class Solution {
    int depth(TreeNode*root){
        if(!root)return 0;
        return max(depth(root->left),depth(root->right))+1;
    }
    void dfs(TreeNode*root,vector<vector<string>>&ans,int d,int pos,int arm){
        ans[d][pos]=i2s(root->val);
        if(root->left)dfs(root->left,ans,d+1,pos-arm,arm/2);
        if(root->right)dfs(root->right,ans,d+1,pos+arm,arm/2);
    }
public:
    vector<vector<string>> printTree(TreeNode* root) {
        int d=depth(root);
        vector<vector<string>>ans(d,vector<string>((1<<d)-1));
        dfs(root,ans,0,(1<<(d-1))-1,d>1?(1<<(d-2)):0);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[1,2]");
    DBGT(root);
    auto ans=sol.printTree(root);
    DBGVV(ans);

    system("pause");
    return 0;
}
