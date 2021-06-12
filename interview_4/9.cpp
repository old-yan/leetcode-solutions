#include "TreeNode.h"
#include "utils.h"

class Solution {
public:
    vector<vector<int>> BSTSequences(TreeNode* root) {
        
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[2,1,3]");
    DBG(root);
    auto ans=sol.BSTSequences(root);
    DBGVV(ans);

    system("pause");
    return 0;
}
