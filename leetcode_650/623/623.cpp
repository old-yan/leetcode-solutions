#include "utils.h"

class Solution {
    void fun(TreeNode*p,int curd,int v,int d){
        if(curd+1==d){
            p->left=new TreeNode(v,p->left,nullptr);
            p->right=new TreeNode(v,nullptr,p->right);
        }
        else{
            if(p->left)fun(p->left,curd+1,v,d);
            if(p->right)fun(p->right,curd+1,v,d);
        }
    }
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d==1){
            return new TreeNode(v,root,nullptr);
        }
        if(root)fun(root,1,v,d);
        return root;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[4,2,6,3,1,5]");
    DBGT(root);
    int v=1;
    int d=2;
    auto ans=sol.addOneRow(root,v,d);
    DBGT(ans);

    system("pause");
    return 0;
}
