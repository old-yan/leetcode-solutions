#include "TreeNode.h"
#include "utils.h"

class Solution {
    tuple<int,int,int>fun(TreeNode*root){
        if(!root){
            return {0x3f3f3f3f,0,0};
        }
        auto [a1,b1,c1]=fun(root->left);
        auto [a2,b2,c2]=fun(root->right);
        int a=1+c1+c2;
        int b=min(a,min(a1+b2,a2+b1));
        int c=min(b,b1+b2);
        return {a,b,c};
    }
public:
    int minCameraCover(TreeNode* root) {
        return get<1>(fun(root));
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[0,null,0,null,0,null,0,null,0,0,0,null,null,0,0]");
    DBG(root);
    auto ans=sol.minCameraCover(root);
    DBG(ans);

    system("pause");
    return 0;
}
