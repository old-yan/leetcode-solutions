#include "LCA.h"
#include "utils.h"

class Solution {
    int maxd;
    vector<TreeNode*>v;
    void traverse(TreeNode*root,int d){
        if(d==maxd)v.pb(root);
        else{
            if(root->left)traverse(root->left,d+1);
            if(root->right)traverse(root->right,d+1);
        }
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        LCA lca(root);
        maxd=lca.getDepth();
        traverse(root,1);
        auto ans=v[0];
        FOR(i,1,v.size()){
            ans=lca.getlca(ans,v[i]);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[0,1,3,null,2]");
    DBG(root);
    auto ans=sol.lcaDeepestLeaves(root);
    DBG(ans);

    system("pause");
    return 0;
}
