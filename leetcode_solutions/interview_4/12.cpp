#include "TreeNode.h"
#include "utils.h"

class Solution {
    int startwith(TreeNode*root,int sum){
        if(!root)return 0;
        sum-=root->val;
        return !sum+startwith(root->left,sum)+startwith(root->right,sum);
    }
public:
    int pathSum(TreeNode* root, int sum) {
        if(!root)return 0;
        else return startwith(root,sum)+pathSum(root->left,sum)+pathSum(root->right,sum);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[5,4,8,11,null,13,4,7,2,null,null,5,1]");
    DBG(root);
    int sum=22;
    auto ans=sol.pathSum(root,sum);
    DBG(ans);

    system("pause");
    return 0;
}
