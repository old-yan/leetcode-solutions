#include "TreeNode.h"
#include "utils.h"

class Solution {
    vi adj[501];
    bool visited[501]={0};
    void dfs(TreeNode*cur,int parent){
        if(!cur)return;
        if(parent>=0)adj[cur->val].pb(parent);
        if(cur->left){
            dfs(cur->left,cur->val);
            adj[cur->val].pb(cur->left->val);
        }
        if(cur->right){
            dfs(cur->right,cur->val);
            adj[cur->val].pb(cur->right->val);
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if(!K)return {target->val};
        dfs(root,-1);
        visited[target->val]=true;
        queue<int>Q({target->val});
        int dis=0;
        vi ans;
        while(int l=Q.size()){
            ++dis;
            while(l--){
                auto p=Q.front();
                Q.pop();
                for(int a:adj[p]){
                    if(!visited[a]){
                        if(dis==K)ans.pb(a);
                        visited[a]=true;
                        Q.push(a);
                    }
                }
            }
            if(dis==K)break;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[3,5,1,6,2,0,8,null,null,7,4]");
    DBG(root);
    TreeNode*target=root->left;
    DBG(target);
    int K=2;
    auto ans=sol.distanceK(root,target,K);
    DBGV(ans);

    system("pause");
    return 0;
}
