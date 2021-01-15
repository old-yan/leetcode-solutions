#include "utils.h"

class Solution {
    int dp[20][20];
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        REP(i,n){
            REP(j,n-i){
                if(!i){
                    dp[j][j+i]=nums[j];
                }
                else{
                    dp[j][j+i]=max(nums[j]-dp[j+1][j+i],nums[j+i]-dp[j][j+i-1]);
                }
            }
        }
        return dp[0][n-1]>=0;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,5,233,7};
    auto ans=sol.PredictTheWinner(nums);
    DBG(ans);

    system("pause");
    return 0;
}
