#include "TreeNode.h"
#include "utils.h"

class Solution {
    int distance,ans;
    struct node{
        int num[9]={0};
    };
    node traverse(TreeNode*cur){
        if(!cur){
            return node();
        }
        else{
            auto l=traverse(cur->left);
            auto r=traverse(cur->right);
            partial_sum(r.num,r.num+9,r.num);
            REP(i,distance-1){
                ans+=l.num[i]*r.num[distance-2-i];
            }
            adjacent_difference(r.num,r.num+9,r.num);
            FORR(i,8,1){
                l.num[i]=l.num[i-1]+r.num[i-1];
            }
            l.num[0]=!cur->left&&!cur->right;
            return l;
        }
    }
public:
    int countPairs(TreeNode* root, int _distance) {
        distance=_distance;
        traverse(root);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[1,2,3,null,4]");
    DBG(root);
    int distance=3;
    auto ans=sol.countPairs(root,distance);
    DBG(ans);

    system("pause");
    return 0;
}
