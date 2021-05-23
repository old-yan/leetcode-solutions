#include "utils.h"

class Solution {
public:
    //二分找出最低的可行速度
    //注意最后一段旅程需要保留浮点数运算
    int minSpeedOnTime(vector<int>& dist, double hour) {
        if(dist.size()>ceil(hour))return -1;
        int last=dist.back();
        ll low=1,high=100000000000ll;
        while(low<high){
            ll mid=(low+high)/2;
            double cnt=0;
            REP(i,dist.size()-1){
                cnt+=(dist[i]+mid-1)/mid;
            }
            cnt+=(double)last/mid;
            if(cnt<=hour)high=mid;
            else low=mid+1;
        }
        return low;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi dist{1,1,100000};
    double hour=2.01;
    auto ans=sol.minSpeedOnTime(dist,hour);
    DBG(ans);

    system("pause");
    return 0;
}
