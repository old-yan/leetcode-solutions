#include "utils.h"

class Solution {
    int sum;
    int ans=0;
    void dfs(TreeNode*root, vi&targets){
        targets.pb(sum);
        for(int&a:targets){
            a-=root->val;
            if(!a)ans++;
        }
        if(root->left){
            dfs(root->left,targets);
        }
        if(root->right){
            dfs(root->right,targets);
        }
        targets.pop_back();
        for(int&a:targets){
            a+=root->val;
        }
    }
public:
    int pathSum(TreeNode* root, int _sum) {
        sum=_sum;
        vi targets;
        if(root)dfs(root,targets);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("10,5,-3,3,2,null,11,3,-2,null,1");
    DBGT(root);
    int sum=8;
    auto ans=sol.pathSum(root,sum);
    DBG(ans);

    system("pause");
    return 0;
}
