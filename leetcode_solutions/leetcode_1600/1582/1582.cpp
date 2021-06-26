#include "utils.h"

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        vi rowsum(m,0),colsum(n,0);
        REP(i,m)REP(j,n)if(mat[i][j]){
            rowsum[i]++;
            colsum[j]++;
        }
        int ans=0;
        REP(i,m)REP(j,n){
            if(mat[i][j]&&rowsum[i]==1&&colsum[j]==1)ans++;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi mat=makevvi("[[1,0,0],[0,0,1],[1,0,0]]");
    auto ans=sol.numSpecial(mat);
    DBG(ans);

    system("pause");
    return 0;
}
