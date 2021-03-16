#include "TreeNode.h"
#include "utils.h"

class Solution {
    int maxdepth=0,maxdepth_num;
    TreeNode*ans=nullptr;
    void traverse(TreeNode*root,int depth){
        if(!root)return;
        if(chmax(maxdepth,depth)){
            maxdepth_num=1;
        }
        else if(maxdepth==depth)maxdepth_num++;
        traverse(root->left,depth+1);
        traverse(root->right,depth+1);
    }
    int gather(TreeNode*root,int depth){
        if(!root)return 0;
        int cur=depth==maxdepth;
        int l=gather(root->left,depth+1);
        int r=gather(root->right,depth+1);
        if(cur+l+r==maxdepth_num&&!ans){
            ans=root;
        }
        return cur+l+r;
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        traverse(root,1);
        gather(root,1);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[3,5,1,6,2,0,8,null,null,7,4]");
    DBGT(root);
    auto ans=sol.subtreeWithAllDeepest(root);
    DBGT(ans);

    system("pause");
    return 0;
}
