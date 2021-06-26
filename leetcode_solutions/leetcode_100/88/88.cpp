#include "utils.h"

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=m-1,j=n-1,k=m+n-1;k>=0;){
            if(j<0||(i>=0&&nums1[i]>nums2[j]))nums1[k--]=nums1[i--];
            else nums1[k--]=nums2[j--];
        }
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums1{1,2,3,0,0,0};
    int m=3;
    vi nums2{2,5,6};
    int n=3;
    sol.merge(nums1,m,nums2,n);
    DBGV(nums1);

    system("pause");
    return 0;
}
