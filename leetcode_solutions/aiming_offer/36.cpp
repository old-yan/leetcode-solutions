#include "TreeNode.h"
#include "utils.h"

class Solution {
    #define Node TreeNode
    pair<Node*,Node*>traverse(Node*root){
        if(!root)return {nullptr,nullptr};
        auto [lh,lt]=traverse(root->left);
        auto [rh,rt]=traverse(root->right);
        Node*h,*t;
        if(lh){
            h=lh,lt->right=root,root->left=lt;
        }
        else{
            h=root;
        }
        if(rh){
            t=rt,rh->left=root,root->right=rh;
        }
        else{
            t=root;
        }
        h->left=t,t->right=h;
        return {h,t};
    }
public:
    Node* treeToDoublyList(Node* root) {
        return traverse(root).first;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    Node* root=new Node("[4,2,5,1,3]");
    DBG(root);
    auto ans=sol.treeToDoublyList(root);
    DBG(ans);

    system("pause");
    return 0;
}
