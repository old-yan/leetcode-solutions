#include "TreeNode.h"
#include "utils.h"

class Solution {
    void fun(TreeNode*&root,int val){
        if(!root||root->val<val){
            root=new TreeNode(val,root,nullptr);
        }
        else{
            fun(root->right,val);
        }
    }
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        fun(root,val);
        return root;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[4,1,3,null,null,2]");
    DBG(root);
    int val=5;
    auto ans=sol.insertIntoMaxTree(root,val);
    DBG(ans);

    system("pause");
    return 0;
}
