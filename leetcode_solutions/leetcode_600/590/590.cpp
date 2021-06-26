#include "utils.h"

#define Node MultiTreeNode//提交时注释本行
class Solution {
    vi ans;
    void fun(Node*root){
        for(auto child:root->children){
            fun(child);
        }
        ans.pb(root->val);
    }
public:
    vector<int> postorder(Node* root) {
        if(root)fun(root);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    Node*root=new Node("[1,null,3,2,4,null,5,6]");
    auto ans=sol.postorder(root);
    DBGV(ans);

    system("pause");
    return 0;
}
