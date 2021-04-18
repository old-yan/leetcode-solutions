#include "utils.h"

class Solution {
    int m,n,k;
    int ans=INT_MIN;
    void fun(int sum[]){
        set<int>S{0};
        REP(i,n){
            auto it=S.lower_bound(sum[i]-k);
            if(it!=S.end())chmax(ans,sum[i]-*it);
            S.insert(sum[i]);
        }
    }
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int _k) {
        m=matrix.size();
        n=matrix[0].size();
        k=_k;
        REP(r1,m){
            int colsum[n];
            memset(colsum,0,sizeof(colsum));
            FOR(r2,r1,m){
                auto&row=matrix[r2];
                REP(c,n)colsum[c]+=row[c];
                partial_sum(colsum,colsum+n,colsum);
                fun(colsum);
                adjacent_difference(colsum,colsum+n,colsum);
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi matrix=makevvi("[[2,2,-1]]");
    int k=3;
    auto ans=sol.maxSumSubmatrix(matrix,k);
    DBG(ans);

    system("pause");
    return 0;
}
