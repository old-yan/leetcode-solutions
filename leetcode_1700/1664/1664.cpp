#include "utils.h"

class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int leftdif=0,rightdif=0,n=nums.size();
        REP(i,n)rightdif+=i%2?nums[i]:-nums[i];
        int ans=0;
        for(int i=0;i<n;i++){
            rightdif-=i%2?nums[i]:-nums[i];
            if(leftdif==rightdif)ans++;
            leftdif+=i%2?nums[i]:-nums[i];
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{2,1,6,4};
    auto ans=sol.waysToMakeFair(nums);
    DBG(ans);

    system("pause");
    return 0;
}
