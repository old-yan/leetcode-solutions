#include "TreeNode.h"
#include "utils.h"

class Solution {
    int low,high;
    void fun(TreeNode*&root){
        if(!root)return;
        if(root->val<low){
            root=root->right;
            fun(root);
        }
        else if(root->val>high){
            root=root->left;
            fun(root);
        }
        else{
            fun(root->left);
            fun(root->right);
        }
    }
public:
    TreeNode* trimBST(TreeNode* root, int _low, int _high) {
        low=_low;
        high=_high;
        fun(root);
        return root;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("3,0,4,null,2,null,null,1");
    DBG(root);
    int low=1;
    int high=3;
    auto ans=sol.trimBST(root,low,high);
    DBG(ans);

    system("pause");
    return 0;
}
