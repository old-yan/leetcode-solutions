#include "utils.h"

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode*p=root;
        vi ans;
        while(p){
            if(p->left){
                TreeNode*q;
                for(q=p->left;q->right&&q->right!=p;q=q->right);
                if(!q->right){
                    q->right=p;
                    ans.pb(p->val);
                    p=p->left;
                }
                else{
                    q->right=nullptr;
                    p=p->right;
                }
            }
            else{
                ans.pb(p->val);
                p=p->right;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("1,null,2,3");
    DBGT(root);
    auto ans=sol.preorderTraversal(root);
    DBGV(ans);

    system("pause");
    return 0;
}
