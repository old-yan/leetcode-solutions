#include "utils.h"

class Solution {
public:
    vector<int> findSquare(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        int Left[m][n],Up[m][n];
        memset(Left,0,sizeof(Left));
        REP(i,m){
            REP(j,n){
                if(!matrix[i][j])Left[i][j]=j?Left[i][j-1]+1:1;
            }
        }
        memset(Up,0,sizeof(Up));
        REP(i,m){
            REPR(j,n-1){
                if(!matrix[i][j])Up[i][j]=i?Up[i-1][j]+1:1;
            }
        }
        int ans=0;
        pair<int,int>upleft;
        REP(i,m){
            REP(j,n){
                for(int ii=i,jj=j,k=1;ii>=0&&jj>=0;ii--,jj--,k++){
                    if(Left[i][j]>=k&&Up[i][j]>=k&&Left[ii][j]>=k&&Up[i][jj]>=k){
                        if(chmax(ans,k))upleft={ii,jj};
                        else if(ans==k)chmin(upleft,make_pair(ii,jj));
                    }
                }
            }
        }
        if(ans)
            return {upleft.first,upleft.second,ans};
        else
            return {};
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi matrix=makevvi("[[1,0,1],[0,0,1],[0,0,1]]");
    auto ans=sol.findSquare(matrix);
    DBGV(ans);

    system("pause");
    return 0;
}
