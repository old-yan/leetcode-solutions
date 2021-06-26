#include "TreeNode.h"
#include "utils.h"

class Solution {
    unordered_map<TreeNode*,ll>M;
    ll sum;
    ll ans=LLONG_MIN;
    int traverse(TreeNode*root){
        if(!root)return 0;
        auto l=traverse(root->left);
        auto r=traverse(root->right);
        return M[root]=root->val+l+r;
    }
    void traverse2(TreeNode*root){
        if(root->left){
            chmax(ans,M[root->left]*(sum-M[root->left]));
            traverse2(root->left);
        }
        if(root->right){
            chmax(ans,M[root->right]*(sum-M[root->right]));
            traverse2(root->right);
        }
    }
public:
    int maxProduct(TreeNode* root) {
        traverse(root);
        sum=M[root];
        traverse2(root);
        return ans%MOD;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("2,3,9,10,7,8,6,5,4,11,1");
    DBG(root);
    auto ans=sol.maxProduct(root);
    DBG(ans);

    system("pause");
    return 0;
}
