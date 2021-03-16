#include "utils.h"

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=(accumulate(ALL(piles),0ll)-1+h)/h,high=*max_element(ALL(piles));
        while(low<high){
            int mid=(low+high)/2;
            int cnt=0;
            for(auto&p:piles){
                cnt+=(p-1+mid)/mid;
            }
            if(cnt<=h)high=mid;
            else low=mid+1;
        }
        return low;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi piles{3,6,7,11};
    int h=8;
    auto ans=sol.minEatingSpeed(piles,h);
    DBG(ans);

    system("pause");
    return 0;
}
