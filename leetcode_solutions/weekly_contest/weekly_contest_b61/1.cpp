#include "utils.h"

class Solution {
public:
    //简单模拟
    int countKDifference(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(abs(nums[i]-nums[j])==k)ans++;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{3,2,1,5,4};
    int k=2;
    auto ans=sol.countKDifference(nums,k);
    DBG(ans);

    system("pause");
    return 0;
}