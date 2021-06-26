#include "utils.h"

class Solution {
public:
    int countArrangement(int n) {
        vector<int> can[16];
        for(int i=1;i<=15;i++){
            for(int j=0;j<15;j++){
                if((i+1)%(j+1)==0||(j+1)%(i+1)==0)can[i].push_back(j);
            }
        }
        int dp[1<<n];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int j=1;j<(1<<n);j++){
            int last=__builtin_popcount(j);
            for(int k:can[last]){
                if(((j>>k)&1)){
                    dp[j]+=dp[j-(1<<k)];
                }
            }
        }
        return dp[(1<<n)-1];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=2;
    auto ans=sol.countArrangement(n);
    DBG(ans);

    system("pause");
    return 0;
}
