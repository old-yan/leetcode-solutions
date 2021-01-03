#include "utils.h"

class Solution {
    pair<int,int>fun(TreeNode*root){
        if(!root)return make_pair(0,0);
        else{
            auto p1=fun(root->left);
            auto p2=fun(root->right);
            return make_pair(max(p1.first,p1.second)+max(p2.first,p2.second),root->val+p1.first+p2.first);
        }
    }
public:
    int rob(TreeNode* root) {
        auto p=fun(root);
        return max(p.first,p.second);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("3,4,5,1,3,null,1");
    DBGT(root);
    auto ans=sol.rob(root);
    DBG(ans);

    system("pause");
    return 0;
}
