#include "TreeNode.h"
#include "utils.h"

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>Q;
        if(root)Q.push(root);
        vvi ans;
        bool reverse=true;
        while(int l=Q.size()){
            reverse=!reverse;
            ans.pb({});
            while(l--){
                auto p=Q.front();
                Q.pop();
                ans.back().pb(p->val);
                if(p->left)Q.push(p->left);
                if(p->right)Q.push(p->right);
            }
            if(reverse)::reverse(ALL(ans.back()));
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[3,9,20,null,null,15,7]");
    DBG(root);
    auto ans=sol.levelOrder(root);
    DBGVV(ans);

    system("pause");
    return 0;
}
