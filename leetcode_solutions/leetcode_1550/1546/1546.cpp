#include "utils.h"

class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_map<int,int>M{{0,0}};
        partial_sum(ALL(nums),nums.begin());
        int ans=0;
        for(int a:nums){
            if(M.count(a-target))chmax(ans,M[a-target]+1);
            chmax(M[a],ans);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{-1,3,5,1,4,2,-9};
    int target=6;
    auto ans=sol.maxNonOverlapping(nums,target);
    DBG(ans);

    system("pause");
    return 0;
}
