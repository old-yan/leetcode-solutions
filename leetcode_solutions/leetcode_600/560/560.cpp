#include "utils.h"

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        partial_sum(ALL(nums),nums.begin());
        unordered_map<int,int>M{{0,1}};
        int ans=0;
        for(int a:nums){
            if(M.count(a-k))ans+=M[a-k];
            M[a]++;
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
