#include "utils.h"

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p||!q)return !p&&!q;
        return p->val==q->val&&isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*p=new TreeNode("1,2,3");
    DBGT(p);
    TreeNode*q=new TreeNode("1,2,3");
    DBGT(q);
    auto ans=sol.isSameTree(p,q);
    DBG(ans);

    system("pause");
    return 0;
}
