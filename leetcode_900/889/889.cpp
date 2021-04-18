#include "TreeNode.h"
#include "utils.h"

class Solution {
    unordered_map<int,int>post_idx;
    TreeNode*makenode(int h1,int h2,int l,vi&pre,vi&post){
        if(!l)return nullptr;
        if(l==1)return new TreeNode(pre[h1]);
        int i=post_idx[pre[h1+1]];
        int l1=i-h2+1,l2=l-1-l1;
        return new TreeNode(pre[h1],makenode(h1+1,h2,l1,pre,post),makenode(h1+1+l1,h2+l1,l2,pre,post));
    }
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        REP(i,post.size())post_idx[post[i]]=i;
        return makenode(0,0,pre.size(),pre,post);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi pre{1,2,4,5,3,6,7};
    vi post{4,5,2,6,7,3,1};
    auto ans=sol.constructFromPrePost(pre,post);
    DBG(ans);

    system("pause");
    return 0;
}
