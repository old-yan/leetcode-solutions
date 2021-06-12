#include "TreeNode.h"
#include "utils.h"

class Solution {
    pair<int,int>traverse(TreeNode*root,int k){
        if(!root)return {0,0};
        auto [rnum,rres]=traverse(root->right,k);
        if(rnum>=k)return {k,rres};
        else if(rnum+1==k)return {k,root->val};
        else{
            auto [lnum,lres]=traverse(root->left,k-rnum-1);
            if(lnum+rnum+1>=k)return {k,lres};
            else return {lnum+rnum+1,0};
        }
    }
public:
    int kthLargest(TreeNode* root, int k) {
        return traverse(root,k).second;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[5,3,6,2,4,null,null,1]");
    DBG(root);
    int k=3;
    auto ans=sol.kthLargest(root,k);
    DBG(ans);

    system("pause");
    return 0;
}
