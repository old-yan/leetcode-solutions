#include "utils.h"

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        auto sum=presum(nums);
        unordered_map<ll,int>M;
        for(auto a:sum)M[a]++;
        int ans=0;
        for(auto a:sum){
            M[a]--;
            ans+=M[a+k];
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,1,1};
    int k=2;
    auto ans=sol.subarraySum(nums,k);
    DBG(ans);

    system("pause");
    return 0;
}
