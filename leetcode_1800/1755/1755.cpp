#include "utils.h"

class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        vi half1(nums.begin(),nums.begin()+nums.size()/2);
        vi half2(nums.begin()+nums.size()/2,nums.end());
        auto v1=getSubsequenceSum(half1);
        auto v2=getSubsequenceSum(half2);
        int ans=INT_MAX;
        for(int i=0,j=v2.size()-1;i<v1.size()&&j>=0;){
            chmin(ans,abs(v1[i]+v2[j]-goal));
            if(v1[i]+v2[j]>goal)j--;
            else if(v1[i]+v2[j]<goal)i++;
            else return 0;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{5,-7,3,5};
    int goal=6;
    auto ans=sol.minAbsDifference(nums,goal);
    DBG(ans);

    system("pause");
    return 0;
}
