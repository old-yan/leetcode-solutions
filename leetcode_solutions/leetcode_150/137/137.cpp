#include "utils.h"

class Solution {
    //模拟三进制的位操作
    #define MIN -6973568802l
    #define MAX 3486784400l
    #define X 10460353203l
    ll fun(ll x,ll y){
        if(x<0)x+=X;
        if(y<0)y+=X;
        int a[21]={0},b[21]={0};
        REP(i,21){
            a[i]=x%3;
            x/=3;
        }
        REP(i,21){
            b[i]=y%3;
            y/=3;
        }
        REP(i,21){
            a[i]=(a[i]+b[i])%3;
        }
        ll val=0;
        REPR(i,20){
            val=val*3+a[i];
        }
        if(val>MAX)val-=X;
        return val;
    }
public:
    int singleNumber(vector<int>& nums) {
        ll i=0;
        for(int a:nums)i=fun(i,a);
        return i;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{2,2,3,2};
    auto ans=sol.singleNumber(nums);
    DBG(ans);

    system("pause");
    return 0;
}
