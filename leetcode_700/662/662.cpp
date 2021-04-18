#include "TreeNode.h"
#include "utils.h"

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,ll>>Q;
        Q.emplace(root,0);
        ll ans=0;
        while(int l=Q.size()){
            ll a=Q.front().second;
            ll Max=INT_MIN;
            while(l--){
                auto p=Q.front();
                Q.pop();
                p.second-=a;
                chmax(Max,p.second);
                if(p.first->left)Q.emplace(p.first->left,p.second*2);
                if(p.first->right)Q.emplace(p.first->right,p.second*2+1);
            }
            chmax(ans,Max+1);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[1,3,2,5,3,null,9]");
    DBG(root);
    auto ans=sol.widthOfBinaryTree(root);
    DBG(ans);

    system("pause");
    return 0;
}
