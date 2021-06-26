#include "TreeNode.h"
#include "utils.h"

class Solution {
    vi v;
    int cursor;
    int target;
    bool dfs(TreeNode*root){
        if(!root)return false;
        if(dfs(root->left))return true;
        if(root->val<target/2)v.pb(root->val);
        else{
            if(v.size()){
                if(root->val*2==target){
                    if(v.back()==root->val)return true;
                }
                else{
                    if(cursor<0)cursor=v.size()-1;
                    while(cursor>=0&&v[cursor]+root->val>target)cursor--;
                    if(cursor<0)return false;
                    if(v[cursor]+root->val==target)return true;
                }
            }
            v.pb(root->val);
        }
        return dfs(root->right);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        target=k;
        cursor=-1;
        return dfs(root);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[1,0,4,-2,null,3]");
    DBG(root);
    int k=7;
    auto ans=sol.findTarget(root,k);
    DBG(ans);

    system("pause");
    return 0;
}
