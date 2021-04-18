#include "TreeNode.h"
#include "utils.h"

class Solution {
    int ans=0;
    pair<int,int>dfs(TreeNode*root){
        int Min=root->val,Max=root->val;
        if(root->left){
            auto l=dfs(root->left);
            chmin(Min,l.first);
            chmax(Max,l.second);
        }
        if(root->right){
            auto r=dfs(root->right);
            chmin(Min,r.first);
            chmax(Max,r.second);
        }
        chmax(ans,abs(root->val-Min));
        chmax(ans,abs(Max-root->val));
        return {Min,Max};
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        dfs(root);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[8,3,10,1,6,null,14,null,null,4,7,13]");
    DBG(root);
    auto ans=sol.maxAncestorDiff(root);
    DBG(ans);

    system("pause");
    return 0;
}
