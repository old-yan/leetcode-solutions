#include "TreeNode.h"
#include "utils.h"

class Solution {
    vvi ans;
    int path[1000],l=0;
    set<TreeNode*>can;
    void func(){
        if(can.empty()){
            ans.emplace_back(path,path+l);
            return;
        }
        TreeNode* cur=nullptr;
        set<TreeNode*>::iterator it=can.begin();
        while(it!=can.end()){
            cur=*it;
            can.erase(it);
            path[l++]=cur->val;
            if(cur->left)can.insert(cur->left);
            if(cur->right)can.insert(cur->right);
            func();
            if(cur->left)can.erase(cur->left);
            if(cur->right)can.erase(cur->right);
            l--;
            it=next(can.insert(cur).first);
        }
    }
public:
    vector<vector<int>> BSTSequences(TreeNode* root) {
        if(root)can.insert(root);
        func();
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[2,1,3]");
    DBG(root);
    auto ans=sol.BSTSequences(root);
    DBGVV(ans);

    system("pause");
    return 0;
}
