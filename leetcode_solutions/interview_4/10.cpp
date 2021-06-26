#include "TreeNode.h"
#include "Union.h"
#include "utils.h"

class Solution {
    bool check(TreeNode*t1,TreeNode*t2){
        return t1==t2||(t1->val==t2->val&&check(t1->left,t2->left)&&check(t1->right,t2->right));
    }
public:
    bool checkSubTree(TreeNode* t1, TreeNode* t2) {
        if(!t1&&t2)return false;
        else return check(t1,t2)||checkSubTree(t1->left,t2)||checkSubTree(t1->right,t2);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*t1=new TreeNode("1,2,3");
    DBG(t1);
    TreeNode*t2=new TreeNode("2");
    DBG(t2);
    auto ans=sol.checkSubTree(t1,t2);
    DBG(ans);

    system("pause");
    return 0;
}
