#include "utils.h"

class Solution {
    vector<string>ans;
    char c[2000];
    void dfs(TreeNode*root,int idx){
        if(idx){
            c[idx++]='-';
            c[idx++]='>';
        }
        string s=i2s(root->val);
        strcpy(c+idx,s.c_str());
        idx+=s.size();
        if(root->left)dfs(root->left,idx);
        if(root->right)dfs(root->right,idx);
        if(!root->left&&!root->right){
            c[idx]=0;
            ans.pb(c);
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root)dfs(root,0);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[1,2,3,null,5]");
    DBGT(root);
    auto ans=sol.binaryTreePaths(root);
    DBGV(ans);

    system("pause");
    return 0;
}
