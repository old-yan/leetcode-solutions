#include "utils.h"

class Solution {
    bool mat[61][61]={0};
    bool topo(){
        int deg[61]={0};
        FOR(i,1,61)FOR(j,1,61){
            if(mat[i][j]){
                deg[j]++;
            }
        }
        queue<int>Q;
        FOR(i,1,61)if(!deg[i])Q.push(i);
        while(Q.size()){
            auto p=Q.front();
            Q.pop();
            FOR(i,1,61){
                if(mat[p][i]){
                    if(!--deg[i])Q.push(i);
                }
            }
        }
        return accumulate(deg,deg+61,0)==0;
    }
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
        REP(i,m)REP(j,n){
            FOR(c,1,61)if(c!=targetGrid[i][j]&&i>=Top[c]&&i<=Bottom[c]&&j>=Left[c]&&j<=Right[c]){
                mat[c][targetGrid[i][j]]=true;
            }
        }
        return topo();
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
