#include "TreeNode.h"
#include "utils.h"

class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        static vector<TreeNode*>v[21];
        if(v[0].empty()){
            v[0].pb(nullptr);
            v[1].pb(new TreeNode(0));
            for(int i=3;i<=20;i+=2){
                for(int left=1;left<i;left+=2){
                    int right=i-1-left;
                    for(auto a:v[left]){
                        for(auto b:v[right]){
                            v[i].pb(new TreeNode(0,a,b));
                        }
                    }
                }
            }
        }
        return v[n];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=7;
    auto ans=sol.allPossibleFBT(n);
    DBGV(ans);

    system("pause");
    return 0;
}
