#include "utils.h"

class Solution {
    int m,n;
    int ans=INT_MIN;
    tuple<int,int,int,int>pos;
    void fun(int sum[],int r1,int r2){
        int Min=0,Minstart=0;
        REP(i,n){
            if(chmax(ans,sum[i]-Min)){
                pos={r1,Minstart,r2,i};
            }
            if(chmin(Min,sum[i]))Minstart=i+1;
        }
    }
public:
    vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
        m=matrix.size();
        n=matrix[0].size();
        REP(r1,m){
            int colsum[n];
            memset(colsum,0,sizeof(colsum));
            FOR(r2,r1,m){
                auto&row=matrix[r2];
                REP(c,n)colsum[c]+=row[c];
                partial_sum(colsum,colsum+n,colsum);
                fun(colsum,r1,r2);
                adjacent_difference(colsum,colsum+n,colsum);
            }
        }
        auto [r1,c1,r2,c2]=pos;
        return {r1,c1,r2,c2};
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi matrix=makevvi("[[9,-8,1,3,-2],[-3,7,6,-2,4],[6,-4,-4,8,-7]]");
    auto ans=sol.getMaxMatrix(matrix);
    DBGV(ans);

    system("pause");
    return 0;
}
