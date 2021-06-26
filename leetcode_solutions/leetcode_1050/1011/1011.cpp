#include "utils.h"

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int low=*max_element(ALL(weights)),high=accumulate(ALL(weights),0);
        while(low<high){
            int mid=(low+high)/2;
            int cur=0,cnt=1;
            for(int a:weights){
                if(cur+a>mid){
                    cur=a;
                    cnt++;
                }
                else cur+=a;
            }
            if(cnt<=D)high=mid;
            else low=mid+1;
        }
        return low;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi weights{3,2,2,4,1,4};
    int D=3;
    auto ans=sol.shipWithinDays(weights,D);
    DBG(ans);

    system("pause");
    return 0;
}
