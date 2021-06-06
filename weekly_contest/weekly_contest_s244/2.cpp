#include "utils.h"

class Solution {
public:
    //从大往小模拟
    //每次到一个次大值时，需要把比次大值大的那些值都降过来
    //都降过来之后，此时的次大值成为了最大的，接下来去搜索下一个次大值
    int reductionOperations(vector<int>& nums) {
        sort(ALLR(nums));
        ll ans=0;
        for(int i=0,j;i<nums.size();i=j){
            for(j=i+1;j<nums.size()&&nums[j]==nums[i];j++);
            ans+=i;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{5,1,3};
    auto ans=sol.reductionOperations(nums);
    DBG(ans);

    system("pause");
    return 0;
}
