#include "Graph.h"
#include "utils.h"

class Solution {
public:
    bool isPrintable(vector<vector<int>>& targetGrid) {
        int m=targetGrid.size(),n=targetGrid[0].size();
        vi Left(61,n),Right(61,0),Top(61,m),Bottom(61,0);
        REP(i,m)REP(j,n){
            int c=targetGrid[i][j];
            chmin(Left[c],int(j));
            chmax(Right[c],int(j));
            chmin(Top[c],int(i));
            chmax(Bottom[c],int(i));
        }
        dg.reset(60);
        REP(i,m)REP(j,n){
            FOR(c,1,61)if(c!=targetGrid[i][j]&&i>=Top[c]&&i<=Bottom[c]&&j>=Left[c]&&j<=Right[c]){
                dg.addEdge(targetGrid[i][j]-1,c-1);
            }
        }
        tp.solve(dg);
        return tp.seq.size()==60;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi targetGrid=makevvi("[[1,1,1,1],[1,2,2,1],[1,2,2,1],[1,1,1,1]]");
    auto ans=sol.isPrintable(targetGrid);
    DBG(ans);

    system("pause");
    return 0;
}
