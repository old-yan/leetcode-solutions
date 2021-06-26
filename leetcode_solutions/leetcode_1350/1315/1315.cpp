#include "TreeNode.h"
#include "utils.h"

class Solution {
    int ans=0;
    void traverse(TreeNode*root,bool father,bool grandpa){
        if(grandpa)ans+=root->val;
        grandpa=father;
        father=root->val%2==0;
        if(root->left)traverse(root->left,father,grandpa);
        if(root->right)traverse(root->right,father,grandpa);
    }
public:
    int sumEvenGrandparent(TreeNode* root) {
        traverse(root,false,false);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]");
    DBG(root);
    auto ans=sol.sumEvenGrandparent(root);
    DBG(ans);

    system("pause");
    return 0;
}
