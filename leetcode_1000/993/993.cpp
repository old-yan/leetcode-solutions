#include "TreeNode.h"
#include "utils.h"

class Solution {
    int depthx,depthy;
    int parentx,parenty;
    void dfs(TreeNode*root,int p,int d,int x,int y){
        if(root->val==x){
            depthx=d;
            parentx=p;
        }
        else if(root->val==y){
            depthy=d;
            parenty=p;
        }
        if(root->left)dfs(root->left,root->val,d+1,x,y);
        if(root->right)dfs(root->right,root->val,d+1,x,y);
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root,0,0,x,y);
        return depthx==depthy&&parentx!=parenty;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[1,2,3,4]");
    DBGT(root);
    auto ans=sol.isCousins(root);
    DBG(ans);

    system("pause");
    return 0;
}
