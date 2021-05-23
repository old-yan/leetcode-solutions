#include "utils.h"

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cur=INT_MIN;
        int ans=0;
        for(int a:nums){
            if(a<=cur){
                ans+=cur+1-a;
                cur++;
            }
            else cur=a;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,1,1};
    auto ans=sol.minOperations(nums);
    DBG(ans);

    system("pause");
    return 0;
}
