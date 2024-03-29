#include "NextNode.h"
#include "utils.h"

class Solution {
    #define Node NextNode//提交时注释本行
    void fun(Node*p,Node*right){
        if(!right){
            if(p->right)fun(p->right,nullptr);
            if(p->left){
                if(p->right)fun(p->left,p->right);
                else fun(p->left,nullptr);
            }
        }
        else{
            p->next=right;
            while(right&&!right->left&&!right->right)right=right->next;
            if(right){
                if(right->left)right=right->left;
                else right=right->right;
            }
            if(p->right)fun(p->right,right);
            if(p->left){
                if(p->right)fun(p->left,p->right);
                else fun(p->left,right);
            }
        }
    }
public:
    Node* connect(Node* root) {
        if(!root)return root;
        fun(root,nullptr);
        return root;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    NextNode*root=new NextNode("[1,2,3,4,5,null,6,7,null,null,null,null,8]");
    DBG(root);
    auto ans=sol.connect(root);
    DBG(ans);

    system("pause");
    return 0;
}
