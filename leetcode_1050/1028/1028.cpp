#include "TreeNode.h"
#include "utils.h"

class Solution {
    vi vals,deps;
    TreeNode*makenode(int&idx,int d){
        auto p=new TreeNode(vals[idx++]);
        if(idx<deps.size()&&deps[idx]==d+1){
            p->left=makenode(idx,d+1);
            if(idx<deps.size()&&deps[idx]==d+1){
                p->right=makenode(idx,d+1);
            }
        }
        return p;
    }
public:
    TreeNode* recoverFromPreorder(string S) {
        for(int i=0,j;i<S.size();i=j){
            for(j=i;S[j]=='-';j++);
            deps.pb(j-i);
            int val=0;
            while(isdigit(S[j]))val=val*10+S[j++]-'0';
            vals.pb(val);
        }
        int idx=0;
        return makenode(idx,0);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string S="1-2--3--4-5--6--7";
    auto ans=sol.recoverFromPreorder(S);
    DBG(ans);

    system("pause");
    return 0;
}
