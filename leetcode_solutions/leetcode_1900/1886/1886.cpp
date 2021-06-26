#include "utils.h"

class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n=mat.size();
        auto rotate=[&](vvi&A){
            vvi B(A);
            REP(i,n){
                REP(j,n){
                    B[i][j]=A[n-1-j][i];
                }
            }
            return B;
        };
        if(mat==target)return true;
        mat=rotate(mat);
        if(mat==target)return true;
        mat=rotate(mat);
        if(mat==target)return true;
        mat=rotate(mat);
        if(mat==target)return true;
        return false;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi mat=makevvi("[[0,0,0],[0,1,0],[1,1,1]]");
    vvi target=makevvi("[[1,1,1],[0,1,0],[0,0,0]]");
    auto ans=sol.findRotation(mat,target);
    DBG(ans);

    system("pause");
    return 0;
}
