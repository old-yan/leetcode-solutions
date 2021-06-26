#include "utils.h"

class Solution {
    bool fun(vi&nums){
        vector<double>dp[4][4];
        REP(i,4){
            REP(j,4-i){
                if(!i)dp[j][j+i].pb(nums[j]);
                else{
                    FOR(k,j+1,j+i+1){
                        for(double a:dp[j][k-1]){
                            for(double b:dp[k][j+i]){
                                dp[j][j+i].pb(a+b);
                                dp[j][j+i].pb(a-b);
                                dp[j][j+i].pb(a*b);
                                if(b)dp[j][j+i].pb(double(a)/b);
                            }
                        }
                    }
                    sort(ALL(dp[j][j+i]));
                    dp[j][j+i].resize(unique(ALL(dp[j][j+i]))-dp[j][j+i].begin());
                }
            }
        }
        return find_if(ALL(dp[0][3]),[](double d){return abs(d-24)<EPS;})!=dp[0][3].end();
    }
public:
    bool judgePoint24(vector<int>&nums) {
        vi origin=nums;
        do{
            if(fun(nums))return true;
            next_permutation(ALL(nums));
        }while(nums!=origin);
        return false;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{4,1,8,7};
    auto ans=sol.judgePoint24(nums);
    DBG(ans);

    system("pause");
    return 0;
}
