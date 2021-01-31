#include "utils.h"

class Solution {
public:
    string tree2str(TreeNode* t) {
        if(!t)return "";
        string left=tree2str(t->left);
        string right=tree2str(t->right);
        if(t->left){
            if(t->right)return i2s(t->val)+"("+left+")("+right+")";
            else return i2s(t->val)+"("+left+")";
        }
        else{
            if(t->right)return i2s(t->val)+"()("+right+")";
            else return i2s(t->val);
        }
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[1,2,3,null,4]");
    DBGT(root);
    auto ans=sol.tree2str(root);
    DBG(ans);

    system("pause");
    return 0;
}
