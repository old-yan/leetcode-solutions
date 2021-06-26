#include "utils.h"

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        ll cnt[101]={0};
        for(int a:arr)cnt[a]++;
        ll ans=0;
        REP(i,target/3+1){
            FOR(j,i,101){
                int k=target-i-j;
                if(k>100)continue;
                if(j>k)break;
                if(i==j&&j==k)ans=(ans+cnt[i]*(cnt[i]-1)*(cnt[i]-2)/6)%MOD;
                else if(i==j)ans=(ans+cnt[i]*(cnt[i]-1)/2*cnt[k])%MOD;
                else if(j==k)ans=(ans+cnt[i]*cnt[j]*(cnt[j]-1)/2)%MOD;
                else ans=(ans+cnt[i]*cnt[j]*cnt[k])%MOD;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr{1,1,2,2,3,3,4,4,5,5};
    int target=8;
    auto ans=sol.threeSumMulti(arr,target);
    DBG(ans);

    system("pause");
    return 0;
}
