#include "TreeNode.h"
#include "utils.h"

class Solution {
    vector<TreeNode*>v;
    void inordertraverse(TreeNode*root){
        if(!root)return;
        inordertraverse(root->left);
        v.pb(root);
        inordertraverse(root->right);
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        inordertraverse(root);
        v.pb(nullptr);
        REP(i,v.size()-1){
            v[i]->left=nullptr;
            v[i]->right=v[i+1];
        }
        return v[0];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[5,3,6,2,4,null,8,1,null,null,null,7,9]");
    DBGT(root);
    auto ans=sol.increasingBST(root);
    DBGT(ans);

    system("pause");
    return 0;
}
