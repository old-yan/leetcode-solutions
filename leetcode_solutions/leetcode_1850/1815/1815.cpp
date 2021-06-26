#include "utils.h"

class Solution {
public:
    int maxHappyGroups(int batchSize, vector<int>& groups) {
        int cnt[batchSize];
        memset(cnt,0,sizeof(cnt));
        for(int a:groups){
            cnt[a%batchSize]++;
        }
        int units[batchSize+1];
        REP(i,batchSize+1)units[i]=i?units[i-1]*(cnt[i-1]+1):1;
        int dp[units[batchSize]],sum[units[batchSize]];
        memset(sum,0xff,sizeof(sum));
        dp[0]=0;
        sum[0]=0;
        FOR(state,1,units[batchSize]){
            dp[state]=INT_MIN;
            REP(i,batchSize){
                int j=state%units[i+1]/units[i];
                if(j){
                    int rest=state-units[i];
                    if(sum[state]<0)sum[state]=(sum[rest]+i)%batchSize;
                    chmax(dp[state],dp[rest]+!(sum[rest]%batchSize));
                }
            }
        }
        return dp[units[batchSize]-1];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int batchSize=3;
    vi groups{1,2,3,4,5,6};
    auto ans=sol.maxHappyGroups(batchSize,groups);
    DBG(ans);

    system("pause");
    return 0;
}
