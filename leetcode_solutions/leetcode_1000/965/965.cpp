#include "TreeNode.h"
#include "utils.h"

class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        queue<TreeNode*>Q({root});
        while(Q.size()){
            auto p=Q.front();
            Q.pop();
            if(p->val!=root->val)return false;
            if(p->left)Q.push(p->left);
            if(p->right)Q.push(p->right);
        }
        return true;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[1,1,1,1,1,null,1]");
    DBG(root);
    auto ans=sol.isUnivalTree(root);
    DBG(ans);

    system("pause");
    return 0;
}
