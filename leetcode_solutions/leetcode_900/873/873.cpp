#include "utils.h"

class Solution {
    int dp[1000][1000];
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size();
        int ans=0;
        REP(i,n){
            for(int j=i-1,k=0;j>=0;j--){
                while(k<j&&arr[k]<arr[i]-arr[j])k++;
                if(k<j&&arr[k]+arr[j]==arr[i]){
                    dp[i][j]=dp[j][k]+1;
                    chmax(ans,dp[i][j]);
                }
                else dp[i][j]=2;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr{1,3,7,11,12,14,18};
    auto ans=sol.lenLongestFibSubseq(arr);
    DBG(ans);

    system("pause");
    return 0;
}
