#include "utils.h"

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        int dp[n+1];
        dp[n]=0;
        sort(ALL(intervals));
        REPR(i,n-1){
            int low=i+1,high=n;
            while(low<high){
                int mid=(low+high)/2;
                if(intervals[mid][0]>=intervals[i][1])high=mid;
                else low=mid+1;
            }
            dp[i]=1+dp[low];
            chmax(dp[i],dp[i+1]);
        }
        return n-dp[0];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi intervals{
        {1,2}, {2,3}, {3,4}, {1,3}
    };
    auto ans=sol.eraseOverlapIntervals(intervals);
    DBG(ans);

    system("pause");
    return 0;
}
