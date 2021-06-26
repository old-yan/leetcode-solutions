#include "utils.h"

class Solution {
    pair<int,int> dp[40][40];
    vi arr;
    pair<int,int>&fun(int l,int r){
        if(dp[l][r].second<0x3f3f3f3f)return dp[l][r];
        if(l==r)return dp[l][r]={0,arr[l]};
        auto&res=dp[l][r];
        FOR(i,l+1,r+1){
            auto&a=fun(l,i-1);
            auto&b=fun(i,r);
            chmin(res.second,max(a.second,b.second));
            chmin(res.first,a.second*b.second+a.first+b.first);
        }
        return res;
    }
public:
    int mctFromLeafValues(vector<int>& _arr) {
        arr=_arr;
        int n=arr.size();
        fill(dp[0],dp[n],make_pair(0x3f3f3f3f,0x3f3f3f3f));
        return fun(0,n-1).first;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr{6,2,4};
    auto ans=sol.mctFromLeafValues(arr);
    DBG(ans);

    system("pause");
    return 0;
}
