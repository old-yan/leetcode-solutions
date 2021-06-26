#include "utils.h"

class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int sum1=accumulate(ALL(nums1),0);
        int sum2=accumulate(ALL(nums2),0);
        int makeup[6]={0};
        for(int a:nums1){
            if(sum1<sum2)makeup[6-a]++;
            else makeup[a-1]++;
        }
        for(int a:nums2){
            if(sum2<sum1)makeup[6-a]++;
            else makeup[a-1]++;
        }
        int dif=abs(sum1-sum2);
        int ans=0;
        FORR(i,5,1){
            if(dif<=i*makeup[i]){
                ans+=(dif+i-1)/i;
                dif=0;
                break;
            }
            else{
                dif-=i*makeup[i];
                ans+=makeup[i];
            }
        }
        return dif?-1:ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums1{1,2,3,4,5,6};
    vi nums2{1,1,2,2,2,2};
    auto ans=sol.minOperations(nums1,nums2);
    DBG(ans);

    system("pause");
    return 0;
}
