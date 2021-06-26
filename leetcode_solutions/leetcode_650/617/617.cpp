#include "TreeNode.h"
#include "utils.h"

class Solution {
    TreeNode*merge(TreeNode* t1, TreeNode* t2){
        if(!t1)return t2;
        if(!t2)return t1;
        t1->val+=t2->val;
        t1->left=merge(t1->left,t2->left);
        t1->right=merge(t1->right,t2->right);
        return t1;
    }
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        return merge(t1,t2);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*t1=new TreeNode("[1,3,2,5]");
    DBG(t1);
    TreeNode*t2=new TreeNode("[2,1,3,null,4,null,7]");
    DBG(t2);
    auto ans=sol.mergeTrees(t1,t2);
    DBG(ans);

    system("pause");
    return 0;
}
