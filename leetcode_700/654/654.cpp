#include "TreeNode.h"
#include "utils.h"

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>&nums) {
        stack<TreeNode*>S;
        TreeNode*dummy=new TreeNode(INT_MAX);
        S.push(dummy);
        for(int a:nums){
            TreeNode*p=new TreeNode(a);
            while(S.top()->val<a){
                p->left=S.top();
                S.pop();
            }
            S.top()->right=p;
            S.push(p);
        }
        return dummy->right;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{3,2,1,6,0,5};
    auto ans=sol.constructMaximumBinaryTree(nums);
    DBGT(ans);

    system("pause");
    return 0;
}
