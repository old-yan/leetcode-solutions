#include "utils.h"

class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        if(upper+lower!=accumulate(ALL(colsum),0))return {};
        int m=2,n=colsum.size();
        vvi ans(2,vi(n,0));
        REP(j,n){
            if(colsum[j]==2){
                ans[0][j]=ans[1][j]=1;
                if(upper--<=0)return {};
                if(lower--<=0)return {};
            }
        }
        REP(j,n){
            if(colsum[j]==1){
                if(upper){
                    upper--;
                    ans[0][j]=1;
                }
                else{
                    lower--;
                    ans[1][j]=1;
                }
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int upper=4;
    int lower=7;
    vi colsum{2,1,2,2,1,1,1};
    auto ans=sol.reconstructMatrix(upper,lower,colsum);
    DBGVV(ans);

    system("pause");
    return 0;
}
