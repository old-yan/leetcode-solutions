#include "utils.h"

class Solution {
    pair<TreeNode*,TreeNode*>fun(TreeNode*p){
        TreeNode*right=p->right;
        if(p->left){
            auto a=fun(p->left);
            p->left=nullptr;
            p->right=a.first;
            a.second->right=right;
            if(right)return make_pair(p,fun(right).second);
            else return make_pair(p,a.second);
        }
        else{
            if(right)return make_pair(p,fun(right).second);
            else return make_pair(p,p);
        }
    }
public:
    void flatten(TreeNode* root) {
        if(root)fun(root).second->right=nullptr;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("1,2,5,3,4,null,6");
    DBGT(root);
    sol.flatten(root);
    DBGT(root);

    system("pause");
    return 0;
}