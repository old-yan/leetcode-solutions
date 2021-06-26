#include "utils.h"

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        bitset<300>b[300];
        REP(i,m){
            REP(j,n){
                if(matrix[i][j])b[i].set(j);
            }
        }
        int ans=0;
        REP(i,m){
            int cnt=0;
            REP(j,m){
                int k=(b[i]^b[j]).count();
                if(!k||k==n)cnt++;
            }
            chmax(ans,cnt);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi matrix=makevvi("[[0,0,0],[0,0,1],[1,1,0]]");
    auto ans=sol.maxEqualRowsAfterFlips(matrix);
    DBG(ans);

    system("pause");
    return 0;
}
