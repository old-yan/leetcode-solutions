#include "utils.h"

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vi ans;
        queue<TreeNode*>Q;
        if(root)Q.push(root);
        while(int l=Q.size()){
            ans.pb(INT_MIN);
            while(l--){
                auto p=Q.front();
                Q.pop();
                chmax(ans.back(),p->val);
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

    TreeNode*root=new TreeNode("[1,3,2,5,3,null,9]");
    auto ans=sol.largestValues(root);
    DBGV(ans);

    system("pause");
    return 0;
}
