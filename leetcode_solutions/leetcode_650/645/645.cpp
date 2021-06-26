#include "utils.h"

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int appear[10001]={0};
        int sum=nums.size()*(nums.size()+1)/2;
        vi ans;
        for(int a:nums){
            if(++appear[a]>1)ans.pb(a);
            else sum-=a;
        }
        ans.pb(sum);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,2,2,4};
    auto ans=sol.findErrorNums(nums);
    DBGV(ans);

    system("pause");
    return 0;
}
