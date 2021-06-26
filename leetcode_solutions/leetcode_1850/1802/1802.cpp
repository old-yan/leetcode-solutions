#include "utils.h"

class Solution {
    ll sidenum(ll cur,ll len){
        if(len>=cur){
            return cur*(cur-1)/2+len-cur+1;
        }
        else{
            return (cur-1+cur-len)*len/2;
        }
    }
public:
    int maxValue(int n, int index, int maxSum) {
        ll low=1,high=maxSum;
        while(low<high){
            ll mid=(low+high+1)/2;
            if(sidenum(mid,index)+mid+sidenum(mid,n-1-index)<=maxSum)low=mid;
            else high=mid-1;
        }
        return low;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=4;
    int index=2;
    int maxSum=6;
    auto ans=sol.maxValue(n,index,maxSum);
    DBG(ans);

    system("pause");
    return 0;
}
