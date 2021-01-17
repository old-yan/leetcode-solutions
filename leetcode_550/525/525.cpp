#include "utils.h"

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for(int&a:nums)if(!a)a=-1;
        auto sum=presum(nums);
        unordered_map<ll,int>M;
        int ans=0;
        REP(i,sum.size()){
            if(M.count(sum[i])){
                chmax(ans,int(i)-M[sum[i]]);
            }
            else{
                M[sum[i]]=i;
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
