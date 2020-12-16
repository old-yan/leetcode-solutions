#include "utils.h"

class Solution {
    pair<ll,ll>fun(TreeNode*p){
        pair<ll,ll>a=make_pair(INT_MIN,INT_MIN);
        pair<ll,ll>b=make_pair(INT_MIN,INT_MIN);
        if(p->left){
            a=fun(p->left);
        }
        if(p->right){
            b=fun(p->right);
        }
        ll l1=INT_MIN,l2=INT_MIN;
        l2=max((ll)p->val,p->val+max(a.second,b.second));
        l1=max(max(l2,a.second+b.second+p->val),max(a.first,b.first));
        return make_pair(l1,l2);
    }
public:
    int maxPathSum(TreeNode* root) {
        return fun(root).first;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=maketreenode("-10,9,20,null,null,15,7");
    DBGT(root);
    auto ans=sol.maxPathSum(root);
    DBG(ans);

    system("pause");
    return 0;
}
