#include "TreeNode.h"
#include "utils.h"

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*>Q;
        Q.push(root);
        vector<double>ans;
        while(int l=Q.size()){
            double cnt=0;
            REP(i,l){
                auto p=Q.front();
                Q.pop();
                cnt+=p->val;
                if(p->left)Q.push(p->left);
                if(p->right)Q.push(p->right);
            }
            ans.pb(cnt/l);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[3,9,20,15,7]");
    DBG(root);
    auto ans=sol.averageOfLevels(root);
    DBGV(ans);

    system("pause");
    return 0;
}
