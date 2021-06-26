#include "utils.h"

class Solution {
    string tree2str(TreeNode*root){
        return root?"{"+i2s(root->val)+tree2str(root->left)+tree2str(root->right)+"}":"{}";
    }
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        return int(tree2str(s).find(tree2str(t)))>=0;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*s=new TreeNode("[3,4,5,1,2]");
    TreeNode*t=new TreeNode("[4,1,2]");
    auto ans=sol.isSubtree(s,t);
    DBG(ans);

    system("pause");
    return 0;
}
