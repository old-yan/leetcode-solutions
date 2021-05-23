#include "utils.h"

class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n=nums.size();
        int leftSmaller[n],rightSmaller[n];
        stack<int>S;
        REP(i,n){
            while(S.size()&&nums[S.top()]>=nums[i])S.pop();
            leftSmaller[i]=S.size()?S.top():-1;
            S.push(i);
        }
        stack<int>().swap(S);
        REPR(i,n-1){
            while(S.size()&&nums[S.top()]>=nums[i])S.pop();
            rightSmaller[i]=S.size()?S.top():n;
            S.push(i);
        }
        ll _presum[n+1];
        auto presum=_presum+1;
        presum[-1]=0;
        REP(i,n){
            presum[i]=presum[i-1]+nums[i];
        }
        ll ans=0;
        REP(i,n){
            chmax(ans,(ll)nums[i]*(presum[rightSmaller[i]-1]-presum[leftSmaller[i]]));
        }
        return ans%MOD;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,2,3,2};
    auto ans=sol.maxSumMinProduct(nums);
    DBG(ans);

    system("pause");
    return 0;
}
