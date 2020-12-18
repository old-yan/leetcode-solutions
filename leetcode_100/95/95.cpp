#include "utils.h"

class Solution {
    vector<TreeNode*>dp[10][10];
public:
    vector<TreeNode*> generateTrees(int n) {
        REP(i,n+1){
            FOR(j,1,n-i+1){
                if(!i){
                    dp[j][j+i].pb(new TreeNode(10+j));
                }
                else{
                    for(auto a:dp[j+1][j+i]){
                        TreeNode*p=new TreeNode(10+j);
                        p->right=a;
                        dp[j][j+i].pb(p);
                    }
                    for(auto a:dp[j][j+i-1]){
                        TreeNode*p=new TreeNode(10+j+i);
                        p->left=a;
                        dp[j][j+i].pb(p);
                    }
                    FOR(k,j+1,j+i){
                        for(auto a:dp[j][k-1]){
                            for(auto b:dp[k+1][j+i]){
                                TreeNode*p=new TreeNode(10+k);
                                p->left=a;
                                p->right=b;
                                dp[j][j+i].pb(p);
                            }
                        }
                    }
                }
            }
        }
        return dp[1][n];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=3;
    auto ans=sol.generateTrees(n);
    DBGV(ans);

    system("pause");
    return 0;
}
