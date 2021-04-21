#include "utils.h"

class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vi row(m,0),col(n,0);
        for(auto&indice:indices){
            row[indice[0]]++;
            col[indice[1]]++;
        }
        int ans=0;
        REP(i,m){
            REP(j,n){
                ans+=(row[i]+col[j])%2;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int m=2;
    int n=3;
    vvi indices=makevvi("[[0,1],[1,1]]");
    auto ans=sol.oddCells(m,n,indices);
    DBG(ans);

    system("pause");
    return 0;
}
