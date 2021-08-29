#include "utils.h"

class Solution {
public:
    //这道题是经典的状态压缩+子集枚举问题
    //比如 1101101 可以表示完成任务 {0,2,3,5,6} 的状态
    //枚举其所有子集，作为最后一天的任务，比如 0001100 作为子集，且能够在一天内完成，那么 dp[1101101]=dp[1100001]+1 的转移成立
    int minSessions(vector<int>& tasks, int sessionTime) {
        int n=tasks.size();
        //首先，算出所有可能的任务组合的总费时
        int sum[1<<n];
        {
            sum[0]=0;
            for(int state=1;state<1<<n;state++){
                sum[state]=sum[state-(state&-state)]+tasks[__builtin_ctz(state)];
            }
        }
        //从小到大进行动态规划，dp[state]表示
        int dp[1<<n];
        memset(dp,0x3f,sizeof(dp));
        //没有任务的话，需要 0 天完成
        dp[0]=0;
        for(int state=1;state<1<<n;state++){
            //枚举 state 的所有子集 s ，如果 sum[s]<sessionTime 说明这个子集可以作为最后一天
            for(int s=state;s;s=(s-1)&state)if(sum[s]<=sessionTime){
                dp[state]=min(dp[state],dp[state-s]+1);
            }
        }
        return dp[(1<<n)-1];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<int>tasks{3,1,3,1,1};
    int sessionTime=8;
    auto ans=sol.minSessions(tasks,sessionTime);
    DBG(ans);

    system("pause");
    return 0;
}
