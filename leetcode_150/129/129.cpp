#include "TreeNode.h"
#include "utils.h"

class Solution {
    int ans=0;
    void dfs(TreeNode*p,int val){
        val=val*10+p->val;
        if(!p->left&&!p->right){
            ans+=val;
        }
        else{
            if(p->left)dfs(p->left,val);
            if(p->right)dfs(p->right,val);
        }
    }
public:
    int sumNumbers(TreeNode* root) {
        if(root)dfs(root,0);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("4,9,0,5,1");
    DBG(root);
    auto ans=sol.sumNumbers(root);
    DBG(ans);

    system("pause");
    return 0;
}
