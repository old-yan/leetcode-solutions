#include "utils.h"

class Solution {
    double bs(vi&nums1, vi&nums2, ll sum)
    {
        int low = 0;
        int high = nums1.size();
        while (low<high)
        {
            int mid = (high + low) / 2;
            if (mid>=sum-1||(sum-mid-2<nums2.size()&&nums2[sum-mid-2]<=nums1[mid]))
                high = mid;
            else
                low = mid+1;
        }
        if(low==nums1.size())return nums2[sum-low-1];
        else if(sum-low-1==nums2.size())return nums1[low];
        else return min(nums1[low],nums2[sum-low-1]);
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1=nums1.size(),l2=nums2.size();
        if((l1+l2)%2){
            return bs(nums1,nums2,(l1+l2+1)/2);
        }
        else{
            return (bs(nums1,nums2,(l1+l2)/2)+bs(nums1,nums2,(l1+l2)/2+1))/2;
        }
    }
};

int main(){
    Solution sol;

    vi nums1{1,3};
    DBGV(nums1);
    vi nums2{};
    DBGV(nums2);
    auto ans=sol.findMedianSortedArrays(nums1,nums2);
    DBG(ans);

    system("pause");
}