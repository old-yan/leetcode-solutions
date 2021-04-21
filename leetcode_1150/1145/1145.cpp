#include "TreeNode.h"
#include "utils.h"

class Solution {
    unordered_map<TreeNode*,int>M;
    TreeNode*cur;
    int x;
    int traverse(TreeNode*root){
        if(!root)return 0;
        if(root->val==x)cur=root;
        int l=traverse(root->left);
        int r=traverse(root->right);
        return M[root]=l+r+1;
    }
public:
    bool btreeGameWinningMove(TreeNode* root, int n, int _x) {
        x=_x;
        traverse(root);
        int l=M[cur->left];
        int r=M[cur->right];
        return l>n/2||r>n/2||l+r+1<=n/2;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[1,2,3,4,5,6,7,8,9,10,11]");
    DBG(root);
    int n=11;
    int x=3;
    auto ans=sol.btreeGameWinningMove(root,n,x);
    DBG(ans);

    system("pause");
    return 0;
}
