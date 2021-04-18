#include "TreeNode.h"
#include "utils.h"

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode*p=root;
        vi ans;
        while(p){
            if(p->right){
                TreeNode*q;
                for(q=p->right;q->left&&q->left!=p;q=q->left);
                if(!q->left){
                    q->left=p;
                    ans.pb(p->val);
                    p=p->right;
                }
                else{
                    q->left=nullptr;
                    p=p->left;
                }
            }
            else{
                ans.pb(p->val);
                p=p->left;
            }
        }
        reverse(ALL(ans));
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("1,null,2,3");
    DBG(root);
    auto ans=sol.postorderTraversal(root);
    DBGV(ans);

    system("pause");
    return 0;
}
