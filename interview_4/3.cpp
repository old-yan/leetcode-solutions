#include "ListNode.h"
#include "TreeNode.h"
#include "utils.h"

class Solution {
public:
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        queue<TreeNode*>Q;
        if(tree)Q.push(tree);
        vector<ListNode*>ans;
        while(int l=Q.size()){
            vector<ListNode*>v;
            while(l--){
                auto p=Q.front();
                Q.pop();
                v.pb(new ListNode(p->val));
                if(p->left)Q.push(p->left);
                if(p->right)Q.push(p->right);
            }
            ans.pb(arrtolist(v));
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*tree=new TreeNode("[1,2,3,4,5,null,7,8]");
    DBG(tree);
    auto ans=sol.listOfDepth(tree);
    DBGV(ans);

    system("pause");
    return 0;
}
