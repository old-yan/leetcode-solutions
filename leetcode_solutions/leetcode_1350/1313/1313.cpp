#include "utils.h"

class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i+=2){
            ans.insert(ans.end(),nums[i],nums[i+1]);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,2,3,4};
    auto ans=sol.decompressRLElist(nums);
    DBGV(ans);

    system("pause");
    return 0;
}
