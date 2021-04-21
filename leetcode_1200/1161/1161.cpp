#include "TreeNode.h"
#include "utils.h"

class Solution {
    ll cnt[10000]={0};
    int ans=1;
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>Q;
        Q.push(root);
        int d=1;
        while(int l=Q.size()){
            while(l--){
                auto p=Q.front();
                Q.pop();
                cnt[d]+=p->val;
                if(p->left)Q.push(p->left);
                if(p->right)Q.push(p->right);
            }
            if(cnt[d]>cnt[ans])ans=d;
            d++;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("1,7,0,7,-8,null,null");
    DBG(root);
    auto ans=sol.maxLevelSum(root);
    DBG(ans);

    system("pause");
    return 0;
}
