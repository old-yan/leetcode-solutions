#include "utils.h"

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum=0;
        REP(i,k)sum+=nums[i];
        int maxsum=INT_MIN;
        REP(i,nums.size()-k+1){
            chmax(maxsum,sum);
            if(i+k<nums.size())sum+=nums[i+k]-nums[i];
        }
        return double(maxsum)/k;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,12,-5,-6,50,3};
    int k=4;
    auto ans=sol.findMaxAverage(nums,k);
    DBG(ans);

    system("pause");
    return 0;
}
