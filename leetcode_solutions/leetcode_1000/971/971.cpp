#include "TreeNode.h"
#include "utils.h"

class Solution {
    unordered_map<int,int>M;
    vi ans;
    bool dfs(TreeNode*root,int begin,int end){
        if(begin>=end)return false;
        if(M[root->val]!=begin)return false;
        if(!root->left&&!root->right)return begin+1==end;
        if(root->left&&root->right){
            int l=M[root->left->val],r=M[root->right->val];
            if(l==begin+1){
                return dfs(root->left,l,r)&&dfs(root->right,r,end);
            }
            else if(r==begin+1){
                ans.pb(root->val);
                return dfs(root->left,l,end)&&dfs(root->right,r,l);
            }
            else return false;
        }
        else if(root->left){
            return M[root->left->val]==begin+1&&dfs(root->left,begin+1,end);
        }
        else{
            return M[root->right->val]==begin+1&&dfs(root->right,begin+1,end);
        }
    }
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        REP(i,voyage.size()){
            M[voyage[i]]=i;
        }
        if(dfs(root,0,voyage.size()))return ans;
        else return {-1};
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[1,2]");
    vi voyage{2,1};
    auto ans=sol.flipMatchVoyage(root,voyage);
    DBGV(ans);

    system("pause");
    return 0;
}
