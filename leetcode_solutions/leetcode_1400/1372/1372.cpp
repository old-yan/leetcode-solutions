#include "TreeNode.h"
#include "utils.h"

class Solution {
    int ans=0;
    void traverse(TreeNode*root,int toleft,int toright){
        chmax(ans,max(toleft,toright));
        if(root->left){
            traverse(root->left,toright+1,0);
        }
        if(root->right){
            traverse(root->right,0,toleft+1);
        }
    }
public:
    int longestZigZag(TreeNode* root) {
        traverse(root,0,0);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[1,null,1,1,1,null,null,1,1,null,1,null,null,null,1,null,1]");
    DBG(root);
    auto ans=sol.longestZigZag(root);
    DBG(ans);

    system("pause");
    return 0;
}
