#include "TreeNode.h"
#include "utils.h"

class Solution {
    bool check(TreeNode*s,TreeNode*p){
        if(!p)return true;
        else{
            if(!s||p->val!=s->val)return false;
            return check(s->left,p->left)&&check(s->right,p->right);
        }
    }
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        return A&&B&&(check(A,B)||isSubStructure(A->left,B)||isSubStructure(A->right,B));
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*A=new TreeNode("[3,4,5,1,2]");
    DBG(A);
    TreeNode*B=new TreeNode("[4,1]");
    DBG(B);
    auto ans=sol.isSubStructure(A,B);
    DBG(ans);


    system("pause");
    return 0;
}
