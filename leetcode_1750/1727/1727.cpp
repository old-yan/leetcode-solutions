#include "utils.h"

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        int height[n];
        memset(height,0,sizeof(height));
        ll ans=0;
        REP(i,m){
            REP(j,n)height[j]=matrix[i][j]?height[j]+1:0;
            int copy[n];
            memcpy(copy,height,sizeof(copy));
            sort(copy,copy+n,greater<int>());
            REP(j,n){
                chmax(ans,copy[j]*(j+1));
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi matrix=makevvi("[[0,0,1],[1,1,1],[1,0,1]]");
    auto ans=sol.largestSubmatrix(matrix);
    DBG(ans);

    system("pause");
    return 0;
}
