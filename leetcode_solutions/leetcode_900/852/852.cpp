#include "utils.h"

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low=1,high=arr.size()-2;
        while(low<high){
            int mid=(low+high)/2;
            if(arr[mid]>arr[mid+1])high=mid;
            else low=mid+1;
        }
        return low;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr{0,2,1,0};
    auto ans=sol.peakIndexInMountainArray(arr);
    DBG(ans);

    system("pause");
    return 0;
}
