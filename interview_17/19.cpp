#include "utils.h"

class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        int n=nums.size()+2;
        vi ans;
        if(count(ALL(nums),n-1)==0)ans.pb(n-1);
        if(count(ALL(nums),n)==0)ans.pb(n);
        for(int a:nums){
            a=abs(a);
            if(a<=nums.size())nums[a-1]*=-1;
        }
        REP(i,nums.size()){
            if(nums[i]>0){
                ans.pb(i+1);
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{2,3};
    auto ans=sol.missingTwo(nums);
    DBG(ans);

    system("pause");
    return 0;
}
