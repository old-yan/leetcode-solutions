#include "TreeNode.h"
#include "utils.h"

class Solution {
    unordered_map<int,int>M;
    int fun(TreeNode*root){
        int lsum=0;
        if(root->left)lsum=fun(root->left);
        int rsum=0;
        if(root->right)rsum=fun(root->right);
        M[lsum+root->val+rsum]++;
        return lsum+root->val+rsum;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if(root)fun(root);
        vi ans;
        int anscount=0;
        for(auto&it:M){
            if(it.second>anscount){
                ans={it.first};
                anscount=it.second;
            }
            else if(it.second==anscount){
                ans.pb(it.first);
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[5,2,-3]");
    DBG(root);
    auto ans=sol.findFrequentTreeSum(root);
    DBGV(ans);

    system("pause");
    return 0;
}
