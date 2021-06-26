#include "TreeNode.h"
#include "utils.h"

class Solution {
    int ans=0;
    tuple<bool,int,int,int>traverse(TreeNode*root){
        if(!root)return {true,INT_MAX,INT_MIN,0};
        else{
            auto [b1,lMin,lMax,lsum]=traverse(root->left);
            auto [b2,rMin,rMax,rsum]=traverse(root->right);
            if(!b1||!b2||lMax>=root->val||rMin<=root->val)return {false,0,0,0};
            chmax(ans,lsum+root->val+rsum);
            return {true,min(lMin,root->val),max(rMax,root->val),lsum+root->val+rsum};
        }
    }
public:
    int maxSumBST(TreeNode* root) {
        traverse(root);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]");
    DBG(root);
    auto ans=sol.maxSumBST(root);
    DBG(ans);

    system("pause");
    return 0;
}
