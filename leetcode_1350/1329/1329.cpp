#include "utils.h"

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        REP(i,m){
            vector<pair<int,int>>idx;
            priority_queue<int,vi,greater<int>>Q;
            for(int ii=i,jj=0;VALID;ii++,jj++){
                idx.emplace_back(ii,jj);
                Q.emplace(mat[ii][jj]);
            }
            for(auto [ii,jj]:idx){
                mat[ii][jj]=Q.top();
                Q.pop();
            }
        }
        FOR(j,1,n){
            vector<pair<int,int>>idx;
            priority_queue<int,vi,greater<int>>Q;
            for(int ii=0,jj=j;VALID;ii++,jj++){
                idx.emplace_back(ii,jj);
                Q.emplace(mat[ii][jj]);
            }
            for(auto [ii,jj]:idx){
                mat[ii][jj]=Q.top();
                Q.pop();
            }
        }
        return mat;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi mat=makevvi("[[11,25,66,1,69,7],[23,55,17,45,15,52],[75,31,36,44,58,8],[22,27,33,25,68,4],[84,28,14,11,5,50]]");
    auto ans=sol.diagonalSort(mat);
    DBGVV(ans);

    system("pause");
    return 0;
}
