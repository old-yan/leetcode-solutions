#include "TreeNode.h"
#include "utils.h"

class Solution {
    vector<TreeNode*> seq;
    void inordertraverse(TreeNode*root){
        if(root->left)inordertraverse(root->left);
        seq.pb(root);
        if(root->right)inordertraverse(root->right);
    }
    TreeNode* makeBBST(int l,int r){
        if(l>r)return nullptr;
        int mid=(l+r)/2;
        seq[mid]->left=makeBBST(l,mid-1);
        seq[mid]->right=makeBBST(mid+1,r);
        return seq[mid];
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        inordertraverse(root);
        return makeBBST(0,seq.size()-1);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[1,null,2,null,3,null,4,null,null]");
    DBG(root);
    auto ans=sol.balanceBST(root);
    DBG(ans);

    system("pause");
    return 0;
}
