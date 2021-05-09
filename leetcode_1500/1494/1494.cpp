#include "utils.h"

class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
        int inmask[n],dp[1<<n];
        memset(inmask,0,sizeof(inmask));
        for(auto&de:dependencies)inmask[--de[1]]|=1<<--de[0];
        memset(dp,0x3f,sizeof(dp));
        queue<int>Q;
        dp[(1<<n)-1]=0;
        Q.push((1<<n)-1);
        while(dp[0]==0x3f3f3f3f){
            auto _mask=Q.front();
            Q.pop();
            int mask=0;
            REP(i,n)if((_mask>>i&1)&&!(_mask&inmask[i]))mask|=1<<i;
            if(__builtin_popcount(mask)<=k){
                if(chmin(dp[_mask-mask],dp[_mask]+1)){
                    Q.push(_mask-mask);
                }
            }
            else{
                for(int s=mask;s;s=(s-1)&mask){
                    if(__builtin_popcount(s)<=k&&chmin(dp[_mask-s],dp[_mask]+1)){
                        Q.push(_mask-s);
                    }
                }
            }
        }
        return dp[0];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=4;
    vvi dependencies=makevvi("[[2,1],[3,1],[1,4]]");
    int k=2;
    auto ans=sol.minNumberOfSemesters(n,dependencies,k);
    DBG(ans);

    system("pause");
    return 0;
}
