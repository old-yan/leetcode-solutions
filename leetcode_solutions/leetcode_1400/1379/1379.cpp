#include "TreeNode.h"
#include "utils.h"

class Solution {
    TreeNode*ans;
    void traverse(TreeNode*original,TreeNode*cloned,TreeNode*target){
        if(original==target)ans=cloned;
        if(original->left)traverse(original->left,cloned->left,target);
        if(original->right)traverse(original->right,cloned->left,target);
    }
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        traverse(original,cloned,target);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*original=new TreeNode("[7,4,3,null,null,6,19]");
    DBG(original);
    TreeNode*cloned=new TreeNode("[7,4,3,null,null,6,19]");
    DBG(cloned);
    TreeNode*target=original->right;
    DBG(target);
    auto ans=sol.getTargetCopy(original,cloned,target);
    DBG(ans);

    system("pause");
    return 0;
}
