#include "utils.h"

class Solution {
    ll last=LLONG_MIN;
    int count=0;
    vi ans;
    int maxcount=0;
    void inordertraverse(TreeNode*root){
        if(root->left)inordertraverse(root->left);
        if(last==root->val){
            count++;
        }
        else{
            last=root->val;
            count=1;
        }
        if(count>maxcount){
            maxcount=count;
            ans={root->val};
        }
        else if(count==maxcount){
            ans.pb(root->val);
        }
        if(root->right)inordertraverse(root->right);
    }
public:
    vector<int> findMode(TreeNode* root) {
        if(root)inordertraverse(root);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("1,null,2,2");
    DBGT(root);
    auto ans=sol.findMode(root);
    DBGV(ans);

    system("pause");
    return 0;
}
