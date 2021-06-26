#include "utils.h"

class Solution {
    struct node{
        int count[20]={0};
    };
    node fun(int n){
        if(!n){
            node a;
            a.count[0]=1;
            return a;
        }
        node a=fun(n>>1);
        for(int i=19;i>=1;i--){
            a.count[i]+=a.count[i-1];
        }
        if(n%2==0)a.count[__builtin_popcount(n+1)]--;
        return a;
    }
public:
    int countPrimeSetBits(int L, int R) {
        node count1=fun(R);
        node count2=fun(L-1);
        int ans=0;
        for(int i:{2,3,5,7,11,13,17,19}){
            ans+=count1.count[i]-count2.count[i];
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int L=6;
    int R=10;
    auto ans=sol.countPrimeSetBits(L,R);
    DBG(ans);

    system("pause");
    return 0;
}