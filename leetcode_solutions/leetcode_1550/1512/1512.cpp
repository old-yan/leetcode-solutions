#include "utils.h"

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans=0;
        unordered_map<int,int>M;
        for(int a:nums){
            ans+=M[a]++;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,2,3,1,1,3};
    auto ans=sol.numIdenticalPairs(nums);
    DBG(ans);

    system("pause");
    return 0;
}
