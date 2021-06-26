#include "utils.h"

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int cnt[32]={0};
        for(int a:nums){
            REP(i,32){
                cnt[i]+=a>>i&1;
            }
        }
        int ans=0;
        REP(i,32){
            cnt[i]%=3;
            ans+=(1<<i)*cnt[i];
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{3,4,3,3};
    auto ans=sol.singleNumber(nums);
    DBG(ans);

    system("pause");
    return 0;
}
