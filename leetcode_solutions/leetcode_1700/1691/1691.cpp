#include "utils.h"

class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto&cu:cuboids)sort(ALL(cu));
        sort(ALL(cuboids));
        int n=cuboids.size();
        int dp[n];
        REP(i,n){
            dp[i]=cuboids[i][2];
            REP(j,i){
                if(cuboids[j][0]<=cuboids[i][0]&&cuboids[j][1]<=cuboids[i][1]&&cuboids[j][2]<=cuboids[i][2]){
                    chmax(dp[i],dp[j]+cuboids[i][2]);
                }
            }
        }
        return *max_element(dp,dp+n);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi cuboids=makevvi("[[50,45,20],[95,37,53],[45,23,12]]");
    auto ans=sol.maxHeight(cuboids);
    DBG(ans);

    system("pause");
    return 0;
}
