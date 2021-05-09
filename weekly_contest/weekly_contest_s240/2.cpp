#include "utils.h"

class Solution {
public:
    //双指针
    //当i右移的时候，j的选择范围增大，所以j的右界也右移
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size(),ans=0;
        for(int i=0,j=0;i<n1;i++){
            while(j<n2&&nums2[j]>=nums1[i])j++;
            if(j>i)chmax(ans,j-i-1);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums1{30,29,19,5};
    vi nums2{25,25,25,25,25};
    auto ans=sol.maxDistance(nums1,nums2);
    DBG(ans);

    system("pause");
    return 0;
}
