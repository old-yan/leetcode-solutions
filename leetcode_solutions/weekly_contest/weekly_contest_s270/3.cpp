#include "TreeNode.h"
#include "utils.h"

class Solution {
    vector<pair<int,char>>adj[100001];
    void dfs(TreeNode*cur){
        if(cur->left){
            adj[cur->val].emplace_back(cur->left->val,'L');
            adj[cur->left->val].emplace_back(cur->val,'U');
            dfs(cur->left);
        }
        if(cur->right){
            adj[cur->val].emplace_back(cur->right->val,'R');
            adj[cur->right->val].emplace_back(cur->val,'U');
            dfs(cur->right);
        }
    }
public:
    //显然本题只要找到一条最短路就可以了。无权图的最短路要使用 bfs
    string getDirections(TreeNode* root, int startValue, int destValue) {
        //先 dfs 一次整棵树，以父子关系作为边，建立有向图
        dfs(root);
        //bfs
        queue<int>Q;
        // dist 记录最短距离
        vector<int>dist(100001,INT_MAX);
        // prev 记录最短路的前驱结点，以及从前趋到当前位置所花费的字母
        vector<pair<int,char>>prev(100001,{-1,' '});
        dist[startValue]=0;
        Q.push(startValue);
        while(Q.size()){
            auto p=Q.front();
            Q.pop();
            for(auto [a,c]:adj[p]){
                if(dist[a]>dist[p]+1){
                    dist[a]=dist[p]+1;
                    prev[a]={p,c};
                    Q.push(a);
                }
            }
        }
        //此时我们可以从 destValue 结点不断回溯前趋，一直回溯到 startValue 结点
        int x=destValue;
        string path;
        while(x!=startValue){
            path+=prev[x].second;
            x=prev[x].first;
        }
        //记得获得的路径是从 dest 到 start 的，要翻转一下
        reverse(ALL(path));
        return path;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("5,1,2,3,null,6,4");
    int startValue=3;
    int destValue=6;
    auto ans=sol.getDirections(root,startValue,destValue);
    DBG(ans);

    system("pause");
    return 0;
}