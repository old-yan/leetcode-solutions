#include "utils.h"

class Solution {
    int n;
    vi times;
    vi rnk;
    int dp[100000]={0};
    void init(vi&startTime,vi&endTime){
        n=startTime.size();
        REP(i,n){
            times.pb(startTime[i]);
            times.pb(endTime[i]);
        }
        rnk=getrank2(times);
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        init(startTime,endTime);
        vi idx(n);
        iota(ALL(idx),0);
        sort(ALL(idx),[&](int x,int y){return endTime[x]<endTime[y];});
        int cur=0;
        REP(i,n){
            int start=rnk[idx[i]*2],end=rnk[idx[i]*2+1],p=profit[idx[i]];
            while(cur<end){
                chmax(dp[cur+1],dp[cur]);
                cur++;
            }
            chmax(dp[end],dp[start]+p);
        }
        return dp[rnk[idx[n-1]*2+1]];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi startTime{1,2,3,3};
    vi endTime{3,4,5,6};
    vi profit{50,10,40,70};
    auto ans=sol.jobScheduling(startTime,endTime,profit);
    DBG(ans);

    system("pause");
    return 0;
}
