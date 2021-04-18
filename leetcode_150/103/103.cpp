#include "TreeNode.h"
#include "utils.h"

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*>Q;
        vvi ans;
        if(root)Q.push(root);
        while(Q.size()){
            int l=Q.size();
            vector<TreeNode*>temp;
            while(l--){
                temp.pb(Q.front());
                Q.pop();
                if(temp.back()->left)Q.push(temp.back()->left);
                if(temp.back()->right)Q.push(temp.back()->right);
            }
            vi nums;
            for(auto a:temp)nums.pb(a->val);
            if(ans.size()%2)reverse(ALL(nums));
            ans.pb(nums);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("3,9,20,null,null,15,7");
    DBG(root);
    auto ans=sol.zigzagLevelOrder(root);
    DBGVV(ans);

    system("pause");
    return 0;
}
