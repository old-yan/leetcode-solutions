#include "TreeNode.h"
#include "utils.h"

class Solution {
    struct node{
        int num[11]={0};
    };
    int ans=0,k;
    node traverse(TreeNode*root){
        if(!root)return node();
        else{
            auto l=traverse(root->left);
            auto r=traverse(root->right);
            auto res=node();
            REP(i,k+1)REP(j,k+1){
                if(i+j+1<=k){
                    chmax(res.num[i+j+1],l.num[i]+r.num[j]+root->val);
                }
            }
            chmax(res.num[0],*max_element(l.num,l.num+k+1)+*max_element(r.num,r.num+k+1));
            return res;
        }
    }
public:
    int maxValue(TreeNode* root, int _k) {
        k=_k;
        auto res=traverse(root);
        return *max_element(res.num,res.num+k+1);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[5,2,3,4]");
    DBG(root);
    int k=2;
    auto ans=sol.maxValue(root,k);
    DBG(ans);

    system("pause");
    return 0;
}
