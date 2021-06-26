#include "utils.h"

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for(int&a:nums)if(!a)a=-1;
        partial_sum(ALL(nums),nums.begin());
        unordered_map<ll,int>M{{0,-1}};
        int ans=0;
        REP(i,nums.size()){
            if(M.count(nums[i])){
                chmax(ans,int(i)-M[nums[i]]);
            }
            else{
                M[nums[i]]=i;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{0,1,0};
    auto ans=sol.findMaxLength(nums);
    DBG(ans);

    system("pause");
    return 0;
}
