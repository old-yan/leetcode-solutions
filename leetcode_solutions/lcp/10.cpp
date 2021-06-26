#include "TreeNode.h"
#include "utils.h"

class Solution {
    typedef pair<double,double> pdd;
    pdd dfs(TreeNode*root){
        if(!root)return {0,0};
        auto [a1,b1]=dfs(root->left);
        auto [a2,b2]=dfs(root->right);
        if(a1>a2){swap(a1,a2),swap(b1,b2);}
        if(a2<=a1+b1){
            return {root->val,a1+a2+b1+b2};
        }
        else{
            return {a2-a1-b1+root->val,a1*2+b1*2+b2};
        }
    }
public:
    double minimalExecTime(TreeNode* root) {
        auto ans=dfs(root);
        return ans.first+ans.second/2;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[1,3,2,null,null,4,4]");
    DBG(root);
    auto ans=sol.minimalExecTime(root);
    DBG(ans);

    system("pause");
    return 0;
}
