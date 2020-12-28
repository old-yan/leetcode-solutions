#include "utils.h"

class Solution {
    TreeNode*ans=nullptr;
    int p,q;
    pair<bool,bool>fun(TreeNode*root){
        if(!root)return make_pair(false,false);
        auto a=fun(root->left);
        auto b=fun(root->right);
        auto c=make_pair(a.first||b.first||root->val==p,a.second||b.second||root->val==q);
        if(c.first&&c.second&&!ans)ans=root;
        return c;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode*_p, TreeNode*_q) {
        p=_p->val;
        q=_q->val;
        fun(root);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[3,5,1,6,2,0,8,null,null,7,4]");
    DBGT(root);
    TreeNode*p=root->left;
    TreeNode*q=root->right;
    auto ans=sol.lowestCommonAncestor(root,p,q);
    DBGT(ans);

    system("pause");
    return 0;
}
