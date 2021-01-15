#include "utils.h"

class Solution {
    void fun(TreeNode*&root,int key){
        if(!root)return;
        if(root->val<key)fun(root->right,key);
        else if(root->val>key)fun(root->left,key);
        else{
            if(!root->left&&!root->right){
                delete root;
                root=nullptr;
            }
            else if(!root->left){
                auto old=root;
                root=root->right;
                delete old;
            }
            else if(!root->right){
                auto old=root;
                root=root->left;
                delete old;
            }
            else{
                auto p=root->right;
                while(p->left)p=p->left;
                root->val=p->val;
                fun(root->right,p->val);
            }
        }
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        fun(root,key);
        return root;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("5,3,6,2,4,null,7");
    DBGT(root);
    int key=5;
    auto ans=sol.deleteNode(root,key);
    DBGT(ans);

    system("pause");
    return 0;
}
