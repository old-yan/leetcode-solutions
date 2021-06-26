#include "TreeNode.h"
#include "utils.h"

class Solution {
    pair<bool,int>fun(TreeNode*p){
        if(!p)return make_pair(true,0);
        auto a=fun(p->left);
        auto b=fun(p->right);
        return make_pair(a.first&&b.first&&abs(a.second-b.second)<=1,max(a.second,b.second)+1);
    }
public:
    bool isBalanced(TreeNode* root) {
        return fun(root).first;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("1,2,2,3,3,null,null,4,4");
    DBG(root);
    auto ans=sol.isBalanced(root);
    DBG(ans);

    system("pause");
    return 0;
}
