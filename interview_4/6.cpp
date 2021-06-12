#include "TreeNode.h"
#include "utils.h"

class Solution {
    bool visitp=false;
    TreeNode*ans=nullptr;
    void traverse(TreeNode*root,TreeNode*p){
        if(!root)return;
        traverse(root->left,p);
        if(ans)return;
        else if(visitp)ans=root;
        else if(root==p)visitp=true;
        if(!ans)traverse(root->right,p);
    }
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        traverse(root,p);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[5,3,6,2,4,null,null,1]");
    DBG(root);
    TreeNode*p=root->right;
    DBG(p);
    auto ans=sol.inorderSuccessor(root,p);
    DBG(ans);

    system("pause");
    return 0;
}
