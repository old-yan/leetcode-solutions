#include "utils.h"

int M[(1<<21)+1];
class Solution {
    ll sum[22];
    void init(){
        REP(i,22)sum[i]=i?sum[i-1]<<1:1;
    }
public:
    int countPairs(vector<int>& deliciousness) {
        init();
        memset(M,0,sizeof(M));
        ll ans=0;
        for(int a:deliciousness){
            for(int s:sum)if(s>=a){
                ans+=M[s-a];
            }
            M[a]++;
        }
        return ans%MOD;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi delicious{1,3,5,7,9};
    auto ans=sol.countPairs(delicious);
    DBG(ans);

    system("pause");
    return 0;
}
