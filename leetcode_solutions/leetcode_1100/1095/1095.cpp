#include "MountainArray.h"
#include "utils.h"

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n=mountainArr.length();
        int peak=[&](){
            int low=1,high=n-2;
            while(low<high){
                int mid=low+high>>1;
                if(mountainArr.get(mid+1)<mountainArr.get(mid))high=mid;
                else low=mid+1;
            }
            return low;
        }();
        {
            int low=0,high=peak;
            while(low<high){
                int mid=low+high>>1;
                if(mountainArr.get(mid)>=target)high=mid;
                else low=mid+1;
            }
            if(mountainArr.get(low)==target)return low;
        }
        {
            int low=peak+1,high=n-1;
            while(low<high){
                int mid=low+high>>1;
                if(mountainArr.get(mid)<=target)high=mid;
                else low=mid+1;
            }
            if(mountainArr.get(low)==target)return low;
        }
        return -1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int target=3;
    MountainArray mountainArr({1,2,3,4,5,3,1});
    auto ans=sol.findInMountainArray(target,mountainArr);
    DBG(ans);

    system("pause");
    return 0;
}
