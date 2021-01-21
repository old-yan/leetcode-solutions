#include "utils.h"

class Solution {
    int ans=0;
    int fun(TreeNode*root){
        if(!root)return 0;
        int num1=fun(root->left);
        int num2=fun(root->right);
        ans+=abs(num1-num2);
        return num1+root->val+num2;
    }
public:
    int findTilt(TreeNode* root) {
        fun(root);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[1,2,3]");
    DBGT(root);
    auto ans=sol.findTilt(root);
    DBG(ans);

    system("pause");
    return 0;
}
