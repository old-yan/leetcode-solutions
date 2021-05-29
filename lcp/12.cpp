#include "utils.h"

class Solution {
    bool check(vi&time,ll t,ll m){
        int cur=0,curmax=0,cnt=1;
        for(int a:time){
            if(cur+a-max(curmax,a)>t){
                cnt++;
                cur=curmax=a;
            }
            else{
                cur+=a;
                chmax(curmax,a);
            }
        }
        return cnt<=m;
    }
public:
    int minTime(vector<int>& time, int m) {
        ll low=0,high=accumulate(ALL(time),0ll);
        while(low<high){
            ll mid=(low+high)/2;
            if(check(time,mid,m))high=mid;
            else low=mid+1;
        }
        return low;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi time{1,2,3,3};
    int m=2;
    auto ans=sol.minTime(time,m);
    DBG(ans);

    system("pause");
    return 0;
}
