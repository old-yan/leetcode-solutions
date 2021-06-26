#include "TreeNode.h"
#include "utils.h"

class Solution {
    vector<TreeNode*>ans;
    bool b[1001]={0};
    void traverse(TreeNode*&root){
        if(b[root->val]){
            auto p=root;
            root=nullptr;
            if(p->left){
                traverse(p->left);
                if(p->left)ans.pb(p->left);
            }
            if(p->right){
                traverse(p->right);
                if(p->right)ans.pb(p->right);
            }
        }
        else{
            if(root->left){
                traverse(root->left);
            }
            if(root->right){
                traverse(root->right);
            }
        }
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(int a:to_delete){
            b[a]=true;
        }
        traverse(root);
        if(root)ans.pb(root);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[1,2,3,4,5,6,7]");
    DBG(root);
    vi to_delete{3,5};
    auto ans=sol.delNodes(root,to_delete);
    DBGV(ans);

    system("pause");
    return 0;
}
