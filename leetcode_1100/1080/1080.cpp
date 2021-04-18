#include "TreeNode.h"
#include "utils.h"

class Solution {
    bool search(TreeNode*&cur, int limit){
        if(!cur)return false;
        else if(!cur->left&&!cur->right){
            bool res=cur->val>=limit;
            if(!res)cur=nullptr;
            return res;
        }
        else{
            bool b1=search(cur->left,limit-cur->val);
            bool b2=search(cur->right,limit-cur->val);
            if(!b1&&!b2)cur=nullptr;
            return b1||b2;
        }
    }
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        search(root,limit);
        return root;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[1,2,3,4,-99,-99,7,8,9,-99,-99,12,13,-99,14]");
    DBG(root);
    int limit=1;
    auto ans=sol.sufficientSubset(root,limit);
    DBG(ans);

    system("pause");
    return 0;
}
