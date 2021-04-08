#include "TreeNode.h"
#include "utils.h"

class Solution {
    pair<int,int>fun(TreeNode*root){//first表示盈亏，second表示净化步数
        if(!root)return {0,0};
        auto a=fun(root->left);
        auto b=fun(root->right);
        return {a.first+b.first+root->val-1,a.second+b.second+abs(a.first+b.first+root->val-1)};
    }
public:
    int distributeCoins(TreeNode* root) {
        return fun(root).second;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[3,0,0]");
    DBGT(root);
    auto ans=sol.distributeCoins(root);
    DBG(ans);

    system("pause");
    return 0;
}
