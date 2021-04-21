#include "utils.h"

class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        bool a[8][8];
        int m=8,n=8;
        memset(a,0,sizeof(a));
        vvi ans;
        REP(i,queens.size()){
            a[queens[i][0]][queens[i][1]]=true;
        }
        for(int ii=king[0],jj=king[1];VALID;ii++){
            if(a[ii][jj]){
                ans.pb({ii,jj});
                break;
            }
        }
        for(int ii=king[0],jj=king[1];VALID;ii--){
            if(a[ii][jj]){
                ans.pb({ii,jj});
                break;
            }
        }
        for(int ii=king[0],jj=king[1];VALID;jj++){
            if(a[ii][jj]){
                ans.pb({ii,jj});
                break;
            }
        }
        for(int ii=king[0],jj=king[1];VALID;jj--){
            if(a[ii][jj]){
                ans.pb({ii,jj});
                break;
            }
        }
        for(int ii=king[0],jj=king[1];VALID;ii++,jj++){
            if(a[ii][jj]){
                ans.pb({ii,jj});
                break;
            }
        }
        for(int ii=king[0],jj=king[1];VALID;ii++,jj--){
            if(a[ii][jj]){
                ans.pb({ii,jj});
                break;
            }
        }
        for(int ii=king[0],jj=king[1];VALID;ii--,jj++){
            if(a[ii][jj]){
                ans.pb({ii,jj});
                break;
            }
        }
        for(int ii=king[0],jj=king[1];VALID;ii--,jj--){
            if(a[ii][jj]){
                ans.pb({ii,jj});
                break;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi queens=makevvi("[[0,1],[1,0],[4,0],[0,4],[3,3],[2,4]]");
    vi king{0,0};
    auto ans=sol.queensAttacktheKing(queens,king);
    DBGVV(ans);

    system("pause");
    return 0;
}
