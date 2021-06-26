#include "TreeNode.h"
#include "utils.h"

class Solution {
    ll Min,SecondMin;
    void traverse(TreeNode*root){
        if(root->left){
            if(root->left->val!=Min){
                chmin(SecondMin,(ll)root->left->val);
            }
            else traverse(root->left);
            if(root->right->val!=Min){
                chmin(SecondMin,(ll)root->right->val);
            }
            else traverse(root->right);
        }
    }
public:
    int findSecondMinimumValue(TreeNode* root) {
        Min=root->val;
        SecondMin=LLONG_MAX;
        traverse(root);
        return SecondMin==LLONG_MAX?-1:SecondMin;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[2,2,5,null,null,5,7]");
    DBG(root);
    auto ans=sol.findSecondMinimumValue(root);
    DBG(ans);

    system("pause");
    return 0;
}
