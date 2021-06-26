#include "utils.h"

class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(ALL(position));
        int low=0,high=position.back()-position.front();
        while(low<high){
            int mid=(low+high+1)>>1;
            int pre=-mid,cnt=0;
            for(int a:position){
                if(a>=pre+mid){
                    pre=a;
                    cnt++;
                }
            }
            if(cnt>=m)low=mid;
            else high=mid-1;
        }
        return low;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi position{1,2,3,4,7};
    int m=3;
    auto ans=sol.maxDistance(position,m);
    DBG(ans);

    system("pause");
    return 0;
}
