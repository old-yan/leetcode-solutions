#include "ListNode.h"
#include "TreeNode.h"
#include "utils.h"

class Solution {
    bool check(TreeNode*root,ListNode*head){
        if(!head)return true;
        if(!root)return false;
        if(root->val!=head->val)return false;
        if(check(root->left,head->next))return true;
        if(check(root->right,head->next))return true;
        return false;
    }
    bool traverse(TreeNode*root,ListNode*head){
        if(!root)return false;
        if(check(root,head))return true;
        if(traverse(root->left,head))return true;
        if(traverse(root->right,head))return true;
        return false;
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        return traverse(root,head);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    ListNode*head=makelistnode({4,2,8});
    TreeNode*root=new TreeNode("[1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]");
    DBG(root);
    auto ans=sol.isSubPath(head,root);
    DBG(ans);

    system("pause");
    return 0;
}
