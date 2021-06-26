#include "utils.h"

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans=0;
        for(int i=0,j=0;i<nums1.size();i++){
            while(j<nums2.size()&&nums2[j]>=nums1[i])j++;
            chmax(ans,j-1-i);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums1{55,30,5,4,2};
    vi nums2{100,20,10,10,5};
    auto ans=sol.maxDistance(nums1,nums2);
    DBG(ans);

    system("pause");
    return 0;
}
