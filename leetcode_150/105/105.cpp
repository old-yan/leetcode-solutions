#include "utils.h"

class Solution {
    unordered_map<int,int>M;
    vi preorder,inorder;
    TreeNode*fun(int i1,int i2,int l){
        if(!l)return nullptr;
        TreeNode*p=new TreeNode(preorder[i1]);
        int i=M[preorder[i1]];
        int l1=i-i2;
        int l2=l-1-l1;
        p->left=fun(i1+1,i2,l1);
        p->right=fun(i1+1+l1,i+1,l2);
        return p;
    }
public:
    TreeNode* buildTree(vector<int>&_preorder, vector<int>&_inorder) {
        preorder=_preorder;
        inorder=_inorder;
        REP(i,inorder.size()){
            M[inorder[i]]=i;
        }
        return fun(0,0,preorder.size());
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi preorder{3,9,20,15,7};
    vi inorder{9,3,15,20,7};
    auto ans=sol.buildTree(preorder,inorder);
    DBGT(ans);

    system("pause");
    return 0;
}
