#include "utils.h"

class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode*p=root;
        TreeNode*last,*cur=nullptr;
        TreeNode*go_lower=nullptr;
        bool finish=false;
        while(p){
            if(p->left){
                TreeNode*q;
                for(q=p->left;q->right&&q->right!=p;q=q->right);
                if(!q->right){
                    q->right=p;
                    p=p->left;
                }
                else{
                    q->right=nullptr;
                    if(!finish){
                        last=cur;
                        cur=p;
                        if(!go_lower&&last&&cur->val<last->val){
                            go_lower=last;
                        }
                        if(go_lower&&cur->val>go_lower->val){
                            swap(last->val,go_lower->val);
                            finish=true;
                        }
                    }
                    p=p->right;
                }
            }
            else{
                if(!finish){
                    last=cur;
                    cur=p;
                    if(!go_lower&&last&&cur->val<last->val){
                        go_lower=last;
                    }
                    if(go_lower&&cur->val>go_lower->val){
                        swap(last->val,go_lower->val);
                        finish=true;
                    }
                }
                p=p->right;
            }
        }
        if(!finish)swap(go_lower->val,cur->val);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[68,41,null,-85,null,-73,-49,-98,null,null,null,-124]");
    DBGT(root);
    sol.recoverTree(root);
    DBGT(root);

    system("pause");
    return 0;
}
