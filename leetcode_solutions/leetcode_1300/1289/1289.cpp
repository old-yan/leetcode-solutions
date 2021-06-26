#include "utils.h"

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int m=arr.size(),n=arr[0].size();
        int dp[n];
        fill(dp,dp+n,0);
        REP(i,m){
            int Min=INT_MAX,SecondMin=INT_MAX;
            for(int a:dp){
                if(a<=Min){
                    SecondMin=Min,Min=a;
                }
                else if(a<=SecondMin){
                    SecondMin=a;
                }
            }
            REP(j,n){
                if(dp[j]==Min)dp[j]=arr[i][j]+SecondMin;
                else dp[j]=arr[i][j]+Min;
            }
        }
        return *min_element(dp,dp+n);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi arr=makevvi("[[1,2,3],[4,5,6],[7,8,9]]");
    auto ans=sol.minFallingPathSum(arr);
    DBG(ans);

    system("pause");
    return 0;
}
