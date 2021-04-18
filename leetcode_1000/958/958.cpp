#include "TreeNode.h"
#include "utils.h"

class Solution {
    int cnt=0,Max=0;
    void traverse(TreeNode*root,int idx){
        if(!root)return;
        chmax(Max,idx);
        cnt++;
        traverse(root->left,min(idx*2,1000000));
        traverse(root->right,min(idx*2+1,1000000));
    }
public:
    bool isCompleteTree(TreeNode* root) {
        traverse(root,1);
        return Max==cnt;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[1,2,3,4,5,6]");
    DBG(root);
    auto ans=sol.isCompleteTree(root);
    DBG(ans);

    system("pause");
    return 0;
}
