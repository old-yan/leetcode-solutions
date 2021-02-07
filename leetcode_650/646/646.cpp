#include "utils.h"

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(ALL(pairs),[&](vi&x,vi&y)->bool{return x[1]<y[1];});
        DBGVV(pairs);
        vi dp(pairs.size());
        int ans=0;
        REP(i,pairs.size()){
            int pos;
            {
                int low=0,high=i;
                while(low<high){
                    int mid=(low+high)/2;
                    if(pairs[mid][1]>=pairs[i][0])high=mid;
                    else low=mid+1;
                }
                pos=low-1;
            }
            if(pos<0)dp[i]=i?max(dp[i-1],1):1;
            else dp[i]=max(dp[i-1],dp[pos]+1);
            chmax(ans,dp[i]);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi pairs{
        {1,2},{2,3},{3,4}
    };
    auto ans=sol.findLongestChain(pairs);
    DBG(ans);

    system("pause");
    return 0;
}
