#include "utils.h"

class Solution {
public:
    //本体数据量较小，直接四重循环就可以过
    //当然稍微优化一下，变成三重循环，也是可以的
    int countQuadruplets(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int cnt[101]={0};
                for(int k=j+1;k<n;k++)cnt[nums[k]]++;
                for(int k=j+1;k<n;k++){
                    cnt[nums[k]]--;
                    int target=nums[i]+nums[j]+nums[k];
                    if(target>0&&target<=100)ans+=cnt[target];
                }
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,2,3,6};
    auto ans=sol.countQuadruplets(nums);
    DBG(ans);

    system("pause");
    return 0;
}
