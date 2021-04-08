#include "TreeNode.h"
#include "utils.h"

class Solution {
    int rightBigger[100];
    TreeNode*fun(vi&preorder,int h,int t){
        if(h>t)return nullptr;
        else return new TreeNode(preorder[h],fun(preorder,h+1,rightBigger[h]-1),fun(preorder,rightBigger[h],t));
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        stack<int>S;
        int n=preorder.size();
        REP(i,n){
            while(S.size()&&preorder[S.top()]<preorder[i]){
                rightBigger[S.top()]=i;
                S.pop();
            }
            S.push(i);
        }
        while(S.size()){
            rightBigger[S.top()]=n;
            S.pop();
        }
        return fun(preorder,0,n-1);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi preorder{8,5,1,7,10,12};
    auto ans=sol.bstFromPreorder(preorder);
    DBGT(ans);

    system("pause");
    return 0;
}
