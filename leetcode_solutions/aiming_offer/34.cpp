#include "TreeNode.h"
#include "utils.h"

class Solution {
    vvi ans;
    void dfs(TreeNode*root,int rest,vi&path){
        path.pb(root->val);
        rest-=root->val;
        if(!root->left&&!root->right){
            if(!rest)ans.pb(path);
        }
        else{
            if(root->left)dfs(root->left,rest,path);
            if(root->right)dfs(root->right,rest,path);
        }
        path.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vi path;
        if(root)dfs(root,target,path);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[5,4,8,11,null,13,4,7,2,null,null,5,1]");
    DBG(root);
    int target=22;
    auto ans=sol.pathSum(root,target);
    DBGVV(ans);

    system("pause");
    return 0;
}
