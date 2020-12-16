#include "utils.h"

class Solution {
    int path[1000];
    vvi ans;
    void fun(TreeNode*p,int idx,int rest){
        path[idx++]=p->val;
        rest-=p->val;
        if(!p->left&&!p->right){
            if(!rest)ans.pb(vi(path,path+idx));
        }
        else{
            if(p->left)fun(p->left,idx,rest);
            if(p->right)fun(p->right,idx,rest);
        }
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root)fun(root,0,sum);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=maketreenode("5,4,8,11,null,13,4,7,2,null,null,5,1");
    DBGT(root);
    auto ans=sol.pathSum(root,22);
    DBGVV(ans);

    system("pause");
    return 0;
}
