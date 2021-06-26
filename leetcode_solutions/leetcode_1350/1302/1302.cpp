#include "TreeNode.h"
#include "utils.h"

class Solution {
    int maxd=0;
    int ans=0;
    void traverse(TreeNode*root,int d){
        if(root->left||root->right){
            if(root->left)traverse(root->left,d+1);
            if(root->right)traverse(root->right,d+1);
        }
        else{
            if(chmax(maxd,d))ans=root->val;
            else if(maxd==d)ans+=root->val;
        }
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        traverse(root,1);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[1,2,3,4,5,null,6,7,null,null,null,null,8]");
    DBG(root);
    auto ans=sol.deepestLeavesSum(root);
    DBG(ans);

    system("pause");
    return 0;
}
