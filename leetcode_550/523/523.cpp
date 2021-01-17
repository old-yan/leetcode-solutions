#include "utils.h"

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(!k)k=INT_MAX;
        auto sum=presum(nums);
        unordered_set<ll>S;
        REP(i,sum.size()){
            if(i>1){
                S.insert(sum[i-2]%k);
                if(S.count(sum[i]%k))return true;
            }
        }
        return false;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{23,2,4,6,7};
    int k=6;
    auto ans=sol.checkSubarraySum(nums,k);
    DBG(ans);

    system("pause");
    return 0;
}
