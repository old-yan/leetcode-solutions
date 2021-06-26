#include "utils.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int Max=*max_element(ALL(nums));
        bool appear[Max+1];
        memset(appear,0,sizeof(appear));
        for(int a:nums){
            int b=target-a;
            if(b>=0&&b<=Max&&appear[b]){
                return {a,b};
            }
            appear[a]=true;
        }
        return {};
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{2,7,11,1,5};
    int target=9;
    auto ans=sol.twoSum(nums,target);
    DBGV(ans);

    system("pause");
    return 0;
}
