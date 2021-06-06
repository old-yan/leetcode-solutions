#include "utils.h"

class Solution {
public:
    //翻转四次等于不翻转，所以模拟转三次就够了
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n=mat.size();
        auto turn=[](vvi&A){
            vvi B(A);
            REP(i,n)REP(j,n){
                B[i][j]=A[j][n-1-i];
            }
            return B;
        };
        if(mat==target)return true;
        REP(k,3){
            mat=turn(mat);
            if(mat==target)return true;
        }
        return false;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi mat=makevvi("[[0,1],[1,0]]");
    vvi target=makevvi("[[1,0],[0,1]]");
    auto ans=sol.findRotation(mat,target);
    DBG(ans);

    system("pause");
    return 0;
}
