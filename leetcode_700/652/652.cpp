#include "utils.h"

class Solution {
    unordered_map<TreeNode*,int>findID={{nullptr,0}};
    unordered_map<long,int>feature_table;
    TreeNode* nodelist[6000]={0};
    int parent[6000]={0};
    int val[6000]={0};
    int left[6000]={0};
    int right[6000]={0};
    int deg[6000]={0};
    int dfs(TreeNode*root){
        if(!root)return 0;
        int i=findID[root]=findID.size();
        nodelist[i]=root;
        int il=dfs(root->left);
        int ir=dfs(root->right);
        parent[il]=parent[ir]=i;
        val[i]=root->val;
        left[i]=il;
        right[i]=ir;
        if(il)deg[i]++;
        if(ir)deg[i]++;
        return i;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*>ans;
        dfs(root);
        Union u(findID.size());
        queue<int>Q;
        for(int i=1;i<findID.size();i++)if(!deg[i])Q.push(i);
        while(Q.size()){
            auto p=Q.front();
            Q.pop();
            long il=u.Find(left[p]);
            long ir=u.Find(right[p]);
            long feature=long(val[p]+1000)*100000000+il*10000+ir;
            if(feature_table.count(feature)){
                u.unite(feature_table[feature],p);
            }
            else feature_table[feature]=p;
            if(!--deg[parent[p]]){
                Q.push(parent[p]);
            }
        }
        for(int i=1;i<findID.size();i++){
            if(u.Find(i)==i&&u.size[i]>1)ans.emplace_back(nodelist[i]);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[1,2,3,4,null,2,4,null,null,4]");
    DBGT(root);
    auto ans=sol.findDuplicateSubtrees(root);
    DBGV(ans);

    system("pause");
    return 0;
}
