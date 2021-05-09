#include "utils.h"

class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        ll ans=0,i,j,a,b;
        for(i=j=a=b=0;i<nums1.size()||j<nums2.size();){
            if(i==nums1.size()||(j<nums2.size()&&nums2[j]<nums1[i])){
                j++;b++;
            }
            else if(j==nums2.size()||(i<nums1.size()&&nums1[i]<nums2[j])){
                i++;a++;
            }
            else{
                ans+=max(a,b)+nums1[i];
                a=b=0;
                i++;j++;
            }
        }
        ans+=max(a,b);
        return ans%MOD;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums1{2,4,5,8,10};
    vi nums2{4,6,8,9};
    auto ans=sol.maxSum(nums1,nums2);
    DBG(ans);

    system("pause");
    return 0;
}
