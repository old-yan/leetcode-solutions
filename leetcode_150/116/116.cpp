#include "utils.h"

class Solution {
    #define Node NextNode//提交时注释本行
public:
    Node* connect(Node* root) {
        queue<NextNode*>Q;
        if(root)Q.push(root);
        while(Q.size()){
            int l=Q.size();
            Node*last=nullptr;
            while(l--){
                auto cur=Q.front();
                Q.pop();
                if(last){
                    last->next=cur;
                }
                last=cur;
                if(cur->left)Q.push(cur->left);
                if(cur->right)Q.push(cur->right);
            }
        }
        return root;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    NextNode*root=new NextNode("1,2,3,4,5,6,7");
    DBGN(root);
    auto ans=sol.connect(root);
    DBGN(ans);

    system("pause");
    return 0;
}
