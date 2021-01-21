#include "utils.h"

#define Node QuadTree//提交时注释本行
class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        if(quadTree1->isLeaf){
            if(quadTree1->val)return quadTree1;
            else return quadTree2;
        }
        else{
            if(quadTree2->isLeaf){
                if(quadTree2->val)return quadTree2;
                else return quadTree1;
            }
            else{
                quadTree1->topLeft=intersect(quadTree1->topLeft,quadTree2->topLeft);
                quadTree1->topRight=intersect(quadTree1->topRight,quadTree2->topRight);
                quadTree1->bottomLeft=intersect(quadTree1->bottomLeft,quadTree2->bottomLeft);
                quadTree1->bottomRight=intersect(quadTree1->bottomRight,quadTree2->bottomRight);
                if(quadTree1->topLeft->isLeaf&&quadTree1->topRight->isLeaf&&quadTree1->bottomLeft->isLeaf&&quadTree1->bottomRight->isLeaf){
                    if(quadTree1->topLeft->val==quadTree1->topRight->val&&quadTree1->topLeft->val==quadTree1->bottomLeft->val&&quadTree1->topLeft->val==quadTree1->bottomRight->val){
                        quadTree1->isLeaf=true;
                        quadTree1->val=quadTree1->topLeft->val;
                        delete quadTree1->topLeft;
                        delete quadTree1->topRight;
                        delete quadTree1->bottomLeft;
                        delete quadTree1->bottomRight;
                        quadTree1->topLeft=quadTree1->topRight=quadTree1->bottomLeft=quadTree1->bottomRight=nullptr;
                    }
                }
                return quadTree1;
            }
        }
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    Node*quadTree1=new Node("[[0,1],[1,1],[1,1],[1,0],[1,0]]");
    DBGN(quadTree1);
    Node*quadTree2=new Node("[[0,1],[1,1],[0,1],[1,1],[1,0],null,null,null,null,[1,0],[1,0],[1,1],[1,1]]");
    DBGN(quadTree2);
    auto ans=sol.intersect(quadTree1,quadTree2);
    DBGN(ans);

    system("pause");
    return 0;
}
