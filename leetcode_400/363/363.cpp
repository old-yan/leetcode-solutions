#include "utils.h"

class Solution {
    int m,n,k;
    int ans=INT_MIN;
    void fun(int presum[]){
        set<int>S;
        S.insert(0);
        FOR(r,1,m+1){
            auto it=S.lower_bound(presum[r]-k);
            if(it!=S.end())chmax(ans,presum[r]-*it);
            S.insert(presum[r]);
        }
    }
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int _k) {
        m=matrix.size();
        n=matrix[0].size();
        k=_k;
        int presum[m+1];
        REP(c1,n){
            memset(presum,0,sizeof(presum));
            FOR(c2,c1,n){
                int Minbefore=0,Maxd=INT_MIN;
                int cnt=0;
                REP(r,m){
                    cnt+=matrix[r][c2];
                    presum[r+1]+=cnt;
                    chmax(Maxd,presum[r+1]-Minbefore);
                    chmin(Minbefore,presum[r+1]);
                }
                if(Maxd<=k)chmax(ans,Maxd);
                else fun(presum);
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi matrix{
        {1,0,1},
        {0,-2,3}
    };
    auto ans=sol.maxSumSubmatrix(matrix,2);
    DBG(ans);

    system("pause");
    return 0;
}
