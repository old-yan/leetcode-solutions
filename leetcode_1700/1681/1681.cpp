#include "utils.h"

class Solution {
    int dif[1<<16],dp[1<<16],n,each;
    vi nums,next;
    void getdif(){
        memset(dif,0x3f,sizeof(dif));
        for(int s=(1<<n)-1;s;s=(s-1)&((1<<n)-1)){
            if(__builtin_popcount(s)==each){
                int pre=-1;
                bool dup=false;
                for(int i=0;i<n;i++)if(s>>i&1){
                    if(pre==nums[i]){
                        dup=true;
                        break;
                    }
                    else pre=nums[i];
                }
                if(!dup)dif[s]=nums[31-__builtin_clz(s)]-nums[__builtin_ctz(s)];
            }
        }
    }
public:
    int minimumIncompatibility(vector<int>& _nums, int k) {
        nums=_nums;
        n=nums.size();
        each=n/k;
        sort(ALL(nums));
        if(n%k)return -1;
        next=next_different(nums);
        getdif();
        memset(dp,0x3f,sizeof(dp));
        dp[0]=0;
        FOR(state,1,1<<n)if(__builtin_popcount(state)%each==0){
            for(int s=state;s;s=(s-1)&state)if(__builtin_popcount(s)==each){
                chmin(dp[state],dp[state-s]+dif[s]);
            }
        }
        return dp[(1<<n)-1]==0x3f3f3f3f?-1:dp[(1<<n)-1];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,2,1,4};
    int k=2;
    auto ans=sol.minimumIncompatibility(nums,k);
    DBG(ans);

    system("pause");
    return 0;
}
