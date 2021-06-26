#include "utils.h"

class Solution {
    int dp[32][2];
    bool isone[32];
    int ans=0;
    void dfs(int i,int last,bool same_prefix){
        if(i<0){
            ans++;
        }
        else if(same_prefix){
            if(isone[i]&&!last)dfs(i-1,1,same_prefix);
            dfs(i-1,0,same_prefix&&!isone[i]);
        }
        else{
            if(!last)ans+=dp[i][1];
            ans+=dp[i][0];
        }
    }
public:
    int findIntegers(int num) {
        REP(i,32){
            if(!i)dp[i][0]=dp[i][1]=1;
            else{
                dp[i][0]=dp[i-1][0]+dp[i-1][1];
                dp[i][1]=dp[i-1][0];
            }
        }
        REP(i,32)isone[i]=num&(1<<i);
        dfs(29,0,true);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int num=1;
    auto ans=sol.findIntegers(num);
    DBG(ans);

    system("pause");
    return 0;
}
