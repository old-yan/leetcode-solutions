#include "utils.h"

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int cnt[101]={0};
        for(int a:nums)cnt[a]++;
        int ans=0;
        REP(i,101){
            if(cnt[i]==1)ans+=i;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,2,3,2};
    auto ans=sol.sumOfUnique(nums);
    DBG(ans);

    system("pause");
    return 0;
}
