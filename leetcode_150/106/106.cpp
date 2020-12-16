#include "utils.h"

class Solution {
    vi inorder,postorder;
    unordered_map<int,int>M;
    TreeNode*fun(int i1,int i2,int l){
        if(!l)return nullptr;
        TreeNode*p=new TreeNode(postorder[i2+l-1]);
        int i=M[postorder[i2+l-1]];
        int l1=i-i1;
        int l2=l-1-l1;
        p->left=fun(i1,i2,l1);
        p->right=fun(i+1,i2+l1,l2);
        return p;
    }
public:
    TreeNode* buildTree(vector<int>&_inorder, vector<int>&_postorder) {
        inorder=_inorder;
        postorder=_postorder;
        REP(i,inorder.size()){
            M[inorder[i]]=i;
        }
        return fun(0,0,inorder.size());
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi inorder{9,3,15,20,7};
    vi postorder{9,15,7,20,3};
    auto ans=sol.buildTree(inorder,postorder);
    DBGT(ans);

    system("pause");
    return 0;
}
