#include "TreeNode.h"
#include "utils.h"

class Solution {
    void traverse(TreeNode*root,vi&v){
        if(!root)return;
        v.pb(root->val);
        traverse(root->left,v);
        traverse(root->right,v);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vi v1,v2;
        traverse(root1,v1);
        traverse(root2,v2);
        return v1==v2;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root1=new TreeNode("[3,5,1,6,2,9,8,null,null,7,4]");
    DBGT(root1);
    TreeNode*root2=new TreeNode("[3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]");
    DBGT(root2);
    auto ans=sol.leafSimilar(root1,root2);
    DBG(ans);

    system("pause");
    return 0;
}
