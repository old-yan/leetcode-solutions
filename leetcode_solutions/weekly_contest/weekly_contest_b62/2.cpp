#include "utils.h"

class Solution {
public:
    //简单模拟
    int numOfPairs(vector<string>& nums, string target) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j and nums[i]+nums[j]==target)ans++;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>nums{"777","7","77","77"};
    string target="7777";
    auto ans=sol.numOfPairs(nums,target);
    DBG(ans);

    system("pause");
    return 0;
}