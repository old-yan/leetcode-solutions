#include "TreeNode.h"
#include "utils.h"

class Solution {
    int Min=0,Max=0;
    void dfs(TreeNode*root,int col){
        chmin(Min,col);
        chmax(Max,col);
        if(root->left)dfs(root->left,col-1);
        if(root->right)dfs(root->right,col+1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root,0);
        vvi ans(Max-Min+1);
        queue<tuple<int,int,TreeNode*>>Q;
        Q.emplace(root->val,-Min,root);
        while(int l=Q.size()){
            vector<pair<int,int>>cache;
            while(l--){
                auto [val,col,p]=Q.front();
                Q.pop();
                cache.emplace_back(col,val);
                if(p->left)Q.emplace(p->left->val,col-1,p->left);
                if(p->right)Q.emplace(p->right->val,col+1,p->right);
            }
            sort(ALL(cache));
            for(auto [col,val]:cache)ans[col].pb(val);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[3,9,20,null,null,15,7]");
    DBGT(root);
    auto ans=sol.verticalTraversal(root);
    DBGVV(ans);

    system("pause");
    return 0;
}
