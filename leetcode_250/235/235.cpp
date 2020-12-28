#include "utils.h"

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode*s;
        for(s=root;s!=p&&s!=q;){
            if(s->val>p->val&&s->val>q->val)s=s->left;
            else if(s->val<p->val&&s->val<q->val)s=s->right;
            else break;
        }
        return s;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[6,2,8,0,4,7,9,null,null,3,5]");
    DBGT(root);
    TreeNode*p=root->left;
    TreeNode*q=root->right;
    auto ans=sol.lowestCommonAncestor(root,p,q);
    DBGT(ans);

    system("pause");
    return 0;
}
