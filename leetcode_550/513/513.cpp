#include "utils.h"

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*>Q;
        Q.push(root);
        int ans;
        while(int l=Q.size()){
            ans=Q.front()->val;
            while(l--){
                auto p=Q.front();
                Q.pop();
                if(p->left)Q.push(p->left);
                if(p->right)Q.push(p->right);
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[2,1,3]");
    DBGT(root);
    auto ans=sol.findBottomLeftValue(root);
    DBG(ans);

    system("pause");
    return 0;
}
