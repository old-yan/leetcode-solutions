#include "TreeNode.h"
#include "utils.h"

class Solution {
    vi ans;
    void traverse(TreeNode*root){
        if(root->left)traverse(root->left);
        ans.pb(root->val);
        if(root->right)traverse(root->right);
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        if(root1)traverse(root1);
        auto mid=ans.size();
        if(root2)traverse(root2);
        inplace_merge(ans.begin(),ans.begin()+mid,ans.end());
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root1=new TreeNode("[2,1,4]");
    DBG(root1);
    TreeNode*root2=new TreeNode("[1,0,3]");
    DBG(root2);
    auto ans=sol.getAllElements(root1,root2);
    DBGV(ans);

    system("pause");
    return 0;
}
