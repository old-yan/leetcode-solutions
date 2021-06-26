#include "utils.h"

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int m=nums.size(),n=nums[0].size();
        if(m*n!=r*c)return nums;
        vvi ans(r,vi(c));
        REP(i,m*n){
            ans[i/c][i%c]=nums[i/n][i%n];
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi nums{
        {1,2},
        {3,4}
    };
    int r=1;
    int c=4;
    auto ans=sol.matrixReshape(nums,r,c);
    DBGVV(ans);

    system("pause");
    return 0;
}
