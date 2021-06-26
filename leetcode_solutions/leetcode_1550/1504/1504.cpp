#include "utils.h"

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        int ans=0;
        REP(r1,m){
            int colsum[n];
            memset(colsum,0,sizeof(colsum));
            FOR(r2,r1,m){
                REP(c,n)colsum[c]+=mat[r2][c];
                int j=0;
                REP(i,n){
                    if(colsum[i]==r2-r1+1)j++;
                    else{
                        ans+=j*(j+1)/2;
                        j=0;
                    }
                }
                ans+=j*(j+1)/2;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi mat=makevvi("[[1,0,1],[1,1,0],[1,1,0]]");
    auto ans=sol.numSubmat(mat);
    DBG(ans);

    system("pause");
    return 0;
}
