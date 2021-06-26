#include "LCA.h"
#include "utils.h"

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode*cur=root;
        while(true){
            if(cur->val<p->val&&cur->val<q->val)cur=cur->right;
            else if(cur->val>p->val&&cur->val>q->val)cur=cur->left;
            else return cur;
        }
        return nullptr;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[6,2,8,0,4,7,9,null,null,3,5]");
    DBG(root);
    TreeNode*p=root->left;
    DBG(p);
    TreeNode*q=root->right;
    DBG(q);
    auto ans=sol.lowestCommonAncestor(root,p,q);
    DBG(ans);

    system("pause");
    return 0;
}
