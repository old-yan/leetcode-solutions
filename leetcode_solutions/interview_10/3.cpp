#include "utils.h"

class Solution {
    int bs(vi&arr){
        int low=0,high=arr.size()-1;
        while(low<high){
            if(arr[low]<arr[high])return low;
            int mid=(low+high)/2;
            if(arr[low]>arr[high]){
                if(arr[mid]<=arr[high])high=mid;
                else low=mid+1;
            }
            else{
                if(arr[mid]<arr[high])high=mid;
                else if(arr[mid]>arr[low])low=mid+1;
                else{
                    while(high>mid&&arr[high]==arr[mid])high--;
                    if(arr[high]>arr[mid])return high+1;
                }
            }
        }
        return low;
    }
public:
    int search(vector<int>& arr, int target) {
        int head=bs(arr);
        vi::iterator it;
        if(!head)it=lower_bound(ALL(arr),target);
        else if(arr.front()>target)it=lower_bound(arr.begin()+head,arr.end(),target);
        else it=lower_bound(arr.begin(),arr.begin()+head,target);
        return it!=arr.end()&&*it==target?it-arr.begin():-1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr{15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};
    int target=5;
    auto ans=sol.search(arr,target);
    DBG(ans);

    system("pause");
    return 0;
}
