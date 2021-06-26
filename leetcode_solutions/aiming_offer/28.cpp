#include "TreeNode.h"
#include "utils.h"

class Solution {
    bool check(TreeNode*A,TreeNode*B){
        if(!A||!B){
            return !A&&!B;
        }
        if(A->val!=B->val)return false;
        return check(A->left,B->right)&&check(A->right,B->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return !root||check(root->left,root->right);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[1,2,2,3,4,4,3]");
    DBG(root);
    auto ans=sol.isSymmetric(root);
    DBG(ans);

    system("pause");
    return 0;
}
