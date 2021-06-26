#include "TreeNode.h"
#include "utils.h"

class Solution {
    int cnt[9]={0};
    int odd=0;
    int ans=0;
    void traverse(TreeNode*root){
        cnt[root->val]^=1;
        if(cnt[root->val])odd++;
        else odd--;
        if(!root->left&&!root->right){
            ans+=odd<=1;
        }
        else{
            if(root->left)traverse(root->left);
            if(root->right)traverse(root->right);
        }
        cnt[root->val]^=1;
        if(cnt[root->val])odd++;
        else odd--;
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        traverse(root);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[2,3,1,3,1,null,1]");
    DBG(root);
    auto ans=sol.pseudoPalindromicPaths(root);
    DBG(ans);

    system("pause");
    return 0;
}
