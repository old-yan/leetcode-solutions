#include "utils.h"

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        int dp[n];
        memset(dp,0x3f,sizeof(dp));
        queue<pair<int,int>>Q;
        dp[start]=0;
        Q.emplace(start,0);
        while(Q.size()){
            auto [pos,dis]=Q.front();
            Q.pop();
            if(!arr[pos])return true;
            if(pos+arr[pos]<n&&chmin(dp[pos+arr[pos]],dis+1)){
                Q.emplace(pos+arr[pos],dis+1);
            }
            if(pos>=arr[pos]&&chmin(dp[pos-arr[pos]],dis+1)){
                Q.emplace(pos-arr[pos],dis+1);
            }
        }
        return false;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr{4,2,3,0,3,1,2};
    int start=0;
    auto ans=sol.canReach(arr,start);
    DBG(ans);

    system("pause");
    return 0;
}
