#include "TreeNode.h"
#include "utils.h"

class Solution {
    int ans=0;
    int fun(TreeNode*root){
        if(!root)return 0;
        int left=fun(root->left);
        int right=fun(root->right);
        int res=1;
        if((root->left&&root->left->val==root->val)&&(root->right&&root->right->val==root->val)){
            chmax(ans,left+right);
            chmax(res,max(left,right)+1);
        }
        else if(root->left&&root->left->val==root->val){
            chmax(ans,left);
            chmax(res,left+1);
        }
        else if(root->right&&root->right->val==root->val){
            chmax(ans,right);
            chmax(res,right+1);
        }
        return res;
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        fun(root);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[5,4,5,1,1,5]");
    DBG(root);
    auto ans=sol.longestUnivaluePath(root);
    DBG(ans);

    system("pause");
    return 0;
}
