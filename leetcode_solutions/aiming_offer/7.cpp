#include "TreeNode.h"
#include "utils.h"

class Solution {
    unordered_map<int,int>M;
    TreeNode*makenode(int h1,int h2,int l,vi&preorder,vi&inorder){
        if(l<=0)return nullptr;
        auto idx=M[preorder[h1]];
        int l1=idx-h2,l2=l-1-l1;
        return new TreeNode(preorder[h1],
            makenode(h1+1,h2,l1,preorder,inorder),
            makenode(h1+l1+1,idx+1,l2,preorder,inorder)
        );
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        REP(i,inorder.size()){
            M[inorder[i]]=i;
        }
        return makenode(0,0,preorder.size(),preorder,inorder);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi preorder{3,9,20,15,7};
    vi inorder{9,3,15,20,7};
    auto ans=sol.buildTree(preorder,inorder);
    DBG(ans);

    system("pause");
    return 0;
}
