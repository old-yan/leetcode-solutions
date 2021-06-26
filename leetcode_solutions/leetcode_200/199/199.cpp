#include "utils.h"

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vi ans;
        queue<TreeNode*>Q;
        if(root)Q.push(root);
        while(Q.size()){
            ans.pb(Q.front()->val);
            int l=Q.size();
            while(l--){
                auto a=Q.front();
                Q.pop();
                if(a->right)Q.push(a->right);
                if(a->left)Q.push(a->left);
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("1,2,3,null,5,null,4");
    auto ans=sol.rightSideView(root);
    DBGV(ans);

    system("pause");
    return 0;
}
