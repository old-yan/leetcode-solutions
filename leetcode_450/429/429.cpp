#include "utils.h"

class Solution {
    #define Node MultiTreeNode//提交时注释本行
public:
    vector<vector<int>> levelOrder(Node* root) {
        vvi ans;
        queue<Node*>Q;
        if(root)Q.push(root);
        while(int l=Q.size()){
            vi temp;
            while(l--){
                auto p=Q.front();
                temp.pb(p->val);
                Q.pop();
                for(auto q:p->children){
                    Q.push(q);
                }
            }
            ans.pb(temp);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    MultiTreeNode*root=new MultiTreeNode("[1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]");
    auto ans=sol.levelOrder(root);
    DBGVV(ans);

    system("pause");
    return 0;
}
