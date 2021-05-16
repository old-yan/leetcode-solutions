#include "utils.h"

class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        partial_sum(ALL(nums),nums.begin());
        int total=nums.back();
        int ans=0;
        for(int i=0,j=1,k=1;i<nums.size()-2&&nums[i]<=total/3;i++){
            int left_sum=nums[i];
            while(j==i||(nums[j]<left_sum*2)){
                j++;
            }
            while(k+2<nums.size()&&nums[k+1]<=left_sum+(total-left_sum)/2){
                k++;
            }
            ans=(ans+k+1-j)%MOD;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{8892,2631,7212,1188,6580,1690,5950,7425,8787,4361,9849,4063,9496,9140,9986,1058,2734,6961,8855,2567,7683,4770,40,850,72,2285,9328,6794,8632,9163,3928,6962,6545,6920,926,8885,1570,4454,6876,7447,8264,3123,2980,7276,470,8736,3153,3924,3129,7136,1739,1354,661,1309,6231,9890,58,4623,3555,3100,3437};
    auto ans=sol.waysToSplit(nums);
    DBG(ans);

    system("pause");
    return 0;
}
