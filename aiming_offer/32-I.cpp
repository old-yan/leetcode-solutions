#include "TreeNode.h"
#include "utils.h"

class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        queue<TreeNode*>Q;
        if(root)Q.push(root);
        vi ans;
        while(Q.size()){
            auto p=Q.front();
            Q.pop();
            ans.pb(p->val);
            if(p->left)Q.push(p->left);
            if(p->right)Q.push(p->right);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[3,9,20,null,null,15,7]");
    DBG(root);
    auto ans=sol.levelOrder(root);
    DBGV(ans);

    system("pause");
    return 0;
}
