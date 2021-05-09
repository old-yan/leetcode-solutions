#include "utils.h"

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vi v;
        v.reserve(n*(n+1)/2);
        REP(i,n){
            int cnt=0;
            FOR(j,i,n){
                cnt+=nums[j];
                v.emplace_back(cnt);
            }
        }
        nth_element(v.begin(),v.begin()+left-1,v.end());
        nth_element(v.begin()+left,v.begin()+right,v.end());
        return accumulate(v.begin()+left-1,v.begin()+right,0ll)%MOD;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,2,3,4};
    int n=4;
    int left=1;
    int right=5;
    auto ans=sol.rangeSum(nums,n,left,right);
    DBG(ans);

    system("pause");
    return 0;
}
