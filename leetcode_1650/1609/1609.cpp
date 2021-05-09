#include "TreeNode.h"
#include "utils.h"

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*>Q;
        Q.push(root);
        int level=0;
        while(int l=Q.size()){
            vi v;
            while(l--){
                auto p=Q.front();
                Q.pop();
                if(p->val%2==level%2)return false;
                v.pb(p->val);
                if(p->left)Q.push(p->left);
                if(p->right)Q.push(p->right);
            }
            if(level%2==0){
                FOR(i,1,v.size())if(v[i]<=v[i-1])return false;
            }
            else{
                FOR(i,1,v.size())if(v[i]>=v[i-1])return false;
            }
            level++;
        }
        return true;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("1,10,4,3,null,7,9,12,8,6,null,null,2");
    DBG(root);
    auto ans=sol.isEvenOddTree(root);
    DBG(ans);

    system("pause");
    return 0;
}
