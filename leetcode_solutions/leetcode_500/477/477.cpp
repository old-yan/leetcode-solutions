#include "utils.h"

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int count[32]={0};
        for(int a:nums){
            REP(j,32)count[j]+=(a>>j)&1;
        }
        int ans=0;
        REP(i,32){
            int j=count[i];
            ans+=j*(nums.size()-j);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{4,14,2};
    auto ans=sol.totalHammingDistance(nums);
    DBG(ans);

    system("pause");
    return 0;
}
