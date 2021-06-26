#include "utils.h"

#define Node MultiTreeNode//提交时注释本行
class Solution {
public:
    int maxDepth(Node* root) {
        if(!root)return 0;
        int depth=1;
        for(auto child:root->children){
            chmax(depth,maxDepth(child)+1);
        }
        return depth;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    Node*root=new Node("[1,null,3,2,4,null,5,6]");
    auto ans=sol.maxDepth(root);
    DBG(ans);

    system("pause");
    return 0;
}
